class c_scard  
{  
 public:  
     void AddRef() {refCount++;}  
     void Release() {refCount--; if( refCount == 0 ) delete this;}  
     int refCount;  
    void reconnect(){return;}  
 private:  
}; 



//----------------------------------------------------------------------------- 
// Name:    LoadScript()    [global function]  
// Desc:    Reads a file specified by "filename" parameter and creates a new   
//          Angelscript Section with the name specified by "module" parameter.  
//-----------------------------------------------------------------------------  
int LoadScript(asIScriptEngine * pScriptEngine, const char *filename, const char * module)  
{  
    // Read the entire script file  
    FILE * pFile = fopen(filename, "rb");  
    if( pFile == 0 )  
    {  
        printf("Failed to open the script file.\n");  
        return -1;  
    }  
  
    // Find the length of the script file  
    fseek(pFile, 0, SEEK_END);  
    int len = ftell(pFile);  
    fseek(pFile, 0, SEEK_SET);  
    // On Win32 it is possible to do the following instead  
    // int len = _filelength(_fileno(f));  
    std::string code;  
    code.resize(len);  
  
    // Read length of script file  
    size_t c = fread(&code[0], len, 1, pFile);  
    fclose(pFile);  
    if( c == 0 )   
    {  
        printf("Failed to load script file.\n");  
        return -1;  
    }  
  
    // Give the code to the script engine  
    int nRet = pScriptEngine->AddScriptSection(module, filename, code.c_str(), len, 0);  
    if( nRet < 0 )   
    {  
        printf("An error occured while adding the script section.\n");  
    }  
    // At this point the engine has copied the code to an   
    // internal buffer so we are free to release the memory we   
    // allocated.   
    // We can also add other script sections if we would like.  
    // All script sections will be compiled together as if they  
    // where one large script.   
  
    return nRet;  
}   

void CangelTestDlg::OnBnClickedOk()  
  
{  
    // TODO: Add your control notification handler code here  
      
    // Create the AngelScript script engine  
    asIScriptEngine * pScriptEngine = asCreateScriptEngine(ANGELSCRIPT_VERSION);  
  
    if( pScriptEngine == 0 )  
    {  
        AfxMessageBox( _T("Failed to create Angel Script engine.") );  
        return;  
    }  
    // Set the message callback  
    pScriptEngine->SetMessageCallback(asFUNCTION(MessageCallback), NULL, asCALL_CDECL);  
  
    // Register AngelScript Plugins  
    RegisterScriptString(pScriptEngine);  
    // Local function used to load a script file into memory  
    // A separate function was created to unclutter this main function  
    // a bit.  
    if (LoadScript( pScriptEngine, "script.as","myModol" ) < 0)  
    {  
        pScriptEngine->Release();  
        AfxMessageBox(L"Failed to load script file.");  
        return;  
    }  
    int s = pScriptEngine->RegisterObjectType("c_scard", sizeof(c_scard), asOBJ_REF);  
    if(s < 0)  
        AfxMessageBox( L"register c_scard failed" );  
  
    s = pScriptEngine->RegisterObjectBehaviour("c_scard", asBEHAVE_ADDREF, "void f()", asMETHOD(c_scard, AddRef), asCALL_THISCALL);  
  
    if(s<0)  
        AfxMessageBox( L"register behaviour ref failed" );  
  
    s = pScriptEngine->RegisterObjectBehaviour("c_scard", asBEHAVE_RELEASE, "void f()", asMETHOD(c_scard, Release), asCALL_THISCALL);  
  
    if(s<0)  
        AfxMessageBox( L"register behaviour release failed" );  
  
    // Register the function that the scripts will be allowed to use.  
    // This also MUST be done BEFORE we build the script! Or you will get a runtime error.  
    int ret = pScriptEngine->RegisterObjectMethod("c_scard", "void reconnect()", asMETHOD(c_scard,reconnect), asCALL_THISCALL);   
 
    if(ret < 0)  
        AfxMessageBox( L"register function failed" );  
  
    s = pScriptEngine->RegisterGlobalProperty("c_scard scard" , &m_scard);  
  
    if(s<0)  
        AfxMessageBox( L"register object failed" );  
  
    // Why do we need to build the script?  
    // Scripts need to be compiled into byte code, that the virtual machine understands.  
  
    asIScriptContext * pContext = NULL;  
    ret = pScriptEngine->Build( "myModol" );  
    if( ret < 0 )  
    {  
        printf("Failed to compile script\n");  
        goto skip_return;  
    }  
    // Create a context that will execute the script.  
    // What is a "context" you ask?  Well go read the documentation  
    // for this tutorial and find out. :)  
    pContext = pScriptEngine->CreateContext();  
    if( pContext == 0 )   
    {  
        printf("Failed to create the context.");  
        pScriptEngine->Release();  
        return;  
    }  
  
    // Register Script Function  
    // If we had more functions in the module (script file) then we could register those  
    // as well.  Notice that our module is currently NULL which means we only have one   
    // and don't intend to name it.  
  
    int nFunctionID = pScriptEngine->GetFunctionIDByName("myModol", "main");  
    // Must "prepare" the function for execution  
    // Prepare must be called to allow the context to prepare the function stack  
    pContext->Prepare( nFunctionID );  
    // Execute the script function  
    pContext->Execute( );  
  
skip_return:  
  
    // Release the engine  
    pScriptEngine->Release();  
    // We must release the context(s) when no longer using them  
    if ( pContext )  
    {  
        pContext->Release();  
    }  
}  



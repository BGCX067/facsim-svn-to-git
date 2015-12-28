/*
This is written by WANG MengChang
*/
#include "simscript.h"

#include <cassert>

long simScript::nID=0;

simScript::simScript(long tp)
{
    //ctor
    if (LONG_R_TYPE!=tp &&
            DOUBLE_R_TYPE!=tp &&
            STRING_R_TYPE!=tp &&
            SIMBASE_R_TYPE!=tp &&
            BOOL_R_TYPE!=tp &&
            VOID_R_TYPE!=tp
       )
    {
        printf("Error[simscript.cpp:line 14]:A wrong return type is set to a simScript.\n");
    }
    else
    {
        rType=tp;
    }
    HaveToReRun=true;
    dbResult=0.0;
    lResult=0;
    strResult=(std::string*)NULL;
    sbResult=(simBase*)NULL;
    bResult=false;

    script="";
    ID=0;
    nID++;
    ID=nID;

    isCodeAdded=false;
    isCompiled=false;
}

simScript::~simScript()
{
    //dtor
}


void simScript::SetValue(long* along)
{
    run();
    if (rType==LONG_R_TYPE)
    {
        *along=lResult;
    }
    else if (rType==DOUBLE_R_TYPE)
    {
        *along=long(dbResult);
    }
    else
    {
        printf("Error[simscript.cpp:ling 44]: a wrong type is passed to a Long type varialbe.\n");
    }
}
void simScript::SetValue(std::string* astr)
{
    run();
    if (rType==LONG_R_TYPE)
    {
        //转化成字符串
        char tmpstr[100];
        sprintf(tmpstr,"%ld",lResult);
        //astr->clear();
        (*astr)=tmpstr;
    }
    else if (rType==DOUBLE_R_TYPE)
    {
        //同上
        char tmpstr[200];
        sprintf(tmpstr,"%lf",dbResult);
        (*astr)=tmpstr;
    }
    else if (rType==STRING_R_TYPE)
    {
        //strResult 是一个string指针
        if (strResult!=(std::string*)NULL)
        {
            *astr=*strResult;
        }
    }
    else if (rType==SIMBASE_R_TYPE)
    {
        //返回元素的名称
    }
    else
    {
        printf("Error[simscript.cpp:ling XX]: a wrong type is passed to a string type varialbe.\n");
    }
}

void simScript::SetValue(double* af)
{
    run();
    if (rType==LONG_R_TYPE)
    {
        //
        *af=double(lResult);
    }
    else if (rType==DOUBLE_R_TYPE)
    {
        *af=dbResult;
    }
    else if (rType==STRING_R_TYPE)
    {
        //strResult 是一个string指针
        if (strResult!=(std::string*)NULL)
        {
            *af=atof(strResult->c_str());//将字符串转化为双精度浮点型
        }
    }
    else if (rType==SIMBASE_R_TYPE)
    {
        //返回元素的名称
    }
    else
    {
        printf("Error[simscript.cpp:ling XX]: a wrong type is passed to a string type varialbe.\n");
    }

}
void simScript::SetValue(simBase* aobj)
{
    //not completed yet.
}
void simScript::SetValue(bool* abl)
{
    //not yet
    run();
    if (rType==BOOL_R_TYPE)
    {
        *abl=bResult;
    }
    else
    {
        printf("Error[simscript.cpp:ling XX]: a wrong type is passed to a string type varialbe.\n");
    }
}

void simScript::operator =(std::string& astr)
{
    script=astr;
}
void simScript::operator =(const char* astr)
{
    script=astr;
}
void simScript::operator =(char* str)
{
    script=str;
}


std::string simScript::GetScript()
{
    return script;
}

void simScript::RegisterScriptEngine(asIScriptEngine* pEg)
{
    pEngine=pEg;
}

void simScript::run()
{
    //Generate the results
    //1-用一个script_xxx()函数来包含这一语句
    //3-执行脚本
    //4-析取运行结果
    //asIScriptEngine *engine=asCreateScriptEngine(ANGELSCRIPT_VERSION);
    //int r=engine->SetMessageCallback(asFUNCTION(ScriptMessageCallback),0,asCALL_CDECL);assert(r>=0);
    std::string func_name_str;
    func_name_str="script_";
    char sid[50];
    sprintf(sid,"%ld",ID);
    func_name_str+=sid;
    //func_name_str.
    printf("ID=%ld\nFun name=%s\n",ID,func_name_str.c_str());
    int r;

    if (!isCodeAdded)
    {
        std::string rType_str="";

        std::string final_str="";
        if (rType==LONG_R_TYPE)
        {
            rType_str="int";
        }
        else if (rType==DOUBLE_R_TYPE)
        {
            rType_str="double";
        }
        else if (rType==STRING_R_TYPE)
        {
            rType_str="int8";//problems here
        }
        else if (rType==SIMBASE_R_TYPE)
        {
        }
        else if (rType==BOOL_R_TYPE)
        {
            rType_str="bool";
        }
        else if (rType==VOID_R_TYPE)
        {
            rType_str="void";
        }
        else
        {
            printf("\n[simscript.cpp]Wrong script return type.\n");
            return;
        }


        final_str=rType_str;
        final_str+=" ";
        final_str+=func_name_str;
        //如果script为表达式 ,则不用再加return
        bool flag=false;
        std::string::size_type loc = script.find(";", 0);
        if (loc==std::string::npos)
        {
            final_str+="(){\n return ";
            flag=true;
        }
        else
        {
            final_str+="(){\n ";
        }

        final_str+=script;
        if (flag)
        {
            final_str+=";\n}\n";
        }
        else
        {
            final_str+="\n}\n";
        }
        //now final_str is "rtype script_XXX(){ return ... ;}"

        asIScriptModule *mod = pEngine->GetModule(func_name_str.c_str(),
                               asGM_ALWAYS_CREATE);
        //设置模块的代码内容
        mod->AddScriptSection(func_name_str.c_str(),final_str.c_str());

        //编译模块

        printf("Befor compile:\n%s",final_str.c_str());
        r=mod->Build();
        if (r<0)
        {
            printf("编译失败。\n");
            return;
        }
        isCodeAdded=true;
    }
    else
    {
        printf("[info:] code %s has compiled, no need to add again.\n",func_name_str.c_str());
    }

    asIScriptContext *ctx = pEngine->CreateContext();

    int funcID=pEngine->GetModule(func_name_str.c_str())->GetFunctionIdByName(func_name_str.c_str());
    if (funcID<0)
    {
        ctx->Release();
        printf("检索函数%s失败.\n",func_name_str.c_str());
        return;
    }
    r=ctx->Prepare(funcID);
    if (r<0)
    {
        ctx->Release();
        printf("准备函数%s失败.\n",func_name_str.c_str());
        return;
    }

    r=ctx->Execute();
    switch (r)
    {
    case asERROR:
        printf("Script run error.[simscript.cpp]\n");
        ctx->Release();
        return;
        break;
    case asEXECUTION_ABORTED:
        printf("Script is Aborted.\n");
        ctx->Release();
        return;
        break;
    case asEXECUTION_SUSPENDED:
        printf("Script is Suspened.\n");
        break;
    case asEXECUTION_FINISHED:
        break;
    default:
        printf("Script running Error.\n");
    }

    if (rType==LONG_R_TYPE)
    {
        lResult=ctx->GetReturnDWord();
    }
    else if (rType==DOUBLE_R_TYPE)
    {
        dbResult=ctx->GetReturnDouble();
    }
    else if (rType==STRING_R_TYPE)
    {
        //rType_str="int8";//problems here
        printf("String Type return value not implemented yet.\n");
    }
    else if (rType==SIMBASE_R_TYPE)
    {
        printf("SimBase Type return value not implemented yet.\n");
    }
    else if (rType==BOOL_R_TYPE)
    {
        bResult=ctx->GetReturnByte();
    }
    else if (rType==VOID_R_TYPE)
    {
        //void do nothing
    }
    else
    {
        printf("Wrong Type was passed into the script.\n");
    }


    ctx->Release();

}

void ScriptMessageCallback(const asSMessageInfo *msg, void *param)
{
    //
    const char *type = "错误：";
    if ( msg->type == asMSGTYPE_WARNING )
        type = "警告：";
    else if ( msg->type == asMSGTYPE_INFORMATION )
        type = "信息：";
    printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col,type, msg->message);
}


//// Test Script ////
#include <wx/msgdlg.h>
#include <wx/string.h>
double test(double x)
{
    printf("%lf x %lf = %lf",x,x,x*x);
    return x*x;
}
void TestScript()
{
    simElementList aList;

    aList.GetScriptEngine()->RegisterGlobalFunction("double square(double)",asFUNCTION(test),asCALL_CDECL);


    int a,b;
    aList.GetScriptEngine()->RegisterGlobalProperty("int k",&a);
    aList.GetScriptEngine()->RegisterGlobalProperty("int k2",&b);

    simScript sc(LONG_R_TYPE);
    sc="3";
    simScript sc2(DOUBLE_R_TYPE);
    sc2="\tdouble z;\n\tz=square(2.0)+1;\n\treturn z;";
    sc.RegisterScriptEngine(aList.GetScriptEngine());
    sc2.RegisterScriptEngine(aList.GetScriptEngine());

    long rs=0;
    double rs2=0.0;
    //sc.run();
    sc.SetValue(&rs);
    sc2.SetValue(&rs2);
    printf("\nresult is\nrs=%ld\nrs2=%lf\n",rs,rs2);
    printf("======\n\n");

}




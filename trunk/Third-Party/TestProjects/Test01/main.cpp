#include <iostream>
#include <cassert>
#include <string>
#include "./include/angelscript.h"

using namespace std;

void MyFun()
{
    printf("Hello World 来自 AngelScript.\n");
}

//A function to cope with error messages from AS engine,
//has to be defined by your self
void MessageCallback(const asSMessageInfo *msg, void *param)
{
  const char *type = "错误：";
  if( msg->type == asMSGTYPE_WARNING )
    type = "警告：";
  else if( msg->type == asMSGTYPE_INFORMATION )
    type = "信息：";
  printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
}

int main()
{
    //创建一个AS引擎
    asIScriptEngine *engine =
            asCreateScriptEngine(ANGELSCRIPT_VERSION);

    int r;

    //设置(绑定)异常处理函数
    r=engine->SetMessageCallback(asFUNCTION(MessageCallback),
                                0,
                                asCALL_CDECL);
    assert(r>=0);

    //注册一个全局函数，注册之后就可以在脚本中调用
    r=engine->RegisterGlobalFunction("void PrintHello()",
                                    asFUNCTION(MyFun),
                                    asCALL_CDECL);
    assert(r>=0);
    //
    //一个脚本样例：
    string ascript="void main()\n{PrintHello();\nPrintHello();\nPrintHello();}\nint abc(int z){PrintHello();return z-10;}";

    //创建一个脚本模块 module
    asIScriptModule *mod = engine->GetModule("module001", asGM_ALWAYS_CREATE);
    //设置模块的代码内容
    mod->AddScriptSection("example001",ascript.c_str());

    //编译模块
    r=mod->Build();
    if(r<0){
        printf("编译失败。\n");
        return 1;
    }

    //通过编译之后，将调用AS脚本中的函数
    //1-准备一个上下文
    //2-设定函数参数
    //3-执行函数
    //4-析取返回值

    asIScriptContext *ctx = engine->CreateContext();

    //int funcID=engine->GetModule("module")->GetFunctionIdByDecl("void PrintHello()");
    int funcID=engine->GetModule("module001")->GetFunctionIdByName("abc");
    if(funcID<0)
    {
        ctx->Release();
        engine->Release();
        printf("检索函数void main()失败.\n");
        return 1;
    }
    r=ctx->Prepare(funcID);
    if(r<0){
        ctx->Release();
        engine->Release();
        printf("准备函数void main()失败.\n");
        return 1;
    }

    //设置函数的参数
    ctx->SetArgDWord(0,5);
    //执行函数
    r=ctx->Execute();
    //
    long rs=ctx->GetReturnDWord();
    printf("abc(5)=%ld",rs);


    //engine->~asIScriptEngine();
    return 0;
}


















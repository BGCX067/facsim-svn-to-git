#include <iostream>
#include <cassert>
#include <string>
#include "../Test01/include/angelscript.h"

using namespace std;
class MyClass
{
public:
    MyClass()
    {
        k=0;
        refCount=0;
    }
    ~MyClass(){}
    int k;
    void func1()
    {
        cout<<"This is from MyClass.\nk="<<k<<endl;
        k=66;
        cout<<"Now k=66"<<endl;
    }
    //void operator =(MyClass& amc){k=amc.k;}
    void operator =(int m)
    {
        k=m;
    }
    int refCount;
    void AddRef()
    {
        refCount++;
    }
    void Release()
    {
        refCount--;
        if (refCount==0)
            delete this;
    }
};

//A function to cope with error messages from AS engine,
//has to be defined by your self
void MessageCallback(const asSMessageInfo *msg, void *param)
{
    const char *type = "错误：";
    if ( msg->type == asMSGTYPE_WARNING )
        type = "警告：";
    else if ( msg->type == asMSGTYPE_INFORMATION )
        type = "信息：";
    printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col,
           type, msg->message);
}


int main()
{

    MyClass v;
    int r=-1;
    //创建脚本引擎
    asIScriptEngine *engine=asCreateScriptEngine(ANGELSCRIPT_VERSION);
    r=engine->SetMessageCallback(asFUNCTION(MessageCallback),0,asCALL_CDECL);
    assert(r>=0);

    //向引擎注册/声明AClass类型
    r=engine->RegisterObjectType("AClass",sizeof(MyClass),asOBJ_REF);
    assert(r>=0);

    //注册增加引用与释放函数注册
    r = engine->RegisterObjectBehaviour("AClass",
                                        asBEHAVE_ADDREF,
                                        "void f()",
                                        asMETHOD(MyClass,AddRef),
                                        asCALL_THISCALL);
    assert( r >= 0 );
    r = engine->RegisterObjectBehaviour("AClass",
                                        asBEHAVE_RELEASE,
                                        "void f()",
                                        asMETHOD(MyClass,Release),
                                        asCALL_THISCALL);
    assert( r >= 0 );

    //注册成员函数
    r=engine->RegisterObjectMethod("AClass",
                                   "void func1()",
                                   asMETHOD(MyClass,func1),
                                   asCALL_THISCALL);
    assert(r>=0);
    //注册成员变量
    //r=engine->RegisterObjectProperty("AClass","int kk",offsetof(MyClass,k));assert(r>=0);
    //注册特殊的操作符函数
    /*
        r=engine->RegisterObjectBehaviour("AClass",
                            asBEHAVE_ASSIGNMENT,
                            "void f(AClass &in)",
                            asMETHODPR(MyClass,operator=,(MyClass&),void),//asMETHODPR(类名，函数名，(参数表),返回类型)
                            asCALL_THISCALL);assert(r>=0);

        r=engine->RegisterObjectBehaviour("AClass",
                            asBEHAVE_ASSIGNMENT,
                            "void f(int in)",
                            asMETHODPR(MyClass,operator=,(int),void),
                            asCALL_THISCALL);assert(r>=0);
    */

    //注册对象/变量 v
    r=engine->RegisterGlobalProperty("AClass myV",&v);
    assert(r>=0);

    string as="int main(){myV.func1();return 0;}";
    //创建一个脚本模块 module
    asIScriptModule *mod = engine->GetModule("module002",
                           asGM_ALWAYS_CREATE);
    //设置模块的代码内容
    mod->AddScriptSection("example002",as.c_str());

    //编译模块
    r=mod->Build();
    assert(r>=0);

    //准备上下文
    asIScriptContext *ctx = engine->CreateContext();
    int funcID=engine->GetModule("module002")->GetFunctionIdByDecl("int main()");
    if (funcID<0)
    {
        ctx->Release();
        engine->Release();
        printf("检索函数int main()失败.\n");
        return -1;
    }
    r=ctx->Prepare(funcID);
    if (r<0)
    {
        ctx->Release();
        engine->Release();
        printf("准备函数int main()失败.\n");
        return -1;
    }
    //设置函数的参数
    //ctx->SetArgDWord(....----此处不用设置参数
    //执行函数
    r=ctx->Execute();
    cout<<"Execute OK."<<endl;
    //析取返回值
    long rs=ctx->GetReturnDWord();
    printf("\nscript returned value %ld\n",rs);

    engine->Release();
    v.func1();
    return 0;
}

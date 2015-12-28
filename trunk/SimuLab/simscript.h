#ifndef SIMSCRIPT_H
#define SIMSCRIPT_H
/*
class simScript
说明

rType 返回值类型
result 是一个函数指针，根据rType的不同指向不同的函数
SetValue(para1,para2,rType)，为外部变量赋值

*/

//rType defination
#define LONG_R_TYPE 1
#define STRING_R_TYPE 2
#define DOUBLE_R_TYPE 3
#define SIMBASE_R_TYPE 4 //用于返回一个元素对象
#define BOOL_R_TYPE 5
#define VOID_R_TYPE 6

#include "simbase.h"
#include <string>
#include <cstdlib>

#ifndef __WIN_PATH__
#include "angelscript.h"
#else
#include "Add-ons/include/angelscript.h"
#endif
////////////////////////////////
class simScript
{

    public:
    static long nID;
        simScript(long tp);
        virtual ~simScript();
        void SetValue(long* along);
        void SetValue(std::string* astr);
        void SetValue(double* af);
        void SetValue(simBase* aobj);
        void SetValue(bool* abl);
        std::string GetScript();

        void operator =(std::string& astr);
        void operator =(const char* astr);
        void operator =(char* str);
        void RegisterScriptEngine(asIScriptEngine* pEg);
        void run();
    protected:
        long ID;
        long rType;//返回类型说明
        std::string* strResult;//字符串类型的结果
        double dbResult;
        long lResult;
        simBase* sbResult;
        bool bResult;

        std::string script;//脚本内容

        bool HaveToReRun;//在run的过程中判断是否需要重新计算，默认为true
    private:
        asIScriptEngine* pEngine;
        bool isCodeAdded;
        bool isCompiled;
};

void ScriptMessageCallback(const asSMessageInfo *msg, void *param);
#endif // SIMSCRIPT_H

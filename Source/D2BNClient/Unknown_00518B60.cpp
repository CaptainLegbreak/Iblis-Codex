#include "D2BNClient.h"

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

struct D2BnLogStrc
{
    void* hLog;

    D2BnLogStrc(const char* szFileName);
    ~D2BnLogStrc();
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
};

// 0x00518B60
D2BnLogStrc::D2BnLogStrc(const char* szFileName)
{
    SLogCreate(szFileName, 0, &hLog);
}

// build: symbol ??_GD2BnLogStrc@@QAEPAXI@Z 0x00518BD0
inline D2BnLogStrc::~D2BnLogStrc()
{
    SLogClose(hLog);
}

void sub_F28_EmitScalarDeletingDestructor(D2BnLogStrc* pLog)
{
    delete pLog;
}

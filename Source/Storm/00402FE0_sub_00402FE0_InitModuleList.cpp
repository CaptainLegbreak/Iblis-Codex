struct D2CrashGuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned long Data4[2];
};

struct D2CrashModuleStrc
{
    void* f_0;
    unsigned long nSize;
    char szName[0x100];
    char szPath[0x100];
    unsigned long nTimeStamp;
    D2CrashGuidStrc tGuid;
    unsigned long nAge;
    unsigned long nUnknown220;
    unsigned long nVersion;
};

struct D2CrashModuleListStrc
{
    unsigned int nCount;
    D2CrashModuleStrc aModules[0x100];
};

void __stdcall sub_M452_EmitSink(D2CrashModuleListStrc* pList);

// 0x00402FE0
static __declspec(noinline) D2CrashModuleListStrc* sub_00402FE0_InitModuleList(D2CrashModuleListStrc* pList)
{
    D2CrashModuleStrc* pModule = pList->aModules;
    int nLeft = 0x100 - 1;
    do
    {
        pModule->f_0 = 0; pModule->nSize = 0; pModule->nTimeStamp = 0;
        D2CrashGuidStrc* const pGuid = &pModule->tGuid;
        pGuid->Data1 = 0; pGuid->Data2 = 0; pGuid->Data3 = 0; pGuid->Data4[0] = 0; pGuid->Data4[1] = 0;
        pModule->nAge = 0; pModule->nUnknown220 = 0; pModule->nVersion = 0; pModule->szName[0] = 0; pModule->szPath[0] = 0;
        ++pModule;
    }
    while (--nLeft >= 0);
    return pList;
}

// build: context sub_M452_Emit_00402FE0
void __fastcall sub_M452_Emit_00402FE0(int nArg, int nArg2)
{
    D2CrashModuleListStrc tList;
    sub_M452_EmitSink(sub_00402FE0_InitModuleList(&tList));
    tList.nCount = nArg2 - nArg;
    sub_M452_EmitSink(&tList);
}

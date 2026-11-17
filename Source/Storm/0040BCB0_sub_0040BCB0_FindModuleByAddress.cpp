struct D2ModuleInfoStrc
{
    char szPath[0x104];
    char szName[0x100];
    unsigned long dwBase;
    unsigned long dwSize;
    D2ModuleInfoStrc* pNext;
};

// 0x0040BCB0
D2ModuleInfoStrc* __fastcall sub_0040BCB0_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList)
{
    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        if (dwAddress >= pModule->dwBase && dwAddress < pModule->dwBase + pModule->dwSize)
            return pModule;
    }
    return 0;
}

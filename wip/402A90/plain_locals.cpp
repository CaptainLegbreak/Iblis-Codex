// 0x00402A90
bool __stdcall sub_00402A90_GetDbgHelpModuleRange(void** ppBase, unsigned long* pSize)
{
    D2PsapiModuleInfoStrc tInfo;
    if (!ghDbgHelp)
        return false;
    if (!GetModuleInformation(GetCurrentProcess(), ghDbgHelp, &tInfo, sizeof(tInfo)))
        return false;
    void* pBase = tInfo.lpBaseOfDll;
    unsigned long nSize = tInfo.SizeOfImage;
    *ppBase = pBase;
    *pSize = nSize;
    return true;
}

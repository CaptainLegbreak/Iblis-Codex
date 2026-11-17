struct Unicode
{
    unsigned short wChar;

    static int __fastcall strcmp(const Unicode* str1, const Unicode* str2);                 // 0x005264F0
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);     // 0x00526F20
};

char gbRealmNamesInit_00779DA8;                                                             // 0x00779DA8
Unicode gwszRealmNames_00779DF0[7][0x100];                                                  // 0x00779DF0
extern "C" char* __cdecl strcpy(char* dst, const char* src);
#pragma intrinsic(strcpy)

// 0x00437D20
static int sub_00437D20_IsTestRealm(const Unicode* pName)
{
    if (!gbRealmNamesInit_00779DA8)
    {
        char szBuffer[0x100];
        gbRealmNamesInit_00779DA8 = 1;
        strcpy(szBuffer, "Testv104");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[0], szBuffer, 255);
        strcpy(szBuffer, "FatRealm");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[1], szBuffer, 255);
        strcpy(szBuffer, "BetaWest");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[2], szBuffer, 255);
        strcpy(szBuffer, "BetaEurope");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[3], szBuffer, 255);
        strcpy(szBuffer, "BetaUSWest");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[4], szBuffer, 255);
        strcpy(szBuffer, "BetaUSEast");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[5], szBuffer, 255);
        strcpy(szBuffer, "BetaAsia");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[6], szBuffer, 255);
    }

    for (int i = 0; i < 7; ++i)
    {
        if (!Unicode::strcmp(pName, gwszRealmNames_00779DF0[i]))
        {
            return 1;
        }
    }
    return 0;
}

int __stdcall sub_M216_Emit_00437D20(const Unicode* pName, int n)
{
    return sub_00437D20_IsTestRealm(pName) + n;
}

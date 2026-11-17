struct Unicode
{
    unsigned short wChar;
};

extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                      // 0x005267E0
void __fastcall sub_A15_UseText(const Unicode* pText);

// 0x00437F60
static __declspec(noinline) Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}

// 0x00438030
static __declspec(noinline) int sub_00438030_IsNotListedCode(int nValue)
{
    switch (nValue)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

// 0x004380B0
static __declspec(noinline) unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

void __fastcall sub_A15_Emit_00437F60(const unsigned char* pClass)
{
    Unicode wszText[0x40];
    sub_00437F60_GetClassName(wszText, *pClass);
    sub_A15_UseText(wszText);
}

int __fastcall sub_A15_Emit_00438030(const unsigned char* pClass)
{
    return sub_00438030_IsNotListedCode(*pClass);
}

unsigned int __fastcall sub_A15_Emit_004380B0(const unsigned int* pExpire)
{
    return sub_004380B0_GetDaysLeft(*pExpire);
}

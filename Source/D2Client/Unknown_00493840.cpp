struct Unicode;

extern int gnGlobal_007BEEE8; // 0x007BEEE8
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __cdecl sub_0044DB30(); // 0x0044DB30

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB); // 0x0046A530
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470

int gnGlobal_007BEECC; // 0x007BEECC

// 0x00493840
void __cdecl sub_00493840_TogglePopup()
{
    switch (gnGlobal_007BEECC)
    {
    case 0:
        if (!sub_0044DB30())
        {
            gnGlobal_007BEECC = 2;
            gnGlobal_007BEEE8 = 0;
            sub_00455F20(0x23, 1, 0);
        }
        else
        {
            gnGlobal_007BEECC = 1;
            sub_00455F20(0x23, 0, 0);
        }
        break;

    case 1:
        if (!sub_0044DB30())
        {
            gnGlobal_007BEECC = 0;
            sub_00455F20(0x23, 0, 0);
        }
        else
        {
            gnGlobal_007BEECC = 2;
            gnGlobal_007BEEE8 = 0;
            sub_00455F20(0x23, 1, 0);
        }
        break;

    default:
        gnGlobal_007BEECC = 0;
        sub_00455F20(0x23, 0, 0);
        break;
    }
}

// 0x00495030
void __cdecl sub_00495030_DrawKeyHelp()
{
    Unicode wszText[200];
    Unicode wszKey[30];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1051));
    if (sub_00469AA0(6, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_0046A530_GetKeyName(6, 1));
        sub_00526700(wszText, wszKey);
    }
    if (sub_00469AA0(6, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_0046A530_GetKeyName(6, 0));
        sub_00526700(wszText, wszKey);
    }
    const int nWidth = sub_00501820(wszText);
    sub_00502320(wszText, gnGlobal_0071146C - nWidth / 2 - 0x3A, gnGlobal_00711470 - 0xC5, 0, 0);
}

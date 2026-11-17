struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char szIntFormat_006D6454[];                                                               // 0x006D6454

int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc);                                     // 0x00526700
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                 // 0x00526320
unsigned short __fastcall sub_004E6CE0_GetStringId(int nId, int nIndex);                                   // 0x004E6CE0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

static __forceinline int IsMouseInSquare(int nX, int nY)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    return nMouseX >= nX && nMouseX <= nX + 0x30 && nMouseY >= nY - 0x30 && nMouseY <= nY;
}

// 0x004AA1F0
void __fastcall sub_004AA1F0_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY)
{
    if (IsMouseInSquare(nX, nY))
    {
        if (nState != 1)
        {
            nState = 0;
        }
    }
    else
    {
        nState = 1;
    }

    if (!IsMouseInSquare(nX, nY))
    {
        return;
    }

    const Unicode* wszNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    Unicode wszText[0x100];
    const unsigned short nNameId = sub_004E6CE0_GetStringId(*pId, 0);
    const int nTextId = sub_004E6CE0_GetStringId(*pId, 1);
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nTextId));
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105C));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    Unicode wszNumber[10];
    char szNumber[12];
    wsprintfA(szNumber, szIntFormat_006D6454, nQuantity);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nNameId));
    sub_00502280_SetPopUpText(wszText, nX, nY - 0x32, nState, 1);
}

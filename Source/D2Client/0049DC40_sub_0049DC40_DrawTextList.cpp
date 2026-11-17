struct D2UnitStrc;
struct D2StatListStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}

    int isNewline() const
    {
        return wChar == '\n';
    }
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned char nLines[2];
    unsigned char nColor[4];
    unsigned char dwEndTick[4];
    unsigned char pNext[4];
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};

struct D2NamePacketStrc
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nValue[4];
};

struct ListBoxImplementation
{
    void* f_0;
    char unk0x000004[0x18070C];
    int nTextWidth;

    void sub_004BE410_DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410
int __fastcall sub_00501730_GetTextWidthN(const Unicode* wszText, int nLength);                            // 0x00501730
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
T0044CB60* __fastcall sub_00502970_SplitText(Unicode* pText, int* pLineCount, int nWidth);            // 0x00502970
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                 // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc);                                     // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...);                  // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, int nArg, int nArg2, int nArg5); // 0x0065FEC0
extern "C" const char szIntFormat_006D6454[];                                                               // 0x006D6454
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2TextListStrc gtTextList_007BF1E4;                                                                  // 0x007BF1E4
int gnGlobal_007C0E60;                                                                                      // 0x007C0E60
extern Unicode gwszName_007C0E84[];                                                                         // 0x007C0E84

// 0x0049AAA0
int __fastcall sub_0049AAA0_GetCenteredStringX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - sub_00501820(wszText) / 2;
}

// 0x0049DC40
void __cdecl sub_0049DC40_DrawTextList()
{
    int i;
    int nLine;
    D2TextNodeStrc* pNode;
    T0044CB60* pNextLine;
    int nBaseY;
    int bSplit;
    int nOldFont;
    int nLineCount;
    int nX;
    int nWidth;
    int nY;
    T0044CB60* pTextLine;

    if (!gtTextList_007BF1E4.nCount)
    {
        return;
    }

    nOldFont = sub_00502EF0(0xD);
    pNode = gtTextList_007BF1E4.pFirst;
    nBaseY = 0x14;
    if (sub_004538D0(0x13))
    {
        nBaseY = 0x5F;
    }

    nX = 0xF;
    nLine = 0;
    bSplit = 0;
    switch (sub_0045AE90())
    {
    case 1:
        bSplit = 1;
        break;

    case 2:
        nX = gnGlobal_0071146C / 2 + 0xF;
        bSplit = 1;
        break;
    }

    for (; pNode; pNode = *(D2TextNodeStrc**)pNode->pNext)
    {
        for (i = 0; i < 6; ++i)
        {
            if (!pNode->pLines[i])
            {
                continue;
            }

            if (bSplit)
            {
                Unicode wszText[0x190];
                sub_005267E0(wszText, pNode->pLines[i]);
                pTextLine = sub_00502970_SplitText(wszText, &nLineCount, 0x12C);
                if (pTextLine)
                {
                    nY = 15 * nLine + nBaseY;
                    do
                    {
                        pNextLine = pTextLine->pNext;
                        nWidth = sub_00501730_GetTextWidthN(pTextLine->pText, sub_00526800(pTextLine->pText));
                        if (nWidth)
                        {
                            sub_0046EFD0_DrawFramedBox(nX - 5, nY - 0xE, nWidth + 0xA, 0x10, 0, 1);
                            sub_00502320(pTextLine->pText, nX, nY, *(int*)pNode->nColor, 0);
                            ++nLine;
                            nY += 0xF;
                        }
                        FOG_Free(pTextLine->pText, ".\\UI\\text.cpp", 0xA47, 0);
                        FOG_Free(pTextLine, ".\\UI\\text.cpp", 0xA48, 0);
                        pTextLine = pNextLine;
                    }
                    while (pTextLine);
                }
            }
            else
            {
                nWidth = sub_00501730_GetTextWidthN(pNode->pLines[i], sub_00526800(pNode->pLines[i]));
                if (nWidth)
                {
                    sub_0046EFD0_DrawFramedBox(nX - 4, 15 * nLine + nBaseY - 0xE, nWidth + 8, 0x10, 0, 1);
                    sub_00502320(pNode->pLines[i], nX, 15 * nLine + nBaseY, *(int*)pNode->nColor, 0);
                    ++nLine;
                }
            }
        }
    }

    pNode = gtTextList_007BF1E4.pFirst;
    D2TextNodeStrc* pPrevious = 0;
    const unsigned long dwTick = GetTickCount();
    while (pNode)
    {
        if (*(unsigned long*)pNode->dwEndTick < dwTick)
        {
            --gtTextList_007BF1E4.nCount;
            D2TextNodeStrc* pNext = *(D2TextNodeStrc**)pNode->pNext;
            if (gtTextList_007BF1E4.pFirst == pNode)
            {
                gtTextList_007BF1E4.pFirst = pNext;
            }
            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
            if (pPrevious)
            {
                *(D2TextNodeStrc**)pPrevious->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrevious = pNode;
            pNode = *(D2TextNodeStrc**)pNode->pNext;
        }
    }

    sub_00502EF0(nOldFont);
}

// 0x004B9010
void __fastcall sub_004B9010_SetNameFromPacket(D2NamePacketStrc* pPacket)
{
    char szName[16];
    memcpy(szName, pPacket->szName, 16);
    szName[15] = 0;
    sub_00526F20_ToUnicode(gwszName_007C0E84, szName, 16);
    gnGlobal_007C0E60 = *(int*)pPacket->nValue;
}

// 0x004BE410
void ListBoxImplementation::sub_004BE410_DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor)
{
    Unicode wszText[1024];
    sub_005267E0(wszText, wszSource);
    if (sub_00501730_GetTextWidthN(wszText, sub_00526800(wszText)) < nTextWidth - 0x32)
    {
        sub_00502320(wszText, nX, nY, nColor, 0);
        return;
    }

    while (sub_00501730_GetTextWidthN(wszText, sub_00526800(wszText)) > nTextWidth - 0x32)
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
    sub_00502320(wszText, nX, nY, nColor, 0);
}

// 0x004E48B0
void __fastcall sub_004E48B0_BuildText(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused)
{
    Unicode wszText[0x80];
    const Unicode* wszA = D2LANG_GetStringFromTblIndex(0xFA2);
    const Unicode* wszB = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* wszC = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszD = D2LANG_GetStringFromTblIndex(0xFA1);
    Unicode wszNumber[10];
    char szNumber[10];
    SStrPrintf(szNumber, 10, szIntFormat_006D6454, 0x32);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszA);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszD);
    sub_00526700(wszText, wszC);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xDE2));
    sub_00526700(wszText, wszB);
    sub_00526700(wszOut, wszText);
}

// 0x004E6720
void __fastcall sub_004E6720_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4)
{
    sub_0065FEC0_ItemApplyProps(5, 0, pItem, nArg, nArg2, 0);
    Unicode wszBuffer[1024];
    wszBuffer[0].wChar = 0;
    sub_004E6410_BuildPropText(pItem, wszBuffer, nArg3, 1, nArg4);
    sub_00526700(wszText, wszBuffer);

    D2StatListStrc* pStatList = sub_00625790_UnitFindStatList(pItem, 0, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    if (wszText[sub_00526800(wszText) - 1].isNewline())
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
}

// 0x004ED3F0
void __stdcall sub_004ED3F0_DrawHintText(int nArg1, int nStringIndex)
{
    Unicode wszText[100];
    sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1058), nArg1);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    sub_00502280_SetPopUpText(wszText, gnGlobal_0071146C - 0x80, gnGlobal_00711470 - 0x34, 0, 1);
}

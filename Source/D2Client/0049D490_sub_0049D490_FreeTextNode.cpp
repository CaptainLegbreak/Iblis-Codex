extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260

struct Unicode
{
    unsigned short wChar;
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};
#pragma pack(pop)

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
    virtual void AddName(const char* szName, int nSize);
};

class ListBoxWrapper
{
public:
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0C();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1C();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2C();
    virtual void Slot30(); virtual void Slot34(); virtual void Slot38();
    virtual void Refresh();
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);       // 0x00502970
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
int __fastcall sub_00526D30(const Unicode* pText, int nCount);                                              // 0x00526D30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00501730_GetTextWidthN(const Unicode* wszText, int nLength);                             // 0x00501730
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __cdecl sub_0049E340();                                                                                // 0x0049E340
D2TextNodeStrc* __fastcall sub_0049DB10_CloneStringList(D2TextNodeStrc* pSource);                           // 0x0049DB10
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList();                                                   // 0x00611560

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern ListBoxWrapper* gpListBox_007BF1B4;                                                                  // 0x007BF1B4
extern D2TextListStrc gtTextList_007BF1E4;                                                                  // 0x007BF1E4
extern D2TextListStrc gtTextList_007BF1EA;                                                                  // 0x007BF1EA
extern D2TextListStrc gtTextList_007BF1F0;                                                                  // 0x007BF1F0

// 0x0049D490
static void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}

void __fastcall sub_0049DBC0_AddToHistory(D2TextNodeStrc* pSource)
{
    D2TextNodeStrc* pClone = sub_0049DB10_CloneStringList(pSource);
    D2TextNodeStrc* pNode;
    if (gtTextList_007BF1F0.nCount >= 0x80)
    {
        pNode = gtTextList_007BF1F0.pFirst;
        if (pNode)
        {
            D2TextNodeStrc* pPrevious = 0;
            while (pNode->pNext)
            {
                pPrevious = pNode;
                pNode = pNode->pNext;
            }
            sub_0049D490_FreeTextNode(pNode);
            if (pPrevious)
                pPrevious->pNext = 0;
            if (gtTextList_007BF1F0.nCount >= 1)
                gtTextList_007BF1F0.nCount--;
        }
    }
    pNode = gtTextList_007BF1F0.pFirst;
    pClone->pNext = pNode;
    gtTextList_007BF1F0.nCount++;
    gtTextList_007BF1F0.pFirst = pClone;
}

void __fastcall sub_0049E3A0_PrintChatLine(const Unicode* wszText, char nColor)
{
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xD46, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;
    const int nOldFont = sub_00502EF0(0xD);

    int nLines;
    T0044CB60* pLine = sub_00502970_SplitText(wszText, &nLines, gnGlobal_0071146C - 0x46);
    pNode->nLines = (unsigned int)nLines > 6 ? 6 : nLines;
    for (int i = 0; i < nLines; i++)
    {
        if (i < pNode->nLines)
            pNode->pLines[i] = pLine->pText;
        else
            FOG_Free(pLine->pText, ".\\UI\\text.cpp", 0xD5A, 0);
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine, ".\\UI\\text.cpp", 0xD5D, 0);
        pLine = pNext;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtTextList_007BF1E4.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextList_007BF1E4.pFirst;
        unsigned short nCount = 0;
        for (D2TextNodeStrc** ppNext = &pLast->pNext; *ppNext; ppNext = &pLast->pNext)
        {
            pLast = *ppNext;
            nCount++;
        }
        D2_ASSERT(nCount == gtTextList_007BF1E4.nCount - 1, 0xD6C);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextList_007BF1E4.pFirst = pNode;
    }

    if (pNode->nColor == 4 && pNode->nLines == 1)
    {
        char szName[0x100] = { 0 };
        sub_005263E0(szName, pNode->pLines[0], 0x100);
        sub_00611560_GetSquelchList()->AddName(szName, 0x100);
    }

    sub_0049DBC0_AddToHistory(pNode);
    gtTextList_007BF1E4.nCount++;

    int nTotal = 0;
    for (D2TextNodeStrc* p = gtTextList_007BF1E4.pFirst; p; p = p->pNext)
        nTotal += p->nLines;
    if (nTotal > 0x12)
    {
        D2TextNodeStrc* pFirst = gtTextList_007BF1E4.pFirst;
        gtTextList_007BF1E4.nCount--;
        gtTextList_007BF1E4.pFirst = pFirst->pNext;
        sub_0049D490_FreeTextNode(pFirst);
    }

    sub_004B9A00(6, 0, 0, 0, 0);
    if (sub_004538D0(0x18) && gpListBox_007BF1B4)
    {
        gpListBox_007BF1B4->Refresh();
        sub_0049E340();
    }
    sub_00502EF0(nOldFont);
}

void __fastcall sub_0049E5C0_PrintWrappedLine(const Unicode* wszText, char nColor)
{
    const int nOldFont = sub_00502EF0(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = sub_00526800(wszText);
    const int nTotal = nCount;
    int nStart = 0;
    pNode->nLines = 0;
    while (nCount > 0)
    {
        while (sub_00501730_GetTextWidthN(&wszText[nStart], nCount) > gnGlobal_0071146C - 0x46)
        {
            nCount--;
            if (nCount <= 0)
                break;
        }
        if (nStart + nCount != nTotal)
        {
            while (nCount > 0 && !sub_00526D30(&wszText[nStart], nCount + 1))
                nCount--;
        }
        if (!nCount)
            break;

        const Unicode* pSource = &wszText[nStart];
        char szLine[0x400];
        sub_005263E0(szLine, pSource, nCount);
        if (pNode->nLines >= 6)
            break;

        const int nSize = nCount * 2 + 2;
        pNode->pLines[pNode->nLines] = (Unicode*)FOG_Alloc(nSize, ".\\UI\\text.cpp", 0xDD7, 0);
        memset(pNode->pLines[pNode->nLines], 0, nSize);
        sub_00526790(pNode->pLines[pNode->nLines], pSource, nCount);
        pNode->nLines++;
        nStart = nCount;
        nCount = nTotal - nCount;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtTextList_007BF1EA.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextList_007BF1EA.pFirst;
        unsigned short nNodes = 0;
        while (pLast->pNext)
        {
            pLast = pLast->pNext;
            nNodes++;
        }
        D2_ASSERT(nNodes == gtTextList_007BF1EA.nCount - 1, 0xDF1);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextList_007BF1EA.pFirst = pNode;
    }
    gtTextList_007BF1EA.nCount++;
    sub_0049DBC0_AddToHistory(pNode);

    if (gtTextList_007BF1EA.nCount > 2)
    {
        D2TextNodeStrc* pFirst = gtTextList_007BF1EA.pFirst;
        gtTextList_007BF1EA.pFirst = pFirst->pNext;
        sub_0049D490_FreeTextNode(pFirst);
        gtTextList_007BF1EA.nCount--;
    }

    if (sub_004538D0(0x18) && gpListBox_007BF1B4)
    {
        gpListBox_007BF1B4->Refresh();
        sub_0049E340();
    }
    sub_00502EF0(nOldFont);
    sub_004B9A00(6, 0, 0, 0, 0);
}

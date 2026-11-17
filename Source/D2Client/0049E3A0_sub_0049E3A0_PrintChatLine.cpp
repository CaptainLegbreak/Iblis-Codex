extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
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
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __cdecl sub_0049E340();                                                                                // 0x0049E340
void __fastcall sub_0049DBC0_AddToHistory(D2TextNodeStrc* pSource);                                         // 0x0049DBC0
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList();                                                   // 0x00611560

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern ListBoxWrapper* gpListBox_007BF1B4;                                                                  // 0x007BF1B4
D2TextListStrc gtTextList_007BF1E4;                                                                         // 0x007BF1E4

// 0x0049D490
static __declspec(noinline) void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}

// 0x0049E3A0
void __fastcall sub_0049E3A0_PrintChatLine(const Unicode* wszText, char nColor)
{
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xD46, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;
    int nOldFont = sub_00502EF0(0xD);

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
        D2TextNodeStrc** ppNext = &pLast->pNext;
        if (pLast->pNext)
        {
            do
            {
                pLast = *ppNext;
                ppNext = &pLast->pNext;
                nCount++;
            }
            while (*ppNext);
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
        char szName[0x100] = {0};
        sub_005263E0(szName, pNode->pLines[0], 0x100);
        sub_00611560_GetSquelchList()->AddName(szName, 0x100);
    }

    sub_0049DBC0_AddToHistory(pNode);
    gtTextList_007BF1E4.nCount++;

    int nTotal = 0;
    D2TextNodeStrc* p = gtTextList_007BF1E4.pFirst;
    if (gtTextList_007BF1E4.pFirst)
    {
        do
        {
            nTotal += p->nLines;
            p = p->pNext;
        }
        while (p);
    }
    if (nTotal > 0x12)
    {
        D2TextNodeStrc* pOld = gtTextList_007BF1E4.pFirst;
        gtTextList_007BF1E4.pFirst = gtTextList_007BF1E4.pFirst->pNext;
        gtTextList_007BF1E4.nCount--;
        sub_0049D490_FreeTextNode(pOld);
    }

    sub_004B9A00(6, 0, 0, 0, 0);
    if (sub_004538D0(0x18) && gpListBox_007BF1B4)
    {
        gpListBox_007BF1B4->Refresh();
        sub_0049E340();
    }
    sub_00502EF0(nOldFont);
}

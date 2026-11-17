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

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    unsigned char pNext[4];
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};
#pragma pack(pop)

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
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount);                           // 0x00526790
int __fastcall sub_00526D30(const Unicode* pText, int nCount);                                              // 0x00526D30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall D2Win_10123(const Unicode* wszText, int nLength);                                            // 0x00501730
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __cdecl sub_0049E340();                                                                                // 0x0049E340
void __fastcall sub_0049DBC0_AddToHistory(D2TextNodeStrc* pSource);                                         // 0x0049DBC0
static __declspec(noinline) void sub_0049D490_FreeTextNode(D2TextNodeStrc* pNode);

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern ListBoxWrapper* gpListBox_007BF1B4;                                                                  // 0x007BF1B4
extern D2TextListStrc gtTextList_007BF1EA;                                                                  // 0x007BF1EA

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

// 0x0049E5C0
void __fastcall sub_0049E5C0_PrintPartyText(const Unicode* wszText, char nColor)
{
    const int nOldFont = sub_00502EF0(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, 0x24);
    *(D2TextNodeStrc**)pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = sub_00526800(wszText);
    const int nTotal = nCount;
    int nStart = 0;
    pNode->nLines = 0;
    for (;;)
    {
        while (nCount > 0 && D2Win_10123(&wszText[nStart], nCount) > gnGlobal_0071146C - 0x46)
            nCount--;

        if (nStart + nCount != nTotal)
        {
            while (nCount > 0 && !sub_00526D30(&wszText[nStart], nCount + 1))
                nCount--;
        }

        if (!nCount)
            break;

        const Unicode* pSource = &wszText[nStart];
        int aLine[0x100];
        sub_005263E0((char*)aLine, pSource, nCount);
        if (pNode->nLines >= 6)
            break;

        const int nSize = nCount * 2 + 2;
        pNode->pLines[pNode->nLines] = (Unicode*)FOG_Alloc(nSize, ".\\UI\\text.cpp", 0xDD7, 0);
        memset(pNode->pLines[pNode->nLines], 0, nSize);
        strncpy(pNode->pLines[pNode->nLines], pSource, nCount);
        pNode->nLines++;
        nStart = nCount;
        nCount = nTotal - nCount;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtTextList_007BF1EA.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextList_007BF1EA.pFirst;
        unsigned short nNodes = 0;
        D2TextNodeStrc** ppNext = (D2TextNodeStrc**)pLast->pNext;
        if (*ppNext)
        {
            do
            {
                pLast = *ppNext;
                ppNext = (D2TextNodeStrc**)pLast->pNext;
                nNodes++;
            } while (*ppNext);
        }
        D2_ASSERT(nNodes == gtTextList_007BF1EA.nCount - 1, 0xDF1);
        *(D2TextNodeStrc**)pLast->pNext = pNode;
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
        gtTextList_007BF1EA.pFirst = *(D2TextNodeStrc**)gtTextList_007BF1EA.pFirst->pNext;
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

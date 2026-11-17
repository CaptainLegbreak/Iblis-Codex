extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszExcelCppFile[];                                                                    // 0x006FC448

struct D2TxtLinkNodeStrc
{
    char szText[0x20];
    int nLinkIndex;
    D2TxtLinkNodeStrc* pLeft;
    D2TxtLinkNodeStrc* pRight;
};

struct D2TxtLinkStrc
{
    int nRecords;
    int nAllocatedCells;
    void* pTbl;
    D2TxtLinkNodeStrc* pRoot;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
void __fastcall sub_004113C0(char* szText, int nLength);                                                    // 0x004113C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn);                  // 0x006BD3C0

static __declspec(noinline) void sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppNode, D2TxtLinkNodeStrc* pNew);

static void sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppNode, D2TxtLinkNodeStrc* pNew)
{
    while (*ppNode)
    {
        D2TxtLinkNodeStrc* pNode = *ppNode;
        const int nCmp = strcmp(pNew->szText, pNode->szText);
        if (nCmp < 0)
        {
            ppNode = &pNode->pLeft;
        }
        else if (nCmp > 0)
        {
            ppNode = &pNode->pRight;
        }
        else
        {
            FOG_FreePool(0, pNew, gszExcelCppFile, 0x4A7, 0);
            return;
        }
    }

    *ppNode = pNew;
}

// 0x006BD5A0
int __fastcall sub_006BD5A0_AddTxtLink(D2TxtLinkStrc* pLinker, const char* szText)
{
    D2_ASSERT(pLinker, 0x4CC);
    D2_ASSERT(!pLinker->pTbl, 0x4D0);

    const int nRow = FOG_GetRowFromTxt(pLinker, szText, 0);
    if (nRow >= 0)
    {
        return nRow;
    }

    D2TxtLinkNodeStrc* pNode = (D2TxtLinkNodeStrc*)FOG_AllocPool(0, sizeof(D2TxtLinkNodeStrc), gszExcelCppFile, 0x4D9, 0);
    memset(pNode, 0, sizeof(D2TxtLinkNodeStrc));
    SStrCopy(pNode->szText, szText, sizeof(pNode->szText));
    sub_004113C0(pNode->szText, sizeof(pNode->szText));
    pNode->nLinkIndex = pLinker->nRecords;
    sub_006BD490_InsertNode(&pLinker->pRoot, pNode);
    return pLinker->nRecords++;
}

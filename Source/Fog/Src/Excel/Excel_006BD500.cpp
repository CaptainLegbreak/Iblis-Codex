extern "C" const char gszEmptyAssertText;                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
#pragma intrinsic(memset)
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B430
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0
void __fastcall sub_004113C0(char* szString, int nLength); // 0x004113C0

struct D2LinkNode006BD500Strc
{
    char szCode[0x20];
    int nIndex;
    D2LinkNode006BD500Strc* pLeft;
    D2LinkNode006BD500Strc* pRight;
};

struct D2LinkTree006BD500Strc
{
    D2LinkNode006BD500Strc* pRoot;
};

struct D2BinLinker006BD500Strc
{
    int nCount;
    unsigned char unk_04[0x04];
    void* pLocked;
    D2LinkTree006BD500Strc tTree;
};

struct D2TxtLinkNodeStrc
{
    char szText[32];
    int nLinkIndex;
    D2TxtLinkNodeStrc* pPrevious;
    D2TxtLinkNodeStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

static __declspec(noinline) void __cdecl sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppLink, D2TxtLinkNodeStrc* pNode);

// 0x006BD490
static void __cdecl sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppLink, D2TxtLinkNodeStrc* pNode)
{
    while (*ppLink)
    {
        D2TxtLinkNodeStrc* pCurrent = *ppLink;
        const int nCompare = strcmp(pNode->szText, pCurrent->szText);
        if (nCompare < 0)
        {
            ppLink = &pCurrent->pPrevious;
        }
        else if (nCompare > 0)
        {
            ppLink = &pCurrent->pNext;
        }
        else
        {
            FOG_FreePool(0, pNode, ".\\Src\\Excel\\Excel.cpp", 1191, 0);
            return;
        }
    }

    *ppLink = pNode;
}

// 0x006BD500
int __stdcall sub_006BD500_AddCode(D2BinLinker006BD500Strc* pLinker, const char* szCode)
{
    D2_ASSERT(pLinker, 0x4B2);
    D2_ASSERT(!pLinker->pLocked, 0x4B6);

    D2LinkNode006BD500Strc* pNode = (D2LinkNode006BD500Strc*)FOG_AllocPool(0, sizeof(D2LinkNode006BD500Strc), ".\\Src\\Excel\\Excel.cpp", 0x4B9, 0);
    memset(pNode, 0, sizeof(D2LinkNode006BD500Strc));
    SStrCopy(pNode->szCode, szCode, 0x20);
    sub_004113C0(pNode->szCode, 0x20);
    pNode->nIndex = pLinker->nCount;
    sub_006BD490_InsertNode((D2TxtLinkNodeStrc**)&pLinker->tTree, (D2TxtLinkNodeStrc*)pNode);
    return pLinker->nCount++;
}

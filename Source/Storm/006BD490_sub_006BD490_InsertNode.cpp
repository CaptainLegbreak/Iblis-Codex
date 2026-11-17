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

// build: context sub_006BD490_Shim
// calling-convention shim (not game code)
void __cdecl sub_006BD490_Shim(D2TxtLinkNodeStrc** ppRoot, D2TxtLinkNodeStrc* pNode)
{
    sub_006BD490_InsertNode(ppRoot, pNode);
}

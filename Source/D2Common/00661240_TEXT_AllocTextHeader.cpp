struct D2TextNodeStrc
{
    short nStringId;
    unsigned short pad0x02;
    int nMenu;
    D2TextNodeStrc* pNext;
};

struct D2TextHeaderStrc
{
    void* pMemPool;
    unsigned short nCount;
    unsigned short pad0x06;
    D2TextNodeStrc* pNode;
};

struct D2MessageStrc
{
    unsigned char nMenu;
    unsigned char pad0x01;
    unsigned short nStringId;
};

struct D2MessageListStrc
{
    unsigned char nCount;
    unsigned char pad0x01;
    D2MessageStrc pMessages[8];
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);               // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);             // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define TEXT_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00661240
D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(void* pMemPool)
{
    D2TextHeaderStrc* pTextHeader = (D2TextHeaderStrc*)sub_0040B430(pMemPool, sizeof(D2TextHeaderStrc), ".\\Text\\Text.cpp", 43, 0);
    pTextHeader->pMemPool = pMemPool;
    pTextHeader->pNode = 0;
    pTextHeader->nCount = 0;
    return pTextHeader;
}

// 0x00661270
static void sub_00661270(D2TextHeaderStrc* pTextHeader)
{
    D2TextNodeStrc* pNode = pTextHeader->pNode;
    while (pNode)
    {
        D2TextNodeStrc* pNext = pNode->pNext;
        sub_0040B480(pTextHeader->pMemPool, pNode, ".\\Text\\Text.cpp", 60, 0);
        pNode = pNext;
    }

    pTextHeader->nCount = 0;
}

// 0x006612A0
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader)
{
    sub_00661270(pTextHeader);
    sub_0040B480(pTextHeader->pMemPool, pTextHeader, ".\\Text\\Text.cpp", 76, 0);
}

// 0x006612F0
void __stdcall TEXT_AddNodeToTextList(D2TextHeaderStrc* pTextHeader, short nStringId, int nMenu)
{
    D2TextNodeStrc* pNext = pTextHeader->pNode;
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)sub_0040B430(pTextHeader->pMemPool, sizeof(D2TextNodeStrc), ".\\Text\\Text.cpp", 90, 0);
    pNode->pNext = pNext;
    pNode->nStringId = nStringId;
    pNode->nMenu = nMenu;

    ++pTextHeader->nCount;
    pTextHeader->pNode = pNode;
}

// 0x00661330
void __stdcall TEXT_RemoveNodeFromTextList(D2TextHeaderStrc* pTextHeader, short nStringId)
{
    D2TextNodeStrc* pPrevious = 0;
    D2TextNodeStrc* pNode = pTextHeader->pNode;
    while (pNode)
    {
        if (pNode->nStringId == nStringId)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pNode->pNext;
            }
            else
            {
                pTextHeader->pNode = pNode->pNext;
            }

            sub_0040B480(pTextHeader->pMemPool, pNode, ".\\Text\\Text.cpp", 123, 0);
            --pTextHeader->nCount;
            return;
        }

        pPrevious = pNode;
        pNode = pNode->pNext;
    }
}

// 0x00661390
int __stdcall TEXT_GetMenuType2NodeCount(D2TextHeaderStrc* pTextHeader)
{
    int nNodes = 0;
    for (D2TextNodeStrc* pNode = pTextHeader->pNode; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMenu == 2)
        {
            ++nNodes;
        }
    }

    return nNodes;
}

// 0x006613C0
short __stdcall TEXT_GetStringIdOfMenuType2Node(D2TextHeaderStrc* pTextHeader, int nNodeId)
{
    int nCounter = 0;
    D2TextNodeStrc* pNode = pTextHeader->pNode;
    while (pNode)
    {
        if (pNode->nMenu == 2)
        {
            if (nCounter == nNodeId)
            {
                return pNode->nStringId;
            }

            ++nCounter;
        }

        pNode = pNode->pNext;
    }

    return 3724;
}

// 0x00661400
short __stdcall sub_00661400(D2TextHeaderStrc* pTextHeader, int nNodeId)
{
    int nCounter = 0;
    D2TextNodeStrc* pNode = pTextHeader->pNode;
    while (pNode)
    {
        if (pNode->nMenu == 0)
        {
            if (nCounter == nNodeId)
            {
                return pNode->nStringId;
            }

            ++nCounter;
        }

        pNode = pNode->pNext;
    }

    return -1;
}

// 0x00661440
short __stdcall sub_00661440(D2TextHeaderStrc* pTextHeader, int nNodeId)
{
    int nCounter = 0;
    D2TextNodeStrc* pNode = pTextHeader->pNode;
    while (pNode)
    {
        if (pNode->nMenu == 1)
        {
            if (nCounter == nNodeId)
            {
                return pNode->nStringId;
            }

            ++nCounter;
        }

        pNode = pNode->pNext;
    }

    return -1;
}

// 0x00661480
void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMsgList)
{
    TEXT_ASSERT(pTextHeader, 237);
    TEXT_ASSERT(pMsgList, 238);

    memset(pMsgList, 0, sizeof(D2MessageListStrc));
    D2TextNodeStrc* pNode = pTextHeader->pNode;
    pMsgList->nCount = (unsigned char)pTextHeader->nCount;

    for (int i = 0; pNode; pNode = pNode->pNext)
    {
        TEXT_ASSERT(i < 8, 248);

        pMsgList->pMessages[i].nMenu = (unsigned char)pNode->nMenu;
        pMsgList->pMessages[i].nStringId = pNode->nStringId;
        ++i;
    }
}

// 0x00661510
void __stdcall TEXT_CreateTextHeaderFromMessageList(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMsgList)
{
    TEXT_ASSERT(pTextHeader, 267);
    TEXT_ASSERT(pMsgList, 268);

    sub_00661270(pTextHeader);

    TEXT_ASSERT(pMsgList->nCount < 8, 274);

    for (int i = 0; i < pMsgList->nCount; ++i)
    {
        TEXT_AddNodeToTextList(pTextHeader, pMsgList->pMessages[i].nStringId, pMsgList->pMessages[i].nMenu);
    }
}

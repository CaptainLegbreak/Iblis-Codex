extern "C" void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B380
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2QMsg006C23B0Strc
{
    unsigned int nSize;
    D2QMsg006C23B0Strc* pNext;
    unsigned char pData[1];
};

struct D2QConn006C23B0Strc
{
    unsigned char unk_00[0x74];
    D2QMsg006C23B0Strc* pMsgHead;
};

static __declspec(noinline) void __stdcall sub_006C23B0_QueueMessage(D2QConn006C23B0Strc* pConn, unsigned int nSize, const void* pData);

// 0x006C23B0
static void __stdcall sub_006C23B0_QueueMessage(D2QConn006C23B0Strc* pConn, unsigned int nSize, const void* pData)
{
    D2QMsg006C23B0Strc* pMsg = (D2QMsg006C23B0Strc*)FOG_Alloc(nSize + 8, ".\\Src\\QServer\\QServerNT.cpp", 0x440, 0);
    memcpy(pMsg->pData, pData, nSize);
    pMsg->nSize = nSize;
    pMsg->pNext = 0;
    if (!pConn->pMsgHead)
    {
        pConn->pMsgHead = pMsg;
        return;
    }
    D2QMsg006C23B0Strc* pLast = pConn->pMsgHead;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pMsg;
}

// calling-convention shim (not game code)
void __stdcall shim_11(D2QConn006C23B0Strc* pConn, unsigned int nSize, const void* pData)
{
    sub_006C23B0_QueueMessage(pConn, nSize, pData);
}

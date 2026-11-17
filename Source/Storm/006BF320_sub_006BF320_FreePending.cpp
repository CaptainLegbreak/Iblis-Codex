typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct sub_006BF320_Node
{
    char unk_00[0x0C];
    sub_006BF320_Node* pNext;
};

struct sub_006BF320_Server
{
    char unk_000[0x84C];
    sub_006BF320_Node* pPending;
    char unk_850[4];
    char cs[0x18];
};

static __declspec(noinline) void sub_006BF320_FreePending(sub_006BF320_Server* pServer);
// 0x006BF320
static void sub_006BF320_FreePending(sub_006BF320_Server* pServer)
{
    EnterCriticalSection((CRITICAL_SECTION*)pServer->cs);
    sub_006BF320_Node* pNode = pServer->pPending;
    while (pNode)
    {
        sub_006BF320_Node* pFree = pNode;
        pNode = pNode->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 2480, 0);
    }
    pServer->pPending = 0;
    LeaveCriticalSection((CRITICAL_SECTION*)pServer->cs);
}

// calling-convention shim (not game code)
void __fastcall sub_006BF320_Shim(sub_006BF320_Server* pServer)
{
    sub_006BF320_FreePending(pServer);
    FOG_Free(pServer, ".\\Src\\QServer\\QServer.cpp", 0, 0);
}

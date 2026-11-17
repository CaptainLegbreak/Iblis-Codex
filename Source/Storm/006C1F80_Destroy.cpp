struct D2CriticalSection006C1F80Strc
{
    int aData[6];
};
struct D2QSNode006C1F80Strc
{
    int unk00;
    D2QSNode006C1F80Strc* pNext;
};
struct D2QSQueue006C1F80Strc
{
    int unk00;
    D2CriticalSection006C1F80Strc tLock;
    D2QSNode006C1F80Strc* pHead;
    int nCount;

    void Destroy();
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSection006C1F80Strc* pLock); // 0x006CC1FC

// 0x006C1F80
void D2QSQueue006C1F80Strc::Destroy()
{
    D2QSNode006C1F80Strc* pNode = pHead;
    while (pHead)
    {
        pNode = pNode->pNext;
        FOG_Free(pHead, ".\\Src\\D2QSQueue.cpp", 0x27, 0);
        pHead = pNode;
    }
    nCount = 0;
    pHead = 0;
    DeleteCriticalSection(&tLock);
}

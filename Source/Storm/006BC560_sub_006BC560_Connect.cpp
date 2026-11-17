struct sub_006BC560_Strc
{
    char unk_000[8];
    char pSocket[0x104];
    int nPort;
    int nResult;
    char unk_114[0x14];
    char pAddress[4];
};

void __stdcall sub_006BC3A0(void* pContext); // 0x006BC3A0
int __fastcall FOG_SOCKET_Connect(void* pSocket, int nPort, void (__stdcall* pfnCallback)(void*), void* pContext, void* pAddress); // 0x0040E230

// 0x006BC560
int __stdcall sub_006BC560_Connect(sub_006BC560_Strc* pThis)
{
    pThis->nResult = FOG_SOCKET_Connect(pThis->pSocket, pThis->nPort, sub_006BC3A0, pThis, pThis->pAddress);
    return 1;
}

#include "Fog.h"
D2Connection006C03A0Strc* __fastcall sub_006BE540_Find(D2Server006C03A0Strc* pServer, unsigned int nKey); // 0x006BE540
int __fastcall sub_006C3410_Send(D2Server006C03A0Strc* pServer, D2Connection006C03A0Strc* pConnection, int a, int b); // 0x006C3410

static __declspec(noinline) int __fastcall sub_006BF500_Dispatch(D2Server006C03A0Strc*, D2Connection006C03A0Strc*, int, int);
// 0x006BF500
static int __fastcall sub_006BF500_Dispatch(D2Server006C03A0Strc* pServer, D2Connection006C03A0Strc* pConnection, int a, int b)
{
    if (!pConnection || pConnection->bClosing) return 0;
    if (pServer->bQueued) return sub_006C2C70_Queue(pServer, pConnection, a, b);
    return sub_006C3410_Send(pServer, pConnection, a, b);
}

// build: context sub_006C03A0_SendToKey
int __stdcall sub_006C03A0_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b)
{
    if (!pServer)
    {
        return 0;
    }
    if ((pServer->nMode == 1 || pServer->nMode == 2) && pServer->pfnHandler)
    {
        return pServer->pfnHandler(pServer, a, b);
    }
    D2Connection006C03A0Strc* pConnection = sub_006BE540_Find(pServer, nKey);
    return sub_006BF500_Dispatch(pServer, pConnection, a, b);
}

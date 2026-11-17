struct D2Connection006C03A0Strc
{
    unsigned char unk_00[0x0C];
    int bClosing;
};
struct D2Server006C03A0Strc
{
    int bQueued;
};
D2Connection006C03A0Strc* __fastcall sub_006BE540_Find(D2Server006C03A0Strc* pServer, unsigned int nKey); // 0x006BE540
int __fastcall sub_006C2C70_Queue(D2Server006C03A0Strc* pServer, D2Connection006C03A0Strc* pConnection, int a, int b); // 0x006C2C70
int __fastcall sub_006C3410_Send(D2Server006C03A0Strc* pServer, D2Connection006C03A0Strc* pConnection, int a, int b); // 0x006C3410

static int sub_006C0140_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b); // 0x006C0140

// 0x006C0140
static int sub_006C0140_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b)
{
    if (!pServer)
    {
        return 0;
    }
    D2Connection006C03A0Strc* pConnection = sub_006BE540_Find(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bQueued)
    {
        return sub_006C2C70_Queue(pServer, pConnection, a, b);
    }
    return sub_006C3410_Send(pServer, pConnection, a, b);
}

// calling-convention shim (not game code)
int __stdcall sub_CallSite_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b)
{
    return sub_006C0140_SendToKey(pServer, nKey, a, b);
}

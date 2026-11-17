struct D2QClientStrc
{
    unsigned int nId;
};

struct T006BE350;
typedef void (__fastcall* D2QAcceptCallback)(T006BE350* pServer, unsigned int nId, const char* szFile, int nLine);

struct T006BE350
{
    char unk_000[0xBC4];
    D2QAcceptCallback pfnOnAccept;
};

D2QClientStrc* __fastcall sub_006BFB70_AddClient(T006BE350* pServer, unsigned int s, unsigned int nAddress); // 0x006BFB70

struct D2QAddressArg
{
    unsigned int nAddress;
};

static __declspec(noinline) void __stdcall sub_006C3440_AddClient(T006BE350* pServer, unsigned int s, D2QAddressArg tAddress);

// 0x006C3440
static void __stdcall sub_006C3440_AddClient(T006BE350* pServer, unsigned int s, D2QAddressArg tAddress)
{
    D2QClientStrc* pClient = sub_006BFB70_AddClient(pServer, s, tAddress.nAddress);
    if (pServer->pfnOnAccept)
        pServer->pfnOnAccept(pServer, pClient->nId, ".\\Src\\QServer\\QServer98.cpp", 0x91);
}

void __fastcall sub_Emit_006C3440(T006BE350* pServer, unsigned int s, unsigned int nAddress)
{
    D2QAddressArg tAddress;
    tAddress.nAddress = nAddress;
    sub_006C3440_AddClient(pServer, s, tAddress);
    sub_006C3440_AddClient(pServer, s + 1, tAddress);
}

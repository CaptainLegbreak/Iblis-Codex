struct D2ServerStrc
{
    int __thiscall sub_006BF660_CheckClient(int clientId); // 0x006BF660
};

// 0x006BF6C0
int __fastcall sub_006BF6C0(D2ServerStrc* server, int clientId)
{
    return server->sub_006BF660_CheckClient(clientId);
}

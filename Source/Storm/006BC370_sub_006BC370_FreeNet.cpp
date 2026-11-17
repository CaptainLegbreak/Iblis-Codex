struct Lock { int data[6]; };
struct NetData { char pad00[0xC]; Lock lock; void* thread; int unk28; int blocked; };
struct QSocket { char pad00[0x110]; NetData* net; };
void __fastcall sub_0040DBD0_FreeNet(NetData*); // 0x0040DBD0

static __declspec(noinline) void __stdcall sub_006BC370_FreeNet(QSocket* socket);
// 0x006BC370
static void __stdcall sub_006BC370_FreeNet(QSocket* socket)
{
    if (!socket)
        return;
    NetData* net = socket->net;
    if (!(net && net->thread))
        return;
    sub_0040DBD0_FreeNet(net);
    socket->net = 0;
}

void __stdcall FreeNetContext(QSocket* socket)
{
    sub_006BC370_FreeNet(socket);
}

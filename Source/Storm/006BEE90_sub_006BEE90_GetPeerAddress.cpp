struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2SocketNodeStrc
{
    void* key;
    D2SocketNodeStrc* next;
    unsigned int reserved08[2];
    unsigned int socket;
};
struct D2SocketTableStrc
{
    unsigned int reserved00[3];
    unsigned int mask;
    unsigned int reserved10;
    D2SocketNodeStrc** buckets;
    unsigned int reserved18;
    D2CriticalSectionStrc* locks;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" int __stdcall getpeername(unsigned int, void*, int*); // 0x006B018C

// 0x006BEE90
unsigned int __stdcall sub_006BEE90_GetPeerAddress(D2SocketTableStrc* table, void* key)
{
    const unsigned int index = table->mask & (unsigned int)key;
    EnterCriticalSection(&table->locks[index]);
    D2SocketNodeStrc* node = table->buckets[index];
    while (node)
    {
        if (node->key == key)
        {
            const unsigned int socket = node->socket;
            LeaveCriticalSection(&table->locks[index]);
            char address[16];
            int length = sizeof(address);
            getpeername(socket, address, &length);
            return *(unsigned int*)(address + 4);
        }
        node = node->next;
    }
    LeaveCriticalSection(&table->locks[index]);
    return 0;
}

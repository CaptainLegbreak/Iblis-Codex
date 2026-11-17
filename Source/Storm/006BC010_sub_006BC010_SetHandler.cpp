typedef int (__fastcall* PacketHandler)(const unsigned char* data,unsigned int size,int context);
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
typedef char check_callback_width[sizeof(PacketHandler)==4?1:-1];
struct ConnectionHandlerView
{
    char retained[0x168];
    PacketHandler callback;
    int context;
};
typedef char check_callback[OFFSET(ConnectionHandlerView,callback)==0x168?1:-1];
typedef char check_context[OFFSET(ConnectionHandlerView,context)==0x16c?1:-1];
typedef char check_partial_view[sizeof(ConnectionHandlerView)==0x170?1:-1];

// 0x006BC010
extern "C" void __stdcall sub_006BC010_SetHandler(ConnectionHandlerView* connection,PacketHandler callback,int context)
{
    if (connection)
    {
        connection->callback = callback;
        connection->context = context;
    }
}

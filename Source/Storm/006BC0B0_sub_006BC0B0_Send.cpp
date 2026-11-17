typedef unsigned int U32;
typedef unsigned short U16;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_size[sizeof(void*)==4?1:-1];
struct SafeSocketView
{
    int connected;
};
struct ConnectionView
{
    char retained[0x110];
    SafeSocketView* socket;
};
struct LinkNode
{
    char retained[0x24];
    LinkNode* firstChild;
    LinkNode* secondChild;
};
struct LinkerView
{
    char retained[0x8];
    void* entries;
    LinkNode* root;
};
typedef char check_connected[OFFSET(SafeSocketView,connected)==0?1:-1];
typedef char check_socket[OFFSET(ConnectionView,socket)==0x110?1:-1];
typedef char check_node_first[OFFSET(LinkNode,firstChild)==0x24?1:-1];
typedef char check_node_second[OFFSET(LinkNode,secondChild)==0x28?1:-1];
typedef char check_node_size[sizeof(LinkNode)==0x2C?1:-1];
typedef char check_entries[OFFSET(LinkerView,entries)==0x8?1:-1];
typedef char check_root[OFFSET(LinkerView,root)==0xC?1:-1];
typedef char check_linker_size[sizeof(LinkerView)==0x10?1:-1];
extern "C" void __fastcall sub_0040DDD0_Lock(SafeSocketView* socket);
extern "C" int __fastcall sub_0040DD80_SendNoLock(SafeSocketView* socket,const char* data,int length);
extern "C" void __fastcall sub_0040DDE0_Unlock(SafeSocketView* socket);
extern "C" void __fastcall sub_006BD070_FreeNodes(LinkNode* node);
extern "C" int __fastcall sub_0040B480_FreePool(void* pool,void* block,const char* file,int line,int unused);
extern "C" const char gExcelFile[]; // 0x006FC448

// 0x006BC0B0
extern "C" int __stdcall sub_006BC0B0_Send(ConnectionView* connection,const char* data,U16 length)
{
    if (connection && connection->socket && connection->socket->connected != 0)
    {
        int sent = 0;
        sub_0040DDD0_Lock(connection->socket);
        if (data && length)
            sent = sub_0040DD80_SendNoLock(connection->socket,data,length);
        sub_0040DDE0_Unlock(connection->socket);
        return length == (U16)sent;
    }
    return 0;
}

// 0x006BD0B0
extern "C" void __stdcall sub_006BD0B0_FreeLinker(LinkerView* linker)
{
    if (linker)
    {
        LinkNode* root = linker->root;
        if (root)
        {
            if (root->firstChild)
                sub_006BD070_FreeNodes(root->firstChild);
            if (root->secondChild)
                sub_006BD070_FreeNodes(root->secondChild);
            sub_0040B480_FreePool(0,root,gExcelFile,0x346,0);
        }
        if (linker->entries)
            sub_0040B480_FreePool(0,linker->entries,gExcelFile,0x35D,0);
        sub_0040B480_FreePool(0,linker,gExcelFile,0x360,0);
    }
}

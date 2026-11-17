typedef unsigned int U32;
typedef unsigned char U8;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_size[sizeof(void*)==4?1:-1];
struct PaletteColor
{
    U8 c0;
    U8 c1;
    U8 c2;
    U8 unused;
};
typedef char check_PaletteColor_size[sizeof(PaletteColor)==4?1:-1];
struct Unit
{
    int type;
    int classId;
    void* pool;
    int f_C;
};
typedef char check_Unit_classId[OFFSET(Unit,classId)==4?1:-1];
typedef char check_Unit_unitId[OFFSET(Unit,f_C)==0xC?1:-1];
struct ReceiveQueue
{
    U32 status;
    U8 criticalSection[0x18];
    void* head;
    void* tail;
};
typedef char check_ReceiveQueue_size[sizeof(ReceiveQueue)==0x24?1:-1];
typedef char check_ReceiveQueue_head[OFFSET(ReceiveQueue,head)==0x1C?1:-1];
struct BinFile
{
    void* data;
};
struct Server;
struct ClientNode
{
    int clientId;
    ClientNode* next;
    U8 unknown8[0x18];
    U32 gameGuid;
};
typedef char check_ClientNode_next[OFFSET(ClientNode,next)==4?1:-1];
typedef char check_ClientNode_gameGuid[OFFSET(ClientNode,gameGuid)==0x20?1:-1];
typedef char check_ClientNode_size[sizeof(ClientNode)==0x24?1:-1];
extern "C" U8 __stdcall sub_00605210_FindNearestColor(const U8* palette,U32 count,int c0,int c1,int c2);
extern "C" int __fastcall sub_0063E860_UnitPredicate(Unit* unit);
extern "C" int __fastcall sub_00457490_MonsterFlag(int classId,int flag);
extern "C" U32 __fastcall sub_006C2090_ReadQueue(ReceiveQueue* queue,char* buffer,int capacity);
extern "C" int __fastcall sub_0040B3C0_Free(void* block,const char* file,int line,int flags);
extern "C" int __fastcall sub_0040B480_FreePool(void* pool,void* block,const char* file,int line,int flags);
extern "C" ClientNode* __fastcall sub_006BE540_FindClient(Server* server,int clientId);
extern "C" const int gCollisionPatterns_006EB3DC[4];
extern "C" const char gExcelFile_006FC448[]; // 0x006FC448
struct PaletteTables
{
    PaletteColor colors[256];
    U8 tables[256*32];
};
typedef char check_PaletteTables_tables[OFFSET(PaletteTables,tables)==0x400?1:-1];
struct ReceiveConnection
{
    U8 pad0[0x170];
    ReceiveQueue queue;
};
typedef char check_ReceiveConnection_queue[OFFSET(ReceiveConnection,queue)==0x170?1:-1];

// 0x006BC120
extern "C" U32 __stdcall sub_006BC120_receive(ReceiveConnection* connection, char* buffer, int capacity)
{
    if (!connection)
        return 0;
    return sub_006C2090_ReadQueue(&connection->queue, buffer, capacity);
}

// 0x006BCDA0
extern "C" void __stdcall sub_006BCDA0_freeBinFile(BinFile* file)
{
    sub_0040B3C0_Free(file->data,gExcelFile_006FC448,154,0);
    sub_0040B480_FreePool(0,file,gExcelFile_006FC448,155,0);
}

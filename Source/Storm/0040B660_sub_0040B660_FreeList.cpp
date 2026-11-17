struct List20C
{
    char gap00[0x20C];
    List20C* next;
};
struct List204
{
    char gap00[0x204];
    List204* next;
};
struct List08
{
    char gap00[0x8];
    List08* next;
};

#pragma pack(push, 1)
struct ListCD
{
    char gap00[0xCD];
    ListCD* next;
};
#pragma pack(pop)
struct PoolOwner
{
    char gap00[0x1C];
    void* pool;
};
struct SingleWord
{
    int value;
};
struct FourWords
{
    int first;
    int second;
    int third;
    int fourth;
};
struct QuestView
{
    char gap00[0x9];
    unsigned char active;
    char gapAfterActive[2];
    unsigned char state;
    char gapAfterState[0xB];
    void* extra;
};
struct Extra11
{
    char gap00[0x11];
    unsigned char flag;
};
struct Extra14
{
    char gap00[0x14];
    unsigned char flag;
};
struct GameMode
{
    char gap00[0x70];
    int mode;
};
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char pointer_width[sizeof(void*)==4?1:-1];
typedef char List20C_next[OFFSET(List20C,next)==0x20C?1:-1];
typedef char List204_next[OFFSET(List204,next)==0x204?1:-1];
typedef char List08_next[OFFSET(List08,next)==0x8?1:-1];
typedef char ListCD_next[OFFSET(ListCD,next)==0xCD?1:-1];
typedef char PoolOwner_pool[OFFSET(PoolOwner,pool)==0x1C?1:-1];
typedef char SingleWord_value[OFFSET(SingleWord,value)==0x0?1:-1];
typedef char FourWords_first[OFFSET(FourWords,first)==0x0?1:-1];
typedef char FourWords_second[OFFSET(FourWords,second)==0x4?1:-1];
typedef char FourWords_third[OFFSET(FourWords,third)==0x8?1:-1];
typedef char FourWords_fourth[OFFSET(FourWords,fourth)==0xC?1:-1];
typedef char QuestView_active[OFFSET(QuestView,active)==0x9?1:-1];
typedef char QuestView_state[OFFSET(QuestView,state)==0xC?1:-1];
typedef char QuestView_extra[OFFSET(QuestView,extra)==0x18?1:-1];
typedef char Extra11_flag[OFFSET(Extra11,flag)==0x11?1:-1];
typedef char Extra14_flag[OFFSET(Extra14,flag)==0x14?1:-1];
typedef char GameMode_mode[OFFSET(GameMode,mode)==0x70?1:-1];
typedef char packed_ListCD_size[sizeof(ListCD)==0xD1?1:-1];
extern "C" int __fastcall FOG_Free(void* allocation,const char* file,int line,int flags); // 0x0040B3C0
extern "C" void* __fastcall FOG_AllocPool(void* pool,int size,const char* file,int line,int flags);
extern "C" QuestView* __fastcall QUESTS_GetQuestData(void* game,int id);
extern "C" List204* gList_0077BDB4;
extern "C" List08* gList_007BB5C8;
extern "C" ListCD* gList_007BF014;
extern "C" void* gAllocation_009897D0; // 0x009897D0
extern "C" const char gSource_006CD628[]; // 0x006CD628
extern "C" const char gSource_006D5460[];
extern "C" const char gSource_006D7268[];
extern "C" const char gSource_006DA04C[];
extern "C" const char gSource_006E1560[];

// 0x0040B660
extern "C" void __fastcall sub_0040B660_FreeList(List20C* node)
{
    while (node)
    {
        List20C* next = node->next;
        FOG_Free(node, gSource_006CD628, 0x1F7, 0);
        node = next;
    }
}

extern "C" void __cdecl sub_0043F800_FreeList()
{
    List204* node = gList_0077BDB4;
    while (node)
    {
        List204* next = node->next;
        FOG_Free(node, gSource_006D5460, 0x1C01, 0);
        node = next;
    }
    gList_0077BDB4 = 0;
}

extern "C" void __cdecl sub_004797C0_FreeList()
{
    List08* node = gList_007BB5C8;
    while (node)
    {
        List08* next = node->next;
        FOG_Free(node, gSource_006D7268, 0x22F, 0);
        node = next;
    }
    gList_007BB5C8 = 0;
}

extern "C" void __cdecl sub_0049A020_FreeList()
{
    ListCD* node = gList_007BF014;
    while (node)
    {
        ListCD* next = node->next;
        FOG_Free(node, gSource_006DA04C, 0x108, 0);
        node = next;
    }
    gList_007BF014 = 0;
}

// 0x006B9B00
extern "C" void __cdecl sub_006B9B00_FreeGlobal()
{
    if (gAllocation_009897D0)
    {
        FOG_Free(gAllocation_009897D0, ".\\Src\\d3dSmack.cpp", 0x5E, 0);
        gAllocation_009897D0 = 0;
    }
}

extern "C" FourWords* __stdcall sub_006BD040_AllocateFourWords(const char* file, int line)
{
    FourWords* result = (FourWords*)FOG_AllocPool(0, 0x10, file, line, 0);
    result->first = 0;
    result->second = 0;
    result->third = 0;
    result->fourth = 0;
    return result;
}

extern "C" unsigned char __fastcall sub_0059D7E0_QuestStateCheck(void* game)
{
    QuestView* quest = QUESTS_GetQuestData(game, 0xD);
    if (quest && quest->active != 0 && quest->state == 1)
        return 1;
    return 0;
}

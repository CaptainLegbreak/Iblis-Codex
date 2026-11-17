struct DeadControl
{
    char gap0[0x8];
    unsigned int flags;
    char gapC[0x30];
    DeadControl* next;
};
struct BoundRecord
{
    char gap0[0x4];
    unsigned short active;
};
struct QueueNode
{
    char gap0[0x8];
    BoundRecord* binding;
    QueueNode* next;
    QueueNode* previous;
};
struct QueueState
{
    unsigned int first;
    unsigned int second;
    unsigned int count;
    QueueNode* activeHead;
    QueueNode* activeTail;
    QueueNode* freeHead;
    QueueNode* freeTail;
    void* buffer;
};
struct Game;
struct QuestExtra
{
    char gap0[0x13];
    unsigned char flag;
};
struct QuestView
{
    char gap0[0x18];
    QuestExtra* extra;
};
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
typedef char check_DeadControl_flags[OFFSET(DeadControl,flags)==0x8?1:-1];
typedef char check_DeadControl_next[OFFSET(DeadControl,next)==0x3C?1:-1];
typedef char check_DeadControl_size[sizeof(DeadControl)==0x40?1:-1];
typedef char check_BoundRecord_active[OFFSET(BoundRecord,active)==0x4?1:-1];
typedef char check_BoundRecord_size[sizeof(BoundRecord)==0x6?1:-1];
typedef char check_QueueNode_binding[OFFSET(QueueNode,binding)==0x8?1:-1];
typedef char check_QueueNode_next[OFFSET(QueueNode,next)==0xC?1:-1];
typedef char check_QueueNode_previous[OFFSET(QueueNode,previous)==0x10?1:-1];
typedef char check_QueueNode_size[sizeof(QueueNode)==0x14?1:-1];
typedef char check_QueueState_first[OFFSET(QueueState,first)==0x0?1:-1];
typedef char check_QueueState_second[OFFSET(QueueState,second)==0x4?1:-1];
typedef char check_QueueState_count[OFFSET(QueueState,count)==0x8?1:-1];
typedef char check_QueueState_activeHead[OFFSET(QueueState,activeHead)==0xC?1:-1];
typedef char check_QueueState_activeTail[OFFSET(QueueState,activeTail)==0x10?1:-1];
typedef char check_QueueState_freeHead[OFFSET(QueueState,freeHead)==0x14?1:-1];
typedef char check_QueueState_freeTail[OFFSET(QueueState,freeTail)==0x18?1:-1];
typedef char check_QueueState_buffer[OFFSET(QueueState,buffer)==0x1C?1:-1];
typedef char check_QueueState_size[sizeof(QueueState)==0x20?1:-1];
typedef char check_QuestExtra_flag[OFFSET(QuestExtra,flag)==0x13?1:-1];
typedef char check_QuestExtra_size[sizeof(QuestExtra)==0x14?1:-1];
typedef char check_QuestView_extra[OFFSET(QuestView,extra)==0x18?1:-1];
typedef char check_QuestView_size[sizeof(QuestView)==0x1C?1:-1];
extern "C" int __fastcall FOG_Free(void* memory, const char* file, int line, int flags);
extern "C" QuestView* __fastcall QUESTS_GetQuestData(Game* game, int id); // 0x00543640
extern "C" int gCleanupSuppression_007D55C4;
extern "C" DeadControl* gDeadHead_007D55C0;
extern "C" unsigned int gFirstMask_006CE268;
extern "C" unsigned int gSecondMask_006CE26C;
extern "C" const char gControlSource_006DC6A4[];
extern "C" const char gQueueSource_006DD5B4[];

// 0x005B5210
extern "C" unsigned int __fastcall sub_005B5210_ReadQuestFlag(Game* game)
{
    QuestView* quest = QUESTS_GetQuestData(game, 0x17);
    if (quest)
        return quest->extra->flag;
    return 0;
}

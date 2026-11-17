struct Message
{
    char pad00[10];
    short wheel;
    char padWheel[24-10-2];
    int handled;
    int result;
};
struct Handler
{
    virtual int unused0(Message*);
    virtual int unused1(Message*);
    virtual int wheel(Message*);
    virtual int unused3(Message*);
    virtual int unused4(Message*);
    virtual int unused5(Message*);
    virtual int unused6(Message*);
    virtual int previous2(Message*);
    virtual int next2(Message*);
    virtual int previous1(Message*);
    virtual int next1(Message*);
};
struct HandlerNode
{
    Handler* object;
    HandlerNode* next;
};
struct SelectionEntry
{
    int enabled;
    char pad04[272-4];
};
struct SelectionState
{
    char pad00[68];
    int selected;
    char padSelected[76-68-4];
    int activeCount;
    int totalCount;
    char padTotal[372-80-4];
    SelectionEntry entries[9];
    char padEntries[4];
    HandlerNode* handlers;
};
extern "C" SelectionState* gVar_007C0E54; // 0x007C0E54
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" int __stdcall sub_00420290_QueueMessage(Message*); // 0x00420290
extern "C" int __fastcall sub_004B9A00_Notify(int, void*, int, int, int); // 0x004B9A00
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static void __cdecl sub_004B7100_Select(int step, SelectionState* state); // 0x004B7100

static __declspec(noinline) void __cdecl sub_004B7100_Select(int step, SelectionState* state)
{
    if (state->activeCount > 1)
    {
        int selection = state->selected;
        do
        {
            selection += step;
            if (selection >= state->totalCount)
                selection = 0;
            else if (selection < 0)
                selection = state->totalCount - 1;
        } while (!state->entries[selection].enabled);
        sub_004B9A00_Notify(1, 0, 0, 0, 0);
        state->selected = selection;
    }
}

extern "C" void __stdcall sub_004B7610_Wheel(Message* message)
{
    if (message->wheel)
    {
        int turns = message->wheel / 120;
        if (turns)
        {
            SelectionState* state = gVar_007C0E54;
            D2_ASSERT(gVar_007C0E54, 505);
            for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
                if (node->object && node->object->wheel(message) == 1)
                    return;
            if (turns > 0)
                sub_004B7100_Select(-1, state);
            else
                sub_004B7100_Select(1, state);
        }
    }
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
}

// 0x004B7870
extern "C" void __stdcall sub_004B7870_Previous2(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 626);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->previous2(message) == 1)
            return;
    sub_004B7100_Select(-1, state);
}

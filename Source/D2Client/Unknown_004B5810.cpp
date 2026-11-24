#include "D2Client.h"
#include "D2ClientMenus.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Handler;
struct HandlerNode;
struct SelectionEntry;

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
void __cdecl NPCMENU_BuildNpcMenu(); // 0x004B4830
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern char gbNpcMessageShown; // 0x007C0C69

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

int __cdecl sub_004B1D70_FindNpcEntry(); // 0x004B1D70
void __stdcall NPCMENU_OpenNpcPanel(int nStringIndex, int nEntryIndex); // 0x004B5890
extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850
void __stdcall NPCMENU_OpenConfirmDialog(int nStringIndex); // 0x004B5AD0
void __cdecl sub_004B5140(); // 0x004B5140
extern void (__cdecl* gpfnCallback_00726E59)(); // 0x00726E59
extern unsigned short gwGlobal_00726E4D; // 0x00726E4D

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Draw(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0();
    virtual unsigned int GetAt(int nIndex);
};

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
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09


// 0x004B5BC0
int __cdecl sub_004B5BC0_SelectNpcEntry()
{
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = 1;
    int nIndex = sub_004B1D70_FindNpcEntry();
// build: symbol ?gpNpcEntry@* 0x007C0C7D
    gpNpcEntry = &gaNpcEntries[nIndex];
    NPCMENU_OpenNpcPanel(0xD35, nIndex);
    return 1;
}



static inline SelectionState* GetSelectionState(int line)
{
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(state, line);
    return state;
}

// 0x004B7100
static void __cdecl sub_004B7100_Select(int step, SelectionState* state)
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

extern "C" void __stdcall DIALOG_WheelMsg(Message* message)
{
    if (message->wheel)
    {
        int turns = message->wheel / 120;
        if (turns)
        {
            SelectionState* state = GetSelectionState(505);
            for (HandlerNode* node = state->handlers; node; node = node->next)
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

extern "C" void __stdcall DIALOG_SelectPreviousMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = GetSelectionState(565);
    for (HandlerNode* node = state->handlers; node; node = node->next)
        if (node->object && node->object->previous1(message) == 1)
            return;
    sub_004B7100_Select(-1, state);
}

extern "C" void __stdcall DIALOG_SelectNextMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = GetSelectionState(597);
    for (HandlerNode* node = state->handlers; node; node = node->next)
        if (node->object && node->object->next1(message) == 1)
            return;
    sub_004B7100_Select(1, state);
}

extern "C" void __stdcall DIALOG_SelectPreviousAltMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = GetSelectionState(626);
    for (HandlerNode* node = state->handlers; node; node = node->next)
        if (node->object && node->object->previous2(message) == 1)
            return;
    sub_004B7100_Select(-1, state);
}

extern "C" void __stdcall DIALOG_SelectNextAltMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = GetSelectionState(656);
    for (HandlerNode* node = state->handlers; node; node = node->next)
        if (node->object && node->object->next2(message) == 1)
            return;
    sub_004B7100_Select(1, state);
}

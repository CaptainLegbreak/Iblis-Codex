#include "D2Client.h"
#include "D2ClientMenus.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Handler;
struct HandlerNode;
struct SelectionEntry;

void __fastcall sub_004B8020(void* pRes); // 0x004B8020
void __cdecl sub_004B4830_Rebuild(); // 0x004B4830
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern char gbGlobal_007C0C69; // 0x007C0C69

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

int __cdecl sub_004B1D70_FindNpcEntry(); // 0x004B1D70
void __stdcall sub_004B5890_OpenNpcPanel(int nStringIndex, int nEntryIndex); // 0x004B5890
extern D2NpcEntryStrc gaNpcEntries_00726850[]; // 0x00726850
void __stdcall sub_004B5AD0_OpenConfirmDialog(int nStringIndex); // 0x004B5AD0
void __cdecl sub_004B5140(); // 0x004B5140
extern void (__cdecl* gpfnCallback_00726E59)(); // 0x00726E59
extern unsigned short gwGlobal_00726E4D; // 0x00726E4D

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
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
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

// 0x004B5810
int __cdecl sub_004B5810()
{
    if (gbGlobal_007C0C69)
    {
        return 0;
    }

    if (gpDialog_007C0D6F)
    {
        sub_004B8020(gpDialog_007C0D6F);
        sub_004B9A00(1, 0, 0, 0, 0);
        gpDialog_007C0D6F = 0;
        sub_004B4830_Rebuild();
    }

    return 1;
}


// 0x004B65F0
int __cdecl sub_004B65F0_Initialize()
{
    gnGlobal_00726E47 = 3;
    gpfnCallback_00726E59 = sub_004B5140;
    gwGlobal_00726E4D = 0xD36;
    return 1;
}


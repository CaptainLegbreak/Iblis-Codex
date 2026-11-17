extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma pack(push, 1)
struct D2NpcMenuEntryStrc
{
    int nType;
    char unk0x04[2];
    short wStringId;
    short wSlot[3];
    char unk0x0E[4];
    int (__cdecl* pfnHandler)();
    int nSlot[3];
    char unk0x22[5];
};

struct D2NpcPacketStrc
{
    unsigned char nHeader;
    unsigned short wSubId;
};
#pragma pack(pop)

struct D2UnitStrc;
struct D2BitBufferStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
void __cdecl sub_00487CC0();                                                                                // 0x00487CC0
void __cdecl sub_00488F10();                                                                                // 0x00488F10
int __cdecl sub_004B2020_OpenTimedDialog34();                                                               // 0x004B2020
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0

extern D2NpcMenuEntryStrc gNpcMenuEntries_00726C4C[];                                                       // 0x00726C4C
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gnGlobal_007C0D39;                                                                               // 0x007C0D39
extern short gwGlobal_007C0D3D;                                                                             // 0x007C0D3D
extern void* gpGlobal_007C0D47;                                                                             // 0x007C0D47
extern int gnGlobal_007C0D57;                                                                               // 0x007C0D57
extern void* gpRes_007C0D67;                                                                                // 0x007C0D67
extern unsigned char gbGlobal_007C0D89;                                                                     // 0x007C0D89
extern int gnGlobal_007C0D8E;                                                                               // 0x007C0D8E
extern int gnGlobal_007C0D96;                                                                               // 0x007C0D96
extern char gbGlobal_007C0DE0;                                                                              // 0x007C0DE0
extern int gnGlobal_007C0DE1;                                                                               // 0x007C0DE1
extern int gnGlobal_007C0DE5;                                                                               // 0x007C0DE5
extern int gnGlobal_007C0DE9;                                                                               // 0x007C0DE9
extern int gnGlobal_007C0DED;                                                                               // 0x007C0DED

// 0x004B21C0
static __forceinline void sub_004B21C0_SetEntryType2(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].nType = 2;
    gNpcMenuEntries_00726C4C[nIndex].wSlot[0] = 0;
    gNpcMenuEntries_00726C4C[nIndex].nSlot[0] = 0;
}

// 0x004B21E0
static __forceinline void sub_004B21E0_SetEntryType3(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].nType = 3;
    gNpcMenuEntries_00726C4C[nIndex].wSlot[1] = 0;
    gNpcMenuEntries_00726C4C[nIndex].nSlot[1] = 0;
}

// 0x004B2200
static __forceinline void sub_004B2200_SetEntryType4(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].nType = 4;
    gNpcMenuEntries_00726C4C[nIndex].wSlot[2] = 0;
    gNpcMenuEntries_00726C4C[nIndex].nSlot[2] = 0;
}

// 0x004B2220
static __forceinline void sub_004B2220_SetEntryHandler(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].wStringId = 0xFB4;
    gNpcMenuEntries_00726C4C[nIndex].pfnHandler = sub_004B2020_OpenTimedDialog34;
    gNpcMenuEntries_00726C4C[nIndex].nType = 3;
}

void __stdcall sub_M129_Emit_004B21C0(int a, int b, int c, int d)
{
    sub_004B21C0_SetEntryType2(a);
    sub_004B21E0_SetEntryType3(b);
    sub_004B2200_SetEntryType4(c);
    sub_004B2220_SetEntryHandler(d);
}

// 0x004B25C0
void __fastcall sub_004B25C0_OnPacketSub3(D2NpcPacketStrc* pPacket)
{
    D2_ASSERT(pPacket, 0xFC6);
    if (pPacket->wSubId == 3 && gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
    {
        gnGlobal_007C0D39 = 1;
        gwGlobal_007C0D3D = pPacket->wSubId;
    }
}

// 0x004B2620
void __fastcall sub_004B2620_CopyQuestBuffer(unsigned char* pBuffer)
{
    QUESTRECORD_CopyBufferToRecord((D2BitBufferStrc*)gpGlobal_007C0D47, pBuffer, 0x60, 0);
}

// 0x004B2900
void __cdecl sub_004B2900_CloseDialog()
{
    if (gpRes_007C0D67)
    {
        sub_004B8020(gpRes_007C0D67);
        gpRes_007C0D67 = 0;
    }
    gnGlobal_007C0C6B = 3;
    sub_00487CC0();
    sub_00488F10();
    sub_00466FE0();
}

// 0x004B2940
void __cdecl sub_004B2940()
{
    const unsigned int nTick = GetTickCount();
    if (nTick - gnGlobal_007C0DE9 > 1000)
    {
        gnGlobal_007C0D57 = nTick + 100;
    }
    else
    {
        unsigned int nCount = gnGlobal_007C0DED;
        if (nCount >= 10)
            nCount = 10;
        gnGlobal_007C0D57 = (nCount + 30) * 500 + nTick;
    }
    gnGlobal_007C0D96 = 0;
    gbGlobal_007C0DE0 = 0;
    gnGlobal_007C0DE1 = 0;
    gnGlobal_007C0DE5 = 0;
    if (!sub_0044DB30())
        sub_004B2900_CloseDialog();
}

// 0x004B29E0
void __fastcall sub_004B29E0(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 1 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

#include "gen/data/Source/D2Client/004B21C0_sub_004B21C0_SetEntryType2.inc"

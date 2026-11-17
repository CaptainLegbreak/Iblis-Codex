struct D2UnitStrc;
struct D2DrlgActStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x7C];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2ClientTimedBoxStrc
{
    int bActive;
    int nValue;
    unsigned char nColor[4];
    int nFadeIn;
    int nFadeOut;
    int nHold;
    int nTotal;
    int nTick;
    int nAngle;
    int nLevelId;
    int bLocked;
};

#define LEVEL_DENOFEVIL 8
#define LEVEL_THRONEOFDESTRUCTION 131
#define LEVEL_THEWORLDSTONECHAMBER 132
#define LEVEL_EFFECT_TICKS 30
#define THRONE_MISSILE 0x27F

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                    // 0x0061A180
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2UnitStrc* __fastcall sub_004C5420_CreateFirstMissile(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
void __stdcall sub_0046AF70(D2ActiveRoomStrc* pRoom);                                                       // 0x0046AF70
void __cdecl sub_0046AD10();                                                                                // 0x0046AD10
void __cdecl sub_0046C060_DrawCountdown();                                                                  // 0x0046C060

extern D2DrlgActStrc* gpGlobal_007A0634;                                                                    // 0x007A0634
extern D2ClientTimedBoxStrc gtTimedBox_007A742C;                                                            // 0x007A742C
int gnGlobal_007A745C;                                                                                      // 0x007A745C
int gnGlobal_007A7460;                                                                                      // 0x007A7460
extern int gnTimerEnd_007A7464;                                                                             // 0x007A7464
int gnGlobal_007A7468;                                                                                      // 0x007A7468
int gnGlobal_007A746C;                                                                                      // 0x007A746C
extern int gnGlobal_007129CC;                                                                               // 0x007129CC
extern int gnGlobal_007129D0;                                                                               // 0x007129D0
extern int gnTimerUnitId_007129D4;                                                                          // 0x007129D4

// 0x0046B0D0
void __cdecl sub_0046B0D0_ApplyDenOfEvilRooms()
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(gpGlobal_007A0634); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DENOFEVIL)
        {
            sub_0046AF70(pRoom);
        }
    }
}

// 0x0046BE60
void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 0x344);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DENOFEVIL && gnGlobal_007A745C != 0)
    {
        sub_0046AF70(pRoom);
    }
}

// 0x0046BEB0
void __cdecl sub_0046BEB0_UpdateTimers()
{
    if (gtTimedBox_007A742C.bActive)
    {
        sub_0046AD10();
    }
    if (!gnGlobal_007A745C && gnGlobal_007129CC != -1)
    {
        gnGlobal_007129CC += 1;
        if (gnGlobal_007129CC >= LEVEL_EFFECT_TICKS)
        {
            gnGlobal_007A745C = 1;
            sub_0046B0D0_ApplyDenOfEvilRooms();
        }
    }
    if (gnGlobal_007A7460 && gnGlobal_007129D0 != -1)
    {
        gnGlobal_007129D0 += 1;
        if (gnGlobal_007129D0 >= LEVEL_EFFECT_TICKS)
        {
            gnGlobal_007A7460 = 0;
            gnGlobal_007129D0 = -1;
        }
    }
}

// 0x0046BF30
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return;
    }
    switch (DUNGEON_GetLevelIdFromRoom(pRoom))
    {
    case LEVEL_THRONEOFDESTRUCTION:
    case LEVEL_THEWORLDSTONECHAMBER:
        if (!gnGlobal_007A746C && gnGlobal_007A7468)
        {
            D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
            if (pUnit)
            {
                sub_004C5420_CreateFirstMissile(pUnit, THRONE_MISSILE, 0, 1);
                gnGlobal_007A746C = 1;
            }
        }
        break;
    default:
        gnGlobal_007A746C = 0;
        break;
    }
}

// 0x0046BF90
void __cdecl sub_0046BF90_ResetLevelEffects()
{
    gnGlobal_007A745C = 0;
    gnGlobal_007129CC = -1;
    gnGlobal_007A7460 = 0;
    gnTimerEnd_007A7464 = 0;
    gnTimerUnitId_007129D4 = -1;
    gnGlobal_007A7468 = 0;
    memset(&gtTimedBox_007A742C, 0, sizeof(gtTimedBox_007A742C));
}

// 0x0046C130
void __cdecl sub_0046C130_DrawCountdown()
{
    sub_0046C060_DrawCountdown();
}

#include "gen/data/Source/D2Client/0046B0D0_sub_0046B0D0_ApplyDenOfEvilRooms.inc"

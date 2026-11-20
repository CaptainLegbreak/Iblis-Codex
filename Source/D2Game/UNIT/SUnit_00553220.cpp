#include "D2Game.h"

#define UNITFLAG_DOUPDATE           0x00000001
#define UNITFLAG_INITSEEDSET        0x00000010
#define UNITFLAG_HASTXTMSG          0x00000100
#define UNITFLAG_HASEVENTSOUND      0x00000400
#define UNITFLAG_SUMMONER           0x00000800
#define UNITFLAGEX_TELEPORTED       0x00010000
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ObjectDataStrc;
struct D2AnimFrameTableStrc;

struct D2UnitStrc
{
    int dwUnitType;
    unsigned char unk_04[0x10];
    D2ObjectDataStrc* pObjectData;
    unsigned char unk_18[0x18];
    void* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    short nActionFrame;
    D2AnimFrameTableStrc* pAnimData;
    unsigned char unk_54[0x2C];
    D2GameStrc* pGame;
    unsigned char unk_84[0x10];
    int dwOwnerType;
    int dwOwnerGUID;
    unsigned char unk_9C[0x28];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall STATLIST_FreeModStats(D2UnitStrc* pUnit); // 0x00625960
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit); // 0x00571F40
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int bInvalid); // 0x00620FA0
void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit); // 0x00639EE0

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
    unsigned char unk_AC[0x10];
    D2DrlgActStrc* pAct[5];
};

void __fastcall D2GAME_INVMODE_Last_6FC416D0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597B00
void __stdcall STATLIST_RemoveAllStatsFromOverlay(D2UnitStrc* pUnit); // 0x00627410
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __fastcall sub_0053FA90_ClearArenaUnitUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053FA90
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int bSet, int bUpdate); // 0x00573570
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

struct D2ObjectDataStrc { int unk_00; unsigned char nLevelId; char unk_05[0x13]; int nX; int nY; };

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0
D2ActiveRoomStrc* __stdcall DUNGEON_StreamRoomAtCoords(D2DrlgActStrc* pAct, int nX, int nY); // 0x0061A140
void __fastcall GAME_ActivateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0052D0F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

struct D2AnimFrameTableStrc
{
    char unk0x00[0x10];
    unsigned char pFrameFlags[144];
};

enum
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_ENDANIM = 1,
};
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag); // 0x0055B300
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710

// build: context UNIT_HasFlag
__forceinline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x00553220
void __fastcall SUNIT_ClearUpdateData(D2GameStrc* pGame, D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1304);

    STATLIST_FreeModStats(ptUnit);
    D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(ptUnit);
    ptUnit->dwFlags &= ~(UNITFLAG_DOUPDATE | UNITFLAG_INITSEEDSET);
    UNITS_SetCurrentRoomInvalid(ptUnit, 0);
    ptUnit->dwFlags &= ~(UNITFLAG_HASEVENTSOUND | UNITFLAG_UPGRLIFENHITCLASS);
    ptUnit->dwFlagEx &= 0xFFDEE7FF;
    STATES_ClearGfxStateFlags(ptUnit);
    D2GAME_INVMODE_Last_6FC416D0(pGame, ptUnit);

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(ptUnit))
    {
        STATLIST_RemoveAllStatsFromOverlay(ptUnit);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(ptUnit))
    {
        STATLIST_RemoveAllStatsFromOverlay(ptUnit);
    }

    switch (ptUnit->dwUnitType)
    {
    case 0:
        STATLIST_SetUnitStat(ptUnit, 29, -1, 0);
        ptUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        sub_0053FA90_ClearArenaUnitUpdate(pGame, ptUnit);
        return;

    case 2:
        ptUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        return;

    case 1:
        ptUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        if (UNIT_HasFlag(ptUnit, UNITFLAG_SUMMONER))
        {
            ptUnit->dwFlags &= ~UNITFLAG_SUMMONER;
            MONSTER_ToggleSummonerFlag(ptUnit, 1, 0);
        }
        ptUnit->dwFlagEx &= ~UNITFLAGEX_TELEPORTED;
        return;

    case 3:
        return;

    case 4:
        ptUnit->dwFlags &= ~UNITFLAG_SENDREFRESHMSG;
        break;
    }

    if (ptUnit->dwUnitType == 4)
    {
        ITEMS_SetItemFlag(ptUnit, 0x20, 0);
        ITEMS_SetItemFlag(ptUnit, 0x2000, 0);
    }
}

// 0x00553720
D2UnitStrc* __fastcall sub_00553720_ResolveObjectOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1930); exit(-1); }
    const unsigned char nLevelId = pUnit->pObjectData->nLevelId;
    const int nAct = DRLG_GetActNoFromLevelId(nLevelId);
    const int nX = pUnit->pObjectData->nX;
    const int nY = pUnit->pObjectData->nY;

    if (!sub_00619DA0_ActLookup(pGame->pAct[nAct], nX, nY))
    {
        D2ActiveRoomStrc* pRoom = DUNGEON_StreamRoomAtCoords(pGame->pAct[nAct], nX, nY);
        if (pRoom)
            GAME_ActivateRoom(pGame, pRoom);
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x005539B0
void __fastcall SUNIT_ScheduleAnimationEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nFrame = pGame->dwGameFrame;
    const int nFrameBonus = UNITS_GetFrameBonus(pUnit) << 8;
    int nAnimFrame = nFrameBonus;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    D2AnimFrameTableStrc* pAnimData = pUnit->pAnimData;
    int nIndex = nFrameBonus >> 8;
    int nParam = 0;
    while (nAnimFrame + nAnimSpeed < nFrameCount)
    {
        ++nFrame;
        nAnimFrame += nAnimSpeed;
        for (int i = nAnimFrame >> 8; nIndex <= i; ++nIndex)
        {
            if (nIndex >= 144)
            {
                break;
            }

            D2AnimSeqTxt* pSequence = (D2AnimSeqTxt*)pUnit->pAnimSeq;
            int nEvent;
            if (pSequence)
            {
                DATATBLS_GetSequenceEvent(pSequence, nIndex << 8, &nEvent);
            }
            else
            {
                nEvent = pAnimData->pFrameFlags[nIndex];
            }

            if (nEvent)
            {
                switch (nEvent)
                {
                case 1:
                case 2:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, nParam);
                    ++nParam;
                    break;

                case 3:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }
            }
        }
    }

    if (nFrame == pGame->dwGameFrame)
    {
        ++nFrame;
    }

    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    pUnit->nSeqCurrentFramePrecise = pGame->dwGameFrame << 8;
}

// build: context UNIT_HasFlagEx
inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// build: context sub_0044BE50
inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

// 0x00552FD0
__forceinline D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!UNIT_HasFlagEx(pUnit, UNITFLAGEX_STOREOWNERINFO))
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x00554200
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pUnit)
    {
        D2UnitStrc* pOwner = 0;
        if (pUnit->dwUnitType == 1)
        {
            pOwner = AIGENERAL_GetMinionOwner(pUnit);
        }
        else if (pUnit->dwUnitType == 3)
        {
            pOwner = SUNIT_GetOwner(pGame, pUnit);
        }

        if (pOwner)
        {
            pUnit = pOwner;
        }
    }

    D2UnitStrc* i = pTarget;
    while (sub_0044BE50(i) == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(i);
        if (!pOwner || pOwner == i)
        {
            break;
        }

        i = pOwner;
    }

    if (pUnit == i)
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == 0 && i && i->dwUnitType == 0)
    {
        return PLAYERLIST_CheckFlag(pUnit, i, 8);
    }

    return STATLIST_AreUnitsAligned(pUnit, i) == 0;
}

static __forceinline int UNIT_TypeOrInvalid(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

static __forceinline unsigned short SUNIT_GetPartyId_Inline(D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->pGame && pPlayer->dwUnitType == 0)
        return PARTY_GetPartyIdForUnitOwner(pPlayer->pGame, pPlayer);
    return 0xFFFF;
}

// 0x00554DE0
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (pUnit1 && pUnit1->dwUnitType == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit1);
        if (pOwner)
        {
            pUnit1 = pOwner;
        }
    }
    if (pUnit2 && (!pUnit2 ? 6 : pUnit2->dwUnitType) == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit2);
        if (pOwner)
        {
            pUnit2 = pOwner;
        }
    }
    if (pUnit1 == pUnit2)
    {
        return 1;
    }
    if (UNIT_TypeOrInvalid(pUnit1) == 0 && UNIT_TypeOrInvalid(pUnit2) == 0)
    {
        const unsigned int nPartyId1 = SUNIT_GetPartyId_Inline(pUnit1);
        const unsigned int nPartyId2 = SUNIT_GetPartyId_Inline(pUnit2);
        return nPartyId1 == nPartyId2 && nPartyId2 != 0xFFFF;
    }
    return STATLIST_AreUnitsAligned(pUnit1, pUnit2);
}

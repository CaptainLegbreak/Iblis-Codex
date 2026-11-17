struct D2ActiveRoomStrc;

struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectDataStrc
{
    char unk0x00[0x04];
    unsigned char InteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x8C];
    int unk0xA4;
    char unk0xA8[0x1C];
    unsigned int dwFlags;
};

struct D2ObjectsTxt
{
    char unk0x000[0xC4];
    unsigned char nSelectable[8];
    char unk0x0CC[0x5C];
    unsigned char nIsAttackable;
    char unk0x129[0x14];
    unsigned char nAutomap13D;
    char unk0x13E[0x73];
    unsigned char nInitFn;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
    int nX;
    int nY;
};

typedef void (__fastcall* D2ObjInitFn)(D2ObjInitFnStrc* pOp);
typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);                              // 0x006CC34C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2ObjInitFn gpObjInitFnTable_00731BC0[80];                                                           // 0x00731BC0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x00540F30
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
int __fastcall sub_0054F520_AllocTimerArg(D2GameStrc* pGame);                                               // 0x0054F520
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, char bSparkChest);                         // 0x005540A0
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit);                              // 0x00621B30
void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, int pTimerArg);                                        // 0x006234C0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x0054F5D0
void __fastcall OBJECTS_InitHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pUnit);

    if (pUnit)
    {
        pUnit->dwUnitId = nUnitGUID;
    }

    D2GAME_SetSparkChest_6FCBD7C0(pUnit, 0);

    int nAnimMode;
    if (pUnit)
    {
        pUnit->dwFlags &= ~8u;
        pUnit->unk0xA4 = 0;
        nAnimMode = pUnit->dwAnimMode;
    }
    else
    {
        nAnimMode = 0;
    }

    D2_ASSERT(nAnimMode < 8, 0x240);

    if (pObjectsTxtRecord->nIsAttackable)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 4u;
        }
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~4u;
        }
    }

    pUnit->pObjectData->InteractType = 0;

    const int nClassId = pUnit->dwClassId;
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pUnit);
    D2_ASSERT((unsigned short)nClassId < 0x23D, 0x260);
    D2_ASSERT(pObjectsTxtRecord->nInitFn < 80, 0x262);

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);

    if (pObjectsTxtRecord->nInitFn < 80 && gpObjInitFnTable_00731BC0[pObjectsTxtRecord->nInitFn])
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpObjInitFnTable_00731BC0[pObjectsTxtRecord->nInitFn]), 0x26A);

        D2ObjInitFnStrc pOp;
        pOp.pGame = pGame;
        pOp.pObject = pUnit;
        pOp.pRoom = pRoom;
        pOp.pObjectregion = pObjectControl;
        pOp.pObjectTxt = pObjectsTxtRecord;
        pOp.nX = nX;
        pOp.nY = nY;
        gpObjInitFnTable_00731BC0[pObjectsTxtRecord->nInitFn](&pOp);
    }

    if (pObjectsTxtRecord->nSelectable[nAnimMode])
    {
        pUnit->dwFlags |= 2u;
    }
    else
    {
        pUnit->dwFlags &= ~2u;
    }

    int bFlag80 = 1;
    if (pObjectsTxtRecord->nAutomap13D)
    {
        bFlag80 = (pUnit->dwFlags & 0x80) != 0;
    }

    if (!bFlag80 && !SEED_RollLimitedRandomNumber(&pObjectControl->pSeed, 14))
    {
        UNITS_ChangeAnimMode(pUnit, 2);
    }

    UNITS_SetTimerArg(pUnit, sub_0054F520_AllocTimerArg(pGame));
}

#include "gen/data/Source/D2Game/0054F5D0_OBJECTS_InitHandler.inc"

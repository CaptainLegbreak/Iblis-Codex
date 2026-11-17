struct D2HoverTextStrc;

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
    char unk0xF8[0x28];
    unsigned char nHasCollision[8];
    char unk0x128[0x17];
    unsigned char nMode[8];
};

struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char InteractType;
    unsigned char nPortalFlags;
    unsigned short unk0x06;
    void* pShrineTxt;
    int dwOperateGUID;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x8C];
    D2HoverTextStrc* pHoverText;
    char unk0xA8[0x1C];
    unsigned int dwFlags;
};

struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

typedef int(__stdcall* FARPROC)();
typedef void(__fastcall* ObjTrapHandlerFunction)(D2GameStrc* pGame, D2UnitStrc* pObject);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C

extern ObjTrapHandlerFunction gpObjectTrapHandlerTable_00732CEC[10];                                         // 0x00732CEC
extern int gnObjectTrapHandlers_00732D14;                                                                    // 0x00732D14

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit);                                                            // 0x00621B00
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg);                             // 0x006611D0

#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1
#define EVENTTYPE_FREEHOVER 6
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAG_HASTXTMSG 0x00000100

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

// 0x00581490
void __fastcall sub_6FC74AC0(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && (unsigned short)pObject->dwAnimMode == OBJMODE_OPERATING)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pObject->dwClassId);
        if (pObjectsTxtRecord->nMode[2])
        {
            pObject->dwAnimMode = OBJMODE_OPENED;
            if (!pObjectsTxtRecord->nHasCollision[2])
            {
                UNITS_FreeCollisionPath(pObject);
            }
        }
    }
}

// 0x005814D0
void __fastcall sub_6FC74B00(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (UNITS_IsShrine(pObject))
    {
        UNITROOM_RefreshUnit(pObject);
        SetUnitFlagMask(pObject, UNITFLAG_DOUPDATE);
        UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
        pObject->pObjectData->dwOperateGUID = 0;
    }
}

// 0x00581620
void __fastcall sub_6FC74CA0(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (!pObject)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pObject->pHoverText;
    if (pHoverText)
    {
        const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
        if (nTimeout <= pGame->dwGameFrame)
        {
            CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
            pObject->pHoverText = 0;
            UNITROOM_RefreshUnit(pObject);
            pObject->dwFlags |= UNITFLAG_HASTXTMSG;
        }
        else
        {
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_FREEHOVER, nTimeout, 0, 0);
        }
    }
}

// 0x005817A0
void __fastcall sub_6FC74DF0(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject));
    const unsigned char nTrapType = pObject->pObjectData->InteractType & 0x7F;
    if (nTrapType >= gnObjectTrapHandlers_00732D14)
    {
        return;
    }

    if (nTrapType == 8)
    {
        if (nLevelId >= 75)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[2]), 0x161);
            gpObjectTrapHandlerTable_00732CEC[2](pGame, pObject);
            return;
        }
    }
    else if (nTrapType == 3)
    {
        if (nLevelId < 40 && nLevelId != 25)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[2]), 0x16C);
            gpObjectTrapHandlerTable_00732CEC[2](pGame, pObject);
            return;
        }
    }
    else if ((nTrapType == 1 || nTrapType == 4) && nLevelId < 40)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[2]), 0x176);
        gpObjectTrapHandlerTable_00732CEC[2](pGame, pObject);
        return;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[nTrapType]), 0x17B);
    gpObjectTrapHandlerTable_00732CEC[nTrapType](pGame, pObject);
}

// 0x00581CD0
int __fastcall OBJECTS_OperateFunction30_ExplodingChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pOp->pPlayer, 0);
        OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pOp->pPlayer, 1);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}

#include "gen/data/Source/D2Game/00581490_sub_6FC74AC0.inc"

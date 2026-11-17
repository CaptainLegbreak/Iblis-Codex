extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

struct D2GameStrc;

struct D2ClientStrc;

struct D2DynamicPathStrc;

struct D2InventoryStrc;

struct D2ActiveRoomStrc;

struct D2ServerCallbackFunctions;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

typedef void (__fastcall* PLRMODESTARTXY)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY);
typedef void (__fastcall* PLRMODESTARTID)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget);

struct D2PlayerModeChartStrc
{
    PLRMODESTARTXY pfnStartXY;
    PLRMODESTARTID pfnStartID;
};

extern D2PlayerModeChartStrc gsPlayerModeChart_006E1740[];                                                       // 0x006E1740
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                            // 0x00883D50

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall D2Common_10469(D2UnitStrc* pUnit);                                                           // 0x00627540
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss);                                 // 0x00639FB0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_SetClientDead_6FC33830(D2ClientStrc* pClient, void* pArg);                           // 0x00538260
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic);                             // 0x00649F70
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);           // 0x00553990
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __fastcall sub_0057F700(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2ActiveRoomStrc* pRoom); // 0x0057F700
void __fastcall D2GAME_KillPlayerPets_6FC7CD10(D2GameStrc* pGame, D2UnitStrc* pPlayer);                     // 0x00575BC0
void __fastcall CLIENTS_ToggleFlag(D2ClientStrc* pClient, unsigned short nFlag, int bSet);                  // 0x00538650
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag);                                         // 0x00538670
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                       // 0x00553570
void __fastcall sub_6FCBC4D0(D2UnitStrc* pUnit);                                                            // 0x005533D0
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit);                          // 0x00646020
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pAttacker);   // 0x00535AB0
void __fastcall sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005539B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall ITEMS_DropPlayerEar(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                // 0x0055A200
void __fastcall D2GAME_PLRMSG_Last_6FC89450(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0054D8A0
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);    // 0x0053F720
void __fastcall PLAYER_StopInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer);                            // 0x005350F0

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 0x02:
    case 0x04:
    case 0x05:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 0x02:
    case 0x04:
    case 0x05:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0057F330
static void sub_6FC814F0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    STATLIST_SetUnitStat(pPlayer, 0x06, 0, 0);
    D2Common_10469(pPlayer);
    STATES_UpdateStayDeathFlags(pPlayer, 0);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrModes.cpp", 0x234);
    D2GAME_SetClientDead_6FC33830(pClient, 0);
    PATH_SetUnitDeadCollision(pPlayer, 1);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 0x08, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 0x09, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
}

// 0x0057FCA0
void __fastcall PLRMODE_StartXY_Dead(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY)
{
    sub_0057F700(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetRoom(pUnit));
    D2GAME_KillPlayerPets_6FC7CD10(pGame, pUnit);

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrModes.cpp", 0x434);
    CLIENTS_ToggleFlag(pClient, 0x08, 1);

    if (!gpD2EventCallbackTable_6FD45830 || CLIENTS_CheckFlag(pClient, 0x04))
    {
        D2GAME_SAVE_WriteFile_6FC8A500(pGame, pUnit, CLIENTS_GetName(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrModes.cpp", 0x43A)), 0);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 0x11);
    sub_6FCBC4D0(pUnit);
    sub_6FC814F0(pGame, pUnit);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pUnit);
}

// 0x00580EC0
void __fastcall PLRMODE_StartID_Death(D2GameStrc* pGame, D2UnitStrc* pDefender, int nMode, D2UnitStrc* pAttacker)
{
    bool bIsDruid = false;
    if (pDefender && pDefender->dwUnitType == 0 && pDefender->dwClassId == 0x05)
    {
        bIsDruid = true;
    }

    if (SKILLS_RemoveTransformStatesFromShapeshiftedUnit(pDefender) && bIsDruid)
    {
        D2_ASSERT(pGame, 0x805);

        if (pDefender->pInventory && INVENTORY_GetCursorItem(pDefender->pInventory))
        {
            return;
        }

        D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[1].pfnStartXY), 0x812);

        gsPlayerModeChart_006E1740[1].pfnStartXY(pGame, pDefender, 1, 0, 0);
        return;
    }

    PLAYER_ApplyDeathPenalty(pGame, pDefender, pAttacker);
    SUNIT_SetCombatMode(pGame, pDefender, 0);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pDefender, ".\\PLAYER\\PlrModes.cpp", 0x40B);
    CLIENTS_ToggleFlag(pClient, 0x08, 1);
    sub_6FCBC4D0(pDefender);
    sub_6FC814F0(pGame, pDefender);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pDefender);
    sub_6FCBCE70(pGame, pDefender);

    if (!STATES_CheckState(pDefender, 0x07) && pDefender)
    {
        pDefender->dwFlags &= ~0x02;
    }

    if (pDefender && pAttacker && pDefender->dwUnitType == 0 && pDefender != pAttacker)
    {
        D2UnitStrc* pOwner;
        if (pAttacker->dwUnitType == 0
            || pAttacker->dwUnitType == 1 && (pOwner = AIGENERAL_GetMinionOwner(pAttacker)) != 0 && pOwner->dwUnitType == 0 && pOwner != pDefender)
        {
            ITEMS_DropPlayerEar(pGame, pDefender);
        }
    }

    if (pAttacker)
    {
        D2GAME_PLRMSG_Last_6FC89450(pGame, pAttacker, pDefender);
        ARENA_ProcessKillEvent(pGame, pAttacker, pDefender);
    }

    PLAYER_StopInteractions(pGame, pDefender);
}

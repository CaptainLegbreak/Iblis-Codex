#include "D2Client.h"
#include "D2Primitives.h"
#include "D2StormTypes.h"

struct D2PacketRecord21Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char pWaypointData[16];
};
int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags();                                                           // 0x004B32D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __cdecl WARDENCLIENT_BuildWaypointList();                                                              // 0x0049C7F0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __cdecl GAME_ResetMouseState();                                                                                // 0x0044DA40
int __cdecl sub_0047F210_IsMouseInSlots();                                                                  // 0x0047F210
void __cdecl sub_0049C6C0_SendWaypointClose();                                                              // 0x0049C6C0
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern D2WaypointRowRectStrc gaWaypointRowRects[9];                                                // 0x007224F8
extern D2WaypointMenuEntryStrc gaWaypointEntries[9];                                               // 0x007BF03C
static bool gbWaypointClosePressed;                                                                        // 0x007BF06C
static int gnWaypointSelected;                                                                       // 0x007BF06D
extern char gbSent;                                                                              // 0x007BF085
extern int gnScreenWidth;                                                                               // 0x0071146C
extern int gnScreenHeight;                                                                               // 0x00711470
extern int gnPanelOffsetX;                                                                               // 0x007A2858
extern int gnPanelOffsetY;                                                                               // 0x007A285C

// 0x0049C490
static int sub_0049C490_GetActTabAtPoint(int nX, int nY)
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        if (nY > 0x1E || nX > 0x140)
            return -1;
        if (nX < 0x40)
            return 0;
        if (nX < 0x80)
            return 1;
        if (nX < 0xC0)
            return 2;
        if (nX < 0x100)
            return 3;
        return 4;
    }

    if (nY > 0x1E || nX > 0x140)
        return -1;
    if (nX < 0x50)
        return 0;
    if (nX < 0xA0)
        return 1;
    if (nX < 0xF0)
        return 2;
    return 3;
}

// 0x0049C510
static int sub_0049C510_GetWaypointRowAtPoint(int nX, int nY)
{
    for (int i = 0; i < 9; ++i)
    {
        if (gaWaypointEntries[i].bEnabled && nX > gaWaypointRowRects[i].nX && nX < gaWaypointRowRects[i].nX + 0x118
            && nY > gaWaypointRowRects[i].nY && nY < gaWaypointRowRects[i].nY + 0x1E)
            return i;
    }
    return -1;
}

// 0x0049C760
static void sub_0049C760_SetWaypointAct(int nAct)
{
// build: symbol ?gnWaypointActCount@* 0x007224E4
    if (nAct >= gnWaypointActCount)
        nAct = 0;

    switch (nAct)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1C, 0))
            nAct = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0))
            nAct = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0))
            nAct = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0))
            nAct = 0;
    }

// build: symbol ?gnWaypointAct@* 0x007BF086
    gnWaypointAct = nAct;
}

// 0x0049C980
void __cdecl sub_0049C980_UpdateWaypointAct()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                sub_0049C760_SetWaypointAct(DRLG_GetActNoFromLevelId(nLevelId));
                WARDENCLIENT_BuildWaypointList();
                return;
            }
        }
    }

    gnWaypointAct = 0;
    WARDENCLIENT_BuildWaypointList();
}

// 0x0049CF90
void __fastcall sub_0049CF90(D2PacketRecord21Strc* pPacket)
{
    if (sub_00455F20(0x14, 0, 1) == 1)
    {
        GAME_ResetMouseState();
        sub_0049C980_UpdateWaypointAct();
// build: symbol ?gnWaypointId@* 0x007BF07D
        gnWaypointId = *(int*)pPacket->nUnitGUID;
// build: symbol ?gpWaypointData@* 0x007BF081
        WAYPOINTS_CopyAndValidateWaypointData(gpWaypointData, pPacket->pWaypointData);
        gbSent = 0;
        WARDENCLIENT_BuildWaypointList();
    }
}

// 0x0049D010
void __stdcall sub_0049D010_WaypointMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX <= gnScreenWidth && nY <= gnScreenHeight - 0x31)
    {
        nX -= gnPanelOffsetX;
        nY += gnPanelOffsetY;
        if (gbWaypointClosePressed)
        {
            if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
            {
                sub_00455F20(0x14, 1, 0);
                sub_0049C6C0_SendWaypointClose();
            }
        }
        else if (gnWaypointSelected != -1 && gnWaypointSelected == sub_0049C510_GetWaypointRowAtPoint(nX, nY))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            sub_004786A0_SendDwords2(0x49, gnWaypointId, *(int*)gaWaypointEntries[gnWaypointSelected].nLevelId);
            gbSent = 1;
            sub_0049C6C0_SendWaypointClose();
            gbWaypointClosePressed = false;
            gnWaypointSelected = -1;
            sub_00455F20(0x14, 1, 0);
            sub_004B9A00(0x8B7, 0, 0, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
    }
}

// 0x0049D160
void __stdcall sub_0049D160_WaypointMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX > gnScreenWidth / 2 || nY > gnScreenHeight - 0x31)
    {
        if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
        {
            sub_004786A0_SendDwords2(0x49, gnWaypointId, 0);
            gbSent = 1;
        }
        sub_00455F20(0x14, 1, 1);
        return;
    }

    nX -= gnPanelOffsetX;
    nY += gnPanelOffsetY;
    const int nTab = sub_0049C490_GetActTabAtPoint(nX, nY);
    if (nTab != -1)
    {
        if (nTab != gnWaypointAct)
            sub_004B9A00(6, 0, 0, 0, 0);
        sub_0049C760_SetWaypointAct(nTab);
        WARDENCLIENT_BuildWaypointList();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }

    gnWaypointSelected = -1;
    if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
    {
        gbWaypointClosePressed = true;
        sub_004B9A00(4, 0, 0, 0, 0);
    }
    else
    {
        gnWaypointSelected = sub_0049C510_GetWaypointRowAtPoint(nX, nY);
        if (gnWaypointSelected != -1)
            sub_004B9A00(4, 0, 0, 0, 0);
    }

    if ((unsigned short)pMsg->lParam > gnScreenWidth || (unsigned short)((unsigned int)pMsg->lParam >> 16) > gnScreenHeight - 0x31)
        return;

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

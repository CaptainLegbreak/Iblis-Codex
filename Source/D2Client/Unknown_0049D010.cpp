#include "D2Client.h"

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

struct D2PacketRecord21Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char pWaypointData[16];
};

struct D2WaypointMenuEntryStrc
{
    char nLevelId[4];
    char bEnabled;
};

struct D2WaypointRowRectStrc
{
    int nX;
    int nY;
    int nUnk0x08[4];
};
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
D2BitBufferStrc* __cdecl sub_004B32D0();                                                           // 0x004B32D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __cdecl sub_0049C7F0_BuildWaypointList();                                                              // 0x0049C7F0
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                         // 0x00455F20
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __cdecl sub_0047F210_IsMouseInSlots();                                                                  // 0x0047F210
void __cdecl sub_0049C6C0_SendWaypointClose();                                                              // 0x0049C6C0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
extern D2WaypointRowRectStrc gaWaypointRowRects_007224F8[9];                                                // 0x007224F8
extern D2WaypointMenuEntryStrc gaWaypointEntries_007BF03C[9];                                               // 0x007BF03C
static bool gbWaypointButton_007BF06C;                                                                        // 0x007BF06C
static int gnWaypointSelected_007BF06D;                                                                       // 0x007BF06D
extern char gbGlobal_007BF085;                                                                              // 0x007BF085
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C

// 0x0049C490
static int sub_0049C490_GetActTabAtPoint(int nX, int nY)
{
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
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
        if (gaWaypointEntries_007BF03C[i].bEnabled && nX > gaWaypointRowRects_007224F8[i].nX && nX < gaWaypointRowRects_007224F8[i].nX + 0x118
            && nY > gaWaypointRowRects_007224F8[i].nY && nY < gaWaypointRowRects_007224F8[i].nY + 0x1E)
            return i;
    }
    return -1;
}

// 0x0049C760
static void sub_0049C760_SetWaypointAct(int nAct)
{
    if (nAct >= gnWaypointActCount_007224E4)
        nAct = 0;

    switch (nAct)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x1C, 0))
            nAct = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x17, 0))
            nAct = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0xF, 0))
            nAct = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 7, 0))
            nAct = 0;
    }

    gnWaypointAct_007BF086 = nAct;
}

// 0x0049C980
void __cdecl sub_0049C980_UpdateWaypointAct()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                sub_0049C760_SetWaypointAct(DRLG_GetActNoFromLevelId(nLevelId));
                sub_0049C7F0_BuildWaypointList();
                return;
            }
        }
    }

    gnWaypointAct_007BF086 = 0;
    sub_0049C7F0_BuildWaypointList();
}

// 0x0049CF90
void __fastcall sub_0049CF90(D2PacketRecord21Strc* pPacket)
{
    if (sub_00455F20(0x14, 0, 1) == 1)
    {
        sub_0044DA40();
        sub_0049C980_UpdateWaypointAct();
        gnGlobal_007BF07D = *(int*)pPacket->nUnitGUID;
        WAYPOINTS_CopyAndValidateWaypointData(gpWaypointData_007BF081, pPacket->pWaypointData);
        gbGlobal_007BF085 = 0;
        sub_0049C7F0_BuildWaypointList();
    }
}

// 0x0049D010
void __stdcall sub_0049D010_WaypointMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX <= gnGlobal_0071146C && nY <= gnGlobal_00711470 - 0x31)
    {
        nX -= gnGlobal_007A2858;
        nY += gnGlobal_007A285C;
        if (gbWaypointButton_007BF06C)
        {
            if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
            {
                sub_00455F20(0x14, 1, 0);
                sub_0049C6C0_SendWaypointClose();
            }
        }
        else if (gnWaypointSelected_007BF06D != -1 && gnWaypointSelected_007BF06D == sub_0049C510_GetWaypointRowAtPoint(nX, nY))
        {
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, *(int*)gaWaypointEntries_007BF03C[gnWaypointSelected_007BF06D].nLevelId);
            gbGlobal_007BF085 = 1;
            sub_0049C6C0_SendWaypointClose();
            gbWaypointButton_007BF06C = false;
            gnWaypointSelected_007BF06D = -1;
            sub_00455F20(0x14, 1, 0);
            sub_004B9A00(0x8B7, 0, 0, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        gbWaypointButton_007BF06C = false;
        gnWaypointSelected_007BF06D = -1;
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
    else
    {
        gbWaypointButton_007BF06C = false;
        gnWaypointSelected_007BF06D = -1;
    }
}

// 0x0049D160
void __stdcall sub_0049D160_WaypointMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX > gnGlobal_0071146C / 2 || nY > gnGlobal_00711470 - 0x31)
    {
        if (!gbGlobal_007BF085 && sub_00463DD0() && UNITS_GetRoom(sub_00463DD0()))
        {
            sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, 0);
            gbGlobal_007BF085 = 1;
        }
        sub_00455F20(0x14, 1, 1);
        return;
    }

    nX -= gnGlobal_007A2858;
    nY += gnGlobal_007A285C;
    const int nTab = sub_0049C490_GetActTabAtPoint(nX, nY);
    if (nTab != -1)
    {
        if (nTab != gnWaypointAct_007BF086)
            sub_004B9A00(6, 0, 0, 0, 0);
        sub_0049C760_SetWaypointAct(nTab);
        sub_0049C7F0_BuildWaypointList();
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }

    gnWaypointSelected_007BF06D = -1;
    if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
    {
        gbWaypointButton_007BF06C = true;
        sub_004B9A00(4, 0, 0, 0, 0);
    }
    else
    {
        gnWaypointSelected_007BF06D = sub_0049C510_GetWaypointRowAtPoint(nX, nY);
        if (gnWaypointSelected_007BF06D != -1)
            sub_004B9A00(4, 0, 0, 0, 0);
    }

    if ((unsigned short)pMsg->lParam > gnGlobal_0071146C || (unsigned short)((unsigned int)pMsg->lParam >> 16) > gnGlobal_00711470 - 0x31)
        return;

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

#include "D2Client.h"

struct D2UiRectStrc { int nLeft,nRight,nTop,nBottom; };
struct D2UiRecordStrc { int unknown00; unsigned char nBoxes,unknown05; unsigned short unknown06; D2UiRectStrc aRects[16]; };
struct SMSGHANDLER_PARAMS { void* hWnd; unsigned int uMessage,wParam; unsigned short nX,nY; unsigned int dwCommandSource,dwArg; int bUseResult,lResult; };
void __stdcall sub_00660CB0_GetUiRecord(int,int,D2UiRecordStrc*); // 0x00660CB0
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int,int,D2UiRectStrc*,int); // 0x00660D10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc*,int); // 0x0063C7F0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc*); // 0x0062BAD0
int __fastcall sub_004C2240(D2UnitStrc*); // 0x004C2240
void __fastcall sub_004786A0_SendIntInt(char,int,int); // 0x004786A0
void __fastcall sub_00478680_SendPacket5(char,int); // 0x00478680
void __fastcall sub_004C21F0(D2UnitStrc*); // 0x004C21F0
int __fastcall sub_004C1D60(D2UnitStrc*); // 0x004C1D60
int __fastcall sub_004B9A00(int,int,int,int,int); // 0x004B9A00
int __cdecl sub_00468830(); // 0x00468830
int __cdecl sub_0044DA30(); // 0x0044DA30
int __cdecl sub_00463DF0(); // 0x00463DF0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __cdecl sub_00453EC0(); // 0x00453EC0
int __fastcall sub_004538D0(unsigned int); // 0x004538D0
void __fastcall sub_00455F20_SetUiVar(int,int,int); // 0x00455F20
void __fastcall sub_004A8CE0_SelectSkillSide(int); // 0x004A8CE0
int __cdecl sub_0044BE90_GetRun(); // 0x0044BE90
void __fastcall sub_0044BE80_SetRun(int); // 0x0044BE80
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS*); // 0x00498DC0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS*); // 0x00420290
extern int gnUiRecordRow_007A5218; // 0x007A5218
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
#include "gen/data/Source/D2Client/Unknown_004996A0/gnGlobal_00722358.inc"
#include "D2Structs.h"
extern int gnGlobal_007BEF84; // 0x007BEF84
extern int gnGlobal_007BEF88; // 0x007BEF88
extern int gbUiRecordMode_007BEF98; // 0x007BEF98
static int gnGlobal_007BEFA4;        // 0x007BEFA4
static int gnGlobal_007BEFD0;        // 0x007BEFD0
static int gnGlobal_007BEFD4;        // 0x007BEFD4
static int gnGlobal_007BEFD8;        // 0x007BEFD8

// 0x004987E0
static int __stdcall sub_004987E0_GetBeltBoxAt(int nY, int nX)
{
    D2UiRecordStrc tRecord;
    int nResult = -1;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    for (int i = 0; i < tRecord.nBoxes; ++i)
    {
        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, i);
        if (nX >= tRect.nLeft && nX <= tRect.nRight && nY >= tRect.nTop && nY <= tRect.nBottom)
        {
            nResult = i;
            break;
        }
    }
    return nResult;
}

// build: context sub_00498870_ClickBeltBox
static void __stdcall sub_00498870_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY)
{
    const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
    if (nBox == -1)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    if (sub_00468830() == 6)
    {
        return;
    }

    if (pCursorItem && ITEMS_CheckIfBeltable(pCursorItem))
    {
        const int bBusy = sub_004C2240(pCursorItem);
        if (pBeltItem)
        {
            if (!bBusy)
            {
                sub_004786A0_SendIntInt(0x25, pCursorItem->dwUnitId, pBeltItem->dwUnitId);
                sub_004C21F0(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            sub_004786A0_SendIntInt(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
            sub_004C21F0(pCursorItem);
        }
        sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
        return;
    }

    if (pBeltItem && !pCursorItem && !sub_004C2240(pBeltItem))
    {
        sub_00478680_SendPacket5(0x24, pBeltItem->dwUnitId);
        sub_004C21F0(pBeltItem);
    }
}

static __forceinline void CancelCursorMode()
{
    if(sub_00468830()==6) sub_00453EC0();
    else if(sub_00468830()==8) sub_00478680_SendPacket5(0x4C,-1);
}
// 0x004996A0
void __stdcall sub_004996A0_BeltMouseRelease(SMSGHANDLER_PARAMS* pMsg)
{
    if(sub_0044DA30() || sub_00463DF0()) {
        pMsg->bUseResult=0;
        return;
    }
    D2UnitStrc* pPlayer=sub_00463DD0();
    const int x=pMsg->nX;
    const int y=pMsg->nY;
    gnGlobal_007BEF88=0;
    gnGlobal_007BEF84=0;
    if(gnGlobal_007BEFA4) {
        if(gbUiRecordMode_007BEF98) {
            if(sub_00498DC0_MouseMoveMsg(pMsg)) {
                CancelCursorMode();
                sub_00498870_ClickBeltBox(pPlayer->pInventory,x,y);
                pMsg->bUseResult=1;
                pMsg->lResult=0;
                sub_00420290_HandleMsg(pMsg);
            }
            else if(x>=gnGlobal_0071146C/2-8 && x<=gnGlobal_0071146C/2+5 && y>=gnGlobal_00711470-39 && y<=gnGlobal_00711470-13) {
                if(sub_004538D0(21)) sub_00455F20_SetUiVar(21,1,0);
                else sub_00455F20_SetUiVar(21,2,0);
            }
            else if(x>=117 && x<=165 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470) {
                sub_00455F20_SetUiVar(3,2,0);
                sub_004A8CE0_SelectSkillSide(1);
            }
            else if(x>=gnGlobal_0071146C-165 && x<=gnGlobal_0071146C-117 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470) {
                sub_00455F20_SetUiVar(3,2,0);
                sub_004A8CE0_SelectSkillSide(0);
            }
            else if(x>=gnGlobal_0071146C/2-145 && x<=gnGlobal_0071146C/2-128 && y>=gnGlobal_00711470-28 && y<=gnGlobal_00711470-8) {
                sub_0044BE80_SetRun(!sub_0044BE90_GetRun());
            }
            gnGlobal_007BEFA4=0;
        }
        else if(y>gnGlobal_00711470-48) {
            if(x>=gnGlobal_0071146C/2+23 && x<=gnGlobal_0071146C/2+145 && y>=gnGlobal_00711470-39 && y<=gnGlobal_00711470-10) {
                CancelCursorMode();
                sub_00498870_ClickBeltBox(pPlayer->pInventory,x,y);
            }
            else if(x>=117 && x<=165 && y<=gnGlobal_00711470) {
                CancelCursorMode();
                if(sub_004538D0(3)) sub_00455F20_SetUiVar(3,1,0);
                else sub_00455F20_SetUiVar(3,0,0);
                sub_004A8CE0_SelectSkillSide(1);
            }
            else if(x>=gnGlobal_0071146C-165 && x<=gnGlobal_0071146C-117 && y<=gnGlobal_00711470) {
                CancelCursorMode();
                if(sub_004538D0(3)) sub_00455F20_SetUiVar(3,1,0);
                else sub_00455F20_SetUiVar(3,0,0);
                sub_004A8CE0_SelectSkillSide(0);
            }
            else if(x>=gnGlobal_0071146C/2-145 && x<=gnGlobal_0071146C/2-128 && y>=gnGlobal_00711470-28 && y<=gnGlobal_00711470-8) {
                sub_0044BE80_SetRun(!sub_0044BE90_GetRun());
            }
            else if(x>=gnGlobal_0071146C/2-8 && x<=gnGlobal_0071146C/2+5 && y>=gnGlobal_00711470-39 && y<=gnGlobal_00711470-13) {
                if(sub_004538D0(21)) sub_00455F20_SetUiVar(21,1,0);
                else sub_00455F20_SetUiVar(21,2,0);
                if(gnGlobal_007BEFD0) gnGlobal_007BEFD4=!gnGlobal_007BEFD4;
            }
            gnGlobal_007BEFA4=0;
            gnGlobal_00722358=0;
            pMsg->bUseResult=1;
            pMsg->lResult=0;
            sub_00420290_HandleMsg(pMsg);
        }
        else {
            pMsg->bUseResult=0;
        }
    }
    else {
        if((x>=117 && x<=165 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470) ||
           (x>=gnGlobal_0071146C-165 && x<=gnGlobal_0071146C-117 && y>=gnGlobal_00711470-48 && y<=gnGlobal_00711470)) {
            if(sub_004538D0(3)) sub_00455F20_SetUiVar(3,1,0);
        }
        gnGlobal_007BEFA4=0;
        pMsg->bUseResult=0;
    }
    gnGlobal_007BEFD0=0;
    gnGlobal_007BEFD8=0;
}

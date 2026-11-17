#include "D2Client.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
    int unk0x14[6];
    D2DynamicPathStrc* pDynamicPath;
};

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);     // 0x00625D00
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode);                                     // 0x00480E70
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

// 0x004D89B0
void __fastcall sub_004D89B0_ApplyStateMonster(D2UnitStrc* pUnit, int nState)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, 0x163, 0);
    const int nMode = pUnit->dwAnimMode;
    sub_004AEDD0(pUnit, nValue);
    if (nMode == 8)
    {
        sub_00480E70_SetUnitMode(pUnit, 8);
    }
    else
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
    }

    if (nValue == 0x21F)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2Common_10216(pPath, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit) + 10, 1);
    }
}

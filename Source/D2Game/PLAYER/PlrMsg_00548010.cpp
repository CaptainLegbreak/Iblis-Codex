#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
struct D2ClientStrc;

int __stdcall PATH_GetXPosition(D2PathRecordStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2PathRecordStrc* pPath); // 0x00648900
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10

static inline int UNITS_GetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ((D2StaticPathStrc*)pUnit->pDynamicPath)->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition((D2PathRecordStrc*)pUnit->pDynamicPath) : 0;
    }
}

static inline int UNITS_GetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ((D2StaticPathStrc*)pUnit->pDynamicPath)->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition((D2PathRecordStrc*)pUnit->pDynamicPath) : 0;
    }
}

// 0x00548010
void __fastcall sub_00548010_SendUnitPosition(D2UnitStrc* pUnit, D2ClientStrc* pClient, unsigned char a7)
{
    const int nY = UNITS_GetYPosition(pUnit);
    const int nX = UNITS_GetXPosition(pUnit);
    const unsigned int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
    const int nUnitType = (pUnit ? pUnit->dwUnitType : UNIT_INVALID);
    D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, a7);
}

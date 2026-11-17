#include "D2Game.h"

struct D2StaticPathStrc
{
    unsigned char unk_00[0x0C];
    int nXPos;
    int nYPos;
};
struct D2UnitStrc
{
    int dwUnitType;
    unsigned char dwClassId[8];
    unsigned int dwUnitId;
    unsigned char unk_10[0x1C];
    void* pPath;
};
int __stdcall PATH_GetXPosition(D2PathRecordStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2PathRecordStrc* pPath); // 0x00648900
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitType, int nUnitGUID, int nPosX, int nPosY, unsigned char a7); // 0x0053BC10

static __forceinline int UNITS_GetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return ((D2StaticPathStrc*)pUnit->pPath)->nXPos;
    default:
        return pUnit->pPath ? PATH_GetXPosition((D2PathRecordStrc*)pUnit->pPath) : 0;
    }
}

static __forceinline int UNITS_GetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return ((D2StaticPathStrc*)pUnit->pPath)->nYPos;
    default:
        return pUnit->pPath ? PATH_GetYPosition((D2PathRecordStrc*)pUnit->pPath) : 0;
    }
}

// 0x00548010
void __fastcall sub_00548010_SendUnitPosition(D2UnitStrc* pUnit, D2ClientStrc* pClient, unsigned char a7)
{
    const int nY = UNITS_GetYPosition(pUnit);
    const int nX = UNITS_GetXPosition(pUnit);
    const unsigned int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
    const int nUnitType = (pUnit ? pUnit->dwUnitType : 6);
    D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, a7);
}

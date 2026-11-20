#include "D2Client.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2Unicode.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" size_t __cdecl strlen(const char* szString);

extern const D2AutomapPointStrc gaAutomapCross_006D6638[13];
extern "C" const char szAutomapFile_006D66F0[];
extern int gdwGlobal_007113E8;
extern int gnAutomapScale_00711254;
extern int gdwGlobal_007A5150;
extern int gnAutomapOffsetX_007A5198;
extern int gnAutomapOffsetY_007A519C;
extern unsigned char gnAutomapColors_007A51B0[];
extern int gnGlobal_007A51C8;
extern int gnGlobal_007A51CC;
extern int gnGlobal_007A51D0;
extern int gnGlobal_007A51D4;

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine);
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit);
int __fastcall sub_00478D90_GetUnitAlignment(unsigned int nUnitId);
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory);
int __fastcall sub_00502EF0(int nArg);
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
int __fastcall sub_00501820(const Unicode* wszText);
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha);
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);
int __fastcall sub_0047A1E0(D2StoredUnitRecordStrc* pEntry);
void __fastcall sub_0047A1B0_GetEntryPosition(D2StoredUnitRecordStrc* pEntry, int* pX, int* pY);
void __stdcall sub_00643260(int* pX, int* pY);
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry);
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790

static inline int AUTOMAP_GetUnitType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static inline int AUTOMAP_GetUnitClassId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

static inline int AUTOMAP_GetUnitAnimMode(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

static inline int AUTOMAP_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

static inline int AUTOMAP_GetUnitClassIdR(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static inline int AUTOMAP_GetUnitAnimModeR(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return pUnit->dwAnimMode;
}

static int sub_00459BC0_GetAutomapUnitColor(D2UnitStrc* pUnit, unsigned char* pColor)
{
    switch (AUTOMAP_GetUnitType(pUnit))
    {
    case 0:
        if (pUnit && pUnit->dwAnimMode == 0x11)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory || INVENTORY_GetOwnerId(pInventory) != pUnit->dwUnitId)
            {
                return 0;
            }

            *pColor = gnAutomapColors_007A51B0[2];
            return 1;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            *pColor = gnAutomapColors_007A51B0[0];
            return 1;
        }

        {
            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                *pColor = gnAutomapColors_007A51B0[3];
                return 1;
            }
        }

        *pColor = gnAutomapColors_007A51B0[1];
        return 1;

    case 1:
    {
        if (pUnit)
        {
            if (pUnit->dwAnimMode == 0xC)
            {
                return 0;
            }

            if (AUTOMAP_UnitHasFlag(pUnit, 0x200000))
            {
                return 0;
            }
        }

        if (sub_00457490_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B)
                {
                    return 0;
                }
            }

            *pColor = gnAutomapColors_007A51B0[6];
            return 1;
        }

        int nClass;
        int nMode;
        int nType = AUTOMAP_GetUnitType(pUnit);
        nClass = AUTOMAP_GetUnitClassIdR(pUnit);
        nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, szAutomapFile_006D66F0, 0x92D);
        if (!nType && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && sub_004639D0_GetOwnerUnit(pUnit))
        {
            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                *pColor = gnAutomapColors_007A51B0[4];
                return 1;
            }

            *pColor = gnAutomapColors_007A51B0[1];
            return 1;
        }

        switch (sub_00478D90_GetUnitAlignment(!pUnit ? -1 : pUnit->dwUnitId))
        {
        case 0:
        case 3:
            return 0;

        case 1:
            if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                *pColor = gnAutomapColors_007A51B0[4];
                return 1;
            }
            *pColor = gnAutomapColors_007A51B0[4];
            return 1;

        case 2:
            if (!gdwGlobal_007113E4)
            {
                return 0;
            }
            *pColor = gnAutomapColors_007A51B0[5];
            return 1;
        }

        return 1;
    }

    case 2:
        switch (AUTOMAP_GetUnitClassId(pUnit))
        {
        case 0x3B:
            *pColor = gnAutomapColors_007A51B0[8];
            return 1;

        case 0x3C:
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            if (nLevelId == 0x7D || nLevelId == 0x7E || nLevelId == 0x7F || nLevelId == 0x6F
                || nLevelId == 0x70 || nLevelId == 0x75)
            {
                return 0;
            }
        }
            *pColor = gnAutomapColors_007A51B0[8];
            return 1;

        case 0x10B:
            *pColor = 0;
            return 1;
        }
        break;
    }

    return 0;
}

static void __stdcall sub_0045A760_DrawAutomapText(unsigned char nColor, const char* szText, int nX, int nY)
{
    if (!strlen(szText))
    {
        return;
    }

    if (nColor >= 0xD)
    {
        nColor = 0;
    }

    const int nOldFont = sub_00502EF0(6);
    Unicode wszText[0x17];
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszText, szText, 0x17);
    sub_00502320(wszText, nX - sub_00501820(wszText) / 2, nY - 10, nColor, 0);
    sub_00502EF0(nOldFont);
}

static void __stdcall sub_0045A7F0_DrawAutomapCross(unsigned char nColor, int nX, int nY)
{
    if (gdwGlobal_007A5150 == 1)
    {
        nX -= 1;
        nY += 5;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross_006D6638[i].nX * 2, nY + gaAutomapCross_006D6638[i].nY * 2,
            nX + gaAutomapCross_006D6638[i + 1].nX * 2, nY + gaAutomapCross_006D6638[i + 1].nY * 2, nColor, 0xFF);
    }
}

static void sub_0045A860_DrawAutomapUnit(D2UnitStrc* pUnit)
{
    int nUnitType;
    if (!pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pUnit->dwUnitType;
    }
    unsigned char nColor = 0;
    if (nUnitType == 0 && sub_00464820_IsDeadOrDying(pUnit) && !STATES_CheckState(pUnit, 7))
    {
        return;
    }

    if (!sub_00459BC0_GetAutomapUnitColor(pUnit, &nColor))
    {
        return;
    }

    const int nClientX = UNITS_GetClientCoordX(pUnit);
    const int nClientY = UNITS_GetClientCoordY(pUnit);
    const int nX = nClientX / gnAutomapScale_00711254 - gnAutomapOffsetX_007A5198 + 8;
    const int nY = nClientY / gnAutomapScale_00711254 - gnAutomapOffsetY_007A519C - 8;
    if (nX < gnGlobal_007A51C8 || nX > gnGlobal_007A51D0 || nY < gnGlobal_007A51CC || nY > gnGlobal_007A51D4)
    {
        return;
    }

    switch (nUnitType)
    {
    case 0:
        if (gdwGlobal_007113E4 || nColor != gnAutomapColors_007A51B0[3])
        {
            sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        }

        if (gdwGlobal_007113E8 && gdwGlobal_007113E4 && pUnit != sub_00463DD0_GetPlayerUnit())
        {
            if (nColor == gnAutomapColors_007A51B0[3])
            {
                if (gdwGlobal_007113E4)
                {
                    sub_0045A760_DrawAutomapText(2, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
                }
            }
            else
            {
                sub_0045A760_DrawAutomapText(1, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
            }
        }
        break;

    case 1:
    {
        sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        if (!gdwGlobal_007113E8)
        {
            break;
        }

        if (sub_00457490_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            const int nOldFont = sub_00502EF0(6);
            const Unicode* wszName = sub_00464A60_GetUnitName(pUnit);
            sub_00502320(wszName, nX - sub_00501820(wszName) / 2, nY - 10, 4, 0);
            sub_00502EF0(nOldFont);
        }

        if (!gdwGlobal_007113E8 || !gdwGlobal_007113E4)
        {
            break;
        }

        {
            int nType = AUTOMAP_GetUnitType(pUnit);
            int nClass = AUTOMAP_GetUnitClassIdR(pUnit);
            int nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, szAutomapFile_006D66F0, 0xA15);
            if (nType || !STATES_CheckStateMaskOnUnit(pUnit, 0x25))
            {
                break;
            }

            D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
            if (!pOwner || pOwner->dwUnitType != 0)
            {
                break;
            }

            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                break;
            }

            sub_0045A760_DrawAutomapText(1, UNITS_GetPlayerData(pOwner)->szName, nX, nY);
        }
        break;
    }

    case 2:
        if (gdwGlobal_007113E8 && pUnit && pUnit->dwClassId == 0x10B)
        {
            const int nOldFont = sub_00502EF0(6);
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xCF3);
            sub_00502320(wszText, nX - sub_00501820(wszText) / 2, nY - 10, nColor, 0);
            sub_00502EF0(nOldFont);
        }
        else
        {
            sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        }
        break;
    }
}

static void sub_0045AB60_DrawAutomapPartyMember(D2StoredUnitRecordStrc* pEntry)
{
    int nX = 0;
    int nY = 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));
    const unsigned char nEntryAct = DRLG_GetActNoFromLevelId(sub_0047A1E0(pEntry));
    if (DRLG_GetActNoFromLevelId(nLevelId) != nEntryAct)
    {
        return;
    }

    sub_0047A1B0_GetEntryPosition(pEntry, &nX, &nY);
    sub_00643260(&nX, &nY);
    nX = nX / gnAutomapScale_00711254 - gnAutomapOffsetX_007A5198 + 8;
    nY = nY / gnAutomapScale_00711254 - gnAutomapOffsetY_007A519C - 8;
    if (nX < gnGlobal_007A51C8 || nX > gnGlobal_007A51D0 || nY < gnGlobal_007A51CC || nY > gnGlobal_007A51D4)
    {
        return;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross_006D6638[i].nX * 2, nY + gaAutomapCross_006D6638[i].nY * 2,
            nX + gaAutomapCross_006D6638[i + 1].nX * 2, nY + gaAutomapCross_006D6638[i + 1].nY * 2, gnAutomapColors_007A51B0[3], 0xFF);
    }

    if (gdwGlobal_007113E8)
    {
        sub_0045A760_DrawAutomapText(2, sub_004795C0_GetEntryName(pEntry), nX, nY);
    }
}

// 0x0045AC90
void __cdecl sub_0045AC90_DrawAutomapUnits()
{
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc** ppRooms = 0;
    int nRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pPlayer), &ppRooms, &nRooms);
    const int nCount = nRooms;
    for (int i = 0; i < nCount; ++i)
    {
        for (D2UnitStrc* pUnit = ppRooms[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            sub_0045A860_DrawAutomapUnit(pUnit);
        }
    }

    const unsigned short nIndex = sub_00479BC0_GetEntryIndex(pEntry);
    if (nIndex == 0xFFFF || !gdwGlobal_007113E4)
    {
        return;
    }

    for (pEntry = sub_004795A0_GetNextEntry(pEntry); pEntry; pEntry = sub_004795A0_GetNextEntry(pEntry))
    {
        if (!sub_00463990(sub_0047A0C0_GetRecordUnitId(pEntry), 0) && nIndex == sub_00479BC0_GetEntryIndex(pEntry))
        {
            sub_0045AB60_DrawAutomapPartyMember(pEntry);
        }
    }
}

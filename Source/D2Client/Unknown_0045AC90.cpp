#include "D2StateIds.h"
#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2Unicode.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" size_t __cdecl strlen(const char* szString);

// build: symbol ?gaAutomapCross@* 0x006D6638
extern const D2AutomapPointStrc gaAutomapCross[13];
// build: symbol _gszAutomapFile 0x006D66F0
extern "C" const char gszAutomapFile[];
// build: symbol ?gbAutomapPartyNames@* 0x007113E8
extern int gbAutomapPartyNames;
// build: symbol ?gnAutomapScale@* 0x00711254
extern int gnAutomapScale;
// build: symbol ?gnAutomapMode@* 0x007A5150
extern int gnAutomapMode;
// build: symbol ?gnAutomapOffsetX@* 0x007A5198
extern int gnAutomapOffsetX;
// build: symbol ?gnAutomapOffsetY@* 0x007A519C
extern int gnAutomapOffsetY;
// build: symbol ?gabAutomapColors@* 0x007A51B0
extern unsigned char gabAutomapColors[];
// build: symbol ?gnAutomapClipLeft@* 0x007A51C8
extern int gnAutomapClipLeft;
// build: symbol ?gnAutomapClipTop@* 0x007A51CC
extern int gnAutomapClipTop;
// build: symbol ?gnAutomapClipRight@* 0x007A51D0
extern int gnAutomapClipRight;
// build: symbol ?gnAutomapClipBottom@* 0x007A51D4
extern int gnAutomapClipBottom;

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine);
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit); // 0x00465400
int __fastcall sub_00478D90_GetUnitAlignment(unsigned int nUnitId);
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory);
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha);
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);
const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0
int __fastcall ROSTER_GetLevelId(D2StoredUnitRecordStrc* pEntry); // 0x0047A1E0
void __fastcall sub_0047A1B0_GetEntryPosition(D2StoredUnitRecordStrc* pEntry, int* pX, int* pY);
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY);
const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
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

// build: symbol ?AUTOMAP_GetAutomapUnitColor@* 0x00459BC0
static int AUTOMAP_GetAutomapUnitColor(D2UnitStrc* pUnit, unsigned char* pColor)
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

            *pColor = gabAutomapColors[2];
            return 1;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            *pColor = gabAutomapColors[0];
            return 1;
        }

        {
            const unsigned short nPlayerRoster = CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)CUNIT_GetPlayerPartyId(pUnit))
            {
                *pColor = gabAutomapColors[3];
                return 1;
            }
        }

        *pColor = gabAutomapColors[1];
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

        if (MONSTERUNIQUE_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B)
                {
                    return 0;
                }
            }

            *pColor = gabAutomapColors[6];
            return 1;
        }

        int nClass;
        int nMode;
        int nType = AUTOMAP_GetUnitType(pUnit);
        nClass = AUTOMAP_GetUnitClassIdR(pUnit);
        nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, gszAutomapFile, 0x92D);
        if (!nType && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && CUNIT_GetOwnerUnit(pUnit))
        {
            const unsigned short nPlayerRoster = CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)CUNIT_GetPlayerPartyId(pUnit))
            {
                *pColor = gabAutomapColors[4];
                return 1;
            }

            *pColor = gabAutomapColors[1];
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
                *pColor = gabAutomapColors[4];
                return 1;
            }
            *pColor = gabAutomapColors[4];
            return 1;

        case 2:
// build: symbol ?gbAutomapParty@* 0x007113E4
            if (!gbAutomapParty)
            {
                return 0;
            }
            *pColor = gabAutomapColors[5];
            return 1;
        }

        return 1;
    }

    case 2:
        switch (AUTOMAP_GetUnitClassId(pUnit))
        {
        case 0x3B:
            *pColor = gabAutomapColors[8];
            return 1;

        case 0x3C:
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            if (nLevelId == LEVEL_HELL1 || nLevelId == LEVEL_HELL2 || nLevelId == LEVEL_HELL3 || nLevelId == LEVEL_ID_ACT5_BARRICADE_1
                || nLevelId == LEVEL_ARREATPLATEAU || nLevelId == LEVEL_TUNDRAWASTELANDS)
            {
                return 0;
            }
        }
            *pColor = gabAutomapColors[8];
            return 1;

        case 0x10B:
            *pColor = 0;
            return 1;
        }
        break;
    }

    return 0;
}

// build: symbol ?AUTOMAP_DrawAutomapText@* 0x0045A760
static void __stdcall AUTOMAP_DrawAutomapText(unsigned char nColor, const char* szText, int nX, int nY)
{
    if (!strlen(szText))
    {
        return;
    }

    if (nColor >= 0xD)
    {
        nColor = 0;
    }

    const int nOldFont = D2Win_10127_SetFont(6);
    Unicode wszText[0x17];
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszText, szText, 0x17);
    D2Win_10117_DrawText(wszText, nX - D2Win_10121_GetTextWidth(wszText) / 2, nY - 10, nColor, 0);
    D2Win_10127_SetFont(nOldFont);
}

// build: symbol ?AUTOMAP_DrawAutomapCross@* 0x0045A7F0
static void __stdcall AUTOMAP_DrawAutomapCross(unsigned char nColor, int nX, int nY)
{
    if (gnAutomapMode == 1)
    {
        nX -= 1;
        nY += 5;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross[i].nX * 2, nY + gaAutomapCross[i].nY * 2,
            nX + gaAutomapCross[i + 1].nX * 2, nY + gaAutomapCross[i + 1].nY * 2, nColor, 0xFF);
    }
}

// build: symbol ?AUTOMAP_DrawAutomapUnit@* 0x0045A860
static void AUTOMAP_DrawAutomapUnit(D2UnitStrc* pUnit)
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
    if (nUnitType == 0 && CUNIT_IsDeadOrDying(pUnit) && !STATES_CheckState(pUnit, STATE_PLAYERBODY))
    {
        return;
    }

    if (!AUTOMAP_GetAutomapUnitColor(pUnit, &nColor))
    {
        return;
    }

    const int nClientX = UNITS_GetClientCoordX(pUnit);
    const int nClientY = UNITS_GetClientCoordY(pUnit);
    const int nX = nClientX / gnAutomapScale - gnAutomapOffsetX + 8;
    const int nY = nClientY / gnAutomapScale - gnAutomapOffsetY - 8;
    if (nX < gnAutomapClipLeft || nX > gnAutomapClipRight || nY < gnAutomapClipTop || nY > gnAutomapClipBottom)
    {
        return;
    }

    switch (nUnitType)
    {
    case 0:
        if (gbAutomapParty || nColor != gabAutomapColors[3])
        {
            AUTOMAP_DrawAutomapCross(nColor, nX, nY);
        }

        if (gbAutomapPartyNames && gbAutomapParty && pUnit != sub_00463DD0_GetPlayerUnit())
        {
            if (nColor == gabAutomapColors[3])
            {
                if (gbAutomapParty)
                {
                    AUTOMAP_DrawAutomapText(2, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
                }
            }
            else
            {
                AUTOMAP_DrawAutomapText(1, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
            }
        }
        break;

    case 1:
    {
        AUTOMAP_DrawAutomapCross(nColor, nX, nY);
        if (!gbAutomapPartyNames)
        {
            break;
        }

        if (MONSTERUNIQUE_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            const int nOldFont = D2Win_10127_SetFont(6);
            const Unicode* wszName = CUNIT_GetUnitName(pUnit);
            D2Win_10117_DrawText(wszName, nX - D2Win_10121_GetTextWidth(wszName) / 2, nY - 10, 4, 0);
            D2Win_10127_SetFont(nOldFont);
        }

        if (!gbAutomapPartyNames || !gbAutomapParty)
        {
            break;
        }

        {
            int nType = AUTOMAP_GetUnitType(pUnit);
            int nClass = AUTOMAP_GetUnitClassIdR(pUnit);
            int nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, gszAutomapFile, 0xA15);
            if (nType || !STATES_CheckStateMaskOnUnit(pUnit, 0x25))
            {
                break;
            }

            D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
            if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
            {
                break;
            }

            const unsigned short nPlayerRoster = CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)CUNIT_GetPlayerPartyId(pUnit))
            {
                break;
            }

            AUTOMAP_DrawAutomapText(1, UNITS_GetPlayerData(pOwner)->szName, nX, nY);
        }
        break;
    }

    case 2:
        if (gbAutomapPartyNames && pUnit && pUnit->dwClassId == 0x10B)
        {
            const int nOldFont = D2Win_10127_SetFont(6);
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xCF3);
            D2Win_10117_DrawText(wszText, nX - D2Win_10121_GetTextWidth(wszText) / 2, nY - 10, nColor, 0);
            D2Win_10127_SetFont(nOldFont);
        }
        else
        {
            AUTOMAP_DrawAutomapCross(nColor, nX, nY);
        }
        break;
    }
}

// build: symbol ?AUTOMAP_DrawAutomapPartyMember@* 0x0045AB60
static void AUTOMAP_DrawAutomapPartyMember(D2StoredUnitRecordStrc* pEntry)
{
    int nX = 0;
    int nY = 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));
    const unsigned char nEntryAct = DRLG_GetActNoFromLevelId(ROSTER_GetLevelId(pEntry));
    if (DRLG_GetActNoFromLevelId(nLevelId) != nEntryAct)
    {
        return;
    }

    sub_0047A1B0_GetEntryPosition(pEntry, &nX, &nY);
    DUNGEON_GameSubtileToClientCoords(&nX, &nY);
    nX = nX / gnAutomapScale - gnAutomapOffsetX + 8;
    nY = nY / gnAutomapScale - gnAutomapOffsetY - 8;
    if (nX < gnAutomapClipLeft || nX > gnAutomapClipRight || nY < gnAutomapClipTop || nY > gnAutomapClipBottom)
    {
        return;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross[i].nX * 2, nY + gaAutomapCross[i].nY * 2,
            nX + gaAutomapCross[i + 1].nX * 2, nY + gaAutomapCross[i + 1].nY * 2, gabAutomapColors[3], 0xFF);
    }

    if (gbAutomapPartyNames)
    {
        AUTOMAP_DrawAutomapText(2, ROSTER_GetEntryName(pEntry), nX, nY);
    }
}

// 0x0045AC90
void __cdecl sub_0045AC90_DrawAutomapUnits()
{
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc** ppRooms = 0;
    int nRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pPlayer), &ppRooms, &nRooms);
    const int nCount = nRooms;
    for (int i = 0; i < nCount; ++i)
    {
        for (D2UnitStrc* pUnit = ppRooms[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            AUTOMAP_DrawAutomapUnit(pUnit);
        }
    }

    const unsigned short nIndex = ROSTER_GetEntryIndex(pEntry);
    if (nIndex == 0xFFFF || !gbAutomapParty)
    {
        return;
    }

    for (pEntry = ROSTER_GetNextStoredUnit(pEntry); pEntry; pEntry = ROSTER_GetNextStoredUnit(pEntry))
    {
        if (!CUNIT_FindClientUnit(ROSTER_GetRecordUnitId(pEntry), 0) && nIndex == ROSTER_GetEntryIndex(pEntry))
        {
            AUTOMAP_DrawAutomapPartyMember(pEntry);
        }
    }
}

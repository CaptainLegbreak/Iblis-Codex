#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2GameObjs.h"
#include "D2LevelTxt.h"


struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    unsigned int nWidth;
    unsigned int nHeight;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" unsigned int __cdecl strlen(const char* szString);
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
const Unicode* __fastcall sub_00453E70_GetLevelName(int nLevelId); // 0x00453E70
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
void __fastcall sub_00454AD0_DrawUnitHoverName(D2UnitStrc* pUnit);                                          // 0x00454AD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);                                      // 0x00464A60
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY);                           // 0x004760C0
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20
int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150
const char* __fastcall sub_0047A290_GetOwnerName(int nUnitId);                                              // 0x0047A290
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5, int nArg6); // 0x005022F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
const Unicode* __fastcall D2LANG_GetStringByReferenceString(const char* szKey);                                       // 0x00524E20
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                       // 0x00620900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);        // 0x0063E810
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0
extern unsigned short gwszText_007A2A78[];                                                                  // 0x007A2A78
extern Unicode gxGlobal_007A2C80[80];                                                                       // 0x007A2C80
extern int gdwGlobal_007A2D20;                                                                              // 0x007A2D20
extern int gdwGlobal_007A2D24;                                                                              // 0x007A2D24
extern int gdwGlobal_007A2D28;                                                                              // 0x007A2D28
extern unsigned short gwszText_007A2D30[];                                                                  // 0x007A2D30
extern Unicode gwszHoverName_007A2F38[];                                                                    // 0x007A2F38

static void __stdcall sub_00452AF0_GetPartyText(D2UnitStrc* pUnit, Unicode* pDst, int nMaxLength, int* pValue, int* pFlag)
{
    const char* szName = sub_0047A210_GetPartyName(pUnit);
    if (pUnit && pUnit->dwAnimMode == 0x11)
    {
        *pValue = 0;
        unsigned short wszName[0x80];
        for (int i = 0; i < 0x80; i++)
            wszName[i] = 0;
        sub_00526F20_ToUnicode((Unicode*)wszName, szName, 0x80);
        sub_005272B0_FormatText(pDst, (Unicode*)wszName, D2LANG_GetStringFromTblIndex(0x90B), nMaxLength, STRTABLE_GetLanguage());
        *pFlag = 1;
        return;
    }
    *pValue = sub_0047A6B0_GetLifeValue(!pUnit ? -1 : pUnit->dwUnitId) * 128 / 100;
    *pFlag = 0;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_0047A070_IsPartyRelation(!pPlayer ? -1 : pPlayer->dwUnitId, nUnitId))
    {
        *pFlag = 1;
    }
    sub_00526F20_ToUnicode(pDst, szName, 0x80);
}

static void __stdcall sub_00452BE0_ShowUnitHoverName(D2UnitStrc* pUnit, int bSet)
{
    int nValues[2];
    if (sub_004B3230_GetTickPair(&nValues[0]))
    {
        return;
    }
    nValues[1] = sub_004525F0_GetHoverTextY(pUnit);
    const int nY = gnHoverY_0070F858 - 0x48;
    const int nX = gnHoverX_0070F854;
    const Unicode* pName = sub_00464A60_GetUnitName(pUnit);
    if (bSet)
    {
        gxGlobal_007A2C80[0].wChar = 0;
        if (pName)
        {
            sub_005267E0(gxGlobal_007A2C80, pName);
            gdwGlobal_007A2D24 = nY;
            gdwGlobal_007A2D20 = nX;
            gdwGlobal_007A2D28 = nValues[1];
        }
    }
    else
    {
        D2Win_10130_DrawFramedTextEx(pName, nX, nY, 0, 1, nValues[1]);
    }
}

static int __stdcall sub_00452C70_GetRosterText(D2UnitStrc* pUnit, Unicode* pDst, int* pValue, int* pFlag)
{
    const int nIndex = sub_00479150_FindRosterIndex(!pUnit ? -1 : pUnit->dwUnitId);
    if (nIndex == -1)
    {
        return 0;
    }
    if (!pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 0x0C)
    {
        return 1;
    }
    const char* szName = sub_0047A1F0(nIndex);
    if (!szName)
    {
        return 0;
    }
    sub_00526320_ToUnicode(pDst, szName, 0x80);
    *pValue = sub_0047A6B0_GetLifeValue(nIndex) * 128 / 100;
    *pFlag = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_0047A070_IsPartyRelation(!pPlayer ? -1 : pPlayer->dwUnitId, nIndex))
    {
        *pFlag = 1;
    }
    return 1;
}

static __forceinline int SetHoverPositionFromUnit(D2UnitStrc* pUnit)
{
    if (sub_004F51D0_IsPerspective())
    {
        const int nPrecisionX = UNITS_GetPrecisionX(pUnit);
        const int nPrecisionY = UNITS_GetPrecisionY(pUnit);
        if (!sub_004F66E0_IsPrecisionOnScreen(nPrecisionX, nPrecisionY))
        {
            return 0;
        }
        int nX;
        int nY;
        sub_004F6760_PrecisionToScreen(nPrecisionX, nPrecisionY, 0, &nX, &nY);
        switch (sub_0045AE90())
        {
        case 1:
            nX -= gnGlobal_0071146C / 4;
            break;
        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
        gnHoverX_0070F854 = nX;
        gnHoverY_0070F858 = nY + 0x10;
    }
    else
    {
        gnHoverX_0070F854 = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0();
        gnHoverY_0070F858 = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset();
    }
    return 1;
}

void __cdecl sub_00452D20_DrawPetHover()
{
    if (sub_0045AE90() == 3)
    {
        return;
    }
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        return;
    }
    if (sub_00478E40_FindEntry(nPetId)->nValue != 1)
    {
        return;
    }
    D2UnitStrc* pPet = sub_00463990(nPetId, 1);
    if (!pPet)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pPet))
    {
        return;
    }
    sub_00452BE0_ShowUnitHoverName(pPet, 1);
}

void __fastcall sub_00453330_DrawPartyMemberText(D2UnitStrc* pUnit)
{
    const int nBorder = sub_0045AE90();
    if (nBorder == 3)
    {
        return;
    }
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        return;
    }
    D2RectStrc tView;
    sub_00476070_GetViewRect(gpView_007A0640, &tView.nLeft, &tView.nTop, &tView.nRight, &tView.nBottom);
    int nOffsetX;
    int nOffsetY;
    sub_004760C0_GetViewOffset(gpView_007A0640, &nOffsetX, &nOffsetY);
    tagRECT tRect;
    SetRect(&tRect, nOffsetX, nOffsetY, tView.nRight - tView.nLeft + nOffsetX, tView.nBottom - tView.nTop + nOffsetY);
    D2CoordStrc tCoords;
    UNITS_GetClientCoords(pUnit, &tCoords);
    tCoords.nY = tCoords.nY - tRect.top - 0x46;
    tCoords.nX -= tRect.left;
    switch (nBorder)
    {
    case 1:
        tCoords.nX -= gnGlobal_0071146C / 4;
        if (tCoords.nX > gnGlobal_0071146C / 2)
        {
            return;
        }
        break;
    case 2:
        tCoords.nX += gnGlobal_0071146C / 4;
        if (tCoords.nX < gnGlobal_0071146C / 2)
        {
            return;
        }
        break;
    }
    if (tCoords.nY <= 0 || tCoords.nY >= gnGlobal_0071146C || tCoords.nX <= -0x32 || tCoords.nX >= gnGlobal_00711470 + 0x32)
    {
        return;
    }
    Unicode wszName[0x80];
    int nPercent;
    int bFlag;
    sub_00452AF0_GetPartyText(pUnit, wszName, 0x80, &nPercent, &bFlag);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00454F30
void __fastcall sub_00454F30_DrawUnitHover(D2UnitStrc* pUnit)
{
    if (sub_0045AE90() == 3)
    {
        return;
    }
    if (!pUnit)
    {
        return;
    }
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType == 5 && sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0_GetPlayerUnit()) > 100)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pUnit))
    {
        return;
    }

    switch (pUnit->dwUnitType)
    {
    case 0:
    {
        Unicode wszName[0x80];
        int nPercent;
        int bFlag;
        sub_00452AF0_GetPartyText(pUnit, wszName, 0x80, &nPercent, &bFlag);
        D2Win_10130_DrawFramedTextEx(wszName, gnHoverX_0070F854, gnHoverY_0070F858 - 0x48, bFlag, 1, nPercent);
        return;
    }
    case 4:
        if (gaUIVarStates_007A27C0[13])
        {
            return;
        }
        sub_004527D0(pUnit, 0, 0);
        return;
    case 1:
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId != 0x1A1 && nClassId != 0x1A2)
        {
            if (!sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                if (nClassId == 0x164)
                {
                    int bFlag = 3;
                    Unicode wszName[0x80];
                    int nPercent = 0;
                    if (sub_00452C70_GetRosterText(pUnit, wszName, &nPercent, &bFlag))
                    {
                        if (bFlag == 3)
                        {
                            return;
                        }
                        D2Win_10130_DrawFramedTextEx(wszName, gnHoverX_0070F854, gnHoverY_0070F858 - 0x48, bFlag, 1, nPercent);
                        return;
                    }
                }
                sub_00454AD0_DrawUnitHoverName(pUnit);
                return;
            }
            sub_00452BE0_ShowUnitHoverName(pUnit, 0);
        }
        else
        {
            D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pRecord)
            {
                MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pRecord->wNameStr));
                sub_00452BE0_ShowUnitHoverName(pUnit, 0);
            }
        }
        gwszText_007A2D30[0] = 0;
        gwszText_007A2A78[0] = 0;
        gwszHoverName_007A2F38[0].wChar = 0;
        return;
    }
    case 2:
    {
        Unicode wszUnused[0x80];
        Unicode wszLine[0x100];
        Unicode wszText[0x80] = { 0 };
        int nLow;
        if (sub_004B3230_GetTickPair(&nLow))
        {
            return;
        }
        if (sub_004A0000() == 1)
        {
            return;
        }
        const Unicode* pName = sub_00464A60_GetUnitName(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nOffset = sub_00622270_GetHoverOffset(pUnit);
        const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord((unsigned short)nClassId)->nSubClass;
        if (nFlags & 4)
        {
            Unicode wszOwner[0x80];
            sub_005267E0(wszText, sub_00453E70_GetLevelName(pUnit->pObjectData->InteractType));
            if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1)
            {
                char szOwner[0x80];
                const char* szName = sub_0047A290_GetOwnerName(pUnit->dwUnitId);
                if (szName)
                {
                    sprintf(szOwner, " (%s) ", szName);
                    sub_00526F20_ToUnicode(wszOwner, szOwner, 0x80);
                    sub_00526700(wszText, wszOwner);
                }
                else if (strlen(sub_004BDFD0_GetObjectText(pUnit)))
                {
                    sprintf(szOwner, " (%s) ", sub_004BDFD0_GetObjectText(pUnit));
                    sub_00526F20_ToUnicode(wszOwner, szOwner, 0x80);
                    sub_00526700(wszText, wszOwner);
                }
            }
            D2Win_10129_DrawFramedText(wszText, gnHoverX_0070F854, gnHoverY_0070F858 + nOffset, 0, 1);
            return;
        }
        if (nFlags & 0x80)
        {
            return;
        }
        if (nFlags & 0x40)
        {
            const Unicode* pObjectName = sub_00464A60_GetUnitName(pUnit);
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom)
            {
                return;
            }
            D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
            sub_005267E0(wszLine, pObjectName);
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszLine, D2LANG_GetStringByReferenceString(pLevelsTxt->szLevelName));
            D2Win_10129_DrawFramedText(wszLine, gnHoverX_0070F854, gnHoverY_0070F858 + nOffset, 0, 1);
            return;
        }
        D2Win_10129_DrawFramedText(pName, gnHoverX_0070F854, gnHoverY_0070F858 + nOffset, 0, 1);
        return;
    }
    case 5:
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nLevelId = sub_0061A1D0_GetTileLevelId(pRoom, nClassId);
        D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(nLevelId);
        if (!pLevelsTxt)
        {
            return;
        }
        D2TileRectStrc* pRect = sub_00619620(pRoom, pUnit);
        if (!pRect)
        {
            return;
        }
        const int nX = (pRect->nWidth >> 1) + pRect->nX + gnHoverX_0070F854;
        const int nY = (pRect->nHeight >> 1) + pRect->nY + gnHoverY_0070F858;
        Unicode wszText[0xC8] = { 0 };
        const Unicode* pText = (const Unicode*)pLevelsTxt->wszLevelWarp;
        if (nLevelId == 8)
        {
            if (sub_004B92E0_GetTableByte(0, 1))
            {
                pText = D2LANG_GetStringFromTblIndex(0x13DE);
            }
            else
            {
                pText = D2LANG_GetStringFromTblIndex(0x13DD);
            }
        }
        sub_00526790(wszText, pText, 0xC7);
        D2Win_10129_DrawFramedText(wszText, nX, nY, 0, 1);
        return;
    }
    }
}

#include "gen/data/Source/D2Client/Unknown_00454F30.inc"

struct D2UnitStrc;

#include "D2Client.h"
#include "D2Unicode.h"
#include "D2ClientParty.h"


const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall TEXT_GetCenteredStringX(unsigned short nStringIndex, int nCenterX);                  // 0x0049AAA0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);              // 0x005269D0
int __fastcall ROSTER_IsPlayerHostile(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5E0
int __fastcall ROSTER_PlayerAllowsLoot(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A640
int __fastcall ROSTER_IsHostileToPlayer(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5B0
int __fastcall ROSTER_AllowsPlayerLoot(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A610
int __fastcall ROSTER_IsMaleClass(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A670
int __cdecl WINMAIN_IsHardcore();                                                                      // 0x0044B850
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall ROSTER_GetLevel(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90
int __fastcall ROSTER_TestHostileFlag(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CE0
int __fastcall ROSTER_TestLootFlag(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C20
int __fastcall ROSTER_TestMuteFlag(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C60
int __fastcall ROSTER_TestSquelchFlag(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CA0
extern int gnPanelOffsetX;                                                                               // 0x007A2858
extern int gnPanelOffsetY;                                                                               // 0x007A285C
extern unsigned char gnBoxColor;                                                                     // 0x007BF034
extern D2PartyRowStrc* gpRosterUnits;                                                            // 0x007BF014
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

static inline int GetCenteredStringXInline(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - D2Win_10121_GetTextWidth(wszText) / 2;
}

static void __stdcall sub_0049AAF0_DrawTextFrame(unsigned short nAltString, unsigned short nString, int nX, int bLarge)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    int nAltWidth = 0;
    if (nAltString)
    {
        Unicode wszAlt[100];
        sub_005267E0(wszAlt, D2LANG_GetStringFromTblIndex(nAltString));
        nAltWidth = D2Win_10121_GetTextWidth(wszAlt);
    }
    int nY = 0x23;
    int nHeight = 0x1E;
    if (!bLarge)
    {
        nY = 0x2A;
        nHeight = 0xF;
    }
    if (nWidth > nAltWidth)
        AUTOMAP_DrawFramedBox(gnPanelOffsetX - nWidth / 2 + nX - 5, nY - gnPanelOffsetY, nWidth + 0xA, nHeight, gnBoxColor, 2);
    else
        AUTOMAP_DrawFramedBox(gnPanelOffsetX - nAltWidth / 2 + nX - 5, nY - gnPanelOffsetY, nAltWidth + 0xA, nHeight, gnBoxColor, 2);
}

void __cdecl sub_0049ABD0_DrawRosterHoverHints()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2StoredUnitRecordStrc* pFirst = ROSTER_GetNextStoredUnit(0);
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
    if (ROSTER_GetEntryIndex(pFirst) != 0xFFFF)
    {
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + 0xE3 && nMouseX <= gnPanelOffsetX + 0x118 && nMouseY >= 0x18 - gnPanelOffsetY && nMouseY <= 0x23 - gnPanelOffsetY)
        {
            sub_0049AAF0_DrawTextFrame(0, 0x1018, 0xD5, 0);
            {
                const int nTextX = TEXT_GetCenteredStringX(0x1018, 0xD5);
                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1018), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 0, 0);
            }
        }
    }
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(pFirst);
    while (pRow)
    {
        const int nY = pRow->aSlots[0].nY;
        const int nX = pRow->aSlots[0].nX;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + nX && nMouseX <= gnPanelOffsetX + nX + 0x35 && nMouseY >= nY - gnPanelOffsetY - 0x14 && nMouseY <= nY - gnPanelOffsetY)
        {
            if (!pRow->aSlots[0].nType)
            {
                const int nState = pRow->aSlots[0].nState;
                if (nState == 0)
                {
                    sub_0049AAF0_DrawTextFrame(0x1005, 0x1004, 0xDA, 1);
                    {
                        const int nTextX = GetCenteredStringXInline(0x1004, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1004), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = GetCenteredStringXInline(0x1005, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1005), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
                else if (nState == 2)
                {
                    sub_0049AAF0_DrawTextFrame(0x1007, 0x1006, 0xDA, 1);
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1006, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1006), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1007, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1007), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
                else if (nState == 4)
                {
                    sub_0049AAF0_DrawTextFrame(0x1009, 0x1008, 0xDA, 1);
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1008, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1008), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1009, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1009), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

static void __stdcall sub_0049AF60_DrawButtonHint(unsigned short nString1, unsigned short nString2, int nCenterX, int nUnused, int nY1, int nY2, int nColor)
{
    if (!nString2)
    {
        sub_0049AAF0_DrawTextFrame(0, nString1, nCenterX, 0);
        {
            const int nTextX = TEXT_GetCenteredStringX(nString1, nCenterX);
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnPanelOffsetX, nY1 - gnPanelOffsetY, nColor, 0);
        }
        return;
    }
    sub_0049AAF0_DrawTextFrame(nString2, nString1, nCenterX, 1);
    {
        const int nTextX = TEXT_GetCenteredStringX(nString1, nCenterX);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnPanelOffsetX, nY1 - gnPanelOffsetY, nColor, 0);
    }
    {
        const int nTextX = TEXT_GetCenteredStringX(nString2, nCenterX);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString2), nTextX + gnPanelOffsetX, nY2 - gnPanelOffsetY, nColor, 0);
    }
}

// 0x0049B030
static void sub_0049B030_DrawRosterTooltip(D2StoredUnitRecordStrc* pEntry)
{
    Unicode wszLine1[0x80];
    Unicode wszLine2[0x80];
    int nColor1 = 0;
    int nColor2 = 0;
    int nHeight = 0x10;
    Unicode wszName[0x80];
    char szDefault[0x80];
    const char* szName = ROSTER_GetEntryName(pEntry);
    if (!szName)
    {
        strcpy(szDefault, "ERROR PLAYER NAME");
        szName = szDefault;
    }
    sub_00526320_ToUnicode(wszName, szName, 0x80);
    const int nA = ROSTER_IsPlayerHostile(pEntry);
    const int nB = ROSTER_PlayerAllowsLoot(pEntry);
    const int nC = ROSTER_IsHostileToPlayer(pEntry);
    const int nD = ROSTER_AllowsPlayerLoot(pEntry);
    const int bE = ROSTER_IsMaleClass(pEntry);
    if (nA == nC)
    {
        if (bE)
// build: symbol ?gawRosterHostileMale@* 0x00722450
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileMale[nA][nC]));
        else
// build: symbol ?gawRosterHostileFemale@* 0x00722458
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileFemale[nA][nC]));
    }
    else
    {
        if (bE)
            sub_005269D0(0x80, wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileMale[nA][nC]), wszName);
        else
            sub_005269D0(0x80, wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileFemale[nA][nC]), wszName);
    }
    if (WINMAIN_IsHardcore())
    {
        nHeight = 0x1E;
        if (nB == nD)
        {
            if (ROSTER_IsMaleClass(pEntry))
// build: symbol ?gawRosterLootMale@* 0x00722460
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootMale[nB][nD]));
            else
// build: symbol ?gawRosterLootFemale@* 0x00722468
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootFemale[nB][nD]));
        }
        else
        {
            if (ROSTER_IsMaleClass(pEntry))
                sub_005269D0(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootMale[nB][nD]), wszName);
            else
                sub_005269D0(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootFemale[nB][nD]), wszName);
        }
    }
    if (nA)
        nColor1 = 8;
    if (nC)
        nColor1 = 1;
    if (nB)
        nColor2 = 9;
    if (nD)
        nColor2 = 4;
    const int nWidth1 = D2Win_10121_GetTextWidth(wszLine1) + 0xA;
    const int nWidth2 = D2Win_10121_GetTextWidth(wszLine2) + 0xA;
    AUTOMAP_DrawFramedBox(gnPanelOffsetX + 0x24, 0x23 - gnPanelOffsetY, nWidth1 > nWidth2 ? nWidth1 : nWidth2, nHeight, gnBoxColor, 2);
    D2Win_10117_DrawText(wszLine1, gnPanelOffsetX + 0x29, 0x32 - gnPanelOffsetY, nColor1, 0);
    D2Win_10117_DrawText(wszLine2, gnPanelOffsetX + 0x29, 0x41 - gnPanelOffsetY, nColor2, 0);
}

void __cdecl sub_0049B330_DrawRosterButtonHints()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2StoredUnitRecordStrc* pFirst = ROSTER_GetNextStoredUnit(0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
    int bInTown = 0;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(pFirst);
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        bInTown = 1;
    while (pRow)
    {
        const int nRowY = pRow->nY;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + 0x24 && nMouseX <= gnPanelOffsetX + 0x8C && nMouseY >= nRowY - gnPanelOffsetY - 0x1A && nMouseY <= nRowY - gnPanelOffsetY)
            sub_0049B030_DrawRosterTooltip(pEntry);
        else
        {
            for (int k = 1; k < 5; ++k)
            {
                const int nY = pRow->aSlots[k].nY;
                const int nX = pRow->aSlots[k].nX;
                const int nBX = sub_00468730();
                const int nBY = sub_00468740();
                if (nBX >= gnPanelOffsetX + nX && nBX <= gnPanelOffsetX + nX + 0x14 && nBY >= nY - gnPanelOffsetY - 0x14 && nBY <= nY - gnPanelOffsetY)
                {
                    if (pRow->aSlots[k].nType == 1)
                    {
                        if (ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) >= 9)
                        {
                            if (pRow->nLevel >= 9)
                            {
                                if (!bInTown)
                                {
                                    sub_0049AAF0_DrawTextFrame(0, 0x1019, 0x6E, 0);
                                    {
                                        const int nTextX = TEXT_GetCenteredStringX(0x1019, 0x6E);
                                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1019), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 1, 0);
                                    }
                                    return;
                                }
                                if (ROSTER_TestHostileFlag(pEntry))
                                    sub_0049AF60_DrawButtonHint(0x100C, 0x100D, 0x6E, 0, 0x32, 0x41, 0);
                                else
                                    sub_0049AF60_DrawButtonHint(0x100A, 0x100B, 0x6E, 0, 0x32, 0x41, 0);
                                return;
                            }
                            sub_0049AAF0_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x101A, 0xA0);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x101B, 0xA0);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        sub_0049AAF0_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                        {
                            const int nTextX = GetCenteredStringXInline(0x101A, 0xA0);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                        }
                        {
                            const int nTextX = GetCenteredStringXInline(0x101B, 0xA0);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aSlots[k].nType == 2)
                    {
                        if (WINMAIN_IsHardcore())
                        {
                            if (ROSTER_TestLootFlag(pEntry))
                            {
                                sub_0049AAF0_DrawTextFrame(0x1011, 0x1010, 0xFF, 1);
                                {
                                    const int nTextX = TEXT_GetCenteredStringX(0x1010, 0xFF);
                                    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1010), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                                }
                                {
                                    const int nTextX = TEXT_GetCenteredStringX(0x1011, 0xFF);
                                    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1011), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                                }
                                return;
                            }
                            sub_0049AAF0_DrawTextFrame(0x100F, 0x100E, 0xFF, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x100E, 0xFF);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x100E), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x100F, 0xFF);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x100F), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                    }
                    else if (pRow->aSlots[k].nType == 3)
                    {
                        if (ROSTER_TestMuteFlag(pEntry))
                        {
                            sub_0049AAF0_DrawTextFrame(0x1013, 0x1012, 0x114, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1012, 0x114);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1012), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1013, 0x114);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1013), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        sub_0049AAF0_DrawTextFrame(0x1015, 0x1014, 0x114, 1);
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1014, 0x114);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1014), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                        }
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1015, 0x114);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1015), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aSlots[k].nType == 4)
                    {
                        if (ROSTER_TestSquelchFlag(pEntry))
                        {
                            sub_0049AAF0_DrawTextFrame(0, 0x1017, 0x128, 0);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1017, 0x128);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1017), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        sub_0049AAF0_DrawTextFrame(0, 0x1016, 0x128, 0);
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1016, 0x128);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1016), gnPanelOffsetX + nTextX, 0x37 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

#include "gen/data/Source/D2Client/Unknown_0049B030.inc"
struct D2StoredUnitRecordStrc;

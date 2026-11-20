#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}
};

#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    char unk0x00[4];
    D2RosterButtonStrc aButtons[5];
    char unk0xA4[0x19];
    int nLevel;
    int nLevelId;
    char unk0xC5[4];
    int nY;
    D2RosterUnitStrc* pNext;
};
#pragma pack(pop)

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_0049AAA0_GetCenteredStringX(unsigned short nStringIndex, int nCenterX);                  // 0x0049AAA0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);              // 0x005269D0
int __fastcall sub_0047A5E0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5E0
int __fastcall sub_0047A640(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A640
int __fastcall sub_0047A5B0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5B0
int __fastcall sub_0047A610(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A610
int __fastcall sub_0047A670(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A670
int __cdecl sub_0044B850_IsHardcore();                                                                      // 0x0044B850
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90
int __fastcall sub_00479CE0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CE0
int __fastcall sub_00479C20(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C20
int __fastcall sub_00479C60(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C60
int __fastcall sub_00479CA0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CA0
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern unsigned char gbGlobal_007BF034;                                                                     // 0x007BF034
extern D2RosterUnitStrc* gpRosterUnits_007BF014;                                                            // 0x007BF014
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

static __forceinline int GetCenteredStringXInline(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - sub_00501820(wszText) / 2;
}

static void __stdcall sub_0049AAF0_DrawTextFrame(unsigned short nAltString, unsigned short nString, int nX, int bLarge)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    const int nWidth = sub_00501820(wszText);
    int nAltWidth = 0;
    if (nAltString)
    {
        Unicode wszAlt[100];
        sub_005267E0(wszAlt, D2LANG_GetStringFromTblIndex(nAltString));
        nAltWidth = sub_00501820(wszAlt);
    }
    int nY = 0x23;
    int nHeight = 0x1E;
    if (!bLarge)
    {
        nY = 0x2A;
        nHeight = 0xF;
    }
    if (nWidth > nAltWidth)
        sub_0046EFD0_DrawFramedBox(gnGlobal_007A2858 - nWidth / 2 + nX - 5, nY - gnGlobal_007A285C, nWidth + 0xA, nHeight, gbGlobal_007BF034, 2);
    else
        sub_0046EFD0_DrawFramedBox(gnGlobal_007A2858 - nAltWidth / 2 + nX - 5, nY - gnGlobal_007A285C, nAltWidth + 0xA, nHeight, gbGlobal_007BF034, 2);
}

void __cdecl sub_0049ABD0_DrawRosterHoverHints()
{
    D2RosterUnitStrc* pRow = gpRosterUnits_007BF014;
    D2StoredUnitRecordStrc* pFirst = sub_004795A0_GetNextEntry(0);
    gbGlobal_007BF034 = D2Win_10034_MixRGB(0, 0, 0);
    if (sub_00479BC0_GetEntryIndex(pFirst) != 0xFFFF)
    {
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnGlobal_007A2858 + 0xE3 && nMouseX <= gnGlobal_007A2858 + 0x118 && nMouseY >= 0x18 - gnGlobal_007A285C && nMouseY <= 0x23 - gnGlobal_007A285C)
        {
            sub_0049AAF0_DrawTextFrame(0, 0x1018, 0xD5, 0);
            {
                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1018, 0xD5);
                sub_00502320(D2LANG_GetStringFromTblIndex(0x1018), nTextX + gnGlobal_007A2858, 0x37 - gnGlobal_007A285C, 0, 0);
            }
        }
    }
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(pFirst);
    while (pRow)
    {
        const int nY = pRow->aButtons[0].nY;
        const int nX = pRow->aButtons[0].nX;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnGlobal_007A2858 + nX && nMouseX <= gnGlobal_007A2858 + nX + 0x35 && nMouseY >= nY - gnGlobal_007A285C - 0x14 && nMouseY <= nY - gnGlobal_007A285C)
        {
            if (!pRow->aButtons[0].nType)
            {
                const int nState = pRow->aButtons[0].nState;
                if (nState == 0)
                {
                    sub_0049AAF0_DrawTextFrame(0x1005, 0x1004, 0xDA, 1);
                    {
                        const int nTextX = GetCenteredStringXInline(0x1004, 0xDA);
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1004), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                    }
                    {
                        const int nTextX = GetCenteredStringXInline(0x1005, 0xDA);
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1005), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                    }
                }
                else if (nState == 2)
                {
                    sub_0049AAF0_DrawTextFrame(0x1007, 0x1006, 0xDA, 1);
                    {
                        const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1006, 0xDA);
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1006), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                    }
                    {
                        const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1007, 0xDA);
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1007), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                    }
                }
                else if (nState == 4)
                {
                    sub_0049AAF0_DrawTextFrame(0x1009, 0x1008, 0xDA, 1);
                    {
                        const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1008, 0xDA);
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1008), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                    }
                    {
                        const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1009, 0xDA);
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1009), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = sub_004795A0_GetNextEntry(pEntry);
    }
}

static void __stdcall sub_0049AF60_DrawButtonHint(unsigned short nString1, unsigned short nString2, int nCenterX, int nUnused, int nY1, int nY2, int nColor)
{
    if (!nString2)
    {
        sub_0049AAF0_DrawTextFrame(0, nString1, nCenterX, 0);
        {
            const int nTextX = sub_0049AAA0_GetCenteredStringX(nString1, nCenterX);
            sub_00502320(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnGlobal_007A2858, nY1 - gnGlobal_007A285C, nColor, 0);
        }
        return;
    }
    sub_0049AAF0_DrawTextFrame(nString2, nString1, nCenterX, 1);
    {
        const int nTextX = sub_0049AAA0_GetCenteredStringX(nString1, nCenterX);
        sub_00502320(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnGlobal_007A2858, nY1 - gnGlobal_007A285C, nColor, 0);
    }
    {
        const int nTextX = sub_0049AAA0_GetCenteredStringX(nString2, nCenterX);
        sub_00502320(D2LANG_GetStringFromTblIndex(nString2), nTextX + gnGlobal_007A2858, nY2 - gnGlobal_007A285C, nColor, 0);
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
    const char* szName = sub_004795C0_GetEntryName(pEntry);
    if (!szName)
    {
        strcpy(szDefault, "ERROR PLAYER NAME");
        szName = szDefault;
    }
    sub_00526320_ToUnicode(wszName, szName, 0x80);
    const int nA = sub_0047A5E0(pEntry);
    const int nB = sub_0047A640(pEntry);
    const int nC = sub_0047A5B0(pEntry);
    const int nD = sub_0047A610(pEntry);
    const int bE = sub_0047A670(pEntry);
    if (nA == nC)
    {
        if (bE)
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722450[nA][nC]));
        else
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722458[nA][nC]));
    }
    else
    {
        if (bE)
            sub_005269D0(0x80, wszLine1, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722450[nA][nC]), wszName);
        else
            sub_005269D0(0x80, wszLine1, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722458[nA][nC]), wszName);
    }
    if (sub_0044B850_IsHardcore())
    {
        nHeight = 0x1E;
        if (nB == nD)
        {
            if (sub_0047A670(pEntry))
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722460[nB][nD]));
            else
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722468[nB][nD]));
        }
        else
        {
            if (sub_0047A670(pEntry))
                sub_005269D0(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722460[nB][nD]), wszName);
            else
                sub_005269D0(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterStrings_00722468[nB][nD]), wszName);
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
    const int nWidth1 = sub_00501820(wszLine1) + 0xA;
    const int nWidth2 = sub_00501820(wszLine2) + 0xA;
    sub_0046EFD0_DrawFramedBox(gnGlobal_007A2858 + 0x24, 0x23 - gnGlobal_007A285C, nWidth1 > nWidth2 ? nWidth1 : nWidth2, nHeight, gbGlobal_007BF034, 2);
    sub_00502320(wszLine1, gnGlobal_007A2858 + 0x29, 0x32 - gnGlobal_007A285C, nColor1, 0);
    sub_00502320(wszLine2, gnGlobal_007A2858 + 0x29, 0x41 - gnGlobal_007A285C, nColor2, 0);
}

void __cdecl sub_0049B330_DrawRosterButtonHints()
{
    D2RosterUnitStrc* pRow = gpRosterUnits_007BF014;
    D2StoredUnitRecordStrc* pFirst = sub_004795A0_GetNextEntry(0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
    int bInTown = 0;
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(pFirst);
    gbGlobal_007BF034 = D2Win_10034_MixRGB(0, 0, 0);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        bInTown = 1;
    while (pRow)
    {
        const int nRowY = pRow->nY;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnGlobal_007A2858 + 0x24 && nMouseX <= gnGlobal_007A2858 + 0x8C && nMouseY >= nRowY - gnGlobal_007A285C - 0x1A && nMouseY <= nRowY - gnGlobal_007A285C)
            sub_0049B030_DrawRosterTooltip(pEntry);
        else
        {
            for (int k = 1; k < 5; ++k)
            {
                const int nY = pRow->aButtons[k].nY;
                const int nX = pRow->aButtons[k].nX;
                const int nBX = sub_00468730();
                const int nBY = sub_00468740();
                if (nBX >= gnGlobal_007A2858 + nX && nBX <= gnGlobal_007A2858 + nX + 0x14 && nBY >= nY - gnGlobal_007A285C - 0x14 && nBY <= nY - gnGlobal_007A285C)
                {
                    if (pRow->aButtons[k].nType == 1)
                    {
                        if (sub_00479B90(sub_004795A0_GetNextEntry(0)) >= 9)
                        {
                            if (pRow->nLevel >= 9)
                            {
                                if (!bInTown)
                                {
                                    sub_0049AAF0_DrawTextFrame(0, 0x1019, 0x6E, 0);
                                    {
                                        const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1019, 0x6E);
                                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1019), nTextX + gnGlobal_007A2858, 0x37 - gnGlobal_007A285C, 1, 0);
                                    }
                                    return;
                                }
                                if (sub_00479CE0(pEntry))
                                    sub_0049AF60_DrawButtonHint(0x100C, 0x100D, 0x6E, 0, 0x32, 0x41, 0);
                                else
                                    sub_0049AF60_DrawButtonHint(0x100A, 0x100B, 0x6E, 0, 0x32, 0x41, 0);
                                return;
                            }
                            sub_0049AAF0_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x101A, 0xA0);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                            }
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x101B, 0xA0);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                            }
                            return;
                        }
                        sub_0049AAF0_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                        {
                            const int nTextX = GetCenteredStringXInline(0x101A, 0xA0);
                            sub_00502320(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                        }
                        {
                            const int nTextX = GetCenteredStringXInline(0x101B, 0xA0);
                            sub_00502320(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aButtons[k].nType == 2)
                    {
                        if (sub_0044B850_IsHardcore())
                        {
                            if (sub_00479C20(pEntry))
                            {
                                sub_0049AAF0_DrawTextFrame(0x1011, 0x1010, 0xFF, 1);
                                {
                                    const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1010, 0xFF);
                                    sub_00502320(D2LANG_GetStringFromTblIndex(0x1010), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                                }
                                {
                                    const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1011, 0xFF);
                                    sub_00502320(D2LANG_GetStringFromTblIndex(0x1011), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                                }
                                return;
                            }
                            sub_0049AAF0_DrawTextFrame(0x100F, 0x100E, 0xFF, 1);
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x100E, 0xFF);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x100E), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                            }
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x100F, 0xFF);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x100F), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                            }
                            return;
                        }
                    }
                    else if (pRow->aButtons[k].nType == 3)
                    {
                        if (sub_00479C60(pEntry))
                        {
                            sub_0049AAF0_DrawTextFrame(0x1013, 0x1012, 0x114, 1);
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1012, 0x114);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x1012), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                            }
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1013, 0x114);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x1013), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                            }
                            return;
                        }
                        sub_0049AAF0_DrawTextFrame(0x1015, 0x1014, 0x114, 1);
                        {
                            const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1014, 0x114);
                            sub_00502320(D2LANG_GetStringFromTblIndex(0x1014), nTextX + gnGlobal_007A2858, 0x32 - gnGlobal_007A285C, 0, 0);
                        }
                        {
                            const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1015, 0x114);
                            sub_00502320(D2LANG_GetStringFromTblIndex(0x1015), nTextX + gnGlobal_007A2858, 0x41 - gnGlobal_007A285C, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aButtons[k].nType == 4)
                    {
                        if (sub_00479CA0(pEntry))
                        {
                            sub_0049AAF0_DrawTextFrame(0, 0x1017, 0x128, 0);
                            {
                                const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1017, 0x128);
                                sub_00502320(D2LANG_GetStringFromTblIndex(0x1017), nTextX + gnGlobal_007A2858, 0x37 - gnGlobal_007A285C, 0, 0);
                            }
                            return;
                        }
                        sub_0049AAF0_DrawTextFrame(0, 0x1016, 0x128, 0);
                        {
                            const int nTextX = sub_0049AAA0_GetCenteredStringX(0x1016, 0x128);
                            sub_00502320(D2LANG_GetStringFromTblIndex(0x1016), gnGlobal_007A2858 + nTextX, 0x37 - gnGlobal_007A285C, 0, 0);
                        }
                        return;
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = sub_004795A0_GetNextEntry(pEntry);
    }
}

#include "gen/data/Source/D2Client/Unknown_0049B030.inc"
struct D2StoredUnitRecordStrc;

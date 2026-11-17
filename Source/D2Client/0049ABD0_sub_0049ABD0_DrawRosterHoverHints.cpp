struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}
};

struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2StoredUnitRecordStrc;

struct D2RosterButtonStrc
{
    int nX;
    int nY;
    int unk0x08[2];
    int nType;
    int nState;
    int unk0x18[2];
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
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry);                           // 0x004795C0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);              // 0x005269D0
int __fastcall sub_0047A5E0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5E0
int __fastcall sub_0047A640(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A640
int __fastcall sub_0047A5B0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5B0
int __fastcall sub_0047A610(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A610
int __fastcall sub_0047A670(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A670
int __cdecl sub_0044B850_IsHardcore();                                                                      // 0x0044B850
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
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
extern unsigned short gawRosterStrings_00722450[2][2];                                                      // 0x00722450
extern unsigned short gawRosterStrings_00722458[2][2];                                                      // 0x00722458
extern unsigned short gawRosterStrings_00722460[2][2];                                                      // 0x00722460
extern unsigned short gawRosterStrings_00722468[2][2];                                                      // 0x00722468
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

static __forceinline int GetStringWidthInline(unsigned short nStringIndex)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return sub_00501820(wszText);
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

static void __stdcall sub_0049AAF0_DrawTextFrame(unsigned short nAltString, unsigned short nString, int nX, int bLarge); // 0x0049AAF0

// 0x0049ABD0
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
                if (pRow->aButtons[0].nState == 0)
                {
                    sub_0049AAF0_DrawTextFrame(0x1005, 0x1004, 0xDA, 1);
                    {
                        const int nHalf = GetStringWidthInline(0x1004) / 2;
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1004), gnGlobal_007A2858 - nHalf + 0xDA, 0x32 - gnGlobal_007A285C, 0, 0);
                    }
                    {
                        const int nHalf = GetStringWidthInline(0x1005) / 2;
                        sub_00502320(D2LANG_GetStringFromTblIndex(0x1005), gnGlobal_007A2858 - nHalf + 0xDA, 0x41 - gnGlobal_007A285C, 0, 0);
                    }
                }
                else if (pRow->aButtons[0].nState == 2)
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
                else if (pRow->aButtons[0].nState == 4)
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

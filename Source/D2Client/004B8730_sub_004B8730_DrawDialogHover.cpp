struct Unicode
{
    unsigned short ch;
};

struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2ClientDialogStrc;

int __fastcall sub_004538D0(unsigned int nUIVar);                                                    // 0x004538D0
int __cdecl sub_004549C0_IsPanelAllocated();                                                                // 0x004549C0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                       // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
int __cdecl sub_00463DF0();                                                                    // 0x00463DF0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __cdecl sub_00487B30_ResetNpcState();                                                                  // 0x00487B30
void __cdecl sub_0048A6F0_Clear();                                                                          // 0x0048A6F0
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog);
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId);                                                          // 0x0061AAF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2ClientDialogStrc* gpDialog_007C0E64;                                                               // 0x007C0E64
extern D2ClientDialogStrc* gpDialog_007C0E6C;                                                               // 0x007C0E6C
extern int gnGlobal_007C0E7C;                                                                               // 0x007C0E7C

// 0x004B8730
void __cdecl sub_004B8730_DrawDialogHover()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (gnGlobal_007C0E7C > 2 && !sub_004549C0_IsPanelAllocated())
    {
        if (nX >= gnGlobal_007A2858 + 0x111 && nX <= gnGlobal_007A2858 + 0x133 && nY >= 0xA8 - gnGlobal_007A285C && nY <= 0xCA - gnGlobal_007A285C)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnGlobal_007A2858 + 0xEF, 0xA7 - gnGlobal_007A285C, 0, 0);
        if (nX >= gnGlobal_007A2858 + 0xDD && nX <= gnGlobal_007A2858 + 0xFF && nY >= 0x17F - gnGlobal_007A285C && nY <= 0x1A1 - gnGlobal_007A285C)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnGlobal_007A2858 + 0xBB, 0x17E - gnGlobal_007A285C, 0, 0);
        if (nX >= gnGlobal_007A2858 + 0x111 && nX <= gnGlobal_007A2858 + 0x133 && nY >= 0x17F - gnGlobal_007A285C && nY <= 0x1A1 - gnGlobal_007A285C)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1022), gnGlobal_007A2858 + 0x107, 0x17E - gnGlobal_007A285C, 0, 0);
    }

    if (sub_00463DD0_GetPlayerUnit())
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
        if (sub_00463DF0() || (pRoom && !DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))))
        {
            if (sub_004538D0(0x17))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                sub_00455F20(0x17, 1, 0);
                sub_0048A6F0_Clear();
                sub_00487B30_ResetNpcState();
                gnGlobal_007C0E7C = 0;
            }
            return;
        }
    }

    if (gnGlobal_007C0E7C >= 3 && gnGlobal_007C0E7C <= 6)
        return;
    if (!gnGlobal_007C0E7C)
        return;
    if (gnGlobal_007C0E7C == 1)
    {
        if (gpDialog_007C0E6C)
            sub_004B8100_DrawDialog(gpDialog_007C0E6C);
    }
    else if (gnGlobal_007C0E7C == 2)
    {
        if (gpDialog_007C0E64)
            sub_004B8100_DrawDialog(gpDialog_007C0E64);
    }
}

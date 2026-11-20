#include "D2Client.h"
#include "D2Structs.h"
struct D2UnitStrc;


struct Unicode;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __cdecl sub_004939B0_LoadPopupHireling(); // 0x004939B0
void __cdecl sub_004B4830_Rebuild(); // 0x004B4830
int __cdecl sub_004B4CF0_NpcMenuReturn(); // 0x004B4CF0
void* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnCallback)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28, int nArg2C); // 0x004B7EB0
void __fastcall sub_004B8020(void* pDialog); // 0x004B8020
void __fastcall sub_004B8370_SetCtrlState(void* pDialog, int nValue); // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pDialog, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6, int (__cdecl* pfnCallback)(), int nArg8); // 0x004B85F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern void* gpDialog_007C0D63; // 0x007C0D63
extern void* gpDialog_007C0D67; // 0x007C0D67
extern unsigned char gbGlobal_007C0D89; // 0x007C0D89

static __forceinline void sub_004B5640_RefreshNpcMenu()
{
    if (gnGlobal_007C0D29)
    {
        D2UnitStrc* pNpc = sub_00463990(gnGlobal_007C0D25, 1);
        if (pNpc)
        {
            switch ((unsigned int)pNpc->dwClassId)
            {
            case 0xF4:
            case 0xF5:
            case 0xF6:
            case 0x109:
            case 0x208:
                gnGlobal_00726EBC = 2;
                gnGlobal_00726EE3 = 2;
                gnGlobal_00726F0A = 2;
                gnGlobal_00726F31 = 2;
                gnGlobal_00727216 = 2;
                break;
            }
        }
    }

    sub_004B4830_Rebuild();
}

// 0x004B5640
void __cdecl sub_004B5640_OpenNpcMenu()
{
    if (gpDialog_007C0D67)
    {
        sub_004B8020(gpDialog_007C0D67);
        gpDialog_007C0D67 = 0;
    }

    const unsigned char nType = gbGlobal_007C0D89;
    if (nType != 5)
    {
        if (nType != 6 && nType != 3)
        {
                int nStringId;
                switch (nType)
                {
                case 15:
                    nStringId = 0xD23;
                    break;
                case 16:
                    nStringId = 0xD1D;
                    break;
                case 12:
                    nStringId = 0xD22;
                    break;
                case 10:
                    nStringId = 0xD1C;
                    break;
                case 11:
                    nStringId = 0xD20;
                    break;
                case 7:
                case 8:
                    nStringId = 0xD1E;
                    break;
                default:
                    nStringId = 0xD21;
                    break;
                }

                gnGlobal_007C0C6B = 12;
                D2_ASSERT(!gpDialog_007C0D63, 0x1413);

                gpDialog_007C0D63 = sub_004B7EB0_CreateDialog(sub_00468730(), sub_00468740(), sub_004B4CF0_NpcMenuReturn, 0, 0, 1, 1, 0, 0, 0, 1);
                sub_004B8370_SetCtrlState(gpDialog_007C0D63, 1);
                sub_004B85F0_AddTextLine(gpDialog_007C0D63, D2LANG_GetStringFromTblIndex(nStringId), 0x15, 0, 1, 1, 0, 0);
                sub_004B85F0_AddTextLine(gpDialog_007C0D63, D2LANG_GetStringFromTblIndex(0xD4B), 0xF, 0, 0, 1, sub_004B4CF0_NpcMenuReturn, 1);
            return;
        }
    }
    else
    {
        sub_004939B0_LoadPopupHireling();
    }

    sub_004B5640_RefreshNpcMenu();
}

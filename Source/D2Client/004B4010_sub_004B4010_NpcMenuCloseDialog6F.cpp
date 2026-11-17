extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientDialogStrc;
struct D2InventoryStrc;
struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};
struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};
typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3);                    // 0x004786D0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0
int __cdecl sub_004B4070();                                                                                 // 0x004B4070
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840
void __fastcall sub_004A10E0(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);                         // 0x004A10E0
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0
int __fastcall sub_004B6A30_NpcTextCallback(void* pContext, int nArg, int nValue);                          // 0x004B6A30
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __cdecl sub_004B4830_Rebuild();                                                                        // 0x004B4830
void __cdecl sub_00487D40_ResetButtonsFromState7();                                                         // 0x00487D40

extern D2ClientDialogStrc* gpDialog_007C0D6B;                                                               // 0x007C0D6B
extern D2ClientDialogStrc* gpDialog_007C0D6F;                                                               // 0x007C0D6F
extern D2ClientDialogStrc* gpDialog_007C0D7B;                                                               // 0x007C0D7B
extern D2ClientDialogStrc* gpDialog_007C0D63;                                                               // 0x007C0D63
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern char gbGlobal_007C0C69;                                                                              // 0x007C0C69
extern unsigned short gwGlobal_007C0C77;                                                                    // 0x007C0C77
extern unsigned short gwGlobal_007C0C79;                                                                    // 0x007C0C79
extern int gnNpcSoundActive_007C0DB4;                                                                       // 0x007C0DB4
extern int gnNpcSoundHandle_007C0DB8;                                                                       // 0x007C0DB8
int gdwGlobal_007C0DB0;                                                                                     // 0x007C0DB0
D2UnitStrc* gpUnit_007C0DD4;                                                                                // 0x007C0DD4
unsigned short gwGlobal_007C0DD8;                                                                           // 0x007C0DD8
extern D2ClientStringListStrc gtStringList_007C0D9A;                                                        // 0x007C0D9A

void __fastcall sub_004B1980_AddUsedString(unsigned short wStringId)
{
    if (gtStringList_007C0D9A.wCount < 9)
    {
        gtStringList_007C0D9A.awStrings[gtStringList_007C0D9A.wCount] = wStringId;
        gtStringList_007C0D9A.wCount++;
    }
}

// 0x004B4010
int __cdecl sub_004B4010_NpcMenuCloseDialog6F()
{
    if (gbGlobal_007C0C69)
        return 0;

    if (gpDialog_007C0D6F)
    {
        sub_004B8020(gpDialog_007C0D6F);
        gpDialog_007C0D6F = 0;
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }
    return 1;
}

// 0x004B4290
int __cdecl sub_004B4290_NpcMenuSend38()
{
    sub_004B4070();
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0);
    return 1;
}

// 0x004B42B0
int __cdecl sub_004B42B0_NpcMenuTrade()
{
    if (gnNpcSoundActive_007C0DB4)
    {
        if (gnNpcSoundHandle_007C0DB8)
        {
            sub_004BA840(gnNpcSoundHandle_007C0DB8);
            gnNpcSoundHandle_007C0DB8 = 0;
        }
        gnNpcSoundActive_007C0DB4 = 0;
    }

    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0D25, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 1;
    }

    gnGlobal_007C0C6B = 3;
    gdwGlobal_007C0DB0 = 0;
    sub_00455F20(0xC, 0, 0);
    sub_004786D0_SendPacket(0x38, 1, gnGlobal_007C0D25, 0);
    gpUnit_007C0DD4 = sub_00463DD0();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B45D0
int __cdecl sub_004B45D0_NpcMenuCancel()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B4620
int __cdecl sub_004B4620_NpcMenuCancelB()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B4670
int __cdecl sub_004B4670_NpcMenuCancelText()
{
    if (gpDialog_007C0D7B)
    {
        sub_004B8020(gpDialog_007C0D7B);
        gpDialog_007C0D7B = 0;
        sub_004786A0_SendIntInt(0x31, gnGlobal_007C0D25, gwGlobal_007C0C77);
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B46D0
int __cdecl sub_004B46D0_NpcMenuCancelTextB()
{
    if (gpDialog_007C0D7B)
    {
        sub_004B8020(gpDialog_007C0D7B);
        gpDialog_007C0D7B = 0;
        sub_004786A0_SendIntInt(0x31, gnGlobal_007C0D25, gwGlobal_007C0C77);
    }
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    return 1;
}

// 0x004B4730
int __cdecl sub_004B4730_NpcMenuTalk()
{
    if (gpDialog_007C0D7B)
    {
        sub_004B8020(gpDialog_007C0D7B);
        gpDialog_007C0D7B = 0;
    }

    if (!(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 1;
    }

    sub_004A10E0(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0, gwGlobal_007C0C77, 0);
    sub_004B1980_AddUsedString(gwGlobal_007C0C77);
    if (gwGlobal_007C0C79 == 0xFFFF)
    {
        gnGlobal_007C0C6B = 0;
    }
    else
    {
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B6A30_NpcTextCallback, 0);
    }
    sub_004786A0_SendIntInt(0x31, gnGlobal_007C0D25, gwGlobal_007C0C77);
    return 1;
}

// 0x004B4CF0
int __cdecl sub_004B4CF0_NpcMenuReturn()
{
    sub_00466FE0();
    sub_004B9A00(1, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0D63);
    gpDialog_007C0D63 = 0;
    if (gnGlobal_007C0C6B == 0xC)
    {
        if (gnGlobal_007C0D31 == 5)
        {
            sub_004B3C20(gnGlobal_007C0D25);
            sub_00455F20(8, 1, 0);
            return 1;
        }
        sub_004B4830_Rebuild();
        return 1;
    }

    D2_ASSERT(gnGlobal_007C0D31 != 6, 0xD55);
    D2_ASSERT(gnGlobal_007C0C6B != 8, 0xD56);
    gnGlobal_007C0C6B = 3;
    sub_00487D40_ResetButtonsFromState7();
    return 1;
}

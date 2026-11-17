#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ClientStringListStrc;
struct D2NpcMessageStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __cdecl sub_00466FE0(); // 0x00466FE0
void __cdecl sub_00487C20_ResetButtonsFromState5(); // 0x00487C20
void __cdecl sub_004B1E80(); // 0x004B1E80
int __cdecl sub_004B5C60_Handler(); // 0x004B5C60
void __fastcall sub_004B8020(void* pRes); // 0x004B8020

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x8];
    int dwAnimMode;
    unsigned char unk_14[0x4C];
    D2InventoryStrc* pInventory;
};

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0();
    virtual unsigned int GetAt(int nIndex);
};

extern unsigned char gbFound_007C0DDA; // 0x007C0DDA
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
void __cdecl sub_00453AE0(); // 0x00453AE0
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __fastcall sub_004C0620(int nArg); // 0x004C0620
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __fastcall sub_00478EE0_GetPetCount(D2UnitStrc* pOwner, int nPetType); // 0x00478EE0
void __cdecl sub_004B3610_CloseTradeDialog(); // 0x004B3610
extern int (__cdecl* gpfnGlobal_00726CD7)(); // 0x00726CD7
extern short gwGlobal_00726CC9; // 0x00726CC9
extern int (__cdecl* gpfnGlobal_00727253)(); // 0x00727253
extern short gwGlobal_00727245; // 0x00727245
extern int (__cdecl* gpfnGlobal_007272A5)(); // 0x007272A5
extern short gwGlobal_00727295; // 0x00727295
extern unsigned char gbGlobal_007C0D89; // 0x007C0D89
void __cdecl sub_004B2940(); // 0x004B2940

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

void __fastcall sub_004B3C20(int nValue); // 0x004B3C20
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_004BA840(int nHandle); // 0x004BA840
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0
int __fastcall sub_004B6A30_NpcTextCallback(void* pContext, int nArg, int nValue); // 0x004B6A30
void __cdecl sub_004B4830_Rebuild(); // 0x004B4830
void __cdecl sub_00487D40_ResetButtonsFromState7(); // 0x00487D40
extern D2ClientDialogStrc* gpDialog_007C0D63; // 0x007C0D63
extern char gbGlobal_007C0C69; // 0x007C0C69
extern int gnNpcSoundActive_007C0DB4; // 0x007C0DB4
extern int gnNpcSoundHandle_007C0DB8; // 0x007C0DB8
extern D2ClientStringListStrc gtStringList_007C0D9A; // 0x007C0D9A

#pragma pack(push, 1)
struct D2NpcMessageStrc
{
    unsigned short nMessage;
    char unk0x02[9];
    int nClass;
};

struct D2NpcEntryStrc
{
    char unk0x00[5];
    D2NpcMessageStrc* pMessages;
    int nCount;
    int nIndex;
    char bSelected;
};

#pragma pack(pop)

void __cdecl sub_004B17A0();
int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue);
extern unsigned char gbGlobal_007C0C6A; // 0x007C0C6A

// 0x004B2E70
int __cdecl sub_004B2E70_MenuBack()
{
    if (gnGlobal_007C0D31 == 5)
    {
        if (gpRes_007C0D5F)
        {
            sub_004B8020(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B1E80();
        return 1;
    }
    if (gnGlobal_007C0C6B == 4)
    {
        if (gpRes_007C0D5F)
        {
            sub_004B8020(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B2650(0, 0);
        return 1;
    }
    sub_00466FE0();
    D2_ASSERT(gnGlobal_007C0C6B != 4, 0x14F9);
    return 1;
}

// 0x004B2F00
int __cdecl sub_004B2F00_MenuClose()
{
    sub_004B8020(gpRes_007C0D5F);
    gpRes_007C0D5F = 0;
    if (gnGlobal_007C0D31 == 5)
    {
        sub_004B5C60_Handler();
        return 1;
    }
    sub_00487C20_ResetButtonsFromState5();
    gnGlobal_007C0C6B = 3;
    sub_00466FE0();
    return 1;
}

int gnGlobal_007C0C60; // 0x007C0C60

int gnGlobal_007C0C64; // 0x007C0C64

// 0x004B3360
void __fastcall sub_004B3360(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x13E && pUnit->dwAnimMode == 2)
        gbFound_007C0DDA = 1;
}

// 0x004B35B0
int __cdecl sub_004B35B0_NpcMenuHandler()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }
    sub_00455F20(8, 1, 0);
    sub_00453AE0();
    sub_00487990_ResetHover();
    gnGlobal_007C0C6B = 7;
    gnGlobal_007C0D31 = 0;
    sub_004C0620(gnGlobal_007C0D25);
    return 1;
}

// 0x004B3660
int __cdecl sub_004B3660_TradeMenuHandler()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    const int nCount = gpTradeObj_007C0D83->GetCount();
    gnGlobal_007C0C60 = nCount;
    gnGlobal_007C0C64 = gnGlobal_007C0D25;
    if (nCount < 10 && gpTradeObj_007C0D83->GetAt(nCount) < 10)
    {
        if (sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0) == -1
            && (!sub_0044DCC0() || (!sub_00478EE0_GetPetCount(sub_00463DD0(), 7) && gwGlobal_00725494 == 0xFFFF)))
        {
            sub_004B1E80();
            return 0;
        }
        sub_004B3610_CloseTradeDialog();
    }
    return 0;
}

// 0x004B3700
int __cdecl sub_004B3700_InitHandler()
{
    gnGlobal_00726CC1 = 4;
    gpfnGlobal_00726CD7 = sub_004B35B0_NpcMenuHandler;
    gwGlobal_00726CC9 = 0xFB1;
    return 1;
}

// 0x004B3730
int __cdecl sub_004B3730_InitHandler()
{
    gnGlobal_0072723D = 4;
    gpfnGlobal_00727253 = sub_004B35B0_NpcMenuHandler;
    gwGlobal_00727245 = 0x58DC;
    return 1;
}

// 0x004B3760
int __cdecl sub_004B3760_InitHandler()
{
    gnGlobal_0072728B = 5;
    gpfnGlobal_007272A5 = sub_004B35B0_NpcMenuHandler;
    gwGlobal_00727295 = 0x58DD;
    return 1;
}

// 0x004B3C00
void __fastcall sub_004B3C00(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 0 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

int gdwGlobal_007C0DB0; // 0x007C0DB0

D2UnitStrc* gpUnit_007C0DD4; // 0x007C0DD4

unsigned short gwGlobal_007C0DD8; // 0x007C0DD8

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

// 0x004B40D0
static void __stdcall sub_004B40D0_ShowNpcMessage(char bFlag, int nIndex)
{
    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    if (!pNpc)
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gbGlobal_007C0C69 = 1;
    sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
    sub_004B8020(gpRes_007C0D6F);
    gpRes_007C0D6F = 0;
    gpNpcEntry_007C0C7D->bSelected = 1;
    if (!gbGlobal_007C0C6A)
    {
        sub_004B17A0();
        if (bFlag)
            nIndex = gpNpcEntry_007C0C7D->nIndex;
    }
    D2UnitStrc* pUnit = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    sub_004A10E0(pUnit, gpNpcEntry_007C0C7D->pMessages[nIndex % gpNpcEntry_007C0C7D->nCount].nMessage, 0);
}

// 0x004B41C0
int __cdecl sub_004B41C0_NextNpcMessage()
{
    sub_004B40D0_ShowNpcMessage(1, gpNpcEntry_007C0C7D->nIndex);
    return 1;
}

// 0x004B41E0
int __cdecl sub_004B41E0_GreetNpcMessage()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    if (gnGlobal_007C0D29)
    {
        D2UnitStrc* pNpc = sub_00463990(gnGlobal_007C0D25, 1);
        if (pNpc)
        {
            switch (pNpc->dwClassId)
            {
            case 0x201:
                if (nClass == 4)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xF);
                    return 1;
                }
                break;
            case 0x202:
                if (nClass == 2)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xB);
                    return 1;
                }
                break;
            case 0x203:
                if (nClass == 3)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xA);
                    return 1;
                }
                break;
            }
        }
    }
    if (nClass == gpNpcEntry_007C0C7D->pMessages[1].nClass)
        sub_004B40D0_ShowNpcMessage(0, 1);
    else
        sub_004B40D0_ShowNpcMessage(0, 0);
    return 1;
}

// 0x004B5140
int __cdecl sub_004B5140_NpcMenuAction28()
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
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x28);
    return 1;
}

// 0x004B51A0
int __cdecl sub_004B51A0_NpcMenuAction4B()
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
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x4B);
    return 1;
}

// 0x004B5200
int __cdecl sub_004B5200_NpcMenuAction6D()
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
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x6D);
    return 1;
}

// 0x004B5260
int __cdecl sub_004B5260_NpcMenuAction28b()
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
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 0x28);
    return 1;
}

// 0x004B52C0
int __cdecl sub_004B52C0_NpcMenuAction01()
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
    sub_004786D0_SendPacket(0x38, 0, gnGlobal_007C0D25, 1);
    return 1;
}

struct D2ClientDialogStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x8];
    int dwAnimMode;
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

extern unsigned char gbFound_007C0DDA;                                                                      // 0x007C0DDA
extern D2ClientDialogStrc* gpDialog_007C0D6B;                                                               // 0x007C0D6B
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
void __fastcall sub_004C0620(int nArg);                                                                     // 0x004C0620
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
extern D2NpcTradeObjStrc* gpTradeObj_007C0D83;                                                              // 0x007C0D83
int gnGlobal_007C0C60;                                                                                      // 0x007C0C60
int gnGlobal_007C0C64;                                                                                      // 0x007C0C64
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                  // 0x00478F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_00478EE0_GetPetCount(D2UnitStrc* pOwner, int nPetType);                                  // 0x00478EE0
extern unsigned short gwGlobal_00725494;                                                                    // 0x00725494
void __cdecl sub_004B1E80();                                                                                // 0x004B1E80
void __cdecl sub_004B3610_CloseTradeDialog();                                                               // 0x004B3610
extern int gnGlobal_00726CC1;                                                                               // 0x00726CC1
extern int (__cdecl* gpfnGlobal_00726CD7)();                                                                // 0x00726CD7
extern short gwGlobal_00726CC9;                                                                             // 0x00726CC9
extern int gnGlobal_0072723D;                                                                               // 0x0072723D
extern int (__cdecl* gpfnGlobal_00727253)();                                                                // 0x00727253
extern short gwGlobal_00727245;                                                                             // 0x00727245
extern int gnGlobal_0072728B;                                                                               // 0x0072728B
extern int (__cdecl* gpfnGlobal_007272A5)();                                                                // 0x007272A5
extern short gwGlobal_00727295;                                                                             // 0x00727295
extern unsigned char gbGlobal_007C0D89;                                                                     // 0x007C0D89
extern int gnGlobal_007C0D8E;                                                                               // 0x007C0D8E
extern int gnGlobal_007C0D96;                                                                               // 0x007C0D96
void __cdecl sub_004B2940();                                                                                // 0x004B2940

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

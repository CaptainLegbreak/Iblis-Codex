#include "D2Client.h"

#define D2_FREE_PANEL_CEL(pCel) if (pCel) { sub_00478A00(pCel); pCel = 0; }
struct D2PetTypeTxt;

struct D2UnitStrc
{
    int dwUnitType;
    unsigned char unk_04[0x5C];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBE8];
    D2PetTypeTxt* pPetTypeTxt;
    char unk0xBEC[0x04];
    int nPetTypeTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny); // 0x00478F20
int __fastcall sub_00478F70(D2UnitStrc* pUnit); // 0x00478F70
int __fastcall sub_0047A2C0(D2UnitStrc* pUnit); // 0x0047A2C0
void __fastcall sub_00496BE0_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg); // 0x00496BE0
int __cdecl D2GFX_GetResolutionMode(); // 0x004F5160
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern void* gapHirelingIcons_007BEEB0[7]; // 0x007BEEB0
extern int gnGlobal_007BEECC; // 0x007BEECC
extern void* gpCel_007BEF18; // 0x007BEF18
extern void* gpCel_007BEF1C; // 0x007BEF1C
extern void* gpCel_007BEF74; // 0x007BEF74
extern int gbGlobal_007BEFA0; // 0x007BEFA0
extern unsigned char gnTextColorA_007BEFBB; // 0x007BEFBB
extern unsigned char gnTextColorB_007BEFE4; // 0x007BEFE4
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

struct D2PetTypeTxt
{
    unsigned int dwHcIdx;
    unsigned char nPetFlags[4];
    short wGroup;
    short wBaseMax;
    unsigned short wName;
    unsigned char nIconType;
    char szIcon[5][32];
    char unk0xAF;
    unsigned short wClass[5];
    char unk0xBA[0x26];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId); // 0x00479120
extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern void** gppHirelingCels_007BEEAC; // 0x007BEEAC

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __fastcall sub_00467410_SetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue); // 0x00467410
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc*,int,int); // 0x00478F20
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
D2UnitStrc* __fastcall sub_00463990(int,int); // 0x00463990
int __fastcall sub_00479120_GetHirelingClassId(int); // 0x00479120
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0
void __fastcall sub_004CBDE0_PlayEventSound(int,unsigned char,unsigned short); // 0x004CBDE0

void** gppHirelingCels_007BEEAC; // 0x007BEEAC

int gnGlobal_007BEEDC; // 0x007BEEDC

int gnGlobal_007BEEE0; // 0x007BEEE0

int gnGlobal_007BEEE8; // 0x007BEEE8

void* gpGlobal_007BEEEC; // 0x007BEEEC

void* gpGlobal_007BEEF0; // 0x007BEEF0

void* gpGlobal_007BEEF4; // 0x007BEEF4

void* gpCel_007BEF0C; // 0x007BEF0C

void* gpCel_007BEF10; // 0x007BEF10

void* gpCel_007BEF14; // 0x007BEF14

void* gpCel_007BEF20; // 0x007BEF20

void* gpCel_007BEF24; // 0x007BEF24

void* gpCel_007BEF28; // 0x007BEF28

void* gpCel_007BEF2C; // 0x007BEF2C

void* gpCel_007BEF60; // 0x007BEF60

void* gpCel_007BEF64; // 0x007BEF64

void* gpCel_007BEF68; // 0x007BEF68

void* gpCel_007BEF70; // 0x007BEF70

void* gpCel_007BEF78; // 0x007BEF78

void* gpCellFile_007BEF7C; // 0x007BEF7C

void* gpCel_007BEF80; // 0x007BEF80

// 0x00492EC0
void __cdecl sub_00492EC0_FreeHirelingIcons()
{
    for (int i = 0; i < 7; ++i)
    {
        if (gapHirelingIcons_007BEEB0[i])
        {
            sub_00478A00(gapHirelingIcons_007BEEB0[i]);
            gapHirelingIcons_007BEEB0[i] = 0;
        }
    }
    if (gppHirelingCels_007BEEAC)
    {
        const int nCount = sgptDataTables->nPetTypeTxtRecordCount * 5;
        for (int i = 0; i < nCount; ++i)
        {
            void* pCel = gppHirelingCels_007BEEAC[i];
            if (pCel)
            {
                sub_00478A00(pCel);
            }
        }
        sub_0040B480(0, gppHirelingCels_007BEEAC, ".\\UI\\Hireables.cpp", 0xB7, 0);
        gppHirelingCels_007BEEAC = 0;
    }
}

// 0x00493340
void __cdecl sub_00493340_UpdateHirelingPanel()
{
    if (gnGlobal_007BEECC == 2)
    {
        gnGlobal_007BEEE8 = 0;
        gnGlobal_007BEEE0 = 0;
        gnGlobal_007BEEDC = 0;
        return;
    }
    D2UnitStrc* pPlayer = sub_00463DD0();
    int bHasPet = 0;
    if (sub_00478F70(pPlayer))
    {
        bHasPet = 1;
    }
    if ((sub_0047A2C0(pPlayer) && gnGlobal_007BEECC != 1) || bHasPet)
    {
        const int nPetId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
        D2UnitStrc* pPet;
        if (nPetId == -1 || ((pPet = sub_00463990(nPetId, 1)) != 0 && sub_00464820_IsDeadOrDying(pPet)))
        {
            gnGlobal_007BEEDC = 0;
            gnGlobal_007BEEE0 = 0;
            gnGlobal_007BEEE8 = 0;
        }
        if (!sub_004538D0(0x13))
        {
            sub_00455F20(0x13, 0, 0);
        }
    }
    else
    {
        gnGlobal_007BEEE8 = 0;
        gnGlobal_007BEEE0 = 0;
        gnGlobal_007BEEDC = 0;
        if (sub_004538D0(0x13))
        {
            sub_00455F20(0x13, 1, 0);
        }
    }
}

// 0x004942D0
int __cdecl sub_004942D0_GetHelpMenuSetting()
{
    if (gdwHelpMenu_00722310 == 0xFFFFFFFF)
    {
        gdwHelpMenu_00722310 = 0;
        SRegLoadValue("Diablo II", "Help Menu", 1, &gdwHelpMenu_00722310);
    }
    return gdwHelpMenu_00722310;
}

// 0x00494320
void __cdecl sub_00494320_LoadHelpCels()
{
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (!gpGlobal_007BEEEC)
        {
            gpGlobal_007BEEEC = sub_004520C0_LoadUiCelFile("Menu\\800helpborder");
        }
        else
        {
            sub_00478A00(gpGlobal_007BEEEC);
            gpGlobal_007BEEEC = 0;
            gpGlobal_007BEEEC = sub_004520C0_LoadUiCelFile("Menu\\800helpborder");
        }
    }
    else
    {
        if (!gpGlobal_007BEEEC)
        {
            gpGlobal_007BEEEC = sub_004520C0_LoadUiCelFile("Menu\\helpborder");
        }
        else
        {
            sub_00478A00(gpGlobal_007BEEEC);
            gpGlobal_007BEEEC = 0;
            gpGlobal_007BEEEC = sub_004520C0_LoadUiCelFile("Menu\\helpborder");
        }
    }
    if (!gpGlobal_007BEEF0)
    {
        gpGlobal_007BEEF0 = sub_004520C0_LoadUiCelFile("Menu\\helpwhitebullet");
    }
    if (!gpGlobal_007BEEF4)
    {
        gpGlobal_007BEEF4 = sub_004520C0_LoadUiCelFile("Menu\\helpyellowbullet");
    }
}

// 0x00494EE0
void __cdecl sub_00494EE0_FreeHelpCels()
{
    if (gpGlobal_007BEEEC)
    {
        sub_00478A00(gpGlobal_007BEEEC);
        gpGlobal_007BEEEC = 0;
    }
    if (gpGlobal_007BEEF0)
    {
        sub_00478A00(gpGlobal_007BEEF0);
        gpGlobal_007BEEF0 = 0;
    }
    if (gpGlobal_007BEEF4)
    {
        sub_00478A00(gpGlobal_007BEEF4);
        gpGlobal_007BEEF4 = 0;
    }
}

// 0x00496990
void __cdecl sub_00496990_FreePanelCels()
{
    D2_FREE_PANEL_CEL(gpCellFile_007BEF7C);
    D2_FREE_PANEL_CEL(gpCel_007BEF64);
    D2_FREE_PANEL_CEL(gpCel_007BEF78);
    D2_FREE_PANEL_CEL(gpCel_007BEF24);
    D2_FREE_PANEL_CEL(gpCel_007BEF60);
    D2_FREE_PANEL_CEL(gpCel_007BEF14);
    D2_FREE_PANEL_CEL(gpCel_007BEF10);
    D2_FREE_PANEL_CEL(gpCel_007BEF74);
    D2_FREE_PANEL_CEL(gpCel_007BEF18);
    D2_FREE_PANEL_CEL(gpCel_007BEF1C);
    D2_FREE_PANEL_CEL(gpCel_007BEF68);
    D2_FREE_PANEL_CEL(gpCel_007BEF80);
    D2_FREE_PANEL_CEL(gpCel_007BEF70);
    D2_FREE_PANEL_CEL(gpCel_007BEF2C);
    D2_FREE_PANEL_CEL(gpCel_007BEF20);
    D2_FREE_PANEL_CEL(gpCel_007BEF0C);
    D2_FREE_PANEL_CEL(gpCel_007BEF28);
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
}

// 0x00496CF0
void __cdecl sub_00496CF0_ValidateActiveSkills()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
    {
        return;
    }
    D2SkillStrc* pSkill = UNITS_GetLeftSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillLevel(pPlayer, pSkill, 1) <= 0)
    {
        SKILLS_RemoveSkill(pPlayer, SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\panel.cpp", 0x289), ".\\UI\\panel.cpp", 0x289);
        SKILLS_SetLeftActiveSkill(pPlayer, 0, -1);
        pSkill = UNITS_GetLeftSkill(pPlayer);
    }
    sub_00496BE0_DrawSkillInfo(pPlayer, pSkill, 0x75, gnGlobal_00711470, 1);
    pSkill = UNITS_GetRightSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillLevel(pPlayer, pSkill, 1) <= 0)
    {
        SKILLS_RemoveSkill(pPlayer, SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\panel.cpp", 0x294), ".\\UI\\panel.cpp", 0x294);
        SKILLS_SetRightActiveSkill(pPlayer, 0, -1);
        pSkill = UNITS_GetRightSkill(pPlayer);
    }
    sub_00496BE0_DrawSkillInfo(pPlayer, pSkill, gnGlobal_0071146C - 0xA5, gnGlobal_00711470, 0);
}

// 0x00497270
void __cdecl sub_00497270_InitTextColorA()
{
    gnTextColorA_007BEFBB = D2Win_10034_MixRGB(0xF4, 0xC0, 0x4C);
}

// 0x00497290
void __cdecl sub_00497290_InitTextColorB()
{
    gnTextColorB_007BEFE4 = D2Win_10034_MixRGB(0, 0, 0xFF);
}

// 0x004979E0
int __cdecl sub_004979E0()
{
    return gbGlobal_007BEFA0 != 0;
}

// 0x004979F0
int __cdecl sub_004979F0()
{
    switch (gnUiRecordIndex_00722354)
    {
    case 2:
        return 1;
    case 1:
    case 4:
        return 2;
    case 0:
    case 5:
        return 3;
    default:
        return 4;
    }
}

#include "gen/data/Source/D2Client/UI/Hireables.inc"

// 0x00493220
static __forceinline void sub_00493220_ToggleAmount(int* pTotal, int* pAmount)
{
    if (*pAmount)
    {
        *pTotal -= *pAmount;
        *pAmount = 0;
    }
    else
    {
        *pAmount = 10;
        *pTotal += 10;
    }
}

// 0x004934B0
D2UnitStrc* __cdecl sub_004934B0_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return 0;
    return INVENTORY_GetCursorItem(pPlayer->pInventory);
}

void __fastcall sub_M110_Emit_00493220(int* pTotal, int* pAmount)
{
    sub_00493220_ToggleAmount(pTotal + 1, pAmount);
}

static __forceinline D2PetTypeTxt* sub_00493240_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x00493240
D2CelFileStrc* __fastcall sub_00493240_PetIconForType(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle)
{
    int aPath[0x40];

    D2PetTypeTxt* pPetTypeTxtRecord = sub_00493240_GetPetTypeTxtRecord(nPetType);
    if (!pPetTypeTxtRecord)
    {
        return 0;
    }

    if (pSingle)
    {
        *pSingle = pPetTypeTxtRecord->nPetFlags[5 >> 3] & gdwBitMasks[5 & 7];
    }

    int nUnitId = sub_00478F20_FindPetIdByOwner(pOwner, nPetType, 0);
    *pUnitId = nUnitId;
    if (nUnitId == -1)
    {
        return 0;
    }

    int nClassId = sub_00479120_GetHirelingClassId(nUnitId);
    int nIcon = 0;
    for (int i = 1; i < 5; ++i)
    {
        if (nClassId == pPetTypeTxtRecord->wClass[i] && pPetTypeTxtRecord->szIcon[i][0])
        {
            nIcon = i;
            break;
        }
    }

    int nSlot = nPetType * 5 + nIcon;
    void** ppCel = &gppHirelingCels_007BEEAC[nSlot];
    if (!*ppCel)
    {
        sprintf((char*)aPath, "hireables\\%s", pPetTypeTxtRecord->szIcon[nIcon]);
        ppCel = &gppHirelingCels_007BEEAC[nSlot];
        *ppCel = sub_004520C0_LoadUiCelFile((char*)aPath);
    }
    return (D2CelFileStrc*)*ppCel;
}

// 0x00493430
void __stdcall sub_00493430_PetIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnGlobal_007BEECC == 2)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nUnitId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
    if (nUnitId != -1)
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPet = sub_00463990(nUnitId, 1);
    if (!pPet)
    {
        pMsg->bReturn = 0;
        return;
    }

    sub_00467410_SetEntryValue(pPlayer, pPet, 1);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x004934D0
int __stdcall sub_004934D0_CheckBoxAction(int playSound)
{
 if(!sub_0044DCC0()) return 0;
 int result=0;
 D2UnitStrc* player=sub_00463DD0();
 if(!player) return 0;
 D2UnitStrc* current=sub_00463DD0();
 D2UnitStrc* item=current ? INVENTORY_GetCursorItem(current->pInventory):0;
 if(!item) return 0;
 int petId=sub_00478F20_FindPetIdByOwner(player,7,0);
 if(petId==-1) return 0;
 if(ITEMS_CheckItemFlag(item,16,955,".\\UI\\Hireables.cpp") && !ITEMS_CheckItemFlag(item,256,955,".\\UI\\Hireables.cpp")) {
  if(ITEMS_CheckItemTypeId(item,76) || ITEMS_CheckItemTypeId(item,80) || ITEMS_CheckItemTypeId(item,81)) {
   if(playSound) sub_004CBDE0_PlayEventSound(petId,1,84);
   return 1;
  }
  if(ITEMS_CheckItemTypeId(item,3) || ITEMS_CheckItemTypeId(item,37)) result=1;
  D2UnitStrc* pet=sub_00463990(petId,1);
  if(!pet) return 0;
  switch(sub_00479120_GetHirelingClassId(petId)) {
   case 271: if(ITEMS_CheckItemTypeId(item,27)) result=1; break;
   case 338: if(ITEMS_CheckItemTypeId(item,33) || ITEMS_CheckItemTypeId(item,34)) result=1; break;
   case 359:
    if(ITEMS_CheckItemTypeId(item,2)) result=1;
    if(ITEMS_CheckItemTypeId(item,30) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1;
    break;
   case 560: if(ITEMS_CheckItemTypeId(item,28) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1; break;
   case 561: if(ITEMS_CheckItemTypeId(item,30)) result=1; break;
  }
  if(!result) {
   if(playSound) sub_004CBDE0_PlayEventSound(petId,1,85);
  } else if(!ITEMS_CheckRequirements(item,pet,0,0,0,0)) result=0;
  return result;
 }
 if(playSound) sub_004CBDE0_PlayEventSound(petId,1,86);
 return 0;
}

struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBF0];
    int nPetTypeTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20
int __fastcall sub_00478F70(D2UnitStrc* pUnit);                                                             // 0x00478F70
int __fastcall sub_0047A2C0(D2UnitStrc* pUnit);                                                             // 0x0047A2C0
void __fastcall sub_00496BE0_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg); // 0x00496BE0
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine);          // 0x006470F0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern unsigned long gdwHelpMenu_00722310;                                                                  // 0x00722310
extern int gnUiRecordIndex_00722354;                                                                        // 0x00722354
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void** gppHirelingCels_007BEEAC;                                                                            // 0x007BEEAC
extern void* gapHirelingIcons_007BEEB0[7];                                                                  // 0x007BEEB0
extern int gnGlobal_007BEECC;                                                                               // 0x007BEECC
int gnGlobal_007BEEDC;                                                                                      // 0x007BEEDC
int gnGlobal_007BEEE0;                                                                                      // 0x007BEEE0
int gnGlobal_007BEEE8;                                                                                      // 0x007BEEE8
void* gpGlobal_007BEEEC;                                                                                    // 0x007BEEEC
void* gpGlobal_007BEEF0;                                                                                    // 0x007BEEF0
void* gpGlobal_007BEEF4;                                                                                    // 0x007BEEF4
void* gpCel_007BEF0C;                                                                                       // 0x007BEF0C
void* gpCel_007BEF10;                                                                                       // 0x007BEF10
void* gpCel_007BEF14;                                                                                       // 0x007BEF14
extern void* gpCel_007BEF18;                                                                                // 0x007BEF18
extern void* gpCel_007BEF1C;                                                                                // 0x007BEF1C
void* gpCel_007BEF20;                                                                                       // 0x007BEF20
void* gpCel_007BEF24;                                                                                       // 0x007BEF24
void* gpCel_007BEF28;                                                                                       // 0x007BEF28
void* gpCel_007BEF2C;                                                                                       // 0x007BEF2C
extern unsigned char gabGlobal_007BEF30[0x30];                                                              // 0x007BEF30
void* gpCel_007BEF60;                                                                                       // 0x007BEF60
void* gpCel_007BEF64;                                                                                       // 0x007BEF64
void* gpCel_007BEF68;                                                                                       // 0x007BEF68
void* gpCel_007BEF70;                                                                                       // 0x007BEF70
extern void* gpCel_007BEF74;                                                                                // 0x007BEF74
void* gpCel_007BEF78;                                                                                       // 0x007BEF78
void* gpCellFile_007BEF7C;                                                                                  // 0x007BEF7C
void* gpCel_007BEF80;                                                                                       // 0x007BEF80
extern int gbGlobal_007BEFA0;                                                                               // 0x007BEFA0
extern unsigned char gnTextColorA_007BEFBB;                                                                 // 0x007BEFBB
extern unsigned char gnTextColorB_007BEFE4;                                                                 // 0x007BEFE4

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

#define D2_FREE_PANEL_CEL(pCel) if (pCel) { sub_00478A00(pCel); pCel = 0; }

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

#include "gen/data/Source/D2Client/00492EC0_sub_00492EC0_FreeHirelingIcons.inc"

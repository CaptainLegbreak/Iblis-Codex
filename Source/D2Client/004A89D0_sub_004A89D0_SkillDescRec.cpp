struct D2UnitStrc;
struct D2SkillStrc;

struct D2SkillsTxt
{
    short nSkillId;
    unsigned short unk0x02;
    unsigned char nFlags[8];
    char unk0x0C[0x188];
    short wSkillDesc;
    char unk0x196[0xA6];
};

struct D2SkillDescTxt
{
    char unk0x00[0x120];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    char unk0xB90[0x4];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};

#pragma pack(push, 2)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};
#pragma pack(pop)

struct D2SkillIconStateStrc
{
    char unk0x000[0x2D0];
    int anValues[60];
    unsigned char bFlag;
    char unk0x3C1[0x4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                              // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
unsigned char gbGlobal_007A0522;                                                                            // 0x007A0522
extern D2UiCelFileStrc gaSkillIconCels_00724AC0[7];                                                         // 0x00724AC0
extern int gnGlobal_00724BEC;                                                                               // 0x00724BEC
extern D2UiCelFileStrc gaPanelCels_00724BF0[7];                                                             // 0x00724BF0
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
D2SkillIconStateStrc gtSkillIconState_007C0300;                                                             // 0x007C0300
extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
int ganIconValues_007C0728[16];                                                                             // 0x007C0728
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
unsigned short gawIconValues_007C07A8[8];                                                                   // 0x007C07A8
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8
void* gpSkillIconCel_007C07F8;                                                                              // 0x007C07F8
int gbGlobal_007C07FC;                                                                                      // 0x007C07FC
extern "C" int gnValue_007C0C3C;                                                                            // 0x007C0C3C
int gnGlobal_007C0C40;                                                                                      // 0x007C0C40
int gnGlobal_007C0C44;                                                                                      // 0x007C0C44
int gnGlobal_007C0C4C;                                                                                      // 0x007C0C4C
unsigned char gbColor_007C0C50;                                                                             // 0x007C0C50

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __stdcall sub_004A9D70(D2SkillsTxt* pSkillsTxt, int nQuantity);                                       // 0x004A9D70
void __fastcall sub_004AA3A0(D2UnitStrc* pUnit, int nX, int nArg3, int nArg4, int nArg5);                  // 0x004AA3A0
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage);                                     // 0x004AAAE0
void __cdecl sub_004AACE0();                                                                                // 0x004AACE0
void __stdcall sub_004AB310(int nValue);                                                                    // 0x004AB310
void __cdecl sub_004AB530_DrawTabCel();                                                                     // 0x004AB530
void __cdecl sub_004AB630();                                                                                // 0x004AB630
void __cdecl sub_004AC200();                                                                                // 0x004AC200
void __cdecl sub_004AC4D0();                                                                                // 0x004AC4D0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                     // 0x004D9FC0
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit);                                              // 0x00620150
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x006253B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId);                                                   // 0x00645040
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);                                                      // 0x006450F0

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004A89D0
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

// 0x004A8A30
void __cdecl sub_004A8A30_InitSkillIcons()
{
    gpSkillIconCel_007C07F8 = sub_004520C0_LoadUiCelFile("Spells\\Skillicon");
    gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels_00724AC0[gbGlobal_007A0522].szPath);

    int i;
    for (i = 0; i < 16; ++i)
    {
        ganIconValues_007C0728[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gnHotkeyOwner_007C0768[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gbHotkeyLeft_007C07B8[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gnHotkeySkill_007C06C8[i] = -1;
    }

    memset(&gtSkillIconState_007C0300, 0, 0x3C5);
    for (i = 0; i < 60; ++i)
    {
        gtSkillIconState_007C0300.anValues[i] = -1;
    }
    for (i = 0; i < 8; ++i)
    {
        gawIconValues_007C07A8[i] = 0;
    }
}

// 0x004A8C00
void __cdecl sub_004A8C00_FreeSkillIcons()
{
    if (gpSkillIconCel_007C07F8)
    {
        sub_00478A00(gpSkillIconCel_007C07F8);
        gpSkillIconCel_007C07F8 = 0;
    }

    if (gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile)
    {
        sub_00478A00(gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile);
        gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile = 0;
    }

    for (int i = 0; i < 7; ++i)
    {
        if (gaSkillIconCels_00724AC0[i].pCelFile)
        {
            sub_00478A00(gaSkillIconCels_00724AC0[i].pCelFile);
            gaSkillIconCels_00724AC0[i].pCelFile = 0;
        }
    }
}

// 0x004A8C80
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt)
{
    if (!pSkillsTxt)
    {
        return gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile;
    }

    int nClass = pSkillsTxt->nSkillId;
    nClass = SKILLS_GetClassIdFromSkillId(nClass);
    if (nClass >= 0 && nClass <= 6)
    {
        if (!gaSkillIconCels_00724AC0[nClass].pCelFile)
        {
            gaSkillIconCels_00724AC0[nClass].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels_00724AC0[nClass].szPath);
        }
        return gaSkillIconCels_00724AC0[nClass].pCelFile;
    }

    return gpSkillIconCel_007C07F8;
}

// 0x004A8CE0
void __fastcall sub_004A8CE0_SetValue(int nValue)
{
    gbGlobal_007C07FC = nValue;
}

// 0x004A8D30
int __fastcall sub_004A8D30_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    const int nState = sub_004D9FC0_GetSkillUseState(pUnit, pSkill);
    if (nState)
    {
        return nState == 6 ? 4 : 1;
    }
    return 0;
}

// 0x004A9A90
int __fastcall sub_004A9A90_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9AE0
int __fastcall sub_004A9AE0_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9B30
int __fastcall sub_004A9B30_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9B80
int __fastcall sub_004A9B80_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9DF0
void __cdecl sub_004A9DF0_UpdateSkillIcons()
{
    D2SkillStrc* pSkill = UNITS_GetStartSkill(sub_00463DD0());
    D2_ASSERT(pSkill, 1149);

    do
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 36))
        {
            sub_004A9D70(pSkillsTxt, SKILLS_GetQuantity(pSkill));
        }
        pSkill = SKILLS_GetNextSkill(pSkill);
    }
    while (pSkill);
}

// 0x004AA7E0
void __cdecl sub_004AA7E0_ResetSkillIcons()
{
    memset(&gtSkillIconState_007C0300, 0, 0x3C5);
    for (int i = 0; i < 60; ++i)
    {
        gtSkillIconState_007C0300.anValues[i] = -1;
    }

    if (gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0(sub_00463DD0(), 0x50, 1, 0, 0);
    }
    if (!gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0(sub_00463DD0(), gnGlobal_0071146C - 0x80, 0, 0, 0);
    }
    if (gbGlobal_007C07FC)
    {
        sub_004AA3A0(sub_00463DD0(), 0x50, 1, 1, 0);
    }
    if (!gbGlobal_007C07FC)
    {
        sub_004AA3A0(sub_00463DD0(), gnGlobal_0071146C - 0x80, 0, 1, 0);
    }
}

// 0x004AA900
int __cdecl sub_004AA900_IsStateOrValue()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer && STATES_CheckState(pPlayer, 0x36))
    {
        return 1;
    }
    return gnValue_007C0C3C;
}

// 0x004AA920
void __cdecl sub_004AA920_LoadPanelCel()
{
    char* szPath = gaPanelCels_00724BF0[gbGlobal_007A0522].szPath;
    D2_ASSERT(szPath, 136);
    gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile = sub_004520C0_LoadUiCelFile(szPath);
}

// 0x004AB2F0
void __cdecl sub_004AB2F0_SetBlackColor()
{
    gbColor_007C0C50 = D2Win_10034_MixRGB(0, 0, 0);
}

// 0x004AC690
void __cdecl sub_004AC690_DrawSkillPanel()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    sub_00502EF0(1);
    gnGlobal_007C0C4C = 1;
    sub_004AAAE0_DrawPagedPanel(gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile, gnGlobal_00724BEC);
    sub_004AACE0();
    if (STATLIST_GetUnitBaseStat(pPlayer, 5, 0) > 0)
    {
        gnGlobal_007C0C40 = 1;
        gnGlobal_007C0C44 = 1;
        sub_004AC200();
    }
    else
    {
        gnGlobal_007C0C40 = 0;
        gnGlobal_007C0C44 = 0;
        sub_004AC4D0();
    }
    sub_004AB530_DrawTabCel();
    sub_004AB630();
    sub_004AB310(gnGlobal_00724BEC);
}

#include "gen/data/Source/D2Client/004A89D0_sub_004A89D0_SkillDescRec.inc"

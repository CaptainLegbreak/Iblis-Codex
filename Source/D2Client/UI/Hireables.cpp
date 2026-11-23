#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2StormTypes.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"

#define D2_FREE_PANEL_CEL(pCel) if (pCel) { ARCHIVE_FreeClientCellFile(pCel); pCel = 0; }

struct D2PetTypeTxt;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny); // 0x00478F20

int __fastcall sub_00478F70_HasPets(D2UnitStrc* pUnit); // 0x00478F70

int __fastcall ROSTER_HasPartyMate(D2UnitStrc* pUnit); // 0x0047A2C0

void __fastcall WARDENCLIENT_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg); // 0x00496BE0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

extern int gnScreenWidth; // 0x0071146C

extern int gnScreenHeight; // 0x00711470

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


static int gnPetIconPopupState;                                                                               // 0x007BEECC

extern void* gpCel_007BEF18; // 0x007BEF18

extern void* gpCtrlPnl7Cel; // 0x007BEF1C

extern void* gp800CtrlPnl7Cel; // 0x007BEF74

extern int gbBeltRowsShown; // 0x007BEFA0

extern unsigned char gnTextColorA; // 0x007BEFBB

extern unsigned char gnTextColorB; // 0x007BEFE4

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

int __fastcall sub_00479120_GetHirelingClassId(int nUnitId); // 0x00479120

extern const unsigned int gdwBitMasks[]; // 0x006CE268

void** gpHirelingRecords; // 0x007BEEAC

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __fastcall VIEW_SetPetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue); // 0x00467410

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0

int __stdcall ITEMSIsA(D2UnitStrc*,int); // 0x00629BB0

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0

void __fastcall UNITSND_PlayEventSound(int,unsigned char,unsigned short); // 0x004CBDE0

int gnGlobal_007BEEDC; // 0x007BEEDC

static int gbPopupPending; // 0x007BEEE0

int gnGlobal_007BEEE8; // 0x007BEEE8

void* gpHelpBorderCel; // 0x007BEEEC

void* gpHelpWhiteBulletCel; // 0x007BEEF0

void* gpHelpYellowBulletCel; // 0x007BEEF4

void* gpRunButtonCel; // 0x007BEF0C

void* gpPopBeltCel; // 0x007BEF10

void* gpGemSocketCel; // 0x007BEF14

void* gpSkillPointsCel; // 0x007BEF20

void* gpInvWarnCel; // 0x007BEF24

void* gpHostilePicCel; // 0x007BEF28

void* gpMenuPanelCel; // 0x007BEF2C

void* gpDuroIconCel; // 0x007BEF60

void* gpInvCharCel; // 0x007BEF64

void* gpHlthManaCel; // 0x007BEF68

void* gpStateButtonCel; // 0x007BEF70

void* gpArrowCel; // 0x007BEF78

void* gpBtnCel; // 0x007BEF7C

void* gpOverlapCel; // 0x007BEF80

struct D2StoredUnitRecordStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90

short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit); // 0x00465400

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit);                                     // 0x00464A60

int __fastcall sub_00478EE0_CountPets(D2UnitStrc* pOwner, int nPetType);                                 // 0x00478EE0

int __fastcall ROSTER_GetPetLife(int nUnitId);                                                       // 0x00479080

D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry);              // 0x004795A0

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall ROSTER_GetClassId(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479BA0

unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                      // 0x00479BC0

int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);                              // 0x0047A0C0

int __fastcall ROSTER_GetPartyLife(int nUnitId);                                                     // 0x0047A150

D2CelFileStrc* __fastcall HIREABLES_GetPetIcon(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle); // 0x00493240

void __stdcall INV_DrawIconNumber(int nValue, int nX);                                                // 0x00493100

const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);                                         // 0x0046A530

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

extern D2CelFileStrc* gapHirelingIcons[7];                                                         // 0x007BEEB0

static unsigned char gnLifeColorHigh;                                                              // 0x007BEED0

static unsigned char gnLifeColorMid;                                                               // 0x007BEED1

static unsigned char gnLifeColorLow;                                                               // 0x007BEED2

static unsigned char gbLifeColorsInit;                                                             // 0x007BEED3

static int gnPopupX;                                                                               // 0x007BEED4

static int gnPopupY;                                                                               // 0x007BEED8

static int gbPopupShown;                                                                           // 0x007BEEDC

static unsigned char gbOpenMercInvPending;                                                                     // 0x007BEEE4

static int gdwPopupTick;                                                                           // 0x007BEEE8


struct D2HirelingIconRecordStrc
{
    int unk0x00[5];
};
extern D2HirelingIconRecordStrc* gpHirelingRecords_007BEEAC; // 0x007BEEAC
extern "C" size_t __cdecl strlen(const char* szString);

// 0x00492C20
void __cdecl HIREABLES_LoadHirelingIcons()
{
    char aszClassIcons[5][32] = {
        "Hireables\\AmazonIcon",
        "Hireables\\SorceressIcon",
        "Hireables\\BarbarianIcon",
        "Hireables\\PaladinIcon",
        "Hireables\\NecromancerIcon",
    };
    char aszExpansionIcons[7][32] = {
        "Hireables\\AssassinIcon",
        "Hireables\\DruidIcon",
    };
    memset(gapHirelingIcons, 0, sizeof(gapHirelingIcons));
    int nIcon = 0;
    for (int i = 0; i < 5; ++i, ++nIcon)
    {
        gapHirelingIcons[nIcon] = (D2CelFileStrc*)sub_004520C0_LoadUiCelFile(aszClassIcons[i]);
    }
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        for (int i = 0; i < 7; ++i, ++nIcon)
        {
            if (!strlen(aszExpansionIcons[i]))
            {
                break;
            }
            gapHirelingIcons[nIcon] = (D2CelFileStrc*)sub_004520C0_LoadUiCelFile(aszExpansionIcons[i]);
        }
    }
    const int nSize = sgptDataTables->nPetTypeTxtRecordCount * sizeof(D2HirelingIconRecordStrc);
    gpHirelingRecords_007BEEAC = (D2HirelingIconRecordStrc*)sub_0040B430(0, nSize, ".\\UI\\Hireables.cpp", 0x96, 0);
    memset(gpHirelingRecords_007BEEAC, 0, nSize);
}

// 0x00492EC0
void __cdecl HIREABLES_FreeHirelingIcons()
{
    for (int i = 0; i < 7; ++i)
    {
        if (gapHirelingIcons[i])
        {
            ARCHIVE_FreeClientCellFile(gapHirelingIcons[i]);
            gapHirelingIcons[i] = 0;
        }
    }
    if (gpHirelingRecords)
    {
        const int nCount = sgptDataTables->nPetTypeTxtRecordCount * 5;
        for (int i = 0; i < nCount; ++i)
        {
            void* pCel = gpHirelingRecords[i];
            if (pCel)
            {
                ARCHIVE_FreeClientCellFile(pCel);
            }
        }
        sub_0040B480(0, gpHirelingRecords, ".\\UI\\Hireables.cpp", 0xB7, 0);
        gpHirelingRecords = 0;
    }
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00492FA0
static void __stdcall HIREABLES_DrawFittedText(int nX, int nY, int nColor, Unicode* pText)
{
    const int nOldFont = D2Win_10127_SetFont(6);
    Unicode* pEnd = &pText[31];
    while (D2Win_10121_GetTextWidth(pText) > 0x42)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    nX += 0x16 - D2Win_10121_GetTextWidth(pText) / 2;
    if (nX < 0)
        nX = 0;
    D2Win_10117_DrawText(pText, nX, nY, nColor, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x00493020
static void __stdcall HIREABLES_DrawPetTypeName(int nX, int nY, int nPetType)
{
    D2PetTypeTxt* pPetTypeTxt = (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount) ? &sgptDataTables->pPetTypeTxt[nPetType] : 0;
    if (pPetTypeTxt && pPetTypeTxt->wStringId > 0 && pPetTypeTxt->wStringId != 0x1506)
    {
        Unicode wszName[32];
        sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(pPetTypeTxt->wStringId));
        HIREABLES_DrawFittedText(nX, nY, 0, wszName);
    }
}

// 0x004930A0
static void __stdcall HIREABLES_DrawRosterName(const char* szName, int nX, int nY)
{
    unsigned short wszName[32];
    for (int i = 0; i < 32; ++i)
    {
        wszName[i] = 0;
    }
    sub_00526320_ToUnicode((Unicode*)wszName, szName, 32);
    HIREABLES_DrawFittedText(nX, nY, 0, (Unicode*)wszName);
}

struct D2UnitStrc;

// 0x00493220
static inline void HIREABLES_ToggleAmount(int* pTotal, int* pAmount)
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

void __fastcall sub_M110_Emit_00493220(int* pTotal, int* pAmount)
{
    HIREABLES_ToggleAmount(pTotal + 1, pAmount);
}

static inline D2PetTypeTxt* sub_00493240_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

// 0x00493840
void __cdecl sub_00493840_TogglePopup()
{
    switch (gnPetIconPopupState)
    {
    case 0:
        if (!GAME_GetConnectionType())
        {
            gnPetIconPopupState = 2;
            gnGlobal_007BEEE8 = 0;
            UI_SetUIVar(0x23, 1, 0);
        }
        else
        {
            gnPetIconPopupState = 1;
            UI_SetUIVar(0x23, 0, 0);
        }
        break;

    case 1:
        if (!GAME_GetConnectionType())
        {
            gnPetIconPopupState = 0;
            UI_SetUIVar(0x23, 0, 0);
        }
        else
        {
            gnPetIconPopupState = 2;
            gnGlobal_007BEEE8 = 0;
            UI_SetUIVar(0x23, 1, 0);
        }
        break;

    default:
        gnPetIconPopupState = 0;
        UI_SetUIVar(0x23, 0, 0);
        break;
    }
}

// 0x00494320
void __cdecl HIREABLES_LoadHelpCels()
{
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (!gpHelpBorderCel)
        {
            gpHelpBorderCel = sub_004520C0_LoadUiCelFile("Menu\\800helpborder");
        }
        else
        {
            ARCHIVE_FreeClientCellFile(gpHelpBorderCel);
            gpHelpBorderCel = 0;
            gpHelpBorderCel = sub_004520C0_LoadUiCelFile("Menu\\800helpborder");
        }
    }
    else
    {
        if (!gpHelpBorderCel)
        {
            gpHelpBorderCel = sub_004520C0_LoadUiCelFile("Menu\\helpborder");
        }
        else
        {
            ARCHIVE_FreeClientCellFile(gpHelpBorderCel);
            gpHelpBorderCel = 0;
            gpHelpBorderCel = sub_004520C0_LoadUiCelFile("Menu\\helpborder");
        }
    }
    if (!gpHelpWhiteBulletCel)
    {
        gpHelpWhiteBulletCel = sub_004520C0_LoadUiCelFile("Menu\\helpwhitebullet");
    }
    if (!gpHelpYellowBulletCel)
    {
        gpHelpYellowBulletCel = sub_004520C0_LoadUiCelFile("Menu\\helpyellowbullet");
    }
}

// 0x00494EE0
void __cdecl HIREABLES_FreeHelpCels()
{
    if (gpHelpBorderCel)
    {
        ARCHIVE_FreeClientCellFile(gpHelpBorderCel);
        gpHelpBorderCel = 0;
    }
    if (gpHelpWhiteBulletCel)
    {
        ARCHIVE_FreeClientCellFile(gpHelpWhiteBulletCel);
        gpHelpWhiteBulletCel = 0;
    }
    if (gpHelpYellowBulletCel)
    {
        ARCHIVE_FreeClientCellFile(gpHelpYellowBulletCel);
        gpHelpYellowBulletCel = 0;
    }
}

// 0x00495030
void __cdecl sub_00495030_DrawKeyHelp()
{
    Unicode wszText[200];
    Unicode wszKey[30];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1051));
    if (CUNIT_GetHotkeyBinding(6, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(6, 1));
        sub_00526700(wszText, wszKey);
    }
    if (CUNIT_GetHotkeyBinding(6, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(6, 0));
        sub_00526700(wszText, wszKey);
    }
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    D2Win_10117_DrawText(wszText, gnScreenWidth - nWidth / 2 - 0x3A, gnScreenHeight - 0xC5, 0, 0);
}

// 0x00496990
void __cdecl HIREABLES_FreePanelCels()
{
    D2_FREE_PANEL_CEL(gpBtnCel);
    D2_FREE_PANEL_CEL(gpInvCharCel);
    D2_FREE_PANEL_CEL(gpArrowCel);
    D2_FREE_PANEL_CEL(gpInvWarnCel);
    D2_FREE_PANEL_CEL(gpDuroIconCel);
    D2_FREE_PANEL_CEL(gpGemSocketCel);
    D2_FREE_PANEL_CEL(gpPopBeltCel);
    D2_FREE_PANEL_CEL(gp800CtrlPnl7Cel);
    D2_FREE_PANEL_CEL(gpCel_007BEF18);
    D2_FREE_PANEL_CEL(gpCtrlPnl7Cel);
    D2_FREE_PANEL_CEL(gpHlthManaCel);
    D2_FREE_PANEL_CEL(gpOverlapCel);
    D2_FREE_PANEL_CEL(gpStateButtonCel);
    D2_FREE_PANEL_CEL(gpMenuPanelCel);
    D2_FREE_PANEL_CEL(gpSkillPointsCel);
    D2_FREE_PANEL_CEL(gpRunButtonCel);
    D2_FREE_PANEL_CEL(gpHostilePicCel);
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
}

// 0x004979E0
int __cdecl HIREABLES_AreBeltRowsShown()
{
    return gbBeltRowsShown != 0;
}

// 0x004979F0
int __cdecl HIREABLES_GetBeltRowCount()
{
// build: symbol ?gnUiRecordIndex@* 0x00722354
    switch (gnUiRecordIndex)
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

static void __stdcall sub_00493A00_DrawLifeBar(int nPetType, int nX, int nUnitId)
{
    int nLife = nPetType ? ROSTER_GetPetLife(nUnitId) : ROSTER_GetPartyLife(nUnitId);
    if (!nLife)
        return;

    nLife = nLife <= 0 ? 0 : nLife;
    const int nXEnd = nX + 0x2E;
    if (nLife >= 100)
        nLife = 100;
    const int nXFill = nX + nLife * 0x2E / 100;
    if (!gbLifeColorsInit)
    {
        gbLifeColorsInit = 1;
        gnLifeColorHigh = D2Win_10034_MixRGB(0, 0x80, 0);
        gnLifeColorMid = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
        gnLifeColorLow = D2Win_10034_MixRGB(0xFF, 0, 0);
    }
    unsigned char nColor = gnLifeColorHigh;
    if (nLife < 50)
        nColor = gnLifeColorMid;
    if (nLife < 25)
        nColor = gnLifeColorLow;
    D2GFX_DrawBox(nX, 0xE, nXFill, 0x13, nColor, 5);
    D2GFX_DrawBox(nXFill, 0xE, nXEnd, 0x13, 0, 5);
}

// 0x00497270
void __cdecl HIREABLES_InitTextColorA()
{
    gnTextColorA = D2Win_10034_MixRGB(0xF4, 0xC0, 0x4C);
}

// 0x00497290
void __cdecl HIREABLES_InitTextColorB()
{
    gnTextColorB = D2Win_10034_MixRGB(0, 0, 0xFF);
}

// 0x00493240
D2CelFileStrc* __fastcall HIREABLES_GetPetIcon(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle)
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
    void** ppCel = &gpHirelingRecords[nSlot];
    if (!*ppCel)
    {
        sprintf((char*)aPath, "hireables\\%s", pPetTypeTxtRecord->szIcon[nIcon]);
        ppCel = &gpHirelingRecords[nSlot];
        *ppCel = sub_004520C0_LoadUiCelFile((char*)aPath);
    }
    return (D2CelFileStrc*)*ppCel;
}

// 0x00493340
void __cdecl HIREABLES_UpdateHirelingPanel()
{
    if (gnPetIconPopupState == 2)
    {
        gnGlobal_007BEEE8 = 0;
        gbPopupPending = 0;
        gnGlobal_007BEEDC = 0;
        return;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int bHasPet = 0;
    if (sub_00478F70_HasPets(pPlayer))
    {
        bHasPet = 1;
    }
    if ((ROSTER_HasPartyMate(pPlayer) && gnPetIconPopupState != 1) || bHasPet)
    {
        const int nPetId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
        D2UnitStrc* pPet;
        if (nPetId == -1 || ((pPet = CUNIT_FindClientUnit(nPetId, 1)) != 0 && CUNIT_IsDeadOrDying(pPet)))
        {
            gnGlobal_007BEEDC = 0;
            gbPopupPending = 0;
            gnGlobal_007BEEE8 = 0;
        }
        if (!GAME_GetUIVarState(0x13))
        {
            UI_SetUIVar(0x13, 0, 0);
        }
    }
    else
    {
        gnGlobal_007BEEE8 = 0;
        gbPopupPending = 0;
        gnGlobal_007BEEDC = 0;
        if (GAME_GetUIVarState(0x13))
        {
            UI_SetUIVar(0x13, 1, 0);
        }
    }
}

// 0x00493430
void __stdcall HIREABLES_PetIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnPetIconPopupState == 2)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nUnitId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
    if (nUnitId != -1)
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPet = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pPet)
    {
        pMsg->bReturn = 0;
        return;
    }

    VIEW_SetPetEntryValue(pPlayer, pPet, 1);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004934B0
D2UnitStrc* __cdecl HIREABLES_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    return INVENTORY_GetCursorItem(pPlayer->pInventory);
}

// 0x004934D0
int __stdcall HIREABLES_CanEquipHirelingItem(int playSound)
{
 if(!GAME_IsExpansion()) return 0;
 int result=0;
 D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
 if(!player) return 0;
 D2UnitStrc* current=sub_00463DD0_GetPlayerUnit();
 D2UnitStrc* item=current ? INVENTORY_GetCursorItem(current->pInventory):0;
 if(!item) return 0;
 int petId=sub_00478F20_FindPetIdByOwner(player,7,0);
 if(petId==-1) return 0;
 if(ITEMS_CheckItemFlag(item,16,955,".\\UI\\Hireables.cpp") && !ITEMS_CheckItemFlag(item,256,955,".\\UI\\Hireables.cpp")) {
  if(ITEMSIsA(item,76) || ITEMSIsA(item,80) || ITEMSIsA(item,81)) {
   if(playSound) UNITSND_PlayEventSound(petId,1,84);
   return 1;
  }
  if(ITEMSIsA(item,3) || ITEMSIsA(item,37)) result=1;
  D2UnitStrc* pet=CUNIT_FindClientUnit(petId,1);
  if(!pet) return 0;
  switch(sub_00479120_GetHirelingClassId(petId)) {
   case 271: if(ITEMSIsA(item,27)) result=1; break;
   case 338: if(ITEMSIsA(item,33) || ITEMSIsA(item,34)) result=1; break;
   case 359:
    if(ITEMSIsA(item,2)) result=1;
    if(ITEMSIsA(item,30) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1;
    break;
   case 560: if(ITEMSIsA(item,28) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1; break;
   case 561: if(ITEMSIsA(item,30)) result=1; break;
  }
  if(!result) {
   if(playSound) UNITSND_PlayEventSound(petId,1,85);
  } else if(!ITEMS_CheckRequirements(item,pet,0,0,0,0)) result=0;
  return result;
 }
 if(playSound) UNITSND_PlayEventSound(petId,1,86);
 return 0;
}

// 0x00493B00
static void __stdcall HIREABLES_DrawUnitName(D2UnitStrc* pUnit, int nX, int nY)
{
    if (pUnit)
    {
        unsigned short wszName[32];
        memset(wszName, 0, sizeof(wszName));
        sub_00526790((Unicode*)wszName, CUNIT_GetUnitName(pUnit), 32);
        wszName[31] = 0;
        HIREABLES_DrawFittedText(nX, nY, 0, (Unicode*)wszName);
    }
}

// 0x004942D0
int __cdecl HIREABLES_GetHelpMenuSetting()
{
// build: symbol ?gdwHelpMenu@* 0x00722310
    if (gdwHelpMenu == 0xFFFFFFFF)
    {
        gdwHelpMenu = 0;
        SRegLoadValue("Diablo II", "Help Menu", 1, &gdwHelpMenu);
    }
    return gdwHelpMenu;
}

static int __stdcall sub_00493B50_DrawRosterIcons(int* pnY, int* pbAlternate, D2UnitStrc* pPlayer, int* pnX)
{
    int bDrawn = 0;
    const unsigned short nIndex = CUNIT_GetPlayerPartyId(pPlayer);
    const int nPlayerId = pPlayer ? pPlayer->dwUnitId : -1;
    if (nIndex == 0xFFFF || gnPetIconPopupState)
        return 0;

    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    if (!pEntry)
        return 0;

    do
    {
        if (ROSTER_GetEntryIndex(pEntry) != nIndex)
            continue;

        const int nUnitId = ROSTER_GetRecordUnitId(pEntry);
        if (nUnitId == nPlayerId)
            continue;

        D2CelFileStrc* pCelFile;
        switch (ROSTER_GetClassId(pEntry))
        {
        case 0:
            pCelFile = gapHirelingIcons[0];
            break;
        case 1:
            pCelFile = gapHirelingIcons[1];
            break;
        case 2:
            pCelFile = gapHirelingIcons[2];
            break;
        case 3:
            pCelFile = gapHirelingIcons[3];
            break;
        case 4:
            pCelFile = gapHirelingIcons[4];
            break;
        case 5:
            pCelFile = gapHirelingIcons[5];
            break;
        case 6:
            pCelFile = gapHirelingIcons[6];
            break;
        default:
            continue;
        }

        if (!pCelFile)
            continue;

        sub_00493A00_DrawLifeBar(0, *pnX, nUnitId);
        HIREABLES_DrawRosterName(ROSTER_GetEntryName(pEntry), *pnX, *pnY);
        if (*pbAlternate)
        {
            *pnY -= *pbAlternate;
            *pbAlternate = 0;
        }
        else
        {
            *pbAlternate = 10;
            *pnY += 10;
        }
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pCelFile;
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
        *pnX += 0x38;
        bDrawn = 1;
    }
    while ((pEntry = ROSTER_GetNextStoredUnit(pEntry)) != 0);

    if (!bDrawn)
        return 0;

    return 1;
}

static int __stdcall sub_00493CE0_DrawSummonIcon(D2UnitStrc* pPlayer, int* pbAlternate, int* pnX, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, 7, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(7, *pnX, nUnitId);
    HIREABLES_DrawUnitName(CUNIT_FindClientUnit(nUnitId, 1), *pnX, *pnY);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    gnPopupX = *pnX;
    gnPopupY = *pnY;
    if (gbPopupPending && gdwPopupTick && GetTickCount() - gdwPopupTick >= 700)
    {
        gbPopupShown = 1;
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 7, 0);
        *pnX += 0x38;
        return 1;
    }

    if (gbPopupShown)
    {
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 7, 0);
        *pnX += 0x38;
        return 1;
    }

    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493E10_DrawPetIcon(D2UnitStrc* pPlayer, int* pnX, int* pbAlternate, int nPetType, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, nPetType, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(nPetType, *pnX, nUnitId);
    HIREABLES_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493EB0_DrawPetCountIcon(D2UnitStrc* pPlayer, int* pnY, int* pbAlternate, int* pnX, int nPetType)
{
    const int nCount = sub_00478EE0_CountPets(pPlayer, nPetType);
    if (!nCount)
        return 0;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    int bSingle = 0;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, nPetType, &nUnitId, &bSingle);
    if (!tContext.pCellFile)
        return 0;

    if (nCount == 1 && bSingle)
        sub_00493A00_DrawLifeBar(nPetType, *pnX, sub_00478F20_FindPetIdByOwner(pPlayer, nPetType, 0));

    INV_DrawIconNumber(nCount, *pnX);
    HIREABLES_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493F80_DrawPetIcon3(D2UnitStrc* pPlayer, int* pnX, int* pbAlternate, int nPetType, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, nPetType, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(nPetType, *pnX, nUnitId);
    HIREABLES_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

void __cdecl sub_00494020_DrawPetIcons()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nY = 0x48;
    int bAlternate = 0;
    int nX = 0xF;
    const int nMode = sub_0045AE90();
    if (nMode != 3 && nMode != 2 && !GAME_GetUIVarState(9) && !GAME_GetUIVarState(0xB) && gnPetIconPopupState != 2)
    {
        if (GAME_IsExpansion() && !GAME_GetUIVarState(0x23) && gnPetIconPopupState != 2 && sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0) != -1)
            UI_SetUIVar(0x23, 0, 0);

        int bAny = sub_00493B50_DrawRosterIcons(&nY, &bAlternate, pPlayer, &nX);
        bAny |= sub_00493CE0_DrawSummonIcon(pPlayer, &bAlternate, &nX, &nY);
        for (int i = 0; i < sgptDataTables->nPetTypeTxtRecordCount; ++i)
        {
            D2PetTypeTxt* pPetTypeTxt = (i >= 0 && i < sgptDataTables->nPetTypeTxtRecordCount) ? &sgptDataTables->pPetTypeTxt[i] : 0;
            if (!pPetTypeTxt)
                continue;

            switch (pPetTypeTxt->nIconType)
            {
            case 1:
                bAny |= sub_00493E10_DrawPetIcon(pPlayer, &nX, &bAlternate, i, &nY);
                break;
            case 2:
                bAny |= sub_00493EB0_DrawPetCountIcon(pPlayer, &nY, &bAlternate, &nX, i);
                break;
            case 3:
                bAny |= sub_00493F80_DrawPetIcon3(pPlayer, &nX, &bAlternate, i, &nY);
                break;
            }
        }

        if (!bAny)
            UI_SetUIVar(0x13, 1, 0);

        if (gbOpenMercInvPending && !GAME_GetUIVarState(0x24) && UI_SetUIVar(0x24, 0, 0))
        {
            SRegSaveValue("Diablo II", "PopupHireling", 0, 1);
            gbOpenMercInvPending = 0;
        }

        if (gbPopupPending && gbPopupShown)
        {
            Unicode wszText[0x100];
            wszText[0].wChar = 0;
            const Unicode* wszSuffix = D2LANG_GetStringFromTblIndex(0x58A2);
            const Unicode* wszFormat = D2LANG_GetStringFromTblIndex(0x58A3);
            const Unicode* wszMiddle = D2LANG_GetStringFromTblIndex(0xF9E);
            sub_005269D0(0x100, wszText, wszFormat, CMDTBL_GetKeyName(0x36, 1));
            sub_00526700(wszText, wszMiddle);
            sub_00526700(wszText, wszSuffix);
            D2Win_10129_DrawFramedText(wszText, gnPopupX, gnPopupY + 0x24, 0, 0);
        }
    }
    else
    {
        gbPopupShown = 0;
        gbPopupPending = 0;
    }
}

#include "gen/data/Source/D2Client/UI/Hireables.inc"

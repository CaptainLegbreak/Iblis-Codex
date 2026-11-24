#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2ClientGfx.h"
#include "D2StatIds.h"

struct D2SkillStrc;

struct D2UnitStrc;

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_PASSIVE = 4,
    SKILLSFLAGINDEX_LEFTSKILL = 30,
    SKILLSFLAGINDEX2_SCROLL = 4,
};

#pragma pack(push, 1)

struct D2SpellSelSlotsStrc
{
    int nX[60];
    int nY[60];
    int nSkill[60];
    int f_2D0[60];
    unsigned char nCount;
    int nState;
};

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304

extern D2SpellSelSlotsStrc gtHotkeySlots_007C0300;                                                           // 0x007C0300

int gaSkillRowY[4];                                                                                 // 0x007C070C

extern unsigned int gdwBitMasks_006CE268[];                                                                  // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

void __fastcall sub_004A9870_DrawSkillSlot(D2SkillsTxt* pSkillsTxt, int nOwner, int nCharges, int nState, int nX, int nY, int bLeft); // 0x004A9870

void __fastcall TEXT_UpdateSkillButtonHover(D2SkillsTxt* pSkillsTxt, int nState, int nLevel, int nCharges, int nX, int nY); // 0x004A8D50

void __fastcall sub_004AA1F0_DrawSkillQuantity(D2SkillsTxt* pSkillsTxt, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HotkeySlotTableStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0


extern int gbSkillSelectRight; // 0x007C07FC

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2SkillDescTxt* CLIENT_GetSkillDescTxtRecord(int nSkillId)
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

struct D2UiCelFileStrc;

#pragma pack(push, 2)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};
#pragma pack(pop)

extern D2UiCelFileStrc gaSkillIconCels[7]; // 0x00724AC0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

unsigned char gnCharClass; // 0x007A0522

void* gpSkillIconCel; // 0x007C07F8

// 0x004A8C00
void __cdecl sub_004A8C00_FreeSkillIcons()
{
    if (gpSkillIconCel)
    {
        ARCHIVE_FreeClientCellFile(gpSkillIconCel);
        gpSkillIconCel = 0;
    }

    if (gaSkillIconCels[gnCharClass].pCelFile)
    {
        ARCHIVE_FreeClientCellFile(gaSkillIconCels[gnCharClass].pCelFile);
        gaSkillIconCels[gnCharClass].pCelFile = 0;
    }

    for (int i = 0; i < 7; ++i)
    {
        if (gaSkillIconCels[i].pCelFile)
        {
            ARCHIVE_FreeClientCellFile(gaSkillIconCels[i].pCelFile);
            gaSkillIconCels[i].pCelFile = 0;
        }
    }
}

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0

int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040

// 0x004A8C80
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt)
{
    if (!pSkillsTxt)
    {
        return gaSkillIconCels[gnCharClass].pCelFile;
    }

    int nClass = pSkillsTxt->nSkillId;
    nClass = SKILLS_GetClassIdFromSkillId(nClass);
    if (nClass >= 0 && nClass <= 6)
    {
        if (!gaSkillIconCels[nClass].pCelFile)
        {
            gaSkillIconCels[nClass].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels[nClass].szPath);
        }
        return gaSkillIconCels[nClass].pCelFile;
    }

    return gpSkillIconCel;
}

// 0x004A8CE0
void __fastcall sub_004A8CE0_SetValue(int nValue)
{
    gbSkillSelectRight = nValue;
}

// 0x004A8D30
int __fastcall sub_004A8D30_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    const int nState = sub_004D9FC0(pUnit, pSkill);
    if (nState)
    {
        return nState == 6 ? 4 : 1;
    }
    return 0;
}

struct D2TextNodeStrc;

struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};

struct D2TextNodeStrc
{
    void* pOwned[6];
    unsigned char unk0x18[10];
    unsigned char pNext[4];
};

void __fastcall sub_004EF990_SetSkillPopUpText(D2UnitStrc* pUnit, int nId, int nA, int nB, int nState, int nX, int nY); // 0x004EF990

// 0x004A8D50
void __fastcall TEXT_UpdateSkillButtonHover(short* pId, int nState, int nA, int nB, int nX, int nY)
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
    {
        nState = nState == 1;
    }
    else
    {
        nState = 1;
    }

    nMouseX = sub_00468730();
    nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
    {
        sub_004EF990_SetSkillPopUpText(sub_00463DD0_GetPlayerUnit(), *pId, nA, nB, nState, nX, nY);
    }
}

// 0x004A9A00
static int __stdcall SPELLSEL_AddSkillSlot(int nX, int bLeft, int nY, D2SkillStrc* pSkill, int nState)
{
    gtHotkeySlots_007C0300.nX[gtHotkeySlots_007C0300.nCount] = nX;
    gtHotkeySlots_007C0300.nY[gtHotkeySlots_007C0300.nCount] = nY;
    gtHotkeySlots_007C0300.nSkill[gtHotkeySlots_007C0300.nCount] = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\spellsel.cpp", 0x23D);
    SKILLS_GetSkillInfo(pSkill, &gtHotkeySlots_007C0300.f_2D0[gtHotkeySlots_007C0300.nCount], 0, 0, 0);
    gtHotkeySlots_007C0300.nState = nState;
    ++gtHotkeySlots_007C0300.nCount;
    if (!bLeft)
        nX -= 0x30;
    else
        nX += 0x30;
    return nX;
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
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9BD0
void __stdcall SPELLSEL_SkillSelectClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 954);

    const int nStartY = sub_00468740();
    int bHandled = 0;
    for (int i = 0; i < 60; ++i)
    {
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(sub_00463DD0_GetPlayerUnit(), gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
            if (pSkill)
            {
                int nCharges;
                if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1 && SKILLS_GetSkillInfo(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
                {
                    if (GAME_GetUIVarState(3))
                    {
                        UI_SetUIVar(3, 1, 0);
                    }

                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }

                MSG_SendTwoDwords(0x3C, (gbSkillSelectRight ? 0x80000000 : 0) + gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
                UI_SetUIVar(3, 1, 0);
                gbSkillSelectRight = 0;
                bHandled = 1;
                GAME_ResetMouseState();
            }
        }
    }

    if (nStartY <= gnScreenHeight - 49 && !bHandled && GAME_GetUIVarState(3))
    {
        UI_SetUIVar(3, 1, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

extern int gaHotkeySkills[16]; // 0x007C06C8

extern int gaHotkeyOwners[16]; // 0x007C0768

extern int gaHotkeyLeft[16]; // 0x007C07B8

extern int gaChargedSkillIds[60]; // 0x007C04E0

// 0x004A9D70
void __stdcall sub_004A9D70_ClearSkillHotkeys(D2SkillsTxt* pSkillsTxt, int nQuantity)
{
    int i = 0;
    while (i < 60)
    {
        if (gaChargedSkillIds[i] != pSkillsTxt->nSkillId)
        {
            ++i;
            continue;
        }

        for (int nSlot = 0; nSlot < 16; ++nSlot)
        {
            if (gaHotkeySkills[nSlot] == gaChargedSkillIds[i] && nQuantity <= 0)
            {
                gaHotkeySkills[nSlot] = -1;
                gaHotkeyLeft[nSlot] = -1;
                gaHotkeyOwners[nSlot] = -1;
                MSG_SendTwoDwords(0x51, (nSlot << 16) + 0xFFFF, -1);
            }
        }

        ++i;
    }
}


#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

extern unsigned int gdwBitMasks[]; // 0x006CE268

// 0x004A9DF0
void __cdecl sub_004A9DF0_UpdateSkillIcons()
{
    D2SkillStrc* pSkill = UNITS_GetStartSkill(sub_00463DD0_GetPlayerUnit());
    D2_ASSERT(pSkill, 1149);

    do
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 36))
        {
            sub_004A9D70_ClearSkillHotkeys(pSkillsTxt, SKILLS_GetQuantity(pSkill));
        }
        pSkill = SKILLS_GetNextSkill(pSkill);
    }
    while (pSkill);
}

// 0x004A9E60
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey)
{
    for (int i = 0; i < 60; ++i)
    {
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            if (gaHotkeySkills[nHotkey] != -1)
            {
                MSG_SendTwoDwords(0x51, (nHotkey << 16) + 0xFFFF, -1);
            }

            gaHotkeySkills[nHotkey] = gtHotkeySlots_007C0300.nSkill[i];
            if (!gbSkillSelectRight)
            {
                gaHotkeyLeft[nHotkey] = 0;
            }
            else
            {
                gaHotkeyLeft[nHotkey] = 1;
            }
            gaHotkeyOwners[nHotkey] = gtHotkeySlots_007C0300.f_2D0[i];
            MSG_SendTwoDwords(0x51, (nHotkey << 16) + (gaHotkeyLeft[nHotkey] ? 0x8000 : 0) + gaHotkeySkills[nHotkey], gaHotkeyOwners[nHotkey]);

            for (int j = 0; j < 16; ++j)
            {
                if (gaHotkeySkills[nHotkey] == gaHotkeySkills[j] && gaHotkeyOwners[nHotkey] == gaHotkeyOwners[j] && nHotkey != j)
                {
                    gaHotkeySkills[j] = -1;
                    gaHotkeyLeft[j] = -1;
                    gaHotkeyOwners[j] = -1;
                    MSG_SendTwoDwords(0x51, (j << 16) + 0xFFFF, -1);
                }
            }
        }
    }
}


void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

int gnSelectedHotkey; // 0x007C0708

// 0x004A9FC0
static int sub_004A9FC0_IsHotkeyUsable(int nSlot)
{
    if (gaHotkeySkills[nSlot] == -1)
        return 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    if (!pSkill)
        return 0;
    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        int nCharges;
        if (SKILLS_GetSkillInfo(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
            return 0;
    }
    return 1;
}

// 0x004AA030
void __fastcall sub_004AA030_SelectHotkey(int nSlot)
{
    if (gaHotkeySkills[nSlot] == -1)
        return;
    if (!sub_004A9FC0_IsHotkeyUsable(nSlot))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    gnSelectedHotkey = nSlot;
    MSG_SendTwoDwords(0x3C, (gaHotkeyLeft[nSlot] ? 0x80000000 : 0) + gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    if (gaHotkeyLeft[nSlot])
        SKILLS_SetLeftActiveSkill(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    else
        SKILLS_SetRightActiveSkill(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
}

struct D2ClientServiceStrc;

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

struct D2RareAffixTxt
{
    char unk0x00[0x0C];
    unsigned short wStringId;
    char unk0x0E[0x18];
    char szName[0x20];
};

// 0x004AA0C0
void __fastcall INV_SetHotkeySkillSlot(int nSlot, int nValueA, int nValueB, int nValueC)
{
    gaHotkeySkills[nSlot] = nValueA;
    gaHotkeyLeft[nSlot] = nValueB;
    gaHotkeyOwners[nSlot] = nValueC;
}

struct Unicode;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

unsigned short __fastcall sub_004E6CE0_GetStringId(int nId, int nIndex); // 0x004E6CE0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

static inline int IsMouseInSquare(int nX, int nY)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    return nMouseX >= nX && nMouseX <= nX + 0x30 && nMouseY >= nY - 0x30 && nMouseY <= nY;
}

// 0x004AA0F0
static void sub_004AA0F0_AssignFreeHotkey(int nSlot, int nIndex)
{
    if (nSlot >= 16)
        return;
    if (gaHotkeySkills[nSlot] != -1)
        return;

    gaHotkeySkills[nSlot] = gtHotkeySlots_007C0300.nSkill[nIndex];
    if (!gbSkillSelectRight)
        gaHotkeyLeft[nSlot] = 0;
    else
        gaHotkeyLeft[nSlot] = 1;
    gaHotkeyOwners[nSlot] = gtHotkeySlots_007C0300.f_2D0[nIndex];
    MSG_SendTwoDwords(0x51, (nSlot << 16) + (gaHotkeyLeft[nSlot] ? 0x8000 : 0) + gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
}

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

// 0x004AA160
void __cdecl sub_004AA160_FillHotkeys()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(UNITS_GetStartSkill(pPlayer), 0x524);
    int nSlot = 0;
    for (int i = 0; i < 60; ++i)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, gtHotkeySlots_007C0300.nSkill[i]);
        if (!pSkill)
            continue;
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (!pSkillsTxt)
            continue;
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 4))
            continue;
        if (nSlot > 15)
            continue;
        sub_004AA0F0_AssignFreeHotkey(nSlot, i);
        ++nSlot;
    }
}

// 0x004AA1F0
void __fastcall sub_004AA1F0_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY)
{
    if (IsMouseInSquare(nX, nY))
    {
        if (nState != 1)
        {
            nState = 0;
        }
    }
    else
    {
        nState = 1;
    }

    if (!IsMouseInSquare(nX, nY))
    {
        return;
    }

    const Unicode* wszNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    Unicode wszText[0x100];
    const unsigned short nNameId = sub_004E6CE0_GetStringId(*pId, 0);
    const int nTextId = sub_004E6CE0_GetStringId(*pId, 1);
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nTextId));
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105C));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    Unicode wszNumber[10];
    char szNumber[12];
// build: symbol ?gszFormatI@* 0x006D6454
    wsprintfA(szNumber, gszFormatI, nQuantity);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nNameId));
    D2Win_10129_DrawFramedText(wszText, nX, nY - 0x32, nState, 1);
}

// 0x004AA3A0
void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw)
{
    int nY = gnScreenHeight - 0x56;
    int nMaxRow = 0;
    const int nStepX = bLeft ? 0x30 : -0x30;
    unsigned char abPoolUsed[0x100];
    memset(abPoolUsed, 0, sizeof(abPoolUsed));
    for (int nRow = 0; nRow < 5; ++nRow)
    {
        int nX = nStartX;
        D2SkillStrc* pNext;
        for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = pNext)
        {
            pNext = SKILLS_GetNextSkill(pSkill);
            D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
            if (!pSkillsTxt)
                continue;
            D2SkillDescTxt* pSkillDescTxt = CLIENT_GetSkillDescTxtRecord(pSkillsTxt->nSkillId);
            if (!pSkillDescTxt)
                continue;
            if (bLeft && !(pSkillsTxt->nFlags[SKILLSFLAGINDEX_LEFTSKILL >> 3] & gdwBitMasks_006CE268[SKILLSFLAGINDEX_LEFTSKILL & 7]))
                continue;
            if (pSkillsTxt->nFlags[SKILLSFLAGINDEX_PASSIVE >> 3] & gdwBitMasks_006CE268[SKILLSFLAGINDEX_PASSIVE & 7])
                continue;
            if (SKILLS_GetFlags(pSkill) & 8)
                continue;
            int nOwner = -1;
            int nCharges = 0;
            int nQuantity = 0;
            int bItem = SKILLS_GetSkillInfo(pSkill, &nOwner, 0, 0, &nCharges);
            if (!bLeft && !bItem)
            {
                nQuantity = SKILLS_GetQuantity(pSkill);
                if (nQuantity > 0 && (pSkillsTxt->nFlags[4 + (SKILLSFLAGINDEX2_SCROLL >> 3)] & gdwBitMasks_006CE268[SKILLSFLAGINDEX2_SCROLL & 7]))
                    bItem = 1;
            }
            if (nRow < 4)
            {
                if (bItem)
                    continue;
                if (nRow != (char)pSkillDescTxt->nListRow)
                    continue;
            }
            else if (!bItem)
                continue;
            int nState;
            const int nUse = sub_004D9FC0(pUnit, pSkill);
            if (nUse)
                nState = nUse == 6 ? 4 : 1;
            else
                nState = 0;
            if (nMaxRow < nRow)
            {
                nY -= 0x30;
                nMaxRow = nRow;
            }
            if (pSkillDescTxt->nListPool > 0 && pSkillDescTxt->nListPool < 0x100)
            {
                if (abPoolUsed[pSkillDescTxt->nListPool] > 0)
                    continue;
                abPoolUsed[pSkillDescTxt->nListPool] = 1;
            }
            if (!bNoSlots)
            {
                if (!bNoDraw)
                    sub_004A9870_DrawSkillSlot(pSkillsTxt, nOwner, nCharges, nState, nX, nY, bLeft);
                nX = SPELLSEL_AddSkillSlot(nX, bLeft, nY, pSkill, nState);
            }
            else
            {
                if (!nQuantity)
                    TEXT_UpdateSkillButtonHover(pSkillsTxt, nState, SKILLS_GetSkillLevel(pUnit, pSkill, 1), nCharges, nX, nY);
                else
                    sub_004AA1F0_DrawSkillQuantity(pSkillsTxt, nState, nQuantity, nX, nY);
                nX += nStepX;
            }
            switch (nRow)
            {
            case 1:
                gaSkillRowY[0] = nY;
                break;
            case 2:
                gaSkillRowY[1] = nY;
                break;
            case 3:
                gaSkillRowY[2] = nY;
                break;
            case 4:
                gaSkillRowY[3] = nY;
                break;
            }
        }
    }
}

struct D2SkillIconStateStrc;

extern D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300

// 0x004AA680
void __cdecl sub_004AA680_BuildRightRows()
{
    if (gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
}

extern int gnScreenWidth; // 0x0071146C

// 0x004AA6B0
void __fastcall sub_004AA6B0_BuildLeftRows(int bNoDraw)
{
    if (!gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 0, bNoDraw);
    }
}

// 0x004AA6E0
void __cdecl sub_004AA6E0_BuildRightRows2()
{
    if (gbSkillSelectRight)
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
}

// 0x004AA710
void __cdecl sub_004AA710_BuildLeftRows2()
{
    if (!gbSkillSelectRight)
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 1, 0);
}

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

// 0x004AA740
void __fastcall sub_004AA740_CycleHotkey(int nDelta)
{
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    const int nStep = (nDelta > 0) * 2 - 1;
    if (nDelta < 0)
        nDelta = -nDelta;
    if (!nDelta)
        return;
    int nFound = -1;
    int nSlot = gnSelectedHotkey + nStep;
    for (int i = 0; i < 16; ++i, nSlot += nStep)
    {
        if (nSlot < 0)
            nSlot = 15;
        else if (nSlot >= 16)
            nSlot = 0;
        if (gaHotkeySkills[nSlot] != -1 && !gaHotkeyLeft[nSlot] && sub_004A9FC0_IsHotkeyUsable(nSlot))
        {
            nFound = nSlot;
            if (!--nDelta)
                break;
        }
    }
    if (nFound != -1)
        sub_004AA030_SelectHotkey(nFound);
}

// 0x004AA7E0
void __cdecl sub_004AA7E0_ResetSkillIcons()
{
    memset(&gtHotkeySlots, 0, 0x3C5);
    for (int i = 0; i < 60; ++i)
    {
        gtHotkeySlots.anValues[i] = -1;
    }

    if (gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
    if (!gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 0, 0);
    }
    if (gbSkillSelectRight)
    {
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
    }
    if (!gbSkillSelectRight)
    {
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 1, 0);
    }
}

// 0x004AA8B0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        const int nValue = sgptDataTables->pSkillsTxt[nSkillId].nMaxLevel;
        if (nValue > 0)
            return nValue;
    }
    return 20;
}

extern "C" int gbSkillPointsHighlight; // 0x007C0C3C

// 0x004AA8E0
void __cdecl sub_004AA8E0_ClearValue7C0C3C()
{
    gbSkillPointsHighlight = 0;
}

// 0x004AA8F0
extern "C" void __cdecl INV_ClearSkillPointsHighlight()
{
    gbSkillPointsHighlight = 0;
}

#include "gen/data/Source/D2Client/UI/spellsel.inc"

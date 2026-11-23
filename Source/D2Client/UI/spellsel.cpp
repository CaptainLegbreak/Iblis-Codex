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

extern int gnScreenHeight;                                                                                // 0x00711470

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

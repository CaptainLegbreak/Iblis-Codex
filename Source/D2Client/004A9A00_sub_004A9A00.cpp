enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_PASSIVE = 4,
    SKILLSFLAGINDEX_LEFTSKILL = 30,
    SKILLSFLAGINDEX2_SCROLL = 4,
};

struct D2UnitStrc;
struct D2SkillStrc;

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

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x2];
    unsigned char nFlags[8];
    char unk0x00C[0x188];
    short wSkillDesc;
    char unk0x196[0x23C - 0x196];
};

struct D2SkillDescTxt
{
    char unk0x00[0x05];
    char nListRow;
    unsigned char nListPool;
    char unk0x07[0x120 - 0x07];
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

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern D2SpellSelSlotsStrc gtHotkeySlots_007C0300;                                                           // 0x007C0300
int gnSkillRowY_007C070C[4];                                                                                 // 0x007C070C
extern int gnGlobal_00711470;                                                                                // 0x00711470
extern unsigned int gdwBitMasks_006CE268[];                                                                  // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit);                                              // 0x00620150
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);                                                      // 0x006450F0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                       // 0x004D9FC0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
void __fastcall sub_004A9870_DrawSkillSlot(D2SkillsTxt* pSkillsTxt, int nOwner, int nCharges, int nState, int nX, int nY, int bLeft); // 0x004A9870
void __fastcall sub_004A8D50_UpdateButton(D2SkillsTxt* pSkillsTxt, int nState, int nLevel, int nCharges, int nX, int nY); // 0x004A8D50
void __fastcall sub_004AA1F0_DrawSkillQuantity(D2SkillsTxt* pSkillsTxt, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0

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
static int __stdcall sub_004A9A00(int nX, int bLeft, int nY, D2SkillStrc* pSkill, int nState)
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

// 0x004AA3A0
void __fastcall sub_004AA3A0_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw)
{
    int nY = gnGlobal_00711470 - 0x56;
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
            D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
                if (nRow != pSkillDescTxt->nListRow)
                    continue;
            }
            else if (!bItem)
                continue;
            int nState;
            const int nUse = sub_004D9FC0_GetSkillUseState(pUnit, pSkill);
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
                nX = sub_004A9A00(nX, bLeft, nY, pSkill, nState);
            }
            else
            {
                if (!nQuantity)
                    sub_004A8D50_UpdateButton(pSkillsTxt, nState, SKILLS_GetSkillLevel(pUnit, pSkill, 1), nCharges, nX, nY);
                else
                    sub_004AA1F0_DrawSkillQuantity(pSkillsTxt, nState, nQuantity, nX, nY);
                nX += nStepX;
            }
            switch (nRow)
            {
            case 1:
                gnSkillRowY_007C070C[0] = nY;
                break;
            case 2:
                gnSkillRowY_007C070C[1] = nY;
                break;
            case 3:
                gnSkillRowY_007C070C[2] = nY;
                break;
            case 4:
                gnSkillRowY_007C070C[3] = nY;
                break;
            }
        }
    }
}

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;
typedef unsigned short Unicode;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x18];
    unsigned int dwFrameCountPrecise;
};

struct D2SkillsTxt
{
    char unk0x000[0x194];
    short wSkillDesc;
    char unk0x196[0xA6];
};

struct D2SkillDescTxt
{
    char unk0x00[0x0E];
    unsigned short wStrAlt;
    char unk0x10[0x110];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    void* pSkillDescLinker;
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                             // 0x00649180
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __fastcall sub_004BA840(void* pUnitSfx);                                                               // 0x004BA840
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

// 0x004C9320
int __fastcall sub_004C9320_SkillCltDoCollide(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill || !pDynamicPath)
        return 0;

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    const int bPlayer = nUnitType == 0;
    const int nMask = bPlayer ? 0x80 : 0x100;
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    const int nFlags = SKILLS_GetFlags(pSkill);
    if ((nFlags & 3) == 3)
    {
        COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nMask);
        PATH_SetFootprintCollisionMask(pDynamicPath, nMask);
        PATH_SetMoveTestCollisionMask(pDynamicPath, bPlayer ? 0x1C09 : 0x3C01);
        SKILLS_SetFlags(pSkill, 0);
        sub_004BA840(sub_004CA900_FindUnitSfxInRange(pUnit, 0x9E3));
    }
    else if (nFlags & 1)
    {
        UNITS_SetAnimationFrame(pUnit, 3);
        pUnit->dwFrameCountPrecise = 0x500;
    }
    return 1;
}

// 0x004E6E30
static unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    if (pSkillsTxtRecord)
    {
        const int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        pSkillDescTxtRecord = (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount) ? &sgptDataTables->pSkillDescTxt[nSkillDesc] : 0;
    }

    if (!pSkillDescTxtRecord)
        return 0x1506;

    return pSkillDescTxtRecord->wStrAlt;
}

void __fastcall sub_J15_Emit_004E6E30(Unicode* pBuffer, D2SkillStrc* pSkill)
{
    sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(sub_004E6E30_GetSkillDescAltStr(SKILLS_GetSkillIdFromSkill(pSkill, 0, 0x700))));
}

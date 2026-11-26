#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2CommonApi.h"

struct D2SkillsTxt;
struct D2SkillDescTxt;
union D2SeedStrc;

typedef unsigned short Unicode;






extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
void __fastcall sub_004BA840_StopSound(void* pUnitSfx); // 0x004BA840
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

typedef char D2SkillsTxt_size_check[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

extern const int gaMissileAroundOffsetY[8]; // 0x006DAE88
extern const int gaMissileAroundOffsetX[8]; // 0x006DAEA8
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

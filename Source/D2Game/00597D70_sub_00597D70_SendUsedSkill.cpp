struct D2ClientStrc;
struct D2SkillStrc;
struct D2DynamicPathStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
};

void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall sub_0053D530(D2ClientStrc* pClient, unsigned char a2, int a3, int nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D530
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient);                             // 0x005387F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

static __declspec(noinline) void __stdcall sub_00597D70_SendUsedSkill(D2UnitStrc* pMonster, D2UnitStrc* pTarget, D2ClientStrc* pClient);

// 0x00597D70
static void __stdcall sub_00597D70_SendUsedSkill(D2UnitStrc* pMonster, D2UnitStrc* pTarget, D2ClientStrc* pClient)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pMonster);
    if (!pSkill)
    {
        return;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\MONSTER\\MonsterMsg.cpp", 150);
    const char nSkillLevel = SKILLS_GetSkillLevel(pMonster, pSkill, 1);
    const int nUnitGUID = !pMonster ? -1 : pMonster->dwUnitId;

    if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
    {
        sub_0053D530(pClient, 1, nUnitGUID, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId, nSkillId, 0, nSkillLevel, 0);
    }
    else
    {
        sub_6FC3F060(pClient, 1, nUnitGUID, D2COMMON_10175_PathGetFirstPointX(pMonster->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMonster->pDynamicPath), (unsigned short)nSkillId, 0, nSkillLevel, 0);
    }
}

void __fastcall sub_00597D70_EmitCaller(D2GameStrc* pGame, D2UnitStrc* pMonster, D2ClientStrc* pClient)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pMonster);
    if (pTarget && !CLIENTS_IsInUnitsRoom(pTarget, pClient))
    {
        pTarget = 0;
    }

    if (pMonster->dwAnimMode == 17 || UNITS_GetUsedSkill(pMonster))
    {
        sub_00597D70_SendUsedSkill(pMonster, pTarget, pClient);
        return;
    }

    sub_0053D530(pClient, 1, pMonster->dwUnitId, pTarget->dwUnitType, pTarget->dwUnitId, pMonster->dwAnimMode, 0, 0, 0);
}

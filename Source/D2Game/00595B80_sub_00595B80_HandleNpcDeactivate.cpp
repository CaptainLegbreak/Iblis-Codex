struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; };
struct D2QuestArgStrc { D2GameStrc* pGame; int nEvent; D2UnitStrc* pTarget; };
struct D2Act1Quest6Strc { char unk_000[0x195]; unsigned char bCainActivated; };
struct D2QuestDataStrc { char unk_00[0x14]; unsigned int dwFlags; D2Act1Quest6Strc* pQuestDataEx; char unk_1C[0x8C]; void* pfNpcDeactivate; };
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc*, D2UnitStrc*, void*); // 0x00595B20
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*, int, D2UnitStrc*, int (__fastcall*)(D2GameStrc*, D2UnitStrc*, void*), bool); // 0x00544300

// 0x00595B80
void __fastcall sub_00595B80_HandleNpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 265)
    {
        D2Act1Quest6Strc* pQuestDataEx = pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainActivated == 1)
        {
            *(unsigned char*)&pQuestData->dwFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q6_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->bCainActivated = 0;
            pQuestData->pfNpcDeactivate = 0;
        }
    }
}

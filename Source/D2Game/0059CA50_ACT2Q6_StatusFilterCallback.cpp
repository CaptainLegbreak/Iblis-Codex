struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2Act2Quest6Strc { char unk00[0x10]; unsigned char bStatusOverride; char unk11[3]; unsigned char nStatus; };
struct D2QuestDataStrc { char unk00[9]; unsigned char bNotIntro; unsigned char bActive; unsigned char fLastState; unsigned char fState; char unk0D[0xB]; D2Act2Quest6Strc* pQuestDataEx; };
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
// 0x0059CA50
bool __fastcall ACT2Q6_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 7, 0)) { *pStatus = 0; return true; }
    D2Act2Quest6Strc* pEx = pQuest->pQuestDataEx;
    if (pEx->bStatusOverride) { *pStatus = pEx->nStatus; return true; }
    *pStatus = 0;
    if (!QUESTRECORD_GetQuestState(pFlags, 14, 0))
    {
        if (QUESTRECORD_GetQuestState(pFlags, 14, 3) == 1) { *pStatus = 5; return true; }
        if (QUESTRECORD_GetQuestState(pFlags, 14, 4) == 1) { *pStatus = 6; return true; }
        if (pQuest->bNotIntro)
        {
            if (QUESTRECORD_GetQuestState(pFlags, 14, 5) == 1) { *pStatus = pQuest->fLastState; return true; }
            if (pQuest->fState < 3) { *pStatus = pQuest->fLastState; return true; }
            *pStatus = 12;
        }
    }
    return true;
}

struct D2BitBufferStrc;
struct D2QuestDataStrc { int nQuestNo; char unk04[7]; unsigned char fLastState; unsigned char fState; unsigned char nInitNo; char unk0E[0xD2]; int nQuestFilter; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
// 0x00543F90
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pStatus, D2BitBufferStrc* pFlags)
{
    const int bCompletedBefore = QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, 14);
    if (pQuest->fState >= pQuest->nInitNo)
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, 13) == 1)
        {
            if (pQuest->nQuestFilter >= 41)
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1109);
                exit(-1);
            }
            *pStatus = pQuest->fLastState;
            return;
        }
        if (pQuest->nQuestNo == 4 && bCompletedBefore)
        {
            if (pQuest->fState == 6)
            {
                *pStatus = 12;
                return;
            }
            *pStatus = pQuest->fLastState;
            return;
        }
        if (pQuest->nQuestNo == 10)
        {
            *pStatus = pQuest->fLastState == 4 ? 4 : 12;
            return;
        }
        goto status12;
    }
    if (bCompletedBefore)
        goto status12;
    if (pQuest->nQuestNo == 4 && pQuest->fLastState == 6 && !QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, 13))
        goto status12;
    *pStatus = pQuest->fLastState;
    return;
status12:
    *pStatus = 12;
}

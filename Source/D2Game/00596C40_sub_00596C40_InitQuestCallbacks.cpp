extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
struct D2QuestCallbacks00596C40Strc
{
    void* pfCallbackA0;
    unsigned char unk_A4[0x1C];
    void* pfCallbackC0;
    unsigned char unk_C4[0x3C - 0x24];
};
struct D2QuestData00596C40Strc
{
    unsigned char unk_00[0x0A];
    unsigned char nA;
    unsigned char nB;
    unsigned char nC;
    unsigned char unk_0D[0xA0 - 0x0D];
    D2QuestCallbacks00596C40Strc tCallbacks;
    void* pRecordDC;
    int nE0;
    unsigned char unk_E4[4];
    void* pfStatusFilterE8;
    void* pfActiveFilterEC;
};
extern unsigned char gtRecord_00738778[]; // 0x00738778
void __fastcall sub_00596A90_Callback(); // 0x00596A90
void __fastcall sub_00596BA0_EmptyCallback(); // 0x00596BA0
void __fastcall ACT3Q7_StatusFilterCallback(); // 0x00596BB0
void __fastcall ACT1Q7_ActiveFilterCallback(); // 0x00596BC0

// 0x00596C40
void __fastcall sub_00596C40_InitQuestCallbacks(D2QuestData00596C40Strc* pQuestData)
{
    memset(&pQuestData->tCallbacks, 0, sizeof(pQuestData->tCallbacks));
    pQuestData->tCallbacks.pfCallbackA0 = (void*)sub_00596A90_Callback;
    pQuestData->tCallbacks.pfCallbackC0 = (void*)sub_00596BA0_EmptyCallback;
    pQuestData->pRecordDC = gtRecord_00738778;
    pQuestData->nA = 1;
    pQuestData->nC = 0;
    pQuestData->nB = 0;
    pQuestData->nE0 = 0x1D;
    pQuestData->pfStatusFilterE8 = (void*)ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilterEC = (void*)ACT1Q7_ActiveFilterCallback;
}

#include "gen/data/Source/D2Game/00596C40_sub_00596C40_InitQuestCallbacks.inc"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
struct D2QuestCallbacks0058EA50Strc
{
    void* pfCallbackA0;
    unsigned char unk_A4[0x28];
    void* pfCallbackCC;
    unsigned char unk_D0[0x3C - 0x30];
};
struct D2QuestData0058EA50Strc
{
    unsigned char unk_00[0x0A];
    unsigned char nA;
    unsigned char nB;
    unsigned char nC;
    unsigned char unk_0D[0x18 - 0x0D];
    int n18;
    unsigned char unk_1C[0xA0 - 0x1C];
    D2QuestCallbacks0058EA50Strc tCallbacks;
    void* pRecordDC;
    int nE0;
    unsigned char unk_E4[4];
    void* pfStatusFilterE8;
    void* pfActiveFilterEC;
};
extern unsigned char gtRecord_00732FF8[]; // 0x00732FF8
void __fastcall sub_00586B50_Callback(); // 0x00586B50
void __fastcall sub_0058E990_Callback(); // 0x0058E990
void __fastcall sub_00586C40_StatusFilterCallback(); // 0x00586C40
void __fastcall sub_00586C50_ActiveFilterCallback(); // 0x00586C50

// 0x0058EA50
void __fastcall sub_0058EA50_InitQuestCallbacks(D2QuestData0058EA50Strc* pQuestData)
{
    memset(&pQuestData->tCallbacks, 0, sizeof(pQuestData->tCallbacks));
    pQuestData->tCallbacks.pfCallbackA0 = (void*)sub_00586B50_Callback;
    pQuestData->tCallbacks.pfCallbackCC = (void*)sub_0058E990_Callback;
    pQuestData->pRecordDC = gtRecord_00732FF8;
    pQuestData->nA = 1;
    pQuestData->nC = 0;
    pQuestData->nB = 0;
    pQuestData->n18 = 0;
    pQuestData->nE0 = 0x2A;
    pQuestData->pfStatusFilterE8 = (void*)sub_00586C40_StatusFilterCallback;
    pQuestData->pfActiveFilterEC = (void*)sub_00586C50_ActiveFilterCallback;
}

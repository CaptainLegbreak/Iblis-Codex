struct D2GameStrc;

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
};

// 0x005919C0
static __forceinline void sub_005919C0_SetLastStateTwo(D2QuestDataStrc* pQuestData)
{
    pQuestData->fLastState = 2;
}

void __stdcall sub_M113_Emit_005919C0(D2QuestDataStrc* pFirst, D2QuestDataStrc* pSecond)
{
    sub_005919C0_SetLastStateTwo(pFirst);
    sub_005919C0_SetLastStateTwo(pSecond);
}

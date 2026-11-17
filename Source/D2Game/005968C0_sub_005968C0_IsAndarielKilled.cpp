struct D2QuestArgStrc;

struct D2Act1Quest6Strc
{
    char unk0x000[0x194];
    unsigned char bAndarielKilled;
    unsigned char bCainActivated;
    unsigned char pad0x196[2];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    void* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    D2Act1Quest6Strc* pQuestDataEx;
};

// 0x005968C0
int __fastcall sub_005968C0_IsAndarielKilled(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->bNotIntro)
        return pQuestData->pQuestDataEx->bAndarielKilled;
    return 1;
}

// 0x00596BA0
void __fastcall sub_00596BA0_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}

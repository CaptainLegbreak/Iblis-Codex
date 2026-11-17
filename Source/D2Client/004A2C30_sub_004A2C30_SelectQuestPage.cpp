struct D2QuestTextsStrc;

struct D2QuestTableStrc
{
    unsigned char bEnabled;
    unsigned char nCelId;
    unsigned char nCelId2;
    unsigned char nPage;
    D2QuestTextsStrc* pTexts;
    int nCondition;
    int nQuestId;
};

extern D2QuestTableStrc gaQuestTable_00723F30[];                                                            // 0x00723F30
extern int ganPageSelection_007BF280[5];                                                                    // 0x007BF280

// 0x004A2C30
void __fastcall sub_004A2C30_SelectQuestPage(int nCondition)
{
    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable_00723F30[i].nCondition == nCondition)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex != -1)
        ganPageSelection_007BF280[gaQuestTable_00723F30[nIndex].nPage] = gaQuestTable_00723F30[nIndex].nCelId2;
}

struct D2TextHeaderStrc;

struct D2NPCMessageStrc
{
    int nNPCNo;
    unsigned short nStringIndex;
    unsigned short nPad;
    int nMenu;
};

struct D2NPCMessageTableStrc
{
    D2NPCMessageStrc pMessages[16];
    int nMessages;
};

struct D2QuestDataStrc
{
    char unk0x00[0xDC];
    D2NPCMessageTableStrc* pNPCMessages;
};

void __stdcall TEXT_AddNodeToTextList(D2TextHeaderStrc* pTextHeader, short nStringId, int nMenu);            // 0x006612F0

// 0x00543790
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex)
{
    D2NPCMessageTableStrc* pTables = pQuest->pNPCMessages;

    for (int i = 0; i < pTables[nIndex].nMessages; ++i)
    {
        if (pTables[nIndex].pMessages[i].nNPCNo == nNPCID)
        {
            int nMenu = pTables[nIndex].pMessages[i].nMenu;
            if (nMenu == 1)
            {
                nMenu = 0;
            }

            TEXT_AddNodeToTextList(pTextControl, pTables[nIndex].pMessages[i].nStringIndex, nMenu);
        }
    }
}

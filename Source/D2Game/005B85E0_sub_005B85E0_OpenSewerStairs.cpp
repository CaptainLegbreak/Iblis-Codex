struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
    unsigned char pad0x02[2];
    int nSewerStairsObjectGUID;
    int nSewerStairsObjectMode;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

#define UNIT_OBJECT 2
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1

void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId);                 // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

// 0x005B85E0
void __fastcall sub_005B85E0_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bSewerStairsInitialized == 1)
    {
        D2UnitStrc* pFoundUnit = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nSewerStairsObjectGUID);
        if (!pFoundUnit)
        {
            pQuestDataEx->nSewerStairsObjectMode = OBJMODE_OPENED;
            return;
        }

        UNITS_ChangeAnimMode(pFoundUnit, pQuestDataEx->nSewerStairsObjectMode);
        if (pQuestDataEx->nSewerStairsObjectMode != OBJMODE_OPENED)
        {
            pQuestDataEx->nSewerStairsObjectMode = OBJMODE_OPENED;
            const int nClassId = pFoundUnit->dwClassId;
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
            sub_005417D0_DirectDated(pQuestData->pGame, pFoundUnit, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pQuestData->pGame->dwGameFrame, 0, 0);
        }
    }
}

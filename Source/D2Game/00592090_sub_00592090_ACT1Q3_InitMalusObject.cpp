struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x04];
    int dwUnitId;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    char unk0x0B[0x0D];
    void* pQuestDataEx;
};

struct D2Act1Quest3Strc
{
    unsigned char unk0x00;
    unsigned char bMalusInitialized;
    unsigned char bCharsiIntroActivated;
    unsigned char bCharsiEndActivated;
    int nMalusGUID;
    char unk0x08[0x90];
    int nMalusObjectMode;
};

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x00592090
void __fastcall sub_00592090_ACT1Q3_InitMalusObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (pQuestData)
    {
        D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->bMalusInitialized = 1;
        pQuestDataEx->nMalusGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        if (!pQuestData->bNotIntro)
        {
            pQuestDataEx->nMalusObjectMode = 2;
        }
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nMalusObjectMode);
    }
}

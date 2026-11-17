struct D2HoverTextStrc;
struct D2TimerArgStrc;
struct D2UnitStrc;
struct D2GameStrc
{
    char unk0x00[28];
    void* pMemoryPool;
    char unk0x20[4352];
    D2UnitStrc* pUnitList[5][128];
};
struct D2ObjectsTxt
{
    char unk0x00[376];
    unsigned int dwParm[8];
};
struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
};
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x8C];
    D2HoverTextStrc* pHoverText;
};
struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    void* pRoom;
    void* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
};

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit);                                            // 0x006234F0
void __fastcall sub_0054F580(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg);                // 0x0054F580
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600

#define UNIT_OBJECT 2
#define UNIT_LIST_SIZE 128
#define WELL_PARAM 2

// 0x00552A00
void __fastcall OBJECTS_FreeHoverMessage(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pObject->pHoverText);
    }

    sub_0054F580(pGame, UNITS_GetTimerArg(pObject));
    sub_6FC349F0(pGame, pObject);
}

// 0x00552A40
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < UNIT_LIST_SIZE; ++i)
    {
        D2UnitStrc* pObject = pGame->pUnitList[UNIT_OBJECT][i];
        while (pObject)
        {
            D2UnitStrc* pCurrent = pObject;
            pObject = SUNIT_GetNextUnitFromList(pObject);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x00552B30
void __fastcall OBJECTS_InitFunction16_Well(D2ObjInitFnStrc* pOp)
{
    pOp->pObject->pObjectData->InteractType = 2 * (unsigned char)pOp->pObjectTxt->dwParm[WELL_PARAM];
}

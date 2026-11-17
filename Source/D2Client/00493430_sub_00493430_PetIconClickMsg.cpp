struct D2UnitStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00467410_SetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue);            // 0x00467410
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20

extern int gnGlobal_007BEECC;                                                                               // 0x007BEECC

// 0x00493430
void __stdcall sub_00493430_PetIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnGlobal_007BEECC == 2)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nUnitId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
    if (nUnitId != -1)
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPet = sub_00463990(nUnitId, 1);
    if (!pPet)
    {
        pMsg->bReturn = 0;
        return;
    }

    sub_00467410_SetEntryValue(pPlayer, pPet, 1);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

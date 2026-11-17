struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xE4];
    D2UnitStrc* pRoomNext;
};

D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom);                               // 0x00619F60
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

// 0x0064C0C0
void __stdcall UNITROOM_SortUnitListByTargetY(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc** ppUnitFirst = 0;
    D2UnitStrc** ppUnit = 0;
    D2UnitStrc* pNextUnit = 0;
    D2UnitStrc* pUnit = 0;
    int bContinue = 0;

    ppUnit = DUNGEON_GetUnitListFromRoom(pRoom);
    pUnit = *ppUnit;
    ppUnitFirst = ppUnit;
    D2UnitStrc* pPreviousUnit = 0;

    if (pUnit)
    {
        pNextUnit = pUnit->pRoomNext;
        do
        {
            bContinue = 0;

            while (pNextUnit)
            {
                int nY = UNITS_GetClientCoordY(pUnit);
                if (nY > UNITS_GetClientCoordY(pNextUnit))
                {
                    if (pPreviousUnit)
                    {
                        pPreviousUnit->pRoomNext = pNextUnit;
                    }
                    else
                    {
                        *ppUnitFirst = pNextUnit;
                    }

                    pUnit->pRoomNext = pNextUnit->pRoomNext;
                    pNextUnit->pRoomNext = pUnit;
                    pPreviousUnit = pNextUnit;
                    pNextUnit = pUnit->pRoomNext;
                    bContinue = 1;
                }
                else
                {
                    pPreviousUnit = pUnit;
                    pUnit = pNextUnit;
                    pNextUnit = pNextUnit->pRoomNext;
                }
            }
        }
        while (bContinue);
    }
}

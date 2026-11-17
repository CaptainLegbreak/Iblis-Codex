struct D2GameStrc { char unk00[0xA8]; int dwGameFrame; };
struct D2QuestExtraStrc { char unk00[0xC]; int nState; int nMode; };
struct D2QuestDataStrc { int nQuest; D2GameStrc* pGame; char unk08[0x10]; D2QuestExtraStrc* pQuestDataEx; };
struct D2UnitStrc { int dwUnitType; char unk04[0xC]; int dwAnimMode; char unk14[0xD4]; D2UnitStrc* pRoomNext; };
struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned int __stdcall D2Common_10399(D2UnitStrc*, D2UnitStrc*); // 0x00641530
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc*); // 0x00623830
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0

static __forceinline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}
// 0x005BCAC0
void __fastcall sub_005BCAC0_UpdateQuestObject(D2QuestDataStrc* pQuest, D2UnitStrc* pObject)
{
    D2QuestExtraStrc* pEx = pQuest->pQuestDataEx;
    if (pEx->nState == 2)
    {
        const int nMode = !pObject ? 0 : pObject->dwAnimMode;
        if (nMode == 2) return;
        for (D2UnitStrc* pUnit = UNITS_GetRoom(pObject)->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            if (UNITS_GetUnitTypeInline(pUnit) == 0 && D2Common_10399(pUnit, pObject) < 18)
            {
                if (nMode == 0)
                {
                    pEx->nMode = 2;
                    UNITS_ChangeAnimMode(pObject, 1);
                }
                else if (nMode == 1)
                {
                    pEx->nMode = 2;
                    UNITS_ChangeAnimMode(pObject, 2);
                    UNITS_FreeCollisionPath(pObject);
                }
                EVENT_SetEvent(pQuest->pGame, pObject, 7, pQuest->pGame->dwGameFrame + 24, 0, 0);
                return;
            }
        }
    }
    EVENT_SetEvent(pQuest->pGame, pObject, 7, pQuest->pGame->dwGameFrame + 24, 0, 0);
}

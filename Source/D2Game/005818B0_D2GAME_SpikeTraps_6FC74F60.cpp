struct D2ObjectDataStrc { int unk00; unsigned char InteractType; };
struct D2UnitStrc { int dwUnitType; int dwClassId; char pad08[8]; int dwAnimMode; D2ObjectDataStrc* pObjectData; char pad18[0xE8 - 0x18]; D2UnitStrc* pRoomNext; };
struct D2ActiveRoomStrc { char pad00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2GameStrc { char pad00[0xA8]; unsigned int dwGameFrame; };
struct D2CoordStrc { int nX; int nY; };
struct D2ObjectsTxt { char pad00[0xD8]; unsigned int dwFrameCnt[8]; };

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall UNITS_GetDistanceToOtherUnit(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005818B0
void __fastcall D2GAME_SpikeTraps_6FC74F60(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    int nAnimMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);

    int bArmed = 0;
    switch (pObject->pObjectData->InteractType)
    {
    case 1:
        bArmed = 1;
    case 0:
    {
        D2CoordStrc tCoord;
        UNITS_GetCoords(pObject, &tCoord);

        int bWarningTriggered = 0;
        int bDamageTriggered = 0;
        D2UnitStrc* pUnit = pRoom->pUnitFirst;
        if (pUnit)
        {
            do
            {
                const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
                const int nUnitMode = pUnit ? pUnit->dwAnimMode : 0;
                if (nUnitType == 0 && nUnitMode != 17 && UNITS_GetDistanceToOtherUnit(pObject, pUnit) <= 0)
                {
                    if (bArmed)
                    {
                        OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, pUnit, 0);
                        bDamageTriggered = 1;
                    }
                    else
                    {
                        SUNIT_AttachSound(pObject, 13, 0);
                        bWarningTriggered = 1;
                    }
                }

                pUnit = pUnit->pRoomNext;
            }
            while (pUnit);

            if (bWarningTriggered)
            {
                pObject->pObjectData->InteractType = 1;
                EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 25, 0, 0);
                return;
            }
        }

        if (bArmed)
        {
            if (bDamageTriggered == 1)
            {
                pObject->pObjectData->InteractType = 2;
                UNITS_ChangeAnimMode(pObject, 1);
            }
            else
            {
                pObject->pObjectData->InteractType = 0;
            }

            EVENT_SetEvent(pGame, pObject, 3, (DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId)->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            return;
        }
        break;
    }
    case 2:
        if (nAnimMode)
        {
            UNITS_ChangeAnimMode(pObject, 0);
            pObject->pObjectData->InteractType = 0;
        }
        EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 15, 0, 0);
        return;
    }

    EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 15, 0, 0);
}

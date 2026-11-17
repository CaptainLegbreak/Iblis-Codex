struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2RoomCoordListStrc;
struct D2CoordStrc { int nX; int nY; };
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; char unk6E[0x3A]; int dwGameFrame; };
struct D2AiControlStrc { char unk00[0x14]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk00[0x56]; short wAiParam[8][3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; char unk04[0x10]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2DataTablesStrc { char unk00[0xA80]; int nMonStatsTxtRecordCount; };
extern D2DataTablesStrc* gpDataTables; // 0x00744304
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nClass, int* pX, int* pY, int nAvoid); // 0x0054DC40
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClass, int nMode, int a7, int a8); // 0x005B2F20
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nId); // 0x0063EC70
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
// build: context ValidateMonsterId
inline int ValidateMonsterId(int nId)
{
    if (nId < 0 || nId >= gpDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nId;
}
// 0x005E0160
void __fastcall sub_005E0160_ThinkSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    if (nDistance <= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pAiControl->dwAiParam[1] <= 0)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return;
        }
        if (pAiControl->dwAiParam[0] <= pGame->dwGameFrame)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            int nMonsterId = D2Common_11063(pRoom, ValidateMonsterId(96));
            int nX;
            int nY;
            if (MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nMonsterId, &nX, &nY, 0))
            {
                if (D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, 2, 0x42))
                {
                    --pAiControl->dwAiParam[1];
                    pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
                }
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

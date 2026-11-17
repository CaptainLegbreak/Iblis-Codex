struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc { int unused[3]; int nXPos,nYPos; };
struct D2UnitStrc { int dwUnitType,dwClassId; char unk08[0x24]; union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; }; char unk30[0xB8]; D2UnitStrc* pRoomNext; };
struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2MonStatsTxt { short nId,nBaseId; char unk04[0x1A4]; };
struct D2DataTablesStrc { char unk00[0xA78]; D2MonStatsTxt* pMonStatsTxt; int unkA7C; int nMonStatsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if(!(expr)) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1); }
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc*,int,int); // 0x00463740
static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }

    return pMonStatsTxtRecord->nBaseId;
}

static __forceinline int CLIENTS_GetUnitXForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitYForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

#define SKILLS_ROLL_SEED(pSeed, lSeed) \
    (lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
     (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32), \
     (pSeed)->nLowSeed = (unsigned int)lSeed, \
     (unsigned int)lSeed)

// 0x005DD370
D2UnitStrc* __fastcall sub_005DD370_FindMonsterAtCoords(D2GameStrc* game,D2ActiveRoomStrc* room,int x,int y,int baseId)
{
 D2_ASSERT(room,1954);
 room=D2GAME_GetRoom_6FC52070(room,x,y);
 D2_ASSERT(room,1956);
 for(D2UnitStrc* unit=room->pUnitFirst;unit;unit=unit->pRoomNext) {
  if((!unit ? 6 : unit->dwUnitType)!=1) continue;
  int nBase = MONSTERS_GetBaseIdFromMonsterId(unit->dwClassId);

  if (unit->dwClassId) { if (nBase != baseId) continue; } else { if (nBase != baseId) continue; }
  if (CLIENTS_GetUnitXForceInline(unit)==x && CLIENTS_GetUnitYForceInline(unit)==y) return unit;
 }
 return 0;
}

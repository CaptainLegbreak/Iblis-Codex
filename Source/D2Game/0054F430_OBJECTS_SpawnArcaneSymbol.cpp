struct D2GameStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __fastcall ACT2Q6_GetObjectIdForArcaneThing(D2GameStrc* pGame);                                         // 0x0059D830

#define UNIT_OBJECT 2

// 0x0054F430
D2UnitStrc* __fastcall OBJECTS_SpawnArcaneSymbol(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    const int nObjectId = ACT2Q6_GetObjectIdForArcaneThing(pGame);

    D2_ASSERT(pRoom, 391);

    return SUNIT_AllocUnitData(UNIT_OBJECT, nObjectId, nX, nY, pGame, pRoom, 1, 0, 0);
}

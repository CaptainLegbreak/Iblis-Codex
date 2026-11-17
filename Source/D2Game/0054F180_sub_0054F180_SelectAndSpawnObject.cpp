struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};
struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};
struct D2ObjectDataStrc
{
    char pad00[4];
    unsigned char nType;
};
struct D2UnitStrc
{
    char pad00[0x14];
    D2ObjectDataStrc* pObjectData;
    char pad18[0xAC];
    unsigned int dwFlags;
};
struct D2GameStrc;
struct D2ActiveRoomStrc;
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int); // 0x006427F0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc*, D2ActiveRoomStrc*); // 0x00546FA0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int, int, int, int, D2GameStrc*, D2ActiveRoomStrc*, char, int, unsigned int); // 0x00555230
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc*, unsigned char); // 0x005540A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline unsigned __int64 RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

// 0x0054F180
__declspec(noinline) D2UnitStrc* __fastcall sub_0054F180_SelectAndSpawnObject(
    D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused)
{
    unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    int nLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nObject;
    switch (nAct)
    {
    case 1:
        if (nLevel == 0x4A)
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 3;
            int nChoices[] = { 0x183, 0x185, 0x186, 0x187 };
            nObject = nChoices[nIndex];
        }
        else
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 1;
            int nChoices[] = { 0x57, 0x58 };
            nObject = nChoices[nIndex];
        }
        break;
    case 2:
        if (nLevel == 0x53)
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 3;
            int nChoices[] = { 0x149, 0x14A, 0x14B, 0x14C };
            nObject = nChoices[nIndex];
        }
        else
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 1;
            int nChoices[] = { 0xB5, 0xB7 };
            nObject = nChoices[nIndex];
        }
        break;
    default:
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) % 13;
            int nChoices[] = { 5, 6, 0x8B, 0x8C, 0x8D, 0x90, 0xB0, 0xB1, 0xC6, 0xF0, 0xF1, 0xF2, 0xF3 };
            nObject = nChoices[nIndex];
        }
        break;
    }
    if (nClassId == 0x173)
        nObject = 0x173;
    D2_ASSERT(pRoom, 0x157);
    return SUNIT_AllocUnitData(2, nObject, nX, nY, pGame, pRoom, 1, 0, 0);
}

struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int(__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

typedef D2UnitStrc* (__fastcall* PRESETSPAWNFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode);

extern PRESETSPAWNFN sgPresetStuff_00731D28[];                                                              // 0x00731D28
extern int sgnPresetStuffCount_00731D4C;                                                                    // 0x00731D4C

// 0x0054F490
D2UnitStrc* __fastcall OBJECTS_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId <= 573)
    {
        return 0;
    }

    const int nIndex = nClassId - 574;
    if (nIndex >= sgnPresetStuffCount_00731D4C)
    {
        return 0;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)sgPresetStuff_00731D28[nIndex]), 429);

    return sgPresetStuff_00731D28[nIndex](pGame, pRoom, nClassId, nX, nY, nMode);
}

#include "gen/data/Source/D2Game/0054F490_OBJECTS_SpawnPresetObject.inc"

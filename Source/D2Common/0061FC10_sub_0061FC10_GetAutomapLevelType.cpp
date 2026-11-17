extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const char gszAutomapLevelNames_006E7D50[36][16];                                                    // 0x006E7D50
extern const char gszAutomapTileNames_006E7F90[20][8];                                                      // 0x006E7F90

// 0x0061FC10
static int sub_0061FC10_GetAutomapLevelType(const char* szLevelName)
{
    if (szLevelName[0] != '0')
    {
        for (int nLevelType = 0; nLevelType < 36; ++nLevelType)
        {
            if (!strcmp(szLevelName, gszAutomapLevelNames_006E7D50[nLevelType]))
            {
                return nLevelType;
            }
        }

        D2_ASSERT(0, 0x4A5);
    }

    return 0;
}

// 0x0061FC80
static int sub_0061FC80_GetAutomapTileType(const char* szTileName)
{
    if (szTileName[0] != '0')
    {
        for (int nTileType = 0; nTileType < 20; ++nTileType)
        {
            if (!strcmp(szTileName, gszAutomapTileNames_006E7F90[nTileType]))
            {
                return nTileType;
            }
        }

        D2_ASSERT(0, 0x4D0);
    }

    return 0;
}

void __stdcall sub_M14_EmitAutomapLookups(const char* pAutomapRecord, int* pTypes)
{
    pTypes[0] = sub_0061FC10_GetAutomapLevelType(pAutomapRecord);
    pTypes[1] = sub_0061FC80_GetAutomapTileType(pAutomapRecord + 16);
}

#include "gen/data/Source/D2Common/0061FC10_sub_0061FC10_GetAutomapLevelType.inc"

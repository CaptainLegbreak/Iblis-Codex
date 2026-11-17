extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

extern const unsigned char gaDirection8To4_006E5DA0[];                                                      // 0x006E5DA0
extern const unsigned char gaDirection16To8_006E5DA8[];                                                     // 0x006E5DA8
extern const unsigned char gaDirection8To4Alt_006E5DB8[];                                                   // 0x006E5DB8
extern const unsigned char gaDirection16To8Alt_006E5DC0[];                                                  // 0x006E5DC0

struct D2TileRecordStrc
{
    int nFirst;
    int nSecond;
    int unk0x08;
    int unk0x0C;
};

// 0x00600CB0
int __stdcall sub_00600CB0_ConvertDirection(unsigned int nDirection, unsigned int nDirections, int nNewDirections, int bAlt)
{
    D2_ASSERT(nDirection < nDirections, 0x1A0);

    if (nDirections == 8)
    {
        if (nNewDirections == 4)
        {
            if (bAlt)
            {
                return gaDirection8To4Alt_006E5DB8[nDirection];
            }
            return gaDirection8To4_006E5DA0[nDirection];
        }
    }
    else if (nDirections == 16)
    {
        if (nNewDirections == 8)
        {
            if (bAlt)
            {
                return gaDirection16To8Alt_006E5DC0[nDirection];
            }
            return gaDirection16To8_006E5DA8[nDirection];
        }
    }

    return 0;
}

// 0x00605D20
void __stdcall sub_00605D20_BuildTintTables(unsigned char* pData)
{
    for (int j = 0; j < 12; ++j)
    {
        for (int i = 0; i < 256; ++i)
        {
            const int nValue = pData[4 * i];
            pData[0x6B727 + 256 * j + i] = sub_00605210_FindNearestColor(pData, 256,
                (unsigned char)(pData[0x6B603 + 3 * j] * nValue / 255),
                (unsigned char)(pData[0x6B604 + 3 * j] * nValue / 255),
                (unsigned char)(pData[0x6B605 + 3 * j] * nValue / 255));
        }
    }
}

// 0x00609620
D2TileRecordStrc* __stdcall sub_00609620_AllocTileRecord(int nFirst, int nSecond)
{
    D2TileRecordStrc* pRecord = (D2TileRecordStrc*)FOG_Alloc(sizeof(D2TileRecordStrc), ".\\SRC\\Tilecmp.cpp", 0x6D, 0);
    D2_ASSERT(pRecord, 0x6E);
    memset(pRecord, 0, sizeof(D2TileRecordStrc));
    pRecord->nFirst = nFirst;
    pRecord->nSecond = nSecond;
    return pRecord;
}

#include "gen/data/Source/D2CMP/00600CB0_sub_00600CB0_ConvertDirection.inc"

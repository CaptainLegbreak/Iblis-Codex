extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgStrc;
struct D2ActiveRoomStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x30];
    D2ActiveRoomStrc* pRoom;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x1D0 - 0x1B8];
    int nLevelId;
};

struct D2DrlgListEntryStrc
{
    char unk0x00[0x24];
    D2DrlgListEntryStrc* pNext;
    int dwFlags;
};

struct D2DrlgListOwnerStrc
{
    char unk0x00[0x10];
    D2DrlgListEntryStrc* pFirst;
};

unsigned int __fastcall sub_006C9A38(const char* szString);                                                    // 0x006C9A38
void __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                                   // 0x0061B730
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                        // 0x0066AEC0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040

// 0x0066A290
void __cdecl sub_0066A290_AssertFail()
{
    D2_ASSERT(0, 0x65);
}

// 0x0066A870
static __forceinline int sub_0066A870_SumStringBytes(const char* szText)
{
    int nSum = 0;
    while (*szText)
    {
        nSum += (unsigned char)*szText;
        ++szText;
    }

    return nSum & 0xFF;
}

// 0x0066A890
static __forceinline int sub_0066A890_CompareCodes(const char* szA, const char* szB)
{
    D2_ASSERT(sub_006C9A38(szA) <= 8, 0xD9);
    D2_ASSERT(sub_006C9A38(szB) <= 8, 0xDA);
    if (*(const int*)szA != *(const int*)szB)
    {
        return 0;
    }

    return *(const int*)(szA + 4) == *(const int*)(szB + 4);
}

// 0x0066AC30
static __forceinline D2ActiveRoomStrc* sub_0066AC30_GetActiveRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
    return pDrlgRoom->pRoom;
}

// 0x0066AF10
int* __fastcall sub_0066AF10_GetWarpIdArray(D2DrlgLevelStrc* pLevel)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId);
}

// 0x0066AFB0
static __forceinline int sub_0066AFB0_FindVisIndex(D2DrlgStrc* pDrlg, int nLevelId, int nVisLevel, int nIndex)
{
    int* pVis = DRLGROOM_GetVisArrayFromLevelId(pDrlg, nLevelId);
    int nCount = 0;
    for (unsigned char i = 0; i < 8; ++i)
    {
        if (pVis[i] == nVisLevel)
        {
            if (nCount == nIndex)
            {
                return i;
            }

            ++nCount;
        }
    }

    return -1;
}

// 0x0066AFF0
static __forceinline D2DrlgListEntryStrc* sub_0066AFF0_FindFlaggedEntry(D2DrlgStrc* pDrlg, int nBit)
{
    const int nMask = 1 << (nBit + 4);
    for (D2DrlgListEntryStrc* pEntry = ((D2DrlgListOwnerStrc*)pDrlg)->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwFlags & nMask)
        {
            return pEntry;
        }
    }

    return 0;
}

int __fastcall sub_M117_Emit_0066A870(const char* szText, D2DrlgRoomStrc* pDrlgRoom, D2DrlgStrc* pDrlg, int nLevelId)
{
    int n = sub_0066A870_SumStringBytes(szText);
    n += sub_0066A890_CompareCodes(szText, (const char*)pDrlgRoom);
    n += (int)sub_0066AC30_GetActiveRoom(pDrlgRoom);
    n += sub_0066AFB0_FindVisIndex(pDrlg, nLevelId, n, nLevelId);
    n += (int)sub_0066AFF0_FindFlaggedEntry(pDrlg, n);
    return n;
}

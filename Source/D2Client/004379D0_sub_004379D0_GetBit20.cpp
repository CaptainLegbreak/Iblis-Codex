struct D2WinControlStrc;

struct D2CharSelCacheStrc
{
    unsigned int dwHash;
    void* pData;
    unsigned int dwExpireTick;
    D2CharSelCacheStrc* pNext;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0
int __cdecl sub_00430B40();                                                                                 // 0x00430B40
char* __fastcall sub_00430B50_GetSlotName(int nIndex);                                                      // 0x00430B50
int __cdecl sub_00430A20_FreeSlots();                                                                       // 0x00430A20
void __cdecl sub_00434060();                                                                                // 0x00434060
int __fastcall D2Win_10188(D2WinControlStrc* pTextBox, int nLineNum, int a3);                               // 0x004FBDE0

extern D2CharSelCacheStrc* gpCharSelCache_00779DE8;                                                         // 0x00779DE8
extern int gbFlag_00779C6C;                                                                                 // 0x00779C6C
extern D2WinControlStrc* gpNameControl_007799E8;                                                            // 0x007799E8
extern char gszBaseName_00779B68[];                                                                         // 0x00779B68

// 0x004379D0
int __fastcall sub_004379D0_GetBit20(int nValue)
{
    return nValue & 0x20;
}

// 0x004379E0
unsigned int __fastcall sub_004379E0_GetBits8(unsigned int nValue)
{
    return (nValue >> 8) & 0x1F;
}

// 0x004379F0
void __cdecl sub_004379F0_Forward()
{
    sub_00434060();
}

// 0x00437A00
static __forceinline char* sub_00437A00_GetSlotNameChecked(int nIndex)
{
    if (nIndex < sub_00430B40())
        return sub_00430B50_GetSlotName(nIndex);
    return 0;
}

// 0x00437A60
int __cdecl sub_00437A60_FreeSlots()
{
    return sub_00430A20_FreeSlots();
}

// 0x00437A70
void* __fastcall sub_00437A70_CharSelCacheFind(const char* szKey)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    const int nTick = GetTickCount();
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

// 0x00437C90
void __cdecl sub_00437C90_ScrollNameControl()
{
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl_007799E8, -1, 4);
}

// 0x00437F30
void __fastcall sub_00437F30_CopyBaseName(const char* szName)
{
    char* pDest = gszBaseName_00779B68;
    while (*szName && *szName != '.')
        *pDest++ = *szName++;
    *pDest = 0;
}

int __fastcall sub_M110_Emit_00437A00(int nIndex)
{
    return sub_00437A00_GetSlotNameChecked(nIndex + 1) != 0;
}

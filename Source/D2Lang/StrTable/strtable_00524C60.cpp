extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
#pragma intrinsic(strcmp)

#pragma pack(push, 1)
struct D2StrTableHeader00524C60Strc
{
	unsigned short wCrc;
	unsigned short wNumElements;
	int nHashTableSize;
	unsigned char nVersion;
	unsigned int dwIndexStart;
	unsigned int nNumLoops;
	unsigned int dwFileSize;
};

struct D2StrHashEntry00524C60Strc
{
	unsigned char bUsed;
	unsigned short wIndex;
	unsigned int dwHash;
	unsigned int dwStrOffset;
	unsigned int dwNameOffset;
	unsigned short wNameLength;
};
#pragma pack(pop)

int __stdcall sub_005249E0(const char* szKey, int nHashTableSize); // 0x005249E0

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static __declspec(noinline) unsigned short __stdcall sub_00524C60_FindKey(void** ppSlots, const char* szKey, void** ppOut, D2StrTableHeader00524C60Strc* pTable);

// 0x00524C60
static unsigned short __stdcall sub_00524C60_FindKey(void** ppSlots, const char* szKey, void** ppOut, D2StrTableHeader00524C60Strc* pTable)
{
	D2StrHashEntry00524C60Strc* pHashTable = (D2StrHashEntry00524C60Strc*)((char*)pTable + sizeof(D2StrTableHeader00524C60Strc) + pTable->wNumElements * sizeof(unsigned short));
	unsigned int nLoops = 0;
	int const tArg1 = pTable->nHashTableSize;
	int nHash = sub_005249E0(szKey, tArg1);
	while (nLoops < pTable->nNumLoops)
	{
		++nLoops;
		if ((&pHashTable[nHash])->bUsed == 1 && !strcmp((const char*)pTable + (&pHashTable[nHash])->dwStrOffset, szKey))
		{
			D2_ASSERT(ppSlots[nHash], 662);
			*ppOut = ppSlots[nHash];
			return pHashTable[nHash].wIndex;
		}
		nHash = (nHash + 1) % pTable->nHashTableSize;
	}

	return 0xFFFF;
}

// build: context sub_00524C60_Shim

// calling-convention shim (not game code)
unsigned short __stdcall sub_00524C60_Shim(D2StrTableHeader00524C60Strc* pTable, void** ppSlots, const char* szKey, void** ppOut)
{
	return sub_00524C60_FindKey(ppSlots, szKey, ppOut, pTable);
}

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

struct D2DrlgStrc
{
	char unk_000[0x478];
	void* pMempool;
};

struct D2DrlgPresetInfoStrc
{
	void* pDrlgMap;
	int nDirection;
};

struct D2SeedStrc
{
	unsigned int nLowSeed;
	unsigned int nHighSeed;
};

struct D2DrlgLevelStrc
{
	char unk_000[0x14];
	D2DrlgPresetInfoStrc* pPreset;
	char unk_018[0x1B4 - 0x18];
	D2DrlgStrc* pDrlg;
	char unk_1B8[0x1C4 - 0x1B8];
	D2SeedStrc pSeed;
	char unk_1CC[0x1D0 - 0x1CC];
	int nLevelId;
};

struct D2LvlPrestTxt
{
	char unk_00[0x40];
	int dwFiles;
};

extern const char gszPresetFile[]; // 0x006EE7C4
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall sub_0045C3E0(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2LvlPrestTxt* __fastcall DATATBLS_GetLvlPrestTxtRecordFromLevelId(int nLevelId); // 0x0061F0E0
void __fastcall sub_00642D10(D2DrlgStrc* pDrlg, D2DrlgLevelStrc* pLevel); // 0x00642D10

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// build: context DRLGPRESET_GetFileCount
static __forceinline int DRLGPRESET_GetFileCount(D2LvlPrestTxt* pLvlPrestTxtRecord)
{
	return pLvlPrestTxtRecord->dwFiles;
}

// 0x00667430
void __fastcall DRLGPRESET_InitLevelData(D2DrlgLevelStrc* pLevel)
{
	void* const tArg1 = pLevel->pDrlg->pMempool;
	D2DrlgPresetInfoStrc* pPreset = (D2DrlgPresetInfoStrc*)FOG_AllocPool(tArg1, sizeof(D2DrlgPresetInfoStrc), gszPresetFile, 2809, 0);
	D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecordFromLevelId(pLevel->nLevelId);
	D2_ASSERT(pLvlPrestTxtRecord, 2811);

	pLevel->pPreset = pPreset;
	memset(pPreset, 0, sizeof(D2DrlgPresetInfoStrc));

	const int nFiles = DRLGPRESET_GetFileCount(pLvlPrestTxtRecord);
	if (nFiles)
	{
		pPreset->nDirection = sub_0045C3E0(&pLevel->pSeed, nFiles);
	}
	else
	{
		pPreset->nDirection = -1;
	}

	sub_00642D10(pLevel->pDrlg, pLevel);
}

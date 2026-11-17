struct D2GlideTexCacheStrc
{
	int unk0x00;
	int nEntries;
};

struct D2GlideTileCacheStrc
{
	int unk0x00;
};

struct D2GlideFloorCacheStrc
{
	int unk0x00;
};

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                          // 0x00410610
int __fastcall sub_0050B860_InitSpriteMemory(unsigned int nAddress, unsigned int nAlign);                   // 0x0050B860
int __fastcall sub_0050DFE0_GlideSetSmackTexAddresses(unsigned int nAddress, unsigned int nAlign);          // 0x0050DFE0
int __fastcall sub_0050E890_TexCacheInit(D2GlideTexCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050E890
int __fastcall sub_0050ED90_TileCacheInit(D2GlideTileCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050ED90
int __fastcall sub_0050F320_FloorCacheInit(D2GlideFloorCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050F320
void __cdecl sub_0050B7B0_GlideInitSprites();                                                               // 0x0050B7B0
void __stdcall sub_0050FCB0_GlideReleaseTileCache();                                                        // 0x0050FCB0
void __stdcall sub_00604A30_StoreTileFreeHandler(void (__stdcall* pfnHandler)());                           // 0x00604A30

extern unsigned int (__stdcall* gpfnGrTexMinAddress_0087EB24)(int nTmu);                                    // 0x0087EB24
extern unsigned int (__stdcall* gpfnGrTexMaxAddress_0087EB44)(int nTmu);                                    // 0x0087EB44
extern unsigned int gdwTmuMinAddress_0087EAA4[];                                                            // 0x0087EAA4
extern unsigned int gdwTmuMaxAddress_0087EAE4[];                                                            // 0x0087EAE4
extern int gnTmuCount_0087EFB4;                                                                             // 0x0087EFB4
extern unsigned int gnTexAlign_0087EFBC;                                                                    // 0x0087EFBC
extern int gbFloorTiles_0087EFE8;                                                                           // 0x0087EFE8
extern D2GlideTileCacheStrc gTileCache_0087EB48;                                                            // 0x0087EB48
extern D2GlideFloorCacheStrc gFloorCache_0087EB68;                                                          // 0x0087EB68
extern D2GlideTexCacheStrc gTexCache_0087F068;                                                              // 0x0087F068
extern D2GlideTexCacheStrc gTexCache_0087F088;                                                              // 0x0087F088
extern D2GlideTexCacheStrc gTexCache_0087F0A8;                                                              // 0x0087F0A8
extern unsigned int gnFloorCacheSize_007C90C8;                                                              // 0x007C90C8
extern unsigned int gnTileCacheSize_007C90D4;                                                               // 0x007C90D4
extern unsigned int gnTexCacheSize_007C90E0;                                                                // 0x007C90E0
extern unsigned int gnTexCacheSize_007C90E4;                                                                // 0x007C90E4
extern unsigned int gnTexCacheSize_007C90E8;                                                                // 0x007C90E8
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern const char gszInsufficientTextureMemory_006DD480[];                                     // 0x006DD480

// 0x00509670
int __cdecl sub_00509670_InitTextureMemory()
{
	const unsigned int nMask = gnTexAlign_0087EFBC - 1;
	unsigned int nTotal = 0;
	unsigned int nAlign64K = 0x10000;
	unsigned int nAlign16K = 0x4000;
	unsigned int nAlign4K = 0x1000;
	if (nMask & 0x10000)
	{
		nAlign64K = (nMask | 0x10000) + 1;
	}
	if (nMask & 0x4000)
	{
		nAlign16K = (nMask | 0x4000) + 1;
	}
	if (nMask & 0x1000)
	{
		nAlign4K = (nMask | 0x1000) + 1;
	}

	for (int i = 0; i < gnTmuCount_0087EFB4; ++i)
	{
		gdwTmuMinAddress_0087EAA4[i] = gpfnGrTexMinAddress_0087EB24(i);
		gdwTmuMaxAddress_0087EAE4[i] = gpfnGrTexMaxAddress_0087EB44(i);
		nTotal += gdwTmuMaxAddress_0087EAE4[i] - gdwTmuMinAddress_0087EAA4[i];
	}

	if ((float)nTotal < 3.5 * 1024 * 1024)
	{
		sub_00410610_WriteLogLine(gszInsufficientTextureMemory_006DD480);
		return 0;
	}

	unsigned int nAddress = gdwTmuMinAddress_0087EAA4[0];
	int nTmu = 0;
	if (gbFloorTiles_0087EFE8)
	{
		const unsigned int nMask2 = gnTexAlign_0087EFBC - 1;
		unsigned int nAlign1K = 0x400;
		if (nMask2 & 0x400)
		{
			nAlign1K = (nMask2 | 0x400) + 1;
		}
		unsigned int nAlign32K = 0x8000;
		if (nMask2 & 0x8000)
		{
			nAlign32K = (nMask2 | 0x8000) + 1;
		}

		nAddress += sub_0050B860_InitSpriteMemory(nAddress, gnTexAlign_0087EFBC);
		unsigned int nFree = gdwTmuMaxAddress_0087EAE4[0] - nAddress;
		unsigned int nEnd;
		if (gnTmuCount_0087EFB4 > 1)
		{
			unsigned int nFloorSize = 3 * nFree / 4;
			if (nFloorSize < 0x1CCCCC)
			{
				nFloorSize = 0x1CCCCC;
			}
			gnFloorCacheSize_007C90C8 = nFloorSize;
			nEnd = sub_0050F320_FloorCacheInit(&gFloorCache_0087EB68, nAddress, nFloorSize + nAddress, nAlign32K);
			gnTileCacheSize_007C90D4 = gdwTmuMaxAddress_0087EAE4[0] - nEnd;
			nEnd = sub_0050ED90_TileCacheInit(&gTileCache_0087EB48, nEnd, gdwTmuMaxAddress_0087EAE4[0], nAlign1K);
		}
		else
		{
			unsigned int nFloorSize = nFree / 2;
			if (nFree / 2 >= 0x300000)
			{
				nFloorSize = 0x300000;
			}
			unsigned int nTileSize = nFree / 4;
			if (nFree / 4 >= 0x100000)
			{
				nTileSize = 0x100000;
			}
			gnFloorCacheSize_007C90C8 = nFloorSize;
			nEnd = sub_0050F320_FloorCacheInit(&gFloorCache_0087EB68, nAddress, nFloorSize + nAddress, nAlign32K);
			gnTileCacheSize_007C90D4 = nTileSize;
			nEnd = sub_0050ED90_TileCacheInit(&gTileCache_0087EB48, nEnd, nTileSize + nEnd, nAlign1K);
		}

		if (gnTmuCount_0087EFB4 > 1)
		{
			nEnd = gdwTmuMinAddress_0087EAA4[1];
			nTmu = 1;
		}

		const unsigned int nStart = nEnd;
		const unsigned int nSize = gdwTmuMaxAddress_0087EAE4[nTmu] - nStart;
		nEnd = sub_0050E890_TexCacheInit(&gTexCache_0087F068, nStart, nStart + 25 * nSize / 100, nAlign64K);
		gnTexCacheSize_007C90E0 = gTexCache_0087F068.nEntries * nAlign64K;
		nEnd = sub_0050E890_TexCacheInit(&gTexCache_0087F088, nEnd, nStart + 65 * nSize / 100, nAlign16K);
		gnTexCacheSize_007C90E4 = gTexCache_0087F088.nEntries * nAlign16K;
		sub_0050E890_TexCacheInit(&gTexCache_0087F0A8, nEnd, gdwTmuMaxAddress_0087EAE4[nTmu], nAlign4K);
		gnTexCacheSize_007C90E8 = gTexCache_0087F0A8.nEntries * nAlign4K;
	}
	else if (gnScreenWidth_007C9138 == 800 && gnScreenHeight_007C913C == 600)
	{
		nAddress += sub_0050DFE0_GlideSetSmackTexAddresses(nAddress, gnTexAlign_0087EFBC);
		const unsigned int nFree = gdwTmuMaxAddress_0087EAE4[0] - nAddress;
		if (gnTmuCount_0087EFB4 > 1)
		{
			int nEnd = sub_0050E890_TexCacheInit(&gTexCache_0087F088, nAddress, nAddress + 50 * nFree / 100, nAlign16K);
			gnTexCacheSize_007C90E4 = gTexCache_0087F088.nEntries * nAlign16K;
			sub_0050E890_TexCacheInit(&gTexCache_0087F0A8, nEnd, gdwTmuMaxAddress_0087EAE4[0], nAlign4K);
			gnTexCacheSize_007C90E8 = gTexCache_0087F0A8.nEntries * nAlign4K;
			sub_0050E890_TexCacheInit(&gTexCache_0087F068, gdwTmuMinAddress_0087EAA4[1], gdwTmuMaxAddress_0087EAE4[1], nAlign64K);
			gnTexCacheSize_007C90E0 = gTexCache_0087F068.nEntries * nAlign64K;
		}
		else
		{
			int nEnd = sub_0050E890_TexCacheInit(&gTexCache_0087F068, nAddress, nAddress + 50 * nFree / 100, nAlign64K);
			gnTexCacheSize_007C90E0 = gTexCache_0087F068.nEntries * nAlign64K;
			nEnd = sub_0050E890_TexCacheInit(&gTexCache_0087F088, nEnd, nAddress + 75 * nFree / 100, nAlign16K);
			gnTexCacheSize_007C90E4 = gTexCache_0087F088.nEntries * nAlign16K;
			sub_0050E890_TexCacheInit(&gTexCache_0087F0A8, nEnd, gdwTmuMaxAddress_0087EAE4[0], nAlign4K);
			gnTexCacheSize_007C90E8 = gTexCache_0087F0A8.nEntries * nAlign4K;
		}
	}

	sub_0050B7B0_GlideInitSprites();
	sub_00604A30_StoreTileFreeHandler(sub_0050FCB0_GlideReleaseTileCache);
	return 1;
}

#include "gen/data/Source/D2Win/00509670_sub_00509670_InitTextureMemory.inc"

#include "D2Txt.h"

struct D2TxtLinkStrc;

extern "C" { void* gpMissCode; }                                                                          // 0x0096BC90
extern "C" int gnMissCodeSize;                                                                            // 0x0096BC94
extern "C" int gnMissCodeSizeEx;                                                                          // 0x0096BC98
extern "C" { D2MissilesTxt* gpMissilesTxt; }                                                              // 0x0096C794
extern "C" D2TxtLinkStrc* gpMissilesLinker;                                                                 // 0x0096C798
extern "C" { int gnMissilesTxtRecordCount; }                                                                       // 0x0096C79C
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);             // 0x0040B480
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0

static D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gnMissilesTxtRecordCount)
    {
        return &gpMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x00663210
void __fastcall DATATBLS_UnloadMissilesTxt()
{
    if (gpMissCode)
    {
        sub_0040B480(0, gpMissCode, ".\\DATATBLS\\MissileTbls.cpp", 414, 0);
        gpMissCode = 0;
    }
    gnMissCodeSize = 0;
    gnMissCodeSizeEx = 0;

    if (gpMissilesTxt)
    {
        DATATBLS_UnloadBin(gpMissilesTxt);
    }

    if (gpMissilesLinker)
    {
        FOG_FreeLinker(gpMissilesLinker);
    }
    gnMissilesTxtRecordCount = 0;
}

// 0x00663270
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (pMissilesTxtRecord)
    {
        return pMissilesTxtRecord->nVel + nLevel * pMissilesTxtRecord->nVelLev / 8;
    }

    return 0;
}

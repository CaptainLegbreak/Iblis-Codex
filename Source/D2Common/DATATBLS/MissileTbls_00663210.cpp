#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2TxtLinkStrc;

extern "C" D2DataTablesStrc gD2DataTables; // 0x0096BC30

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);             // 0x0040B480
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0

static D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < gD2DataTables.nMissilesTxtRecordCount)
    {
        return &gD2DataTables.pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x00663210
void __fastcall DATATBLS_UnloadMissilesTxt()
{
    if (gD2DataTables.pMissCode)
    {
        sub_0040B480(0, gD2DataTables.pMissCode, ".\\DATATBLS\\MissileTbls.cpp", 414, 0);
        gD2DataTables.pMissCode = 0;
    }
    gD2DataTables.nMissCodeSize = 0;
    gD2DataTables.nMissCodeSizeEx = 0;

    if (gD2DataTables.pMissilesTxt)
    {
        DATATBLS_UnloadBin(gD2DataTables.pMissilesTxt);
    }

    if (gD2DataTables.pMissilesLinker)
    {
        FOG_FreeLinker((D2TxtLinkStrc*)gD2DataTables.pMissilesLinker);
    }
    gD2DataTables.nMissilesTxtRecordCount = 0;
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

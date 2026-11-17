struct D2GameStrc { char unk00[0x1C]; void* pMemoryPool; char unk20[0x50]; int nGameType; };
struct D2MercDataStrc { unsigned short nName; unsigned short unk02; unsigned int unk04; int bHired; int unk0C; };
struct D2NpcRecordStrc { char unk00[0x10]; D2MercDataStrc* pMercData; char unk14[0xD]; unsigned char bInitialized; };
struct D2HirelingTxt { char unk000[8]; int dwClass; char unk00C[0x108]; unsigned short wNameFirst; unsigned short wNameLast; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" const char gszNpcSourceFile[]; // 0x006E15F0
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2HirelingTxt* __stdcall sub_006564D0_GetHirelingTxtRecord(int, int, int, int); // 0x006564D0
void __fastcall FOG_FreeServerMemory(void*, void*, const char*, int, int); // 0x0040B480
void __fastcall sub_00576070(D2GameStrc*, int, D2NpcRecordStrc*); // 0x00576070
static __forceinline int sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pRecord = sub_006564D0_GetHirelingTxtRecord(pGame->nGameType, nHirelingId, 0, 0);
    if (!pRecord) { *pNameFirst = 0; *pNameLast = 0; *pClass = 0; return -1; }
    *pNameFirst = pRecord->wNameFirst;
    *pNameLast = pRecord->wNameLast;
    if (pClass) *pClass = pRecord->dwClass;
    D2_ASSERT((*pNameLast - *pNameFirst + 1) != -1, 96);
    return (*pNameLast - *pNameFirst + 1);
}
// 0x00577010
void __fastcall sub_00577010_VendorRefresh(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord)
{
    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    int nAvailable = 0;
    int nFirst, nLast;
    const int nCount = sub_00575FF0(pGame, nVendorId, &nFirst, &nLast, 0);
    D2_ASSERT(nCount != -1, 0x632);
    for (int i = 0; i < nCount; ++i)
    {
        if (pMercData[i].unk0C && !pMercData[i].bHired) ++nAvailable;
    }
    if (!nAvailable)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pNpcRecord->pMercData, gszNpcSourceFile, 0x63D, 0);
        pNpcRecord->pMercData = 0;
        pNpcRecord->bInitialized = 0;
        sub_00576070(pGame, nVendorId, pNpcRecord);
    }
}

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ItemsTxt { char unk[0x1A8]; };
struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };

extern D2ItemDataTbl gItemDataTables;                                                                       // 0x0096CA58

// 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId)
{
    if ((unsigned int)nItemId >= (unsigned int)gItemDataTables.nItemsTxtRecordCount)
        return 0;

    D2_ASSERT(gItemDataTables.pItemsTxt, 0x1EF);
    return &gItemDataTables.pItemsTxt[nItemId];
}

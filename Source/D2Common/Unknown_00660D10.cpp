#include "D2ClientTypes.h"
#include "D2TxtItems.h"

extern D2BeltsTxt* sgptBeltInitStats; // 0x0096D4F8
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#define BELTS_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static D2BeltsTxt* sub_00660C70(int nIndex)
{
    BELTS_ASSERT(sgptBeltInitStats, 121);
    D2BeltsTxt* pRecord = &sgptBeltInitStats[nIndex];
    BELTS_ASSERT(pRecord, 122);
    return pRecord;
}

// 0x00660D10
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2InvRectStrc* pInvRect, int nBoxId)
{
    D2BeltsTxt* pBeltsTxtRecord = sub_00660C70(nIndex + 7 * static_cast<const volatile int&>(bHigherRes));
    const D2InvRectStrc* pBoxStats = &pBeltsTxtRecord->beltBoxes[nBoxId];
    BELTS_ASSERT(pBoxStats, 143);

    pInvRect->nLeft = pBoxStats->nLeft;
    pInvRect->nRight = pBoxStats->nRight;
    pInvRect->nTop = pBoxStats->nTop;
    pInvRect->nBottom = pBoxStats->nBottom;
}

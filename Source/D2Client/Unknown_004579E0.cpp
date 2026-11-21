#include "D2ClientUi.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static void sub_00457860_PivotNext(D2AutomapCellStrc** ppNode)
{
    D2AutomapCellStrc* pNode = *ppNode;
    D2_ASSERT(pNode, 0x233);
    D2AutomapCellStrc* pNext = pNode->pNext;
    D2_ASSERT(pNext, 0x234);
    pNode->pNext = pNext->pPrev;
    pNext->pPrev = pNode;
    *ppNode = pNext;
}

static void sub_004578B0_PivotPrev(D2AutomapCellStrc** ppNode);

// 0x004578B0
static void sub_004578B0_PivotPrev(D2AutomapCellStrc** ppNode)
{
    D2AutomapCellStrc* pNode = *ppNode;
    D2_ASSERT(pNode, 0x244);
    D2AutomapCellStrc* pPrev = pNode->pPrev;
    D2_ASSERT(pPrev, 0x245);
    pNode->pPrev = pPrev->pNext;
    pPrev->pNext = pNode;
    *ppNode = pPrev;
}

// 0x004579E0
void __stdcall sub_004579E0_RotateRightHeavy(D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pNode = *ppRoot;
    D2AutomapCellStrc* pNext = pNode->pNext;
    D2_ASSERT(pNext->wWeight == -1 || pNext->wWeight == 1, 0x294);
    if (pNext->wWeight == 1)
    {
        pNode->wWeight = 0;
        pNext->wWeight = 0;
        sub_00457860_PivotNext(&pNode);
    }
    else
    {
        D2AutomapCellStrc* pNextPrev = pNext->pPrev;
        switch (pNextPrev->wWeight)
        {
        case -1:
            pNode->wWeight = 0;
            pNext->wWeight = 1;
            break;
        case 0:
            pNode->wWeight = 0;
            pNext->wWeight = 0;
            break;
        case 1:
            pNode->wWeight = -1;
            pNext->wWeight = 0;
            break;
        }
        pNextPrev->wWeight = 0;
        sub_004578B0_PivotPrev(&pNode->pNext);
        sub_00457860_PivotNext(&pNode);
    }
    *ppRoot = pNode;
}

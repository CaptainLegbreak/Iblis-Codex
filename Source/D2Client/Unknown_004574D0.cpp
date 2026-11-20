#include "D2Client.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2AutomapCellStrc;

extern int gnAutomapBaseY_007A518C; // 0x007A518C
extern int gdwGlobal_007A5150; // 0x007A5150
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnMiniMapX_007A51DC; // 0x007A51DC
extern int gnMiniMapY_007A51D8; // 0x007A51D8
void __cdecl sub_00457520_UpdateAutomapLayout(); // 0x00457520

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x004574D0
void __stdcall sub_004574D0_AutomapBaseYAddStep(int nUnused)
{
    gnAutomapBaseY_007A518C += 0x10;
}

int gnAutomapBaseX_007A5188; // 0x007A5188

int gnAutomapBaseY_007A518C; // 0x007A518C

// 0x004574E0
void __stdcall sub_004574E0_AutomapBaseYSubStep(int nUnused)
{
    gnAutomapBaseY_007A518C -= 0x10;
}

// 0x004574F0
void __stdcall sub_004574F0_AutomapBaseXSubStep(int nUnused)
{
    gnAutomapBaseX_007A5188 -= 0x10;
}

// 0x00457500
void __stdcall sub_00457500_AutomapBaseXAddStep(int nUnused)
{
    gnAutomapBaseX_007A5188 += 0x10;
}

// 0x00457640
void __fastcall sub_00457640(int bForce)
{
    if (!gdwGlobal_007113E0 && !bForce)
    {
        return;
    }

    sub_00457520_UpdateAutomapLayout();
    switch (gdwGlobal_007A5150)
    {
    case 1:
        gnAutomapBaseX_007A5188 = gnGlobal_0071146C / 3 - gnMiniMapX_007A51DC - 0x10;
        gnAutomapBaseY_007A518C = gnGlobal_00711470 / 3 - gnMiniMapY_007A51D8 - 0x10;
        break;
    default:
        gnAutomapBaseX_007A5188 = 0;
        gnAutomapBaseY_007A518C = 0;
        break;
    }
}

// 0x00457860
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

void __stdcall sub_00457900_RotateLeftHeavy(D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pNode = *ppRoot;
    D2AutomapCellStrc* pPrev = pNode->pPrev;
    D2_ASSERT(pPrev->wWeight == -1 || pPrev->wWeight == 1, 0x259);
    if (pPrev->wWeight == -1)
    {
        pNode->wWeight = 0;
        pPrev->wWeight = 0;
        sub_004578B0_PivotPrev(&pNode);
        *ppRoot = pNode;
    }
    else
    {
        D2AutomapCellStrc* pPrevNext = pPrev->pNext;
        switch (pPrevNext->wWeight)
        {
        case -1:
            pNode->wWeight = 1;
            pPrev->wWeight = 0;
            break;
        case 0:
            pNode->wWeight = 0;
            pPrev->wWeight = 0;
            break;
        case 1:
            pNode->wWeight = 0;
            pPrev->wWeight = -1;
            break;
        }
        pPrevNext->wWeight = 0;
        sub_00457860_PivotNext(&pNode->pPrev);
        sub_004578B0_PivotPrev(&pNode);
        *ppRoot = pNode;
    }
}

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
        *ppRoot = pNode;
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
        *ppRoot = pNode;
    }
}

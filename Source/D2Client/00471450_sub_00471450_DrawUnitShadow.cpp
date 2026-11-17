struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xBC];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2ObjectsTxt
{
    char unk0x00[0x118];
    unsigned char nBlocksLight[8];
    char unk0x120[0x28];
    int dwXOffset;
    int dwYOffset;
    unsigned char nDraw;
};

struct D2CelStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

#define UNIT_OBJECT 2
#define UNIT_INVALID 6

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall sub_004DA110_GetUnitGfxShiftX(D2UnitStrc* pUnit);                                             // 0x004DA110
int __stdcall sub_004DA130_GetUnitGfxShiftY(D2UnitStrc* pUnit);                                             // 0x004DA130
void __stdcall sub_004F6540(D2CelContextStrc* pContext, int nX, int nY);                         // 0x004F6540
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2);           // 0x004709A0
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
int __fastcall sub_004DBB50_InitCelContext(D2CelContextStrc* pContext, D2UnitStrc* pUnit, int a3, int nDirection, int nFrame, int* pOut, int a7, int a8); // 0x004DBB50

inline int UNITS_IsFlag5SetInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 5) & 1;
}

// 0x00471450
int __fastcall sub_00471450_DrawUnitShadow(D2UnitStrc* pUnit)
{
    if (UNITS_IsFlag5SetInl(pUnit) || STATES_CheckState(pUnit, 0x92))
    {
        return 0;
    }

    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x86F);
    int bPerspective = sub_004F51D0_IsPerspective();
    int nOffsetX = 0;
    int nOffsetY = 0;
    if (nType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClass);
        D2_ASSERT(pObjectsTxtRecord, 0x87A);
        if (!pObjectsTxtRecord->nDraw || !pObjectsTxtRecord->nBlocksLight[nMode])
        {
            return 0;
        }
        nOffsetX = pObjectsTxtRecord->dwXOffset;
        nOffsetY = pObjectsTxtRecord->dwYOffset;
    }
    int nX = nOffsetX - sub_0045AFC0() + UNITS_GetClientCoordX(pUnit) + sub_004DA110_GetUnitGfxShiftX(pUnit);
    int nY = nOffsetY - sub_0045AFD0_GetMouseYOffset() + UNITS_GetClientCoordY(pUnit) + sub_004DA130_GetUnitGfxShiftY(pUnit);
    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nX += -(gnGlobal_0071146C / 4);
            break;
        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
        nY += 16;
    }
    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 1))
    {
        return 0;
    }
    unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    sub_004F6540(&tContext, nX, nY);
    return 1;
}

#include "D2DDraw.h"

struct D2PlayerDataStrc;
struct D2TextHeaderStrc;
struct D2SetsTxt { char unk0x000[0x128]; };
struct D2SetItemsTxt { char unk0x000[0x1B8]; };
struct D2UniqueItemsTxt { char unk0x000[0x14C]; };

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
    char unk0x18[0x4C];
    void* pLight;
    char unk0x68[0x5C];
    unsigned int dwFlags;
};

struct D2DataTablesStrc
{
    char unk0x000[0xC0C];
    D2SetsTxt* pSetsTxt;
    int nSetsTxtRecordCount;
    char unk0xC14[0x4];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
    char unk0xC20[0x4];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};
#pragma pack(pop)

enum
{
    NUM_HOTKEYS = 114,
};

typedef void (__cdecl* D2WheelCallbackFn)();
typedef int (__stdcall* D2FarProcFn)();
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);                              // 0x006CC34C
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
void __cdecl sub_0049F960_ResetTextBox();                                                                   // 0x0049F960
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader);                                          // 0x006612A0
void __stdcall sub_00416710_Unlock(void* pHandle);                                                          // 0x00416710
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2WheelCallbackFn gpfnWheelUp_007A7404;                                                              // 0x007A7404
extern D2WheelCallbackFn gpfnWheelDown_007A7408;                                                            // 0x007A7408
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90
extern D2UnitStrc* gpAiTargets_007A7470[];                                                                  // 0x007A7470
extern unsigned char gabColors_007BCAD8[5];                                                                 // 0x007BCAD8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern int gnGlobal_007BCE2C;                                                                               // 0x007BCE2C
extern int gnGlobal_00721E34;                                                                               // 0x00721E34
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gnGlobal_00721E4C;                                                                               // 0x00721E4C
extern int gnGlobal_00721E50;                                                                               // 0x00721E50
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4
extern int gdwGlobal_007BCBF8;                                                                              // 0x007BCBF8
extern int gnGlobal_007BF1FA;                                                                               // 0x007BF1FA
extern D2TextHeaderStrc* gpTextHeader_007BF250;                                                             // 0x007BF250
extern int gnGlobal_007C0E7C;                                                                               // 0x007C0E7C
unsigned char* gpDDrawDebugFontGlyphs_008815AC;                                                             // 0x008815AC
extern void* gpReply_008818D0;                                                                              // 0x008818D0
extern "C" void* gpCDKeyHandle_00882744;                                                                    // 0x00882744
extern "C" void* gpCDKeyHandle_00882750;                                                                    // 0x00882750

// 0x00464810
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// 0x00464820
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case 0:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case 1:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00464930
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

// 0x004693B0
void __fastcall sub_004693B0(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp_007A7404)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp_007A7404), 0x383);
            gpfnWheelUp_007A7404();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown_007A7408)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown_007A7408), 0x38B);
            gpfnWheelDown_007A7408();
        }
    }
}

// 0x00469AA0
unsigned short __fastcall sub_00469AA0(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469D70
void __fastcall sub_00469D70(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// 0x00469D90
int __fastcall sub_00469D90(int nA, int nB)
{
    return sub_00469AA0(nA, nB) != 0xFFFF;
}

// 0x0046D750
void __cdecl sub_0046D750()
{
    for (int i = 0; i < 8; ++i)
    {
        gpAiTargets_007A7470[i] = 0;
    }
}

// 0x00483410
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// 0x00483440
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483470
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483960
void __cdecl sub_00483960()
{
    gabColors_007BCAD8[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabColors_007BCAD8[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabColors_007BCAD8[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabColors_007BCAD8[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = D2Win_10034_MixRGB(0x80, 0x40, 0x40);
}

// 0x00489840
int __cdecl sub_00489840_IsNpcState123()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3)
    {
        return 1;
    }

    return 0;
}

// 0x004898A0
void __fastcall sub_004898A0(int nMode)
{
    gnGlobal_007BCE2C = 1;
    if (gdwGlobal_007BCBF0 == 13)
    {
        gdwGlobal_007BCBF0 = 12;
    }

    sub_00455F20(5, 1, 0);
}

// 0x004898D0
void __fastcall sub_004898D0(int nState)
{
    gnGlobal_00721E34 = nState;
    if (nState == 0)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x004A1730
void __cdecl sub_004A1730_ClearPanel()
{
    sub_0049F960_ResetTextBox();
    gnGlobal_007BF1FA = 0;
    if (gpTextHeader_007BF250)
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

// 0x004B8A10
int __cdecl sub_004B8A10()
{
    if (gnGlobal_007C0E7C == 1 || gnGlobal_007C0E7C == 2)
    {
        return 1;
    }

    return 0;
}

// 0x005125B0
void __cdecl sub_005125B0_DDrawFreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs_008815AC)
    {
        FOG_Free(gpDDrawDebugFontGlyphs_008815AC, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs_008815AC = 0;
    }
}

// 0x0051B210
void __cdecl sub_0051B210_FreeBuffer()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

// 0x005239C0
void __cdecl sub_005239C0_UnlockCDKeys()
{
    if (gpCDKeyHandle_00882744)
    {
        sub_00416710_Unlock(gpCDKeyHandle_00882744);
        gpCDKeyHandle_00882744 = 0;
    }

    if (gpCDKeyHandle_00882750)
    {
        sub_00416710_Unlock(gpCDKeyHandle_00882750);
        gpCDKeyHandle_00882750 = 0;
    }
}

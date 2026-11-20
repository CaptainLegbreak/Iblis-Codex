#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"




struct D2SkillsTxt
{
    char unk0x00[0x06];
    unsigned char nFlags6;
    unsigned char nFlags7;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
    char unk0x10[0x4C - 0x10];
    unsigned char nAlign;
};

struct D2MonStats2Txt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
int gdwGlobal_007A6A98;                                                                                     // 0x007A6A98
extern int gdwGlobal_007A6A94;                                                                              // 0x007A6A94
extern int gnSelectedUnitType_007A6A8C;                                                                     // 0x007A6A8C
extern unsigned int gnSelectedUnitId_007A6A78;                                                              // 0x007A6A78
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gbSelectionRectValid_007A6A9C;                                                                   // 0x007A6A9C
extern int gnSelectionLeft_007A6A7C;                                                                        // 0x007A6A7C
extern int gnSelectionRight_007A6A84;                                                                       // 0x007A6A84
extern int gnSelectionTop_007A6A80;                                                                         // 0x007A6A80
extern int gnSelectionBottom_007A6A88;                                                                      // 0x007A6A88
extern int gdwGlobal_007A6AA0;                                                                              // 0x007A6AA0

int __cdecl sub_004A0000();                                                                                 // 0x004A0000
D2UnitStrc* __cdecl sub_0049E8B0_GetTextUnit();                                                             // 0x0049E8B0
void __fastcall sub_0049DA30(D2UnitStrc* pUnit);                                                            // 0x0049DA30
void __cdecl sub_0049DA50_ClearFlag();                                                                      // 0x0049DA50
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall sub_00475FF0_SetViewDirty(D2ViewStrc* pView);                                               // 0x00475FF0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

static void sub_00466DE0_SetHoverUnit(D2UnitStrc* pUnit)
{
    char szBuffer[0x200];

    if (gdwGlobal_007A6A98)
    {
        return;
    }

    if (sub_004A0000() && sub_0049E8B0_GetTextUnit() == pUnit)
    {
        sub_0049DA30(pUnit);
        return;
    }

    sub_0049DA50_ClearFlag();

    int bSame = 0;
    if (pUnit)
    {
        D2_ASSERT(sub_00466870(pUnit, 0, 0, 0), 0x4F);
        const int nUnitType = pUnit->dwUnitType;
        const unsigned int nUnitId = pUnit->dwUnitId;
        if (gdwGlobal_007A6A94 && nUnitType == gnSelectedUnitType_007A6A8C && nUnitId == gnSelectedUnitId_007A6A78)
        {
            bSame = 1;
        }
    }

    if (!bSame && gdwGlobal_007A6A94 && gnSelectedUnitType_007A6A8C == 5)
    {
        D2UnitStrc* pOld = sub_00463990(gnSelectedUnitId_007A6A78, 5);
        if (pOld)
        {
            DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), pOld->dwClassId);
            sub_00475FF0_SetViewDirty(gpView_007A0640);
        }
    }

    if (!pUnit)
    {
        gdwGlobal_007A6A94 = 0;
        return;
    }

    gnSelectedUnitType_007A6A8C = pUnit->dwUnitType;
    gnSelectedUnitId_007A6A78 = pUnit->dwUnitId;
    gdwGlobal_007A6A94 = 1;

    switch (pUnit->dwUnitType)
    {
    case 5:
        if (!bSame)
        {
            DUNGEON_UpdateWarpRoomSelect(UNITS_GetRoom(pUnit), pUnit->dwClassId);
            sub_00475FF0_SetViewDirty(gpView_007A0640);
        }
        break;

    case 2:
        if (UNITS_IsDoor(pUnit) && pUnit->dwAnimMode != 4)
        {
            const unsigned int dwNow = GetTickCount();
            if (dwNow - pUnit->dwTickCount > 0x1F4)
            {
                sprintf(szBuffer, "msg at %d\n", dwNow);
                OutputDebugStringA(szBuffer);
                pUnit->dwTickCount = dwNow;
                sub_00478680_SendPacket5(0x3D, gnSelectedUnitId_007A6A78);
            }
        }
        break;

    case 1:
        if (!bSame)
        {
            const int nClassId = pUnit->dwClassId;
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pMonStatsTxtRecord)
            {
                D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
                if (pMonStats2TxtRecord
                    && !(pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[0])
                    && pMonStatsTxtRecord->nAlign != 1
                    && (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[1]))
                {
                    if (!(pMonStats2TxtRecord->nFlags[2] & gdwBitMasks[1]))
                    {
                        gdwGlobal_00711F94 = nClassId;
                    }
                    gdwGlobal_00711F90 = nClassId;
                }
            }
        }
        break;
    }
}

// 0x00467A70
void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (sub_00466870(pUnit, 0, 0, 0))
        {
            gdwGlobal_007A6A98 = 0;
            sub_00466DE0_SetHoverUnit(pUnit);
            gdwGlobal_007A6A98 = 1;
        }
        else
        {
            gdwGlobal_007A6A98 = 0;
            gdwGlobal_007A6A94 = 0;
        }
    }
    else
    {
        gdwGlobal_007A6A94 = 0;
        gdwGlobal_007A6A98 = 1;
    }
}

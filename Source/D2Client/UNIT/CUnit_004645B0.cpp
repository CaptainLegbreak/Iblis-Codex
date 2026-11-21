#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2PlayerModes.h"

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
struct D2SkillsTxt;
struct Unicode;
struct D2KeyConfigFileStrc;
struct D2StaticPathStrc;
struct D2RectStrc;
struct D2CoordPairStrc;
struct D2MonStats2SelectStrc;



D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
// 0x004645B0
static int __stdcall sub_004645B0_CheckSkillFrame(int nUnused, D2UnitStrc* pUnit);


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId); // 0x00479150

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    union
    {
        int dwPrecisionX;
        struct
        {
            unsigned short wOffsetX;
            unsigned short wPosX;
        };
    };
    union
    {
        int dwPrecisionY;
        struct
        {
            unsigned short wOffsetY;
            unsigned short wPosY;
        };
    };
    int dwTargetX;
    int dwTargetY;
    D2PathPointStrc tSP1;
    D2PathPointStrc tSP2;
    D2PathPointStrc tSP3;
    D2ActiveRoomStrc* pRoom;
    D2ActiveRoomStrc* pRoomNext;
    int unk0x24;
    int dwPathPoints;
    int unk0x2C;
    void* pUnit;
    int dwFlags;
    int unk0x38;
    int eType;
    int ePrevType;
    int dwUnitSize;
    char unk0x48[0x14];
    int dwTargetType;
    int dwTargetId;
    unsigned char unk0x64[3];
    unsigned char nDist;
    unsigned char bDistMax;
    unsigned char unk0x69;
    D2PathPointStrc tPrevPoint;
    D2PathPointStrc tNextPoint;
    char unk0x72[0x0A];
    int dwVelocity;
    int unk0x80;
    int dwVelocity2;
    int unk0x88;
    int unk0x8C;
    unsigned char unk0x90;
    unsigned char nStepNum;
    unsigned char nSteps;
    unsigned char unk0x93;
    unsigned char unk0x94;
    char unk0x95[3];
    int unk0x98;
    D2PathPointStrc PathPoints[78];
    int nSavedSteps;
    D2PathPointStrc SavedSteps[7];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2UnitStrc* __stdcall sub_00534650_GetServerUnitFromFirstGame(int nUnitType, int nUnitId); // 0x00534650
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20
int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pPath); // 0x00648770
void __stdcall sub_00648750(D2DynamicPathStrc* pPath, int nArg); // 0x00648750
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

struct Unicode
{
    unsigned short wChar;
};

struct D2KeyConfigFileStrc
{
    unsigned short wTag;
    unsigned short wVersion;
    unsigned short wSize;
    unsigned char aBody[0x474];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int a2, int a3); // 0x00619DA0
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
extern D2UnitStrc* gpPlayerUnit_007A6A70; // 0x007A6A70
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
extern int gnTimerEnd_007A7464; // 0x007A7464
extern int gnGlobal_0071146C; // 0x0071146C
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_00464EC0_CheckSkillOwner(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464EC0
int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2); // 0x0047A4F0
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x000[0x0C];
    D2CoordStrc tGameCoords;
};


int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __fastcall sub_004DAE60_UnitSupportsMode(D2UnitStrc* pUnit, int nMode); // 0x004DAE60
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit); // 0x004DA0D0
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit); // 0x004DA0F0
extern "C" void* __cdecl memmove(void*, const void*, unsigned int); // 0x00683840
static int __stdcall sub_004640A0_GetUnitSelectRect(D2UnitStrc* pUnit, int nMode, D2RectStrc* pRect, unsigned int nFrame); // 0x004640A0

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[]; // 0x00711F34

extern "C" __declspec(dllimport) int __stdcall PtInRect(const D2RectStrc*, D2CoordPairStrc);
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_00451F30(D2UnitStrc*,unsigned int); // 0x00451F30
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc*); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*,int*,int*,int*,const char*,int); // 0x00645270
D2MonStats2SelectStrc* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
int __fastcall sub_00470860_HitTestUnitGfx(D2UnitStrc*,int,int,int,int); // 0x00470860
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00463EE0_IsPointInTileRect(D2UnitStrc*,int,int); // 0x00463EE0
int __fastcall sub_004DB670_UpdateUnitGfx(D2UnitStrc*,int); // 0x004DB670

static int __stdcall sub_004645B0_CheckSkillFrame(int nUnused, D2UnitStrc* pUnit)
{
    int* pDead = &nUnused;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAnim != 0x12)
    {
        return 1;
    }

    const unsigned char nFrame = pSkillsTxtRecord->nSeqInput;
    if (!nFrame)
    {
        return 0;
    }

    if (nFrame == 0xFF)
    {
        return 0;
    }

    return (pUnit->dwSeqFrame >> 8) >= nFrame;
}

int __fastcall sub_Emit_004645B0(D2UnitStrc* pUnit, int nArg)
{
    return sub_004645B0_CheckSkillFrame(nArg, pUnit);
}

static inline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int SKILLCLT_HasFlag26(D2SkillStrc* pSkill, int nLine)
{
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\CUnit.cpp", nLine));
        if (pSkillsTxtRecord && BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00464F70
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    int bLeft = 0;
    if (pUnit && pTarget)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (!nUnitType || !pTarget->dwUnitType || pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
            if (pLeftSkill)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\CUnit.cpp", 2943));
                if (pSkillsTxtRecord && BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26))
                {
                    bLeft = 1;
                }
            }
            if (SKILLCLT_HasFlag26(UNITS_GetRightSkill(pUnit), 2952) || bLeft)
            {
                int nTargetId = pTarget->dwUnitId;
                if (pTarget->dwUnitType != UNIT_MONSTER || (nTargetId = sub_00479150_FindRosterIndex(nTargetId)) != -1)
                {
                    return sub_0047A520(pUnit->dwUnitId, nTargetId) != 0;
                }
            }
        }
    }
    return 0;
}

// 0x00465070
void __fastcall sub_00465070_OnUnitC(D2UnitStrc* pUnit)
{
    D2_ASSERT(!gdwGlobal_007A0610, 0xBAA);

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    D2UnitStrc* pServerUnit = sub_00534650_GetServerUnitFromFirstGame(nUnitType, nUnitId);
    if (!pServerUnit)
        return;

    D2DynamicPathStrc* pSrc = pServerUnit->pDynamicPath;
    D2DynamicPathStrc* pDst = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    const int nX = pSrc->wPosX;
    const int nY = pSrc->wPosY;
    if (nX != pDst->wPosX || nY != pDst->wPosY)
    {
        if (!COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY))
            return;

        D2Common_10231(pDst, pUnit, pRoom, nX, nY);
    }

    pDst->dwPrecisionX = pSrc->dwPrecisionX;
    pDst->dwPrecisionY = pSrc->dwPrecisionY;
    pDst->dwTargetX = pSrc->dwTargetX;
    pDst->dwTargetY = pSrc->dwTargetY;
    pDst->unk0x24 = pSrc->unk0x24;
    pDst->dwPathPoints = pSrc->dwPathPoints;
    pDst->unk0x38 = pSrc->unk0x38;
    pDst->tSP1 = pSrc->tSP1;
    pDst->tSP2 = pSrc->tSP2;
    pDst->tSP3 = pSrc->tSP3;
    pDst->dwTargetType = pSrc->dwTargetType;
    pDst->dwTargetId = pSrc->dwTargetId;
    pDst->nDist = pSrc->nDist;
    pDst->bDistMax = pSrc->bDistMax;
    pDst->dwVelocity = pSrc->dwVelocity;
    pDst->unk0x80 = pSrc->unk0x80;
    pDst->dwVelocity2 = pSrc->dwVelocity2;
    pDst->unk0x88 = pSrc->unk0x88;
    pDst->unk0x8C = pSrc->unk0x8C;
    pDst->nStepNum = pSrc->nStepNum;
    pDst->nSteps = pSrc->nSteps;
    pDst->unk0x93 = pSrc->unk0x93;
    pDst->unk0x94 = pSrc->unk0x94;
    pDst->unk0x98 = pSrc->unk0x98;
    pDst->tPrevPoint = pSrc->tPrevPoint;
    pDst->tNextPoint = pSrc->tNextPoint;

    if (pSrc->dwPathPoints)
        memcpy(pDst->PathPoints, pSrc->PathPoints, pSrc->dwPathPoints * sizeof(D2PathPointStrc));

    if (pSrc->nSavedSteps)
        memcpy(pDst->SavedSteps, pSrc->SavedSteps, pSrc->nSavedSteps * sizeof(D2PathPointStrc));

    pDst->nSavedSteps = pSrc->nSavedSteps;

    if (pSrc->eType != 8 && pSrc->eType != 11)
        pDst->eType = pSrc->eType;

    if (pSrc->ePrevType != 8 && pSrc->ePrevType != 11)
        pDst->ePrevType = pSrc->ePrevType;

    pDst->ePrevType = pSrc->ePrevType;
    pDst->dwUnitSize = pSrc->dwUnitSize;
    sub_00648750(pDst, D2COMMON_10209_PathCheckPathingFlag(pSrc));

    const unsigned int nMode = pUnit->dwAnimMode;
    const unsigned int nServerMode = pServerUnit->dwAnimMode;
    if (nMode != nServerMode)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            switch (!pServerUnit ? 0u : pServerUnit->dwAnimMode)
            {
            case 2:
            case 6:
                switch (nMode)
                {
                case 1:
                case 5:
                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                        UNITS_ChangeAnimMode(pUnit, 6);
                    else
                        UNITS_ChangeAnimMode(pUnit, 2);
                    break;
                }
                break;

            case 3:
                switch (nMode)
                {
                case 1:
                case 3:
                case 5:
                    UNITS_ChangeAnimMode(pUnit, 3);
                    break;
                }
                break;

            case 1:
            case 5:
                switch (nMode)
                {
                case 2:
                case 3:
                case 6:
                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                        UNITS_ChangeAnimMode(pUnit, 5);
                    else
                        UNITS_ChangeAnimMode(pUnit, 1);
                    break;
                }
                break;

            case 18:
                break;

            default:
                if (nMode != 19)
                {
                    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
                    D2SkillStrc* pServerSkill = UNITS_GetUsedSkill(pServerUnit);
                    if (!pSkill)
                        break;

                    if (pServerSkill && (SKILLS_GetFlags(pServerSkill) & 1) && !(SKILLS_GetFlags(pServerSkill) & 2))
                        break;

                    const int nFlags = SKILLS_GetFlags(pSkill);
                    if (!(nFlags & 1))
                        break;

                    SKILLS_SetFlags(pSkill, nFlags | 2);
                    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
                    return;
                }

                UNITS_ChangeAnimMode(pUnit, nServerMode);
                break;
            }
            break;

        case UNIT_MONSTER:
            switch (nServerMode)
            {
            case 1:
                switch (nMode)
                {
                case 2:
                case 15:
                    UNITS_ChangeAnimMode(pUnit, 1);
                    break;
                }
                break;

            case 2:
                switch (nMode)
                {
                case 1:
                    UNITS_ChangeAnimMode(pUnit, 2);
                    break;
                }
                break;

            case 15:
                switch (nMode)
                {
                case 1:
                    UNITS_ChangeAnimMode(pUnit, 15);
                    break;
                }
                break;
            }
            break;
        }
    }

    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
}

// 0x00465420
D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomBySubtile(int nX, int nY)
{
    char szMessage[0x200];
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    D2ActiveRoomStrc* pRoom = 0;
    if (!nX && !nY)
        return 0;
    if (pPlayer)
    {
        pRoom = UNITS_GetRoom(pPlayer);
        D2ActiveRoomStrc* pFound = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
        if (pFound)
            return pFound;
    }
    D2ActiveRoomStrc* pFound = sub_00619DA0_ActLookup(gpGlobal_007A0634, nX, nY);
    if (pFound)
        return pFound;
    SStrPrintf(szMessage, sizeof(szMessage), "Unable to find room for unit...  hControlUnit:%8x  hUnitRoom:%8x  ghAct:%8x  nX:%d  nY:%d", pPlayer, pRoom, gpGlobal_007A0634, nX, nY);
    D2_ASSERT(0, 0x13C);
}

// 0x0046C060
void __cdecl sub_0046C060_DrawCountdown()
{
    Unicode wszText[256];
    const int nNow = sub_00410A80_GetTime();
    if (!gnTimerEnd_007A7464 || gnTimerEnd_007A7464 <= nNow)
        return;
    D2UnitStrc* pUnit = sub_00463990(gnTimerUnitId_007129D4, 1);
    if (pUnit && pUnit->dwAnimMode != 12 && gnTimerEnd_007A7464 - 0x46 > nNow)
        return;
    for (int i = 0; i < 256; ++i)
        wszText[i].wChar = 0;
    sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x13E9), gnTimerEnd_007A7464 - nNow);
    const int nOldFont = sub_00502EF0(13);
    const int nWidth = sub_00501820(wszText);
    sub_00502320(wszText, gnGlobal_0071146C / 2 - nWidth / 2, 0x177, 9, 1);
    sub_00502EF0(nOldFont);
}

#include "gen/data/Source/D2Client/UNIT/CUnit_004645B0.inc"
struct D2ActiveRoomStrc;
struct D2UnitStrc;

static inline int UNITS_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00465C60
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    int nUnitType;
    int nUnitId;
    if (!pUnit)
    {
        nUnitType = 6;
        nUnitId = -1;
    }
    else
    {
        nUnitType = pUnit->dwUnitType;
        nUnitId = pUnit->dwUnitId;
    }

    int nOtherType = !pOther ? 6 : pOther->dwUnitType;
    int nOtherId = !pOther ? -1 : pOther->dwUnitId;

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if ((!pOther ? 6 : pOther->dwUnitType) == 0 && UNITS_IsDeadOrDying(pOther) && !sub_0047A4F0_TestFlag1(nUnitId, pOther->dwUnitId))
        {
            return 0;
        }

        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pOther && pOther->dwUnitType == UNIT_MONSTER
            && sub_00479150_FindRosterIndex(pOther->dwUnitId) != -1 && !sub_00464EC0_CheckSkillOwner(pUnit, pOther))
        {
            return 0;
        }

        return 1;
    }

    if (nUnitType == 1)
    {
        const int nOwnerId = sub_00479150_FindRosterIndex(nUnitId);
        if (nOwnerId != -1)
        {
            nUnitType = 0;
            nUnitId = nOwnerId;
        }

        int bUnitOwned = 0;
        if (pUnit)
        {
            bUnitOwned = (pUnit->dwFlagEx >> 10) & 1;
        }

        if (bUnitOwned && !pOther->dwOwnerType)
        {
            nUnitType = 0;
            nUnitId = pUnit->dwOwnerGUID;
        }
    }

    if (nOtherType == 1)
    {
        const int nOwnerId = sub_00479150_FindRosterIndex(nOtherId);
        if (nOwnerId != -1)
        {
            nOtherType = 0;
            nOtherId = nOwnerId;
        }

        int bOtherOwned = 0;
        if (pOther)
        {
            bOtherOwned = (pOther->dwFlagEx >> 10) & 1;
        }

        if (bOtherOwned && !pOther->dwOwnerType)
        {
            nOtherId = pOther->dwOwnerGUID;
            nOtherType = 0;
        }
    }

    if (nUnitType == nOtherType && nUnitId == nOtherId)
    {
        return 0;
    }

    if (nUnitType == 0 && nOtherType == 0)
    {
        if (pOther && pOther->dwUnitType == UNIT_PLAYER && sub_00464820_IsDeadOrDying(pOther) && sub_0047A4F0_TestFlag1(nUnitId, pOther->dwUnitId))
        {
            return 1;
        }

        return sub_004DC440(nUnitId, nOtherId, 8);
    }

    if (nOtherType == 1)
    {
        if (sub_004638A0_CheckMonStats2Flag(!pOther ? -1 : pOther->dwClassId, 4))
        {
            return 1;
        }

        if (sub_004638A0_CheckMonStats2Flag(!pOther ? -1 : pOther->dwClassId, 5))
        {
            return 0;
        }
    }

    if (nUnitType == 0 && (nOtherType == 4 || nOtherType == 2))
    {
        return 1;
    }

    return !STATLIST_AreUnitsAligned(pUnit, pOther);
}

// build: context UNITS_InlineGetXPosition
inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// build: context UNITS_InlineGetYPosition
inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00463FE0
static int __stdcall sub_00463FE0_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, D2UnitStrc* pUnit, int nX)
{
    int nUnitX = UNITS_InlineGetXPosition(pUnit);
    int nUnitY = UNITS_InlineGetYPosition(pUnit);
    sub_00643260(&nUnitX, &nUnitY);

    const int nLeft = pObjectsTxtRecord->dwLeft + nUnitX;
    const int nTop = pObjectsTxtRecord->dwTop + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= pObjectsTxtRecord->dwWidth + nLeft && nY <= pObjectsTxtRecord->dwHeight + nTop)
    {
        return 1;
    }

    return 0;
}

// build: context sub_004640A0_GetUnitSelectRect
static int __stdcall sub_004640A0_GetUnitSelectRect(D2UnitStrc* pUnit, int nMode, D2RectStrc* pRect, unsigned int nFrame)
{
    for (; nMode > 0; --nMode)
    {
        memmove(pRect, pUnit, nMode);
        memmove(pRect, (const void*)&nFrame, pRect->nLeft);
        memmove(pRect, pUnit, pUnit->dwUnitType + pRect->nLeft);
        memmove(pRect, pUnit, pUnit->dwClassId + pRect->nTop);
        memmove(pRect, pUnit, pUnit->dwAnimMode + pRect->nRight);
    }
    return pRect->nLeft;
}

// build: context DATATBLS_GetSkillsTxtRecord_Inl
inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

// 0x00464310
static int __stdcall sub_00464310_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
        return 0;

    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), gszCUnitFile_006D6A48, 1674)))
        return 1;

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), gszCUnitFile_006D6A48, 1678)) != 0;
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
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// build: context UNIT_HasFlag
static inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (!pUnit)
        return 0;
    return (pUnit->dwFlags & nFlag) != 0;
}

// build: context UNIT_HasFlagEx
static inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00466870
int __fastcall sub_00466870_IsUnitSelectable(D2UnitStrc* pUnit, int nX, int nY, int bHitTest)
{
    const int nMouseX=sub_00468730();
    switch(sub_0045AE90())
    {
    case 3: return 0;
    case 1: if(nMouseX>=gnScreenWidth_0071146C/2) return 0; break;
    case 2: if(nMouseX<gnScreenWidth_0071146C/2) return 0; break;
    }
    D2UnitStrc* pPlayer=gpPlayerUnit_007A6A70;
    if(UNIT_HasFlag(pUnit,0x200000)) return 0;
    if(!sub_00465C60(pPlayer,pUnit) && !sub_00464EC0(pPlayer,pUnit) && !sub_00464F70(pPlayer,pUnit)) return 0;
    int bSelectable=0;
    if(sub_00464310_CheckMonsterSkillSelect(pUnit,pPlayer))
    {
        if(!pUnit) return 0;
        if(UNIT_HasFlag(pUnit,2) || (pUnit->dwUnitType==UNIT_MONSTER && sub_00464820_IsDeadOrDying(pUnit) && sub_00451F30(pUnit,4))) bSelectable=1;
    }
    else
    {
        if(!pUnit) return 0;
        if(UNIT_HasFlag(pUnit,2)) bSelectable=1;
    }
    if(!UNIT_HasFlagEx(pUnit,0x80) || !bSelectable) return 0;
    if(!bHitTest) return 1;
    int nMode=UNITS_GetAnimOrSeqMode(pUnit);
    int nClassId=pUnit->dwClassId;
    int nType=pUnit->dwUnitType;
    D2COMMON_11013_ConvertMode(pUnit,&nType,&nClassId,&nMode,gszCUnitFile_006D6A48,0x6ED);
    D2ObjectsTxt* ptObjectData=0;
    int nUnitX=UNITS_GetClientCoordX(pUnit);
    int nUnitY=UNITS_GetClientCoordY(pUnit);
    switch(nType)
    {
    case 1:
    {
        D2MonStats2SelectStrc* pStats=UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if(pStats->nFlags[0]&gdwBitMasks[0])
        {
            D2RectStrc tBox;
            const int nTop=nUnitY+pStats->nTop;
            const int nLeft=nUnitX+pStats->nLeft;
            tBox.nLeft=nLeft;
            tBox.nTop=nTop;
            tBox.nRight=nLeft+pStats->nWidth;
            tBox.nBottom=nTop+pStats->nHeight;
            D2CoordPairStrc tPoint={nX,nY};
            return PtInRect(&tBox,tPoint)!=0;
        }
        if(!sub_00470860_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY)) return 0;
        break;
    }
    case 0:
        if(!sub_00470860_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY)) return 0;
        break;
    case 2:
        ptObjectData=DATATBLS_GetObjectsTxtRecord(nClassId);
        if(!sub_00470860_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY) && !ptObjectData->nIsDoor && !ptObjectData->nSelectBox) return 0;
        break;
    case 4:
        if(pUnit->dwAnimMode!=3 || sub_004538D0(13)) return 0;
        break;
    case 5: return sub_00463EE0_IsPointInTileRect(pUnit,nX,nY);
    }
    int bAllComponents=0;
    switch(nType)
    {
    case 2:
        D2_ASSERT(ptObjectData,0x741);
        if(ptObjectData->nIsDoor)
        {
            if(pUnit->dwAnimMode==2 || pUnit->dwAnimMode==4 || pUnit->dwAnimMode==5)
                return sub_00463FE0_IsInObjectSelectBox(nY,ptObjectData,pUnit,nX);
        }
        else if(ptObjectData->nSelectBox) return sub_00463FE0_IsInObjectSelectBox(nY,ptObjectData,pUnit,nX);
        if(ptObjectData->nComponents>1) bAllComponents=1;
        break;
    case 1:
    {
        D2MonStats2SelectStrc* pStats=UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if(pStats && pStats->nComponents>1) bAllComponents=1;
        break;
    }
    case 0:bAllComponents=1;break;
    }
    int nFrame,nFrameCount;
    {
        D2RectStrc tRect;
        UNITS_GetShiftedFrameMetrics(pUnit,&nFrame,&nFrameCount);
        tRect.nBottom=tRect.nRight=tRect.nTop=tRect.nLeft=0;
        if(pUnit->dwUnitType==UNIT_PLAYER && pUnit->dwClassId==4 && pUnit->dwAnimMode==PLRMODE_SEQUENCE) return 1;
        if(bAllComponents)
        {
            for(unsigned int nComponent=0;nComponent<16;++nComponent)
                if(sub_004640A0_GetUnitSelectRect(pUnit,nComponent,&tRect,nFrame) && sub_004DB670_UpdateUnitGfx(pUnit,nComponent) && nX>=tRect.nLeft && nX<=tRect.nRight && nY>=tRect.nBottom && nY<=tRect.nTop) return 1;
            return 0;
        }
        if(sub_004640A0_GetUnitSelectRect(pUnit,1,&tRect,nFrame) && nX>=tRect.nLeft && nX<=tRect.nRight && nY>=tRect.nBottom && nY<=tRect.nTop) return 1;
        return 0;
    }
}

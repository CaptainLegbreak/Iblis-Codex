struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2CelStrc;

struct D2MotionVectorStrc
{
    int nX;
    int nY;
    int nZ;
};

struct D2GfxMotionStrc
{
    unsigned int dwFlags;
    D2MotionVectorStrc tA;
    D2MotionVectorStrc tB;
    D2MotionVectorStrc tD;
    D2MotionVectorStrc tC;
    char unk0x34[0xC];
    int nParam0;
    int nParam1;
};

struct T004DA110
{
    int nValue;
    int nKeyA;
    int nKeyB;
    T004DA110* pNext;
};

struct D2CltUnitEventStrc
{
    int nType;
    int f_4;
    int f_8;
    int nParam1;
    int nParam2;
    int nParam3;
    D2CltUnitEventStrc* pPrevious;
    D2CltUnitEventStrc* pNext;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    char unk0x0C[0x30];
    unsigned int dwSeqSpeed;
    char unk0x40[0xE];
    unsigned char nActionFrame;
    unsigned char unk0x4F;
    char unk0x50[0x40];
    D2CltUnitEventStrc* pCltTimerList;
};

struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned int dwPartyFlags;
    D2RosterInfoStrc* pNext;
};

struct D2LevelsTxt
{
    char unk0x00[0x09];
    unsigned char nDrawEdges;
};

struct D2DrawBoundsArgStrc
{
    char unk0x00[0x14];
    unsigned int dwFlags;
};

struct D2DrawBoundsStrc
{
    char unk0x00[0x28];
    int bActive;
    int nMinX;
    int nMaxX;
    int nMinY;
    int nMaxY;

    void sub_004DDE80_ExtendBounds(D2DrawBoundsArgStrc* pArg, int nX, int nY);
};

struct T00481920
{
    char unk0x00[0x24];
    int nEAXEnviron;
    int nEAXEnvSize;
    int nEAXEnvDiff;
    int nEAXRoomVol;
    int nEAXRoomHF;
    int nEAXDecayTime;
    int nEAXDecayHF;
    int nEAXReflect;
    int nEAXReflectDelay;
    int nEAXReverb;
    int nEAXRevDelay;
    int nEAXRoomRoll;
    int nEAXAirAbsorb;
};

struct D2SoundEnvironStrc
{
    int nEnviron;
    float f_4;
    float fEnvDiff;
    int nRoomVol;
    int f_10;
    float f_14;
    float fDecayHF;
    int nReflect;
    float fReflectDelay;
    int f_24;
    float fRevDelay;
    float fRoomRoll;
    float fAirAbsorb;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x2C];
    unsigned int dwPrgCalc[3];
    char unk0x044[0x10];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    char unk0x082[0x68];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    char unk0x0F0[0x48];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAA4];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" double __cdecl sqrt(double x);                                                                   // 0x006879C0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnSoundEnvironId_0072ADE4;                                                                       // 0x0072ADE4

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                 // 0x004646A0
int __fastcall sub_004648F0_GetPathValue(D2UnitStrc* pUnit);                                                // 0x004648F0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId);                                  // 0x0047A310
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId);                        // 0x00481920
void __fastcall sub_004C5420_CreateClientMissile(D2UnitStrc* pUnit, int nMissileId, int nSkillId, int nSkillLevel); // 0x004C5420
int __fastcall sub_004E31C0_CltDo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                         // 0x004E31C0
int __fastcall D2GFX_GetResolutionMode();                                                                   // 0x004F5160
int __fastcall sub_00513B70_IsSoundEnvironEnabled();                                                        // 0x00513B70
void __fastcall sub_00513C50_SetSoundEnviron(D2SoundEnvironStrc* pEnviron);                                 // 0x00513C50
int __fastcall sub_00514C90_GetSoundMode();                                                                 // 0x00514C90
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                               // 0x00601950
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004DA110
int __stdcall sub_004DA110_GetMotionAX(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nX >> 11;
    }

    return 0;
}

// 0x004DA130
int __stdcall sub_004DA130_GetMotionAY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nY >> 11;
    }

    return 0;
}

// 0x004DA150
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nZ >> 11;
    }

    return 0;
}

// 0x004DA170
int __stdcall sub_004DA170_GetMotionRawAX(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nX;
    }

    return 0;
}

// 0x004DA190
int __stdcall sub_004DA190_GetMotionRawAY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nY;
    }

    return 0;
}

// 0x004DA1B0
int __stdcall sub_004DA1B0_GetMotionRawAZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nZ;
    }

    return 0;
}

// 0x004DA250
void __stdcall sub_004DA250_SetMotionVectorD(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tD.nX = nX << 11;
            pMotion->tD.nY = nY << 11;
            pMotion->tD.nZ = nZ << 11;
        }
        else
        {
            pMotion->tD.nX = nX;
            pMotion->tD.nY = nY;
            pMotion->tD.nZ = nZ;
        }
    }
}

// 0x004DA2F0
void __stdcall sub_004DA2F0_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags |= 4;
        pMotion->nParam0 = nParam0;
        pMotion->nParam1 = nParam1;
    }
}

// 0x004DA320
int __stdcall sub_004DA320_GetMotionParam0(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nParam0;
    }

    return 0;
}

// 0x004DA640
void __stdcall sub_004DA640_SetMotionFlag1(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags |= 1;
    }
}

// 0x004DA660
int __stdcall sub_004DA660_TestMotionFlag1(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion && (pMotion->dwFlags & 1))
    {
        return 1;
    }

    return 0;
}

// 0x004DA690
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags = pMotion->dwFlags & ~1 | 8;
    }
}

// 0x004DA6B0
int __stdcall sub_004DA6B0_TestMotionFlags(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion && (pMotion->dwFlags & 1) && !(pMotion->dwFlags & 8))
    {
        return 0;
    }

    return 1;
}

// 0x004DA920
void __fastcall sub_004DA920_AddGfxUtilNode(T004DA110** ppList, int nValue, int nKeyA, int nKeyB, int* pnCount, int* pnBytes)
{
    T004DA110* pNode = (T004DA110*)FOG_Alloc(sizeof(T004DA110), ".\\ENGINE\\GfxUtil.cpp", 128, 0);
    D2_ASSERT(pNode, 129);

    *pnBytes += sizeof(T004DA110);
    memset(pNode, 0, sizeof(T004DA110));
    pNode->nValue = nValue;
    pNode->nKeyA = nKeyA;
    pNode->nKeyB = nKeyB;
    pNode->pNext = *ppList;
    *ppList = pNode;
    ++*pnCount;
}

// 0x004DA990
T004DA110* __fastcall sub_004DA990_FindGfxUtilNode(T004DA110* pList, int nKeyA, int nKeyB)
{
    for (T004DA110* pNode = pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKeyB == nKeyB && pNode->nKeyA == nKeyA)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x004DAB40
int __fastcall sub_004DAB40_IsCelOnScreen(D2CelStrc* pCel, int nX, int nY, int bFlag)
{
    int nHeight = sub_006018F0(pCel);
    int nBottom = sub_00601950(pCel) + nY;
    int nLeft = sub_00601920(pCel) + nX;
    int nWidth = sub_006018C0(pCel);
    if (bFlag)
    {
        nLeft -= nHeight;
        nWidth += nHeight;
    }

    if (nLeft > gnGlobal_0071146C)
    {
        return 0;
    }

    if (nLeft + nWidth < 0)
    {
        return 0;
    }

    if (nBottom - nHeight > gnGlobal_00711470)
    {
        return 0;
    }

    return nBottom + nHeight >= 0;
}

// 0x004DC110
D2CltUnitEventStrc* __fastcall sub_004DC110_AddCltUnitEvent(D2UnitStrc* pUnit, int nType, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5)
{
    if (!pUnit)
    {
        return 0;
    }

    D2CltUnitEventStrc* pEvent = (D2CltUnitEventStrc*)FOG_AllocPool(pUnit->pMemoryPool, sizeof(D2CltUnitEventStrc), ".\\UNIT\\CUnitEvent.cpp", 72, 0);
    memset(pEvent, 0, sizeof(D2CltUnitEventStrc));
    pEvent->nParam1 = nParam1;
    pEvent->nParam2 = nParam2;
    pEvent->nParam3 = nParam3;
    pEvent->nType = nType;
    pEvent->pNext = pUnit->pCltTimerList;
    pEvent->f_4 = nParam4;
    pEvent->f_8 = nParam5;
    if (pUnit->pCltTimerList)
    {
        pUnit->pCltTimerList->pPrevious = pEvent;
    }
    pUnit->pCltTimerList = pEvent;
    return pEvent;
}

// 0x004DC3E0
void __fastcall sub_004DC3E0_TogglePvpFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            if (bSet)
            {
                pRosterInfo->dwPartyFlags |= nFlags;
            }
            else
            {
                pRosterInfo->dwPartyFlags &= ~nFlags;
            }
            return;
        }
    }
}

// 0x004DC440
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo->dwPartyFlags & nFlags;
        }
    }

    return 0;
}

// 0x004DC4C0
void __fastcall sub_004DC4C0_SetPvpFlagsLow(int nUnitId1, int nUnitId2, unsigned int nFlags)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            pRosterInfo->dwPartyFlags &= 0xFFFF0000;
            pRosterInfo->dwPartyFlags |= nFlags;
            return;
        }
    }
}

// 0x004DDE00
int __stdcall sub_004DDE00_TestLevelDrawEdges(int bArg)
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
        if (pLevelsTxtRecord->nDrawEdges && !bArg && D2GFX_GetResolutionMode() == 2)
        {
            return 1;
        }
    }

    return 0;
}

// 0x004DDE80
void D2DrawBoundsStrc::sub_004DDE80_ExtendBounds(D2DrawBoundsArgStrc* pArg, int nX, int nY)
{
    pArg->dwFlags |= 0x20000;
    if (bActive)
    {
        if (nX < nMinX)
        {
            nMinX = nX;
        }
        if (nX > nMaxX)
        {
            nMaxX = nX;
        }
        if (nY < nMinY)
        {
            nMinY = nY;
        }
        if (nY > nMaxY)
        {
            nMaxY = nY;
        }
    }
}

// 0x004DF6C0
void __fastcall sub_004DF6C0_ApplySoundEnviron(int nEnvironId)
{
    if (nEnvironId == gnSoundEnvironId_0072ADE4)
    {
        return;
    }

    T00481920* pTxt = sub_00481920_GetSoundEnvironTxtRecord(nEnvironId);
    if ((sub_00514C90_GetSoundMode() == 2 || !nEnvironId) && sub_00513B70_IsSoundEnvironEnabled())
    {
        D2SoundEnvironStrc tEnviron;
        tEnviron.nEnviron = pTxt->nEAXEnviron;
        tEnviron.f_4 = pTxt->nEAXEnvSize / 1000.0;
        tEnviron.fEnvDiff = pTxt->nEAXEnvDiff / 1000.0;
        tEnviron.nRoomVol = pTxt->nEAXRoomVol;
        tEnviron.f_10 = pTxt->nEAXRoomHF;
        tEnviron.f_14 = pTxt->nEAXDecayTime / 1000.0;
        tEnviron.fDecayHF = pTxt->nEAXDecayHF / 1000.0;
        tEnviron.nReflect = pTxt->nEAXReflect;
        tEnviron.fReflectDelay = pTxt->nEAXReflectDelay / 1000.0;
        tEnviron.f_24 = pTxt->nEAXReverb;
        tEnviron.fRevDelay = pTxt->nEAXRevDelay / 1000.0;
        tEnviron.fRoomRoll = pTxt->nEAXRoomRoll / 1000.0;
        tEnviron.fAirAbsorb = pTxt->nEAXAirAbsorb / 1000.0;
        sub_00513C50_SetSoundEnviron(&tEnviron);
    }

    gnSoundEnvironId_0072ADE4 = nEnvironId;
}

// 0x004E0C60
int __fastcall sub_004E0C60_CltDoResetActionFrame(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x004E0F40
int __fastcall sub_004E0F40_CltDoSetAnimFrameFromCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x004E12F0
int __fastcall sub_004E12F0_CltDoResetActionFrame2(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x004E24D0
int __fastcall sub_004E24D0_CltDoMissileA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wCltMissileA;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004C5420_CreateClientMissile(pUnit, nMissileId, nSkillId, nSkillLevel);
        return 1;
    }

    return 0;
}

// 0x004E3330
int __fastcall sub_004E3330_CltDoTest(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return sub_004E31C0_CltDo(pUnit, nSkillId, nSkillLevel) != 0;
}

// 0x004E4060
float __stdcall sub_004E4060_SqrtF(float fValue)
{
    return (float)sqrt(fValue);
}

// 0x004E4080
float __cdecl sub_004E4080_SqrtFCdecl(float fValue)
{
    return (float)sqrt(fValue);
}

// 0x004E4130
float __stdcall sub_004E4130_Length2D(float fX, float fY)
{
    float fLengthSquared = fX * fX + fY * fY;
    return (float)sqrt(fLengthSquared);
}

// 0x004E4160
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY)
{
    return (float)(fX * fX + fY * fY);
}

// 0x004F20C0
int __fastcall sub_004F20C0_CltDoSetParamFromCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nValue = sub_004648F0_GetPathValue(pUnit);
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!nValue)
    {
        SKILLS_SetParam1(pSkill, 0);
    }
    else
    {
        SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x004F34D0
int __fastcall sub_004F34D0_CltDoMissileC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wCltMissileC;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004C5420_CreateClientMissile(pUnit, nMissileId, nSkillId, nSkillLevel);
    }

    return 1;
}

#include "gen/data/Source/D2Client/004DA110_sub_004DA110_GetMotionAX.inc"

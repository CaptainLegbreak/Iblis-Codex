typedef int (__stdcall* FARPROC)();

struct D2DynamicPathStrc;
struct D2AnimSeqTxt;

struct T00552FD0
{
    char unk0x00[0x10];
    unsigned char pFrameFlags[0x90];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    D2AnimSeqTxt* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    char unk0x4E[0x02];
    T00552FD0* pAnimData;
    char unk0x54[0x40];
    int dwOwnerType;
    int dwOwnerGUID;
    char unk0x9C[0x2C];
    unsigned int dwFlagEx;
    char unk0xCC[0x18];
    D2UnitStrc* pListNext;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
    char unk0xAC[0x1074];
    D2UnitStrc* pUnitList[5][128];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID);         // 0x00648BB0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_ITEM 4
#define IMODE_EQUIP 1
#define IMODE_INBELT 2
#define STATE_PLAYERBODY 7
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_ENDANIM 1
#define UNITFLAGEX_STOREOWNERINFO 0x400

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!UNIT_HasFlagEx(pUnit, UNITFLAGEX_STOREOWNERINFO))
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x00553490
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1792);
    D2_ASSERT(pGame, 1793);

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 1796);

    if (!PATH_GetTargetUnit(pPath))
    {
        return;
    }

    int nTargetType;
    int nTargetGUID;
    PATH_GetTargetTypeAndGUID(pPath, &nTargetType, &nTargetGUID);

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nTargetType, nTargetGUID);
    if (pTarget != PATH_GetTargetUnit(pPath))
    {
        PATH_SetTargetUnit(pPath, 0);
    }

    if (!pTarget || pTarget->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    const int nAnimMode = pTarget->dwAnimMode;
    if (nAnimMode == IMODE_INBELT || nAnimMode == IMODE_EQUIP)
    {
        PATH_SetTargetUnit(pPath, 0);
    }
}

// 0x005537D0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate)
{
    D2_ASSERT(pGame, 1970);
    D2_ASSERT(pfIterate, 1971);

    D2UnitStrc** ppUnitList;
    if (nType == UNIT_PLAYER)
    {
        ppUnitList = pGame->pUnitList[0];
    }
    else if (nType == UNIT_MONSTER)
    {
        ppUnitList = pGame->pUnitList[1];
    }
    else
    {
        return 0;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)pfIterate), 1991);

    for (int i = 0; i < 128; ++i, ++ppUnitList)
    {
        for (D2UnitStrc* pUnit = *ppUnitList; pUnit; pUnit = pUnit->pListNext)
        {
            if (!STATES_CheckState(pUnit, STATE_PLAYERBODY) && pfIterate(pGame, pUnit, pArg) == 1)
            {
                return pUnit;
            }

            D2_ASSERT(pUnit, 222);
        }
    }

    return 0;
}

// 0x00553C70
void __fastcall sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    if (a3 <= 0)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    const int nCalc = nFrame - (pUnit->nSeqCurrentFramePrecise >> 8) - a3;
    pUnit->nSeqCurrentFramePrecise = (nFrame - nCalc) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        T00552FD0* pAnimData = pUnit->pAnimData;
        int nIndex = nCalc - 1;
        int nAnimFrame = nCalc << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553DC0
void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    pUnit->nSeqCurrentFramePrecise = (nFrame - a3) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        T00552FD0* pAnimData = pUnit->pAnimData;
        int nIndex = a3 - 1;
        int nAnimFrame = a3 << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

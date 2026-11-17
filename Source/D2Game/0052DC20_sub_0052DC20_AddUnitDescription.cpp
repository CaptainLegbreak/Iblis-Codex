extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x0000[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x001C[0x1104];
    D2UnitStrc* pUnitList[5][128];
};

struct D2UnitDescriptionListStrc
{
    int nClassId;
    int nCount;
    int nDefaultCount;
    char szDescription[0x80];
    D2UnitDescriptionListStrc* pNext;
};

typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

#define D2GameReservedSlotHandle (-1)

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
extern UnitDescriptionFunction gpfGetDescription_6FD2CA64[5];                                               // 0x0073107C
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

// 0x0052DC20
static void __stdcall sub_0052DC20_AddUnitDescription(int bCount, int nClassId, D2UnitDescriptionListStrc* pList)
{
    D2UnitDescriptionListStrc* pHead = pList;
    D2_ASSERT(pList, 0x139E);
    do
    {
        if (pList->nClassId == nClassId)
        {
            if (bCount)
            {
                ++pList->nCount;
            }
            else
            {
                ++pList->nDefaultCount;
            }
            return;
        }
        pList = pList->pNext;
    }
    while (pList);

    D2UnitDescriptionListStrc* pNew = (D2UnitDescriptionListStrc*)sub_0040B430(0, sizeof(D2UnitDescriptionListStrc), ".\\GAME\\Game.cpp", 0x13AF, 0);
    if (pNew)
    {
        memset(pNew, 0, sizeof(D2UnitDescriptionListStrc));
        pNew->nClassId = nClassId;
        pNew->nCount = 0;
        pNew->nDefaultCount = 0;
        if (bCount)
        {
            pNew->nCount = 1;
        }
        else
        {
            pNew->nDefaultCount = 1;
        }
        pNew->pNext = pHead->pNext;
        pHead->pNext = pNew;
    }
}

void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    D2UnitStrc** pUnitList = 0;
    if (!pGame)
    {
        return;
    }

    switch (eType)
    {
    case 0:
        pUnitList = pGame->pUnitList[0];
        break;
    case 1:
        pUnitList = pGame->pUnitList[1];
        break;
    case 2:
        pUnitList = pGame->pUnitList[2];
        break;
    case 3:
        pUnitList = pGame->pUnitList[3];
        break;
    case 4:
        pUnitList = pGame->pUnitList[4];
        break;
    }

    for (int i = 0; i < 128; ++i)
    {
        for (D2UnitStrc* pUnit = pUnitList[i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
        {
            sub_0052DC20_AddUnitDescription(1, pUnit->dwClassId, pUnitDescriptionsList);
        }
    }

    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);

    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[eType]), 0x1450);
    for (D2UnitDescriptionListStrc* pNode = pUnitDescriptionsList->pNext; pNode; pNode = pNode->pNext)
    {
        gpfGetDescription_6FD2CA64[eType](pNode->szDescription, pNode->nClassId);
    }
}

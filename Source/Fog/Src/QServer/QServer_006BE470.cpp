struct sub_006BE470_Strc;

struct sub_006BE510_Guard;

struct sub_006BE530_LockRef;

struct sub_006BF170_Object;

struct sub_006BE470_Strc
{
    char unk_000[0x86C];
    int nState;
};

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BE510_Guard
{
    CRITICAL_SECTION* pCriticalSection;

    sub_006BE510_Guard* sub_006BE510_Enter(CRITICAL_SECTION* pCs);
};

typedef struct _RTL_CRITICAL_SECTION* LPCRITICAL_SECTION;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

struct sub_006BE530_LockRef
{
    LPCRITICAL_SECTION pCriticalSection;
};

struct sub_006BF170_Object
{
    int nHandle;
};

void __fastcall sub_006C2110(sub_006BF170_Object* pObject); // 0x006C2110

void __fastcall sub_006C33D0_Stop(sub_006BF170_Object* pObject); // 0x006C33D0

struct sub_006BEA70_Client
{
    char unk_000[0x5BC];
    sub_006BEA70_Client* pNext;
};

struct sub_006BEA70_Server
{
    char unk_000[0x854];
    char cs[0x1C];
    sub_006BEA70_Client** ppBuckets;
    char unk_874[8];
    int nBuckets;
};

// 0x006BE470
int __stdcall sub_006BE470_IsActive(sub_006BE470_Strc* pThis)
{
    if (!pThis)
        return 0;
    return pThis->nState == 1 || pThis->nState == 2;
}

// 0x006BE510
sub_006BE510_Guard* sub_006BE510_Guard::sub_006BE510_Enter(CRITICAL_SECTION* pCs)
{
    pCriticalSection = pCs;
    EnterCriticalSection(pCs);
    return this;
}

// 0x006BE530
void __fastcall sub_006BE530_Leave(sub_006BE530_LockRef* pLock)
{
    LeaveCriticalSection(pLock->pCriticalSection);
}

// 0x006BEA70
int __stdcall sub_006BEA70_CountBucket(sub_006BEA70_Server* pServer, int nBucket)
{
    if (nBucket >= pServer->nBuckets)
        return -1;

    int nCount = 0;
    EnterCriticalSection((CRITICAL_SECTION*)pServer->cs);
    for (sub_006BEA70_Client* pClient = pServer->ppBuckets[nBucket]; pClient; pClient = pClient->pNext)
        ++nCount;
    LeaveCriticalSection((CRITICAL_SECTION*)pServer->cs);
    return nCount;
}

// 0x006BF170
void __fastcall sub_006BF170_Dispatch(sub_006BF170_Object* pObject)
{
    if (pObject->nHandle)
        sub_006C2110(pObject);
    else
        sub_006C33D0_Stop(pObject);
}

// 0x006BF250
void __stdcall sub_006BF250_Nop(int a1, int a2, int a3)
{
}

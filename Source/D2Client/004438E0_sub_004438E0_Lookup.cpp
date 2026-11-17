struct D2LaunchGameEntryStrc
{
    int nAddress;
    char unk0x04[0x10];
    char szName[1];
};

struct D2LaunchGameListStrc
{
    int nCount;
    char unk0x04[0x0C];
    D2LaunchGameEntryStrc tFirst;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x38];
    D2LaunchGameListStrc* (__fastcall* pfQueryGames)(const char* szName, const char* szPassword, int nFilterA, int nFilterB);
};

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x00[0x1EF];
    unsigned short wFlags;
};
#pragma pack(pop)

struct D2LaunchGameRecStrc
{
    char nUnk0x00;
    char szName[0x10];
    char szDesc[0x20];
    char wValue0x31[2];
    char wValue0x33[2];
    char unk0x35[2];
    char nAddress0x37[4];
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
const char* __fastcall sub_00442AE0_SkipString(const char* szText);                                         // 0x00442AE0
int __fastcall sub_00442B20_IsCharOverLimit(const char* pChar);                                             // 0x00442B20

// build: context sub_004438E0_HasProgress
static __forceinline int sub_004438E0_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

// 0x004438E0
int __fastcall sub_004438E0_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord)
{
    int nFilterA = 0;
    int nFilterB = 0;
    if (gpCharInfo_0077BBD8->wFlags & 4)
    {
        nFilterA = 4;
        nFilterB = 4;
    }
    if (gpCharInfo_0077BBD8->wFlags & 0x20)
    {
        nFilterA |= 8;
        nFilterB |= 8;
    }
    if (!sub_004438E0_HasProgress(gpCharInfo_0077BBD8->wFlags, 0x800, 0xA00))
    {
        if (sub_004438E0_HasProgress(gpCharInfo_0077BBD8->wFlags, 0x400, 0x500))
            nFilterB |= 2;
        else
            nFilterB |= 3;
    }

    const char* p = (const char*)gpLaunchFuncs_0077B09C->pfQueryGames(szName, szPassword, nFilterA, nFilterB);
    if (p)
    {
        const int nCount = *(const int*)p;
        if (nCount >= 1)
        {
            p += 0x10;
            *(unsigned short*)pRecord->wValue0x33 = 1;
            *(int*)pRecord->nAddress0x37 = *(const int*)p;
            p += 0x14;
            strcpy(pRecord->szName, p);
            p = sub_00442AE0_SkipString(p);
            p = sub_00442AE0_SkipString(p);
            if (!sub_00442B20_IsCharOverLimit(p))
            {
                strcpy(pRecord->szDesc, p);
                sub_00442AE0_SkipString(p);
                return nCount;
            }
        }
    }

    return 0;
}

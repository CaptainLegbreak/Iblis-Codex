extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

struct D2WinControlStrc;

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    unsigned short wProgressFlags;
};

struct D2GameListRecordStrc
{
    char szName[0x10];
    char szDesc[0x22];
    unsigned short wType;
    char unk0x34[2];
    unsigned int f_36;
    char unk0x3A;
};
#pragma pack(pop)

struct D2LaunchFuncsStrc
{
    char unk0x00[0x38];
    int* (__fastcall* pfnGetGameList)(int nA, int nB, int nFlags, int nDifficulties);
};

extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern D2GameListRecordStrc gtGameList_0077BDC9[];                                                          // 0x0077BDC9
extern D2WinControlStrc* gpGameList_00798BC0;                                                               // 0x00798BC0
int gnGameCount_00798CCC;                                                                                   // 0x00798CCC

int __fastcall sub_00442B20_IsCharOverLimit(const char* szText);                                            // 0x00442B20
void __cdecl sub_00442C20_HandleList();                                                                     // 0x00442C20
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80

static __forceinline int sub_00444E70_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

static __forceinline char* sub_00444E70_NextString(char* p)
{
    D2_ASSERT(p, 0xAD);
    while (*p)
        ++p;
    return p + 1;
}

// 0x00444E70
void __cdecl sub_00444E70_FillGameList()
{
    int nFlags = 0;
    int nDifficulties = 0;
    if (gpCharInfo_0077BBD8->wProgressFlags & 4)
    {
        nFlags = 4;
        nDifficulties = 4;
    }
    if (gpCharInfo_0077BBD8->wProgressFlags & 0x20)
    {
        nFlags |= 8;
        nDifficulties |= 8;
    }
    if (!sub_00444E70_HasProgress(gpCharInfo_0077BBD8->wProgressFlags, 0x800, 0xA00))
    {
        if (sub_00444E70_HasProgress(gpCharInfo_0077BBD8->wProgressFlags, 0x400, 0x500))
            nDifficulties |= 2;
        else
            nDifficulties |= 3;
    }

    char* p = (char*)gpLaunchFuncs_0077B09C->pfnGetGameList(0, 0, nFlags, nDifficulties);
    if (p)
    {
        gnGameCount_00798CCC = *(int*)p;
        p += 4;
        int i = 0;
        while (i < gnGameCount_00798CCC)
        {
            p += 0xC;
            gtGameList_0077BDC9[i].wType = 1;
            gtGameList_0077BDC9[i].f_36 = *(unsigned int*)p;
            p += 0x14;
            strcpy(gtGameList_0077BDC9[i].szName, p);
            if (gpGameList_00798BC0)
                sub_004FCF80_SetTextA(gpGameList_00798BC0, p);
            p = sub_00444E70_NextString(p);
            p = sub_00444E70_NextString(p);
            if (sub_00442B20_IsCharOverLimit(p))
            {
                --gnGameCount_00798CCC;
            }
            else
            {
                strcpy(gtGameList_0077BDC9[i].szDesc, p + 1);
                ++i;
            }
            p = sub_00444E70_NextString(p);
        }
    }

    sub_00442C20_HandleList();
}

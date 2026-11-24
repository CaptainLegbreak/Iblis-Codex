#include "D2Client.h"

void* ghAccelerators;                                                                                    // 0x007A0708
void* ghLngModule;                                                                                 // 0x007A070C

int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580

char gszLngPath[0x104];                                                                            // 0x007A0710

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

struct Unicode;

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    unsigned int nWidth;
    unsigned int nHeight;
};

struct D2UIVarRecordStrc
{
    int anCloseKind[0x26];
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

struct D2GridCellStrc;

struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};

struct D2MonLvlTxt;

struct D2MonLvlTxt
{
    char unk0x00[0x78];
};

// 0x00451260
int __cdecl RECORD_RegisterLngArgument()
{
    SCmdRegisterArgument(0x20000, -1, "lng", gszLngPath, sizeof(gszLngPath), 0, 0, 0);
    return 1;
}

// 0x00451290
void __cdecl sub_00451290_FreeLngModule()
{
    if (ghLngModule)
        FreeLibrary(ghLngModule);
    ghLngModule = 0;
    ghAccelerators = 0;
}

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryExA(const char* szFileName, void* hFile, unsigned long dwFlags); // 0x006CC348

extern "C" __declspec(dllimport) void* __stdcall LoadAcceleratorsA(void* hInstance, const char* szTableName); // 0x006CC4A0









































































































































































































int __stdcall SErrRegisterMessageSource(unsigned short wFacility, void* hModule, void* pReserved);     // 0x0041C2F0

int __stdcall COMCALLBACK_LoadLngString(int nId, char* szBuffer, unsigned int nSize);                         // 0x004512C0

int __fastcall sub_0051740B_ErrorBox(const char* szText);                                                   // 0x0051740B

void __fastcall sub_005177B2_SetLoadStringFn(void* pfnLoadString); // 0x005177B2

extern "C" const char gszLngFileName[];                                                            // 0x006D5EE0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size); // 0x0041C430

extern int gbStringsLoaded_007A070C; // 0x007A070C

// 0x004512C0
int __stdcall COMCALLBACK_LoadLngString(int nId, char* szBuffer, unsigned int nSize)
{
    D2_ASSERT(gbStringsLoaded_007A070C, 0x81);
    if (!SErrGetErrorStr(nId, szBuffer, nSize))
    {
        SStrCopy(szBuffer, "Stupid Lng.cpp error.", nSize);
        return 0;
    }
    return 1;
}

// 0x00451330
int __cdecl GAME_LoadLngModule()
{
    if (gszLngPath[0])
    {
        ghLngModule = LoadLibraryExA(gszLngPath, 0, 2);
        SRegSaveString("Diablo II", "LNG File", 0, gszLngPath);
    }
    if (!ghLngModule)
    {
        if (SRegLoadString("Diablo II", "LNG File", 0, gszLngPath, sizeof(gszLngPath)))
            ghLngModule = LoadLibraryExA(gszLngPath, 0, 2);
        if (!ghLngModule)
        {
            ghLngModule = LoadLibraryExA(gszLngFileName, 0, 2);
            if (!ghLngModule)
            {
                sub_0051740B_ErrorBox("Unable to start LNG manager.");
                return 0;
            }
        }
    }
    ghAccelerators = LoadAcceleratorsA(ghLngModule, (const char*)0x64);
    SErrRegisterMessageSource(0xFFF, ghLngModule, 0);
    sub_005177B2_SetLoadStringFn(COMCALLBACK_LoadLngString);
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_00451290.inc"

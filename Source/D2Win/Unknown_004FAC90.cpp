#include "D2Win.h"

struct D2ConfigStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" const char gszD2CharMpq[]; // 0x006DC77C

typedef int (__cdecl* DiscCallback)();

#pragma pack(push, 1)
struct D2ConfigStrc { char unk00[0x211]; int (__cdecl* expansion)(); };

#pragma pack(pop)

void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70
void* __fastcall sub_00517332_LoadMpqFile(const char*,void*,DiscCallback,int); // 0x00517332
extern void* ghXMusicMpq; // 0x007D5604

// 0x004FAC90
int __cdecl sub_004FAC90_CheckCharArchive()
{
    char szPath[0x104];
    FOG_GetInstallPath(szPath, sizeof(szPath));
    SStrPack(szPath, gszD2CharMpq, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    SStrCopy(szPath, gszD2CharMpq, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    return !sub_00406D20();
}

void* ghCharMpq; // 0x007D5610

void* ghMusicMpq; // 0x007D5628

void* ghXTalkMpq; // 0x007D5618

void* ghXVideoMpq; // 0x007D562C


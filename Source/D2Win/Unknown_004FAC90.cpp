#include "D2Win.h"

struct D2ConfigStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" const char szD2CharMpq_006DC77C[]; // 0x006DC77C

typedef int (__cdecl* DiscCallback)();

#pragma pack(push, 1)
struct D2ConfigStrc { char unk00[0x211]; int (__cdecl* expansion)(); };

#pragma pack(pop)

void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70
void* __fastcall sub_00517332_LoadMpqFile(const char*,void*,DiscCallback,int); // 0x00517332
extern void* ghXMusic_007D5604; // 0x007D5604

// 0x004FAC90
int __cdecl sub_004FAC90_CheckCharArchive()
{
    char szPath[0x104];
    FOG_GetInstallPath(szPath, sizeof(szPath));
    sub_00413800(szPath, szD2CharMpq_006DC77C, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    SStrCopy(szPath, szD2CharMpq_006DC77C, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    return !sub_00406D20();
}

void* ghChar_007D5610; // 0x007D5610

void* ghMusic_007D5628; // 0x007D5628

void* ghXTalk_007D5618; // 0x007D5618

void* ghXVideo_007D562C; // 0x007D562C

// 0x004FAEC0
int __fastcall ARCHIVE_LoadExpansionArchives(DiscCallback play,DiscCallback expansion,void* file,D2ConfigStrc* config) {
    if (sub_00406D20()) { play=0; expansion=0; }
    ghXVideo_007D562C=0;
    int bOk;
    if (!(sub_00408F20_HasExpansionMpq() && (!config || config->expansion()))) {
        ghChar_007D5610=sub_00517332_LoadMpqFile("d2char.mpq",file,play,1000);
        ghMusic_007D5628=sub_00517332_LoadMpqFile("d2music.mpq",file,play,1000);
        ghXMusic_007D5604=0;
        ghXTalk_007D5618=0;
        bOk = ghChar_007D5610 && ghMusic_007D5628;
    } else {
        ghChar_007D5610=sub_00517332_LoadMpqFile("d2char.mpq",0,play,1000);
        ghMusic_007D5628=sub_00517332_LoadMpqFile("d2music.mpq",0,play,1000);
        ghXMusic_007D5604=sub_00517332_LoadMpqFile("d2Xmusic.mpq",file,expansion,3000);
        ghXTalk_007D5618=sub_00517332_LoadMpqFile("d2Xtalk.mpq",file,expansion,3000);
        ghXVideo_007D562C=sub_00517332_LoadMpqFile("d2Xvideo.mpq",file,expansion,3000);
        bOk = ghChar_007D5610 && ghMusic_007D5628 && ghXMusic_007D5604 && ghXTalk_007D5618 && ghXVideo_007D562C;
    }
    if (!bOk) { ARCHIVE_UnloadExpansionArchives(); return 0; }
    return 1;
}

typedef unsigned int U32;
typedef unsigned short U16;
#define OFFSET(T, M) ((unsigned int)&(((T*)0)->M))
struct PlayerNode
{
    int playerId;
    U32 flags;
    PlayerNode* next;
};
struct PlayerListHead
{
    PlayerNode* first;
};
typedef char NodeSize[(sizeof(PlayerNode) == 12) ? 1 : -1];
typedef char NodeFlags[(OFFSET(PlayerNode, flags) == 4) ? 1 : -1];
typedef char NodeNext[(OFFSET(PlayerNode, next) == 8) ? 1 : -1];
extern const char gPlayerListFile[];
extern void* gAuxSoundRows; // 0x007BC9A8
extern int gAuxSoundCount; // 0x007BC9AC
extern void* gCacheRows; // 0x007BC9A0
extern int gCacheCount; // 0x007BC9A4
int gSoundMaxId;        // 0x007BC9B4
int gSoundMinId;        // 0x007BC9B0
extern int gTextY;
extern int gTextRight;
PlayerListHead* __fastcall sub_0047A310(int playerId);
void* __fastcall Allocate(U32 bytes, const char* file, int line, U32 flags);
int __fastcall Release(void* allocation, const char* file, int line, U32 flags); // 0x0040B3C0
void __fastcall sub_004823E0(int index); // 0x004823E0
void* __cdecl sub_004646A0();
int __stdcall DUNGEON_GetLevelIdFromRoom(void* room);
const U16* __fastcall sub_00453E70(int levelId);
int __fastcall sub_00501820(const U16* text);
void __fastcall sub_00502320(const U16* text, int x, int y, int color, int mode);

// 0x004828B0
void __cdecl sub_004828B0_ReleaseSoundTables()
{
    if (gAuxSoundRows)
    {
        Release(gAuxSoundRows, ".\\Sound\\SoundHdr.cpp", 385, 0);
        gAuxSoundRows = 0;
        gAuxSoundCount = 0;
    }
    if (gCacheRows)
    {
        for (int index = 1; index < gCacheCount; index += 1)
            sub_004823E0(index);
        Release(gCacheRows, ".\\Sound\\SoundHdr.cpp", 398, 0);
        gCacheRows = 0;
        gCacheCount = 0;
    }
    gSoundMinId = 0;
    gSoundMaxId = 0;
}

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
extern const char gSoundFile[];
extern void* gAuxSoundRows;
extern int gAuxSoundCount;
extern void* gCacheRows;
extern int gCacheCount;
extern int gSoundMaxId;
extern int gSoundMinId;
extern int gTextY; // 0x007A51BC
extern int gTextRight; // 0x007A5220
PlayerListHead* __fastcall sub_0047A310(int playerId);
void* __fastcall Allocate(U32 bytes, const char* file, int line, U32 flags);
int __fastcall Release(void* allocation, const char* file, int line, U32 flags);
void __fastcall sub_004823E0(int index);
void* __cdecl sub_004646A0();
int __stdcall DUNGEON_GetLevelIdFromRoom(void* room); // 0x0061A1B0
const U16* __fastcall sub_00453E70(int levelId); // 0x00453E70
int __fastcall sub_00501820(const U16* text); // 0x00501820
void __fastcall sub_00502320(const U16* text, int x, int y, int color, int mode); // 0x00502320

// 0x0045A050
void __cdecl sub_0045A050_DrawLevelName()
{
    void* room = sub_004646A0();
    if (room)
    {
        const U16* text = sub_00453E70(DUNGEON_GetLevelIdFromRoom(room));
        sub_00502320(text, gTextRight - sub_00501820(text) - 16, gTextY, 4, 0);
        gTextY += 16;
    }
}

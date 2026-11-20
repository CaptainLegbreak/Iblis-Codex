#include "D2Common.h"
#include "D2Structs.h"
#define PATH_UNKNOWN_FLAG_0x00010 0x00010
#define PATH_UNKNOWN_FLAG_0x00020 0x00020
#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define PATH_CORPSE_SIZE 3

struct ActiveRoom;
struct Room;
struct D2CoordStrc;
union D2FP32_16;
struct D2DrlgCoordsStrc;
struct D2StaticPathStrc;
struct D2PathInfoStrc;
struct Pad40_00648690;
struct Obj00648690;
struct Obj006486D0;
struct T00648730;
struct DrlgView;
struct PathView;
struct UnitView;
struct Obj00648750;
struct View_00648780;
struct View_006489C0;
struct View_00648AA0;
struct View_00648700;
struct Obj00648790;
struct Pad40_006487D0;
struct Obj006487D0;
struct Obj00648810;
struct Obj006488A0;
struct PathPrecisionView;
struct PathPreviousView;
struct Obj006BCDE0;
struct Obj006489D0;
struct Obj00648A20;
struct Obj00648A30;
struct Entry00648A40;
struct Pad40_00648A40;
struct Obj00648A40;
struct Entry00648A60;
struct Pad40_00648A60;
struct Obj00648A60;
struct Obj00648A80;
struct Obj00648AB0;
struct Obj00648AD0;
struct RoomFlags;
struct PathFlags;
struct KeyValue;
struct CodeRow;
struct CodeOutput;
struct LinkView;
struct CodeLink;
struct Vector;
struct DirectionRecord;
struct B25TargetUnit;
struct B25Path;
struct B25DistancePath;
struct B25MissileData;
struct B25MissileUnit;
struct Obj00648C10;
struct Obj00648CD0;
struct D2Record00648E40Strc;
struct PathCollisionView;
struct Pad40_00649070;
struct Obj00649070;
struct Obj006490A0;
struct Obj00649120;
struct D2PathPointStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;
struct D2DynamicPathStrc;

typedef int BOOL;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};


union D2FP32_16
{
    struct
    {
        unsigned short wOffsetX;
        unsigned short wPosX;
        unsigned short wOffsetY;
        unsigned short wPosY;
    };

    struct
    {
        unsigned int dwPrecisionX;
        unsigned int dwPrecisionY;
    };
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    D2DrlgCoordsStrc tCoords;
};

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    char unk0x04[0x08];
    D2CoordStrc tGameCoords;
};


struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned short field_16;
    int nDistMax;
    unsigned char nMinimumFScoreToEvaluate;
    unsigned char field_1D;
    unsigned short field_1E;
    int nPathType;
    int nUnitSize;
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

#pragma pack(push, 1)
struct D2DynamicPathStrc
{
    union
    {
        struct
        {
            D2FP32_16 tGameCoords;
        };
        struct
        {
            unsigned char unk_00[0x2];
            unsigned short wPosX;
            unsigned char unk_04[0x2];
            unsigned short wPosY;
        };
    };
    int dwClientCoordX;
    int dwClientCoordY;
    D2PathPointStrc tTargetCoord;
    D2PathPointStrc tPrevTargetCoord;
    D2PathPointStrc tFinalTargetCoord;
    D2ActiveRoomStrc* pRoom;
    D2ActiveRoomStrc* pPreviousRoom;
    int dwCurrentPointIdx;
    int dwPathPoints;
    void* unk0x2C;
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
    unsigned int unk0x38;
    unsigned int dwPathType;
    unsigned int dwPrevPathType;
    unsigned int dwUnitSize;
    unsigned int dwCollisionPattern;
    unsigned int nFootprintCollisionMask;
    unsigned int nMoveTestCollisionMask;
    unsigned short nCollidedWithMask;
    unsigned short padding0x56;
    D2UnitStrc* pTargetUnit;
    unsigned int dwTargetType;
    unsigned int dwTargetId;
    unsigned char nDirection;
    unsigned char nNewDirection;
    unsigned char nDiffDirection;
    unsigned char unk0x67;
    unsigned char dwSpeed;
    unsigned char unk0x69;
    D2CoordStrc tDirectionVector;
    D2CoordStrc tVelocityVector;
    char padding0x7A[2];
    int dwVelocity;
    unsigned int nPreviousVelocity;
    int dwMaxVelocity;
    int dwAcceleration;
    int dwAccelerationsCounter;
    unsigned char nDist;
    unsigned char nDistMax;
    unsigned char nIDAStarInitFScore;
    unsigned char nStepNum;
    unsigned char nDistance;
    char padding0x95[3];
    int nDirOffset;
    D2PathPointStrc PathPoints[78];
    int nSavedStepsCount;
    D2PathPointStrc SavedSteps[10];
};

#pragma pack(pop)
typedef int (__fastcall* PATH_FUNCTION)(D2PathInfoStrc* pPathInfo);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C
extern const D2CoordStrc gatDirectionToOffset_006EB398[8]; // 0x006EB398
extern PATH_FUNCTION const scpfnPathFunction_006EB6D8[]; // 0x006EB6D8
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
int __stdcall UNITS_IsDoor(D2UnitStrc* pUnit); // 0x00621A70
int __fastcall UNITS_CheckIfObjectOrientationIs1(D2UnitStrc* pUnit); // 0x00621AC0
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster); // 0x0063E860
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064D910
void __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
int __fastcall PATH_ComputePathBlessedHammer_6FDAB3C0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed); // 0x0067A140
int __fastcall PATH_ComputePathChargedBolt_6FDAB4A0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed); // 0x0067A240
static __declspec(noinline) void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo); // 0x00648050
static __declspec(noinline) BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo);

struct Pad40_00648690 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00648690 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    int nValue38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned int dwUnknown64;
    unsigned int dwUnknown68;
    unsigned int dwUnknown6C;
    unsigned int dwUnknown70;
    unsigned int dwUnknown74;
    unsigned int dwUnknown78;
    int nValue7C;
    unsigned int dwUnknown80;
    int nValue84;
};

struct Obj006486D0 { unsigned int dwUnknown00[33]; unsigned int dwValue84; };

typedef unsigned char U8;

typedef unsigned int U32;

struct T00648730
{
    char retainedPrefix[0x1c];
    T00648730* statusNext;
    char retainedMiddle[0x10];
    ActiveRoom* activeRoom;
    char retainedBeforeStatus[0x10];
    U8 status;
    char retainedTail[0xA7];
};

struct DrlgView
{
    char retainedPrefix[0xa0];
    T00648730 statusRooms[4];
};

struct PathView
{
    char retainedPrefix[0x28];
    int pointCount;
    char retainedGap[8];
    U32 flags;
    char retainedBeforePattern[0x10];
    int collisionPattern;
};

struct UnitView
{
    char retainedPrefix[0x2c];
    PathView* path;
};

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_room_next[OFFSET(T00648730,statusNext)==0x1c?1:-1];

typedef char check_room_active[OFFSET(T00648730,activeRoom)==0x30?1:-1];

typedef char check_room_status[OFFSET(T00648730,status)==0x44?1:-1];

typedef char check_room_stride[sizeof(T00648730)==0xec?1:-1];

typedef char check_room_array[OFFSET(DrlgView,statusRooms)==0xa0?1:-1];

typedef char check_first_head[OFFSET(DrlgView,statusRooms)+OFFSET(T00648730,statusNext)==0xbc?1:-1];

typedef char check_second_sentinel[OFFSET(DrlgView,statusRooms)+sizeof(T00648730)==0x18c?1:-1];

typedef char check_second_head[OFFSET(DrlgView,statusRooms)+sizeof(T00648730)+OFFSET(T00648730,statusNext)==0x1a8?1:-1];

typedef char check_path_count[OFFSET(PathView,pointCount)==0x28?1:-1];

typedef char check_path_flags[OFFSET(PathView,flags)==0x34?1:-1];

typedef char check_path_pattern[OFFSET(PathView,collisionPattern)==0x48?1:-1];

typedef char check_unit_path[OFFSET(UnitView,path)==0x2c?1:-1];

struct Obj00648750 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwFlags34;
};

struct View_00648780
{
    char gap[0x28];
    int pointCount;
};

typedef char check_offset_00648780[OFFSET(View_00648780,pointCount)==0x28?1:-1];

typedef char check_size_00648780[sizeof(View_00648780)==0x2C?1:-1];

struct View_006489C0
{
    char gap[0x8];
    int clientX;
};

typedef char check_offset_006489C0[OFFSET(View_006489C0,clientX)==0x8?1:-1];

typedef char check_size_006489C0[sizeof(View_006489C0)==0xC?1:-1];

struct View_00648AA0
{
    char gap[0x20];
    Room* previousRoom;
};

typedef char check_offset_00648AA0[OFFSET(View_00648AA0,previousRoom)==0x20?1:-1];

typedef char check_size_00648AA0[sizeof(View_00648AA0)==0x24?1:-1];

struct View_00648700
{
    char gap[0x88];
    int acceleration;
};

typedef char check_offset_00648700[OFFSET(View_00648700,acceleration)==0x88?1:-1];

typedef char check_size_00648700[sizeof(View_00648700)==0x8C?1:-1];

struct Obj00648790 { unsigned char bUnknown00[0x28]; int nValue28; };

struct Pad40_006487D0 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj006487D0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwValue28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    Pad40_006487D0 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    unsigned int dwUnknown98;
    unsigned int dwField9C;
};

struct Obj00648810 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned char nUnknown64;
    unsigned char nValue65;
};

struct Obj006488A0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned char nValue64;
    unsigned char nValue65;
};

typedef unsigned short U16;

typedef char check_word_width[sizeof(U16)==2?1:-1];

struct PathPrecisionView
{
    U32 precisionX;
};

typedef char check_precision_x[OFFSET(PathPrecisionView,precisionX)==0?1:-1];

struct PathPreviousView
{
    char retainedPrefix[0x14];
    U16 previousTargetX;
    U16 previousTargetY;
};

typedef char check_previous_x[OFFSET(PathPreviousView,previousTargetX)==0x14?1:-1];

typedef char check_previous_y[OFFSET(PathPreviousView,previousTargetY)==0x16?1:-1];

struct Obj006BCDE0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

struct Obj006489D0 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwValue0C; };

struct Obj00648A20 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned short wValue18;
};

struct Obj00648A30 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned short wUnknown18;
    unsigned short wValue1A;
};

struct Entry00648A40 {
    unsigned short wFirst;
    unsigned short wSecond;
};

struct Pad40_00648A40 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00648A40 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    int nIndex28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    Pad40_00648A40 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    Entry00648A40 tEntries98;
};

struct Entry00648A60 {
    unsigned short wFirst;
    unsigned short wSecond;
};

struct Pad40_00648A60 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00648A60 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    int nIndex28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    Pad40_00648A60 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    Entry00648A60 tEntries98;
};

struct Obj00648A80 { unsigned int dwUnknown00[7]; unsigned int dwValue1C; };

struct Obj00648AB0 { unsigned int dwUnknown00[8]; unsigned int dwValue20; };

struct Obj00648AD0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned short wValue10;
    unsigned short wValue12;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwValue58;
};

typedef signed char S8;

struct RoomFlags
{
    char pad0[0x28];
    U32 flags;
};

typedef char check_RoomFlags_flags[OFFSET(RoomFlags,flags)==0x28?1:-1];

typedef char check_RoomFlags_size[sizeof(RoomFlags)==0x2C?1:-1];

struct PathFlags
{
    char pad0[0x34];
    U32 flags;
};

typedef char check_PathFlags_flags[OFFSET(PathFlags,flags)==0x34?1:-1];

typedef char check_PathFlags_size[sizeof(PathFlags)==0x38?1:-1];

struct KeyValue
{
    U32 key;
    int value;
};

typedef char check_KeyValue_value[OFFSET(KeyValue,value)==4?1:-1];

typedef char check_KeyValue_size[sizeof(KeyValue)==8?1:-1];

struct CodeRow
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    int row;
};

typedef char check_CodeRow_row[OFFSET(CodeRow,row)==4?1:-1];

typedef char check_CodeRow_c0[OFFSET(CodeRow,c0)==0?1:-1];

typedef char check_CodeRow_c1[OFFSET(CodeRow,c1)==1?1:-1];

typedef char check_CodeRow_c2[OFFSET(CodeRow,c2)==2?1:-1];

typedef char check_CodeRow_c3[OFFSET(CodeRow,c3)==3?1:-1];

typedef char check_CodeRow_size[sizeof(CodeRow)==8?1:-1];

struct CodeOutput
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    S8 terminal;
};

typedef char check_CodeOutput_terminal[OFFSET(CodeOutput,terminal)==4?1:-1];

typedef char check_CodeOutput_c0[OFFSET(CodeOutput,c0)==0?1:-1];

typedef char check_CodeOutput_c1[OFFSET(CodeOutput,c1)==1?1:-1];

typedef char check_CodeOutput_c2[OFFSET(CodeOutput,c2)==2?1:-1];

typedef char check_CodeOutput_c3[OFFSET(CodeOutput,c3)==3?1:-1];

typedef char check_CodeOutput_size[sizeof(CodeOutput)==5?1:-1];

struct LinkView
{
    int count;
    char pad4[0x4];
    KeyValue* entries;
};

typedef char check_LinkView_entries[OFFSET(LinkView,entries)==0x8?1:-1];

typedef char check_LinkView_size[sizeof(LinkView)==0xC?1:-1];

struct CodeLink
{
    int count;
    char pad4[0x4];
    CodeRow* entries;
};

typedef char check_CodeLink_entries[OFFSET(CodeLink,entries)==0x8?1:-1];

typedef char check_CodeLink_size[sizeof(CodeLink)==0xC?1:-1];

struct Vector
{
    int x;
    int y;
};

typedef char check_Vector_y[OFFSET(Vector,y)==4?1:-1];

typedef char check_Vector_size[sizeof(Vector)==8?1:-1];

struct DirectionRecord
{
    int x;
    int y;
    int angle;
};

typedef char check_DirectionRecord_y[OFFSET(DirectionRecord,y)==4?1:-1];

typedef char check_DirectionRecord_angle[OFFSET(DirectionRecord,angle)==8?1:-1];

typedef char check_DirectionRecord_size[sizeof(DirectionRecord)==12?1:-1];

extern DirectionRecord gDirectionTable_006EB7E0[128];

struct B25TargetUnit
{
    unsigned int type;
    U8 pad4[0x8];
    unsigned int id;
};

struct B25Path
{
    U8 pad0[0x58];
    B25TargetUnit* target;
    unsigned int targetType;
    unsigned int targetId;
};

struct B25DistancePath
{
    U8 pad0[0x90];
    U8 distance;
    U8 newDistance;
};

struct B25MissileData
{
    U8 pad0[0x28];
    int targetStatus;
};

struct B25MissileUnit
{
    unsigned int type;
    U8 pad4[0x10];
    B25MissileData* data;
};

typedef char CheckTargetUnitid[(OFFSET(B25TargetUnit,id)==0xC)?1:-1];

typedef char CheckPathtarget[(OFFSET(B25Path,target)==0x58)?1:-1];

typedef char CheckPathtargetType[(OFFSET(B25Path,targetType)==0x5C)?1:-1];

typedef char CheckPathtargetId[(OFFSET(B25Path,targetId)==0x60)?1:-1];

typedef char CheckDistancePathdistance[(OFFSET(B25DistancePath,distance)==0x90)?1:-1];

typedef char CheckDistancePathnewDistance[(OFFSET(B25DistancePath,newDistance)==0x91)?1:-1];

typedef char CheckMissileDatatargetStatus[(OFFSET(B25MissileData,targetStatus)==0x28)?1:-1];

typedef char CheckMissileUnitdata[(OFFSET(B25MissileUnit,data)==0x14)?1:-1];

struct Obj00648C10 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwValue4C;
};

struct Obj00648CD0 { unsigned int dwUnknown00[20]; unsigned int dwValue50; };

struct D2Record00648E40Strc
{
    unsigned char unk_00[0x90];
    unsigned char nValue90;
};

extern "C" U16 __stdcall COLLISION_CheckMaskWithSize(ActiveRoom* room,int x,int y,int unitSize,U16 mask); // 0x0064D9B0

struct PathCollisionView
{
    char retainedGap0[0x2];
    U16 positionX;
    char retainedGap1[0x2];
    U16 positionY;
    char retainedGap2[0x14];
    ActiveRoom* room;
    char retainedGap3[0x24];
    int f_44;
    char retainedGap4[0xC];
    U16 collidedMask;
    char retainedGap5[0x26];
    int velocity;
};

typedef char check_positionX[OFFSET(PathCollisionView,positionX)==0x2?1:-1];

typedef char check_positionY[OFFSET(PathCollisionView,positionY)==0x6?1:-1];

typedef char check_room[OFFSET(PathCollisionView,room)==0x1C?1:-1];

typedef char check_unitSize[OFFSET(PathCollisionView,f_44)==0x44?1:-1];

typedef char check_collidedMask[OFFSET(PathCollisionView,collidedMask)==0x54?1:-1];

typedef char check_velocity[OFFSET(PathCollisionView,velocity)==0x7C?1:-1];

struct Pad40_00649070 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00649070 {
    Pad40_00649070 tPad000;
    Pad40_00649070 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned char nUnknown90;
    unsigned char nUnknown91;
    unsigned char nUnknown92;
    unsigned char nValue93;
};

struct Obj006490A0 { unsigned char bUnknown00[0x93]; unsigned char bValue93; };

struct Obj00649120 { unsigned char bUnknown00[0x94]; unsigned char bValue94; };

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath); // 0x00650590
static __declspec(noinline) unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo);
static __declspec(noinline) int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath);
static __declspec(noinline) int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit);

static __declspec(noinline) BOOL PATH_IsTargetDestinationAllowed(D2PathInfoStrc* pPathInfo, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_NONE;
    if (nUnitType != UNIT_MONSTER)
    {
        return TRUE;
    }

    if (MONSTERS_CanBeInTown(pUnit))
    {
        return TRUE;
    }

    D2ActiveRoomStrc* pTargetRoom = pPathInfo->pTargetRoom;
    if (!pTargetRoom)
    {
        const unsigned short nStartX = pPathInfo->tStartCoord.X;
        const unsigned short nStartY = pPathInfo->tStartCoord.Y;
        const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
        const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
        D2ActiveRoomStrc* pRoomHalfway = COLLISION_GetRoomBySubTileCoordinates(
            pPathInfo->pStartRoom,
            nStartX + (nTargetX - nStartX) / 2,
            nStartY + (nTargetY - nStartY) / 2);
        pTargetRoom = COLLISION_GetRoomBySubTileCoordinates(pRoomHalfway, nTargetX, nTargetY);
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown)
{
    if (!pPath)
    {
        return 0;
    }

    D2_ASSERT(pPath->pUnit == pUnit, LINE_PATH_UNIT);

    if (pPath->dwFlags & PATH_MISSILE_MASK)
    {
        return PATH_MissileToTarget(pPath, pUnit);
    }

    pPath->nCollidedWithMask = 0;
    D2UnitStrc* pTargetUnit = pPath->pTargetUnit;
    if (pTargetUnit && (!CLIENTS_GetUnitX(pTargetUnit) || !CLIENTS_GetUnitY(pTargetUnit)))
    {
        return 0;
    }

    D2PathInfoStrc tPathInfo;
    D2PathPointStrc tStart;
    tStart.X = pPath->tGameCoords.wPosX;
    tStart.Y = pPath->tGameCoords.wPosY;
    tPathInfo.tStartCoord = tStart;
    if (tStart.X != 0 || tStart.Y != 0)
    {
        tPathInfo.nUnitSize = pPath->dwUnitSize;
        tPathInfo.nCollisionPattern = pPath->dwCollisionPattern;
        tPathInfo.pDynamicPath = pPath;
        tPathInfo.nCollisionMask = pPath->nMoveTestCollisionMask;
        tPathInfo.nDistMax = pPath->nDistMax;
        tPathInfo.nMinimumFScoreToEvaluate = pPath->nIDAStarInitFScore;
        tPathInfo.field_14 = PATH_UpdateTargetUnit(&tPathInfo);

        if (pPath->tTargetCoord.X != 0 || pPath->tTargetCoord.Y != 0)
        {
            tPathInfo.tTargetCoord = pPath->tTargetCoord;
            if (tPathInfo.tStartCoord.X != tPathInfo.tTargetCoord.X || tPathInfo.tStartCoord.Y != tPathInfo.tTargetCoord.Y)
            {
                const int nDeltaX = tPathInfo.tTargetCoord.X - tPathInfo.tStartCoord.X;
                const int nDeltaY = tPathInfo.tTargetCoord.Y - tPathInfo.tStartCoord.Y;
                if (nDeltaX <= PATH_MAX_DISTANCE && -nDeltaX <= PATH_MAX_DISTANCE && nDeltaY <= PATH_MAX_DISTANCE && -nDeltaY <= PATH_MAX_DISTANCE)
                {
                    tPathInfo.pStartRoom = pPath->pRoom;
                    tPathInfo.pTargetRoom = COLLISION_GetRoomBySubTileCoordinates(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y);
                    if (tPathInfo.pStartRoom && tPathInfo.pTargetRoom && (PATH_IsTargetDestinationAllowed(&tPathInfo, pUnit) || bAllowInTown))
                    {
                        tPathInfo.nPathType = pPath->dwPathType;

                        D2UnitStrc* pPathTargetUnit = pPath->pTargetUnit;
                        BOOL bRemovedTargetUnitFootprint = FALSE;
                        PATH_RemoveCollisionFootprintForUnit(pUnit, FALSE);
                        if (pPathTargetUnit && UNITS_GetUnitSizeX(pPathTargetUnit) && (pPath->dwFlags & PATH_UNKNOWN_FLAG_0x00800))
                        {
                            bRemovedTargetUnitFootprint = PATH_RemoveCollisionFootprintForUnit(pPathTargetUnit, FALSE);
                        }

                        BOOL bUpdatePath = PATH_TRUE;
                        if ((pPath->dwFlags & PATH_UNKNOWN_FLAG_0x01000)
                            && COLLISION_CheckAnyCollisionWithPattern(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y, pPath->dwCollisionPattern, pPath->nMoveTestCollisionMask))
                        {
                            bUpdatePath = PATH_PreparePathTargetForPathUpdate(&tPathInfo);
                        }

                        pPath->tFinalTargetCoord.X = tPathInfo.tTargetCoord.X;
                        pPath->dwCurrentPointIdx = 0;
                        pPath->tFinalTargetCoord.Y = tPathInfo.tTargetCoord.Y;
                        pPath->dwPathPoints = 0;
                        pPath->dwCurrentPointIdx = 0;

                        int nPathPoints = 0;
                        if (bUpdatePath)
                        {
                            D2_ASSERT(!IsBadCodePtr((void*)scpfnPathFunction_006EB6D8[tPathInfo.nPathType]), LINE_PATH_FUNCTION);
                            nPathPoints = scpfnPathFunction_006EB6D8[tPathInfo.nPathType](&tPathInfo);
                        }
                        pPath->dwPathPoints = nPathPoints;

                        D2_ASSERT(tPathInfo.tStartCoord.X == tStart.X && tPathInfo.tStartCoord.Y == tStart.Y, LINE_START_COORD);

                        if (bRemovedTargetUnitFootprint)
                        {
                            PATH_AddCollisionFootprintForUnit(pPath->pTargetUnit);
                        }
                        PATH_AddCollisionFootprintForUnit(pUnit);

                        if (!pPath->dwPathPoints)
                        {
                            pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
                            return 0;
                        }

                        PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_TRUE, PATH_TRUE);
                        if (pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                        {
                            sub_6FDA8220(pPath);
                            D2PathPointStrc tPrev;
                            tPrev.X = pPath->tTargetCoord.X;
                            pPath->tPrevTargetCoord.Y = pPath->tTargetCoord.Y;
                            const unsigned int nFlags = pPath->dwFlags;
                            pPath->unk0x38 = 0;
                            pPath->tPrevTargetCoord.X = tPrev.X;
                            if (!(nFlags & PATH_UNKNOWN_FLAG_0x00010) && !pPath->pTargetUnit)
                            {
                                pPath->tTargetCoord.X = pPath->PathPoints[pPath->dwPathPoints - 1].X;
                                pPath->tTargetCoord.Y = pPath->PathPoints[pPath->dwPathPoints - 1].Y;
                            }

                            if (pPath->dwPathPoints)
                            {
                                pPath->dwFlags = nFlags | PATH_UNKNOWN_FLAG_0x00020;
                            }
                            else
                            {
                                pPath->dwFlags = nFlags & ~PATH_UNKNOWN_FLAG_0x00020;
                            }
                            return pPath->dwPathPoints;
                        }
                    }
                }
            }
        }
    }

    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
    return 0;
}

#include "gen/data/Source/D2Common/PATH/Path.inc"

// 0x00403F50
void __cdecl sub_00403F50_Nop()
{
}

// 0x00648050
static __declspec(noinline) void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo)
{
    int nY;
    const int nDeltaX = pPathInfo->tTargetCoord.X - pPathInfo->tStartCoord.X;
    const int nDeltaY = pPathInfo->tTargetCoord.Y - pPathInfo->tStartCoord.Y;
    const int nAbsDeltaX = D2_ABS(nDeltaX);
    const int nAbsDeltaY = D2_ABS(nDeltaY);
    if (nAbsDeltaX < PATH_SNAP_RANGE && nAbsDeltaY < PATH_SNAP_RANGE && (nAbsDeltaX != 0 || nAbsDeltaY != 0))
    {
        int nX = pPathInfo->tTargetCoord.X;
        const int nCollisionPattern = pPathInfo->nCollisionPattern;
        const int nCollisionMask = pPathInfo->nCollisionMask;
        const int nOffsetX = gnTable_006EB490[nDeltaY][nDeltaX];
        const int nOffsetY = gnTable_006EB490[nDeltaX][nDeltaY];
        nY = pPathInfo->tTargetCoord.Y;
        int nChebyshevDistance = D2_MAX(nAbsDeltaX, nAbsDeltaY);
        while (nChebyshevDistance < PATH_SNAP_RANGE)
        {
            nX += nOffsetX;
            nY += nOffsetY;
            if (COLLISION_CheckAnyCollisionWithPattern(pPathInfo->pStartRoom, nX, nY, nCollisionPattern, nCollisionMask))
            {
                break;
            }

            pPathInfo->tTargetCoord.X = nX;
            pPathInfo->tTargetCoord.Y = nY;
            ++nChebyshevDistance;
        }
    }
}

inline unsigned int PATH_InlineGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline unsigned int PATH_InlineGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00648120
static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2_ASSERT(!(pPath->dwFlags & PATH_MISSILE_MASK), LINE_PREPARE_MISSILE);

    const unsigned short nStartX = pPathInfo->tStartCoord.X;
    const unsigned short nStartY = pPathInfo->tStartCoord.Y;
    const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
    const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nUnitType = !pPath->pUnit ? UNIT_NONE : pPath->pUnit->dwUnitType;

    D2PathPointStrc aTestDirPathPoints[3];
    aTestDirPathPoints[0].X = nTargetX;
    aTestDirPathPoints[0].Y = nTargetY;
    aTestDirPathPoints[1].X = nTargetX;
    aTestDirPathPoints[1].Y = nTargetY;
    aTestDirPathPoints[2].X = nTargetX;
    aTestDirPathPoints[2].Y = nTargetY;

    int aTestDir[3];
    sub_6FDAB7D0(aTestDir, pPathInfo->tTargetCoord, pPathInfo->tStartCoord);
    while (1)
    {
        if (nStartX == aTestDirPathPoints[0].X && nStartY == aTestDirPathPoints[0].Y)
        {
            break;
        }

        aTestDirPathPoints[0].X += gatDirectionToOffset_006EB398[aTestDir[0]].nX;
        aTestDirPathPoints[0].Y += gatDirectionToOffset_006EB398[aTestDir[0]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[0].X, aTestDirPathPoints[0].Y, nCollisionPattern, nCollisionMask))
        {
            pPathInfo->tTargetCoord.X = aTestDirPathPoints[0].X;
            pPathInfo->tTargetCoord.Y = aTestDirPathPoints[0].Y;
            if (aTestDirPathPoints[0].X == nStartX && aTestDirPathPoints[0].Y == nStartY)
            {
                return FALSE;
            }

            if (nUnitType == UNIT_PLAYER)
            {
                PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
            }
            return PATH_TRUE;
        }

        aTestDirPathPoints[1].X += gatDirectionToOffset_006EB398[aTestDir[1]].nX;
        aTestDirPathPoints[1].Y += gatDirectionToOffset_006EB398[aTestDir[1]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[1].X, aTestDirPathPoints[1].Y, nCollisionPattern, nCollisionMask))
        {
            pPathInfo->tTargetCoord.X = aTestDirPathPoints[1].X;
            pPathInfo->tTargetCoord.Y = aTestDirPathPoints[1].Y;
            if (aTestDirPathPoints[1].X == nStartX && aTestDirPathPoints[1].Y == nStartY)
            {
                return FALSE;
            }

            if (nUnitType == UNIT_PLAYER)
            {
                PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
            }
            return PATH_TRUE;
        }

        if (aTestDir[2] != PATH_DIR_NULL)
        {
            aTestDirPathPoints[2].X += gatDirectionToOffset_006EB398[aTestDir[2]].nX;
            aTestDirPathPoints[2].Y += gatDirectionToOffset_006EB398[aTestDir[2]].nY;
            if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[2].X, aTestDirPathPoints[2].Y, nCollisionPattern, nCollisionMask))
            {
                pPathInfo->tTargetCoord.X = aTestDirPathPoints[2].X;
                pPathInfo->tTargetCoord.Y = aTestDirPathPoints[2].Y;
                if (aTestDirPathPoints[2].X == nStartX && aTestDirPathPoints[2].Y == nStartY)
                {
                    return FALSE;
                }

                if (nUnitType == UNIT_PLAYER)
                {
                    PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
                }
                return PATH_TRUE;
            }
        }

        int aNextTestDir[3];
        sub_6FDAB7D0(aNextTestDir, aTestDirPathPoints[0], pPathInfo->tStartCoord);
        aTestDir[0] = aNextTestDir[0];
    }

    return FALSE;
}

// 0x00648370
void __cdecl sub_00648370_Nop()
{
}

// 0x00648380
void __cdecl sub_00648380_Nop()
{
}

// 0x00648430
void __cdecl sub_00648430_Nop()
{
}

// 0x00648440
void __cdecl sub_00648440_Nop()
{
}

// 0x00648450
void __cdecl sub_00648450_Nop()
{
}

// 0x00648690
extern "C" __declspec(dllexport) void __stdcall sub_00648690(Obj00648690* pObj, int nValue, int nUnused3, int nUnused4) {
    if (pObj) {
        if (nValue != pObj->nValue7C) {
            pObj->nValue38 = 15;
        }
        pObj->nValue7C = nValue;
        pObj->nValue84 = nValue;
    }
}

// 0x006486D0
extern "C" __declspec(dllexport) void __stdcall sub_006486D0(Obj006486D0* pObj, unsigned int dwValue) {
    pObj->dwValue84 = dwValue;
}

// 0x00648700
extern "C" void __stdcall sub_00648700_acceleration(View_00648700* path, int value)
{
    path->acceleration = value;
}

extern "C" ActiveRoom* __fastcall DRLGACTIVATE_GetARoomInClientSight(DrlgView* drlg)
{
    T00648730* room = drlg->statusRooms[0].statusNext;
    if (room == &drlg->statusRooms[0] || !room)
    {
        room = drlg->statusRooms[1].statusNext;
        if (room == &drlg->statusRooms[1] || !room)
            return 0;
    }
    return room->activeRoom;
}

// 0x00648730
extern "C" void __stdcall sub_00648730(PathView* path)
{
    path->flags &= 0xffffffdf;
    path->pointCount = 0x0;
}

// 0x00648750
extern "C" __declspec(dllexport) void __stdcall sub_00648750(Obj00648750* pObj, int bSet) {
    if (bSet) {
        pObj->dwFlags34 |= 0x20;
    } else {
        pObj->dwFlags34 &= ~0x20;
    }
}

// 0x00648780
extern "C" int __stdcall sub_00648780_pointCount(View_00648780* path)
{
    return path->pointCount;
}

// 0x00648790
extern "C" __declspec(dllexport) void __stdcall sub_00648790(Obj00648790* pObj, int nValue) {
    if (nValue > 77) {
        nValue = 77;
    }
    pObj->nValue28 = nValue;
}

// 0x006487D0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006487D0(Obj006487D0* pObj, unsigned int** ppOut) {
    *ppOut = &pObj->dwField9C;
    return pObj->dwValue28;
}

// 0x00648810
extern "C" __declspec(dllexport) unsigned char __stdcall sub_00648810(Obj00648810* pObj) {
    return pObj->nValue65;
}

// 0x006488A0
extern "C" __declspec(dllexport) void __stdcall sub_006488A0(Obj006488A0* pObj, unsigned char nValue) {
    if (pObj) {
        unsigned char nMasked = nValue & 0x3F;
        pObj->nValue64 = nMasked;
        pObj->nValue65 = nMasked;
    }
}

// 0x006489A0
extern "C" void __stdcall PATH_SetPrecisionX(PathPrecisionView* path,U32 precisionX)
{
    path->precisionX = precisionX;
}

// 0x006489C0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006489C0(Obj006BCDE0* pObj) {
    return pObj->dwValue08;
}

// 0x006489D0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006489D0(Obj006489D0* pObj) {
    return pObj->dwValue0C;
}

// 0x00648A20
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A20(Obj00648A20* pObj) {
    return pObj->wValue18;
}

// 0x00648A30
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A30(Obj00648A30* pObj) {
    return pObj->wValue1A;
}

// 0x00648A40
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A40(Obj00648A40* pObj) {
    int nIndex = pObj->nIndex28;
    if (nIndex) {
        return (&pObj->tEntries98 + nIndex)->wFirst;
    }
    return 0;
}

// 0x00648A60
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A60(Obj00648A60* pObj) {
    int nIndex = pObj->nIndex28;
    if (nIndex) {
        return (&pObj->tEntries98 + nIndex)->wSecond;
    }
    return 0;
}

// 0x00648A80
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648A80(Obj00648A80* pObj) {
    return pObj->dwValue1C;
}

extern "C" int __stdcall sub_006489C0_clientX(View_006489C0* path)
{
    return path->clientX;
}

// 0x00648AA0
extern "C" Room* __stdcall sub_00648AA0_previousRoom(View_00648AA0* path)
{
    return path->previousRoom;
}

// 0x00648AB0
extern "C" __declspec(dllexport) void __stdcall sub_00648AB0(Obj00648AB0* pObj) {
    pObj->dwValue20 = 0;
}

// 0x00648AD0
extern "C" __declspec(dllexport) void __stdcall sub_00648AD0(Obj00648AD0* pObj, unsigned short wA, unsigned short wB) {
    if (pObj) {
        pObj->wValue10 = wA;
        pObj->wValue12 = wB;
        pObj->dwValue58 = 0;
    }
}

extern "C" void __fastcall sub_0061BAC0_portalFlag(RoomFlags* room, int reset)
{
    if (reset)
        room->flags &= ~0x400000U;
    else
        room->flags |= 0x400000U;
}

// 0x00648B40
extern "C" void __stdcall sub_00648B40_roomInvalid(PathFlags* path, int invalid)
{
    if (invalid != 0)
        path->flags |= 2U;
    else
        path->flags &= ~2U;
}

// 0x00648B90
extern "C" void __stdcall sub_00648B90_SetPathTarget(B25Path* path, B25TargetUnit* target)
{
    path->target = target;
    if (target)
    {
        path->targetType = target->type;
        path->targetId = target->id;
    }
}

// 0x00648C10
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648C10(Obj00648C10* pObj) {
    if (!pObj) {
        return 0xFFFF;
    }
    return pObj->dwValue4C;
}

// 0x00648CD0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00648CD0(Obj00648CD0* pObj) {
    return pObj->dwValue50;
}

// 0x00648E40
void __stdcall sub_00648E40_SetByte90(D2Record00648E40Strc* pRecord, unsigned char nValue)
{
    pRecord->nValue90 = nValue;
}

// 0x00648E70
extern "C" void __stdcall sub_00648E70_SetDistance(B25DistancePath* path, U8 distance)
{
    if (path)
    {
        if (distance >= 0x4D)
            distance = 0x4D;
        path->newDistance = distance;
        path->distance = distance;
    }
}

// 0x00648EB0
extern "C" U16 __stdcall sub_00648EB0(PathCollisionView* path)
{
    if (path->velocity == 0)
        path->collidedMask = COLLISION_CheckMaskWithSize(path->room,path->positionX,path->positionY,path->f_44,0x7FFF);
    return path->collidedMask;
}

// 0x00649050
extern "C" void __stdcall sub_00649050(PathPreviousView* path)
{
    path->previousTargetX = 0;
    path->previousTargetY = 0;
}

// 0x00649070
extern "C" __declspec(dllexport) void __stdcall sub_00649070(Obj00649070* pObj, unsigned char nValue) {
    if (pObj) {
        if (nValue >= 1 && nValue <= 19) {
            pObj->nValue93 = nValue - 1;
        } else {
            pObj->nValue93 = 0;
        }
    }
}

// 0x006490A0
extern "C" __declspec(dllexport) int __stdcall sub_006490A0(Obj006490A0* pObj) {
    return pObj->bValue93 + 1;
}

// 0x00649120
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00649120(Obj00649120* pObj) {
    return pObj->bValue94;
}

// 0x00649190
extern "C" void __stdcall PATH_SetUnitCollisionPattern(UnitView* unit,int collisionPattern)
{
    unit->path->collisionPattern = collisionPattern;
}

// 0x006492A0
extern "C" __declspec(dllexport) int __stdcall sub_006492A0(int nX1, int nY1, int nX2, int nY2) {
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    return nDX * nDX + nDY * nDY;
}

// 0x006492F0
static __declspec(noinline) int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tOldCoords;
    tOldCoords.X = pPath->tGameCoords.wPosX;
    tOldCoords.Y = pPath->tGameCoords.wPosY;

    pPath->dwCurrentPointIdx = 0;

    if (pPath->pTargetUnit)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPath->pTargetUnit);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPath->pTargetUnit);
    }

    int nXDistance = tOldCoords.X - pPath->tTargetCoord.X;
    if (nXDistance < 0)
    {
        nXDistance = -nXDistance;
    }
    if (nXDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    int nYDistance = tOldCoords.Y - pPath->tTargetCoord.Y;
    if (nYDistance < 0)
    {
        nYDistance = -nYDistance;
    }
    if (nYDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    if (!pPath->tTargetCoord.X || !pPath->tTargetCoord.Y)
    {
        return 0;
    }

    pPath->PathPoints[0] = pPath->tTargetCoord;
    pPath->dwPathPoints = PATH_ONE;
    pPath->unk0x38 = 0;
    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_ONE, PATH_ONE);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    if (!pRoom
        || !(pPath->tTargetCoord.X >= pRoom->tCoords.nSubtileX && pPath->tTargetCoord.X < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
            && pPath->tTargetCoord.Y >= pRoom->tCoords.nSubtileY && pPath->tTargetCoord.Y < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight))
    {
        pPath->dwFlags |= PATH_ONE;
    }
    return pPath->dwPathPoints;
}

// 0x00649760
static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit)
{
    switch (pPath->dwPathType)
    {
    case 4:
        if (PATH_ComputePathClassicMissile(pPath))
        {
            pPath->dwFlags |= 0x20;
            return pPath->dwPathPoints;
        }
        pPath->dwFlags &= ~0x20;
        return 0;
    case 10:
        PATH_ComputePathChargedBolt_6FDAB4A0(pPath, &pUnit->pSeed);
        pPath->dwFlags |= 0x20;
        return pPath->dwPathPoints;
    case 14:
        PATH_ComputePathBlessedHammer_6FDAB3C0(pPath, &pUnit->pSeed);
        pPath->dwFlags |= 0x20;
        return pPath->dwPathPoints;
    default:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x207);
        exit(-1);
    }
}

// 0x006497D0
static __declspec(noinline) unsigned char PATH_AdvanceToDoor(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* pTargetUnit = pPath->pTargetUnit;

    D2_ASSERT(UNITS_IsDoor(pTargetUnit), LINE_DOOR);

    if (UNITS_CheckIfObjectOrientationIs1(pTargetUnit))
    {
        if (pPath->tGameCoords.wPosY < PATH_InlineGetUnitY(pTargetUnit))
        {
            pPath->tTargetCoord.Y -= 2;
        }
        else
        {
            pPath->tTargetCoord.Y += 2;
        }
    }
    else
    {
        if (pPath->tGameCoords.wPosX < PATH_InlineGetUnitX(pTargetUnit))
        {
            pPath->tTargetCoord.X -= 2;
        }
        else
        {
            pPath->tTargetCoord.X += 2;
        }
    }

    return 2;
}

// 0x006498A0
static __declspec(noinline) unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* pPathTargetUnit = pPath->pTargetUnit;
    if (pPathTargetUnit)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPathTargetUnit);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPathTargetUnit);

        if (pPath->tTargetCoord.X == 0 && pPath->tTargetCoord.Y == 0)
        {
            return 0;
        }

        switch (pPathTargetUnit->dwUnitType)
        {
        case UNIT_ITEM:
            return 2;

        case UNIT_OBJECT:
            if (!UNITS_IsDoor(pPathTargetUnit))
            {
                return 2;
            }
            return PATH_AdvanceToDoor(pPathInfo);

        case UNIT_PLAYER:
        case UNIT_MONSTER:
            if (pPath->dwSpeed)
            {
                PATHUtil_AdvanceTowardsTarget_6FDAB890(pPath);
            }
            return 1;

        default:
            return 1;
        }
    }
    return 1;
}

void __stdcall D2Common_10228(D2UnitStrc* pUnit)
{
    if (pUnit->pDynamicPath)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
    }
}

// 0x00649F70
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, BOOL bForGameLogic)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (bForGameLogic || pUnit->dwUnitType != UNIT_MONSTER)
    {
        D2Common_10228(pUnit);
        COLLISION_SetMaskWithSizeXY(pPath->pRoom, pPath->wPosX, pPath->wPosY, PATH_CORPSE_SIZE, PATH_CORPSE_SIZE, COLLIDE_CORPSE);
    }
    else
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
        PATH_SetFootprintCollisionMask(pPath, COLLIDE_CORPSE);
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
    PATH_RecacheRoomIfNeeded(pPath);
}

// 0x0064A730
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(B25MissileUnit* unit)
{
    if (unit && unit->type == 3 && unit->data)
        return unit->data->targetStatus;
    return 0;
}

// 0x006BD130
extern "C" int __stdcall sub_006BD130_findKey(LinkView* link, U32 key, int unusedLogError)
{
    int upper = link->count;
    int lower = 0;
    KeyValue* entries = link->entries;
    while (lower < upper)
    {
        int middle = lower + (upper - lower) / 2;
        U32 current = entries[middle].key;
        if (key > current)
            lower = middle + 1;
        else if (key < current)
            upper = middle;
        else
            return entries[middle].value;
    }
    return -1;
}

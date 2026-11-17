#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define gnGlobal_007A7430 (gtTimedBox_007A742C.nValue)
#define gnGlobal_007A7434 (gtTimedBox_007A742C.nColor[0])
#define gnGlobal_007A7435 (gtTimedBox_007A742C.nColor[1])
#define gnGlobal_007A7436 (gtTimedBox_007A742C.nColor[2])
struct D2SaveChunkPacketStrc;
struct D2ErrorPacketStrc;
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2GfxNodeStrc;
struct D2SortEntryStrc;
struct D2HotkeyStrc;
struct D2HotkeyCommandStrc;
struct D2ByteRecordStrc;
struct D2PacketRecord6Strc;
struct D2PacketRecord7Strc;
struct D2PacketRecord8Strc;
struct D2PacketRecord11Strc;
struct D2PacketRecord13Strc;
struct D2PacketRecord15Strc;
struct D2PacketRecord21Strc;
struct D2GSPacket5AStrc;
struct D2GSPacket81Strc;
struct D2GSPacket91Strc;
struct D2Packet81ArgsStrc;
struct D2SendPacket6BStrc;
struct D2ClientTimedBoxStrc;

#pragma pack(push, 1)
struct D2SaveChunkPacketStrc
{
    unsigned char f_0;
    unsigned char nLength;
    unsigned char bFirst;
    unsigned int nTotal;
    unsigned char aData[1];
};

struct D2ErrorPacketStrc
{
    unsigned char f_0;
    int nCode;
};

#pragma pack(pop)

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __cdecl sub_0045C520_SaveCharFile(); // 0x0045C520
void __fastcall sub_0044E380_SetConnectionError(int nError); // 0x0044E380
extern unsigned char* gpSaveBuffer_007A5224; // 0x007A5224
extern unsigned int gnSaveBufferSize_007A5228; // 0x007A5228
extern int gdwGlobal_007A0618; // 0x007A0618

enum D2C_CA2Constants
{
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
    LEVEL_8 = 8,
    LEVEL_107 = 107,
    LEVEL_108 = 108,
    MODE_2 = 2,
    VK_MENU = 0x12,
    VK_F4 = 0x73,
    NUM_HOTKEYS = 114,
    NUM_HOTKEY_COMMANDS = 0x39,
    GRID_SIZE = 48,
};

typedef int (__stdcall* FARPROC)();

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        int wParam;
        struct
        {
            unsigned short wParamLow;
            unsigned short wParamHigh;
        };
    };
    union
    {
        int lParam;
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
    };
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    char unk0x04[0x24];
    unsigned short nClientFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

struct D2GfxNodeStrc
{
    int nType;
    int nId;
    int nValue;
    char unk0x0C[0x98];
    D2GfxNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x2C];
    D2GfxNodeStrc* pNodeList2C;
};

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

struct D2SortEntryStrc
{
    int nKey;
    unsigned char unk0x04[2];
    unsigned char nFlag[4];
};

struct D2HotkeyStrc
{
    unsigned char nCommand[4];
    unsigned short nKey;
    unsigned char unk0x06[4];
};

struct D2HotkeyCommandStrc
{
    void (__cdecl* pfnCommand)();
    int unk0x04;
    int nModeFlag;
};

struct D2ByteRecordStrc
{
    char unk0x00[0x25];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_27;
};

struct D2GridCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
};

struct D2PacketRecord7Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
};

struct D2PacketRecord8Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
};

struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
};

struct D2PacketRecord13Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
};

struct D2PacketRecord15Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
    unsigned char unk0x0D;
    unsigned char unk0x0E;
};

struct D2PacketRecord21Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
    unsigned char unk0x0D;
    unsigned char unk0x0E;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char unk0x11;
    unsigned char unk0x12;
    unsigned char unk0x13;
    unsigned char unk0x14;
};

struct D2GSPacket5AStrc
{
    int nData00;
    int nData04;
    int nData08;
    int nData0C;
    int nData10;
    int f_14;
    int nData18;
    int nData1C;
    int nData20;
    int nData24;
};

struct D2GSPacket81Strc
{
    unsigned char nHeader;
    unsigned char nByte01;
    unsigned short nWord02;
    int nArg04;
    int nArg08;
    int nArg0C;
    int nArg10;
};

struct D2GSPacket91Strc
{
    unsigned short nData00;
    unsigned short nData02;
    unsigned short nData04;
    unsigned short nData06;
    unsigned short nData08;
    unsigned short nData0A;
    unsigned short nData0C;
    unsigned short nData0E;
    unsigned short nData10;
    unsigned short nData12;
    unsigned short f_14;
    unsigned short nData16;
    unsigned short nData18;
};

struct D2Packet81ArgsStrc
{
    int nArg0C;
    int nArg10;
    int nZero;
};

struct D2SendPacket6BStrc
{
    unsigned char nHeader;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
void __fastcall sub_0049EB10(D2GSPacket5AStrc* pPacket); // 0x0049EB10
void __fastcall sub_004B6390(D2PacketRecord15Strc* pPacket); // 0x004B6390
void __fastcall sub_004C4620(D2PacketRecord8Strc* pPacket); // 0x004C4620
void __fastcall sub_004C2020(D2PacketRecord13Strc* pPacket); // 0x004C2020
void __fastcall sub_004C1BC0(D2PacketRecord11Strc* pPacket, int nArg); // 0x004C1BC0
void __fastcall sub_004C1BF0(D2PacketRecord11Strc* pPacket); // 0x004C1BF0
void __fastcall sub_004B9210(D2PacketRecord15Strc* pPacket); // 0x004B9210
void __fastcall sub_004B3240(D2PacketRecord7Strc* pPacket); // 0x004B3240
void __fastcall sub_004C0550(D2PacketRecord7Strc* pPacket); // 0x004C0550
void __fastcall sub_004A2CB0(int nArg, D2PacketRecord6Strc* pPacket); // 0x004A2CB0
void __fastcall sub_004B3510(D2GSPacket91Strc* pPacket); // 0x004B3510
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit(); // 0x00463DE0
void __fastcall sub_004BDF30(D2PacketRecord7Strc* pPacket); // 0x004BDF30
void __fastcall sub_0049CF90(D2PacketRecord21Strc* pPacket); // 0x0049CF90
void __fastcall sub_004B9010(D2PacketRecord21Strc* pPacket); // 0x004B9010
void __fastcall sub_00478BB0(int nArg08, int nArg04, unsigned char nByte01, unsigned short nWord02, D2Packet81ArgsStrc* pArgs); // 0x00478BB0
void __fastcall sub_004C51B0(D2PacketRecord6Strc* pPacket); // 0x004C51B0
void __fastcall sub_004B3380(D2PacketRecord6Strc* pPacket); // 0x004B3380
void __cdecl sub_0044DA70(); // 0x0044DA70
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall sub_00619EE0(D2ActiveRoomStrc* pRoom); // 0x00619EE0
void __stdcall sub_00619F20(D2ActiveRoomStrc* pRoom); // 0x00619F20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall sub_0046BD50(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0046BD50
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0
int __stdcall sub_0061C0E0(void* pAct); // 0x0061C0E0
extern int gnGlobal_007A5248; // 0x007A5248
extern int gnGlobal_007A5254; // 0x007A5254
extern int gnGlobal_007A5258; // 0x007A5258
extern int gnGlobal_007A6B08; // 0x007A6B08
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90
extern D2HotkeyCommandStrc gtHotkeyCommands_00712698[]; // 0x00712698
extern int gnGlobal_007A7418; // 0x007A7418
extern int gnGlobal_007A7460; // 0x007A7460

struct D2ClientTimedBoxStrc
{
    int bActive;
    int nValue;
    unsigned char nColor[4];
    int nFadeIn;
    int nFadeOut;
    int nHold;
    int nTotal;
    int nTick;
    int nAngle;
    int nLevelId;
    int bLocked;
};

extern D2ClientTimedBoxStrc gtTimedBox_007A742C; // 0x007A742C
extern void* gpGlobal_007A0634; // 0x007A0634
extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68
extern unsigned char gRowTable_007B5C10[][0x100]; // 0x007B5C10
extern int gnGlobal_007B8D10; // 0x007B8D10
extern int gnSentBytes_007A6AF8; // 0x007A6AF8
extern int gnSentPackets_007A6B00; // 0x007A6B00

static void sub_0045C620_ReceiveSaveChunk(D2SaveChunkPacketStrc* pPacket)
{
    if (gpSaveBuffer_007A5224 && pPacket->bFirst)
    {
        FOG_Free(gpSaveBuffer_007A5224, ".\\GAME\\SCmd.cpp", 0x5B, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }

    if (!gpSaveBuffer_007A5224)
        gpSaveBuffer_007A5224 = (unsigned char*)FOG_Alloc(pPacket->nTotal, ".\\GAME\\SCmd.cpp", 0x62, 0);

    unsigned int nSize = gnSaveBufferSize_007A5228;
    unsigned char* pDest = gpSaveBuffer_007A5224 + nSize;
    const unsigned char* pSource = pPacket->aData;
    for (int i = 0; i < pPacket->nLength; i++)
        *pDest++ = *pSource++;

    nSize += pPacket->nLength;
    gnSaveBufferSize_007A5228 = nSize;
    if (pPacket->nTotal == nSize)
    {
        sub_0045C520_SaveCharFile();
        FOG_Free(gpSaveBuffer_007A5224, ".\\GAME\\SCmd.cpp", 0x71, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }
}

static void sub_0045C6D0_HandleErrorPacket(D2ErrorPacketStrc* pPacket)
{
    switch (pPacket->nCode)
    {
    case 1: sub_0044E380_SetConnectionError(0); return;
    case 2: sub_0044E380_SetConnectionError(1); return;
    case 3: sub_0044E380_SetConnectionError(2); return;
    case 4: sub_0044E380_SetConnectionError(3); return;
    case 5: sub_0044E380_SetConnectionError(4); return;
    case 6: sub_0044E380_SetConnectionError(5); return;
    case 7: sub_0044E380_SetConnectionError(0x0A); return;
    case 8: sub_0044E380_SetConnectionError(0x0B); return;
    case 9: sub_0044E380_SetConnectionError(0x0C); return;
    case 10: sub_0044E380_SetConnectionError(0x0D); return;
    case 11: sub_0044E380_SetConnectionError(0x0E); return;
    case 12: sub_0044E380_SetConnectionError(0x0F); return;
    case 13: sub_0044E380_SetConnectionError(0x10); return;
    case 14: sub_0044E380_SetConnectionError(0x11); return;
    case 15: sub_0044E380_SetConnectionError(0x12); return;
    case 16: sub_0044E380_SetConnectionError(0x13); return;
    case 17: sub_0044E380_SetConnectionError(0x14); return;
    case 18: sub_0044E380_SetConnectionError(0x15); return;
    case 19: sub_0044E380_SetConnectionError(0x16); return;
    case 20: sub_0044E380_SetConnectionError(0x17); return;
    case 21: sub_0044E380_SetConnectionError(0x18); return;
    case 24: sub_0044E380_SetConnectionError(0x1A); return;
    case 23: sub_0044E380_SetConnectionError(0x19); return;
    case 26: sub_0044E380_SetConnectionError(0x1C); return;
    case 25: sub_0044E380_SetConnectionError(0x1B); return;
    }
    sub_0044E380_SetConnectionError(9);
}

// 0x0045C850
void __fastcall sub_0045C850_HandleSystemPacket(unsigned char* pPacket, int nSize)
{
    if (nSize == -1)
        return;

    switch (pPacket[0])
    {
    case 0xAF:
        gdwGlobal_007A0618 = 1;
        return;
    case 0xB0:
        gdwGlobal_007A0618 = 0;
        return;
    case 0xB3:
        sub_0045C620_ReceiveSaveChunk((D2SaveChunkPacketStrc*)pPacket);
        return;
    case 0xB4:
        sub_0045C6D0_HandleErrorPacket((D2ErrorPacketStrc*)pPacket);
        return;
    }
}

int gnGlobal_007B8D14; // 0x007B8D14

int gnGlobal_007B8D18; // 0x007B8D18

int gnGlobal_007B8D1C; // 0x007B8D1C

int gnGlobal_007B9534; // 0x007B9534

// 0x0045E070
void __fastcall sub_0045E070_Packet5A(const D2GSPacket5AStrc* pPacket)
{
    D2GSPacket5AStrc tPacket = *pPacket;
    sub_0049EB10(&tPacket);
}

// 0x0045E0D0
void __fastcall sub_0045E0D0_Packet2A(const D2PacketRecord15Strc* pPacket)
{
    D2PacketRecord15Strc tPacket = *pPacket;
    sub_004B6390(&tPacket);
}

// 0x0045E220
void __fastcall sub_0045E220_Packet3F(const D2PacketRecord8Strc* pPacket)
{
    D2PacketRecord8Strc tPacket = *pPacket;
    sub_004C4620(&tPacket);
}

// 0x0045E240
void __fastcall sub_0045E240_Packet40(const D2PacketRecord13Strc* pPacket)
{
    D2PacketRecord13Strc tPacket = *pPacket;
    sub_004C2020(&tPacket);
}

// 0x0045E2A0
void __fastcall sub_0045E2A0_Packet47(const D2PacketRecord11Strc* pPacket)
{
    D2PacketRecord11Strc tPacket = *pPacket;
    sub_004C1BC0(&tPacket, 1);
}

// 0x0045E2D0
void __fastcall sub_0045E2D0_Packet48(const D2PacketRecord11Strc* pPacket)
{
    D2PacketRecord11Strc tPacket = *pPacket;
    sub_004C1BF0(&tPacket);
}

// 0x0045E370
void __fastcall sub_0045E370_Packet50(const D2PacketRecord15Strc* pPacket)
{
    D2PacketRecord15Strc tPacket = *pPacket;
    sub_004B9210(&tPacket);
}

// 0x0045E3D0
void __fastcall sub_0045E3D0_Packet4E(const D2PacketRecord7Strc* pPacket)
{
    D2PacketRecord7Strc tPacket = *pPacket;
    sub_004B3240(&tPacket);
}

// 0x0045E490
void __fastcall sub_0045E490_Packet58(const D2PacketRecord7Strc* pPacket)
{
    D2PacketRecord7Strc tPacket = *pPacket;
    sub_004C0550(&tPacket);
}

// 0x0045E540
void __fastcall sub_0045E540_Packet5D(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    sub_004A2CB0(1, &tPacket);
}

// 0x0045E580
void __fastcall sub_0045E580_Packet91(const D2GSPacket91Strc* pPacket)
{
    D2GSPacket91Strc tPacket = *pPacket;
    sub_004B3510(&tPacket);
}

// 0x0045E610
void __fastcall sub_0045E610_Packet60(const D2PacketRecord7Strc* pPacket)
{
    D2PacketRecord7Strc tPacket = *pPacket;
    D2_ASSERT(sub_00463DE0_GetStoredUnit(), 3361);
    sub_004BDF30(&tPacket);
}

// 0x0045E670
void __fastcall sub_0045E670_Packet63(const D2PacketRecord21Strc* pPacket)
{
    D2PacketRecord21Strc tPacket = *pPacket;
    sub_0049CF90(&tPacket);
}

// 0x0045E810
void __fastcall sub_0045E810_Packet78(const D2PacketRecord21Strc* pPacket)
{
    D2PacketRecord21Strc tPacket = *pPacket;
    sub_004B9010(&tPacket);
}

// 0x0045E890
void __fastcall sub_0045E890_Packet81(const D2GSPacket81Strc* pPacket)
{
    D2Packet81ArgsStrc tArgs;
    tArgs.nArg0C = pPacket->nArg0C;
    tArgs.nArg10 = pPacket->nArg10;
    tArgs.nZero = 0;
    sub_00478BB0(pPacket->nArg08, pPacket->nArg04, pPacket->nByte01, pPacket->nWord02, &tArgs);
}

// 0x0045E910
void __fastcall sub_0045E910_Packet7C(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    sub_004C51B0(&tPacket);
}

// 0x0045EA40
void __fastcall sub_0045EA40_Packet8A(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    sub_004B3380(&tPacket);
}

// 0x0045FF70
void __stdcall sub_0045FF70_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A5254 = 1;
    gnGlobal_007A5248 = 0;
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004603E0
void __stdcall sub_004603E0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A5258 = 1;
    gnGlobal_007A5248 = 0;
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00460730
void __fastcall sub_00460730_SetMonsterClientFlags(D2UnitStrc* pUnit, unsigned short nFlags, int bSet)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        if (bSet)
        {
            pUnit->pMonsterData->nClientFlags |= nFlags;
        }
        else
        {
            pUnit->pMonsterData->nClientFlags &= ~nFlags;
        }
    }
}

// 0x00463C00
void __fastcall sub_00463C00_OnModeChange(D2UnitStrc* pUnit, unsigned char nOldMode, unsigned char nNewMode)
{
    int nOld = nOldMode;
    int nNew = nNewMode;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nOld != nNew)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom)
        {
            if (nNew == MODE_2)
            {
                sub_00619EE0(pRoom);
            }
            else if (nOld == MODE_2)
            {
                sub_00619F20(pRoom);
            }
            D2Common_10214(pUnit);
        }
    }
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x00463EE0
int __fastcall sub_00463EE0_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY)
{
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 1419);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2TileRectStrc* pRect = sub_00619620(pRoom, pUnit);
    if (!pRect)
    {
        return 0;
    }

    int nUnitX = UNITS_GetXPositionInline(pUnit);
    int nUnitY = UNITS_GetYPositionInline(pUnit);
    sub_00643260(&nUnitX, &nUnitY);

    const int nLeft = pRect->nX + nUnitX;
    const int nTop = pRect->nY + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= nLeft + pRect->nWidth && nY <= nTop + pRect->nHeight)
    {
        return 1;
    }
    return 0;
}

// build: context sub_00467EF0_MsgHandler
void __stdcall sub_00467EF0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        gnGlobal_007A6B08 = 0;
        sub_004F59F0(0);
    }
    else
    {
        gnGlobal_007A6B08 = 0;
    }
    pMsg->lResult = 0;
    pMsg->bUseResult = 0;
}

// 0x00469450
int __cdecl sub_00469450_CompareEntries(const void* pA, const void* pB)
{
    const D2SortEntryStrc* pLeft = (const D2SortEntryStrc*)pA;
    const D2SortEntryStrc* pRight = (const D2SortEntryStrc*)pB;
    if (pLeft->nKey < pRight->nKey)
    {
        return -1;
    }
    if (pLeft->nKey > pRight->nKey)
    {
        return 1;
    }
    if (*(const int*)pLeft->nFlag)
    {
        return *(const int*)pRight->nFlag ? 0 : -1;
    }
    return *(const int*)pRight->nFlag ? 1 : 0;
}

// 0x0046A840
void __stdcall sub_0046A840_HotkeyMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam & 0x40000000)
    {
        return;
    }

    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey == pMsg->wParam && *(int*)gtHotkeys_007A6F90[i].nCommand != 0xFFFF
            && *(int*)gtHotkeys_007A6F90[i].nCommand < NUM_HOTKEY_COMMANDS && *(int*)gtHotkeys_007A6F90[i].nCommand <= 0xDF
            && gtHotkeyCommands_00712698[*(int*)gtHotkeys_007A6F90[i].nCommand].pfnCommand)
        {
            if (gtHotkeys_007A6F90[i].nKey == VK_F4 && (GetKeyState(VK_MENU) & 0x8000))
            {
                return;
            }

            if (gnGlobal_007A7418 == 2 && !gtHotkeyCommands_00712698[*(int*)gtHotkeys_007A6F90[i].nCommand].nModeFlag)
            {
                return;
            }

            D2_ASSERT(!IsBadCodePtr((FARPROC)gtHotkeyCommands_00712698[*(int*)gtHotkeys_007A6F90[i].nCommand].pfnCommand), 2038);
            gtHotkeyCommands_00712698[*(int*)gtHotkeys_007A6F90[i].nCommand].pfnCommand();
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}

// 0x0046BDD0
int __fastcall sub_0046BDD0_GetLevelLight(D2ActiveRoomStrc* pRoom, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    switch (DUNGEON_GetLevelIdFromRoom(pRoom))
    {
    case LEVEL_8:
        return sub_0046BD50(pRed, pGreen, pBlue);

    case LEVEL_107:
    case LEVEL_108:
        if (gnGlobal_007A7460 && gnGlobal_007129D0 == -1)
        {
            *pRed = 0xFF;
            *pGreen = 0x40;
            *pBlue = 0x30;
            return 0xA0;
        }
        return 0;

    default:
        *pRed = gnGlobal_007A7434;
        *pGreen = gnGlobal_007A7435;
        *pBlue = gnGlobal_007A7436;
        return gnGlobal_007A7430;
    }
}

// 0x0046E150
void __fastcall sub_0046E150_SetGfxNodeValue(D2UnitStrc* pUnit, int nId, int nValue)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 510);

    for (D2GfxNodeStrc* pNode = pGfxData->pNodeList2C; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
        {
            D2_ASSERT(pNode->nType == 1, 517);
            pNode->nValue = nValue;
        }
    }
}

// 0x00474390
void __fastcall sub_00474390_SetRecordBytes(D2ByteRecordStrc* pRecord, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2)
{
    D2_ASSERT(pRecord, 359);
    pRecord->nValue0 = nValue0;
    pRecord->nValue1 = nValue1;
    pRecord->f_27 = nValue2;
}

// 0x00474550
void __fastcall sub_00474550_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int bLevelLight)
{
    unsigned char nRed = 0;
    unsigned char nGreen = 0;
    unsigned char nBlue = 0;
    int nIntensity;

    if (bLevelLight)
    {
        nIntensity = sub_0046BDD0_GetLevelLight(pRoom, &nRed, &nGreen, &nBlue);
        if (nRed || nGreen || nBlue)
        {
            goto out;
        }
    }

    unsigned char nRoomIntensity;
    sub_00619D70(pRoom, &nRoomIntensity, &nRed, &nGreen, &nBlue);
    nIntensity = nRoomIntensity;
    if (!nRed && !nGreen && !nBlue)
    {
        sub_0061C0B0(gpGlobal_007A0634, &nRed, &nGreen, &nBlue);
        nIntensity = sub_0061C0E0(gpGlobal_007A0634);
    }

out:
    *pIntensity = nIntensity;
    *pRed = nRed;
    *pGreen = nGreen;
    *pBlue = nBlue;
}

// 0x00475AA0
void __fastcall sub_00475AA0_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3)
{
    int nCellX = (nX >> 3) - gnGlobal_007B0A54;
    int nCellY = (nY >> 3) - gnGlobal_007B0A58;

    if (nCellX < 0)
    {
        nCellX = 0;
    }
    else if (nCellX > GRID_SIZE - 1)
    {
        nCellX = GRID_SIZE - 1;
    }

    if (nCellY < 0)
    {
        nCellY = 0;
    }
    else if (nCellY > GRID_SIZE - 1)
    {
        nCellY = GRID_SIZE - 1;
    }

    D2GridCellStrc* pCell = &gtGridCells_007B0E68[nCellY * GRID_SIZE + nCellX];
    *pValue0 = pCell->nValue0;
    if (gnGlobal_00712B8C)
    {
        *pValue1 = pCell->nValue1;
        *pValue2 = pCell->f_6;
        *pValue3 = pCell->nValue3;
    }
}

// 0x00475D30
unsigned char** __stdcall sub_00475D30_BuildRampTable(unsigned int nSize, int nSteps)
{
    unsigned char** ppTable = (unsigned char**)sub_00517993_VirtualAlloc(nSize * nSize * nSteps * sizeof(unsigned char*));
    unsigned char** ppEntry = ppTable;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSize; ++j)
        {
            const int nStep = ((j - i) << 16) / nSteps;
            int nValue = i << 16;
            for (unsigned int k = 0; k < nSteps; ++k)
            {
                *ppEntry = gRowTable_007B5C10[(unsigned char)(nValue / 0x10000)];
                ++ppEntry;
                nValue += nStep;
            }
        }
    }
    return ppTable;
}

// 0x00476A80
void __fastcall sub_00476A80_SetTimedState(int nArg0, int nArg1, int nArg2, int nArg3)
{
    if (nArg2)
    {
        gnGlobal_007B8D10 = GetTickCount();
        gnGlobal_007B8D14 = nArg1;
        gnGlobal_007B8D18 = nArg2;
        gnGlobal_007B8D1C = nArg3;
        gnGlobal_007B9534 = nArg0;
    }
}

// 0x00477DA0
void __cdecl sub_00477DA0()
{
    D2SendPacket6BStrc tPacket;
    tPacket.nHeader = 0x6B;
    sub_0052AE50_SendPacket(sizeof(D2SendPacket6BStrc), 0, &tPacket);
    gnSentBytes_007A6AF8 += sizeof(D2SendPacket6BStrc);
    gnSentPackets_007A6B00 += 1;
}

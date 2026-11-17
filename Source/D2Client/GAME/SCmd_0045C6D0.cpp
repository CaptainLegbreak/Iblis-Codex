#include "D2Client.h"

struct Unicode;
struct D2SaveChunkPacketStrc;
struct D2ErrorPacketStrc;
struct D2ClientSightPacketStrc;
struct D2GSPacketSrvAE;

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

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);
void __cdecl sub_0045C520_SaveCharFile();
void __fastcall sub_0044E380_SetConnectionError(int nError);
extern "C" const char szSCmdCppFile_006D69E4[];
extern unsigned char* gpSaveBuffer_007A5224;
extern unsigned int gnSaveBufferSize_007A5228;
extern int gdwGlobal_007A0618;

#pragma pack(push, 1)
struct D2ClientSightPacketStrc
{
    unsigned char unk0x00;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};

#pragma pack(pop)
extern "C" void* gpAct_007A0634; // 0x007A0634
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl sub_00463DD0(); // 0x00463DD0
extern "C" void* __stdcall UNITS_GetRoom(void* pUnit); // 0x00620BB0
extern "C" void __stdcall DUNGEON_SetClientIsInSight(void* pAct, int nLevelId, int nX, int nY, void* pRoom); // 0x0061A070
extern "C" void __stdcall DUNGEON_UnsetClientIsInSight(void* pAct, int nLevelId, int nX, int nY, void* pRoom); // 0x0061A0C0

#pragma pack(push, 1)
struct D2GSPacketSrvAE
{
    unsigned char nHeader;
    unsigned short nLength;
    unsigned char pData[1];
};

#pragma pack(pop)
void __fastcall sub_004802E0(unsigned char* pData, int nLength); // 0x004802E0
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_007A285C; // 0x007A285C
extern int gnGlobal_007A5254; // 0x007A5254

static void sub_0045C620_ReceiveSaveChunk(D2SaveChunkPacketStrc* pPacket)
{
    if (gpSaveBuffer_007A5224 && pPacket->bFirst)
    {
        FOG_Free(gpSaveBuffer_007A5224, szSCmdCppFile_006D69E4, 0x5B, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }

    if (!gpSaveBuffer_007A5224)
        gpSaveBuffer_007A5224 = (unsigned char*)FOG_Alloc(pPacket->nTotal, szSCmdCppFile_006D69E4, 0x62, 0);

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
        FOG_Free(gpSaveBuffer_007A5224, szSCmdCppFile_006D69E4, 0x71, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }
}

// 0x0045C6D0
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

// 0x0045CAB0
void __fastcall sub_0045CAB0_SetClientSight(D2ClientSightPacketStrc* pPacket)
{
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    if (!gpAct_007A0634)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x58A);
        exit(-1);
    }
    void* pPlayer = sub_00463DD0();
    void* pRoom = pPlayer ? UNITS_GetRoom(pPlayer) : 0;
    DUNGEON_SetClientIsInSight(gpAct_007A0634, pPacket->nLevelId, nX, nY, pRoom);
}

// 0x0045CB20
void __fastcall sub_0045CB20_ClearClientSight(D2ClientSightPacketStrc* pPacket)
{
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    if (!gpAct_007A0634)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x59E);
        exit(-1);
    }
    void* pPlayer = sub_00463DD0();
    void* pRoom = pPlayer ? UNITS_GetRoom(pPlayer) : 0;
    DUNGEON_UnsetClientIsInSight(gpAct_007A0634, pPacket->nLevelId, nX, nY, pRoom);
}

// 0x0045F5F0
void __fastcall sub_0045F5F0_GamePacketAE(D2GSPacketSrvAE* pPacket)
{
    if (gdwGlobal_007A0610 == 2 || gdwGlobal_007A0610 == 3)
        sub_004802E0(pPacket->pData, pPacket->nLength);
}

// 0x0045FC60
void __cdecl sub_0045FC60_DrawLoadingTexts()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xBE - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
    if (sub_00408F20_HasExpansionMpq())
        sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x5578), 0);
    else
        sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1431), 0);
    sub_00502EF0(nOldFont);
}

// 0x0045FFB0
void __stdcall sub_0045FFB0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A5254 = 0;
}

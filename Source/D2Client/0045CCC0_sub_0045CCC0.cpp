extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum D2C_F23Constants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    ITEMSTATCOSTFLAGINDEX_SIGNED = 1,
    STAT_ID_END = 0x1FF,
    STATE_ID_END = 0xFF,
};

struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4];
    unsigned int dwFlagEx;
};

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2ItemStatCostTxt
{
    unsigned short wStatId;
    unsigned short pad0x02;
    unsigned char nItemStatFlags[4];
    unsigned char nSendBits;
    unsigned char nSendParamBits;
    char unk0x0A[0x13A];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[4];
    int nItemStatCostTxtRecordCount;
};

struct D2GSPacketSrv0D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nHitClass;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char nHitType;
    unsigned char nUnitLifePct;
};

struct D2ClientUnitUpdateStrc
{
    unsigned char nUnitType;
    unsigned char nUnitGUID[4];
    unsigned char nX[2];
    unsigned char nY[2];
};

struct D2GSPacketSrv16
{
    unsigned char nHeader;
    unsigned char nSize[2];
    unsigned char nNumUpdates;
    D2ClientUnitUpdateStrc unitUpdate[1];
};

struct D2GSPacketSrv93
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
};

struct D2GSPacketSrv27Strc
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

struct D2GSPacketSrv3E
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned char pBuffer[32];
};

struct D2GSPacketSrv42Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
};

struct D2GSPacketSrv74Strc
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
};

struct D2GSPacketSrv7DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
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
};

struct D2GSPacketSrv82
{
    unsigned char nHeader;
    unsigned char dwOwnerGUID[4];
    char szOwnerName[16];
    unsigned char dwPortalGUID0[4];
    unsigned char dwPortalGUID1[4];
};

struct D2GSPacketSrvA8
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitId[4];
    unsigned char nSize;
    unsigned char nState;
    unsigned char pStream[1];
};

struct D2GSPacketSrvAA
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitId[4];
    unsigned char nSize;
    unsigned char pStream[1];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern void* gpGlobal_007BB384;                                                                             // 0x007BB384

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);        // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits);                                     // 0x00411030
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_00462F60(D2GSPacketSrv74Strc* pPacket);                                                 // 0x00462F60
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __fastcall sub_0047A270(int nOwnerGUID, int nPortalGUID0, int nPortalGUID1);                           // 0x0047A270
void __fastcall sub_0047A690(int nUnitGUID, unsigned char nLifePct);                                        // 0x0047A690
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10
void __fastcall sub_004A1600(D2GSPacketSrv27Strc* pPacket);                                                 // 0x004A1600
void __fastcall sub_004BDFE0_SetObjectName(D2UnitStrc* pUnit, const char* szName);                          // 0x004BDFE0
void __fastcall sub_004C1F30(unsigned int nA, unsigned char nB, unsigned int nC, unsigned int nD, unsigned short nE); // 0x004C1F30
void __fastcall sub_004C2050(D2GSPacketSrv42Strc* pPacket);                                                 // 0x004C2050
void __fastcall sub_004C2270(D2GSPacketSrv7DStrc* pPacket);                                                 // 0x004C2270
void __fastcall sub_004C7990(D2UnitStrc* pUnit, int nA, int nB, char nC);                                   // 0x004C7990
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D9B20_BeginState(D2UnitStrc* pUnit, int nState);                                    // 0x004D9B20
int __fastcall sub_004D9D70_SetStateStat(D2UnitStrc* pUnit, int nPrev, int nState, int nStatId, int nValue, int nLayer); // 0x004D9D70
void __fastcall sub_004D9E60_EndState(D2UnitStrc* pUnit, int nState);                                      // 0x004D9E60
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620

// 0x0045CCC0
void __fastcall sub_0045CCC0(D2UnitStrc* pUnit, const D2GSPacketSrv0D* pPacket)
{
    const int nUnitGUID = *(const int*)pPacket->dwUnitGUID;
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nX;
    args[1] = *(const unsigned short*)pPacket->nY;
    args[2] = pPacket->nHitType;
    sub_00480C10_UnitEvent(pPacket->nHitClass, pUnit, args, 1);
    if (pPacket->nUnitType == UNIT_PLAYER)
    {
        sub_0047A690(nUnitGUID, pPacket->nUnitLifePct);
    }
}

// 0x0045D2E0
void __fastcall sub_0045D2E0_Packet16(const D2GSPacketSrv16* pPacket)
{
    D2_ASSERT(pPacket->nNumUpdates, 2133);

    const D2ClientUnitUpdateStrc* pUpdate = pPacket->unitUpdate;
    for (int i = 0; i < pPacket->nNumUpdates; ++i)
    {
        unsigned short nX = *(const unsigned short*)pUpdate->nX;
        unsigned short nY = *(const unsigned short*)pUpdate->nY;
        D2UnitStrc* pUnit = sub_00463990(*(const int*)pUpdate->nUnitGUID, pUpdate->nUnitType);
        if (pUnit)
        {
            sub_004804E0_SetPosition(pUnit, nX, nY, 0, 0, 0);
        }
        ++pUpdate;
    }
}

// 0x0045DD10
void __fastcall sub_0045DD10_Packet93(const D2GSPacketSrv93* pPacket)
{
    const int nUnitGUID = *(const int*)pPacket->nUnitGUID;
    int nValue = pPacket->unk0x05;
    if (nValue > 0x80)
        nValue -= 0x100;
    const int nB = pPacket->unk0x06;
    const char nC = pPacket->unk0x07;

    D2UnitStrc* pUnit = sub_00463990(nUnitGUID, UNIT_PLAYER);
    if (pUnit)
    {
        sub_004C7990(pUnit, nValue, nB, nC);
    }
}

// 0x0045E0A0
void __fastcall sub_0045E0A0_Packet27(const D2GSPacketSrv27Strc* pPacket)
{
    D2GSPacketSrv27Strc tPacket = *pPacket;
    sub_004A1600(&tPacket);
}

// 0x0045E130
void __fastcall sub_0045E130_Packet3E(D2GSPacketSrv3E* pPacket)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pBuffer, pPacket->nSize - 2);

    unsigned int nA;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nA = sub_00411020_ReadBits(&tBuffer, 8);
    else if (!sub_00411020_ReadBits(&tBuffer, 1))
        nA = sub_00411020_ReadBits(&tBuffer, 16);
    else
        nA = sub_00411020_ReadBits(&tBuffer, 32);

    const unsigned char nB = sub_00411020_ReadBits(&tBuffer, 1);
    const unsigned int nC = sub_00411020_ReadBits(&tBuffer, 9);

    unsigned int nD;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nD = sub_00411020_ReadBits(&tBuffer, 8);
    else if (!sub_00411020_ReadBits(&tBuffer, 1))
        nD = sub_00411020_ReadBits(&tBuffer, 16);
    else
        nD = sub_00411020_ReadBits(&tBuffer, 32);

    unsigned short nE;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nE = sub_00411020_ReadBits(&tBuffer, 8);
    else
        nE = sub_00411020_ReadBits(&tBuffer, 16);

    sub_004C1F30(nA, nB, nC, nD, nE);
}

// 0x0045E270
void __fastcall sub_0045E270_Packet42(const D2GSPacketSrv42Strc* pPacket)
{
    D2GSPacketSrv42Strc tPacket = *pPacket;
    sub_004C2050(&tPacket);
}

// 0x0045E7B0
void __fastcall sub_0045E7B0_Packet74(const D2GSPacketSrv74Strc* pPacket)
{
    D2GSPacketSrv74Strc tPacket = *pPacket;
    sub_00462F60(&tPacket);
}

// 0x0045E930
void __fastcall sub_0045E930_Packet7D(const D2GSPacketSrv7DStrc* pPacket)
{
    D2GSPacketSrv7DStrc tPacket = *pPacket;
    sub_004C2270(&tPacket);
}

// 0x0045E9D0
void __fastcall sub_0045E9D0_Packet82(const D2GSPacketSrv82* pPacket)
{
    const int nOwnerGUID = *(const int*)pPacket->dwOwnerGUID;
    const int nPortalGUID0 = *(const int*)pPacket->dwPortalGUID0;
    const int nPortalGUID1 = *(const int*)pPacket->dwPortalGUID1;

    D2UnitStrc* pPortal = sub_00463990(nPortalGUID0, UNIT_OBJECT);
    if (pPortal)
    {
        sub_004BDFE0_SetObjectName(pPortal, pPacket->szOwnerName);
    }

    if (nPortalGUID1 != -1)
    {
        pPortal = sub_00463990(nPortalGUID1, UNIT_OBJECT);
        if (pPortal)
        {
            sub_004BDFE0_SetObjectName(pPortal, pPacket->szOwnerName);
        }
        sub_0047A270(nOwnerGUID, nPortalGUID0, nPortalGUID1);
    }
}

// 0x0045EE20
void __fastcall sub_0045EE20_PacketA8(D2GSPacketSrvA8* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(*(const int*)pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    const int nState = pPacket->nState;
    sub_004D9B20_BeginState(pUnit, nState);

    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pStream, pPacket->nSize - 8);
    int nPrev = 0;
    int nStatId = sub_00411020_ReadBits(&tBuffer, 9);
    while (nStatId < STAT_ID_END)
    {
        if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            return;
        D2ItemStatCostTxt* pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        if (!pItemStatCostTxtRecord)
            return;
        if (pItemStatCostTxtRecord->nSendBits <= 0)
            return;

        int nLayer = 0;
        if (pItemStatCostTxtRecord->nSendParamBits > 0)
            nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendParamBits);

        int nValue;
        if (pItemStatCostTxtRecord->nSendBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SIGNED & 7])
            nValue = BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendBits);
        else
            nValue = sub_00411020_ReadBits(&tBuffer, pItemStatCostTxtRecord->nSendBits);

        nPrev = sub_004D9D70_SetStateStat(pUnit, nPrev, nState, nStatId, nValue, nLayer);
        nStatId = sub_00411020_ReadBits(&tBuffer, 9);
    }

    sub_004D9E60_EndState(pUnit, nState);
}

// 0x0045EFA0
void __fastcall sub_0045EFA0_PacketAA(D2GSPacketSrvAA* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(*(const int*)pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pStream, pPacket->nSize - 7);
    int nState = sub_00411020_ReadBits(&tBuffer, 8);
    while (nState < STATE_ID_END)
    {
        sub_004D9B20_BeginState(pUnit, nState);
        if (sub_00411020_ReadBits(&tBuffer, 1))
        {
            int nPrev = 0;
            int nStatId = sub_00411020_ReadBits(&tBuffer, 9);
            while (nStatId < STAT_ID_END)
            {
                if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
                    return;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
                if (!pItemStatCostTxtRecord)
                    return;
                if (pItemStatCostTxtRecord->nSendBits <= 0)
                    return;

                int nLayer = 0;
                if (pItemStatCostTxtRecord->nSendParamBits > 0)
                    nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendParamBits);

                int nValue;
                if (pItemStatCostTxtRecord->nSendBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SIGNED & 7])
                    nValue = BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendBits);
                else
                    nValue = sub_00411020_ReadBits(&tBuffer, pItemStatCostTxtRecord->nSendBits);

                nPrev = sub_004D9D70_SetStateStat(pUnit, nPrev, nState, nStatId, nValue, nLayer);
                nStatId = sub_00411020_ReadBits(&tBuffer, 9);
            }
        }
        sub_004D9E60_EndState(pUnit, nState);
        nState = sub_00411020_ReadBits(&tBuffer, 8);
    }
}

// 0x004689D0
void __cdecl sub_004689D0_ShowHelpOnce()
{
    if (sub_0044DA30())
        return;
    if (sub_00463DF0())
        return;

    sub_00455F20(0x21, 2, 0);
    unsigned long dwValue;
    if (!SRegLoadValue("Diablo II", "Help Menu", 1, &dwValue) || !dwValue)
    {
        dwValue = 1;
        SRegSaveValue("Diablo II", "Help Menu", 1, dwValue);
    }
}

// 0x0046B4A0
void __cdecl sub_0046B4A0_RequestNearMonster()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    D2UnitStrc* pMonster = UNITFINDS_FindUnitInNeighboredRooms(pRoom, UNIT_MONSTER, 0x20E);
    if (!pMonster)
        return;

    const int nX = UNITS_GetXPosition(pMonster);
    const int nY = CLIENTS_GetUnitY(pMonster);
    sub_004CDB40_SubmitRequest(pPlayer, 0x25E, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pPlayer, 0x25B, nX, nY, 0, 1);
    pMonster->dwFlagEx |= 0x40000;
}

// 0x00476E30
void __cdecl sub_00476E30_LoadGreenBlood()
{
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpGlobal_007BB384 = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile);
    }
}

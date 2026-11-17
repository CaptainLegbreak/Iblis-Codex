extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma pack(push, 1)
struct D2Packet18RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned char nValue07;
    unsigned char nValue08;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2Packet95RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2Packet96RecordStrc
{
    unsigned char nHeader;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};
#pragma pack(pop)

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
};

struct D2PacketBufferStrc
{
    int nMax;
    int nCount;
    int unk0x08;
    unsigned char* pData;
};

typedef void (__fastcall* D2PacketHandlerFn)(unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    D2PacketHandlerFn pfnHandler;
    int nSize;
    void* f_8;
};

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC);
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode);
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit);
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(D2UnitStrc* pUnit);
void __fastcall sub_004647A0_SetPacketBuffer(D2UnitStrc* pUnit, D2PacketBufferStrc* pBuffer);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall sub_0052B920(unsigned char* pPacket, unsigned int nLength, int* pSize);
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);

extern "C" const char szSCmdCppFile_006D69E4[];
extern int gnGlobal_007A5230;
extern D2PacketTableEntryStrc gtPacketTable_007114D0[];
extern int gnPacketBytes_007A6AF4;
extern int gnPacketBlocks_007A6AFC;
extern int gnLargePacketBlocks_007A6B04;
extern unsigned char gnLastPacketId_007A5234;

static void sub_0045D900_ReadPacket18(unsigned char* pData, D2Packet18RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xF);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nValue07 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nValue08 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045D9B0
void __fastcall sub_0045D9B0_HandlePacket18(unsigned char* pPacket)
{
    D2Packet18RecordStrc tRecord;
    sub_0045D900_ReadPacket18(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, 6, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, 8, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 0x4A, tRecord.nValue07, 0);
    STATLIST_SetUnitStat(pPlayer, 0x1A, tRecord.nValue08, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        sub_00480E70_SetUnitMode(pPlayer, 5);
        sub_004647D0_UpdateAttackableFlag(pPlayer);
    }
}

static void sub_0045DA90_ReadPacket95(unsigned char* pData, D2Packet95RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xD);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045DB20
void __fastcall sub_0045DB20_HandlePacket95(unsigned char* pPacket)
{
    D2Packet95RecordStrc tRecord;
    sub_0045DA90_ReadPacket95(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, 6, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, 8, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        sub_00480E70_SetUnitMode(pPlayer, 5);
        sub_004647D0_UpdateAttackableFlag(pPlayer);
    }
}

static void sub_0045DBE0_ReadPacket96(unsigned char* pData, D2Packet96RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 9);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

void __fastcall sub_0045DC50_HandlePacket96(unsigned char* pPacket)
{
    D2Packet96RecordStrc tRecord;
    sub_0045DBE0_ReadPacket96(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
}

static D2PacketBufferStrc* sub_0045F610_GrowPacketBuffer(D2UnitStrc* pUnit)
{
    if (!gnGlobal_007A5230)
    {
        for (int i = 0; i < 0xAF; ++i)
        {
            if (gtPacketTable_007114D0[i].f_8 && gtPacketTable_007114D0[i].nSize > gnGlobal_007A5230)
            {
                gnGlobal_007A5230 = gtPacketTable_007114D0[i].nSize;
            }
        }
        gnGlobal_007A5230 += 5;
    }
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer)
    {
        pBuffer = (D2PacketBufferStrc*)FOG_Alloc(0x10, szSCmdCppFile_006D69E4, 0x1266, 0);
        memset(pBuffer, 0, 0x10);
        sub_004647A0_SetPacketBuffer(pUnit, pBuffer);
    }
    int nNewMax = pBuffer->nMax + 5;
    unsigned char* pData = (unsigned char*)FOG_Alloc(gnGlobal_007A5230 * nNewMax, szSCmdCppFile_006D69E4, 0x126B, 0);
    memset(pData, 0, gnGlobal_007A5230 * nNewMax);
    if (pBuffer->pData)
    {
        memcpy(pData, pBuffer->pData, pBuffer->nMax * gnGlobal_007A5230);
        FOG_Free(pBuffer->pData, szSCmdCppFile_006D69E4, 0x126F, 0);
    }
    pBuffer->nMax = nNewMax;
    pBuffer->pData = pData;
    return pBuffer;
}

static void __stdcall sub_0045F730_QueuePacket(unsigned char* pPacket, int nLength, D2UnitStrc* pUnit)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer || pBuffer->nCount + 1 == pBuffer->nMax)
    {
        pBuffer = sub_0045F610_GrowPacketBuffer(pUnit);
    }
    D2_ASSERT(nLength <= gnGlobal_007A5230, 0x127F);
    memcpy(pBuffer->pData + pBuffer->nCount * gnGlobal_007A5230, pPacket, nLength);
    ++pBuffer->nCount;
}

void __fastcall sub_0045F7B0_ProcessPackets(unsigned char* pData, int nSize)
{
    if (nSize == -1)
    {
        return;
    }
    int nRemaining = nSize;
    unsigned char* pPacket = pData;
    GetTickCount();
    if (nSize > 500)
    {
        ++gnLargePacketBlocks_007A6B04;
    }
    while (nRemaining > 0)
    {
        unsigned char nId = *pPacket;
        int nPacketSize;
        if (!sub_0052B920(pPacket, nSize, &nPacketSize))
        {
            return;
        }
        unsigned short nLength = (unsigned short)nPacketSize;
        D2_ASSERT(nId < 0xAF, 0x1449);
        D2PacketTableEntryStrc* pEntry = &gtPacketTable_007114D0[nId];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT(nLength == pEntry->nSize, 0x1450);
        }
        if (pEntry->nSize == -1 || nLength == pEntry->nSize)
        {
            if (pEntry->f_8)
            {
                int nUnitId;
                int nUnitType;
                switch (nId)
                {
                case 0x67: case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D:
                    nUnitId = *(int*)(pPacket + 1);
                    nUnitType = 1;
                    break;
                default:
                    nUnitId = *(int*)(pPacket + 2);
                    nUnitType = pPacket[1];
                    break;
                }
                D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
                if (pUnit)
                {
                    sub_0045F730_QueuePacket(pPacket, nLength, pUnit);
                }
            }
            switch (nId)
            {
            case 0x0D:
                if (pPacket[1] == 1)
                {
                    sub_00463990(*(int*)(pPacket + 2), 1);
                }
                break;
            case 0x18:
            {
                D2Packet18RecordStrc tRecord;
                sub_0045D900_ReadPacket18(pPacket, &tRecord);
                break;
            }
            case 0x95:
            {
                D2Packet95RecordStrc tRecord;
                sub_0045DA90_ReadPacket95(pPacket, &tRecord);
                break;
            }
            case 0x96:
            {
                D2Packet96RecordStrc tRecord;
                sub_0045DBE0_ReadPacket96(pPacket, &tRecord);
                break;
            }
            }
            if (pEntry->pfnHandler)
            {
                pEntry->pfnHandler(pPacket);
            }
        }
        gnPacketBytes_007A6AF4 += nLength;
        nRemaining -= nLength;
        pPacket += nLength;
        gnLastPacketId_007A5234 = nId;
    }
    ++gnPacketBlocks_007A6AFC;
}

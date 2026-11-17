struct D2GameStrc;
struct D2ClientStrc;
struct D2DynamicPathStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; char unk10[0x1C]; D2DynamicPathStrc* pDynamicPath; };
struct D2MissilesTxt { int unk00; unsigned int dwMissileFlags; char unk08[0x19C]; };
struct D2DataTablesStrc { char unk00[0xB64]; D2MissilesTxt* pMissilesTxt; void* pLinker; int nMissilesTxtRecordCount; };
#pragma pack(push, 1)
struct D2GSPacketSrv73 { unsigned char nHeader; int unk01; unsigned short nMissileId; int nX; int nY; int nFirstX; int nFirstY; unsigned short nCurrentFrame; unsigned char nUnitType; int nUnitGUID; unsigned char nLevel; unsigned char nPierce; };
#pragma pack(pop)
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gnMissileFlag_006CE27C; // 0x006CE27C
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __stdcall sub_0064A3E0_GetMissileId(D2UnitStrc*); // 0x0064A3E0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __fastcall sub_6FC3F610(D2ClientStrc*, D2GSPacketSrv73*); // 0x0053DA10
__forceinline D2MissilesTxt* GetMissilesTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}
// 0x0059FEE0
void __fastcall sub_0059FEE0_SendMissilePacket(D2ClientStrc* pClient, D2GameStrc* pGame, D2UnitStrc* pMissile, int bSendPath)
{
    if (!pMissile || pMissile->dwUnitType != 3)
        return;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return;
    D2MissilesTxt* pMissilesTxt = GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxt || !(pMissilesTxt->dwMissileFlags & gnMissileFlag_006CE27C))
        return;
    D2GSPacketSrv73 packet = {};
    packet.nHeader = 0x73;
    packet.nMissileId = sub_0064A3E0_GetMissileId(pMissile);
    packet.nX = CLIENTS_GetUnitX(pMissile);
    packet.nY = CLIENTS_GetUnitY(pMissile);
    if (bSendPath)
    {
        packet.nFirstX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
        packet.nFirstY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);
    }
    packet.nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : 6;
    packet.nUnitType = nOwnerType;
    packet.nUnitGUID = pOwner->dwUnitId;
    packet.nLevel = MISSILE_GetLevel(pMissile);
    packet.nPierce = STATLIST_UnitGetStatValue(pMissile, 0x148, 0);
    sub_6FC3F610(pClient, &packet);
}

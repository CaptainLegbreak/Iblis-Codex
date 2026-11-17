struct D2ClientStrc;

struct D2ShrinesTxt
{
    unsigned char nCode;
};

struct D2ObjectsTxt
{
    char unk0x00[0x167];
    unsigned char nSubClass;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
    unsigned char nPortalFlags;
    unsigned short unk0x06;
    D2ShrinesTxt* pShrineTxt;
    int dwOperateGUID;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0xC4 - 0x18];
    unsigned int dwFlags;
};

#define UNIT_OBJECT 2

void __fastcall D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char a6, int nAnimMode); // 0x0053B470
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall sub_6FC3F550(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053D900
D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit);                              // 0x00621B70
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

// 0x00581A20
void __fastcall OBJMODE_SendObjectModeAndShrineUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(pClient, 0x0E, UNIT_OBJECT, !pUnit ? -1 : pUnit->dwUnitId, 3, !pUnit ? 0 : (pUnit->dwFlags >> 1) & 1, (unsigned short)pUnit->dwAnimMode);

    const unsigned char nSubClass = DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nSubClass;
    if (nSubClass)
    {
        if (nSubClass & 4)
        {
            sub_6FC3F550(pClient, pUnit);
        }
        else if (pUnit->dwAnimMode == 1 && nSubClass & 1)
        {
            const D2ShrinesTxt* const pShrineTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
            unsigned char nCode = 0;
            if (pShrineTxt)
            {
                nCode = pShrineTxt->nCode;
            }

            const int nOperateGUID = pUnit->pObjectData->dwOperateGUID;
            if (nOperateGUID)
            {
                sub_6FC3F060(pClient, 2, !pUnit ? -1 : pUnit->dwUnitId, 0, 0, nOperateGUID - 1, 0, nCode, 0);
            }
        }
    }
}

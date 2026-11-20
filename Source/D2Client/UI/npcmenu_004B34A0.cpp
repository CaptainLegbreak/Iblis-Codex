#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2ClientMenus.h"
#include "D2UnitData.h"

struct D2NpcMonListPacketStrc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short nMonIds[12];
};

#pragma pack(push, 2)
#pragma pack(pop)

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_004B3790_RemoveInventoryClientUnits(D2UnitStrc* pUnit); // 0x004B3790
void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __cdecl sub_004A1730_ClearPanel();                                                                     // 0x004A1730
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __cdecl sub_004B4830_Rebuild();                                                                        // 0x004B4830
int __cdecl sub_004B5C60_Handler();                                                                         // 0x004B5C60

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2ClientDialogStrc* gpDialog_007C0D63;                                                               // 0x007C0D63
extern D2ClientDialogStrc* gpDialog_007C0D67;                                                               // 0x007C0D67
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850
extern "C" int gnNpcSoundActive_007C0DB4;                                                                   // 0x007C0DB4
extern "C" int gnNpcSoundHandle_007C0DB8;                                                                   // 0x007C0DB8
extern int (__cdecl* gpfnGlobal_00726E0B)();                                                                // 0x00726E0B
extern short gwGlobal_00726DFF;                                                                             // 0x00726DFF

// 0x004B34A0
int __cdecl sub_004B34A0()
{
    if (gpDialog_007C0D5F || gpDialog_007C0D63 || gpDialog_007C0D67 || gpDialog_007C0D6B || gpDialog_007C0D6F
        || gpDialog_007C0D73 || gpDialog_007C0D77 || gpDialog_007C0D7B)
    {
        return 1;
    }

    return 0;
}

// 0x004B3510
void __fastcall sub_004B3510(D2NpcMonListPacketStrc* pPacket)
{
    for (int i = 0; i < 12; ++i)
    {
        if (pPacket->nMonIds[i] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            for (int j = 0; j < gnNpcEntryCount_0072554C; ++j)
            {
                if (gaNpcEntries_00726850[j].nId == pPacket->nMonIds[i])
                {
                    gaNpcEntries_00726850[j].bFlag = 1;
                }
            }
        }
    }
}

// 0x004B3C20
void __fastcall sub_004B3C20(int nValue)
{
    if (sub_00463DD0_GetPlayerUnit())
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
    }

    D2UnitStrc* pNpc = sub_00463990(nValue, 1);
    if (pNpc)
    {
        sub_004B3790_RemoveInventoryClientUnits(pNpc);
    }

    if (gnNpcSoundActive_007C0DB4)
    {
        sub_004BA840(gnNpcSoundHandle_007C0DB8);
    }

    gnNpcSoundActive_007C0DB4 = 0;
    gnNpcSoundHandle_007C0DB8 = 0;

    D2UnitStrc* pUnit = sub_00463990(nValue, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }

    sub_004786A0_SendDwords2(0x30, 1, nValue);
    sub_004A1730_ClearPanel();
    gnGlobal_007C0D29 = 0;
    sub_00455F20(8, 1, 0);

    if (pUnit)
    {
        if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nClientFlags &= ~1;
        }

        sub_00480E70_SetUnitMode(pUnit, 1);
    }
}

// 0x004B5C20
int __cdecl sub_004B5C20_ClosePanel77()
{
    if (gpDialog_007C0D77)
    {
        sub_004B8020(gpDialog_007C0D77);
        delete gpTradeObj_007C0D83;
        gpTradeObj_007C0D83 = 0;
        gpDialog_007C0D77 = 0;
    }

    sub_004B4830_Rebuild();
    return 1;
}

// 0x004B6410
int __cdecl sub_004B6410_InitHandler()
{
    gnGlobal_00726DF9 = 3;
    gpfnGlobal_00726E0B = sub_004B5C60_Handler;
    gwGlobal_00726DFF = 0xD45;
    return 1;
}

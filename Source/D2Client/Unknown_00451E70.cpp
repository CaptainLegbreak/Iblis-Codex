#include "D2Client.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MsgHandlerEntryStrc;
struct Pad40_00451F30;
struct Obj00451F30;
struct Obj00451F70;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct Unicode;
struct D2StatesTxt;
struct D2MonLvlTxt;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2PetTypeTxt;
struct D2ItemTypesTxt;

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    SMSGHANDLER pfnHandler;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2MsgHandlerEntryStrc gMsgHandlers_0070F7E4[4]; // 0x0070F7E4
void __fastcall sub_00451D10_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451D10
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

struct Pad40_00451F30 {
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

struct Obj00451F30 {
    Pad40_00451F30 tPad000;
    Pad40_00451F30 tPad040;
    Pad40_00451F30 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwFlagsC4;
};

struct Obj00451F70 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwValue10;
};



struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    unsigned char unk_C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
    unsigned char unk_A9C[0xD4];
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
    char unk0xB78[0x20];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x1C];
    int nOverlayTxtRecordCount;
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
    unsigned char unk_BCC[0x8];
    int nItemStatCostTxtRecordCount;
    unsigned char unk_BD8[0x10];
    D2PetTypeTxt* pPetTypeTxt;
    char unk0xBEC[0x04];
    int nPetTypeTxtRecordCount;
    char unk0xBF4[0x04];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct Unicode
{
    unsigned short wChar;
};

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

struct D2StatesTxt
{
    char unk0x00[0x3C];
};

struct D2MonLvlTxt
{
    char unk0x00[0x78];
};



struct D2PetTypeTxt
{
    char unk0x00[0xE0];
};

struct D2ItemTypesTxt
{
    char szCode[4];
    short nEquiv1;
    short nEquiv2;
    unsigned char nRepair;
    unsigned char nBody;
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    short wShoots;
    short wQuiver;
    unsigned char nThrowable;
    unsigned char nReload;
    unsigned char nReEquip;
    unsigned char nAutoStack;
    char unk0x14[0xD0];
};

typedef char check_states_size[(sizeof(D2StatesTxt) == 0x3C) ? 1 : -1];

typedef char check_monlvl_size[(sizeof(D2MonLvlTxt) == 0x78) ? 1 : -1];

typedef char check_skills_size[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];

typedef char check_charstats_size[(sizeof(D2CharStatsTxt) == 0xC4) ? 1 : -1];

typedef char check_pettype_size[(sizeof(D2PetTypeTxt) == 0xE0) ? 1 : -1];

typedef char check_itemtypes_size[(sizeof(D2ItemTypesTxt) == 0xE4) ? 1 : -1];

typedef char check_datatables_size[(sizeof(D2DataTablesStrc) == 0xC00) ? 1 : -1];

// 0x00451E70
int __fastcall sub_00451E70_RegisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x178);
    sub_00451DB0_RegisterMsgHandlers((int)hWnd, gMsgHandlers_0070F7E4, 4);
    SMsgPushRegisterState((int)hWnd);
    return 1;
}

// 0x00451EB0
void __fastcall sub_00451EB0_UnregisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < 4; ++i)
    {
        sub_00451D10_UnregisterMsgHandler(hWnd, gMsgHandlers_0070F7E4[i].nType, gMsgHandlers_0070F7E4[i].nId, gMsgHandlers_0070F7E4[i].pfnHandler);
    }
    sub_00420320_RegisterHandlers(hWnd);
}

#include "gen/data/Source/D2Client/Unknown_00451E70.inc"

// 0x00451F30
extern "C" __declspec(dllexport) int __fastcall sub_00451F30(Obj00451F30* pObj, unsigned int dwMask) {
    if (!pObj) {
        return 0;
    }
    return (pObj->dwFlagsC4 & dwMask) != 0;
}

// 0x00451F70
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00451F70(Obj00451F70* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue10;
}

// 0x00451FB0
D2MonStats2Txt* __fastcall sub_00451FB0(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nId];
    }
    return 0;
}

// 0x00451FE0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

Unicode gwszText_007A2A78[256]; // 0x007A2A78

int gnHoverTextState_007A2C78; // 0x007A2C78

// 0x00452020
int __fastcall sub_00452020_GetOverlayTxtRecordCount()
{
    return sgptDataTables->nOverlayTxtRecordCount;
}

// 0x00452030
int __fastcall sub_00452030_GetItemStatCostTxtRecordCount()
{
    return sgptDataTables->nItemStatCostTxtRecordCount;
}

// 0x00452070
int* __fastcall sub_00452070_ClearBlock(int* pData)
{
    for (int i = 0; i < 0x80; ++i)
    {
        pData[i] = 0;
    }

    return pData;
}

// 0x00452160
void __cdecl sub_00452160_Nop()
{
}

// 0x00452550
void __fastcall sub_00452550_SetHoverText(const Unicode* pText, int nState)
{
    if (!pText)
    {
        gwszText_007A2A78[0].wChar = 0;
        return;
    }

    sub_005267E0(gwszText_007A2A78, pText);
    gnHoverTextState_007A2C78 = nState;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x00452040
extern "C" D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x00478A20
extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }

    return 0;
}

// 0x004833E0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x005A0000
extern "C" D2MonLvlTxt* __fastcall sub_005A0000_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005C8BC0
extern "C" int __fastcall sub_005C8BC0_GetSkillsTxtParam7(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6];
}

// 0x00628440
extern "C" int __stdcall sub_00628440_GetShootsFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wShoots;
}

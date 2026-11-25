#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2TxtTables.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
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


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2MsgHandlerEntryStrc gaWindowMsgHandlers[4]; // 0x0070F7E4
void __fastcall SCMD_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451D10
void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

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




extern D2DataTablesStrc* sgptDataTables; // 0x00744304

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];


struct D2MonLvlTxt
{
    char unk0x00[0x78];
};





typedef char check_states_size[(sizeof(D2StatesTxt) == 0x3C) ? 1 : -1];

typedef char check_monlvl_size[(sizeof(D2MonLvlTxt) == 0x78) ? 1 : -1];

typedef char check_skills_size[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];

typedef char check_charstats_size[(sizeof(D2CharStatsTxt) == 0xC4) ? 1 : -1];

typedef char check_pettype_size[(sizeof(D2PetTypeTxt) == 0xE0) ? 1 : -1];

typedef char check_itemtypes_size[(sizeof(D2ItemTypesTxt) == 0xE4) ? 1 : -1];


// 0x00451E70
int __fastcall sub_00451E70_RegisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x178);
    SCMD_RegisterMsgHandlers((int)hWnd, gaWindowMsgHandlers, 4);
    SMsgPushRegisterState((int)hWnd);
    return 1;
}

// 0x00451EB0
void __fastcall sub_00451EB0_UnregisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < 4; ++i)
    {
        SCMD_UnregisterMsgHandler(hWnd, gaWindowMsgHandlers[i].nType, gaWindowMsgHandlers[i].nId, (SMSGHANDLER)gaWindowMsgHandlers[i].pfnHandler);
    }
// build: symbol ?SMsgPopRegisterState@* 0x00420320
    SMsgPopRegisterState(hWnd);
}

#include "gen/data/Source/D2Client/Unknown_00451E70.inc"

extern "C" __declspec(dllexport) int __fastcall sub_00451F30(Obj00451F30* pObj, unsigned int dwMask); // 0x00451F30

extern "C" __declspec(dllexport) unsigned int __fastcall sub_00451F70(Obj00451F70* pObj); // 0x00451F70



extern Unicode gwszHoverText[]; // 0x007A2A78

int gnHoverTextState; // 0x007A2C78





// 0x00452550
void __fastcall sub_00452550_SetHoverText(const Unicode* pText, int nState)
{
    if (!pText)
    {
        gwszHoverText[0].wChar = 0;
        return;
    }

    sub_005267E0(gwszHoverText, pText);
    gnHoverTextState = nState;
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
extern "C" int __stdcall ITEMS_GetAmmoTypeFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wShoots;
}

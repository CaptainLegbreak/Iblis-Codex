struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

struct D2PanelHotkeysStrc
{
    int nIndex26Sec;
    int nIndex16Sec;
    int nIndex26;
    int nIndex16;
    int nIndex29Sec;
    int nIndex29;
    int nIndex2CSec;
    int nIndex2C;
    D2MsgHandlerEntryStrc* f_20;
};

int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount);// 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __fastcall sub_0046AA20(int nArg1, int nArg2);                                                         // 0x0046AA20
void __cdecl sub_0047B090_InitChatIme();                                                                    // 0x0047B090
void __cdecl sub_0047B4D0();                                                                                // 0x0047B4D0
void __cdecl sub_00487B30();                                                                                // 0x00487B30
void __fastcall sub_00467A70(int nArg);                                                                     // 0x00467A70
void __fastcall sub_004A5200(int nArg);                                                                     // 0x004A5200
void __cdecl sub_00454980();                                                                                // 0x00454980
void __cdecl sub_00491940_ResetNpcPanel();                                                                  // 0x00491940
void __cdecl sub_004B8920();                                                                                // 0x004B8920
void __cdecl sub_0048A680();                                                                                // 0x0048A680
void __cdecl sub_00489E50_LoadStashPanelCels();                                                             // 0x00489E50
void __cdecl sub_0048A4B0_LoadCubePanelCel();                                                               // 0x0048A4B0
void sub_004A0050_OpenListBoxDialog();                                                                      // 0x004A0050
void __cdecl sub_0049A640();                                                                                // 0x0049A640

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[];                                                    // 0x006D5F28
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F58[];                                                    // 0x006D5F58
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FAC[];                                                    // 0x006D5FAC
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FC4[];                                                    // 0x006D5FC4
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FD0[];                                                    // 0x006D5FD0
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FE8[];                                                    // 0x006D5FE8
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6000[];                                                    // 0x006D6000
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D600C[];                                                    // 0x006D600C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6030[];                                                    // 0x006D6030
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6084[];                                                    // 0x006D6084
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D615C[];                                                    // 0x006D615C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D61B0[];                                                    // 0x006D61B0
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D61C8[];                                                    // 0x006D61C8
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6204[];                                                    // 0x006D6204
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D621C[];                                                    // 0x006D621C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D62C4[];                                                    // 0x006D62C4
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6300[];                                                    // 0x006D6300
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6318[];                                                    // 0x006D6318
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D633C[];                                                    // 0x006D633C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6360[];                                                    // 0x006D6360
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F878[];                                                    // 0x0070F878
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F8D8[];                                                    // 0x0070F8D8
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F930[];                                                    // 0x0070F930
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F9D0[];                                                    // 0x0070F9D0
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070FA30[];                                                    // 0x0070FA30
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070FA84[];                                                    // 0x0070FA84
extern const D2PanelHotkeysStrc gtPanelHotkeys_006D5F88;                                                    // 0x006D5F88
extern const D2PanelHotkeysStrc gtPanelHotkeys_006D618C;                                                    // 0x006D618C
extern const D2PanelHotkeysStrc gtPanelHotkeys_006D6234;                                                    // 0x006D6234
extern const D2PanelHotkeysStrc gtPanelHotkeys_006D6258;                                                    // 0x006D6258
extern const D2PanelHotkeysStrc gtPanelHotkeys_006D627C;                                                    // 0x006D627C
extern const D2PanelHotkeysStrc gtPanelHotkeys_006D62A0;                                                    // 0x006D62A0
int gnPanelFlag_007A2864;                                                                                   // 0x007A2864
extern int gnPanelState_007A27E8;                                                                           // 0x007A27E8

static __forceinline void SetHotkey(const D2PanelHotkeysStrc* pDesc, int nIndex, int nKeyFunc, int bSecondary, int nDefault)
{
    if (nIndex == -1)
        return;

    if (sub_00469D90(nKeyFunc, bSecondary))
    {
        const unsigned short nKey = sub_00469AA0(nKeyFunc, bSecondary);
        if (nKey != 0xFFFF && nKey <= 0xDF)
        {
            pDesc->f_20[nIndex].nId = nKey;
            return;
        }
    }

    pDesc->f_20[nIndex].nId = nDefault;
}

// 0x00453640
static void sub_00453640_SetPanelHotkeys(const D2PanelHotkeysStrc* pDesc)
{
    SetHotkey(pDesc, pDesc->nIndex16Sec, 0x16, 0x1, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26Sec, 0x26, 0x1, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29Sec, 0x29, 0x1, 0x4E);
    if (sub_00408F20_HasExpansionMpq())
        SetHotkey(pDesc, pDesc->nIndex2CSec, 0x2C, 0x1, 0x57);
    SetHotkey(pDesc, pDesc->nIndex16, 0x16, 0x0, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26, 0x26, 0x0, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29, 0x29, 0x0, 0x4E);
    if (sub_00408F20_HasExpansionMpq())
        SetHotkey(pDesc, pDesc->nIndex2C, 0x2C, 0x0, 0x57);
}

// 0x00455720
void __fastcall sub_00455720_SetPanelHandlers(int nPanel)
{
    switch (nPanel)
    {
    case 0xA:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        gnPanelFlag_007A2864 = 0x1;
        return;
    case 0x0:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5F28, 0x4);
        return;
    case 0x3:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FC4, 0x1);
        return;
    case 0x4:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FAC, 0x2);
        return;
    case 0x2:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FD0, 0x2);
        return;
    case 0x1:
        sub_00487B30();
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5F58, 0x4);
        return;
    case 0x5:
        sub_0047B090_InitChatIme();
        sub_0046AA20(0, 0x1);
        if (gnPanelState_007A27E8)
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        sub_0047B4D0();
        return;
    case 0x6:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FE8, 0x2);
        return;
    case 0x13:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6000, 0x1);
        return;
    case 0x7:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D600C, 0x2);
        return;
    case 0x9:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6030, 0x7);
        sub_00467A70(0);
        return;
    case 0xB:
        sub_004A5200(0x1);
        sub_00454980();
        return;
    case 0xC:
        sub_0046AA20(0x2, 0x1);
        sub_00491940_ResetNpcPanel();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D5F88);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F878, 0x8);
        return;
    case 0xF:
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D618C);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F8D8, 0x7);
        return;
    case 0x11:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D615C, 0x4);
        return;
    case 0x10:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D61B0, 0x2);
        return;
    case 0x14:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D61C8, 0x5);
        return;
    case 0x15:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6204, 0x2);
        return;
    case 0x16:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D621C, 0x2);
        sub_0049A640();
        return;
    case 0x17:
        sub_0046AA20(0, 0x1);
        sub_004B8920();
        sub_0048A680();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D6234);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F930, 0xD);
        return;
    case 0x19:
        sub_0046AA20(0x2, 0x1);
        sub_00489E50_LoadStashPanelCels();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D6258);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F9D0, 0x8);
        return;
    case 0x1A:
        sub_0046AA20(0x2, 0x1);
        sub_0048A4B0_LoadCubePanelCel();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D627C);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070FA30, 0x7);
        return;
    case 0x18:
        sub_004A0050_OpenListBoxDialog();
        return;
    case 0x1F:
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D62A0);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070FA84, 0x2);
        return;
    case 0x21:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D62C4, 0x5);
        return;
    case 0x22:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6300, 0x2);
        return;
    case 0x23:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6318, 0x3);
        return;
    case 0x24:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D633C, 0x3);
        return;
    case 0x25:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6360, 0x2);
        return;
    }
}

#include "gen/data/Source/D2Client/00453640_sub_00453640_SetPanelHotkeys.inc"

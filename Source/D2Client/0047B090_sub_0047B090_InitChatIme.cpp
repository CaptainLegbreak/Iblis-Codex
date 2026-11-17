struct D2MsgHandlerEntryStrc;
struct T0046E1B0;
struct T0047A980;

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
bool __cdecl sub_0047B010_IsImeLanguage();                                                                  // 0x0047B010
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __cdecl sub_00525150();                                                                         // 0x00525150

extern "C" int __stdcall ImmReleaseContext(int hWnd, T0046E1B0* hImc);                                         // 0x006B00B4
extern "C" T0046E1B0* __stdcall ImmGetContext(int hWnd);                                                       // 0x006B00C6
extern "C" int __stdcall ImmIsIME(T0047A980* hKl);                                                              // 0x006B00D8
extern "C" int __stdcall ImmGetConversionStatus(T0046E1B0* hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE
extern "C" int __stdcall ImmSimulateHotKey(int hWnd, unsigned long nHotKey);                                // 0x006B00E4
extern "C" int __stdcall ImmSetConversionStatus(T0046E1B0* hImc, unsigned long nConversion, unsigned long nSentence); // 0x006B00EA
extern "C" int __stdcall ImmSetOpenStatus(T0046E1B0* hImc, int bOpen);                                         // 0x006B00F0
extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID();                        // 0x006CC354
extern "C" __declspec(dllimport) T0047A980* __stdcall GetKeyboardLayout(unsigned long idThread);               // 0x006CC4C0

extern D2MsgHandlerEntryStrc gtChatHandlers_00712F4C[];                                                     // 0x00712F4C
extern D2MsgHandlerEntryStrc gtChatInputHandlers_00712FA8[];                                                // 0x00712FA8
extern int gnLanguageId_007BB5DC;                                                                           // 0x007BB5DC
unsigned char gbChatInputOpen_007BB5E1;                                                                     // 0x007BB5E1
extern unsigned short gwChatText_007BB5F8;                                                                  // 0x007BB5F8
extern unsigned short gwChatText_007BC850;                                                                  // 0x007BC850

static unsigned char gbGlobal_007BB5E0;                                                                     // 0x007BB5E0
static int gnGlobal_007BB5F0;                                                                               // 0x007BB5F0

// 0x0047B090
void __cdecl sub_0047B090_InitChatIme()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatHandlers_00712F4C, 4);
    gnLanguageId_007BB5DC = sub_00525150();
    if (gnLanguageId_007BB5DC != 6 && gnLanguageId_007BB5DC != 9 && gnLanguageId_007BB5DC != 8 && gnLanguageId_007BB5DC != 7 && gnLanguageId_007BB5DC != 12)
        return;

    gbChatInputOpen_007BB5E1 = 0;
    if (!sub_0047B010_IsImeLanguage())
        return;

    const unsigned short nLangId = GetSystemDefaultLangID();
    T0046E1B0* hImc = ImmGetContext(sub_004F59A0());
    if (!hImc)
        return;

    gwChatText_007BC850 = 0;
    gwChatText_007BB5F8 = 0;
    switch (gnLanguageId_007BB5DC)
    {
    case 6:
        if (nLangId != 0x411)
            break;
        gbChatInputOpen_007BB5E1 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        if (ImmSetOpenStatus(hImc, 1))
        {
            gbGlobal_007BB5E0 = 1;
            gnGlobal_007BB5F0 = 3;
        }
        else
        {
            gbGlobal_007BB5E0 = 0;
            gnGlobal_007BB5F0 = 0;
        }
        ImmReleaseContext(sub_004F59A0(), hImc);
        return;

    case 7:
    case 12:
    {
        if (nLangId != 0x412 && nLangId != 0x812)
            break;
        ImmSetOpenStatus(hImc, 1);
        unsigned long nConversion, nSentence;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        ImmSetConversionStatus(hImc, 1, nSentence);
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (nConversion & 1)
        {
            gnGlobal_007BB5F0 = 1;
            gbGlobal_007BB5E0 = 1;
        }
        else
        {
            gnGlobal_007BB5F0 = 0;
        }
        gbChatInputOpen_007BB5E1 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;
    }

    case 9:
        gbGlobal_007BB5E0 = 0;
        gbChatInputOpen_007BB5E1 = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(sub_004F59A0(), 0x70);
        ImmSetOpenStatus(hImc, 1);
        gnGlobal_007BB5F0 = 4;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;

    case 8:
        gbGlobal_007BB5E0 = 0;
        gbChatInputOpen_007BB5E1 = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(sub_004F59A0(), 0x10);
        ImmSetOpenStatus(hImc, 1);
        gnGlobal_007BB5F0 = 5;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;
    }
    ImmReleaseContext(sub_004F59A0(), hImc);
}

#include "gen/data/Source/D2Client/0047B090_sub_0047B090_InitChatIme.inc"

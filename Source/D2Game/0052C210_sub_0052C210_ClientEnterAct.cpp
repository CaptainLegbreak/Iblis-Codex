extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;

struct D2ClientStrc
{
    char unk0x00[0x1AC];
    unsigned char nAct;
};

void __fastcall sub_0053AFB0_EnsureAct(D2GameStrc* pGame, unsigned char nAct);                              // 0x0053AFB0
void __fastcall sub_0053ABE0_EnterAct(D2GameStrc* pGame, D2ClientStrc* pClient);                            // 0x0053ABE0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                            // 0x005386D0

// 0x0052C210
void __fastcall sub_0052C210_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x1C4);
    sub_0053AFB0_EnsureAct(pGame, pClient->nAct);
    sub_0053ABE0_EnterAct(pGame, pClient);
    CLIENTS_SetClientState(pClient, 2);
}

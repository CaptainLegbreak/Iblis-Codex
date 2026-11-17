extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define CLIENTFLAGEX_ARENA_RELATED 0x04

struct D2GameStrc;

struct D2ClientStrc
{
    char unk0x000[0x0C];
    unsigned char nByte0C;
    char unk0x00D[0x19B];
    D2GameStrc* pGame;
    unsigned char nAct;
    unsigned char nByte1AD;
    char unk0x1AE[0x226];
    unsigned int dwFlags;
    char unk0x3D8[0xAC];
    int nIronGolemItemGUID;
};

void __fastcall ARENA_SendScoresToClient(D2GameStrc* pGame, D2ClientStrc* pClient);                        // 0x0053FC70

// 0x005383B0
unsigned char __fastcall sub_005383B0(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x816);
    return pClient->nByte1AD;
}

// 0x005383E0
void __fastcall sub_005383E0(D2ClientStrc* pClient, unsigned char nValue)
{
    D2_ASSERT(pClient, 0x822);
    pClient->nByte1AD = nValue;
}

// 0x005385E0
void __cdecl sub_005385E0()
{
}

// 0x00538730
int __fastcall sub_00538730(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x989);
    return pClient->nIronGolemItemGUID;
}

// 0x00538860
void __fastcall sub_00538860(D2ClientStrc* pClient, int bSet)
{
    D2_ASSERT(pClient, 0x9F7);
    if (bSet)
    {
        if (!(pClient->dwFlags & CLIENTFLAGEX_ARENA_RELATED))
            ARENA_SendScoresToClient(pClient->pGame, pClient);
        pClient->dwFlags |= CLIENTFLAGEX_ARENA_RELATED;
    }
    else
    {
        pClient->dwFlags &= ~CLIENTFLAGEX_ARENA_RELATED;
    }
}

// 0x00538900
unsigned char __fastcall sub_00538900(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0xA11);
    return pClient->nByte0C;
}

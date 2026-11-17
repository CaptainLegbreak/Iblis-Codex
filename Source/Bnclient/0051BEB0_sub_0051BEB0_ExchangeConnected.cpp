extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern long volatile gnConnected_00881BF0; // 0x00881BF0

static __declspec(noinline) long sub_0051BEB0_ExchangeConnected(long nComparand, long nExchange);
// 0x0051BEB0
static long sub_0051BEB0_ExchangeConnected(long nComparand, long nExchange)
{
    return InterlockedCompareExchange(&gnConnected_00881BF0, nExchange, nComparand);
}

long __fastcall ExchangeConnectedContext(long nExchange, long nComparand)
{
    return sub_0051BEB0_ExchangeConnected(nComparand, nExchange);
}

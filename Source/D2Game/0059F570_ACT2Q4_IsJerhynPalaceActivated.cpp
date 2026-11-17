struct D2GameStrc;

unsigned char __fastcall sub_0059F510_ACT2Q4_IsJerhynPalaceBlocked(D2GameStrc* pGame);                      // 0x0059F510

// 0x0059F570
int __fastcall ACT2Q4_IsJerhynPalaceActivated(D2GameStrc* pGame)
{
    return sub_0059F510_ACT2Q4_IsJerhynPalaceBlocked(pGame) == 1 ? 1 : 0;
}

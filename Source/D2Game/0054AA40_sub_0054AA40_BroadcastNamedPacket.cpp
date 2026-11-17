struct D2GameStrc;
struct D2ClientStrc;
struct D2NetPacketRecStrc { int unk_00; int unk_04; char szName[16]; };
void __fastcall j_D2GAME_SendPacket0x5A_6FC3DEC0(D2ClientStrc*, D2NetPacketRecStrc*); // 0x0054AA30
void __fastcall GAME_ForEachIngameClient(D2GameStrc*, void (__fastcall*)(D2ClientStrc*, D2NetPacketRecStrc*), D2NetPacketRecStrc*); // 0x0052DED0

// 0x0054AA40
void __fastcall sub_0054AA40_BroadcastNamedPacket(D2GameStrc* pGame, D2NetPacketRecStrc* pPacket)
{
    const char* szName = pPacket->szName;
    int i;
    for (i = 0; i < 16; ++i)
    {
        if (!szName[i])
        {
            break;
        }
    }
    if (i < 16)
        GAME_ForEachIngameClient(pGame, j_D2GAME_SendPacket0x5A_6FC3DEC0, pPacket);
}

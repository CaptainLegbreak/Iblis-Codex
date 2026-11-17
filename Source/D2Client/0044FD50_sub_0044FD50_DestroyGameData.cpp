struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

// 0x0044FD50
void __fastcall sub_0044FD50_DestroyGameData(D2SGameDataStrc* pData)
{
    pData->~D2SGameDataStrc();
}

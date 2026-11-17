struct D2BigPairStrc
{
    ~D2BigPairStrc();
};
// build: symbol ??1D2BigPairStrc@@QAE@XZ 0x00528530

extern D2BigPairStrc data_0088273C; // 0x0088273C

// 0x006CB480
void __cdecl sub_006CB480_DestroyBigPair()
{
    data_0088273C.~D2BigPairStrc();
}

struct D2LogMsgListStrc
{
    ~D2LogMsgListStrc();
};
// build: symbol ??1D2LogMsgListStrc@@QAE@XZ 0x0040FD90

extern D2LogMsgListStrc data_0075E868; // 0x0075E868

// 0x006CB090
void __cdecl sub_006CB090_DestroyLogMsgList()
{
    data_0075E868.~D2LogMsgListStrc();
}

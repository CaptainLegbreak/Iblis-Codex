struct D2TimedRecordStrc
{
    __int64 qwValue;
    char unk0x08[0x10];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
D2TimedRecordStrc gaRecords_0075E8A8[4095];                                                                 // 0x0075E8A8
unsigned int gnRecordCount_007768A4;                                                                        // 0x007768A4
int gnTickAtReset_007768A0;                                                                                 // 0x007768A0

// 0x00411280
void __cdecl sub_00411280_ResetRecords()
{
    for (unsigned int i = 0; i < gnRecordCount_007768A4; ++i)
    {
        gaRecords_0075E8A8[i].qwValue = 0;
    }
    gnTickAtReset_007768A0 = GetTickCount();
}

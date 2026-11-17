extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260
extern unsigned int gdwStartTick_008846E8; // 0x008846E8

// 0x006CAF60
void __cdecl sub_006CAF60_InitStartTick()
{
    gdwStartTick_008846E8 = GetTickCount();
}

extern "C" { int gdwGlobal_008817A0; } // 0x008817A0
extern "C" int gdwGlobal_00881794; // 0x00881794
extern "C" int __cdecl sub_00513B50(); // 0x00513B50
extern "C" int __stdcall sub_00415EE0(int nValue); // 0x00415EE0
extern "C" int __fastcall sub_00515530(int nType, int nArg); // 0x00515530

// 0x00514780
extern "C" void __fastcall sub_00514780_CreateSoundChannel(int nArg)
{
    gdwGlobal_008817A0 = nArg;
    sub_00415EE0(sub_00513B50());
    gdwGlobal_00881794 = sub_00515530(1, gdwGlobal_008817A0);
}

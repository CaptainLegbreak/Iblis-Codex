unsigned int __stdcall SStrHash(const char* text, unsigned int flags, unsigned int hashSeed); // 0x00413CE0
unsigned int gdwGameTimeHash_0077AD60;        // 0x0077AD60

// 0x006CA980
void __cdecl sub_006CA980_InitializeGameTimeHash()
{
    gdwGameTimeHash_0077AD60 = SStrHash("Game Time", 0, 0);
}

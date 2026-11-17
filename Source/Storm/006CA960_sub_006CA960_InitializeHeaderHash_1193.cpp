unsigned int __stdcall SStrHash(const char* text, unsigned int flags, unsigned int hashSeed); // 0x00413CE0
extern unsigned int gdwHeaderHash_0077AD64; // 0x0077AD64

// 0x006CA960
void __cdecl sub_006CA960_InitializeHeaderHash()
{
    gdwHeaderHash_0077AD64 = SStrHash("Header", 0, 0);
}

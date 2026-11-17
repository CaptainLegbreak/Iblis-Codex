extern "C" void __cdecl srand(unsigned int nSeed);                                                          // 0x00687454
extern "C" int __cdecl rand();                                                                              // 0x00687461
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6

// 0x00522BC0
void __fastcall sub_00522BC0_FillRandomBytes(char* szBuffer, int nSize)
{
    srand(0x150B);
    for (int i = 0; i < nSize - 1; )
    {
        const char c = (char)rand();
        if (c)
        {
            szBuffer[i] = c;
            i += 1;
        }
    }
    srand(_time32(0));
    szBuffer[nSize - 1] = 0;
}

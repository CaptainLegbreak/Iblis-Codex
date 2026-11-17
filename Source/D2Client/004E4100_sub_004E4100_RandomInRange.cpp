typedef unsigned int U32;
typedef char check_scalar_width[(sizeof(U32) == 4 && sizeof(int) == 4) ? 1 : -1];
extern "C" int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

// 0x004E4100
extern "C" int __fastcall sub_004E4100_RandomInRange(int nMin, int nMax)
{
    U32 width = (U32)nMax - (U32)nMin + 1u;
    return sub_004E40A0((int)width) + nMin;
}

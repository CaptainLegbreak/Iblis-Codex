// Altered from the original zlib source.
extern "C" void __cdecl free(void* pMemory);                                                                // 0x00683FC0

// 0x0042DC90
void __fastcall zcfree(void* opaque, void* ptr)
{
    free(ptr);
}

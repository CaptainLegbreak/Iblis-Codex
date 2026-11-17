int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern void* gpNewsCacheItems_00881C38; // 0x00881C38
extern const char gszTypeNewsTableItem_0072FF8C[]; // 0x0072FF8C

// 0x006CB450
void __cdecl sub_006CB450_StaticFiniNewsCache()
{
    if (gpNewsCacheItems_00881C38)
    {
        SMemFree(gpNewsCacheItems_00881C38, gszTypeNewsTableItem_0072FF8C, -2, 0);
    }
}

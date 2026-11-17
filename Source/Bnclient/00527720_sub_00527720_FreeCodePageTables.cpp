struct D2LangByteRangeStrc;
struct D2LangCharMapEntryStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650
extern D2LangCharMapEntryStrc* gpCharMap_00882B24;                                                          // 0x00882B24
D2LangByteRangeStrc* gpLeadByteRanges_00882B28;                                                             // 0x00882B28
unsigned short* gpCharMapIndex_00882B2C;                                                                    // 0x00882B2C

// 0x00527720
void __cdecl sub_00527720_FreeCodePageTables()
{
    if (gpLeadByteRanges_00882B28)
    {
        SMemFree(gpLeadByteRanges_00882B28, "delete[]", -1, 0);
        gpLeadByteRanges_00882B28 = 0;
    }
    if (gpCharMap_00882B24)
    {
        SMemFree(gpCharMap_00882B24, "delete[]", -1, 0);
        gpCharMap_00882B24 = 0;
    }
    if (gpCharMapIndex_00882B2C)
    {
        SMemFree(gpCharMapIndex_00882B2C, "delete[]", -1, 0);
        gpCharMapIndex_00882B2C = 0;
    }
}

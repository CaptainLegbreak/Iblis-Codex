int __stdcall sub_006C4D70_FindValue(int nKey); // 0x006C4D70

// 0x006C4F90
int __stdcall sub_006C4F90_GetBool(int nKey)
{
    return sub_006C4D70_FindValue(nKey) != 0;
}

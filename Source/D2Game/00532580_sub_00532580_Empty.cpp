// 0x00532580
void __cdecl sub_00532580_Empty()
{
}

// 0x00532D90
static int sub_00532D90_ClearValue(int* pValue)
{
    *pValue = 0;
    return 0;
}

int __fastcall sub_M107_Emit_00532D90(int* pValue, int bClear)
{
    if (bClear)
        return sub_00532D90_ClearValue(pValue);
    return bClear + 1;
}

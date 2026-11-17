// 0x006216B0
static __forceinline int sub_006216B0_IsModeValue(int nMode, int nValue)
{
    switch (nMode)
    {
    case 0:
        if (nValue == 9)
        {
            return 1;
        }
        break;
    case 1:
        if (nValue == 6)
        {
            return 1;
        }
        break;
    }
    return 0;
}

int __fastcall sub_M119_Emit_006216B0(int nMode, int nValue, int nOther)
{
    return sub_006216B0_IsModeValue(nMode, nOther) + nValue;
}

struct D2UnitStrc;

// 0x004DAA70
void __fastcall sub_004DAA70_GetItemMode(D2UnitStrc* pUnit, int* pMode)
{
    switch (*pMode)
    {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
        *pMode = 4;
        break;

    case 3:
    case 5:
        *pMode = 3;
        break;
    }
}

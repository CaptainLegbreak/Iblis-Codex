struct D2UnitStrc;

void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);         // 0x0055BF50

// 0x0055BFE0
void __fastcall sub_0055BFE0_ClearTargetingFlags(D2UnitStrc* pUnit)
{
    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1E5);
}

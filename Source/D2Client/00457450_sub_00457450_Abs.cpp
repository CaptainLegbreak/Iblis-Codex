struct D2AutomapCellStrc
{
    int unk0x00;
    short nCellNo;
    short nY;
    short nX;
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
extern int gdwGlobal_007113E0;                                                                              // 0x007113E0
extern int gdwGlobal_007A51E4;                                                                              // 0x007A51E4
int gdwGlobal_007A51E8;                                                                                     // 0x007A51E8
extern int gdwGlobal_007A51E0;                                                                              // 0x007A51E0
extern int gdwGlobal_007113E4;                                                                              // 0x007113E4
extern int gdwGlobal_007113E8;                                                                              // 0x007113E8
int gaAutomapCellTable_007A3150[0x800];                                                                     // 0x007A3150
static int gnAutomapOffsetX_007A5198;                                                                       // 0x007A5198
static int gnAutomapOffsetY_007A519C;                                                                       // 0x007A519C
static int gnAutomapScale_00711254;                                                                         // 0x00711254

// 0x00457450
int __fastcall sub_00457450_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x00457750
int __fastcall sub_00457750_SaveAutomapCenters(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Centers", 0, nValue);
    gdwGlobal_007113E0 = nValue;
    return nValue;
}

// 0x00457780
int __fastcall sub_00457780_SaveAutomapLeft(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Left", 0, nValue);
    gdwGlobal_007A51E4 = nValue;
    gdwGlobal_007A51E8 = nValue;
    gdwGlobal_007A51E0 = nValue;
    return nValue;
}

// 0x004577C0
int __fastcall sub_004577C0_SaveAutomapParty(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Party", 0, nValue);
    gdwGlobal_007113E4 = nValue;
    return nValue;
}

// 0x004577F0
int __fastcall sub_004577F0_SaveAutomapPartyNames(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Party Names", 0, nValue);
    gdwGlobal_007113E8 = nValue;
    return nValue;
}

// 0x00457810
static __forceinline void sub_00457810_SubtractAutomapOffset(int* pX, int* pY)
{
    *pX -= gnAutomapOffsetX_007A5198;
    *pY -= gnAutomapOffsetY_007A519C;
}

// 0x00457830
static __forceinline void sub_00457830_ScaleAutomapPoint(int* pX, int* pY)
{
    *pX /= gnAutomapScale_00711254;
    *pY /= gnAutomapScale_00711254;
    *pX += 8;
    *pY -= 8;
    *pX -= gnAutomapOffsetX_007A5198;
    *pY -= gnAutomapOffsetY_007A519C;
}

void __fastcall sub_M117_Emit_00457810(int* pX, int* pY, int nScale)
{
    gnAutomapScale_00711254 = nScale;
    sub_00457810_SubtractAutomapOffset(pX, pY);
    sub_00457830_ScaleAutomapPoint(pX, pY);
    gnAutomapOffsetX_007A5198 = *pX;
    gnAutomapOffsetY_007A519C = *pY;
}

// 0x00457AC0
int __fastcall sub_00457AC0_CompareAutomapCells(const D2AutomapCellStrc* pA, const D2AutomapCellStrc* pB)
{
    int nResult = pA->nX - pB->nX;
    if (!nResult)
    {
        nResult = pA->nY - pB->nY;
        if (!nResult)
        {
            const int nCellA = pA->nCellNo;
            if (gaAutomapCellTable_007A3150[nCellA] != -1)
            {
                const int nCellB = pB->nCellNo;
                if (gaAutomapCellTable_007A3150[nCellA] != gaAutomapCellTable_007A3150[nCellB])
                {
                    nResult = nCellA - nCellB;
                }
            }
        }
    }

    return nResult;
}

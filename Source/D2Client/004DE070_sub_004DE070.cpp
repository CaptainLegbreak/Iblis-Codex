struct D2GridCellStrc
{
    unsigned char nB0;
    unsigned char nB1;
    unsigned char nB2;
    unsigned char nB3;
    int nX;
    int nY;
};

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
unsigned char __stdcall sub_0061C0E0(void* pAct);                                                           // 0x0061C0E0
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pR, unsigned char* pG, unsigned char* pB);           // 0x0061C0B0
void __fastcall sub_00475AA0(int nX, int nY, unsigned char* pB0, unsigned char* pB1, unsigned char* pB2, unsigned char* pB3); // 0x00475AA0

// 0x004DE070
void __stdcall sub_004DE070(D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int bFlat, int nMode, int bCorners)
{
    const unsigned char nB0 = sub_0061C0E0(gpGlobal_007A0634);
    D2GridCellStrc* pCell = pCells;
    switch (nMode)
    {
    case 1:
        nX += -(gnGlobal_0071146C / 4);
        break;
    case 2:
        nX += gnGlobal_0071146C / 4;
        break;
    }

    unsigned char nB1, nB2, nB3;
    sub_0061C0B0(gpGlobal_007A0634, &nB1, &nB2, &nB3);

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i, ++pCell)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                pCell->nX = ((i - j) << 4) + nX;
                pCell->nY = nY + ((i + j) << 3);
                if (bFlat)
                {
                    pCell->nB0 = nB0;
                    pCell->nB1 = nB1;
                    pCell->nB3 = nB3;
                    pCell->nB2 = nB2;
                }
                else
                    sub_00475AA0((nSubX + i) << 3, 8 * (nSubY + j), &pCell->nB0, &pCell->nB1, &pCell->nB2, &pCell->nB3);
            }
        }
    }
}

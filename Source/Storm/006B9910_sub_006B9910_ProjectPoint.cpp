extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern int gnOriginX_00981740; // 0x00981740
extern int gnOriginY_00981744; // 0x00981744
int gnTrigTable_00981748[0x2000];        // 0x00981748
extern int gnScale_00989748; // 0x00989748

// 0x006B9910
void __fastcall sub_006B9910_ProjectPoint(int nX, int nY, int nUnused, int* pScreenX, int* pScreenY, int bAlternate)
{
    int nA = ((nX - gnOriginX_00981740) * 24) >> 16;
    int nB = ((nY - gnOriginY_00981744) * 24) >> 16;
    int nSum = (nB + nA) * 724;
    int nDepth = (nSum * -512) >> 10;
    int nAngle = (nSum * 886) >> 20;
    int nCos = gnTrigTable_00981748[(nAngle - 0x1000) & 0x1FFF];

    int nHeight = (nDepth * nCos) >> 20;
    *pScreenX = (((nB - nA) * nCos * 724) >> 20) + gnScreenWidth_007C9138 / 2;

    *pScreenY = gnScreenHeight_007C913C / 2 + nHeight - 16;

    int nValue = nHeight - (((nDepth + 0x37400) * gnTrigTable_00981748[(nAngle - 0xF80) & 0x1FFF]) >> 20);

    if (bAlternate)
    {
        gnScale_00989748 = (nValue * 0x4CC) >> 10;
    }
    else
    {
        gnScale_00989748 = (nValue * 0x466) >> 10;
    }
}

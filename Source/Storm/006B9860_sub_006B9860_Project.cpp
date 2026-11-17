int gnOriginX_00981740;        // 0x00981740
int gnOriginY_00981744;        // 0x00981744
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern int gnPerspective_00981748[]; // 0x00981748

// 0x006B9860
void __fastcall sub_006B9860_Project(int x, int y, int z, int* outX, int* outY)
{
    int nA = ((x - gnOriginX_00981740) * 24) >> 16;
    int nB = ((y - gnOriginY_00981744) * 24) >> 16;
    int nZ = z * 1228;
    int nSum = (nB + nA) * 724;
    int nScale = gnPerspective_00981748[(((nSum * 886 + nZ * 512) >> 20) - 4096) & 8191];
    *outX = (((nB - nA) * nScale * 724) >> 20) + gnScreenWidth_007C9138 / 2;
    *outY = ((((nZ * 886 - nSum * 512) >> 10) * nScale) >> 20) + gnScreenHeight_007C913C / 2 - 32;
}

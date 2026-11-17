#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

extern int gaScaleTable_00981748[0x2000]; // 0x00981748
extern int gnScaleTableReady_00989748; // 0x00989748

// 0x006B97D0
void __cdecl sub_006B97D0_BuildScaleTable()
{
    for (int j = 0; j < 0x2000; ++j)
    {
        const int i = j - 0x1000;
        const int nValue = D2_MIN(D2_MAX(i, -2999), 2999);
        gaScaleTable_00981748[j] = 3072000 / (nValue - 3000);
    }
    gnScaleTableReady_00989748 = 256;
}

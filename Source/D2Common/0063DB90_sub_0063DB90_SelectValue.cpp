// 0x0063DB90
static int __stdcall sub_0063DB90_SelectValue(int a, int b)
{
    if (b)
        return a ? 5 : 1;
    return a ? 3 : 0;
}

int __stdcall sub_K15_Emit5(int* p, int n)
{
    return sub_0063DB90_SelectValue(p[0], n) + sub_0063DB90_SelectValue(p[n], p[3]);
}

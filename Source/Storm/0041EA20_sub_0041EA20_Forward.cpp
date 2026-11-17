int __stdcall sub_0041E720_Worker(void* p1, unsigned int* p2, const void* p3, unsigned int n4, int n5);    // 0x0041E720

// 0x0041EA20
int __stdcall sub_0041EA20_Forward(void* p1, unsigned int* p2, const void* p3, unsigned int n4)
{
    return sub_0041E720_Worker(p1, p2, p3, n4, 0);
}

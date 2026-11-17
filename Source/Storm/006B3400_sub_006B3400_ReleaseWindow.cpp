void __cdecl sub_006B3320_ReleaseResources(); // 0x006B3320
extern void* ghDDrawWindow_007C9140; // 0x007C9140
// 0x006B3400
int __cdecl sub_006B3400_ReleaseWindow()
{
    sub_006B3320_ReleaseResources();
    ghDDrawWindow_007C9140 = 0;
    return 1;
}

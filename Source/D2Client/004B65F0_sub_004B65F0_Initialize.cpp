void __cdecl sub_004B5140(); // 0x004B5140
extern int gnGlobal_00726E47; // 0x00726E47
extern void (__cdecl* gpfnCallback_00726E59)(); // 0x00726E59
extern unsigned short gwGlobal_00726E4D; // 0x00726E4D

// 0x004B65F0
int __cdecl sub_004B65F0_Initialize()
{
    gnGlobal_00726E47 = 3;
    gpfnCallback_00726E59 = sub_004B5140;
    gwGlobal_00726E4D = 0xD36;
    return 1;
}

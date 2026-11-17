void __cdecl sub_006CB450_Cleanup(); // 0x006CB450
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CAEC0
void __cdecl sub_006CAEC0_RegisterCleanup()
{
    sub_00683824_RegisterExit(sub_006CB450_Cleanup);
}

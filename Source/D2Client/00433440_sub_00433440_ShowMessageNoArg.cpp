struct Unicode;
typedef void (__cdecl* D2LaunchDoneFn)();

void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380

// 0x00433440
void __fastcall sub_00433440_ShowMessageNoArg(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    sub_00433380_ShowMessage(pText, pfnDone, 0);
}

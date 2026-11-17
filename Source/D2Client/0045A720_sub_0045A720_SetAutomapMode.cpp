extern int gnAutomapMode_007A5150; // 0x007A5150
extern int gnAutomapStep_00711254; // 0x00711254
void __cdecl sub_0045A2B0_ReloadAutomapCels(); // 0x0045A2B0
void __fastcall sub_00457640(int force); // 0x00457640

// 0x0045A720
void __fastcall sub_0045A720_SetAutomapMode(int mode)
{
    if (mode != gnAutomapMode_007A5150)
    {
        gnAutomapMode_007A5150 = mode;
        gnAutomapStep_00711254 = 10;
        switch (mode)
        {
        case 1:
            gnAutomapStep_00711254 = 20;
            break;
        }
        sub_0045A2B0_ReloadAutomapCels();
        sub_00457640(1);
    }
}

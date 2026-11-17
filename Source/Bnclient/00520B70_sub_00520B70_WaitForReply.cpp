extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260

int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
int gnSlotArrayA_00882128[94];                                                                              // 0x00882128
int gdwGlobal_00882528;                                                                                     // 0x00882528

// 0x00520B70
int __fastcall sub_00520B70_WaitForReply(unsigned char nReply)
{
    const unsigned long dwStart = GetTickCount();
    while (!gnSlotArrayA_00882128[nReply])
    {
        if (gdwGlobal_00882528)
        {
            sub_005204A0_SetError(0x12);
            return 0;
        }
        if (GetTickCount() - dwStart > 45000)
        {
            sub_005204A0_SetError(0x11);
            return 0;
        }
        Sleep(10);
    }
    return 1;
}

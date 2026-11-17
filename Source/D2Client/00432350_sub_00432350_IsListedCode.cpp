extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __cdecl sub_00449AC0();                                                                                 // 0x00449AC0
int __cdecl sub_00449C00();                                                                                 // 0x00449C00
extern int gnWaitDone_00779994;                                                                             // 0x00779994

// 0x00432350
static int sub_00432350_IsListedCode(int nCode)
{
    switch (nCode)
    {
    case 2:
    case 10:
    case 11:
    case 12:
    case 13:
    case 126:
    case 127:
        return 1;
    }
    return 0;
}

int __cdecl sub_00432400_GetWaitStatus()
{
    if (gnWaitDone_00779994)
        return 1;

    if (sub_00449AC0())
    {
        switch (WaitForSingleObject((void*)sub_00449AC0(), 0))
        {
        case 0:
            return sub_00432350_IsListedCode(sub_00449C00()) ? 2 : 0;
        case 0x102:
            return 3;
        }
    }

    return 2;
}

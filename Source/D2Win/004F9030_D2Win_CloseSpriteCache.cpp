struct D2CelFileStrc;

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
};

void __stdcall sub_005FFE30_FreeTileCache(int bFree);                                                       // 0x005FFE30
int __stdcall WINDOW_Destroy();                                                                             // 0x004F5900

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern unsigned int gdwInvBitMasks[];                                                                       // 0x006CE2E8
int dword_6F8FE26C;                                                                                         // 0x007D55DC
void* ghMainWindow_6F8FE23C;                                                                                // 0x007D55AC
extern int dword_6F8BDF78;                                                                                  // 0x0072DDD4

// 0x004F9030
int __stdcall D2Win_CloseSpriteCache()
{
    dword_6F8FE26C = 0;
    ghMainWindow_6F8FE23C = 0;
    sub_005FFE30_FreeTileCache(1);
    WINDOW_Destroy();
    return 1;
}

// 0x004F9190
int __fastcall sub_004F9190()
{
    dword_6F8BDF78 = 0;
    return 1;
}

// 0x004F96F0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags)
{
    if (!pControl)
    {
        return;
    }

    if (nFlags)
    {
        pControl->dwFlags |= gdwBitMasks[0];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[0];
    }
}

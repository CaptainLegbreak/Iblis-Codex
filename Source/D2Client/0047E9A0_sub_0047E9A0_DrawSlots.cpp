extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[4];
    int nUnk0x14;
    int unk0x18[7];
    void* pCellFile;
    int unk0x38[4];
};

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern int gbSmallPanel_007BC978;                                                                           // 0x007BC978
extern int gnSlotState_007BC8F8[];                                                                          // 0x007BC8F8
extern int gnSlotFrame_007BC918[];                                                                          // 0x007BC918
extern int gnSlotX_007BC898[];                                                                              // 0x007BC898
extern int gnSlotY_007BC8B8[];                                                                              // 0x007BC8B8
extern void* gpSlotCells_007BC964;                                                                          // 0x007BC964

// 0x0047E9A0
void __stdcall sub_0047E9A0_DrawSlots(int bDraw)
{
    int nSlots = 8;
    if (!bDraw)
    {
        return;
    }

    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }

    int i = 0;
    if (nSlots > 0)
    {
        for (;;)
        {
            if (gnSlotState_007BC8F8[i] == 1)
            {
                D2CelContextStrc tContext = {};
                tContext.pCellFile = gpSlotCells_007BC964;
                tContext.nFrame = gnSlotFrame_007BC918[i] + 1;
                sub_004F6480(&tContext, gnSlotX_007BC898[i], gnSlotY_007BC8B8[i], -1, 5, 0);
                if (++i >= nSlots)
                    break;
            }
            else
            {
                D2CelContextStrc tContext = {};
                tContext.pCellFile = gpSlotCells_007BC964;
                tContext.nFrame = gnSlotFrame_007BC918[i];
                sub_004F6480(&tContext, gnSlotX_007BC898[i], gnSlotY_007BC8B8[i], -1, 5, 0);
                if (++i >= nSlots)
                    break;
            }
        }
    }
}

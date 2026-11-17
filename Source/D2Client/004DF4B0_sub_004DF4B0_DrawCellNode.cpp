struct D2SoundStrc;

struct D2CellPosStrc
{
    int nX;
    int nY;
    char unk0x08[0x10];
    int f_18;
};

struct D2CellNodeStrc
{
    unsigned int dwFlags;
    int nA;
    int nB;
    D2CellPosStrc* pPos;
    D2CellNodeStrc* pNext;
};

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
};

struct D2SlotObjectStrc
{
    char unk0x00[0x2C];
    int nField0x2C;
    int nField0x30;
};

struct D2SlotStrc
{
    D2SoundStrc* f_0;
    int nType;
    D2SlotObjectStrc* pObject;
    char unk0x0C[0x14];
};

int gdwGlobal_007C8C78;                                                                                     // 0x007C8C78
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
void __fastcall sub_00471620(D2CellPosStrc* pPos);                                                          // 0x00471620
void __stdcall sub_004F6980(int nHandle, int nX, int nY, int nArg4, int nArg5);                             // 0x004F6980
unsigned int __fastcall sub_005159B0_GetSoundSampleCount(D2SoundStrc* pSound);                              // 0x005159B0
int __fastcall sub_00514C90_GetSoundMode();                                                                 // 0x00514C90
int __cdecl sub_00513B60();                                                                                 // 0x00513B60
int __fastcall sub_00513B70_IsSoundEnvironEnabled();                                                        // 0x00513B70

// 0x004DF4B0
static __forceinline void sub_004DF4B0_DrawCellNode(D2CellGridViewStrc* pView, D2CellNodeStrc* pNode, int nArg)
{
    const int bMode = sub_004F51D0_IsPerspective();
    if (pNode->dwFlags & 1)
    {
        if (bMode)
        {
            sub_004F6980(pNode->pPos->f_18, pNode->nA, pNode->nB, 4, nArg);
        }
        else
        {
            sub_004F6980(pNode->pPos->f_18, pView->nOffsetX - pView->nScrollX + pNode->pPos->nX, pNode->pPos->nY - pView->nScrollY + pView->nOffsetY, 4, nArg);
        }
    }
    else if (pNode->dwFlags & 2)
    {
        sub_00471620(pNode->pPos);
    }
}

void __stdcall sub_M114_Emit_004DF4B0(D2CellGridViewStrc* pView, D2CellNodeStrc* pNode, int nArg)
{
    sub_004DF4B0_DrawCellNode(pView, pNode, nArg);
}

// 0x004DF790
void __fastcall sub_004DF790_ReleaseSlotObject(D2SlotStrc* pSlot)
{
    if (pSlot->pObject)
    {
        pSlot->pObject->nField0x30 = 2;
        pSlot->pObject->nField0x2C = 0;
        pSlot->pObject = 0;
    }
}

// 0x004DF900
unsigned int __fastcall sub_004DF900_GetSlotSampleCount(D2SlotStrc* pSlot)
{
    return sub_005159B0_GetSoundSampleCount(pSlot->f_0);
}

// 0x004DF910
int __cdecl sub_004DF910_GetSoundMode()
{
    return sub_00514C90_GetSoundMode();
}

// 0x004DF940
int __cdecl sub_004DF940()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }
    return sub_00513B60();
}

// 0x004DF960
int __cdecl sub_004DF960()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }
    return sub_00513B70_IsSoundEnvironEnabled();
}

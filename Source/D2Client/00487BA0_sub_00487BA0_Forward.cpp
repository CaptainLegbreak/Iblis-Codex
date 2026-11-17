struct D2UnitStrc;

int __fastcall sub_004B3870(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x004B3870
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
void __cdecl sub_K04_EmitUse(int nValue);

// 0x00487BA0
static void __stdcall sub_00487BA0_Forward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gdwGlobal_007BCBF0 = 5;
    sub_00468070_SetCursorItemState(0);
}

void __cdecl sub_K04_EmitForward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    sub_00487BA0_Forward(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    sub_K04_EmitUse(nArg7);
}

struct D2EscMenuUIStateStrc
{
    int bCheck;
    int bSave;
    int nSaved;
};

int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
extern D2EscMenuUIStateStrc gaEscMenuUIState_00713058[38];                                                  // 0x00713058

// 0x0047E200
void __fastcall sub_0047E200_CloseMenus(int bRestore)
{
    if (sub_004538D0(9))
    {
        sub_00455F20(9, 1, 0);
    }
    if (bRestore)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            if (gaEscMenuUIState_00713058[i].nSaved)
            {
                sub_00455F20(i, 0, 0);
            }
        }
    }
}

// 0x0047EC20
int __fastcall sub_0047EC20_IsPanelFreeForArg(int bArg)
{
    if (bArg && !sub_004538D0(0x17))
    {
        return 1;
    }
    return 0;
}

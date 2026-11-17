struct D2Object006C30D0Strc
{
    char unk000[0xB90];
    int aSlots[4];
    char unkBA0[0xC18 - 0xBA0];
    int bDisabled;
};

int __fastcall sub_006C2D70(D2Object006C30D0Strc* pObject, int nSlot, int nTimeout); // 0x006C2D70

// 0x006C30D0
int __fastcall sub_006C30D0_ServiceSlots(D2Object006C30D0Strc* pObject, int nTimeout)
{
    if (!pObject->bDisabled)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (pObject->aSlots[i] != -1)
            {
                sub_006C2D70(pObject, i, nTimeout);
            }
        }
    }
    return 1;
}

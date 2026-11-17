enum D2C_StatIds
{
    STAT_GOLD = 14,
    STAT_GOLDBANK = 15,
};

struct D2UnitStrc;

struct D2UiControlAStrc
{
    virtual void sub_Virtual00();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual int GetDirection();
    virtual unsigned int GetStep(int nArg);
};

struct D2UiControlBStrc
{
    virtual void sub_Virtual00();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual unsigned int GetValue();
    virtual void sub_Virtual30();
    virtual void sub_Virtual34();
    virtual void SetValue(int nValue);
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __cdecl sub_00453EE0_ClosePanel();                                                                     // 0x00453EE0

extern int gnGoldPanelMode_007A279C;                                                                        // 0x007A279C
extern D2UiControlAStrc* gpGoldControlA_007A27A4;                                                           // 0x007A27A4
extern D2UiControlBStrc* gpGoldControlB_007A27A8;                                                           // 0x007A27A8
extern unsigned int gnGoldPanelValue_007A2A68;                                                              // 0x007A2A68

// 0x00453FC0
int __cdecl sub_00453FC0_GoldPanelClose()
{
    sub_00453EE0_ClosePanel();
    return 0;
}

// 0x00453FE0
int __cdecl sub_00453FE0_GoldSpinnerChanged()
{
    const int nDirection = gpGoldControlA_007A27A4->GetDirection();
    const unsigned int nStep = gpGoldControlA_007A27A4->GetStep(0);
    if (gpGoldControlB_007A27A8)
    {
        gnGoldPanelValue_007A2A68 = gpGoldControlB_007A27A8->GetValue();
    }
    unsigned int nValue = gnGoldPanelValue_007A2A68;
    unsigned int nMax;
    if (gnGoldPanelMode_007A279C == 4)
    {
        nMax = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLDBANK, 0);
    }
    else
    {
        nMax = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLD, 0);
    }
    if (nDirection == 1)
    {
        nValue += nStep;
        if (nValue > nMax)
        {
            nValue = nMax;
        }
    }
    else if (nDirection == 2)
    {
        if (nStep > nValue)
        {
            nValue = 0;
        }
        else if (nValue)
        {
            nValue -= nStep;
        }
    }
    gnGoldPanelValue_007A2A68 = nValue;
    if (gpGoldControlB_007A27A8)
    {
        gpGoldControlB_007A27A8->SetValue(nValue);
    }
    return 0;
}

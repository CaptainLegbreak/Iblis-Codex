struct D2UiControlAStrc
{
    virtual ~D2UiControlAStrc();
};

struct D2UiControlBStrc
{
    virtual ~D2UiControlBStrc();
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
};

struct D2UiControlCStrc
{
    virtual ~D2UiControlCStrc();
};

void __fastcall sub_0046AA20(int nArg1, int nArg2); // 0x0046AA20
void __cdecl sub_00489880_OpenPanel(); // 0x00489880
void __cdecl sub_004A7A80_OpenPanel0(); // 0x004A7A80
void __fastcall sub_004B8020(void* pRes); // 0x004B8020

extern int gnGoldPanelMode_007A279C; // 0x007A279C
extern void* gpGlobal_007A27A0; // 0x007A27A0
D2UiControlAStrc* gpGoldControlA_007A27A4;        // 0x007A27A4
D2UiControlBStrc* gpGoldControlB_007A27A8;        // 0x007A27A8
D2UiControlCStrc* gpGoldControlC_007A27AC;        // 0x007A27AC
D2UiControlCStrc* gpGoldControlD_007A27B0;        // 0x007A27B0
int gbGoldPanelFlag_007A27B4;        // 0x007A27B4
extern unsigned int gnGoldPanelValue_007A2A68; // 0x007A2A68

static __forceinline int IsGoldPanelMode(int nMode)
{
    if (nMode <= 0)
    {
        return 0;
    }

    if (nMode > 4)
    {
        return 0;
    }

    return 1;
}

// 0x00453EE0
void __cdecl sub_00453EE0_ClosePanel()
{
    if (gbGoldPanelFlag_007A27B4)
    {
        sub_0046AA20(1, 1);
        gbGoldPanelFlag_007A27B4 = 0;
    }

    if (gpGoldControlB_007A27A8)
    {
        gnGoldPanelValue_007A2A68 = gpGoldControlB_007A27A8->GetValue();
    }

    if (gpGlobal_007A27A0)
    {
        sub_004B8020(gpGlobal_007A27A0);
        gpGlobal_007A27A0 = 0;
    }

    if (gpGoldControlA_007A27A4)
    {
        delete gpGoldControlA_007A27A4;
        gpGoldControlA_007A27A4 = 0;
    }

    if (gpGoldControlB_007A27A8)
    {
        delete gpGoldControlB_007A27A8;
        gpGoldControlB_007A27A8 = 0;
    }

    if (gpGoldControlC_007A27AC)
    {
        delete gpGoldControlC_007A27AC;
        gpGoldControlC_007A27AC = 0;
    }

    if (gpGoldControlD_007A27B0)
    {
        delete gpGoldControlD_007A27B0;
        gpGoldControlD_007A27B0 = 0;
    }

    if (gnGoldPanelMode_007A279C != 0)
    {
        if (IsGoldPanelMode(gnGoldPanelMode_007A279C))
        {
            sub_00489880_OpenPanel();
        }
    }
    else
    {
        sub_004A7A80_OpenPanel0();
    }
}

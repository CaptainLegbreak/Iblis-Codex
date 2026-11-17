struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#pragma pack(push, 2)
struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};
#pragma pack(pop)

int __cdecl sub_004B3500();                                                                                 // 0x004B3500
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId);                                                // 0x004B3230
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[];                                                         // 0x007BC9E0
extern unsigned char gnMaxTab_007BCC05;                                                                     // 0x007BCC05
extern int gnButtonCount_00722160;                                                                          // 0x00722160
extern int gnButtonRow_0072215C;                                                                            // 0x0072215C

static void sub_00487E20_SetButtonA(int nButton);                                                           // 0x00487E20
static void sub_00487E60_SetButtonB(int nButton);                                                           // 0x00487E60
static void sub_00487EA0_ClearButton(int nButton);                                                          // 0x00487EA0

static __declspec(noinline) void sub_00487E20_SetButtonA(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD07;
    gaPanelButtons_007BC9E0[nButton].nCel = 2;
    gaPanelButtons_007BC9E0[nButton].nType = 3;
    gaPanelButtons_007BC9E0[nButton].nFrame = 2;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

static __declspec(noinline) void sub_00487E60_SetButtonB(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD08;
    gaPanelButtons_007BC9E0[nButton].nCel = 3;
    gaPanelButtons_007BC9E0[nButton].nType = 4;
    gaPanelButtons_007BC9E0[nButton].nFrame = 4;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

static __declspec(noinline) void sub_00487EA0_ClearButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0;
    gaPanelButtons_007BC9E0[nButton].bActive = 0;
}

// build: context sub_00623C60
static int sub_00623C60(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x00487ED0
void __cdecl sub_00487ED0_SetupPanelButtons()
{
    const int bValue = sub_004B3500();
    int nUnitId;
    if (!sub_004B3230_GetSelectedUnitId(&nUnitId))
        return;

    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (!pUnit)
        return;
    int bButton3Set = 0;
    if (bValue)
    {
        gnMaxTab_007BCC05 = 1;
        sub_00487E20_SetButtonA(0);
        sub_00487E60_SetButtonB(1);
        gaPanelButtons_007BC9E0[2].nString = 0;
        gaPanelButtons_007BC9E0[2].nCel = 1;
        gaPanelButtons_007BC9E0[2].nType = 1;
        gaPanelButtons_007BC9E0[2].nFrame = 0;
        gaPanelButtons_007BC9E0[2].bActive = 0;
    }
    else
    {
        switch (sub_00623C60(pUnit))
        {
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
            gnMaxTab_007BCC05 = 3;
            sub_00487E20_SetButtonA(0);
            sub_00487E60_SetButtonB(1);
            sub_00487EA0_ClearButton(2);
            break;

        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            gnMaxTab_007BCC05 = 3;
            sub_00487E20_SetButtonA(0);
            sub_00487E60_SetButtonB(1);
            gaPanelButtons_007BC9E0[2].nString = 0xD0A;
            gaPanelButtons_007BC9E0[2].nCel = 4;
            gaPanelButtons_007BC9E0[2].nType = 1;
            gaPanelButtons_007BC9E0[2].nFrame = 6;
            gaPanelButtons_007BC9E0[2].bActive = 1;
            gaPanelButtons_007BC9E0[3].nString = 0x276F;
            gaPanelButtons_007BC9E0[3].nCel = 1;
            gaPanelButtons_007BC9E0[3].nType = 8;
            gaPanelButtons_007BC9E0[3].nFrame = 0x12;
            gnButtonCount_00722160 = 4;
            bButton3Set = 1;
            break;

        default:
            gnButtonCount_00722160 = 0;
            return;
        }
    }

    if (!bButton3Set)
    {
        gaPanelButtons_007BC9E0[3].nString = 0x1030;
        gaPanelButtons_007BC9E0[3].nCel = 9;
        gaPanelButtons_007BC9E0[3].nFrame = 0xA;
        gnButtonCount_00722160 = 4;
    }

    gaPanelButtons_007BC9E0[3].bActive = 1;
    gnButtonRow_0072215C = 3;
    gaPanelButtons_007BC9E0[0].nValue = 0;
    gaPanelButtons_007BC9E0[1].nValue = 0;
    gaPanelButtons_007BC9E0[2].nValue = 0;
    gaPanelButtons_007BC9E0[3].nValue = 0;
}

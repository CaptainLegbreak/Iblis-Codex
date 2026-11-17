struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#pragma pack(push, 1)
struct D2NpcMessageStrc
{
    unsigned short nMessage;
    char unk0x02[9];
    int nClass;
};

struct D2NpcEntryStrc
{
    char unk0x00[5];
    D2NpcMessageStrc* pMessages;
    int nCount;
    int nIndex;
    char bSelected;
};
#pragma pack(pop)

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_00487990_ResetHover();
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);
void __fastcall sub_004A10E0(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);
void __cdecl sub_004B17A0();
int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue);
void __fastcall sub_004B3C20(int nValue);
void __fastcall sub_004B8020(void* pRes);
extern char gbGlobal_007C0C69;                                                                              // 0x007C0C69
extern unsigned char gbGlobal_007C0C6A;                                                                     // 0x007C0C6A
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern D2NpcEntryStrc* gpNpcEntry_007C0C7D;                                                                 // 0x007C0C7D
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern void* gpRes_007C0D6F;                                                                                // 0x007C0D6F

// 0x004B40D0
static void __stdcall sub_004B40D0_ShowNpcMessage(char bFlag, int nIndex)
{
    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    if (!pNpc)
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gbGlobal_007C0C69 = 1;
    sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
    sub_004B8020(gpRes_007C0D6F);
    gpRes_007C0D6F = 0;
    gpNpcEntry_007C0C7D->bSelected = 1;
    if (!gbGlobal_007C0C6A)
    {
        sub_004B17A0();
        if (bFlag)
            nIndex = gpNpcEntry_007C0C7D->nIndex;
    }
    D2UnitStrc* pUnit = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    sub_004A10E0(pUnit, gpNpcEntry_007C0C7D->pMessages[nIndex % gpNpcEntry_007C0C7D->nCount].nMessage, 0);
}

int __cdecl sub_004B41C0_NextNpcMessage()
{
    sub_004B40D0_ShowNpcMessage(1, gpNpcEntry_007C0C7D->nIndex);
    return 1;
}

int __cdecl sub_004B41E0_GreetNpcMessage()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    if (gnGlobal_007C0D29)
    {
        D2UnitStrc* pNpc = sub_00463990(gnGlobal_007C0D25, 1);
        if (pNpc)
        {
            switch (pNpc->dwClassId)
            {
            case 0x201:
                if (nClass == 4)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xF);
                    return 1;
                }
                break;
            case 0x202:
                if (nClass == 2)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xB);
                    return 1;
                }
                break;
            case 0x203:
                if (nClass == 3)
                {
                    sub_004B40D0_ShowNpcMessage(0, 0xA);
                    return 1;
                }
                break;
            }
        }
    }
    if (nClass == gpNpcEntry_007C0C7D->pMessages[1].nClass)
        sub_004B40D0_ShowNpcMessage(0, 1);
    else
        sub_004B40D0_ShowNpcMessage(0, 0);
    return 1;
}

struct D2HoverTextStrc;
struct D2TextHeaderStrc;
struct D2MessageListStrc;

#pragma pack(push, 1)
struct D2HoverTextPacketStrc
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned int dwUnitId;
    unsigned char nArg;
    unsigned char unk0x07;
    unsigned char nMode;
    unsigned char unk0x09;
    unsigned short wStringId;
};
#pragma pack(pop)

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[39];
    D2HoverTextStrc* pHoverText;
};

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound);
void __fastcall sub_004A1510_ShowTextBox(unsigned short nStringId);
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemoryPool, const char* szText, int nGameFrame);       // 0x00661110
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(void* pMemPool);                                           // 0x00661240
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader);                                          // 0x006612A0
void __stdcall TEXT_CreateTextHeaderFromMessageList(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661510
void __stdcall TEXT_SortTextNodeListByStringId(D2TextHeaderStrc* pTextHeader);                              // 0x006616E0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);

unsigned short gwTextPanelClassId_007BF234;                                                                 // 0x007BF234
extern int gdwGlobal_007BF206;                                                                              // 0x007BF206
extern int gnGameFrame_007BF20E;                                                                            // 0x007BF20E
D2TextHeaderStrc* gpTextHeader_007BF250;                                                                    // 0x007BF250
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC

// build: context sub_00623C60
static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x004A1600
void __fastcall sub_004A1600_HandleHoverTextPacket(D2HoverTextPacketStrc* pPacket)
{
    if (pPacket->nType == 1)
    {
        D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, 1);
        if (pUnit && pPacket->nArg == 1 && pPacket->nMode == 3)
        {
            if (pUnit->pHoverText)
            {
                CHAT_FreeHoverMsg(0, pUnit->pHoverText);
            }

            char szText[20];
            sprintf(szText, gszFormatD_006D57BC, pPacket->wStringId);
            pUnit->pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame_007BF20E);
            return;
        }

        if (gpTextHeader_007BF250)
        {
            TEXT_FreeTextHeader(gpTextHeader_007BF250);
        }

        gpTextHeader_007BF250 = TEXT_AllocTextHeader(0);
        TEXT_CreateTextHeaderFromMessageList(gpTextHeader_007BF250, (D2MessageListStrc*)&pPacket->nArg);
        TEXT_SortTextNodeListByStringId(gpTextHeader_007BF250);
    }
    else if (pPacket->nType == 2)
    {
        D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, 2);
        if (pPacket->nMode == 3)
        {
            sub_004A1510_ShowTextBox(pPacket->wStringId);
            return;
        }

        gwTextPanelClassId_007BF234 = 0;
        gdwGlobal_007BF206 = pPacket->dwUnitId;
        if (pUnit)
        {
            gwTextPanelClassId_007BF234 = sub_00623C60(pUnit);
        }
        sub_004A1320_OpenTextPanel(pPacket->wStringId, 0, 1);
    }
    else
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

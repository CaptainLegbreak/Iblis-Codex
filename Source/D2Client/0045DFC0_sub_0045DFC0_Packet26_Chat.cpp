struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nLang;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[0x10];
};

struct D2ChatMessageStrc
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char f_2;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[0x10];
    char szText[0x100];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
void __fastcall sub_0049F490_PrintChatMessage(D2ChatMessageStrc* pMessage);                                 // 0x0049F490

// 0x0045DFC0
void __fastcall sub_0045DFC0_Packet26_Chat(const D2GSPacketSrv26* pPacket)
{
    D2ChatMessageStrc tMessage;
    const char* szName = pPacket->szName;
    tMessage.nHeader = pPacket->nHeader;
    tMessage.nType = pPacket->nType;
    tMessage.f_2 = pPacket->nLang;
    tMessage.nUnitType = pPacket->nUnitType;
    tMessage.nUnitId = pPacket->nUnitId;
    tMessage.nColor = pPacket->nColor;
    tMessage.nSubType = pPacket->nSubType;
    SStrCopy(tMessage.szName, szName, 0x10);
    szName += SStrLen(szName) + 1;
    SStrCopy(tMessage.szText, szName, 0x100);
    sub_0049F490_PrintChatMessage(&tMessage);
}

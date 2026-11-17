#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    int dwParam;
    unsigned char nParam;
    union
    {
        char szText[32];
        char szTextData[2][16];
    };
};
#pragma pack(pop)

struct Unicode
{
    unsigned short wChar;
    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2UnitStrc
{
    char unk0x00[0xC];
    int dwUnitId;
};

struct D2MonStatsTxt
{
    char unk0x00[0x6];
    unsigned short wNameStr;
};

struct D2SuperUniquesTxt
{
    char unk0x00[0x2];
    unsigned short wNameStr;
};

struct D2ObjectsTxt
{
    char szName[0x40];
    Unicode wszName[0x40];
};

struct D2StoredUnitRecordStrc;
struct D2DrlgActStrc;
struct D2ActiveRoomStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" unsigned int __cdecl strlen(const char* sz);

D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRecord(int nUnitId);                                    // 0x00479BB0
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry);                           // 0x004795C0
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);                               // 0x0047A0C0
const char* __fastcall sub_0047A210(D2UnitStrc* pUnit);                                       // 0x0047A210
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl sub_005269D0_Sprintf(int nCount, Unicode* pDest, const Unicode* pFormat, ...);                  // 0x005269D0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall sub_0049E3A0_PrintEventText(Unicode* pText, char nColor);                                   // 0x0049E3A0
void __fastcall sub_0049E5C0_PrintPartyText(Unicode* pText, char nColor);                                   // 0x0049E5C0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0
void __stdcall ENVIRONMENT_InitializeEnvironment(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom, int nIndex, int nTicks, int bEclipse); // 0x0061C240
void __fastcall sub_00476A80_StartTiming(int nArg1, int nArg2, int nArg3, int nArg4);                       // 0x00476A80
extern D2DrlgActStrc* gpGlobal_007A0634;                                                                    // 0x007A0634

// 0x0049E8F0
static int sub_0049E8F0_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket)
{
    D2StoredUnitRecordStrc* pRecord = sub_00479BB0_FindRecord(pPacket->dwParam);
    Unicode wszName[16];
    D2UnitStrc* pPlayer = sub_00463DD0();
    char szName[16];
    if (pRecord)
        strcpy(szName, sub_004795C0_GetEntryName(pRecord));
    else
        szName[0] = 0;
    sub_00526F20_ToUnicode(wszName, szName, 16);
    switch (pPacket->nParam)
    {
    case 1:
        sub_005269D0_Sprintf(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277A), wszName);
        break;
    case 2:
        sub_005269D0_Sprintf(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277B), wszName);
        break;
    case 3:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBA));
        sub_004B9A00(16, 0, 0, 0, 0);
        return 1;
    case 4:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBB));
        return 1;
    case 5:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBC));
        break;
    case 6:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBD));
        break;
    case 7:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBE));
        break;
    case 8:
        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0xFBF));
        sub_00526700(pOut, wszName);
        break;
    case 9:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFC0));
        break;
    case 10:
        sub_005269D0_Sprintf(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277C), wszName);
        break;
    case 11:
        sub_005269D0_Sprintf(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277D), wszName);
        break;
    }
    if (pPlayer)
    {
        const int nPlayerId = pPlayer->dwUnitId;
        if (sub_004DC440(nPlayerId, sub_0047A0C0_GetRecordUnitId(pRecord), 4))
            return 0;
    }
    return 1;
}

void __fastcall sub_0049EB10_HandleEventMessage(D2GSPacketSrv5A* pPacket)
{
    Unicode wszBuffer[0x132];
    Unicode wszName[16];
    Unicode wszName2[16];
    if (strlen(pPacket->szTextData[0]) >= 15)
        pPacket->szTextData[0][15] = 0;
    switch (pPacket->nType)
    {
    case 10:
        if (pPacket->szTextData[0][0])
        {
            sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
            sub_005267E0(wszBuffer, wszName);
            sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0x1026));
            sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
            return;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0x1027));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 16:
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0x2A38));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 9:
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xFCF));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 8:
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xFCC));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 0:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE37)) < 0x104, 0x114C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE37));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 1:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE38)) < 0x104, 0x1152);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE38));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 2:
        if (sub_00463DD0() && !strcmp(pPacket->szTextData[0], sub_0047A210(sub_00463DD0())))
            break;
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE39)) < 0x104, 0x115C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3B), wszName, wszAccount);
            sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
            return;
        }
        sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE39), wszName);
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 3:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3A)) < 0x104, 0x116A);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3C), wszName, wszAccount);
            sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
            return;
        }
        sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3A), wszName);
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 4:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3D)) < 0x104, 0x1178);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3D));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 13:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE44)) < 0x104, 0x117E);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE44));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 5:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3E)) < 0x104, 0x1184);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3E));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 6:
    {
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        const Unicode* pKiller;
        int nStringId;
        switch (pPacket->nParam)
        {
        case 0:
            if (!strlen(pPacket->szTextData[1]))
                goto unknown_killer;
            sub_00526F20_ToUnicode(wszName2, pPacket->szTextData[1], 16);
            nStringId = 0xE40;
            pKiller = wszName2;
            break;
        case 1:
            if (!pPacket->szTextData[1][0])
            {
                D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pPacket->dwParam);
                if (!pMonStatsTxtRecord)
                    goto unknown_killer;
                nStringId = 0xE3F;
                pKiller = D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr);
            }
            else
            {
                unsigned short wSuperUnique = *(unsigned short*)pPacket->szTextData[1];
                nStringId = 0xE40;
                D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(wSuperUnique);
                if (!pSuperUniquesTxtRecord)
                    goto unknown_killer;
                pKiller = D2LANG_GetStringFromTblIndex(pSuperUniquesTxtRecord->wNameStr);
            }
            break;
        case 2:
        {
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pPacket->dwParam);
            if (!pObjectsTxtRecord)
                goto unknown_killer;
            nStringId = 0xE3F;
            if (pPacket->dwParam == 11)
                pKiller = D2LANG_GetStringFromTblIndex(0xC98);
            else
                pKiller = pObjectsTxtRecord->wszName;
            break;
        }
        default:
            goto unknown_killer;
        }
        if (sub_00526800(D2LANG_GetStringFromTblIndex(nStringId)) + sub_00526800(pKiller) + 16 >= 0x132)
            return;
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(nStringId));
        sub_00526700(wszBuffer, pKiller);
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
unknown_killer:
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE41));
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    }
    case 7:
        if (sub_0049E8F0_FormatPartyEvent(wszBuffer, pPacket))
            sub_0049E5C0_PrintPartyText(wszBuffer, pPacket->nColor);
        return;
    case 11:
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x69B), wszName);
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 15:
        sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE43), pPacket->dwParam);
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 17:
        sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFC), pPacket->dwParam);
        sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
        return;
    case 18:
        sub_005269D0_Sprintf(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFD));
        if (gpGlobal_007A0634)
            ENVIRONMENT_InitializeEnvironment(gpGlobal_007A0634, sub_004646A0_GetPlayerRoom(), 5, 0, 1);
        sub_00476A80_StartTiming(6, 0xFA0, 0x2710, 0xFA0);
        sub_004B9A00(0x1220, 0, 0, 0, 0);
        break;
    default:
        return;
    }
    sub_0049E3A0_PrintEventText(wszBuffer, pPacket->nColor);
}

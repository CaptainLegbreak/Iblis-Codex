struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[0x08];
    unsigned int dwAnimMode;
};

struct D2ClientStrc
{
    char unk0x000[0x0A];
    unsigned short nSaveFlags;
    char unk0x00C[0x45E - 0x0C];
    unsigned short nGuildFlags;
    unsigned int f_460;
    char unk0x464[0x480 - 0x464];
    unsigned char nGuildBgColor;
    unsigned char nGuildFgColor;
    unsigned char f_482;
};

#pragma pack(push, 1)
struct D2CharacterPreviewRecordStrc
{
    unsigned char pComponents[0x0B];
    unsigned char nClass;
    unsigned char pComponentColors[0x0B];
    unsigned char nLevel;
    unsigned char nClientFlags[2];
    unsigned char nGuildFlags[2];
    unsigned char nGuildBgColor;
    unsigned char nGuildFgColor;
    unsigned char f_1E;
    unsigned int f_1F;
};
#pragma pack(pop)

#define PREVIEW_VERSION 0x0E
#define STAT_LEVEL 0x0C
#define PREVIEW_COPY_SIZE 0x0B
#define NUMBER_OF_PLAYERCLASSES 7
#define PREVIEW_MAX_LEVEL_INDEX 98
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 0x11
#define CLIENTSAVEFLAG_HARDCORE 0x04
#define CLIENTSAVEFLAG_DEAD 0x08
#define CLIENTSAVEFLAG_INVALID_1 0x01
#define CLIENTSAVEFLAG_INVALID_2 0x02
#define CLIENTSAVEFLAG_INVALID_10 0x10
#define PREVIEW_STRING_LENGTH 0x21

extern "C" void __stdcall sub_006BBF40(unsigned char* pBuffer, unsigned int nValue);                         // 0x006BBF40
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bFlag);                           // 0x00537860
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                // 0x00625480
void __stdcall sub_0063E510_FillInventoryTables(D2UnitStrc* pUnit, unsigned char* pTableA, unsigned char* pTableB);
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                                 // 0x0041D2A0
unsigned int __stdcall SStrLen(const char* szString);                                                          // 0x00413750
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

// 0x00539BE0
void __fastcall CLIENTS_FillCharacterPreviewInfo(D2ClientStrc* pClient, char* szInfo)
{
    sub_006BBF40((unsigned char*)szInfo, PREVIEW_VERSION);
    D2CharacterPreviewRecordStrc* pPreview = (D2CharacterPreviewRecordStrc*)(szInfo + 2);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        unsigned char aColors[16];
        unsigned char aComponents[16];
        unsigned char aGfx[16];
        const unsigned char nLevel = (unsigned char)STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
        const unsigned int nClassId = pPlayer->dwClassId;

        memset(aComponents, 0xFF, sizeof(aComponents));
        sub_0063E510_FillInventoryTables(pPlayer, aComponents, aGfx);
        SMemCopy(pPreview->pComponents, aComponents, PREVIEW_COPY_SIZE);
        pPreview->nClass = (unsigned char)nClassId < NUMBER_OF_PLAYERCLASSES ? (unsigned char)nClassId + 1 : 1;

        memset(aColors, 0xFF, sizeof(aColors));
        sub_0063E510_FillInventoryTables(pPlayer, aGfx, aColors);
        for (int i = 0; i < 16; ++i)
        {
            if (!aColors[i])
            {
                aColors[i] = 0xFF;
            }
        }
        SMemCopy(pPreview->pComponentColors, aColors, PREVIEW_COPY_SIZE);

        const unsigned char nLevelIndex = nLevel - 1;
        pPreview->nLevel = nLevelIndex <= PREVIEW_MAX_LEVEL_INDEX ? nLevel : 1;

        const unsigned int nMode = pPlayer->dwAnimMode;
        const unsigned short wSaveFlags = pClient->nSaveFlags;
        unsigned int nFlags = wSaveFlags;
        if ((nMode == PLRMODE_DEAD || nMode == PLRMODE_DEATH) && (wSaveFlags & CLIENTSAVEFLAG_HARDCORE))
        {
            nFlags |= CLIENTSAVEFLAG_DEAD;
        }
        else
        {
            nFlags &= 0xFFF7;
        }
        sub_006BBF40(pPreview->nClientFlags, nFlags);
        sub_006BBF40(pPreview->nGuildFlags, pClient->nGuildFlags);

        unsigned char nBgColor = pClient->nGuildBgColor;
        unsigned char nFgColor = pClient->nGuildFgColor;
        unsigned char nEmblem = pClient->f_482;
        if (!nBgColor)
        {
            nBgColor = 0xFF;
        }
        if (!nFgColor)
        {
            nFgColor = 0xFF;
        }
        if (!nEmblem)
        {
            nEmblem = 0xFF;
        }
        pPreview->nGuildBgColor = nBgColor;
        pPreview->nGuildFgColor = nFgColor;
        pPreview->f_1E = nEmblem;
        pPreview->f_1F = pClient->f_460;

        const int bBadLevel = nLevelIndex > PREVIEW_MAX_LEVEL_INDEX;
        const int bBadClass = (unsigned char)nClassId >= NUMBER_OF_PLAYERCLASSES;
        const int bBadFlags = (nFlags & CLIENTSAVEFLAG_INVALID_1) || (nFlags & CLIENTSAVEFLAG_INVALID_2) || (nFlags & CLIENTSAVEFLAG_INVALID_10);
        const int bBadLength = SStrLen(szInfo) != PREVIEW_STRING_LENGTH;
        if (bBadLevel || bBadClass || bBadFlags || bBadLength)
        {
            *szInfo = 0;
        }
    }
}

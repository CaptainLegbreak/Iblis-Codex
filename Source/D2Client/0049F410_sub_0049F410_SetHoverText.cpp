struct D2HoverTextStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xA4 - 0x08];
    D2HoverTextStrc* pHoverText;
};

struct D2StringSoundStrc
{
    unsigned short wStringId;
    unsigned short wSoundId;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
extern "C" unsigned int __cdecl strlen(const char* szString);
int __cdecl sub_00525150();                                                                         // 0x00525150
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemoryPool, const char* szText, int nGameFrame);       // 0x00661110
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId);                 // 0x00661230

extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern "C" const char gszFormatSound_006DA194[];                                                            // 0x006DA194
extern D2StringSoundStrc* gapClassStringSounds_00722F1C[];                                                  // 0x00722F1C
extern D2StringSoundStrc gaMonStringSounds_00723750[];                                                      // 0x00723750
extern int gnGameFrame_007BF20E;                                                                            // 0x007BF20E

// 0x0049F410
static void __stdcall sub_0049F410_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (!strlen(szText))
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        return;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame_007BF20E);
    CHAT_SetLangIdInHoverMsg(pHoverText, nLangId);
    if (pUnit->pHoverText)
        CHAT_FreeHoverMsg(0, pUnit->pHoverText);
    pUnit->pHoverText = pHoverText;
}

void __fastcall sub_004A0200_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId)
{
    char szText[12];

    if (!pUnit)
        return;

    const int nLangId = sub_00525150();
    if (nLangId < 6)
        return;
    if (nLangId > 7 && nLangId != 9)
        return;
    if (nStringId < 0xB76 || nStringId > 0x1230)
        return;

    if (pUnit->dwUnitType == 0)
    {
        D2StringSoundStrc* pTable = gapClassStringSounds_00722F1C[pUnit->dwClassId];
        for (int i = 0; i < 0x4A; ++i)
        {
            if (pTable[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatSound_006DA194, -1, -1, pTable[i].wSoundId);
                sub_0049F410_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
    else if (pUnit->dwUnitType == 1)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (gaMonStringSounds_00723750[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatD_006D57BC, gaMonStringSounds_00723750[i].wSoundId);
                sub_0049F410_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
}

#include "gen/data/Source/D2Client/0049F410_sub_0049F410_SetHoverText.inc"

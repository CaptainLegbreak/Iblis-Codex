#include "D2Client.h"

struct D2CellFileStrc;

struct Unicode
{
    unsigned short wChar;
};

struct D2AuxLevelEntryStrc
{
    int nType;
    int unk0x04[2];
};
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
D2CellFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                             // 0x004788B0
D2BitBufferStrc* __cdecl sub_004B32D0();                                                           // 0x004B32D0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);             // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);            // 0x0065C360
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...);                             // 0x00684BD5
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern D2AuxLevelEntryStrc gaAuxLevelEntries_00721D98[];                                                    // 0x00721D98
extern int gbQuestTimerActive_007BCC10;                                                                     // 0x007BCC10
int gnQuestTimerValue_007BCC14;                                                                             // 0x007BCC14
unsigned long gdwQuestTimerTicks_007BCC18;                                                                  // 0x007BCC18
extern D2CellFileStrc* gpHoradricCel_007BCC1C;                                                              // 0x007BCC1C

// 0x004521C0
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit)
{
    if (pText->wChar)
    {
        Unicode wszBuffer[0x400];
        wszBuffer[0].wChar = 0;
        for (int i = 1; i < 0x400; i++)
        {
            wszBuffer[i].wChar = 0;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        Unicode wszDigit[3];
        wszDigit[0].wChar = 0;
        wszDigit[1].wChar = 0;
        wszDigit[2].wChar = 0;
        char szDigit[4];
        wsprintfA(szDigit, "%c", (char)(nDigit + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_00526700(wszBuffer, pText);
        sub_005267E0(pText, wszBuffer);
    }
    return pText;
}

// 0x00482CA0
void __fastcall sub_00482CA0_RaiseAuxLevel(int nIndex)
{
    const int nType = gaAuxLevelEntries_00721D98[nIndex].nType;
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d = 0x22;
    unsigned char nLevel;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        sscanf(szAddress, "%d.%d.%d.%d", &a, &b, &c, &d);
        const unsigned char nLow = d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 0x22;
    }

    unsigned char nNeeded;
    switch (nType)
    {
    case 2:
        nNeeded = 2;
        break;
    case 3:
        nNeeded = 3;
        break;
    case 4:
        nNeeded = 4;
        break;
    case 5:
    case 6:
        nNeeded = 5;
        break;
    case 7:
        nNeeded = 7;
        break;
    default:
        nNeeded = 1;
        break;
    }

    if (nNeeded > nLevel)
    {
        int nValue;
        switch (nNeeded)
        {
        case 7:
            nValue = 0x23;
            break;
        case 5:
            nValue = 0xB2;
            break;
        case 4:
            nValue = 0x2A;
            break;
        case 3:
            nValue = 0x62;
            break;
        case 2:
            nValue = 0x26;
            break;
        default:
            nValue = 0x22;
            break;
        }
        d = nValue;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, d);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
}

// 0x0048A540
void __fastcall sub_0048A540_QuestCodeUpdate(int nCode)
{
    char szPath[0x104];
    D2BitBufferStrc* pQuestInfo = sub_004B32D0();
    if (nCode == 0x20747368)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 10, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 10, 11);
    }
    else if (nCode == 0x20326671)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 18, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 18, 11);
    }
    gbQuestTimerActive_007BCC10 = 1;
    gnQuestTimerValue_007BCC14 = 0;
    gdwQuestTimerTicks_007BCC18 = GetTickCount();
    if (!gpHoradricCel_007BCC1C)
    {
        SStrPrintf(szPath, 0x104, "%s\\ui\\menu\\horadric", szDataGlobal_006D4118);
        gpHoradricCel_007BCC1C = sub_004788B0(szPath, 0);
    }
}

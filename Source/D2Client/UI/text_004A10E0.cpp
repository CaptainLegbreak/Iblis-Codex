#include "D2Client.h"

struct D2UnitStrc { unsigned int dwUnitType; unsigned int dwClassId; unsigned int unk08; unsigned int dwUnitId; };
struct D2TextRowStrc { void* pText; D2TextRowStrc* pNext; };
#pragma pack(push, 2)
struct D2TextBlockStrc { D2TextRowStrc* pLines; unsigned char unknown04[0x12]; int unknown16; };
#pragma pack(pop)
struct Unicode { unsigned short wChar; };

void __fastcall FOG_Free(void* pMemory, const char* pFile, int nLine, int nZero); // 0x0040B3C0
void __fastcall sub_0044DA40(); // 0x0044DA40
D2SoundStrc* __fastcall sub_004B9610(int nSound); // 0x004B9610
void __fastcall sub_004B9EF0_ArmHint(D2SoundStrc* pSound, int nZero, int nZero2, int nMode); // 0x004B9EF0
D2UnitStrc* __fastcall sub_00463990(unsigned int nId, int nType); // 0x00463990
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int nType, unsigned int nId); // 0x004786A0
void __fastcall sub_004B3830_ClearNpcInventoryAndSound(unsigned int nUnitId); // 0x004B3830
void __fastcall sub_00467430_SetSelectionRect(D2RectStrc* pRect); // 0x00467430
void __cdecl sub_00466FE0(); // 0x00466FE0
int __fastcall sub_00502EF0(int nFont); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex); // 0x00524A30
D2TextBlockStrc* __fastcall sub_004A05E0_CreateTextBox(const Unicode* pText, int nMode); // 0x004A05E0
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* pText, const char* pSource, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_004E0650_GetStringSound(unsigned short nString); // 0x004E0650
void __fastcall sub_004CB190_ReleaseSkillSfx(D2UnitStrc* pUnit); // 0x004CB190
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_004B9A00(int nSound, D2UnitStrc* pUnit, int nMode, int nZero, int nZero2); // 0x004B9A00
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void* __stdcall sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(void* hWnd, void* pHandlers, int nCount); // 0x00451DB0

extern const char gszTextSourceFile_006DA13C[]; // 0x006DA13C
extern int gnTextTop_007225FC; // 0x007225FC
extern unsigned char gaHandlers_00722600[]; // 0x00722600
extern D2TextBlockStrc* gpTextBox_007BF0A4; // 0x007BF0A4
extern D2TextBlockStrc* gpPreviousTextBox_007BF1A8; // 0x007BF1A8
extern int gnTextState_007BF1BC; // 0x007BF1BC
extern int gnTextActive_007BF1C0; // 0x007BF1C0
extern int gnPreviousTextActive_007BF1C4; // 0x007BF1C4
extern unsigned int gnNpcId_007BF202; // 0x007BF202
extern int gnHasNpc_007BF20A; // 0x007BF20A
extern unsigned short gwMessage_007BF212; // 0x007BF212
extern unsigned long gnStartTick_007BF22C; // 0x007BF22C
extern int gnGlobal_007BF230; // 0x007BF230
extern int gnGlobal_007BF236; // 0x007BF236
extern int gnSoundPlaying_007BF24B; // 0x007BF24B
extern int gnSound_007BF260; // 0x007BF260
extern int gnTextLeft_007BF278; // 0x007BF278
static int gnHandlersSet_007BF27C; // 0x007BF27C

// 0x0049D370
static __declspec(noinline) void sub_0049D370_FreeTextLines(D2TextRowStrc* pLine)
{
    while (pLine)
    {
        D2TextRowStrc* pNext = pLine->pNext;
        FOG_Free(pLine->pText, gszTextSourceFile_006DA13C, 0x60F, 0);
        FOG_Free(pLine, gszTextSourceFile_006DA13C, 0x610, 0);
        pLine = pNext;
    }
}

// 0x0049D410
__forceinline void __stdcall sub_0049D410_FreeTextBox(D2TextBlockStrc* pBox)
{
    if (pBox)
    {
        sub_0049D370_FreeTextLines(pBox->pLines);
        FOG_Free(pBox, gszTextSourceFile_006DA13C, 0x68E, 0);
    }
}

// 0x004A10E0
void __fastcall sub_004A10E0_ShowNpcMessage(D2UnitStrc* pUnit, unsigned short nMessage, int nUnused)
{
    gnGlobal_007BF236 = 0;
    gnTextTop_007225FC = 12;
    gnTextLeft_007BF278 = (gnScreenWidth_0071146C - 325) / 2;
    gnGlobal_007BF230 = 0;
    sub_0044DA40();
    if (gnSound_007BF260)
    {
        D2SoundStrc* pSound = sub_004B9610(gnSound_007BF260);
        if (pSound)
            sub_004B9EF0_ArmHint(pSound, 0, 0, 4);
        gnSound_007BF260 = 0;
    }
    gnSoundPlaying_007BF24B = 0;
    if (!pUnit)
    {
        if (gnPreviousTextActive_007BF1C4)
        {
            if (gpPreviousTextBox_007BF1A8)
            {
                sub_0049D410_FreeTextBox(gpPreviousTextBox_007BF1A8);
                gpPreviousTextBox_007BF1A8 = 0;
            }
            gnPreviousTextActive_007BF1C4 = 0;
        }
        gnHasNpc_007BF20A = 0;
        gnNpcId_007BF202 = 0;
    }
    else
    {
        if (gnHasNpc_007BF20A)
        {
            D2UnitStrc* pPreviousNpc = sub_00463990(gnNpcId_007BF202, 1);
            if (pPreviousNpc && pPreviousNpc != pUnit)
            {
                sub_004786A0_SendDwords2(0x30, 1, gnNpcId_007BF202);
                sub_004B3830_ClearNpcInventoryAndSound(gnNpcId_007BF202);
            }
        }
        gnHasNpc_007BF20A = 1;
        gnNpcId_007BF202 = pUnit->dwUnitId;
    }
    D2RectStrc tRect;
    tRect.nTop = gnTextTop_007225FC;
    tRect.nBottom = (gnTextTop_007225FC + 182 < gnScreenHeight_00711470 - 53)
        ? gnTextTop_007225FC + 182 : gnScreenHeight_00711470 - 53;
    tRect.nLeft = gnTextLeft_007BF278 - 10;
    tRect.nRight = gnTextLeft_007BF278 + 335;
    sub_00467430_SetSelectionRect(&tRect);
    sub_00466FE0();
    gwMessage_007BF212 = nMessage;
    if (!gpTextBox_007BF0A4)
    {
        gnTextState_007BF1BC = 0;
        int nPreviousFont = sub_00502EF0(8);
        gpTextBox_007BF0A4 = sub_004A05E0_CreateTextBox(D2LANG_GetStringFromTblIndex(nMessage), 2);
        if (!gpTextBox_007BF0A4)
        {
            sub_00408A60(gszEmpty_006CC837, sub_00408090(), 0x1024);
            exit(-1);
        }
        sub_00502EF0(nPreviousFont);
        sub_004BAA50_RefreshHintRange();
        gnSoundPlaying_007BF24B = 0;
        int nSound = sub_004E0650_GetStringSound(nMessage);
        if (nSound)
        {
            sub_004CB190_ReleaseSkillSfx(pUnit);
            gnSoundPlaying_007BF24B = sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 5, 0, 0);
            gnSound_007BF260 = nSound;
        }
        gpTextBox_007BF0A4->unknown16 = 0;
        gnTextActive_007BF1C0 = 1;
        if (!gnHandlersSet_007BF27C)
        {
            gnHandlersSet_007BF27C = 1;
            gnStartTick_007BF22C = GetTickCount();
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaHandlers_00722600, 7);
        }
    }
}

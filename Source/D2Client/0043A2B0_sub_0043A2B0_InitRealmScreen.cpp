struct Unicode;
struct D2WinControlStrc;

struct D2FuncRecordStrc
{
    char unk0x00[0x0C];
    int nIndex;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x98];
    D2FuncRecordStrc* (__cdecl* pfnGetRecord)();
};

typedef void (__cdecl* D2LaunchDoneFn)();

int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
int __cdecl sub_00430B40();                                                                                 // 0x00430B40
char* __fastcall sub_00430B50_GetSlotName(int nIndex);                                                      // 0x00430B50
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);                        // 0x00433450
void __cdecl sub_004336C0();                                                                                // 0x004336C0
void __cdecl sub_00434060();                                                                                // 0x00434060
void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FD830(D2WinControlStrc* pControl);                                                   // 0x004FD830
void __fastcall sub_004FDA50(D2WinControlStrc* pControl);                                                   // 0x004FDA50
const char* __stdcall sub_005180E0(D2FuncRecordStrc* pRecord, int nIndex);                                  // 0x005180E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern char gData_00779A40[];                                                                               // 0x00779A40
extern D2WinControlStrc* gpControl_00779D8C;                                                                // 0x00779D8C
extern D2WinControlStrc* gpControl_00779D98;                                                                // 0x00779D98
extern int gnState_00779DAC;                                                                                // 0x00779DAC
extern D2WinControlStrc* gpControl_00779DD0;                                                                // 0x00779DD0
extern D2WinControlStrc* gpCharSelectText_00779DD4;                                                         // 0x00779DD4
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

static __declspec(noinline) int sub_00437A20_FindSlotName(const char* szName)
{
    int i = 0;
    char* szSlot;
    while (i < sub_00430B40() && (szSlot = sub_00430B50_GetSlotName(i)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            return 1;
        ++i;
    }
    return 0;
}

// 0x0043A2B0
int __cdecl sub_0043A2B0_InitRealmScreen()
{
    unsigned short nStringId;
    gnState_00779DAC = 0;
    if (gnLaunchMode_007795EC == 1)
    {
        sub_00434060();
        const int nCount = sub_00430B40();
        if (nCount != -1)
        {
            if (nCount != 0)
            {
                D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x7A);
                sub_004FD830(pControl);
                sub_004FDA50(pControl);
                gpControl_00779DD0 = sub_0042F430_CreateControl(0x94);
                gpCharSelectText_00779DD4 = sub_0042F430_CreateControl(0x95);
                sub_0042F430_CreateControl(0x69);
                gpControl_00779D98 = sub_0042F430_CreateControl(0x6B);
                gpControl_00779D8C = sub_0042F430_CreateControl(0x6C);
                sub_004FC9B0_SetText(sub_0042F430_CreateControl(0x6A), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

                if (!SRegLoadString("Diablo II", "Preferred Realm", 0, gData_00779A40, 0x100) || !sub_00437A20_FindSlotName(gData_00779A40))
                {
                    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
                    const int nIndex = pRecord->nIndex;
                    SStrCopy(gData_00779A40, sub_005180E0(pRecord, nIndex), 0x7FFFFFFF);
                    SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
                    if (!sub_00437A20_FindSlotName(gData_00779A40))
                    {
                        const char* szFirst = sub_00430B40() > 0 ? sub_00430B50_GetSlotName(0) : 0;
                        SStrCopy(gData_00779A40, szFirst, 0x7FFFFFFF);
                        SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
                    }
                }
            }
            else
            {
                sub_0043B9A0();
                nStringId = 0x14AA;
                goto fail;
            }
        }
        else
        {
            sub_0043B9A0();
            nStringId = 0x14E3;
            goto fail;
        }
    }
    return 1;

fail:
    sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(nStringId), sub_004336C0);
    return 0;
}

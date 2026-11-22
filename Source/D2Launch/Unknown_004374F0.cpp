#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

struct D2FuncTable_0077ABF0Strc;
struct Unicode;

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
int __cdecl sub_0043B830(); // 0x0043B830

void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __cdecl sub_00435330_ShowLoginScreen(); // 0x00435330
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0

int gnStatusDots_007799B4; // 0x007799B4

// 0x004374F0
int __stdcall sub_004374F0_UpdateStatusWait(int nArg)
{
    sub_00436AD0_UpdateStatus();
    if (!gnStatusDots_007799B4)
    {
        sub_0043B820_Clear();
        gnStatusDots_007799B4 = (int)gpFuncTable_0077ABF0->pfnSlot04();
        if (!gnStatusDots_007799B4)
        {
            D2Win_StopMessageLoop();
            return 1;
        }
    }

    if (WaitForSingleObject((void*)gnStatusDots_007799B4, 0) == 0)
    {
        D2Win_StopMessageLoop();
    }

    if (sub_0043B830())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        D2Win_StopMessageLoop();
    }

    return 1;
}

D2WinControlStrc* gpPasswordOk_007799A4; // 0x007799A4

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00437730
int __stdcall sub_00437730_ChangePassword(int bOk)
{
    char szOld[0x100];
    char szNew[0x100];
    char szName[0x100];
    if (!bOk)
    {
        sub_004370C0();
        return 1;
    }
    if (!sub_004F9710_TestFlag(gpPasswordOk_007799A4))
        return 1;
    const Unicode* pName = sub_004FDD90_GetEditText(gpPasswordEdit_007799BC);
    const Unicode* pOld = sub_004FDD90_GetEditText(gpPasswordEdit_007799C0);
    const Unicode* pNew = sub_004FDD90_GetEditText(gpPasswordEdit_007799C8);
    if (!sub_005264F0_Compare(pNew, sub_004FDD90_GetEditText(gpPasswordEdit_007799C4)))
    {
        if (sub_005264F0_Compare(pOld, pNew))
        {
            sub_005263E0(szName, pName, 0x100);
            sub_005263E0(szOld, pOld, 0x100);
            sub_005263E0(szNew, pNew, 0x100);
            {
                char szConfirm[0x100];
                sub_005263E0(szConfirm, pNew, 0x100);
            }
            if (gpFuncTable_0077ABF0->pfnSlot68() && gpFuncTable_0077ABF0->pfnSlotC0(szName, szOld, szNew))
            {
                sub_00435330_ShowLoginScreen();
                return 1;
            }
            sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
            return 0;
        }
        else
        {
            Unicode aText[0x100];
            sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B71), 0x13EE, 0, sub_004334D0_CloseBox, 0, 1, 0);
        }
    }
    else
    {
        Unicode aText[0x100];
        sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B72), 0x13EE, 0, sub_004334D0_CloseBox, 0, 1, 0);
    }
    return 1;
}

struct D2WinControlStrc;
struct D2WinControlInitStrc;
struct Unicode;

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    unsigned char nFlags1EF;
    char unk0x1F0[0x361 - 0x1F0];
    char szRealm0x361[0x20];
    char szRealm0x381[0x20];
};
#pragma pack(pop)

struct D2LaunchFuncsStrc
{
    char unk0x00[0x20];
    const char* (__fastcall* pfn0x20)(int nFlag);
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl);                                          // 0x004FA450
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength);                         // 0x004FDD50
int __stdcall sub_0043DBA0_ClearSelection(int nArg1, int nArg2, int nArg3);                                 // 0x0043DBA0
int __stdcall sub_00440110_OnEditChange(void* pMsg);                                                        // 0x00440110
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int, int, int)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(void*)); // 0x004FDB00
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText);                                // 0x004FCF80
void* __cdecl sub_00446CF0();                                                                               // 0x00446CF0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox);                                                      // 0x004F91C0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox);                                                     // 0x004FDD00
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30
void __cdecl sub_0043E660_UpdateOkEnabled();                                                                // 0x0043E660

extern D2WinControlInitStrc gtControlInit_0070D8D0;                                                         // 0x0070D8D0
extern D2WinControlInitStrc gtControlInit_0070D900;                                                         // 0x0070D900
extern D2WinControlInitStrc gtControlInit_0070D930;                                                         // 0x0070D930
extern D2WinControlInitStrc gtControlInit_0070D960;                                                         // 0x0070D960
extern D2WinControlInitStrc gtControlInit_0070D990;                                                         // 0x0070D990
extern D2WinControlInitStrc gtControlInit_0070D9F0;                                                         // 0x0070D9F0
extern D2WinControlInitStrc gtControlInit_0070DA20;                                                         // 0x0070DA20
extern D2WinControlInitStrc gtControlInit_0070E110;                                                         // 0x0070E110
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
D2WinControlStrc* gpControl_0077BCDC;                                                                       // 0x0077BCDC
D2WinControlStrc* gpControl_0077BCE0;                                                                       // 0x0077BCE0
D2WinControlStrc* gpControl_0077BCE4;                                                                       // 0x0077BCE4
D2WinControlStrc* gpControl_0077BCE8;                                                                       // 0x0077BCE8
extern D2WinControlStrc* gpControl_0077BCEC;                                                                // 0x0077BCEC
D2WinControlStrc* gpControl_0077BCF0;                                                                       // 0x0077BCF0
D2WinControlStrc* gpEditBox_0077BCF4;                                                                       // 0x0077BCF4
D2WinControlStrc* gpControl_0077BCFC;                                                                       // 0x0077BCFC

// 0x00440FC0
void __cdecl sub_00440FC0_CreateGatewayControls()
{
    gpControl_0077BCDC = CONTROL_Create(&gtControlInit_0070D8D0);

    gpControl_0077BCE0 = CONTROL_Create(&gtControlInit_0070D900);
    sub_004FD060_SetText(gpControl_0077BCE0, D2LANG_GetStringFromTblIndex(0x148D));

    gpControl_0077BCE4 = CONTROL_Create(&gtControlInit_0070D930);
    sub_004FD060_SetText(gpControl_0077BCE4, D2LANG_GetStringFromTblIndex(0x148E));

    gpControl_0077BCE8 = CONTROL_Create(&gtControlInit_0070D960);
    sub_004FD060_SetText(gpControl_0077BCE8, D2LANG_GetStringFromTblIndex(0x148F));

    gpControl_0077BCEC = CONTROL_Create(&gtControlInit_0070DA20);

    gpControl_0077BCF0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_0077BCF0);

    gpEditBox_0077BCF4 = CONTROL_Create(&gtControlInit_0070D990);
    sub_004FDD50_SetMaxLength(gpEditBox_0077BCF4, 0x20);
    sub_004FDAD0_SetKeyCallback(gpEditBox_0077BCF4, sub_0043DBA0_ClearSelection);
    sub_004FDB00_SetEnterCallback(gpEditBox_0077BCF4, sub_00440110_OnEditChange);

    gpControl_0077BCFC = CONTROL_Create(&gtControlInit_0070D9F0);

    const char* szList = gpLaunchFuncs_0077B09C->pfn0x20(gpCharInfo_0077BBD8->nFlags1EF & 0x20);

    if (gpCharInfo_0077BBD8->szRealm0x381[0])
    {
        D2Win_10045(gpControl_0077BCFC, gpCharInfo_0077BBD8->szRealm0x381);
    }

    if (gpCharInfo_0077BBD8->szRealm0x361[0] && strcmp(gpCharInfo_0077BBD8->szRealm0x381, gpCharInfo_0077BBD8->szRealm0x361))
    {
        D2Win_10045(gpControl_0077BCFC, gpCharInfo_0077BBD8->szRealm0x361);
    }

    while (*szList)
    {
        if (!gpCharInfo_0077BBD8->szRealm0x361[0] || strcmp(szList, gpCharInfo_0077BBD8->szRealm0x361))
        {
            D2Win_10045(gpControl_0077BCFC, szList);
        }

        while (*szList)
        {
            ++szList;
        }
        ++szList;
    }

    sub_004FFE10_SetTextA(gpEditBox_0077BCF4, (const char*)sub_00446CF0());
    sub_004F91C0(gpEditBox_0077BCF4);
    D2Win_10082(gpEditBox_0077BCF4);
    D2Win_10053(gpControl_0077BCFC, 0);
    sub_0043E660_UpdateOkEnabled();
}

#include "gen/data/Source/D2Client/00440FC0_sub_00440FC0_CreateGatewayControls.inc"

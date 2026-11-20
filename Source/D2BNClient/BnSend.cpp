#include "D2BNClient.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PlayerDataStrc;
struct D2TextHeaderStrc;
struct D2BnSizedReplyStrc;
struct QServer;
struct D2CriticalSectionStrc;
struct T0041D340;
struct D2BnRegistrationPacketStrc;
struct D2BnLogonRequestStrc;
struct D2BnCheckAdPacketStrc;
struct D2BnVersionPacketStrc;
struct D2BnLocalePacketStrc;
struct D2CommonChatIgnoreListStrc;
struct D2CommonIgnoreListStrc;
struct D2SetsTxt;
struct D2SetItemsTxt;
struct D2UniqueItemsTxt;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2HotkeyStrc;
struct D2BnGamesListPacketStrc;
struct D2BnAuthHashStrc;
struct D2BnLogonRealmPacketStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct D2BigLoginRecordStrc;
struct D2BigPowModStrc;
struct D2BigPairStrc;
struct D2BnAdClickStrc;
struct D2BnChangeProofStrc;
struct D2PacketBufferStrc;
struct D2BnKeyValuePacketStrc;
struct D2BnReadUserDataReplyStrc;
struct FSafeSock;
struct D2SystemTimeStrc;
struct D2FileTimeStrc;
struct D2TimeZoneInformationStrc;

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425D90_Init();                                                                               // 0x00425D90
    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);                                // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                                                        // 0x00425F00
};

struct D2BnRegistrationPacketStrc
{
    unsigned long nLead;
    unsigned long nRegistrationVersion;
    unsigned long nRegistrationAuthority;
    unsigned long nClientId;
    unsigned long f_10;
    char szText[0x400];
};

struct D2BnLogonRequestStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    unsigned int dwUnk0x0C;
};

struct D2BnCheckAdPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    long nTime;
};

struct D2BnVersionPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    char szText[0x500];
};

struct D2BnLocalePacketStrc
{
    D2FileTimeStrc tSystemTime;
    D2FileTimeStrc tLocalTime;
    long f_10;
    unsigned long nSystemLcid;
    unsigned long nUserLcid;
    unsigned long nUserLangId;
    char szText[0x100];
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) unsigned long __stdcall GetSystemDefaultLCID(void); // 0x006CC39C
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" long __cdecl _time32(long* pTime); // 0x006850E6
int __fastcall sub_0040D290_GetData(char* pBuffer, unsigned int* pnSize); // 0x0040D290
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __fastcall sub_0051A8F0_HandleLogon(int nArg1, int nArg2, const char* szText); // 0x0051A8F0
int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
int __fastcall sub_0051C760_SplitPackets(unsigned char* pBuffer, int nLength); // 0x0051C760
int __fastcall sub_0051E370_SetText(const char* szText, int nLength); // 0x0051E370
void __fastcall sub_0051EA40_SetStatus(int nStatus); // 0x0051EA40
int __fastcall sub_0051EA80_SetName(const char* szName); // 0x0051EA80
int __cdecl sub_0051EAA0_HasName(); // 0x0051EAA0
int __fastcall sub_0051E6D0_ParseLogon(int* pArg1, int* pArg2, char* szText); // 0x0051E6D0
int __fastcall sub_005204A0_SetError(int nError); // 0x005204A0
extern "C" const char szEmpty_006DEF80[]; // 0x006DEF80
extern long volatile gnConnected_00881BF0; // 0x00881BF0
extern long volatile gnReceiveThreads_00881BF4; // 0x00881BF4
extern int gbReady_00881BF8; // 0x00881BF8
extern long volatile gnDnsDone_00881BFC; // 0x00881BFC
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall sub_006C7130_FromWide(char* pDst, unsigned int nDstSize, const unsigned short* pSrc, unsigned int nCount, unsigned int* pnWritten, int nFlags); // 0x006C7130
int __stdcall sub_006C7960_ToWide(unsigned short* pDst, const char* szSrc, unsigned int nCount); // 0x006C7960
extern int gnChannelList_008818C8; // 0x008818C8
extern char* gpAdUrlReply_008818DC; // 0x008818DC
void __stdcall SMemCopy(void*, const void*, unsigned int); // 0x0041D2A0

struct D2CommonChatIgnoreListStrc
{
    virtual int sub_00610EB0_Add(const char* szName) = 0;                                                   // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName) = 0;                                                // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName) = 0;                                              // 0x00610380
    virtual void sub_00610F90_VirtSlot3() = 0;                                                              // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;                                           // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5() = 0;                                                              // 0x0060FC40
    virtual void sub_00611320_VirtSlot6() = 0;                                                              // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;                    // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled() = 0;                                                               // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;                                                 // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10() = 0;                                                             // 0x0060F500
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
};

D2CommonIgnoreListStrc* sub_00611560_GetOrCreateIgnoreList(); // 0x00611560
extern "C" int __fastcall sub_00520C20_GetSlotB(unsigned char nSlot); // 0x00520C20

struct D2SetsTxt { char unk0x000[0x128]; };

struct D2SetItemsTxt { char unk0x000[0x1B8]; };

struct D2UniqueItemsTxt { char unk0x000[0x14C]; };



#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};

#pragma pack(pop)
enum
{
    NUM_HOTKEYS = 114,
};

typedef void (__cdecl* D2WheelCallbackFn)();

typedef int (__stdcall* D2FarProcFn)();

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource); // 0x004743D0
void __cdecl sub_0049F960_ResetTextBox(); // 0x0049F960
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader); // 0x006612A0
void __stdcall sub_00416710_Unlock(void* pHandle); // 0x00416710
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2WheelCallbackFn gpfnWheelUp_007A7404; // 0x007A7404
extern D2WheelCallbackFn gpfnWheelDown_007A7408; // 0x007A7408
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90
extern D2UnitStrc* gpAiTargets_007A7470[]; // 0x007A7470
extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern int gnGlobal_007BCE2C; // 0x007BCE2C
extern int gnGlobal_00721E34; // 0x00721E34
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern int gdwGlobal_007BCBE4; // 0x007BCBE4
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF4; // 0x007BCBF4
extern int gdwGlobal_007BCBF8; // 0x007BCBF8
extern int gnGlobal_007BF1FA; // 0x007BF1FA
extern D2TextHeaderStrc* gpTextHeader_007BF250; // 0x007BF250
extern int gnGlobal_007C0E7C; // 0x007C0E7C
extern unsigned char* gpDDrawDebugFontGlyphs_008815AC; // 0x008815AC
extern void* gpReply_008818D0; // 0x008818D0
extern "C" void* gpCDKeyHandle_00882744; // 0x00882744
extern "C" void* gpCDKeyHandle_00882750; // 0x00882750

struct D2BnGamesListPacketStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nCount;
    char szText[0x100];
};

struct D2BnAuthHashStrc
{
    int f_0;
    int f_4;
    unsigned char abPasswordHash[0x14];
};

struct D2BnLogonRealmPacketStrc
{
    int f_0;
    unsigned char abProof[0x14];
    char szRealmName[0x100];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern int gdwGlobal_008818BC; // 0x008818BC
extern D2BnSizedReplyStrc* gpSizedReply_008818D4; // 0x008818D4
extern int gbDnsPending_008818E0; // 0x008818E0

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;
};

struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;

    void sub_00528480_HashThreeBlocks(const unsigned char* pFirst, const unsigned char* pSecond, const unsigned char* pThird, unsigned char* pDigest); // 0x00528480
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    int sub_00528760_ComputeLoginProof(D2BigLoginRecordStrc* pRecord, const unsigned char* pSalt, const unsigned char* pServerPublic); // 0x00528760
    int sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof);
};

struct D2BnAdClickStrc
{
    int nAdId;
    int bFlag;
};

struct D2BnChangeProofStrc
{
    unsigned char abProof[0x14];
    unsigned char abVerifier[0x40];
};

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pThreadAttributes, unsigned long nStackSize, unsigned long (__stdcall* pStartAddress)(void*), void* pParameter, unsigned long nCreationFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" int __cdecl memcmp(const void* pBuffer1, const void* pBuffer2, unsigned int nSize);
void __cdecl sub_00518D40_Log(const char* szFormat, ...); // 0x00518D40
int __cdecl sub_005193E0_LoadCache(); // 0x005193E0
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480
int __fastcall sub_0051A7D0_ChangePasswordLegacy(const char* szAccountName, const char* szOldPassword, const char* szNewPassword); // 0x0051A7D0
int __cdecl sub_0051C470_CloseBNetConnection(); // 0x0051C470
unsigned long __stdcall BattleConnectFastest(void* pParameter); // 0x0051D0A0
void __cdecl sub_0051D510_ReportNews(); // 0x0051D510
int __cdecl sub_0051DA30_LoadNews(); // 0x0051DA30
void __fastcall sub_0051ED00_QueryState(int* pState); // 0x0051ED00
int __cdecl sub_00520B30_ResetReplies(); // 0x00520B30
void __cdecl sub_00521B50_ReseedLogin(); // 0x00521B50
int __fastcall sub_005221F0_ChangePasswordProof(const char* szAccountName, const char* szOldPassword, const char* szNewPassword); // 0x005221F0
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize); // 0x0052AEB0
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330
int __fastcall SERVER_GetClientPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052BC20
int __fastcall sub_006BF6C0(void* pServer, int nClientId); // 0x006BF6C0
extern "C" const char gszNewsItemTypeName_0072FF8C[]; // 0x0072FF8C
extern int gbNewsActive_00881C24; // 0x00881C24
extern int (__fastcall* gpfnNewsMessage_00881C28)(unsigned int nStamp, const char* szText); // 0x00881C28
extern int (__cdecl* gpfnNewsRefresh_00881C2C)(); // 0x00881C2C
extern D2StormArray408Strc gtNewsItems_00881C30; // 0x00881C30
extern unsigned int gnNewsFirstIndex_00881C40; // 0x00881C40
extern unsigned int gnNewsNewest_00881C44; // 0x00881C44
extern unsigned char gabNewVerifier_00882640[0x40]; // 0x00882640
extern D2BigLoginRecordStrc gtLoginRecord_00882680; // 0x00882680
extern D2BigPairStrc gtBigPair_0088273C; // 0x0088273C
extern void* gpGlobal_00882D08; // 0x00882D08

struct D2BnKeyValuePacketStrc
{
    int nType;
    unsigned int nCount;
    char szText[1];
};

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

struct D2BnReadUserDataReplyStrc
{
    unsigned int nAccounts;
    unsigned int nKeys;
    unsigned int nCookie;
    char aData[1];
};

extern void* gpReply_008818CC; // 0x008818CC

// 0x00464810
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// 0x00464820
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case 0:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case 1:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00464930
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

// 0x004693B0
void __fastcall sub_004693B0(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp_007A7404)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp_007A7404), 0x383);
            gpfnWheelUp_007A7404();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown_007A7408)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown_007A7408), 0x38B);
            gpfnWheelDown_007A7408();
        }
    }
}

// 0x00469AA0
unsigned short __fastcall sub_00469AA0(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469D70
void __fastcall sub_00469D70(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// 0x00469D90
int __fastcall sub_00469D90(int nA, int nB)
{
    return sub_00469AA0(nA, nB) != 0xFFFF;
}

// 0x0046D750
void __cdecl sub_0046D750()
{
    for (int i = 0; i < 8; ++i)
    {
        gpAiTargets_007A7470[i] = 0;
    }
}

// 0x00483410
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// 0x00483440
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483470
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483960
void __cdecl sub_00483960()
{
    gabColors_007BCAD8[0] = sub_004FB180_FindPaletteIndex(0x80, 0, 0);
    gabColors_007BCAD8[1] = sub_004FB180_FindPaletteIndex(0, 0x80, 0);
    gabColors_007BCAD8[2] = sub_004FB180_FindPaletteIndex(0, 0, 0x80);
    gabColors_007BCAD8[3] = sub_004FB180_FindPaletteIndex(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = sub_004FB180_FindPaletteIndex(0x80, 0x40, 0x40);
}

// 0x00489840
int __cdecl sub_00489840_IsNpcState123()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3)
    {
        return 1;
    }

    return 0;
}

// 0x004898A0
void __fastcall sub_004898A0(int nMode)
{
    gnGlobal_007BCE2C = 1;
    if (gdwGlobal_007BCBF0 == 13)
    {
        gdwGlobal_007BCBF0 = 12;
    }

    sub_00455F20(5, 1, 0);
}

// 0x004898D0
void __fastcall sub_004898D0(int nState)
{
    gnGlobal_00721E34 = nState;
    if (nState == 0)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x004A1730
void __cdecl sub_004A1730_ClearPanel()
{
    sub_0049F960_ResetTextBox();
    gnGlobal_007BF1FA = 0;
    if (gpTextHeader_007BF250)
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

// 0x004B8A10
int __cdecl sub_004B8A10()
{
    if (gnGlobal_007C0E7C == 1 || gnGlobal_007C0E7C == 2)
    {
        return 1;
    }

    return 0;
}

// 0x005125B0
void __cdecl sub_005125B0_DDrawFreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs_008815AC)
    {
        FOG_Free(gpDDrawDebugFontGlyphs_008815AC, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs_008815AC = 0;
    }
}

unsigned int gnVersion_0088252C; // 0x0088252C

// 0x0051A490
int __cdecl sub_0051A490_SendRegistration()
{
    D2BnRegistrationPacketStrc tPacket;
    SRegLoadValue(szConfiguration_006DEC7C, "Registration Version", 2, &tPacket.nRegistrationVersion);
    SRegLoadValue(szConfiguration_006DEC7C, "Registration Authority", 2, &tPacket.nRegistrationAuthority);
    SRegLoadValue(szConfiguration_006DEC7C, "Client ID", 2, &tPacket.nClientId);
    SRegLoadValue(szConfiguration_006DEC7C, "Client Token", 2, &tPacket.f_10);
    tPacket.nLead = 1;
    tPacket.szText[1] = tPacket.szText[0] = 0;
    sub_0051C5C0_SendPacket(0x1E, &tPacket, 0x16);
    return 1;
}

// 0x0051A9C0
int __cdecl sub_0051A9C0_RequestLogon()
{
    sub_00520C00_ClearReply(7);
    sub_0051EA80_SetName(&gszEmptyAssertText);
    D2BnLogonRequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.dwPlatform = 0x49583836;
    tRequest.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tRequest.dwVersion = 0x0E;
    sub_00520C00_ClearReply(6);
    if (sub_0051C5C0_SendPacket(6, &tRequest, sizeof(tRequest)) < 0)
        return 0;
    while (!sub_0051EAA0_HasName())
    {
        if (sub_00520BF0_IsReplyReceived(7))
            break;
        if (sub_00520AE0())
            return 0;
        Sleep(10);
    }
    sub_0051EA40_SetStatus(0x66);
    if (sub_00520BF0_IsReplyReceived(7))
        return 0;
    char szText[0x100] = { 0 };
    int nArg2;
    int nArg1;
    if (!sub_0051E6D0_ParseLogon(&nArg1, &nArg2, szText))
    {
        sub_005204A0_SetError(1);
        return 0;
    }
    sub_0051E370_SetText(szEmpty_006DEF80, 2);
    sub_0051A8F0_HandleLogon(nArg1, nArg2, szText);
    sub_00520B70_WaitForReply(7);
    return 0;
}

char* gpAdUrlReply_008818DC; // 0x008818DC

// 0x0051AB30
void __fastcall sub_0051AB30_SetAdUrlReply(const void* pData, unsigned int nSize)
{
    if (gpAdUrlReply_008818DC)
        SMemFree(gpAdUrlReply_008818DC, ".\\BnSend.cpp", 0x188, 0);
    gpAdUrlReply_008818DC = (char*)SMemAlloc(nSize, ".\\BnSend.cpp", 0x189, 0);
    memcpy(gpAdUrlReply_008818DC, pData, nSize);
}

// 0x0051AB80
void __cdecl sub_0051AB80_FreeReplyBuffer()
{
    if (gpReply_008818CC)
    {
        FOG_Free(gpReply_008818CC, ".\\BnSend.cpp", 410, 0);
    }
    gpReply_008818CC = 0;
}

// 0x0051ABB0
char* __fastcall sub_0051ABB0_QueryAdUrl(int nAdId)
{
    sub_00520C00_ClearReply(0x41);
    if (sub_0051C5C0_SendPacket(0x41, &nAdId, 4) < 0)
    {
        return 0;
    }

    sub_00520B70_WaitForReply(0x41);
    if (!gpAdUrlReply_008818DC)
    {
        return 0;
    }

    return gpAdUrlReply_008818DC + 4;
}

// 0x0051ABF0
void* __cdecl sub_0051ABF0_QueryRealms()
{
    sub_00520C00_ClearReply(0x40);
    if (sub_0051C5C0_SendPacket(0x40, 0, 0) < 0)
    {
        return 0;
    }
    sub_00520B70_WaitForReply(0x40);
    return gpReply_008818CC;
}

// 0x0051AC20
void __cdecl sub_0051AC20_FreeChannelList()
{
    if (gnChannelList_008818C8)
    {
        FOG_Free((void*)gnChannelList_008818C8, ".\\BnSend.cpp", 0x1EF, 0);
    }
    gnChannelList_008818C8 = 0;
}

// 0x0051AC50
int __fastcall sub_0051AC50_GetChannelList(int bNoExpansion)
{
    unsigned int nFlags = 0;
    if (sub_0051BEC0_IsExpansion() && !bNoExpansion)
    {
        nFlags |= 1;
    }

    sub_00520C00_ClearReply(0x0B);
    sub_0051C5C0_SendPacket(0x0B, &nFlags, 4);
    sub_00520B70_WaitForReply(0x0B);
    return gnChannelList_008818C8;
}

// 0x0051AD70
int __fastcall sub_0051AD70_EscapeBytes(unsigned char* data, unsigned int length)
{
 if(length>0) {
 unsigned int i=0;
 do {
  if(i==255)return 0;
  if(data[0]==0) {
   SMemCopy(data+2,data+1,256);
   ++length;
   data[1]=1;
   data[0]=255;
   ++data;
   ++i;
  } else if(data[0]==255) {
   SMemCopy(data+2,data+1,256);
   ++length;
   data[1]=255;
   data[0]=255;
   ++data;
   ++i;
  }
 ++i;
 ++data;
 } while(i<length);
 }
 return 1;
}

// 0x0051AE10
int __fastcall sub_0051AE10_Send(const char* szArg1, const char* szArg2, int nArg3)
{
    int nProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    sub_0051C5C0_SendPacket(0x0B, &nProduct, 4);

    char szBuffer[0x200] = { 0 };
    SStrCopy(szBuffer, szArg1, 0x100);
    SStrCopy(&szBuffer[strlen(szBuffer) + 1], szArg2, 0x100);
    return sub_0051C5C0_SendPacket(0x0A, szBuffer, strlen(szBuffer) + strlen(&szBuffer[strlen(szBuffer) + 1]) + 2) >= 0;
}

// 0x0051AF20
int __cdecl sub_0051AF20_SendPacket10()
{
    return sub_0051C5C0_SendPacket(0x10, 0, 0) >= 0;
}

// 0x0051AF40
int __fastcall sub_0051AF40_ChatCommand(const char* szText)
{
    if (!szText || !strlen(szText))
    {
        return 0;
    }

    unsigned short wszText[0x200];
    unsigned int nLength = sub_006C7960_ToWide(wszText, szText, 0x1FF);
    if (!nLength)
    {
        return 0;
    }

    wszText[nLength] = 0;

    char szBuffer[0x200];
    if (sub_006C7130_FromWide(szBuffer, 0x1FF, wszText, 0x1FF, &nLength, 0))
    {
        return 0;
    }

    szBuffer[nLength] = 0;
    return sub_0051C5C0_SendPacket(0x0E, szBuffer, nLength) >= 0;
}

// 0x0051B010
int __cdecl sub_0051B010_CheckAd()
{
    D2BnCheckAdPacketStrc tPacket;
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = gnVersion_0088252C;
    tPacket.nTime = _time32(0);
    sub_0051C5C0_SendPacket(0x15, &tPacket, sizeof(tPacket));
    return 1;
}

// 0x0051B060
int __cdecl sub_0051B060_SendVersion()
{
    D2BnVersionPacketStrc tPacket;
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = gnVersion_0088252C;
    tPacket.szText[1] = tPacket.szText[0] = 0;
    sub_0051C5C0_SendPacket(0x21, &tPacket, 0x0E);
    return 1;
}

// 0x0051B1B0
int __cdecl sub_0051B1B0_SendStopAdv()
{
    sub_0051C5C0_SendPacket(2, 0, 0);
    return 1;
}

// 0x0051B1D0
int __cdecl sub_0051B1D0_LeaveGame()
{
    sub_00611560_GetOrCreateIgnoreList()->sub_0060F500_VirtSlot10();
    sub_0051C5C0_SendPacket(0x1F, 0, 0);
    return 1;
}

// 0x0051B1F0
int __fastcall sub_0051B1F0_GetStartAdvResult(int* pValue)
{
    *pValue = sub_00520C20_GetSlotB(0x1C);
    return sub_00520BF0_IsReplyReceived(0x1C);
}

// 0x0051B210
void __cdecl sub_0051B210_FreeBuffer()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

int gnClientToken_008818C4; // 0x008818C4

// 0x0051B240
void* __fastcall sub_0051B240_GetGamesList(const char* szGameName, const char* szGamePassword, int a3, int a4)
{
    D2BnGamesListPacketStrc tPacket;
    tPacket.unk0x00 = 0;
    tPacket.unk0x04 = 0;
    tPacket.unk0x08 = 0;
    tPacket.nCount = 0x19;

    char* pText = tPacket.szText;
    if (szGameName)
    {
        pText += SStrCopy(pText, szGameName, 0x100) + 1;
    }
    else
    {
        pText += SStrCopy(pText, &gszEmptyAssertText, 0x100) + 1;
    }

    if (szGamePassword)
    {
        pText += SStrCopy(pText, szGamePassword, 0x100) + 1;
    }
    else
    {
        pText += SStrCopy(pText, &gszEmptyAssertText, 0x100) + 1;
    }

    const int nLength = SStrCopy(pText, &gszEmptyAssertText, 0x100);
    const int nSize = (int)(pText - tPacket.szText) + nLength + 1 + 0x10;

    sub_00520C00_ClearReply(9);
    sub_0051C5C0_SendPacket(9, &tPacket, nSize);
    sub_00520B70_WaitForReply(9);
    return gpReply_008818D0;
}

// 0x0051B3B0
void __cdecl sub_0051B3B0_FreeSizedReply()
{
    if (gpSizedReply_008818D4)
    {
        FOG_Free(gpSizedReply_008818D4, ".\\BnSend.cpp", 0x3B2, 0);
    }
    gpSizedReply_008818D4 = 0;
}

// 0x0051B460
D2BnSizedReplyStrc* __fastcall sub_0051B460_LogonRealm(const char* szRealmName, const char* szRealmPassword)
{
    if (!szRealmName)
    {
        return 0;
    }

    D2BnAuthHashStrc tHash;
    gnClientToken_008818C4 += 1;
    tHash.f_0 = gnClientToken_008818C4;
    tHash.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tHash.abPasswordHash, szRealmPassword, strlen(szRealmPassword));

    D2BnLogonRealmPacketStrc tPacket;
    tPacket.f_0 = gnClientToken_008818C4;
    sub_005209D0_HashData(tPacket.abProof, &tHash, 0x1C);
    const int nLength = SStrCopy(tPacket.szRealmName, szRealmName, 0x100) + 1;

    sub_00520C00_ClearReply(0x3E);
    if (sub_0051C5C0_SendPacket(0x3E, &tPacket, nLength + 0x18) < 0)
    {
        return 0;
    }

    sub_00520B70_WaitForReply(0x3E);
    return gpSizedReply_008818D4;
}

// 0x0051B540
void __cdecl sub_0051B540_SendLocale()
{
    D2TimeZoneInformationStrc tTimeZone;
    memset(&tTimeZone, 0, sizeof(tTimeZone));
    GetTimeZoneInformation(&tTimeZone);
    D2SystemTimeStrc tSystemTime;
    GetSystemTime(&tSystemTime);
    D2SystemTimeStrc tLocalTime;
    GetLocalTime(&tLocalTime);
    D2BnLocalePacketStrc tPacket;
    SystemTimeToFileTime(&tSystemTime, &tPacket.tSystemTime);
    SystemTimeToFileTime(&tLocalTime, &tPacket.tLocalTime);
    tPacket.f_10 = tTimeZone.f_0;
    tPacket.nSystemLcid = GetSystemDefaultLCID();
    tPacket.nUserLcid = GetUserDefaultLCID();
    tPacket.nUserLangId = GetUserDefaultLangID();
    tPacket.szText[0] = 0;
    GetLocaleInfoA(0x400, 3, tPacket.szText, 0x40);
    char* p = tPacket.szText + strlen(tPacket.szText) + 1;
    GetLocaleInfoA(0x400, 5, p, 0x40);
    p += strlen(p) + 1;
    GetLocaleInfoA(0x400, 7, p, 0x40);
    p += strlen(p) + 1;
    GetLocaleInfoA(0x400, 0x1002, p, 0x40);
    p += strlen(p) + 1;
    sub_0051C5C0_SendPacket(0x12, &tPacket, p - tPacket.szText + 0x20);
}

int gdwGlobal_00881C04; // 0x00881C04

// 0x0051B6C0
int __fastcall sub_0051B6C0_OnAdClick(int nAdId, int bFlag)
{
    D2BnAdClickStrc tRecord;
    tRecord.nAdId = nAdId;
    tRecord.bFlag = bFlag != 0;
    sub_0051C5C0_SendPacket(0x16, &tRecord, sizeof(tRecord));
    return 1;
}

// 0x0051B6F0
int __fastcall sub_0051B6F0_SendKeyValues(const char* szName, unsigned int nCount, const char** ppKeys, const char** ppValues)
{
    unsigned int nSize = SStrLen(szName) + 1;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        nSize += SStrLen(ppKeys[i]) + 1;
        nSize += SStrLen(ppValues[i]) + 1;
    }

    D2BnKeyValuePacketStrc* pPacket = (D2BnKeyValuePacketStrc*)FOG_Alloc(nSize + 8, ".\\BnSend.cpp", 0x4C4, 0);
    pPacket->nType = 1;
    pPacket->nCount = nCount;

    char* pText = pPacket->szText;
    pText += SStrCopy(pText, szName, 0x7FFFFFFF) + 1;

    unsigned int i;
    for (i = 0; i < nCount; ++i)
    {
        pText += SStrCopy(pText, ppKeys[i], 0x7FFFFFFF) + 1;
    }

    for (i = 0; i < nCount; ++i)
    {
        pText += SStrCopy(pText, ppValues[i], 0x7FFFFFFF) + 1;
    }

    sub_00520C00_ClearReply(0x27);
    int bResult = sub_0051C5C0_SendPacket(0x27, pPacket, (unsigned int)(pText - (char*)pPacket)) >= 0;
    FOG_Free(pPacket, ".\\BnSend.cpp", 0x4E0, 0);
    return bResult;
}

static void* gpReply_008818D8; // 0x008818D8

// 0x0051B960
int __fastcall sub_0051B960_GetReadUserDataReply(unsigned int nKeys, unsigned int nCookie, char** ppValues, const unsigned int* pSizes)
{
    if (!sub_00520BF0_IsReplyReceived(0x26))
        return 0;

    D2BnReadUserDataReplyStrc* pReply = (D2BnReadUserDataReplyStrc*)gpReply_008818D8;
    if (!pReply || pReply->nAccounts != 1 || pReply->nKeys != nKeys || pReply->nCookie != nCookie)
        return 0;

    const char* pText = pReply->aData;
    for (unsigned int i = 0; i < nKeys; ++i)
    {
        if (*pText)
        {
            strncpy(ppValues[i], pText, pSizes[i]);
            const unsigned int nSize = pSizes[i];
            ppValues[i][nSize] = 0;
        }
        else
        {
            *ppValues[i] = 0;
        }
        pText += SStrLen(pText) + 1;
    }
    return 1;
}

// 0x0051BCF0
int __cdecl sub_0051BCF0_SendBuffer()
{
    unsigned int nSize = 0x5DC;
    char aBuffer[0x5DC];
    if (!sub_0040D290_GetData(aBuffer, &nSize))
        return 0;
    return sub_0051C5C0_SendPacket(0x5D, aBuffer, nSize) >= 0;
}

// 0x0051BEA0
long __cdecl sub_0051BEA0_GetConnected()
{
    return InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
}

// 0x0051BED0
void __fastcall sub_0051BED0_SetDnsPending(int bPending)
{
    gbDnsPending_008818E0 = bPending;
    Sleep(10);
}

// 0x0051C350
int __fastcall sub_0051C350_ChangePassword(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x31);
        sub_0051A7D0_ChangePasswordLegacy(szAccountName, szOldPassword, szNewPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x56);
        return sub_005221F0_ChangePasswordProof(szAccountName, szOldPassword, szNewPassword);
    }
    return 0;
}

// 0x0051D1C0
void* __cdecl sub_0051D1C0_OpenBNetConnection()
{
    unsigned long nThreadId;
    sub_00518D40_Log("Connecting to Battle.net...");
    if (InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0))
    {
        sub_0051A480_DebugLog("   already connected");
        return 0;
    }
    if (!sub_0051C470_CloseBNetConnection())
        return 0;
    InterlockedExchange(&gnDnsDone_00881BFC, 0);
    gbDnsPending_008818E0 = 0;
    Sleep(10);
    sub_005193E0_LoadCache();
    sub_00520B30_ResetReplies();
    sub_00521B50_ReseedLogin();
    gdwGlobal_00881C04 = 0;
    return CreateThread(0, 0, BattleConnectFastest, 0, 0, &nThreadId);
}

// 0x0051DBF0
int __fastcall sub_0051DBF0_LoadBNetNews(int (__fastcall* pfnMessage)(unsigned int nStamp, const char* szText), int (__cdecl* pfnRefresh)())
{
    gbNewsActive_00881C24 = 1;
    gpfnNewsMessage_00881C28 = pfnMessage;
    gpfnNewsRefresh_00881C2C = pfnRefresh;
    if (gtNewsItems_00881C30.f_8)
        SMemFree(gtNewsItems_00881C30.f_8, gszNewsItemTypeName_0072FF8C, -2, 0);
    gtNewsItems_00881C30.f_0 = 0;
    gtNewsItems_00881C30.f_4 = 0;
    gtNewsItems_00881C30.f_8 = 0;
    gnNewsNewest_00881C44 = 0;
    gnNewsFirstIndex_00881C40 = 0;
    if (sub_0051DA30_LoadNews())
        sub_0051D510_ReportNews();
    unsigned int nStamp = gnNewsNewest_00881C44;
    sub_0051C5C0_SendPacket(0x46, &nStamp, sizeof(nStamp));
    return 1;
}

// build: context sub_0051C7E0_ReceiveThread
unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter)
{
    char aBuffer[0x2000];
    int nResult = 1;
    if (InterlockedIncrement(&gnReceiveThreads_00881BF4) > 1)
    {
        InterlockedDecrement(&gnReceiveThreads_00881BF4);
        return 1;
    }
    while (!InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0) && !gbReady_00881BF8)
        Sleep(10);
    unsigned long dwLastTick = GetTickCount();
    int nUsed = 0;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    while (pSafeSock && !pSafeSock->bStopping && !InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        const int bReady = FOG_SOCKET_Select(pSafeSock);
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
        if (!pSafeSock || pSafeSock->bStopping || InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
            break;
        if (bReady)
        {
            const int nReceived = FOG_SOCKET_Receive(pSafeSock, &aBuffer[nUsed], sizeof(aBuffer) - nUsed);
            if (nReceived <= 0)
            {
                sub_00520AD0_SetDisconnected();
                nResult = 0;
                break;
            }
            nUsed = sub_0051C760_SplitPackets((unsigned char*)aBuffer, nReceived + nUsed);
        }
        const unsigned long dwTick = GetTickCount();
        if (dwTick - dwLastTick >= 180000)
        {
            sub_0051C5C0_SendPacket(0, 0, 0);
            dwLastTick = dwTick;
        }
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    }
    InterlockedDecrement(&gnReceiveThreads_00881BF4);
    return nResult;
}

// 0x0051DC80
void __fastcall sub_0051DC80(unsigned char* pDigest, const unsigned char* pData, unsigned int nLength)
{
    T0041D340 tContext;
    tContext.sub_00425D90_Init();
    tContext.sub_00425DD0_Update(pData, nLength);
    tContext.sub_00425F00_Final(pDigest);
}

// 0x0051F2D0
int __fastcall sub_0051F2D0_PatchUnk(int* pResult)
{
    int nState;
    sub_0051ED00_QueryState(&nState);
    switch (nState)
    {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        *pResult = 1;
        break;
    }
    return 0;
}

// 0x005220B0
int __fastcall sub_005220B0_SendLogonProof(const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    unsigned char abProof[0x14];
    const int bResult = gtBigPair_0088273C.sub_00528760_ComputeLoginProof(&gtLoginRecord_00882680, pSalt, pServerPublic);
    sub_0041D300_ZeroMemory(gtLoginRecord_00882680.szPassword, sizeof(gtLoginRecord_00882680.szPassword));
    if (bResult)
    {
        sub_0041D2A0_MemCopy(abProof, gtLoginRecord_00882680.abProof, sizeof(abProof));
        sub_0051C5C0_SendPacket(0x54, abProof, sizeof(abProof));
        return 1;
    }
    return 0;
}

// 0x00522310
int __fastcall sub_00522310_SendChangeProof(const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    D2BnChangeProofStrc tPacket;
    const int bResult = gtBigPair_0088273C.sub_00528760_ComputeLoginProof(&gtLoginRecord_00882680, pSalt, pServerPublic);
    sub_0041D300_ZeroMemory(gtLoginRecord_00882680.szPassword, sizeof(gtLoginRecord_00882680.szPassword));
    if (bResult)
    {
        sub_0041D2A0_MemCopy(tPacket.abProof, gtLoginRecord_00882680.abProof, sizeof(tPacket.abProof));
        sub_0041D2A0_MemCopy(tPacket.abVerifier, gabNewVerifier_00882640, sizeof(tPacket.abVerifier));
        sub_0041D300_ZeroMemory(gabNewVerifier_00882640, sizeof(gabNewVerifier_00882640));
        sub_0051C5C0_SendPacket(0x56, &tPacket, sizeof(tPacket));
        return 1;
    }
    return 0;
}

// 0x005239C0
void __cdecl sub_005239C0_UnlockCDKeys()
{
    if (gpCDKeyHandle_00882744)
    {
        sub_00416710_Unlock(gpCDKeyHandle_00882744);
        gpCDKeyHandle_00882744 = 0;
    }

    if (gpCDKeyHandle_00882750)
    {
        sub_00416710_Unlock(gpCDKeyHandle_00882750);
        gpCDKeyHandle_00882750 = 0;
    }
}

// 0x00528890
int D2BigPairStrc::sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof)
{
    unsigned char abProof[0x14];
    pState->sub_00528480_HashThreeBlocks(pRecord->abPublic, pRecord->abProof, pRecord->abKey, abProof);
    return memcmp(abProof, pServerProof, sizeof(abProof)) == 0;
}

// 0x0052B0E0
int __fastcall sub_0052B0E0(QServer* pUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize)
{
    CLIENT_ReadPacketFromBuffer(pPacketBuffer, nBufferSize);
    return 1;
}

// 0x0052B100
int __fastcall SERVER_ValidateClientPacket(D2PacketBufferStrc* pPacketBuffer, int nBufferSize, int* pPacketSize, int* pFlags, int* pType, int* pPriority, int nUnused1, int nUnused2, int nClientId)
{
    if (nBufferSize < sizeof(unsigned char))
        return 3;
    const unsigned char nHeader = pPacketBuffer->data[0];
    int nSize;
    if (SERVER_GetClientPacketSize(pPacketBuffer, nBufferSize, &nSize))
    {
        if (nHeader >= 0x71 && nHeader != 0xFF)
            return 4;
        if ((unsigned short)nSize > 0x204)
            return 4;
        const int nPacketSize = (unsigned short)nSize;
        if (nPacketSize <= nBufferSize)
        {
            *pFlags = 0;
            *pPacketSize = nPacketSize;
            if (nHeader < 0x67)
            {
                *pType = 1;
            }
            else if (nHeader < 0x71)
            {
                *pType = 0;
            }
            else
            {
                if (!sub_006BF6C0(gpGlobal_00882D08, nClientId))
                    return 4;
                *pType = 2;
            }
            *pPriority = 100;
            if (*pType == 0)
                return 2;
            if (*pType == 1)
                return 1;
            return *pType == 2 ? 1 : 2;
        }
    }
    return 3;
}

// 0x0052B720
int __fastcall sub_6FC020B0(QServer* pServer, int nClientId, const char* szFile, int nLine)
{
    unsigned char data[2];
    data[0] = 0xAF;
    data[1] = 1;
    sub_0052B330(0, nClientId, data, sizeof(data));
    return 1;
}

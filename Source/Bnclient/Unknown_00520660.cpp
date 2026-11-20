#include "D2Primitives.h"
typedef unsigned int size_t;
extern "C" size_t __cdecl strlen(const char* szString);
#pragma intrinsic(strlen)


struct D2BnClientIdReplyStrc
{
    unsigned int dwRegistrationVersion;
    unsigned int dwRegistrationAuthority;
    unsigned int dwClientId;
    unsigned int f_C;
};

struct D2BnStartVersioningStrc
{
    D2FileTimeStrc tFileTime;
    char szFileName[4];
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __cdecl sub_00518C70_StartLogging(int nMode, int nValue);                                               // 0x00518C70
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
void __fastcall sub_0051A540_SetValue(int nValue);                                                          // 0x0051A540
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_0051E3B0_SetCheckRevisionValue(const char* szValue);                                    // 0x0051E3B0
void __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910
int __fastcall sub_00520210_QueueMessage(int nId, const void* pData, unsigned int nLength);                // 0x00520210
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0

extern "C" const char szConfiguration_006DEC7C[];                                                           // 0x006DEC7C
extern int gdwGlobal_0072FFA8;                                                                              // 0x0072FFA8
extern int gdwGlobal_008822A0;                                                                              // 0x008822A0
extern int gdwGlobal_008822A4;                                                                              // 0x008822A4
int gdwGlobal_00882318;                                                                                     // 0x00882318
int gdwGlobal_00882350;                                                                                     // 0x00882350
int gdwGlobal_0088236C;                                                                                     // 0x0088236C
int gdwGlobal_0088239C;                                                                                     // 0x0088239C

// 0x00520660
int __fastcall sub_00520660_HandleReply0F(const void* pData, unsigned int nSize)
{
    sub_00520210_QueueMessage(0, pData, nSize);
    return 1;
}

// 0x00520C50
int __fastcall sub_00520C50_HandleReply2A(const int* pData, unsigned int nSize)
{
    gdwGlobal_00882350 = pData[0];
    return 1;
}

// 0x00520C60
int __fastcall sub_00520C60_HandleReply3D(const int* pData, unsigned int nSize)
{
    gdwGlobal_008822A4 = pData[0];
    gdwGlobal_0088239C = 1;
    return 1;
}

// 0x00520C80
int __fastcall sub_00520C80_HandleReply31(const int* pData, unsigned int nSize)
{
    gdwGlobal_008822A0 = pData[0];
    gdwGlobal_0088236C = 1;
    if (!gdwGlobal_008822A0)
        sub_005204A0_SetError(0xE);
    return 1;
}

// 0x00520CB0
int __fastcall sub_00520CB0_HandleClientId(const D2BnClientIdReplyStrc* pData, unsigned int nSize)
{
    if (!pData || nSize < 0x10)
    {
        sub_00518D40_Log("ERROR BDClientId: invalid response");
        return 0;
    }

    unsigned int nRegistrationVersion = pData->dwRegistrationVersion;
    unsigned int nRegistrationAuthority = pData->dwRegistrationAuthority;
    unsigned int nClientId = pData->dwClientId;
    unsigned int nClientToken = pData->f_C;
    SRegSaveValue(szConfiguration_006DEC7C, "Registration Version", 2, nRegistrationVersion);
    SRegSaveValue(szConfiguration_006DEC7C, "Registration Authority", 2, nRegistrationAuthority);
    SRegSaveValue(szConfiguration_006DEC7C, "Client ID", 2, nClientId);
    SRegSaveValue(szConfiguration_006DEC7C, "Client Token", 2, nClientToken);
    sub_00518C70_StartLogging(2, 4);
    sub_00518D40_Log("client acknowledged");
    sub_00518C70_StartLogging(2, -4);
    return 1;
}

// 0x00520D50
int __fastcall sub_00520D50_HandleReply28(const int* pData, unsigned int nSize)
{
    sub_0051A540_SetValue(pData[0]);
    return 1;
}

// 0x00520D60
int __fastcall sub_00520D60_HandleReply1C(const int* pData, unsigned int nSize)
{
    if (!pData[0])
        gdwGlobal_00882318 = 1;
    return 1;
}

// 0x00520D70
int __fastcall sub_00520D70_HandleLogonAck(const int* pData, unsigned int nSize)
{
    sub_0051A540_SetValue(pData[1]);
    sub_00518C70_StartLogging(2, 4);
    sub_00518D40_Log("logon acknowledged");
    sub_00518C70_StartLogging(2, -4);
    return 1;
}

// 0x00520DA0
int __fastcall sub_00520DA0_HandleReply29(const int* pData, unsigned int nSize)
{
    gdwGlobal_0072FFA8 = pData[0] == 0;
    return 1;
}

// 0x00520F60
int __fastcall sub_00520F60_HandleStartVersioning(const D2BnStartVersioningStrc* pData, unsigned int nSize)
{
    const char* szFileName = pData->szFileName;
    if (sizeof(D2FileTimeStrc) + strlen(szFileName) + 1 < nSize)
        sub_0051E3B0_SetCheckRevisionValue(szFileName + strlen(szFileName) + 1);
    sub_0051F910_Report(0x80000001, 3, 0, 0, &pData->tFileTime, szFileName, 0);
    return 1;
}

// 0x00520FC0
int __fastcall sub_00520FC0_HandleReply25(const void* pData, unsigned int nSize)
{
    sub_0051C5C0_SendPacket(0x25, pData, nSize);
    return 1;
}

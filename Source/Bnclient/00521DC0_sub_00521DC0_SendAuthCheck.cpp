struct D2CDKeyInfoStrc
{
    unsigned int dwKeyLength;
    unsigned int dwProductValue;
    unsigned int f_8;
    unsigned int f_C;
    unsigned int dwHash[5];
};

struct D2AuthCheckPacketStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int f_8;
    unsigned int nKeys;
    unsigned int bSpawn;
    D2CDKeyInfoStrc pKeys[2];
    char szData[0x200];
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
unsigned int gdwClientToken_00882530;                                                                       // 0x00882530

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
void __fastcall sub_0051E340_BuildCDKeyInfoForSlot(D2CDKeyInfoStrc* pKeyInfo, unsigned int dwClientToken, int nSlot); // 0x0051E340
int __fastcall sub_0051E6D0_RunCheckRevision(unsigned int* pExeVersion, unsigned int* pExeHash, char* szText); // 0x0051E6D0
int __cdecl sub_0051EAA0_HasName();                                                                         // 0x0051EAA0
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
int __cdecl sub_00520AE0();                                                                                 // 0x00520AE0
void __cdecl sub_005234D0_LockCDKeys();                                                                     // 0x005234D0
void __cdecl sub_005239C0_UnlockCDKeys();                                                                   // 0x005239C0
const char* __cdecl sub_00523AA0_GetExeInfo();                                                              // 0x00523AA0

// 0x00521DC0
int __cdecl sub_00521DC0_SendAuthCheck()
{
    D2AuthCheckPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));

    const long nTime = _time32(0);
    gdwClientToken_00882530 += GetTickCount() + nTime;
    tPacket.f_0 = gdwClientToken_00882530;

    if (!sub_0051EAA0_HasName())
    {
        do
        {
            if (sub_00520AE0())
            {
                return 0;
            }

            Sleep(10);
        }
        while (!sub_0051EAA0_HasName());
    }

    char szText[0x100];
    if (!sub_0051E6D0_RunCheckRevision(&tPacket.f_4, &tPacket.f_8, szText))
    {
        sub_005204A0_SetError(1);
        return 0;
    }

    tPacket.bSpawn = 0;
    sub_005234D0_LockCDKeys();

    char* pString;
    if (sub_0051BEC0_IsExpansion())
    {
        pString = &tPacket.szData[SStrCopy(tPacket.szData, szText, 0x200) + 1];
        tPacket.nKeys = 2;
        sub_0051E340_BuildCDKeyInfoForSlot(&tPacket.pKeys[0], gdwClientToken_00882530, 0);
        sub_0051E340_BuildCDKeyInfoForSlot(&tPacket.pKeys[1], gdwClientToken_00882530, 1);
        SStrCopy(pString, sub_00523AA0_GetExeInfo(), &tPacket.szData[0x200] - pString);
    }
    else
    {
        char* pData = (char*)&tPacket.pKeys[1];
        pString = &pData[SStrCopy(pData, szText, 0x200) + 1];
        tPacket.nKeys = 1;
        sub_0051E340_BuildCDKeyInfoForSlot(&tPacket.pKeys[0], gdwClientToken_00882530, 0);
        SStrCopy(pString, sub_00523AA0_GetExeInfo(), &pData[0x200] - pString);
    }

    sub_005239C0_UnlockCDKeys();
    sub_0051C5C0_SendPacket(0x51, &tPacket, (pString - (char*)&tPacket) + SStrLen(pString) + 1);
    return 1;
}

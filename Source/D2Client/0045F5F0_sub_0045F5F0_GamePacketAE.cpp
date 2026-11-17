struct Unicode;
struct SMSGHANDLER_PARAMS;

#pragma pack(push, 1)
struct D2GSPacketSrvAE
{
    unsigned char nHeader;
    unsigned short nLength;
    unsigned char pData[1];
};
#pragma pack(pop)

extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
void __fastcall sub_004802E0(unsigned char* pData, int nLength);                                            // 0x004802E0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_007A5254;                                                                               // 0x007A5254

// 0x0045F5F0
void __fastcall sub_0045F5F0_GamePacketAE(D2GSPacketSrvAE* pPacket)
{
    if (gdwGlobal_007A0610 == 2 || gdwGlobal_007A0610 == 3)
        sub_004802E0(pPacket->pData, pPacket->nLength);
}

// 0x0045FC60
void __cdecl sub_0045FC60_DrawLoadingTexts()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xBE - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
    if (sub_00408F20_HasExpansionMpq())
        sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x5578), 0);
    else
        sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1431), 0);
    sub_00502EF0(nOldFont);
}

// 0x0045FFB0
void __stdcall sub_0045FFB0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A5254 = 0;
}

#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};


struct D2PanelButtonStrc
{
    int bActive;
    int unk0x04[1];
    unsigned short nString;
    unsigned short unk0x0A;
    int unk0x0C[2];
};

extern int gnGlobal_007BCA4C;                                                                               // 0x007BCA4C
extern int gnGlobal_007BCBD8;                                                                               // 0x007BCBD8

extern D2InvRectStrc gRect_007BCBB0;                                                                        // 0x007BCBB0
#define gnGlobal_007BCBB0 (gRect_007BCBB0.nLeft)
#define gnGlobal_007BCBB4 (gRect_007BCBB0.nRight)
#define gnGlobal_007BCBBC (gRect_007BCBB0.nBottom)
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnButtonCount_00722160;                                                                          // 0x00722160
extern int ganButtonX_00722168[][4];                                                                        // 0x00722168
extern D2PanelButtonStrc gaPanelButtons_007BC9E0[];                                                         // 0x007BC9E0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620
int __cdecl sub_004B32D0();                                                                        // 0x004B32D0
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
int __stdcall ITEMS_GetAllRepairCosts(void* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, int pQuestFlags, void* pfCallback); // 0x0062FE60
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004886C0
void __cdecl sub_004886C0_DrawButtonHoverText()
{
    if (gnGlobal_007BCA4C < gnGlobal_007BCBB0 || gnGlobal_007BCA4C > gnGlobal_007BCBB4)
    {
        return;
    }
    const int nTop = gnGlobal_00711470 + gnGlobal_007A285C - 0x6D;
    if (gnGlobal_007BCBD8 < nTop || gnGlobal_007BCBD8 > gnGlobal_007BCBBC)
    {
        return;
    }
    for (int i = 0; i < gnButtonCount_00722160; ++i)
    {
        if (gaPanelButtons_007BC9E0[i].bActive == 1
            && gnGlobal_007BCA4C > ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858
            && gnGlobal_007BCA4C < ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858 + 0x2D
            && gnGlobal_007BCBD8 > gnGlobal_00711470 + gnGlobal_007A285C - 0x6D
            && gnGlobal_007BCBD8 < gnGlobal_00711470 + gnGlobal_007A285C - 0x41)
        {
            if (gaPanelButtons_007BC9E0[i].nString == 0x276F)
            {
                Unicode wszText[0x100];
                D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
                D2UnitStrc* pNpc = sub_004B1620_GetInteractNpc();
                if (pPlayer && pNpc)
                {
                    const int nNpcClass = pNpc->dwClassId;
                    sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x276F),
                        ITEMS_GetAllRepairCosts(0, pPlayer, nNpcClass, sub_0044DCD0_GetDifficulty(), sub_004B32D0(), 0));
                    D2Win_10129_DrawFramedText(wszText, ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858,
                        gnGlobal_00711470 + gnGlobal_007A285C - 0x64, 0, 0);
                }
            }
            else
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(gaPanelButtons_007BC9E0[i].nString),
                    ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x64, 0, 0);
            }
            return;
        }
    }
}

#include "gen/data/Source/D2Client/UI/inv_004886C0.inc"

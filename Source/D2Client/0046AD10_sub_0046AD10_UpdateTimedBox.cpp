struct D2ActiveRoomStrc;

struct D2ClientTimedBoxStrc
{
    int bActive;
    int nValue;
    unsigned char nColor[4];
    int nFadeIn;
    int nFadeOut;
    int nHold;
    int nTotal;
    int nTick;
    int nAngle;
    int nLevelId;
    int bLocked;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
float __stdcall sub_0040B330_Cos(int nAngle);                                                               // 0x0040B330
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();                                                     // 0x004646A0
void __fastcall sub_00474550_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pLight, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int nFlag); // 0x00474550
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ClientTimedBoxStrc gtTimedBox_007A742C;                                                                   // 0x007A742C

// 0x0046AD10
void __cdecl sub_0046AD10_UpdateTimedBox()
{
    unsigned int nLight = 0;
    sub_00474550_GetRoomLight(sub_004646A0_GetPlayerRoom(), (int*)&nLight, &gtTimedBox_007A742C.nColor[0], &gtTimedBox_007A742C.nColor[1], &gtTimedBox_007A742C.nColor[2], 0);

    if (gtTimedBox_007A742C.nTick < gtTimedBox_007A742C.nFadeIn)
    {
        gtTimedBox_007A742C.nValue = (int)(sub_0040B330_Cos(gtTimedBox_007A742C.nAngle) * nLight);
        gtTimedBox_007A742C.nAngle = (gtTimedBox_007A742C.nTick << 7) / gtTimedBox_007A742C.nFadeIn;
    }
    else if (gtTimedBox_007A742C.nTick >= gtTimedBox_007A742C.nTotal - gtTimedBox_007A742C.nFadeOut)
    {
        gtTimedBox_007A742C.nValue = (int)(sub_0040B330_Cos(gtTimedBox_007A742C.nAngle) * nLight);
        const int nElapsed = gtTimedBox_007A742C.nFadeOut - gtTimedBox_007A742C.nTotal + gtTimedBox_007A742C.nTick;
        if (!gtTimedBox_007A742C.nFadeOut)
        {
            gtTimedBox_007A742C.nFadeOut = 0x19;
        }
        gtTimedBox_007A742C.nAngle = 0x80 - (nElapsed << 7) / gtTimedBox_007A742C.nFadeOut;
    }
    else
    {
        gtTimedBox_007A742C.nValue = 0;
    }

    ++gtTimedBox_007A742C.nTick;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }
    if (gtTimedBox_007A742C.nTick > gtTimedBox_007A742C.nTotal || nLevelId != gtTimedBox_007A742C.nLevelId)
    {
        memset(&gtTimedBox_007A742C, 0, sizeof(gtTimedBox_007A742C));
    }
}

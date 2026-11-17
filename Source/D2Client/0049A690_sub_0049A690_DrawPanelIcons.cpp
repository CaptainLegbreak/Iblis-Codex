struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2CelFileStrc;
struct D2CelStrc;
struct D2StoredUnitRecordStrc;

struct D2GfxDataStrc
{
    int nFrame;
    unsigned char unk0x04;
    unsigned char nComponent;
    unsigned short unk0x06;
    int nUnitType;
    int nUnitIndex;
    unsigned int nMode;
    int unk0x14;
    unsigned int dwUnitToken;
    unsigned int dwComponentToken;
    unsigned int dwArmorType;
    unsigned int dwModeToken;
    unsigned int dwWClassToken;
    int unk0x2C[2];
    D2CelFileStrc* pCelFile;
    int nDrawFlag;
    D2CelStrc* pCel;
    int nDirection;
    unsigned int dwFlags;
};

#pragma pack(push, 1)
struct D2PanelIconStrc
{
    int nX;
    int nY;
    D2CelFileStrc* pCelFile;
    unsigned int nFrame;
    int nType;
    int nState;
    int unk0x18[2];
};

struct D2PanelIconRecordStrc
{
    int unk0x00;
    D2PanelIconStrc pIcons[5];
    unsigned char unk0xA4[0x19];
    int nLevel;
    int unk0xC1;
    int nUnitId;
};
#pragma pack(pop)

extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
static unsigned char gnBoxColor_007BF034;                                                                   // 0x007BF034
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __cdecl sub_0044B850_IsHardcore();                                                                      // 0x0044B850
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, unsigned char nArg6); // 0x0046EFD0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

// 0x0049A690
void __stdcall sub_0049A690_DrawPanelIcons(D2PanelIconRecordStrc* pRecord)
{
    D2UnitStrc* pPlayer = sub_00463DD0();

    D2GfxDataStrc tGfx;
    memset(&tGfx, 0, sizeof(tGfx));
    tGfx.nDirection = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (pRecord->pIcons[i].nType || pRecord->pIcons[i].nState != 1)
        {
            tGfx.pCelFile = pRecord->pIcons[i].pCelFile;
            const unsigned int nFrame = pRecord->pIcons[i].nFrame;
            tGfx.nFrame = nFrame;

            switch (pRecord->pIcons[i].nType)
            {
            case 1:
                if (nFrame < 4 || nFrame > 7)
                {
                    tGfx.nFrame = 4;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnGlobal_007A2858, pRecord->pIcons[i].nY - gnGlobal_007A285C, -1, 5, 0);
                break;

            case 2:
                if (nFrame < 12 || nFrame > 15)
                {
                    tGfx.nFrame = 12;
                }

                if (sub_0044B850_IsHardcore())
                {
                    TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnGlobal_007A2858, pRecord->pIcons[i].nY - gnGlobal_007A285C, -1, 5, 0);
                }
                break;

            case 3:
                if (nFrame > 3)
                {
                    tGfx.nFrame = 0;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnGlobal_007A2858, pRecord->pIcons[i].nY - gnGlobal_007A285C, -1, 5, 0);
                break;

            case 4:
                if (nFrame < 8 || nFrame > 11)
                {
                    tGfx.nFrame = 8;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnGlobal_007A2858, pRecord->pIcons[i].nY - gnGlobal_007A285C, -1, 5, 0);
                break;

            default:
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnGlobal_007A2858, pRecord->pIcons[i].nY - gnGlobal_007A285C, -1, 5, 0);
                break;
            }
        }

        if (pRecord->pIcons[i].nType == 1)
        {
            int bShowBox = 0;
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
            {
                bShowBox = 1;
            }

            if (pRecord->nLevel < 9 && !sub_004DC440(sub_00451F50_GetUnitGUID(pPlayer), pRecord->nUnitId, 8))
            {
                bShowBox = 1;
            }

            if (sub_00479B90(sub_004795A0_GetNextEntry(0)) < 9 || bShowBox)
            {
                sub_0046EFD0_DrawFramedBox(pRecord->pIcons[i].nX + gnGlobal_007A2858, pRecord->pIcons[i].nY - gnGlobal_007A285C - 19, 20, 20, gnBoxColor_007BF034 = D2Win_10034_MixRGB(255, 0, 0), 1);
            }
        }
    }
}

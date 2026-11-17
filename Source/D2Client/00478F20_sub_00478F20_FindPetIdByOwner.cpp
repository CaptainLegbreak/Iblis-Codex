struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int nArg10;
    int unk0x14[2];
    int nLifePercent;
    int unk0x20[4];
    D2RosterPetStrc* pNext;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __stdcall sub_00621050(D2UnitStrc* pUnit, int nArg, int nMode);                                         // 0x00621050
struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

struct D2InvCompGridStrc
{
    D2InvRectStrc rect;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned short pad0x12;
};

void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect);       // 0x0065C180
void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId);                                                // 0x004B3230
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990

extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC
int gnUiRecordRow_007A5218;                                                                                 // 0x007A5218
int gnUiRecordRow_007BEEA8;                                                                                 // 0x007BEEA8
int gnGlobal_007BCBDC;                                                                                      // 0x007BCBDC
int gnGlobal_007BCBE0;                                                                                      // 0x007BCBE0
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern D2InventoryGridInfoStrc gGrid_007BCA30;                                                              // 0x007BCA30
D2InventoryGridInfoStrc gGrid_007BCA50;                                                                     // 0x007BCA50
D2InvRectStrc gInvRect_007BCA68;                                                                            // 0x007BCA68
extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78
D2InvRectStrc gInvRect_007BCA90;                                                                            // 0x007BCA90
extern D2InvRectStrc gInvRect_007BCAA0;                                                                     // 0x007BCAA0
D2InventoryGridInfoStrc gGrid_007BCAB0;                                                                     // 0x007BCAB0
D2InvRectStrc gInvRect_007BCAC8;                                                                            // 0x007BCAC8
D2InvRectStrc gInvRect_007BCAE0;                                                                            // 0x007BCAE0
D2InvRectStrc gInvRect_007BCAF4;                                                                            // 0x007BCAF4
D2InvRectStrc gInvRect_007BCB08;                                                                            // 0x007BCB08
extern D2InventoryGridInfoStrc gGrid_007BCB18;                                                              // 0x007BCB18
extern D2InvRectStrc gInvRect_007BCB30;                                                                     // 0x007BCB30
extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB58;                                                              // 0x007BCB58
extern D2InventoryGridInfoStrc gGrid_007BCB70;                                                              // 0x007BCB70
extern D2InventoryGridInfoStrc gGrid_007BCB88;                                                              // 0x007BCB88
D2InvRectStrc gInvRect_007BCBA0;                                                                            // 0x007BCBA0
extern D2InvRectStrc gRect_007BCBB0;                                                                        // 0x007BCBB0
extern D2InventoryGridInfoStrc gInventoryGrid_007BCBC0;                                                     // 0x007BCBC0
extern D2InvCompGridStrc gaCompGrids_007BCC58[11];                                                          // 0x007BCC58
extern D2InvCompGridStrc gaBodyLocRects_007BCD38[11];                                                       // 0x007BCD38

// 0x00478F20
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny)
{
    if (!pUnit)
        return -1;

    const int nUnitId = pUnit->dwUnitId;
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == nType && pPet->dwOwnerId == nUnitId && (bAny || !pPet->unk0x20[0]))
            return pPet->dwUnitId;
    }

    return -1;
}

// 0x004835B0
void __cdecl sub_004835B0_LoadUiRecords()
{
    if (gnUiRecordRow_007A5218 != gnUiRecordRow_007BEEA8)
    {
        gnUiRecordRow_007BEEA8 = gnUiRecordRow_007A5218;
        gnGlobal_007BCBDC = 0;
        gnGlobal_007BCBE0 = 0;
    }

    if (!gnGlobal_007BCBDC)
    {
        const int nClass = sub_00621050(sub_00463DD0(), 0, sub_0044DCC0());
        sub_0065C180_2(nClass, gnUiRecordRow_007A5218, &gInvRect_007BCAA0);
        sub_0065C1F0_2(nClass, gnUiRecordRow_007A5218, &gGrid_007BCB88);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[4], 0);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[3], 1);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[5], 2);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[1], 3);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[2], 4);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[6], 5);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[7], 6);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[8], 7);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[9], 8);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[10], 9);
        sub_0065C180_2(13, gnUiRecordRow_007A5218, &gInvRect_007BCB08);
        sub_0065C1F0_2(13, gnUiRecordRow_007A5218, &gInventoryGrid_007BCBC0);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[4], 0);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[3], 1);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[5], 2);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[1], 3);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[2], 4);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[6], 5);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[7], 6);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[8], 7);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[9], 8);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[10], 9);
        sub_0065C180_2(6, gnUiRecordRow_007A5218, &gInvRect_007BCAE0);
        sub_0065C1F0_2(6, gnUiRecordRow_007A5218, &gGrid_007BCB18);
        sub_0065C180_2(7, gnUiRecordRow_007A5218, &gInvRect_007BCA90);
        sub_0065C1F0_2(7, gnUiRecordRow_007A5218, &gGrid_007BCA30);
        sub_0065C180_2(8, gnUiRecordRow_007A5218, &gInvRect_007BCA68);
        sub_0065C1F0_2(8, gnUiRecordRow_007A5218, &gGrid_007BCB40);
        sub_0065C180_2(12, gnUiRecordRow_007A5218, &gInvRect_007BCAF4);
        sub_0065C1F0_2(12, gnUiRecordRow_007A5218, &gGrid_007BCA78);
        sub_0065C180_2(9, gnUiRecordRow_007A5218, &gInvRect_007BCB30);
        sub_0065C1F0_2(9, gnUiRecordRow_007A5218, &gGrid_007BCB70);
        sub_0065C180_2(10, gnUiRecordRow_007A5218, &gInvRect_007BCBA0);
        sub_0065C1F0_2(10, gnUiRecordRow_007A5218, &gGrid_007BCAB0);
        sub_0065C180_2(11, gnUiRecordRow_007A5218, &gInvRect_007BCAC8);
        sub_0065C1F0_2(11, gnUiRecordRow_007A5218, &gGrid_007BCA50);
        gnGlobal_007BCBDC = 1;
    }

    int nUnitId;
    if (!gnGlobal_007BCBE0 && gdwGlobal_007BCBF0 && sub_004B3230_GetSelectedUnitId(&nUnitId))
    {
        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
        if (pUnit)
        {
            const int nClass = sub_00621050(pUnit, 0, sub_0044DCC0());
            sub_0065C180_2(nClass, gnUiRecordRow_007A5218, &gRect_007BCBB0);
            sub_0065C1F0_2(nClass, gnUiRecordRow_007A5218, &gGrid_007BCB58);
            gnGlobal_007BCBE0 = 1;
        }
    }
}

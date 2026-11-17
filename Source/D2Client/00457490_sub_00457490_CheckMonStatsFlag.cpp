struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2ViewStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char unk0x04[0x08];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x198];
};

struct D2ItemStatCostTxt
{
    char unk0x000[0x144];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x148];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

struct D2PacketBufferStrc
{
    int nMax;
    int nCount;
    int unk0x08;
    unsigned char* pData;
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormExplicitListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void UnlinkAll();
};

struct D2MsgFilterStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pUnit04;
    D2UnitStrc* pUnit08;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void __cdecl sub_00457520_UpdateAutomapLayout();                                                            // 0x00457520
void __cdecl sub_00459700();                                                                                // 0x00459700
void __cdecl sub_00459E90();                                                                                // 0x00459E90
void __cdecl sub_00459FF0();                                                                                // 0x00459FF0
void __cdecl sub_0045A050();                                                                                // 0x0045A050
void __cdecl sub_0045A0A0();                                                                                // 0x0045A0A0
void __cdecl sub_0045A120();                                                                                // 0x0045A120
void __cdecl sub_0045A190();                                                                                // 0x0045A190
void __cdecl sub_0045AC90();                                                                                // 0x0045AC90
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(void* pArg);                                    // 0x00464770
void __fastcall sub_004647A0_SetPacketBuffer(void* pArg, D2PacketBufferStrc* pBuffer);                      // 0x004647A0
void __fastcall sub_00476000_SetViewRect(D2ViewStrc* pView, int nLeft, int nTop, int nRight, int nBottom);   // 0x00476000
void __fastcall sub_004F52A0_SetOffset(int nOffset);                                                        // 0x004F52A0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnAutomapTextY_007A51BC;                                                                         // 0x007A51BC
extern int gdwGlobal_007A5208;                                                                              // 0x007A5208
extern int gdwGlobal_007A520C;                                                                              // 0x007A520C
extern int gdwGlobal_007A5210;                                                                              // 0x007A5210
int gnGlobal_007A5214;                                                                                      // 0x007A5214
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
int gdwGlobal_007A5238;                                                                                     // 0x007A5238
extern int gdwGlobal_007A5264;                                                                              // 0x007A5264
int gnGlobal_007A526C;                                                                                      // 0x007A526C

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x00457490
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x0045AD60
void __cdecl sub_0045AD60()
{
    if (!gpGlobal_007A0634)
    {
        return;
    }
    if (!sub_00463DE0_GetStoredUnit())
    {
        return;
    }
    if (!UNITS_GetRoom(sub_00463DE0_GetStoredUnit()))
    {
        return;
    }
    sub_00457520_UpdateAutomapLayout();
    sub_00459700();
    sub_0045AC90();
    gnAutomapTextY_007A51BC = 0x18;
    const int nAct = sub_0044DB30();
    const int nPrevious = sub_00502EF0(1);
    sub_00459E90();
    sub_0045A050();
    sub_0045A0A0();
    sub_0045A190();
    if (nAct == 6 || nAct == 8)
    {
        sub_0045A120();
    }
    if (sub_0044DCC0())
    {
        sub_00459FF0();
    }
    sub_00502EF0(nPrevious);
}

// 0x0045ADF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0045AE20
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0045AEA0
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode)
{
    switch (nMode)
    {
    case 0:
    case 3:
        gnGlobal_007A5214 = 0;
        break;
    case 1:
        gnGlobal_007A5214 = -(gnGlobal_0071146C / 4);
        break;
    case 2:
        gnGlobal_007A5214 = gnGlobal_0071146C / 4;
        break;
    }
    gdwGlobal_007A5210 = nMode;
    sub_004F52A0_SetOffset(gnGlobal_007A5214);
    const int nWidth = gnAutomapWidth_007A5220;
    const int nQuarter = nWidth / 4;
    switch (nMode)
    {
    case 0:
        sub_00476000_SetViewRect(gpView_007A0640, 0, 0, nWidth, gnAutomapHeight_007A521C);
        break;
    case 1:
        sub_00476000_SetViewRect(gpView_007A0640, -nQuarter, 0, nWidth - nQuarter, gnAutomapHeight_007A521C);
        break;
    case 2:
        sub_00476000_SetViewRect(gpView_007A0640, nQuarter, 0, nWidth + nQuarter, gnAutomapHeight_007A521C);
        break;
    case 3:
        sub_00476000_SetViewRect(gpView_007A0640, 0, 0, nWidth, gnAutomapHeight_007A521C);
        sub_0044DA70();
        break;
    }
}

// 0x0045AFC0
extern "C" int __cdecl sub_0045AFC0()
{
    return gdwGlobal_007A520C - gnGlobal_007A5214;
}

// 0x0045AFD0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset()
{
    return gdwGlobal_007A5208 - 8;
}

// 0x0045BD00
void D2StormExplicitListStrc::UnlinkAll()
{
    for (;;)
    {
        char* pNode = Head();
        if (!pNode)
        {
            break;
        }
        ((D2StormLinkStrc*)pNode)->Unlink();
    }
}

// 0x0045C460
int __fastcall DATATBLS_GetMonStatsTxtRecordCount()
{
    return sgptDataTables->nMonStatsTxtRecordCount;
}

// 0x0045C4F0
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0045F9F0
void __fastcall sub_0045F9F0_FreePacketBuffer(void* pArg)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pArg);
    if (pBuffer)
    {
        FOG_Free(pBuffer->pData, ".\\GAME\\SCmd.cpp", 0x1516, 0);
        FOG_Free(pBuffer, ".\\GAME\\SCmd.cpp", 0x1517, 0);
        sub_004647A0_SetPacketBuffer(pArg, 0);
    }
}

// 0x00460480
void __fastcall sub_00460480(int bExpansion)
{
    gdwGlobal_007A5238 = bExpansion;
}

// 0x00462920
void __cdecl sub_00462920_ClearValue()
{
    gdwGlobal_007A5264 = 0;
}

// 0x00462930
int __fastcall sub_00462930_FilterMessage(D2MsgFilterStrc* pMsg)
{
    const unsigned int dwFlags = pMsg->dwFlags;
    if (dwFlags & 0x10)
    {
        gnGlobal_007A526C = 0;
        return 0;
    }
    if (dwFlags & 4)
    {
        gnGlobal_007A526C = (pMsg->pUnit08 != 0) + 1;
        return 1;
    }
    if (dwFlags & 8)
    {
        if (!gnGlobal_007A526C)
        {
            return 0;
        }
        if (pMsg->pUnit08)
        {
            const int nType = pMsg->pUnit08->dwUnitType;
            if (nType < 0)
            {
                return 0;
            }
            if (nType > 1 && nType != 5)
            {
                return 0;
            }
            if (pMsg->pUnit04)
            {
                const int nMode = pMsg->pUnit04->dwAnimMode;
                if (nMode == 2 || nMode == 3 || nMode == 6)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// 0x00463830
int __fastcall sub_00463830_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}

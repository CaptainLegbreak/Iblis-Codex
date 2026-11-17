extern "C" const char szDiabloGateways_006DEC8C[];                                                          // 0x006DEC8C
extern "C" const char szOverrideGateways_006DECAC[];                                                        // 0x006DECAC

class BNGatewayAccess
{
private:
    void GetGatewayList(const char* szValueName);                                                           // 0x00518190
    void sub_00518270_LoadGatewayList();

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
    char* m_pGatewayList;
    int m_nGatewayListSize;
    unsigned int m_nDefaultGateway;
    int m_bOverride;
    void* m_pRealms;
};

// 0x00518270
void BNGatewayAccess::sub_00518270_LoadGatewayList()
{
    m_bOverride = 0;
    GetGatewayList(szOverrideGateways_006DECAC);
    if (m_pGatewayList)
    {
        m_bOverride = 1;
        return;
    }
    GetGatewayList(szDiabloGateways_006DEC8C);
}

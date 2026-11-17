struct D2UnitStrc;
struct D2DataTablesStrc
{
    unsigned char unk_000[0xC4];
    int nStatesTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit); // 0x00625BE0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

// 0x00639E30
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    if (pGfxFlags && nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (bSet)
        {
            pGfxFlags[nState >> 5] |= gdwBitMasks[nState & 31];
        }
        else
        {
            pGfxFlags[nState >> 5] &= gdwInvBitMasks[nState & 31];
        }
        UNITROOM_RefreshUnit(pUnit);
    }
}

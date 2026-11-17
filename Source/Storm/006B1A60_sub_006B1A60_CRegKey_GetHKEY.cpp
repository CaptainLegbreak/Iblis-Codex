struct CRegKeyView
{
    void* m_hKey;
};

// 0x006B1A60
void* __fastcall sub_006B1A60_CRegKey_GetHKEY(const CRegKeyView* pKey)
{
    return pKey->m_hKey;
}

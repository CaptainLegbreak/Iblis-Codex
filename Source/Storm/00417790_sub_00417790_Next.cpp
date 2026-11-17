struct D2SFileStormLinkM114Strc
{
    D2SFileStormLinkM114Strc* m_prevlink;
    char* m_next;

    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    char* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
    char* sub_00417790_Next();
    char* sub_004178A0_Next();
    char* sub_004179A0_Next();
};

// 0x00417790
char* D2SFileStormLinkM114Strc::sub_00417790_Next()
{
    return MaskNext();
}

// 0x004178A0
char* D2SFileStormLinkM114Strc::sub_004178A0_Next()
{
    return MaskNext();
}

// 0x004179A0
char* D2SFileStormLinkM114Strc::sub_004179A0_Next()
{
    return MaskNext();
}

struct D2SFileNodeM114Strc
{
    char unk0x00[0x24];
    int nKey;
};

struct D2SFileStormListM114Strc
{
    D2SFileStormLinkM114Strc m_terminator;

    D2SFileNodeM114Strc* Head()
    {
        return (D2SFileNodeM114Strc*)m_terminator.Next();
    }
};

struct D2SFileOwnerM114Strc
{
    D2SFileStormListM114Strc* pList;
};

struct D2SFileArchiveM114Strc
{
    D2SFileOwnerM114Strc* pOwner;
    char unk0x04[0x20];
    int nKey;
};

// 0x00417EE0
static __forceinline int sub_00417EE0_IsNotListHead(D2SFileArchiveM114Strc* pArchive)
{
    if (pArchive->nKey && pArchive->pOwner->pList->Head() && pArchive->nKey == pArchive->pOwner->pList->Head()->nKey)
    {
        return 0;
    }
    return 1;
}

int __stdcall sub_M114_Emit_00417EE0(D2SFileArchiveM114Strc* pArchive)
{
    return sub_00417EE0_IsNotListHead(pArchive) + 5;
}

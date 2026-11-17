extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct D2CompositeUnitStrc;

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    unsigned short wFlags1EF;
    char unk0x1F1[0x1D1];
    char nValue3C2;
};
#pragma pack(pop)

union D2ChannelFlagsStrc
{
    unsigned int dwFlags;
    unsigned char nFlags;
    struct
    {
        unsigned int bFlag01 : 1;
        unsigned int bFlag02 : 1;
        unsigned int bFlag04 : 1;
        unsigned int bFlag08 : 1;
        unsigned int bFlag10 : 1;
        unsigned int bFlag20 : 1;
    };
};

struct D2ChatChannelMemberStrc
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x3];
    union
    {
        unsigned short wFlags8A;
        struct
        {
            unsigned short nLow8A : 5;
            unsigned short bExp8A : 1;
            unsigned short nMid8A : 2;
            unsigned short nLevel8A : 5;
        };
    };
    char unk0x8C[0x4];
    D2ChannelFlagsStrc tFlags90;
    char nValue94;
    char unk0x95[0x7];
    D2CompositeUnitStrc* pComposite;
    int nValue0xA0;
    int unk0xA4;
    int nValue0xA8;
    int unk0xAC;
    D2ChatChannelMemberStrc* pNext;
};

void __stdcall D2Win_10152(D2CompositeUnitStrc* pCompositeUnit, int nY);                                    // 0x005052B0
void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, unsigned int nFlags);                       // 0x00505360

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern unsigned int gdwInvBitMasks[];                                                                       // 0x006CE2E8
extern D2LaunchCharInfoStrc* volatile gpCharInfo_0077BBD8;                                                          // 0x0077BBD8
extern D2ChatChannelMemberStrc* gpChannelUsers_00798F34;                                                          // 0x00798F34
extern int gnChannelScroll_00798F44;                                                                        // 0x00798F44
extern D2ChatChannelMemberStrc* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48

#define CHAN_SETBIT(x, n, cond) if (cond) x |= gdwBitMasks[n]; else x &= gdwInvBitMasks[n]

static inline int CHAN_GetRank(const D2ChannelFlagsStrc* pFlags)
{
    const D2ChannelFlagsStrc tFlags = *pFlags;
    if (tFlags.dwFlags & 2)
        return 4;
    if (tFlags.dwFlags & 8)
        return 3;
    if (tFlags.dwFlags & 1)
        return 2;
    if (tFlags.nFlags & 4)
        return 1;
    return 0;
}

static inline int CHAN_GetLevelClass(D2ChatChannelMemberStrc* pUser)
{
    const int nLevel = pUser->nLevel8A;
    if (pUser->bExp8A)
    {
        if (nLevel >= 15)
            return 3;
        if (nLevel >= 10)
            return 2;
        return nLevel >= 5;
    }
    if (nLevel >= 12)
        return 3;
    if (nLevel >= 8)
        return 2;
    return nLevel >= 4;
}

// 0x00447BB0
void __cdecl sub_00447BB0_Refresh()
{
    int n;
    if (gpChannelUsers_00798F34)
    {
        D2ChatChannelMemberStrc* pSorted = gpChannelUsers_00798F34;
        D2ChatChannelMemberStrc** ppNext = &gpChannelUsers_00798F34->pNext;
        D2ChatChannelMemberStrc* pList = *ppNext;
        _ReadWriteBarrier();
        *ppNext = 0;
        while (pList)
        {
            n = CHAN_GetRank(&pList->tFlags90);
            D2ChatChannelMemberStrc* pPrev = 0;
            int bInserted = 0;
            D2ChatChannelMemberStrc* pCur = pSorted;
            while (pCur && !bInserted)
            {
                if (n > CHAN_GetRank(&pCur->tFlags90))
                {
                    D2ChatChannelMemberStrc* pInsert = pList;
                    pList = pInsert->pNext;
                    pInsert->pNext = pCur;
                    if (pPrev)
                    {
                        pPrev->pNext = pInsert;
                        bInserted = 1;
                    }
                    else
                    {
                        pSorted = pInsert;
                        bInserted = 1;
                    }
                }
                else
                {
                    pPrev = pCur;
                    pCur = pCur->pNext;
                }
            }

            if (!bInserted)
            {
                pPrev->pNext = pList;
                D2ChatChannelMemberStrc* pLast = pList;
                pList = pLast->pNext;
                pLast->pNext = 0;
            }
        }
        gpChannelUsers_00798F34 = pSorted;
    }

    D2ChatChannelMemberStrc* pUser = gpChannelUsers_00798F34;
    int nY = 0x46;
    n = 0;
    if (gpChannelUsers_00798F34)
    do
    {
        unsigned int nState;
        D2ChannelFlagsStrc tFlags;
        if (n >= gnChannelScroll_00798F44 && n < gnChannelScroll_00798F44 + 11)
        {
            D2Win_10152(pUser->pComposite, nY);
            nState = 0xF;
            CHAN_SETBIT(nState, 11, pUser->tFlags90.dwFlags & 9);
            const unsigned short wFlags = pUser->wFlags8A;
            CHAN_SETBIT(nState, 4, wFlags & 8);
            CHAN_SETBIT(nState, 5, wFlags & 4);
            CHAN_SETBIT(nState, 12, wFlags & 0x20);
            const int nLevelClass = CHAN_GetLevelClass(pUser);
            CHAN_SETBIT(nState, 6, nLevelClass & 1);
            CHAN_SETBIT(nState, 7, nLevelClass & 2);
            if (n & 1)
                nState |= gdwBitMasks[8];
            CHAN_SETBIT(nState, 9, pUser->tFlags90.nFlags & 0x20);
            CHAN_SETBIT(nState, 10, pUser == gpSelectedChannelUser_00798F48);
            nY += 0x3C;
        }
        else
        {
            tFlags = pUser->tFlags90;
            nState = 0;
            CHAN_SETBIT(nState, 11, tFlags.dwFlags & 9);
            const unsigned short wFlags = pUser->wFlags8A;
            CHAN_SETBIT(nState, 4, wFlags & 8);
            CHAN_SETBIT(nState, 5, wFlags & 4);
            CHAN_SETBIT(nState, 12, wFlags & 0x20);
            const D2LaunchCharInfoStrc* pCharInfo = gpCharInfo_0077BBD8;
            int bDiffers = pCharInfo->nValue3C2 != pUser->nValue94;
            const unsigned short wCharFlags = pCharInfo->wFlags1EF;
            bDiffers |= (wCharFlags & 4) && !pUser->nValue0xA0;
            bDiffers |= !(wCharFlags & 4) && pUser->nValue0xA0;
            bDiffers |= (wCharFlags & 0x20) && !pUser->nValue0xA8;
            bDiffers |= !(wCharFlags & 0x20) && pUser->nValue0xA8;
            CHAN_SETBIT(nState, 13, bDiffers);
            const int nLevelClass = CHAN_GetLevelClass(pUser);
            CHAN_SETBIT(nState, 6, nLevelClass & 1);
            CHAN_SETBIT(nState, 7, nLevelClass & 2);
            CHAN_SETBIT(nState, 9, tFlags.dwFlags & 0x20);
            CHAN_SETBIT(nState, 10, pUser == gpSelectedChannelUser_00798F48);
        }
        D2Win_10156(pUser->pComposite, nState);
        n++;
        pUser = pUser->pNext;
    } while (pUser);
}

#include "gen/data/Source/D2Multi/Src/ComCallback_00447BB0.inc"

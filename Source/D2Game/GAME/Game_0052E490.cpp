#include "D2Game.h"

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;

    D2GameLinkStrc* InlineNextLink(int nLinkOffset)
    {
        if ((int)pNext < 0)
            return (D2GameLinkStrc*)~(unsigned int)pNext;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - (char*)pPrevLink->pNext;
        return (D2GameLinkStrc*)((char*)pNext + nLinkOffset);
    }

    void InlineUnlink()
    {
        if (pPrevLink)
        {
            InlineNextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }

    D2GameStrc* InlineNext()
    {
        return (int)pNext <= 0 ? 0 : pNext;
    }
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;

    ~D2GameStrc();                                                                                          // 0x0044F820
};

struct D2GameListStrc
{
    int nLinkOffset;
    D2GameLinkStrc tTerminator;

    D2GameLinkStrc* InlineLink(D2GameStrc* pGame)
    {
        return pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    }

    D2GameStrc* InlineNext(D2GameStrc* pGame)
    {
        return InlineLink(pGame)->InlineNext();
    }

    D2GameStrc* DeleteNode(D2GameStrc* pGame);
};

struct D2GameDataTableStrc
{
    virtual void InternalDelete(D2GameStrc* pGame);

    void Unlink(D2GameStrc* pGame);
};

extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650

// 0x0052E490
void D2GameDataTableStrc::Unlink(D2GameStrc* pGame)
{
    if (pGame->tLinkToSlot.pNext)
    {
        pGame->tLinkToSlot.InlineUnlink();
        pGame->tLinkToFull.InlineUnlink();
    }
}

// 0x0052E600
D2GameStrc* D2GameListStrc::DeleteNode(D2GameStrc* pGame)
{
    D2GameStrc* pNext = InlineNext(pGame);
    pGame->~D2GameStrc();
    SMemFree(pGame, gszSGameDataTypeName, -2, 0);
    return pNext;
}

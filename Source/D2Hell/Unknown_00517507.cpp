struct D2StormLinkStrc;
struct D2StormListStrc;
struct D2PositiveCountStrc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    unsigned int nNextLink;
};

struct D2StormListStrc
{
    int nLinkOffset;
    D2StormLinkStrc tTerminator;
};

struct D2PositiveCountStrc {
    int unknown00;
    int unknown04;
    int count;
};


// 0x00517507
void __fastcall sub_00517507_InitList(D2StormListStrc* pList)
{
    D2StormLinkStrc* pTerminator = &pList->tTerminator;
    pTerminator->pPrevLink = pTerminator;
    pList->tTerminator.nNextLink = ~(unsigned int)pTerminator;
}

// 0x00517512
unsigned int __fastcall sub_00517512_Add(unsigned int first, unsigned int second)
{
    return first + second;
}

// 0x00517516
int __fastcall sub_00517516_GetPositiveCount(D2PositiveCountStrc* data)
{
    int value = data->count;
    if (value <= 0) value = 0;
    return value;
}

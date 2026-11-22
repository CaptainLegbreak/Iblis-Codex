#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"

struct D2HintRecordStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;
struct D2ValueNodeStrc;
struct D2ValueLinkStrc;

struct D2HintRecordStrc
{
    int unk0x00;
    int nValue;
};

struct D2TimedHintEntryStrc
{
    int bUsed;
    int nHintId;
    int nKey;
    char unk0x0C[0x10];
    int nValue1C;
    char unk0x20[0x08];
    union
    {
        D2HintRecordStrc* pRecord;
        void* pKeyList;
    };
    void* f_2C;
    int nState;
    unsigned int dwTick;
};

extern D2TimedHintNodeStrc* gpTimedHintList_007C5458; // 0x007C5458

struct D2ValueNodeStrc
{
    char unk0x00[8];
    int nKey;
    char unk0x0C[0x10];
    int nValue;
};

struct D2ValueLinkStrc
{
    D2ValueNodeStrc* pValue;
    D2ValueLinkStrc* pNext;
};

extern D2ValueLinkStrc* gpValueList_007C5458; // 0x007C5458


// 0x004B9610
void* __fastcall sub_004B9610(int nHintId)
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nHintId == nHintId)
        {
            return (void*)pEntry->nKey;
        }
    }
    return 0;
}

// 0x004B9B20
int __fastcall sub_004B9B20(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nValue1C;
            }
        }
    }
    return 0;
}

// 0x004B9B50
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue)
{
    if (!nKey)
        return;
    D2ValueLinkStrc* pLink = gpValueList_007C5458;
    if (!pLink)
        return;
    do
    {
        D2ValueNodeStrc* pValue = pLink->pValue;
        if (pValue->nKey == nKey)
        {
            pValue->nValue = nValue;
            return;
        }
        pLink = pLink->pNext;
    } while (pLink);
}


// 0x004B9C20
int __cdecl sub_004B9C20_IsSpeechPlaying()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nState != 2 && pEntry->nHintId >= 0xB76 && pEntry->nHintId <= 0x1230)
        {
            return 1;
        }
    }
    return 0;
}


// 0x004B9C60
int __cdecl sub_004B9C60_IsSongPlaying()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nState != 2 && pEntry->nHintId >= 0x1231 && pEntry->nHintId <= 0x125A)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9CA0
int __fastcall sub_004B9CA0_GetHintIdByKey(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nHintId;
            }
        }
    }
    return 0;
}


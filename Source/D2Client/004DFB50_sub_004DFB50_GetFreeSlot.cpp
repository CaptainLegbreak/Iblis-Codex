struct D2SoundStrc;

#pragma pack(push, 1)
struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int f_4;
    char unk0x08[0x1C];
    int nField0x24;
    char unk0x28[0x04];
    int nField0x2C;
    int nField0x30;
    unsigned int nKey;
    unsigned char nFlags;
    char unk0x39[0x03];
    unsigned char nPriority;
    int nField0x3D;
    unsigned int f_41;
};

struct D2SoundRecordStrc
{
    char unk0x00[0x3E];
    unsigned char nField0x3E;
    char unk0x3F[0x0C];
    unsigned char nField0x4B;
    char unk0x4C;
    unsigned char nField0x4D;
    char unk0x4E;
    unsigned char bStream;
    unsigned char nField0x50;
    char unk0x51[0x03];
    int nField0x54;
    char unk0x58[0x0C];
    int nField0x64;
    int nField0x68;
    int nField0x6C;
    int nField0x70;
    char f_74[0x0C];
    unsigned char nField0x80;
    unsigned char nField0x81;
    char unk0x82[0x04];
    int nState;
};
#pragma pack(pop)

struct D2SlotStrc
{
    D2SoundStrc* f_0;
    int nType;
    D2SlotObjectStrc* pObject;
    int nField0x0C;
    int nField0x10;
    int nField0x14;
    int nField0x18;
    float fField0x1C;
};

extern D2SlotStrc gaSlots_007C8A78[16];                                                                     // 0x007C8A78
int __fastcall sub_004B9DA0_CompareItems(D2SlotObjectStrc* pA, D2SlotObjectStrc* pB, int bCompareFloat, int bCompareValue); // 0x004B9DA0
D2SoundRecordStrc* __fastcall sub_00481860(int nId);                                                        // 0x00481860
int __fastcall sub_00482680(int nId);                                                                       // 0x00482680
void __fastcall sub_00482710(int nIndex, char* szPath);                                                     // 0x00482710
void __fastcall sub_00482970(int nId, int bFlag, int nArg);                                                 // 0x00482970
D2SlotStrc* __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                               // 0x004DF9D0
void __fastcall sub_004DFC20(D2SlotStrc* pSlot);                                                            // 0x004DFC20
int __fastcall sub_00514C90_GetSoundMode();                                                                 // 0x00514C90
int __fastcall sub_005155D0(D2SoundStrc* pSound, int nA, int nB);                                           // 0x005155D0
int __fastcall sub_005156A0(D2SoundStrc* pSound);                                                           // 0x005156A0
int __fastcall sub_00515710(D2SoundStrc* pSound);                                                           // 0x00515710
unsigned int __fastcall sub_005159B0_GetSoundSampleCount(D2SoundStrc* pSound);                              // 0x005159B0
void __fastcall sub_00515A30(D2SoundStrc* pSound, int nValue);                                              // 0x00515A30
void __fastcall sub_00515A60(D2SoundStrc* pSound, int nValue);                                              // 0x00515A60
void __fastcall sub_00515B40(D2SoundStrc* pSound, float fValue);                                            // 0x00515B40
int __fastcall sub_00515D70(D2SoundStrc* pSound, char* szPath, int nA, int nB);                             // 0x00515D70
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0
void __fastcall sub_00516140(D2SoundStrc* pSound);                                                          // 0x00516140

// 0x004DFB50
static D2SlotStrc* __stdcall sub_004DFB50_GetFreeSlot(D2SlotObjectStrc* pObject, int nType)
{
    for (int i = 0; i < 16; ++i)
    {
        D2SlotStrc* pSlot = &gaSlots_007C8A78[i];
        if (!pSlot->pObject && pSlot->nType == nType && !sub_00515710(pSlot->f_0))
            return pSlot;
    }
    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; ++i)
    {
        if (gaSlots_007C8A78[i].nType == nType && gaSlots_007C8A78[i].pObject)
        {
            if (!pBest || sub_004B9DA0_CompareItems(pBest->pObject, gaSlots_007C8A78[i].pObject, 1, 1))
                pBest = &gaSlots_007C8A78[i];
        }
    }
    if (!pBest || !sub_004B9DA0_CompareItems(pObject, pBest->pObject, 0, 0))
        return 0;
    if (pBest->f_0)
    {
        if (pBest->pObject)
            pBest->pObject->f_41 = sub_005159B0_GetSoundSampleCount(pBest->f_0);
        sub_00515EE0_StopSound(pBest->f_0);
    }
    if (pBest->pObject)
    {
        pBest->pObject->nField0x30 = 2;
        pBest->pObject->nField0x2C = 0;
        pBest->pObject = 0;
    }
    return pBest;
}

D2SlotStrc* __fastcall sub_004E01B0_PlaySlotSound(D2SlotObjectStrc* pObject)
{
    D2SoundRecordStrc* pFirst = sub_00481860(pObject->f_4);
    if (!(pObject->nFlags & 1))
        pObject->f_4 = sub_00482680(pObject->f_4);
    D2SlotStrc* pOld = sub_004DF9D0_CheckCacheEntry(pObject->f_4);
    if (pOld && !pOld->pObject->nField0x3D && pObject->nKey - pOld->pObject->nKey < 2 && pOld->pObject->nPriority >= pObject->nPriority)
        return 0;
    D2SoundRecordStrc* pRecord = sub_00481860(pObject->f_4);
    pFirst->nField0x68 = pFirst->nField0x64;
    pFirst->nField0x64 = pObject->f_4;
    if (!pRecord->bStream && pRecord->nState != 2)
    {
        sub_00482970(pObject->f_4, pRecord->nField0x4D == 0, 0);
        if (pRecord->nState != 2)
            return 0;
    }
    if (pRecord->nField0x81)
        return 0;
    int nType = 0;
    if (pRecord->nField0x50)
        nType = 1;
    if (!(nType & 1))
    {
        if (sub_00514C90_GetSoundMode() == 1)
            nType |= 2;
        if (sub_00514C90_GetSoundMode() == 2)
            nType |= 6;
    }
    D2SlotStrc* pSlot = sub_004DFB50_GetFreeSlot(pObject, nType);
    if (!pSlot)
        return 0;
    sub_00516140(pSlot->f_0);
    if (!pRecord->bStream)
    {
        sub_00515A30(pSlot->f_0, pRecord->nField0x3E);
        if (pRecord->nField0x80 == 1)
            sub_00515A60(pSlot->f_0, pRecord->nField0x54 * 2);
        if (!sub_005155D0(pSlot->f_0, pRecord->nField0x6C, pRecord->nField0x70))
            return 0;
    }
    pSlot->pObject = pObject;
    if (nType & 4)
    {
        float fValue = pRecord->nField0x4B ? 1.0f : 0.0f;
        sub_00515B40(pSlot->f_0, fValue);
    }
    pSlot->fField0x1C = 0.0f;
    pSlot->nField0x18 = -1;
    pSlot->nField0x0C = 0;
    pSlot->nField0x10 = 0;
    pSlot->nField0x14 = 0;
    sub_004DFC20(pSlot);
    int bOk;
    if (!pRecord->bStream)
    {
        bOk = sub_005156A0(pSlot->f_0);
    }
    else
    {
        char szPath[0x50];
        sub_00482710(pObject->f_4, szPath);
        bOk = sub_00515D70(pSlot->f_0, szPath, pObject->nField0x24, pRecord->nField0x3E);
    }
    if (!bOk)
    {
        pSlot->pObject = 0;
        return 0;
    }
    return pSlot;
}

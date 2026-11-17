#pragma pack(push, 1)
struct D2Packed004B9BC0Strc
{
    char unk0x00[0x45];
    int nOn;
    char unk0x49[0x04];
    int nHeld;
};
#pragma pack(pop)

struct D2Entry004B9CD0Strc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x30];
    unsigned char nValue;
};

struct D2EntryNode004B9CD0Strc
{
    D2Entry004B9CD0Strc* f_0;
    D2EntryNode004B9CD0Strc* pNext;
};

unsigned int __cdecl sub_00481820();                                                                        // 0x00481820
int __fastcall sub_004E4100(int nMin, int nMax);                                                            // 0x004E4100
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
extern D2EntryNode004B9CD0Strc* gpEntryNodes_007C5458;                                                      // 0x007C5458

// 0x004B9BC0
static __forceinline int sub_004B9BC0_IsOnAndNotHeld(D2Packed004B9BC0Strc* pRecord)
{
    return pRecord->nOn && !pRecord->nHeld;
}

// 0x004B9CD0
void __fastcall sub_004B9CD0_SetEntryByte(int nId, unsigned char nValue)
{
    if (!nId)
    {
        return;
    }
    for (D2EntryNode004B9CD0Strc* pNode = gpEntryNodes_007C5458; pNode; pNode = pNode->pNext)
    {
        D2Entry004B9CD0Strc* pEntry = pNode->f_0;
        if (pEntry->nId == nId)
        {
            pEntry->nValue = nValue;
            return;
        }
    }
}

// 0x004B9EB0
void __cdecl sub_004B9EB0_PlayRandomSound()
{
    if (sub_00481820() % 3 == 0)
    {
        const int nSound = sub_004E4100(0xB76, 0x1230);
        sub_004B9A00(nSound, 0, 0, 0, 0);
    }
}

int __fastcall sub_M119_Emit_004B9BC0(D2Packed004B9BC0Strc* pRecord)
{
    return sub_004B9BC0_IsOnAndNotHeld(pRecord);
}

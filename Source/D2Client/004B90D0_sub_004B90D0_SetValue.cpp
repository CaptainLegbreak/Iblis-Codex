struct D2UnitStrc;
struct D2ClientSoundStrc;

struct D2SoundNodeStrc
{
    D2ClientSoundStrc* f_0;
    D2SoundNodeStrc* pNext;
};

struct D2SoundUnitNodeStrc
{
    D2UnitStrc* pUnit;
    D2SoundUnitNodeStrc* pNext;
};

struct D2SoundVecStrc
{
    float fX;
    float fY;
    float fZ;
};

struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    char unk0x1C[0x0C];
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
};

#pragma pack(push, 1)
struct D2SoundStream4B9BB0Strc
{
    char unk0x00[0x45];
    int nValue;
};
#pragma pack(pop)

struct D2GSPacketText5EStrc
{
    unsigned char aText[37];
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    D2GSPacketText5EStrc tText;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern unsigned long gdwGlobal_007C0E68;                                                                    // 0x007C0E68
unsigned long gdwGlobal_007C0E78;                                                                           // 0x007C0E78
D2GSPacketText5EStrc gtTable_007C0EA4;                                                                      // 0x007C0EA4
int gdwTableInit_007C0ECC;                                                                                  // 0x007C0ECC
extern D2SoundNodeStrc* gpSoundList_007C5458;                                                               // 0x007C5458

void __fastcall sub_0046B630_SetBit(int nIndex);                                                            // 0x0046B630
void __fastcall sub_004CA8D0_NotifyUnitHint(D2UnitStrc* pUnit, int nHandle);                                // 0x004CA8D0
void __fastcall sub_004DF7B0(void* pStream);                                                                // 0x004DF7B0
void __fastcall sub_00516A10_FreeList(D2SoundUnitNodeStrc** ppList);                                        // 0x00516A10

// 0x004B90D0
void __fastcall sub_004B90D0_SetValue(unsigned long nValue, bool bFirst)
{
    if (bFirst)
    {
        gdwGlobal_007C0E68 = nValue;
    }
    else
    {
        gdwGlobal_007C0E78 = nValue;
    }
}

// 0x004B9200
void __cdecl sub_004B9200_ResetTable()
{
    gdwTableInit_007C0ECC = 0;
}

// 0x004B92B0
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket)
{
    gtTable_007C0EA4 = pPacket->tText;
    gdwTableInit_007C0ECC = 1;
}

// 0x004B92D0
int __stdcall sub_004B92D0_IsTableReady(int nUnused)
{
    return gdwTableInit_007C0ECC;
}

// 0x004B9330
void __fastcall sub_004B9330_ForwardByte(const unsigned char* pPacket)
{
    sub_0046B630_SetBit(pPacket[1]);
}

// 0x004B9440
D2ClientSoundStrc* __fastcall sub_004B9440_FindSoundByHandle(int nHandle)
{
    if (nHandle)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pSound = pNode->f_0;
            if (pSound->f_8 == nHandle)
            {
                return pSound;
            }
        }
    }
    return 0;
}

// 0x004B9470
static __forceinline void sub_004B9470_ReleaseUnits(D2ClientSoundStrc* pSound)
{
    for (D2SoundUnitNodeStrc* pNode = pSound->pUnitList; pNode; pNode = pNode->pNext)
    {
        sub_004CA8D0_NotifyUnitHint(pNode->pUnit, pSound->f_8);
    }
    sub_00516A10_FreeList(&pSound->pUnitList);
}

// 0x004B94A0
static __forceinline void sub_004B94A0_StopStream(D2ClientSoundStrc* pSound)
{
    if (pSound->nType == 1)
    {
        sub_004DF7B0(pSound->pStream);
    }
    D2_ASSERT(!pSound->pStream, 0x93);
}

void __fastcall sub_M112_Emit_004B9470(D2ClientSoundStrc* pSound)
{
    sub_004B9470_ReleaseUnits(pSound);
}

void __fastcall sub_M112_Emit_004B94A0(D2ClientSoundStrc* pSound)
{
    sub_004B94A0_StopStream(pSound);
}

// 0x004B9560
int __fastcall sub_004B9560_HasSoundHandle(int nHandle)
{
    return sub_004B9440_FindSoundByHandle(nHandle) != 0;
}

// 0x004B9BB0
static __forceinline int sub_004B9BB0_GetStreamValue(D2SoundStream4B9BB0Strc* pStream)
{
    return pStream->nValue;
}

int __fastcall sub_M112_Emit_004B9BB0(D2SoundStream4B9BB0Strc* pStream)
{
    return sub_004B9BB0_GetStreamValue(pStream);
}

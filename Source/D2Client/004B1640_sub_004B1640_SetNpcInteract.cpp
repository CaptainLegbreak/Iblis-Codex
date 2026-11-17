struct D2BitBufferStrc;

struct D2NpcRecordStrc
{
    int unk0x00;
    int nValue04;
    int unk0x08;
    int nValue0C;
};

struct D2NpcQuestHandlerStrc
{
    int nNpcId;
    int nQuestId;
    int nState;
    int bSet;
    int (__cdecl* pfHandler)();
};

#pragma pack(push, 1)
struct D2NpcIndexStrc
{
    int nId;
    char unk0x04[0x23];
};
#pragma pack(pop)

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gdwGlobal_007C0D2D;                                                                              // 0x007C0D2D
extern D2BitBufferStrc* gpQuestFlags_007C0D43;                                                              // 0x007C0D43
extern int gnHandlerCount_007253DC;                                                                         // 0x007253DC
extern D2NpcQuestHandlerStrc gaNpcHandlers_007253E0[];                                                      // 0x007253E0
extern int gnNpcIndexCount_00725A74;                                                                        // 0x00725A74
extern D2NpcIndexStrc gaNpcIndex_00726C48[];                                                                // 0x00726C48

// 0x004B1640
static __declspec(noinline) void sub_004B1640_SetNpcInteract(D2NpcRecordStrc* pRecord)
{
    if (pRecord)
    {
        gnGlobal_007C0D29 = 1;
        gnGlobal_007C0D25 = pRecord->nValue0C;
        gdwGlobal_007C0D2D = pRecord->nValue04;
    }
    else
    {
        gnGlobal_007C0D29 = 0;
    }
}

// 0x004B19A0
static int __stdcall sub_004B19A0_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount)
{
    int nResult = 1;
    for (int i = 0; i < nCount; ++i)
    {
        if (pTable[i].nNpcId == nNpcId)
        {
            if (pTable[i].bSet)
            {
                if (QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
            else
            {
                if (!QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
        }
    }
    return nResult;
}

// 0x004B1A10
static __declspec(noinline) bool sub_004B1A10_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

// 0x004B2E30
static __declspec(noinline) int sub_004B2E30_FindNpcIndex(D2NpcRecordStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->nValue04;
    for (int i = 0; i < gnNpcIndexCount_00725A74; ++i)
    {
        if (gaNpcIndex_00726C48[i].nId == nId)
            return i;
    }
    return 0;
}

void __cdecl sub_F03_Emit_004B1640(D2NpcRecordStrc* pRecord)
{
    sub_004B1640_SetNpcInteract(pRecord);
}

int __cdecl sub_F03_Emit_004B19A0(int nNpcId)
{
    return sub_004B19A0_RunNpcQuestHandlers(nNpcId, gpQuestFlags_007C0D43, gaNpcHandlers_007253E0, gnHandlerCount_007253DC);
}

void __cdecl sub_F03_Emit_004B1A10(int nClassId)
{
    if (sub_004B1A10_IsSpecialNpc(nClassId))
        gnGlobal_007C0D29 = 1;
}

int __cdecl sub_F03_Emit_004B2E30(D2NpcRecordStrc* pRecord)
{
    return sub_004B2E30_FindNpcIndex(pRecord);
}

#include "gen/data/Source/D2Client/004B1640_sub_004B1640_SetNpcInteract.inc"

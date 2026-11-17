struct D2GameStrc;
struct D2AiControlStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x2C - 0x10];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    unsigned int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2ObjectsTxt
{
    char unk0x00[0x16D];
    unsigned char nMonsterOK;
};

struct D2DoorObjectAiCallbackArgStrc
{
    D2UnitStrc* pDoor;
    int nDistance;
    int unk0x08[8];
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
#define MONSTATSFLAGINDEX_OPENDOORS 3

unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648EB0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID); // 0x00584540
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);             // 0x005DE080

// 0x005B0F50
int __fastcall sub_005B0F50_OpenDoorInReach(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (BITARRAY_CHECK(pAiTickParam->pMonstatsTxt->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) && D2Common_10201(pUnit->pDynamicPath) & 0x800)
    {
        D2DoorObjectAiCallbackArgStrc arg;
        arg.pDoor = 0;
        arg.nDistance = 9;

        sub_6FCF1E80(pGame, pUnit, &arg, 0, 8);

        D2UnitStrc* pDoor = arg.pDoor;
        if (pDoor)
        {
            const int nClassId = (pDoor ? pDoor->dwClassId : -1);
            if (DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
            {
                const int nDoorId = (pDoor ? pDoor->dwUnitId : -1);
                OBJMODE_OperateObjectInRange(pGame, pUnit, 2, nDoorId);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
                return 1;
            }
        }
    }

    return 0;
}

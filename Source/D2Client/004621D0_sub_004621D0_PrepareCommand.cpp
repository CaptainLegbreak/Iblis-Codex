struct D2SkillStrc;
struct D2ActiveRoomStrc;

struct D2PlayerDataStrc
{
    char unk0x000[0x150];
    int nState;
    int nMode;
    int nArg1;
    int nArg2;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
};

struct D2PlayerCmdStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pPlayer;
    D2UnitStrc* pTarget;
    int nX;
    int nY;
    int nArg;
    int nMode;
    D2SkillStrc* pSkill;
};

struct D2SkillsTxt
{
    char unk0x00[0x4];
    unsigned char nFlags[8];
};

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __cdecl sub_00453EC0();                                                                                // 0x00453EC0
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit);                                        // 0x0045C470
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __fastcall sub_00467880_FindSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl sub_00468830();                                                                                 // 0x00468830
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460

static inline int E06_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline int E06_GetPlayerModeArg1(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwUnitType == 0 ? (pUnit->pPlayerData ? pUnit->pPlayerData->nArg1 : 0) : 0) : 0;
}

static inline int E06_GetPlayerModeArg2(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwUnitType == 0 ? (pUnit->pPlayerData ? pUnit->pPlayerData->nArg2 : 0) : 0) : 0;
}

static inline void E06_ClearPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

// 0x004621D0
static int sub_004621D0_PrepareCommand(D2PlayerCmdStrc* pCmd)
{
    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    if (pCmd->pSkill && (pCmd->dwFlags & 2) && nResult != 1)
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pCmd->pSkill);
        if (!pSkillsTxt)
            return 0;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCmd->pPlayer);
        if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]) && DUNGEON_IsRoomInTown(pRoom))
        {
            sub_004CB9C0_Request(pCmd->pPlayer, 0x18);
            return 0;
        }

        if (pSkillsTxt->nFlags[0] & gdwBitMasks[4])
            return 0;
    }

    if (pCmd->dwFlags & 0x40)
    {
        pCmd->nArg = 3;
        pCmd->nMode = 4;
    }
    else
    {
        pCmd->nArg = 1;
        pCmd->nMode = 2;
    }

    const int nMode = E06_GetPlayerMode(pCmd->pPlayer);
    if (nMode)
    {
        if (nMode == 0x13)
        {
            const int nModeArg1 = E06_GetPlayerModeArg1(pCmd->pPlayer);
            const int nModeArg2 = E06_GetPlayerModeArg2(pCmd->pPlayer);
            if (sub_00463990(nModeArg2, nModeArg1))
                sub_0045C470_ClearPendingAction(pCmd->pPlayer);
        }
        else
        {
            E06_ClearPlayerMode(pCmd->pPlayer);
        }
    }

    if (!pCmd->pSkill)
        return 0;

    int bForce = (pCmd->dwFlags >> 5) & 1;
    if ((pCmd->dwFlags & 2) && !pCmd->pTarget)
        bForce = 1;
    pCmd->pTarget = sub_00467880_FindSkillTarget(pCmd->pSkill, pCmd->pTarget, &pCmd->nX, &pCmd->nY, pCmd->dwFlags, bForce);
    if (sub_00468830() == 6)
    {
        sub_00453EC0();
        return 1;
    }
    if (sub_00468830() == 8)
        sub_00478680_SendPacket5(0x4C, -1);
    return 1;
}

int __cdecl sub_E06_Emit_004621D0(D2PlayerCmdStrc* pCmd)
{
    if (!sub_004621D0_PrepareCommand(pCmd))
    {
        return 0;
    }
    return pCmd->nMode;
}

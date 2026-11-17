struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    char unk0xC8[0x0C];
    unsigned int dwLastInteractTick;
};

struct D2ClientSkillCmdStrc
{
    int nSkillId;
    int nOwnerGUID;
    int nTargetType;
    int f_C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3);                     // 0x004786D0
int __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillCmdStrc* pArgs);               // 0x004C6EB0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId);                                           // 0x004CB9C0
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY);                            // 0x00621C00
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

// 0x00480930
void __fastcall sub_00480930_InteractWithUnit(unsigned short nType, int nUnitId)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2UnitStrc* pUnit = sub_00463990(nUnitId, nType);
    if (!pUnit)
    {
        return;
    }

    switch (nType)
    {
    case 2:
    {
        PATH_SetTargetUnit(pPlayer->pDynamicPath, 0);
        int bSelectable = 0;
        if (pUnit)
        {
            bSelectable = (pUnit->dwFlags >> 2) & 1;
        }

        if (bSelectable)
        {
            UNITS_UpdateDirectionAndSpeed(pPlayer, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit));

            D2ClientSkillCmdStrc tCmd;
            memset(&tCmd, 0, sizeof(tCmd));
            tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, 1), ".\\UNIT\\UnitMode.cpp", 525);
            if (pUnit->dwClassId == 404)
            {
                if (pUnit->dwAnimMode == 0)
                {
                    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                    if (!pItem || ITEMS_GetBaseCode(pItem) != 0x20326671)
                    {
                        sub_004CB9C0_Request(pPlayer, 0x13);
                        return;
                    }

                    tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetSkillById(pPlayer, 0, -1), ".\\UNIT\\UnitMode.cpp", 536);
                }
            }
            else if (pUnit->dwClassId == 376)
            {
                if (pUnit->dwAnimMode == 0)
                {
                    sub_004786A0_SendIntInt(0x13, nType, nUnitId);
                    return;
                }

                if (pUnit->dwAnimMode == 2)
                {
                    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                    if (!pItem || ITEMS_GetBaseCode(pItem) != 0x20686668)
                    {
                        sub_004CB9C0_Request(pPlayer, 0x13);
                        return;
                    }

                    tCmd.nSkillId = SKILLS_GetSkillIdFromSkill(SKILLS_GetSkillById(pPlayer, 0, -1), ".\\UNIT\\UnitMode.cpp", 558);
                }
            }

            tCmd.nOwnerGUID = -1;
            tCmd.nTargetType = 2;
            tCmd.f_C = nUnitId;
            sub_004C6EB0_StartSkillOnUnit(pPlayer, &tCmd);
        }
        break;
    }

    case 1:
    {
        const unsigned int nTick = GetTickCount();
        if (nTick - pUnit->dwLastInteractTick < 200)
        {
            return;
        }

        pUnit->dwLastInteractTick = nTick;
        break;
    }

    case 0:
        UNITS_UpdateDirectionAndSpeed(pPlayer, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit));
        break;

    case 4:
        sub_004786D0_SendPacket(0x16, 4, nUnitId, (unsigned char)sub_004538D0(1));
        return;
    }

    sub_004786A0_SendIntInt(0x13, nType, nUnitId);
}

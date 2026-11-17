struct D2GameStrc;
struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_INVALID 6

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                    // 0x00554100
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_6FC3F340(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5); // 0x0053D6D0
int __fastcall sub_6FC91250(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, int nGoldAmount); // 0x00568060
void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00579130
void __fastcall sub_6FC79B50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject);                   // 0x005854D0
void __fastcall sub_6FC92EF0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00567330
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

// 0x005351C0
void __fastcall sub_6FC7BEC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2UnitStrc* pInteractUnit;
    int nInteractUnitId;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && (pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID)) != 0)
    {
        {
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                D2GAME_NPC_ResetInteract_6FCCB4D0(pGame, pUnit, pInteractUnit);
                nInteractUnitId = pInteractUnit->dwUnitId;
                sub_6FC3F340(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\Player.cpp", 0x202), 0x62, UNIT_MONSTER, nInteractUnitId, 0);
                return;

            case UNIT_OBJECT:
                sub_6FC79B50(pGame, pUnit, pInteractUnit);
                nInteractUnitId = pInteractUnit->dwUnitId;
                sub_6FC3F340(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\Player.cpp", 0x206), 0x62, UNIT_OBJECT, nInteractUnitId, 0);
                return;

            case UNIT_PLAYER:
                sub_6FC91250(pGame, pUnit, 6, 0);
                return;

            case UNIT_ITEM:
                if (DATATBLS_GetItemsTxtRecord(pInteractUnit->dwClassId)->dwCode == ' xob')
                {
                    sub_6FC92EF0(pGame, pUnit);
                    nInteractUnitId = pInteractUnit->dwUnitId;
                    sub_6FC3F340(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\Player.cpp", 0x211), 0x62, UNIT_ITEM, nInteractUnitId, 0);
                }
                return;
            }
        }
    }

    sub_6FC3F340(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\Player.cpp", 0x217), 0x62, UNIT_INVALID, 0, 0);
}

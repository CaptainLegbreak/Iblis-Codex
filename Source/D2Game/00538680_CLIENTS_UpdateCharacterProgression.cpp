union D2PackedClientSaveFlags
{
    unsigned short nPackedValue;
    struct
    {
        unsigned short bInit : 1;
        unsigned short bUnkFlag0x02 : 1;
        unsigned short bHardcore : 1;
        unsigned short bDead : 1;
        unsigned short bUnkFlag0x10 : 1;
        unsigned short bExpansion : 1;
        unsigned short bLadder : 1;
        unsigned short bUnkFlag0x80 : 1;
        unsigned short nProgression : 5;
        unsigned short bWeaponSwitch : 1;
        unsigned short nDONOTUSEBITS : 2;
    };
};

struct D2ClientStrc
{
    char unk0x00[0x0A];
    D2PackedClientSaveFlags tSaveFlags;
};

// 0x00538680
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty)
{
    int nActsPerDifficulty;
    if (pClient->tSaveFlags.bExpansion)
    {
        nActsPerDifficulty = 5;
    }
    else
    {
        nActsPerDifficulty = 4;
    }

    const int nNewActDifficulty = nAct + nDifficulty * nActsPerDifficulty;
    if (nNewActDifficulty >= pClient->tSaveFlags.nProgression)
    {
        unsigned short* pPackedValue = &pClient->tSaveFlags.nPackedValue;
        *pPackedValue = (*pPackedValue & 0xE0FF) | ((unsigned short)(nDifficulty * nActsPerDifficulty + nAct) << 8);
    }
}

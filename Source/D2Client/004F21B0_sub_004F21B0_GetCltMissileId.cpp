#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2UnitStrc;
struct D2StatListStrc;

struct D2SkillsTxt
{
	char unk_000[0x04];
	unsigned char nFlags[4];
	char unk_008[0x4C];
	short wAuraStat;
	char unk_056[0x2A];
	short wAuraState;
	char unk_082[0x66];
	short wCltMissile[4];
	char unk_0F0[0x23C - 0xF0];
};

struct D2DataTablesStrc
{
	char unk_000[0xC4];
	int nStatesTxtRecordCount;
	char unk_0C8[0xB98 - 0xC8];
	D2SkillsTxt* pSkillsTxt;
	int unk_B9C;
	int nSkillsTxtRecordCount;
	char unk_BA4[0xBD4 - 0xBA4];
	int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gbSkillFlagMask_006CE270; // 0x006CE270
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

// build: context sub_004F21B0_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* sub_004F21B0_GetSkillsTxtRecord(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}
	return 0;
}

// 0x004F21B0
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId)
{
	D2SkillsTxt* pSkillsTxtRecord = sub_004F21B0_GetSkillsTxtRecord(nSkillId);
	if (!pSkillsTxtRecord)
	{
		return -1;
	}

	if (pSkillsTxtRecord->nFlags[0] & gbSkillFlagMask_006CE270)
	{
		if (pSkillsTxtRecord->wAuraState >= 0 && pSkillsTxtRecord->wAuraState < sgptDataTables->nStatesTxtRecordCount
			&& pSkillsTxtRecord->wAuraStat >= 0 && pSkillsTxtRecord->wAuraStat < sgptDataTables->nItemStatCostTxtRecordCount)
		{
			D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraState);
			if (pStatList)
			{
				int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat, 0);
				nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
				return pSkillsTxtRecord->wCltMissile[nIndex];
			}
		}
	}

	return pSkillsTxtRecord->wCltMissile[1];
}

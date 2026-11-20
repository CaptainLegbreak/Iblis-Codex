#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



extern D2DataTablesStrc* sgptDataTables_00744304; // 0x00744304
extern const unsigned char gbFlagMask_006CE270; // 0x006CE270
int __stdcall sub_0064A3E0(D2UnitStrc* pUnit); // 0x0064A3E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

// build: context DATATBLS_GetMissilesTxtRecord
static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
	if (nMissileId >= 0 && nMissileId < sgptDataTables_00744304->nMissilesTxtRecordCount)
	{
		return &sgptDataTables_00744304->pMissilesTxt[nMissileId];
	}
	return 0;
}

static __declspec(noinline) int sub_004CD310_UseCharge(D2UnitStrc* pUnit);

// 0x004CD310
static int sub_004CD310_UseCharge(D2UnitStrc* pUnit)
{
	int nResult = 3;
	D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(sub_0064A3E0(pUnit));

	if (!(pMissilesTxtRecord->nMissileFlags[0] & gbFlagMask_006CE270))
	    return nResult;
		const int nValue = STATLIST_UnitGetStatValue(pUnit, 328, 0);
		if (nValue)
		{
			nResult = 2;
			STATLIST_SetUnitStat(pUnit, 328, nValue - 1, 0);
		}

	return nResult;
}

// build: context sub_004CD310_Shim

// calling-convention shim (not game code)
int __stdcall sub_004CD310_Shim(D2UnitStrc* pUnit)
{
	return sub_004CD310_UseCharge(pUnit);
}

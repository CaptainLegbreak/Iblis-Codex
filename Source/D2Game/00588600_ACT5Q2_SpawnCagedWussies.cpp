struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
	int dwUnitType;
	int dwClassId;
	void* pMemoryPool;
	unsigned int dwUnitId;
	char unk_10[0xB4];
	unsigned int dwFlags;
};

struct D2Act5Quest2Strc
{
	char unk_00[0xB0];
	unsigned int unk0xB0[5][5];
};

struct D2QuestDataStrc
{
	int nQuest;
	D2GameStrc* pGame;
	char unk_08;
	char bNotIntro;
	char unk_0A[0x0E];
	D2Act5Quest2Strc* pQuestDataEx;
};

struct D2ObjInitFnStrc
{
	D2GameStrc* pGame;
	D2UnitStrc* pObject;
	D2ActiveRoomStrc* pRoom;
	void* pObjectregion;
	void* pObjectTxt;
	int nX;
	int nY;
};

D2UnitStrc* __fastcall sub_005B2F20(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, short a8); // 0x005B2F20
void __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nQuestId); // 0x005436B0

// 0x00588600
int __fastcall ACT5Q2_SpawnCagedWussies(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp, int nCount)
{
	int nWussiesSpawned = 0;
	if (pQuestData && pQuestData->bNotIntro)
	{
		for (int i = 0; i < 25; ++i)
		{
			D2UnitStrc* pWussies = sub_005B2F20(pQuestData->pGame, pOp->pRoom, pOp->nX, pOp->nY, 534, 1, 5, 0);
			if (pWussies)
			{
				pWussies->dwFlags |= 0x3000000;

				D2Act5Quest2Strc* pQuestDataEx = pQuestData->pQuestDataEx;
				pQuestDataEx->unk0xB0[nCount][nWussiesSpawned] = !pWussies ? -1 : pWussies->dwUnitId;
				++nWussiesSpawned;

				QUESTS_CreateChainRecord(pQuestData->pGame, pWussies, 32);
				if (nWussiesSpawned >= 5)
				{
					break;
				}
			}
		}
	}

	return nWussiesSpawned;
}

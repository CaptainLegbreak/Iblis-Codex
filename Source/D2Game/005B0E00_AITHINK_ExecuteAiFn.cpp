extern "C" void* __cdecl memset(void*,int,unsigned int);
struct D2GameStrc;
struct D2UnitStrc { int type; int classId; };
struct D2AiTickStrc;
typedef void (__fastcall* AiFn)(D2GameStrc*,D2UnitStrc*,D2AiTickStrc*);
struct D2AiControlStrc { int state; AiFn function; int unk08[3]; int unk14; int unk18; int unk1C; };
struct D2AiTickStrc { D2AiControlStrc* control; int unk04[6]; void* monstats; void* monstats2; };
struct D2AiTableStrc { int unk00; AiFn init; AiFn function; AiFn alternate; };
struct D2DataTablesStrc { int unk00[0xA80/4]; int monstatsCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const char gszEmpty_006CC837[]; // 0x006CC837
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);
int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0
D2AiTableStrc* __fastcall sub_005B15D0_GetAiTable(D2UnitStrc*,int); // 0x005B15D0
void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc*,D2UnitStrc*); // 0x0058EDE0
void* __fastcall DATATBLS_GetMonStatsTxtRecord(int); // 0x00451F80
void* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc*,D2UnitStrc*,D2AiTickStrc*); // 0x005B0CD0
#define ASSERT(expr,line) if (!(expr)) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),line); exit(-1); }
// 0x005B0E00
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState)
{
    ASSERT(!STATES_CheckState(pUnit, 54), 422);

    if (!pGame || !pUnit || !pAiControl || nAiSpecialState >= 18 || (!pUnit ? 6 : pUnit->type) != 1)
    {
        return;
    }

    const int nClassId = pUnit->classId;
    if (nClassId >= sgptDataTables->monstatsCount)
    {
        nAiSpecialState = 1;
    }

    if (pAiControl->function)
    {
        D2AiTableStrc* pAiTableRecord = sub_005B15D0_GetAiTable(pUnit, pAiControl->state);
        if (pAiControl->function == pAiTableRecord->function && pAiTableRecord->alternate)
        {
            pAiControl->state = nAiSpecialState;
            pAiControl->function = pAiTableRecord->alternate;
            return;
        }
    }

    memset(&pAiControl->unk14, 0, 3 * sizeof(int));

    AIGENERAL_FreeAllAiCommands(pGame, pUnit);

    D2AiTableStrc* __restrict pAiTableRecord = sub_005B15D0_GetAiTable(pUnit, nAiSpecialState);
    if (!pAiTableRecord)
    {
        return;
    }

    if (pAiTableRecord->init)
    {
        D2AiTickStrc aiTickParam = {};
        aiTickParam.control = pAiControl;
        aiTickParam.monstats = DATATBLS_GetMonStatsTxtRecord(nClassId);
        aiTickParam.monstats2 = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (!aiTickParam.monstats || !aiTickParam.monstats2)
        {
            return;
        }

        pAiTableRecord->init(pGame, pUnit, &aiTickParam);
    }

    AiFn pAiParamFn = pAiTableRecord->function;
    if (!pAiParamFn)
    {
        pAiParamFn = AITHINK_Fn001_100_Idle_Buffy;
    }

    pAiControl->state = nAiSpecialState;
    pAiControl->function = pAiParamFn;

    ASSERT(!IsBadCodePtr((void*)pAiParamFn), 498);
}

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006CB4C0_Table
{
    int unk_00;
};

void __fastcall sub_00604640(sub_006CB4C0_Table* pTable); // 0x00604640

sub_006CB4C0_Table data_008E8CC0;        // 0x008E8CC0
extern CRITICAL_SECTION data_008E8D10; // 0x008E8D10

// 0x006CB4C0
void __cdecl sub_006CB4C0_DestroyTable()
{
    DeleteCriticalSection(&data_008E8D10);
    sub_00604640(&data_008E8CC0);
}

struct D2StormHashTableReuseStrc;

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct D2StormHashTableReuseStrc
{
    ~D2StormHashTableReuseStrc();
};


// build: symbol ??1D2StormHashTableReuseStrc@@QAE@XZ 0x00450760
extern D2StormHashTableReuseStrc data_007A0690; // 0x007A0690
extern CRITICAL_SECTION gtGameDataTableLock; // 0x007A06E0

// 0x006CB400
void __cdecl sub_006CB400_Nop()
{
}

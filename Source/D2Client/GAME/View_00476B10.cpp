struct SynRect
{
    long left;
    long top;
    long right;
    long bottom;
};

struct Obj004DCF10
{
    unsigned int flags;
    SynRect rect;
    unsigned char beforeRows[0x18];
    void* rows;
    void* data;
    void* table;
    unsigned char unusedTail[0xEABC - 0x38];
};

typedef char Obj004DCF10Size[(sizeof(Obj004DCF10) == 0xEABC) ? 1 : -1];

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define SYN_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int, const char*, int, int); // 0x0040B380
extern "C" __declspec(dllimport) int __stdcall SetRect(SynRect*, int, int, int, int); // 0x006CC498
void __fastcall sub_004DDDF0(void* rows, void* data); // 0x004DDDF0
extern "C" void __fastcall sub_004DCF10(Obj004DCF10*); // 0x004DCF10

unsigned char** gppLerpRows_007B953C;        // 0x007B953C
extern void* gpLerpTable_007B9540; // 0x007B9540
extern void* gpLerpTable_007B9544; // 0x007B9544
int gnGlobal_007B9530;        // 0x007B9530

// 0x00476B10
Obj004DCF10* __cdecl sub_00476B10_CreateView()
{
    SYN_ASSERT(gppLerpRows_007B953C, 0x119);
    SYN_ASSERT(gpLerpTable_007B9540, 0x11A);
    SYN_ASSERT(gpLerpTable_007B9544, 0x11B);

    Obj004DCF10* view = static_cast<Obj004DCF10*>(FOG_Alloc(sizeof(Obj004DCF10), ".\\GAME\\View.cpp", 0x11D, 0));
    SetRect(&view->rect, 0, 0, 0, 0);

    void* const rows = gppLerpRows_007B953C;
    void* const data = gpLerpTable_007B9540;
    void* const table = gpLerpTable_007B9544;

    view->flags = 0;
    view->rows = rows;
    view->data = data;
    view->table = table;
    sub_004DDDF0(rows, data);
    sub_004DCF10(view);
    view->flags |= 1;
    gnGlobal_007B9530 = 0;
    return view;
}

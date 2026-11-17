typedef unsigned long DWORD;
typedef int BOOL;
typedef void* HWND;
typedef void* HIMC;
typedef void* HKL;

struct ImeMessage
{
    unsigned char beforeKind[8];
    DWORD kind;
    unsigned char beforeHandled[12];
    DWORD handled;
    DWORD result;
};

extern "C" int g_007BB5DC_Mode; // 0x007BB5DC
extern "C" unsigned char g_007BB5E0_Enabled; // 0x007BB5E0
extern "C" int g_007BB5F0_State; // 0x007BB5F0
extern "C" { DWORD* g_007BB5F4_Candidates; } // 0x007BB5F4
extern "C" void* __fastcall sub_0040B380_Allocate(DWORD size, const char* source, int line, int flags); // 0x0040B380
extern "C" int __fastcall sub_0040B3C0_Free(void* pointer, const char* source, int line, int flags); // 0x0040B3C0
extern "C" int __stdcall sub_00420290_QueueMessage(ImeMessage* message); // 0x00420290
extern "C" HWND __cdecl sub_004F59A0_GetWindow(); // 0x004F59A0

extern "C" BOOL __stdcall sub_006B00B4_ImmReleaseContext(HWND window, HIMC context); // 0x006B00B4
extern "C" BOOL __stdcall sub_006B00BA_ImmGetOpenStatus(HIMC context); // 0x006B00BA
extern "C" HIMC __stdcall sub_006B00C6_ImmGetContext(HWND window); // 0x006B00C6
extern "C" DWORD __stdcall sub_006B00CC_ImmGetCandidateListA(HIMC context, DWORD index, void* candidates, DWORD bytes); // 0x006B00CC
extern "C" DWORD __stdcall sub_006B00D2_ImmGetCandidateListCountA(HIMC context, DWORD* count); // 0x006B00D2
extern "C" BOOL __stdcall sub_006B00D8_ImmIsIME(HKL layout); // 0x006B00D8
extern "C" BOOL __stdcall sub_006B00DE_ImmGetConversionStatus(HIMC context, DWORD* conversion, DWORD* sentence); // 0x006B00DE
extern "C" __declspec(dllimport) HKL __stdcall GetKeyboardLayout(DWORD thread); // 0x006CC4C0

// 0x0047AD60
static __declspec(noinline) void __cdecl sub_0047AD60_RefreshCandidates(HIMC context)
{
    DWORD count;
    DWORD bytes = sub_006B00D2_ImmGetCandidateListCountA(context, &count);
    if (sub_006B00CC_ImmGetCandidateListA(context, 0, 0, 0) && bytes)
    {
        if (g_007BB5F4_Candidates)
            sub_0040B3C0_Free(g_007BB5F4_Candidates, ".\\UI\\chat.cpp", 235, 0);
        g_007BB5F4_Candidates = (DWORD*)sub_0040B380_Allocate(bytes, ".\\UI\\chat.cpp", 237, 0);
        sub_006B00CC_ImmGetCandidateListA(context, 0, g_007BB5F4_Candidates, bytes);
        if (g_007BB5F4_Candidates[1] == 2 && g_007BB5F4_Candidates[2] == 1)
        {
            sub_0040B3C0_Free(g_007BB5F4_Candidates, ".\\UI\\chat.cpp", 242, 0);
            g_007BB5F4_Candidates = 0;
        }
    }
}

extern "C" void __stdcall sub_0047AE00_ImeNotify(ImeMessage* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    HIMC context = sub_006B00C6_ImmGetContext(sub_004F59A0_GetWindow());
    if (!context)
        return;
    switch (message->kind)
    {
    case 8:
        switch (g_007BB5DC_Mode)
        {
        case 6:
            if (sub_006B00BA_ImmGetOpenStatus(context))
            {
                g_007BB5E0_Enabled = 1;
                g_007BB5F0_State = 3;
            }
            else
            {
                g_007BB5E0_Enabled = 0;
                g_007BB5F0_State = 0;
            }
            break;
        case 8:
            if (sub_006B00BA_ImmGetOpenStatus(context))
            {
                g_007BB5E0_Enabled = 1;
                g_007BB5F0_State = 5;
            }
            else
            {
                g_007BB5E0_Enabled = 0;
                g_007BB5F0_State = 0;
            }
            break;
        case 9:
            if (sub_006B00BA_ImmGetOpenStatus(context))
            {
                g_007BB5E0_Enabled = 1;
                g_007BB5F0_State = 4;
            }
            else
            {
                g_007BB5E0_Enabled = 0;
                g_007BB5F0_State = 0;
            }
            break;
        }
        break;
    case 6:
        {
            DWORD conversion;
            DWORD sentence;
            sub_006B00DE_ImmGetConversionStatus(context, &conversion, &sentence);
            if (g_007BB5DC_Mode == 7 || g_007BB5DC_Mode == 12)
            {
                if (conversion & 1)
                {
                    g_007BB5F0_State = 1;
                    g_007BB5E0_Enabled = 1;
                }
                else
                {
                    g_007BB5E0_Enabled = 0;
                    g_007BB5F0_State = 0;
                }
            }
        }
        break;
    case 5:
        if (g_007BB5DC_Mode == 9)
        {
            sub_0047AD60_RefreshCandidates(context);
            message->handled = 1;
            message->result = 0;
        }
        if (g_007BB5DC_Mode == 8)
        {
            sub_0047AD60_RefreshCandidates(context);
            message->result = 0;
            message->handled = 1;
        }
        break;
    case 4:
        {
        DWORD* candidates = g_007BB5F4_Candidates;
        if (g_007BB5DC_Mode == 9)
        {
            if (candidates)
            {
                sub_0040B3C0_Free(candidates, ".\\UI\\chat.cpp", 352, 0);
                candidates = 0;
                g_007BB5F4_Candidates = candidates;
            }
            message->handled = 1;
            message->result = 0;
        }
        if (g_007BB5DC_Mode == 8)
        {
            if (candidates)
            {
                sub_0040B3C0_Free(candidates, ".\\UI\\chat.cpp", 363, 0);
                g_007BB5F4_Candidates = 0;
            }
            message->result = 0;
            message->handled = 1;
        }
        }
        break;
    case 3:
        if (g_007BB5DC_Mode == 9)
        {
            sub_0047AD60_RefreshCandidates(context);
            message->result = 0;
            message->handled = 1;
        }
        break;
    case 2:
        if (g_007BB5DC_Mode == 9)
        {
            g_007BB5F0_State = sub_006B00D8_ImmIsIME(GetKeyboardLayout(0)) ? 0 : 4;
            message->result = 0;
            message->handled = 1;
        }
        break;
    case 7:
        break;
    }
    sub_006B00B4_ImmReleaseContext(sub_004F59A0_GetWindow(), context);
}

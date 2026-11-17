extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837

struct D2QueueServerStrc
{
    void* pHandle;
};

unsigned int __fastcall sub_006C3120_Start(D2QueueServerStrc* pServer, int nValue); // 0x006C3120

// 0x006BE350
void __stdcall sub_006BE350_StartListening(D2QueueServerStrc* pServer, unsigned int nValue)
{
    if (pServer->pHandle)
    {
        sub_006C3120_Start(pServer, nValue);
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 297);
        exit(-1);
    }
}

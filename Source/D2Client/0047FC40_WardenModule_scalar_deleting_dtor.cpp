int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// build: symbol ??_GWardenModule@@QAEPAXI@Z 0x0047FC40
// 0x0047FC40
class WardenModule
{
public:
    ~WardenModule();
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }

    void* pImage;
    int unk0x04;
    int nImports;
};

void WardenModule_EmitDelete(WardenModule* pModule)
{
    delete pModule;
}

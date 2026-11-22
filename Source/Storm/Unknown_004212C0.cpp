void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char szWardenClientFile_006D8E18[];

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* f_10;
};

struct D2Warden47F930Strc
{
    int n00;
    int n04;
    int n08;

    D2Warden47F930Strc();
};

struct D2WardenModuleHolderAStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderAStrc();
};

struct D2WardenModuleHolderBStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderBStrc();
};

namespace NWardenClient
{
struct Library
{
    Library();
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
};
}

// 0x004212C0
// build: symbol ?WARDENCLIENT_SwapBytes@* 0x0047F8B0
void __fastcall WARDENCLIENT_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

D2Warden47F930Strc::D2Warden47F930Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    unk0x0C = 0;
    f_10 = 0;
}

D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

// build: symbol ?WARDENCLIENT_AllocLoaderMemory@* 0x0047FBF0
void* __fastcall WARDENCLIENT_AllocLoaderMemory(unsigned int nSize)
{
    return SMemAlloc(nSize, szWardenClientFile_006D8E18, 0x10D, 0);
}

// build: symbol ?WARDENCLIENT_FreeLoaderMemory@* 0x0047FC10
void __fastcall WARDENCLIENT_FreeLoaderMemory(void* pMemory)
{
    SMemFree(pMemory, szWardenClientFile_006D8E18, 0x117, 0);
}

NWardenClient::Library::Library()
{
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();                                                                // 0x004E06A0

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

// build: symbol ??_7Library@NWardenClient@@6B@ 0x006D8E38
// 0x0047F8B0
void __fastcall sub_0047F8B0_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x0047F930
D2Warden47F930Strc::D2Warden47F930Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

// 0x0047F940
D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

// 0x0047FBC0
WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    unk0x0C = 0;
    f_10 = 0;
}

// 0x0047FBE0
D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

// 0x0047FBF0
void* __fastcall sub_0047FBF0_WardenAlloc(unsigned int nSize)
{
    return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x10D, 0);
}

// 0x0047FC10
void __fastcall sub_0047FC10_WardenFree(void* pMemory)
{
    SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
}

// 0x0047FC30
NWardenClient::Library::Library()
{
}

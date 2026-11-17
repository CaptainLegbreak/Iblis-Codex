int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __fastcall sub_0052A600(void* pArg);                                                                    // 0x0052A600

struct D2BigPowModStrc
{
    int bValid;
    void* hBase;
    void* hModulus;
    unsigned char abRandomState[0x3C];
    unsigned int nRandomBytesLeft;

    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2BigPairStrc
{
    ~D2BigPairStrc();
    void sub_00528630_Release();

    D2BigPowModStrc* pState;
};

// 0x00528530
D2BigPairStrc::~D2BigPairStrc()
{
    if (pState)
    {
        delete pState;
    }
}

// 0x00528630
void D2BigPairStrc::sub_00528630_Release()
{
    if (pState->bValid)
    {
        sub_0052A600(pState->hModulus);
        sub_0052A600(pState->hBase);
    }
    pState->bValid = 0;
}

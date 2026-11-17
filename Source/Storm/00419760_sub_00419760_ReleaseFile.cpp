int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

struct D2StormFileRecStrc
{
    char unk0x00[0x144];
    int nRefCount;

    ~D2StormFileRecStrc();                                                                                  // 0x00419070
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// 0x00419760
static void sub_00419760_ReleaseFile(D2StormFileRecStrc* pFile)
{
    if (pFile && !--pFile->nRefCount)
        delete pFile;
}

void __fastcall sub_M126_Emit_00419760(int a, D2StormFileRecStrc* pFile, int nUnused)
{
    sub_00419760_ReleaseFile(pFile);
}

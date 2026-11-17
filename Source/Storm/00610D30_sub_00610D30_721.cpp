extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650

struct D2Object00610D30Strc
{
    ~D2Object00610D30Strc(); // 0x00610AA0
    void* sub_00610D30(unsigned int nFlags);
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// 0x00610D30
void* D2Object00610D30Strc::sub_00610D30(unsigned int nFlags)
{
    this->~D2Object00610D30Strc();
    if (nFlags & 1)
        operator delete(this);
    return this;
}

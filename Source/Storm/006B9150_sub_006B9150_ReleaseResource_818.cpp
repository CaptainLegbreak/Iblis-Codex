struct D2ResourceInterface {
    virtual long __stdcall QueryInterface(const void* id, void** output) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
extern D2ResourceInterface* gpResource_00971734; // 0x00971734
// 0x006B9150
void __cdecl sub_006B9150_ReleaseResource()
{
    if (gpResource_00971734) {
        gpResource_00971734->Release();
        gpResource_00971734 = 0;
    }
}

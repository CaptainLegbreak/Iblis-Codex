// calling-convention shim (not game code)
int __stdcall sub_004192F0_OpenArchiveFile(void*, const char*, unsigned int, void**); // 0x004192F0
unsigned int __stdcall sub_00416370_GetFileSize(void*, unsigned int*); // 0x00416370
void* __stdcall sub_00413020_Alloc(unsigned int, const char*, int, unsigned int); // 0x00413020
int __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
int __stdcall SFileReadFile(void*, void*, unsigned int, unsigned int*, void*); // 0x0041B050
int __stdcall sub_004198D0(void*); // 0x004198D0
void* __fastcall sub_00406960_CreateFile(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void*); // 0x004069A0
int __fastcall sub_004069D0_WriteFile(void*, const void*, unsigned int, unsigned int*, void*); // 0x004069D0
extern const char gszBnDownloadFile_006DF338[]; // 0x006DF338
static __declspec(noinline) void __fastcall sub_0051E920_ExtractFile(const char* member, void* archive, const char* destination);

// 0x0051E920
static void __fastcall sub_0051E920_ExtractFile(const char* member, void* archive, const char* destination)
{
    void* output;
    void* source;
    if (!sub_004192F0_OpenArchiveFile(archive, member, 0, &source)) return;
    unsigned int size = sub_00416370_GetFileSize(source, 0);
    void* data = sub_00413020_Alloc(size, gszBnDownloadFile_006DF338, 0x583, 0);
    if (SFileReadFile(source, data, size, 0, 0)) {
        output = sub_00406960_CreateFile(destination, 0x40000000, 3, 0, 2, 0x80, 0);
        if (output != (void*)-1) {
            unsigned int written;
            sub_004069D0_WriteFile(output, data, size, &written, 0);
            sub_004069A0_CloseFile(output);
        }
    }
    SMemFree(data, gszBnDownloadFile_006DF338, 0x592, 0);
    sub_004198D0(source);
}

// build: context sub_0051E920_Shim
// calling-convention shim (not game code)
void __fastcall sub_0051E920_Shim(const char* member, void* archive, const char* destination)
{
    sub_0051E920_ExtractFile(member, archive, destination);
}

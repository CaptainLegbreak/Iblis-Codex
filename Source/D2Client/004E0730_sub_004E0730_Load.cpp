typedef unsigned int size_t;

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long nType, unsigned long nProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long nFreeType); // 0x006CC220
extern "C" __declspec(dllimport) int __stdcall VirtualProtect(void* pAddress, unsigned long nSize, unsigned long nNewProtect, unsigned long* pOldProtect); // 0x006CC360
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall FlushInstructionCache(void* hProcess, const void* pBaseAddress, unsigned long nSize); // 0x006CC35C
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

struct WardenSectionStrc
{
    unsigned int dwRva;
    unsigned int dwSize;
    unsigned int dwProtect;
};

struct WardenHeaderStrc
{
    unsigned int dwImageSize;
    unsigned int unk0x04;
    unsigned int dwRelocOffset;
    unsigned int nRelocCount;
    unsigned int unk0x10[3];
    unsigned int dwImportOffset;
    unsigned int nImportCount;
    unsigned int nSections;
};

struct WardenRawModuleStrc
{
    WardenHeaderStrc tHeader;
    WardenSectionStrc aSections[1];
};

struct WardenImportStrc
{
    unsigned int dwNameOffset;
    unsigned int dwThunkOffset;
};

class WardenModule
{
public:
    ~WardenModule();                                                                // 0x004E06A0
    bool sub_004E0730_Load(void* pData, int nSize);

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* pEntry;
};

// 0x004E0730
bool WardenModule::sub_004E0730_Load(void* pData, int nSize)
{
    int bFailed = 1;
    __try
    {
        WardenRawModuleStrc* pRaw = (WardenRawModuleStrc*)pData;
        unk0x04 = pRaw->tHeader.dwImageSize;
        pImage = VirtualAlloc(0, unk0x04, 0x1000, 4);
        if (!pImage)
        {
            __leave;
        }

        *(WardenHeaderStrc*)pImage = pRaw->tHeader;

        unsigned char* pChunk = (unsigned char*)&pRaw->aSections[((WardenHeaderStrc*)pImage)->nSections];
        unsigned char* pDest = (unsigned char*)pImage + pRaw->aSections[0].dwRva;
        unsigned char* pEnd = (unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwImageSize;
        bool bCopy = true;
        while (pDest < pEnd)
        {
            unsigned short nLength = *(unsigned short*)pChunk;
            pChunk += 2;
            if (bCopy)
            {
                memcpy(pDest, pChunk, nLength);
                pChunk += nLength;
            }
            pDest += nLength;
            if (pDest >= pEnd)
            {
                break;
            }
            bCopy = !bCopy;
        }

        unsigned char* pReloc = (unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwRelocOffset;
        unsigned int nOffset = 0;
        for (unsigned int i = 0; i < ((WardenHeaderStrc*)pImage)->nRelocCount; ++i)
        {
            if (pReloc[0] & 0x80)
            {
                nOffset = (((((pReloc[0] & 0x7F) << 8) + pReloc[1]) << 8) + pReloc[2] << 8) + pReloc[3];
                pReloc += 4;
            }
            else
            {
                nOffset += (pReloc[0] << 8) + pReloc[1];
                pReloc += 2;
            }
            *(unsigned int*)((unsigned char*)pImage + nOffset) += (unsigned int)pImage;
        }

        WardenImportStrc* pImports = (WardenImportStrc*)((unsigned char*)pImage + ((WardenHeaderStrc*)pImage)->dwImportOffset);
        for (unsigned int j = 0; j < ((WardenHeaderStrc*)pImage)->nImportCount; ++j)
        {
            const char* const szLibrary = (const char*)pImage + pImports[j].dwNameOffset;
            void* hLibrary = LoadLibraryA(szLibrary);
            if (!hLibrary)
            {
                __leave;
            }
            for (unsigned int* pThunk = (unsigned int*)((unsigned char*)pImage + pImports[j].dwThunkOffset); *pThunk; ++pThunk)
            {
                if (*pThunk & 0x80000000)
                {
                    *pThunk = (unsigned int)GetProcAddress(hLibrary, (const char*)(*pThunk & 0x7FFFFFFF));
                }
                else
                {
                    *pThunk = (unsigned int)GetProcAddress(hLibrary, (const char*)pImage + *pThunk);
                }
            }
            ++nImports;
        }

        for (unsigned int k = 0; k < ((WardenHeaderStrc*)pImage)->nSections; ++k)
        {
            WardenSectionStrc* pSection = &pRaw->aSections[k];
            void* pAddress = (unsigned char*)pImage + pSection->dwRva;
            unsigned long nLength = pSection->dwSize;
            unsigned long dwOldProtect;
            VirtualProtect(pAddress, nLength, pSection->dwProtect, &dwOldProtect);
            if (pSection->dwProtect & 0xF0)
            {
                FlushInstructionCache(GetCurrentProcess(), pAddress, nLength);
            }
        }

        if (((WardenHeaderStrc*)pImage)->dwRelocOffset < ((WardenHeaderStrc*)pImage)->dwImageSize)
        {
            const unsigned int nRelocStart = ((WardenHeaderStrc*)pImage)->dwRelocOffset;
            const unsigned int nPage = (nRelocStart + 0xFFF) & 0xFFFFF000;
            if (nPage >= nRelocStart && nPage < ((WardenHeaderStrc*)pImage)->dwImageSize)
            {
                VirtualFree((unsigned char*)pImage + nPage, ((WardenHeaderStrc*)pImage)->dwImageSize - nPage, 0x4000);
            }
        }
        bFailed = 0;
    }
    __except (1)
    {
    }

    if (bFailed)
    {
        this->~WardenModule();
    }
    return !bFailed;
}

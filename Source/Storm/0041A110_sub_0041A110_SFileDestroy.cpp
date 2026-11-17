extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __stdcall sub_0041D1E0_ReportHandleLeak(const char* szName);
void __stdcall sub_0041D010_ReportHandleLeak(const char* szName, const char* szDetail);
void __cdecl sub_00419F30();

#define STORM_DELETEOP static void operator delete(void* pMemory) { if (pMemory) SMemFree(pMemory, "delete", -1, 0); }

struct D2StormStreamOwnerStrc
{
    void* pLink[2];
    ~D2StormStreamOwnerStrc();
    STORM_DELETEOP
};

struct D2StormAudioStreamStrc
{
    void* pLink[2];
    ~D2StormAudioStreamStrc();
    STORM_DELETEOP
};

struct D2StormFileRecStrc
{
    void* pLink[2];
    char szName[0x108];
    ~D2StormFileRecStrc();
    STORM_DELETEOP
};

struct D2StormArchiveRecStrc
{
    void* pLink[2];
    char szName[0x104];
    ~D2StormArchiveRecStrc();
    STORM_DELETEOP
};

struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

void* ghStormThread_00779034;                                                                               // 0x00779034
void* ghStormEvent_00779054;                                                                                // 0x00779054
int gbThreadStop_00778F24;                                                                                  // 0x00778F24
D2StormStreamOwnerStrc* gpCurrentRequest_0077902C;                                                          // 0x0077902C
extern D2StormListStrc gRequestList_00708360;                                                               // 0x00708360
extern D2StormListStrc gDdaList_00708384;                                                                   // 0x00708384
extern D2StormListStrc gFileList_0070836C;                                                                  // 0x0070836C
extern D2StormListStrc gArchiveList_00708354;                                                               // 0x00708354
unsigned int* gpCryptTable_00779048;                                                                        // 0x00779048
char* gpStormExplodeWork;                                                                                   // 0x0077903C
unsigned char* gpStreamBuffer_00779050;                                                                     // 0x00779050

// build: symbol ??1D2StormArchiveRecStrc@@QAE@XZ 0x00418A50
// build: symbol ??1D2StormAudioStreamStrc@@QAE@XZ 0x004199A0
// build: symbol ??1D2StormFileRecStrc@@QAE@XZ 0x00419070
// build: symbol ??1D2StormStreamOwnerStrc@@QAE@XZ 0x0041A020
// 0x0041A110
int __cdecl sub_0041A110_SFileDestroy()
{
    sub_00419F30();
    if (ghStormThread_00779034)
    {
        gbThreadStop_00778F24 = 1;
        SetEvent(ghStormEvent_00779054);
        WaitForSingleObject(ghStormThread_00779034, 1000);
        if (ghStormEvent_00779054)
        {
            CloseHandle(ghStormEvent_00779054);
            ghStormEvent_00779054 = 0;
        }
        if (ghStormThread_00779034)
        {
            CloseHandle(ghStormThread_00779034);
            ghStormThread_00779034 = 0;
        }
    }
    if (gpCurrentRequest_0077902C)
    {
        delete gpCurrentRequest_0077902C;
        gpCurrentRequest_0077902C = 0;
    }
    while (gRequestList_00708360.Head())
        delete (D2StormStreamOwnerStrc*)gRequestList_00708360.Head();
    while (D2StormAudioStreamStrc* pStream = (D2StormAudioStreamStrc*)gDdaList_00708384.Head())
    {
        sub_0041D1E0_ReportHandleLeak("AUDIOSTREAM");
        delete pStream;
    }
    while (D2StormFileRecStrc* pFile = (D2StormFileRecStrc*)gFileList_0070836C.Head())
    {
        sub_0041D010_ReportHandleLeak("HSFILE", pFile->szName);
        delete pFile;
    }
    while (D2StormArchiveRecStrc* pArchive = (D2StormArchiveRecStrc*)gArchiveList_00708354.Head())
    {
        sub_0041D010_ReportHandleLeak("HSARCHIVE", pArchive->szName);
        delete pArchive;
    }
    if (gpCryptTable_00779048)
    {
        SMemFree(gpCryptTable_00779048, ".\\SOURCE\\SFILE.CPP", 0xE24, 0);
        gpCryptTable_00779048 = 0;
    }
    if (gpStormExplodeWork)
    {
        SMemFree(gpStormExplodeWork, ".\\SOURCE\\SFILE.CPP", 0xE2A, 0);
        gpStormExplodeWork = 0;
    }
    if (gpStreamBuffer_00779050)
    {
        SMemFree(gpStreamBuffer_00779050, ".\\SOURCE\\SFILE.CPP", 0xE30, 0);
        gpStreamBuffer_00779050 = 0;
    }
    return 1;
}

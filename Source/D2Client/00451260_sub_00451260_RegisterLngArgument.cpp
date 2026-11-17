struct D2MsgRecordChunkStrc
{
    char tRecords[500 * 0x10];
    int nCount;
    int nUnk0x1F44;
    D2MsgRecordChunkStrc* pNext;
};

int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580
int __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                        // 0x0040B3C0
extern char gszLngPath_007A0710[0x104];                                                                     // 0x007A0710
extern D2MsgRecordChunkStrc gtMsgRecordChunkFirst_007A0818;                                                 // 0x007A0818
#define gpMsgRecordChunkHead_007A2760 (gtMsgRecordChunkFirst_007A0818.pNext)

// 0x00451260
int __cdecl sub_00451260_RegisterLngArgument()
{
    SCmdRegisterArgument(0x20000, -1, "lng", gszLngPath_007A0710, sizeof(gszLngPath_007A0710), 0, 0, 0);
    return 1;
}

// 0x00451850
void __cdecl sub_00451850_FreeMsgRecordChunks()
{
    D2MsgRecordChunkStrc* pChunk = gpMsgRecordChunkHead_007A2760;
    while (pChunk)
    {
        D2MsgRecordChunkStrc* pFree = pChunk;
        pChunk = pChunk->pNext;
        sub_0040B3C0(pFree, ".\\GAME\\Record.cpp", 0x120, 0);
    }
}

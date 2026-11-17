struct D2ArchiveHandleStrc;

int __cdecl sub_00406D20();                                                                              // 0x00406D20
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332
void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle);                                     // 0x005173AC

extern "C" const char gszExpansionMpq_006CD3A0[];                                                           // 0x006CD3A0
extern "C" const char szPatchD2Mpq_006DC728[];                                                              // 0x006DC728
extern "C" const char szD2SfxMpq_006DC764[];                                                                // 0x006DC764
extern "C" const char szD2DataMpq_006DC770[];                                                               // 0x006DC770
D2ArchiveHandleStrc* gpD2XMusicMPQ;                                                                         // 0x007D5604
D2ArchiveHandleStrc* gpD2SfxMPQ;                                                                            // 0x007D5608
D2ArchiveHandleStrc* gpD2DeltaMPQ;                                                                          // 0x007D560C
extern D2ArchiveHandleStrc* gpD2CharMPQ;                                                                    // 0x007D5610
D2ArchiveHandleStrc* gpD2VideoMPQ;                                                                          // 0x007D5614
extern D2ArchiveHandleStrc* gpD2XTalkMPQ;                                                                   // 0x007D5618
D2ArchiveHandleStrc* gpD2DataMPQ;                                                                           // 0x007D561C
D2ArchiveHandleStrc* gpD2kfixupMPQ;                                                                         // 0x007D5620
D2ArchiveHandleStrc* gpD2SpeechMPQ;                                                                         // 0x007D5624
extern D2ArchiveHandleStrc* gpD2MusicMPQ;                                                                   // 0x007D5628
extern D2ArchiveHandleStrc* gpD2XVideoMPQ;                                                                  // 0x007D562C
D2ArchiveHandleStrc* gpD2PatchMPQ;                                                                          // 0x007D5630
D2ArchiveHandleStrc* gpD2ExpMPQ;                                                                            // 0x007D5634

// 0x004FAB90
int __cdecl ARCHIVE_LoadArchives()
{
    gpD2DataMPQ = sub_00517332_LoadMpqFile(szD2DataMpq_006DC770, 0, 0, 1000);
    gpD2SfxMPQ = sub_00517332_LoadMpqFile(szD2SfxMpq_006DC764, 0, 0, 1000);
    gpD2SpeechMPQ = sub_00517332_LoadMpqFile("d2speech.mpq", 0, 0, 1000);
    gpD2DeltaMPQ = sub_00517332_LoadMpqFile("d2delta.mpq", 0, 0, 1000);
    gpD2kfixupMPQ = sub_00517332_LoadMpqFile("d2kfixup.mpq", 0, 0, 1000);
    gpD2PatchMPQ = sub_00517332_LoadMpqFile(szPatchD2Mpq_006DC728, 0, 0, 5000);
    gpD2ExpMPQ = sub_00517332_LoadMpqFile(gszExpansionMpq_006CD3A0, 0, 0, 3000);

    return sub_00406D20() || gpD2DataMPQ && gpD2SfxMPQ && gpD2SpeechMPQ && (!sub_00408F20_HasExpansionMpq() || gpD2ExpMPQ);
}

// 0x004FAC80
void* __stdcall D2Win_GetArchive()
{
    return 0;
}

// 0x004FAD70
void __cdecl ARCHIVE_UnloadExpansionArchives()
{
    if (gpD2MusicMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2MusicMPQ);
        gpD2MusicMPQ = 0;
    }

    if (gpD2CharMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2CharMPQ);
        gpD2CharMPQ = 0;
    }

    if (gpD2VideoMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2VideoMPQ);
        gpD2VideoMPQ = 0;
    }

    if (gpD2XMusicMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XMusicMPQ);
        gpD2XMusicMPQ = 0;
    }

    if (gpD2XTalkMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XTalkMPQ);
        gpD2XTalkMPQ = 0;
    }

    if (gpD2XVideoMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XVideoMPQ);
        gpD2XVideoMPQ = 0;
    }
}

// 0x004FAE00
void __cdecl ARCHIVE_FreeArchives()
{
    if (gpD2DataMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2DataMPQ);
        gpD2DataMPQ = 0;
    }

    if (gpD2SpeechMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2SpeechMPQ);
        gpD2SpeechMPQ = 0;
    }

    if (gpD2SfxMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2SfxMPQ);
        gpD2SfxMPQ = 0;
    }

    if (gpD2DeltaMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2DeltaMPQ);
        gpD2DeltaMPQ = 0;
    }

    if (gpD2kfixupMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2kfixupMPQ);
        gpD2kfixupMPQ = 0;
    }

    if (gpD2ExpMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2ExpMPQ);
        gpD2ExpMPQ = 0;
    }

    if (gpD2XMusicMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2XMusicMPQ);
        gpD2XMusicMPQ = 0;
    }

    if (gpD2PatchMPQ)
    {
        ARCHIVE_UnloadMPQFile(gpD2PatchMPQ);
        gpD2PatchMPQ = 0;
    }

    ARCHIVE_UnloadExpansionArchives();
}

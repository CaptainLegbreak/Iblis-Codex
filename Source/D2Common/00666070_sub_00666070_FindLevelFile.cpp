struct D2DrlgFileStrc;

struct D2LevelFileListStrc
{
    char szPath[0x104];
    long nRefCount;
    D2DrlgFileStrc* pFile;
    D2LevelFileListStrc* pNext;
};

struct D2DrlgRoomSubStrc
{
    char unk0x00[0xEC];
    int nFieldEC;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgRoomSubStrc* pSub20;
};

extern D2LevelFileListStrc* gpLevelFilesList;                                                               // 0x0096D60C

// 0x00666070
static __forceinline void sub_00666070_FindLevelFile(D2DrlgFileStrc** ppDrlgFile, D2LevelFileListStrc** ppPrevious, D2LevelFileListStrc** ppCurrent)
{
    D2LevelFileListStrc* pFirst = gpLevelFilesList;
    *ppPrevious = 0;
    for (*ppCurrent = pFirst; *ppCurrent; *ppCurrent = (*ppCurrent)->pNext)
    {
        if ((*ppCurrent)->pFile == *ppDrlgFile)
        {
            return;
        }
        *ppPrevious = *ppCurrent;
    }
}

void __stdcall sub_M121_Emit_00666070(D2DrlgFileStrc** ppDrlgFile, D2LevelFileListStrc** ppPrevious, D2LevelFileListStrc** ppCurrent)
{
    sub_00666070_FindLevelFile(ppDrlgFile, ppPrevious, ppCurrent);
}

// 0x00666FF0
int __fastcall sub_00666FF0_GetRoomSubFieldEC(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pSub20->nFieldEC;
}

typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;
struct Archive;
extern "C" const U16* __fastcall sub_00524A30_GetLocaleString(U16 id);
extern "C" int __stdcall sub_0043A460_CreateNotice(const U16* title,const U16* text,U32 state,U8 selector);
extern "C" void __fastcall sub_00478A00_CloseArchive(Archive* archive);
extern "C" int __fastcall sub_00469D90_HasBinding(U32 action,U32 selector);
extern "C" U16 __fastcall sub_00469AA0_GetBinding(U32 action,U32 selector);
extern "C" U32 gNoticeMode;
extern "C" U32 gNoticeCount;
extern "C" U32 gSelectedNotice;
extern "C" Archive* gArchiveA; // 0x007BF071
extern "C" Archive* gArchiveB; // 0x007BF075
extern "C" Archive* gArchiveC; // 0x007BF079
extern "C" Archive* gArchiveD;
extern "C" Archive* gArchiveE;
extern "C" Archive* gArchiveF;
extern "C" U32 gPrimaryBinding;
extern "C" U32 gSecondaryBinding;

// 0x0049C650
extern "C" void __cdecl sub_0049C650_CloseArchives()
{
    if(gArchiveA) {
        sub_00478A00_CloseArchive(gArchiveA);
        gArchiveA=(Archive*)0;
    }
    if(gArchiveB) {
        sub_00478A00_CloseArchive(gArchiveB);
        gArchiveB=(Archive*)0;
    }
    if(gArchiveC) {
        sub_00478A00_CloseArchive(gArchiveC);
        gArchiveC=(Archive*)0;
    }
}

// 0x0049FE10
extern "C" void __cdecl sub_0049FE10_CloseArchives()
{
    if(gArchiveD) {
        sub_00478A00_CloseArchive(gArchiveD);
        gArchiveD=(Archive*)0;
    }
    if(gArchiveE) {
        sub_00478A00_CloseArchive(gArchiveE);
        gArchiveE=(Archive*)0;
    }
    if(gArchiveF) {
        sub_00478A00_CloseArchive(gArchiveF);
        gArchiveF=(Archive*)0;
    }
}

extern "C" void __cdecl sub_004B7C60_RefreshBindings()
{
    if(sub_00469D90_HasBinding(38,1)) {
        U32 key=sub_00469AA0_GetBinding(38,1);
        if((U16)key!=0xffff && (U16)key<=0xdf)
            gPrimaryBinding=(U16)key;
    }
    if(sub_00469D90_HasBinding(38,0)) {
        U32 key=sub_00469AA0_GetBinding(38,0);
        if((U16)key!=0xffff && (U16)key<=0xdf)
            gSecondaryBinding=(U16)key;
    }
}

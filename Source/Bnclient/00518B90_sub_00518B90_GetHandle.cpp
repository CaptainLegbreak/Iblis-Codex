void __stdcall SLogClose(void* hLog);                                                                       // 0x0041FD00
void __cdecl sub_00520200_DeleteQueueLock();                                                                // 0x00520200
void* gpField00Arg_0088185C;                                                                                // 0x0088185C

struct D2BnLogStrc
{
    void* hLog;

    ~D2BnLogStrc();
    void* sub_00518B90_GetHandle();
};

// 0x00518B80
D2BnLogStrc::~D2BnLogStrc()
{
    SLogClose(hLog);
}

// 0x00518B90
void* D2BnLogStrc::sub_00518B90_GetHandle()
{
    return hLog;
}

// 0x00518BC0
void __fastcall sub_00518BC0_Field00(void* pArg)
{
    gpField00Arg_0088185C = pArg;
}

// 0x00518C20
void __cdecl sub_00518C20_DeleteQueueLock()
{
    sub_00520200_DeleteQueueLock();
}

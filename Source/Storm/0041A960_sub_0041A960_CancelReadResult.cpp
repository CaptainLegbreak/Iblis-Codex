void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
int __stdcall sub_0041A300_CancelRequests(void* pBuffer, void* pOther);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x0041A960
int __stdcall sub_0041A960_CancelReadResult(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEEND;

    if (nValid)
        return sub_0041A300_CancelRequests(pBuffer, 0);
    return 0;
}

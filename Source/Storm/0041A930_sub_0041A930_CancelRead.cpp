void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
int __stdcall sub_0041A300_CancelRequests(void* pBuffer, void* pOther);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

// 0x0041A930
void __stdcall sub_0041A930_CancelRead(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEENDVOID;

    if (nValid)
        sub_0041A300_CancelRequests(pBuffer, 0);
}

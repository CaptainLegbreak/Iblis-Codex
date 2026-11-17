void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern unsigned int gnReadUnit_00708348;                                                                    // 0x00708348

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

// 0x00416570
void __stdcall SFileSetDataChunkSize(int nChunkSize)
{
    VALIDATEBEGIN;
    VALIDATE(!(nChunkSize & (nChunkSize - 1)));
    VALIDATEENDVOID;
    if (nValid)
        gnReadUnit_00708348 = nChunkSize;
}

// 0x00416710
int __stdcall SFileUnloadFile(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEEND;
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1407, 0);
    return nValid ? 1 : 0;
}

#include "gen/data/Source/Storm/00416570_SFileSetDataChunkSize.inc"

#define OPTION_BIAS 0
#define OUTPUT_BYTES 4
#define ERROR_INVALID 0x57
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
int gnErrorOutputMode_0077909C;         // 0x0077909C
int gnOption_007790A0;         // 0x007790A0
int gnFlag_00779098;         // 0x00779098
int gbAlignReads_007790A4;         // 0x007790A4
extern int gbSLogDebugOutput_007790AC;  // 0x007790AC
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(ERROR_INVALID); return 0; }
// 0x0041BF00
int __stdcall StormSetOption(unsigned int nOption, void* pOutput, unsigned int* pSize)
{
    VALIDATEBEGIN;
    VALIDATE(pOutput);
    VALIDATE(pSize);
    VALIDATEEND;
    sub_0041C340_SetLastError(ERROR_INVALID);
    switch (nOption)
    {
    case 1 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gnErrorOutputMode_0077909C;
        *pSize = OUTPUT_BYTES;
        break;
    case 2 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gnOption_007790A0;
        *pSize = OUTPUT_BYTES;
        break;
    case 3 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gnFlag_00779098;
        *pSize = OUTPUT_BYTES;
        break;
    case 4 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gbAlignReads_007790A4;
        *pSize = OUTPUT_BYTES;
        break;
    case 5 + OPTION_BIAS:
        if (*pSize < OUTPUT_BYTES) return 0;
        *(int*)pOutput = gbSLogDebugOutput_007790AC;
        *pSize = OUTPUT_BYTES;
        break;
    }
    sub_0041C340_SetLastError(0);
    return nValid ? 1 : 0;
}

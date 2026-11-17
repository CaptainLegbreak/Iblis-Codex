#ifdef MOVED_TEST
#define OPTION_BIAS 2
#define INPUT_INDEX 1
#define ERROR_INVALID 0x59
#else
#define OPTION_BIAS 0
#define INPUT_INDEX 0
#define ERROR_INVALID 0x57
#endif
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
extern int gnErrorOutputMode_0077909C;  // 0x0077909C
extern int gnOption_007790A0;  // 0x007790A0
extern int gnFlag_00779098;  // 0x00779098
extern int gbAlignReads_007790A4;  // 0x007790A4
extern int gbSLogDebugOutput_007790AC;  // 0x007790AC
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(ERROR_INVALID); return 0; }
// 0x0041BFC0
int __stdcall sub_0041BFC0(unsigned int nOption, const void* pInput, unsigned int nSize)
{
    VALIDATEBEGIN;
    VALIDATE(pInput);
    VALIDATEEND;
    sub_0041C340_SetLastError(ERROR_INVALID);
    switch (nOption)
    {
    case 1 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gnErrorOutputMode_0077909C = ((const int*)pInput)[INPUT_INDEX];
        break;
    case 2 + OPTION_BIAS:
        {
            if (nSize != sizeof(int)) return 0;
            unsigned int nValue = ((const unsigned int*)pInput)[INPUT_INDEX];
            if (!nValue || ((nValue - 1) ^ nValue) != (nValue + nValue - 1)) return 0;
            gnOption_007790A0 = nValue;
            break;
        }
    case 3 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gnFlag_00779098 = ((const int*)pInput)[INPUT_INDEX];
        break;
    case 4 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gbAlignReads_007790A4 = ((const int*)pInput)[INPUT_INDEX];
        break;
    case 5 + OPTION_BIAS:
        if (nSize != sizeof(int)) return 0;
        gbSLogDebugOutput_007790AC = ((const int*)pInput)[INPUT_INDEX];
        break;
    }
    sub_0041C340_SetLastError(0);
    return nValid ? 1 : 0;
}

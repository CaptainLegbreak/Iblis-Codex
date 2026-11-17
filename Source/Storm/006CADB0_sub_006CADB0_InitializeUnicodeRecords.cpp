struct Unicode { unsigned short wChar; };
typedef void (__fastcall* D2UnicodeConstructor)(Unicode*);
void __fastcall sub_0042F530_ClearUnicode(Unicode* pChar); // 0x0042F530
void __stdcall sub_00403040_VectorConstruct(void* pArray, unsigned int nElementSize, int nCount, D2UnicodeConstructor pConstructor); // 0x00403040
unsigned char gaRecords_007C54BC[260];     // 0x007C54BC

// 0x006CADB0
void __cdecl sub_006CADB0_InitializeUnicodeRecords()
{
    int nRemaining = 31;
    unsigned char* pRecord = gaRecords_007C54BC;
    do
    {
        sub_00403040_VectorConstruct(pRecord, 2, 128, sub_0042F530_ClearUnicode);
        pRecord += 0x120;
    }
    while (--nRemaining >= 0);
}

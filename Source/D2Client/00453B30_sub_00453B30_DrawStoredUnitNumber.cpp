struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch)
    {
    }
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
};

struct D2StoredUnitRecordStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC

int __cdecl sub_0047A980_IsNumberDisplayEnabled();                                                          // 0x0047A980
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRecord(int nUnitId);                                    // 0x00479BB0
int __fastcall sub_00479B80_GetRecordValue(D2StoredUnitRecordStrc* pRecord);                               // 0x00479B80
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00453B30
void __cdecl sub_00453B30_DrawStoredUnitNumber()
{
    if (!sub_0047A980_IsNumberDisplayEnabled())
    {
        return;
    }

    D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
    if (!pUnit)
    {
        return;
    }

    D2StoredUnitRecordStrc* pRecord = sub_00479BB0_FindRecord(pUnit->dwUnitId);
    if (!pRecord)
    {
        return;
    }

    const int nValue = sub_00479B80_GetRecordValue(pRecord);
    char szText[12];
    Unicode wszText[12];
    wsprintfA(szText, gszFormatD_006D57BC, nValue);
    sub_00526F20_ToUnicode(wszText, szText, 12);
    sub_00502320(wszText, 600, 25, 4, 0);
}

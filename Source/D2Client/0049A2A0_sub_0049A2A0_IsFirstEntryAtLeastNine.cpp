struct D2StoredUnitRecordStrc;

D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);              // 0x004795A0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90

// 0x0049A2A0
int __cdecl sub_0049A2A0_IsFirstEntryAtLeastNine()
{
    return sub_00479B90(sub_004795A0_GetNextEntry(0)) >= 9;
}

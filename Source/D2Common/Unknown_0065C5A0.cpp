#ifdef MOVED_TEST
#define TABLE_PREFIX 0xA8
#else
#define TABLE_PREFIX 0xA4
#endif
struct D2PropertiesTxt
{
    unsigned short wProp;
    unsigned char nSet[7];
    char unk0x09;
    unsigned short wVal[7];
    unsigned char nFunc[7];
    char unk0x1F;
    unsigned short wStat[7];
};
struct D2DataTablesStrc
{
    char unk0x000[TABLE_PREFIX];
    D2PropertiesTxt* pPropertiesTxt;
    char unk0x0A8[0x04];
    int nPropertiesTxtRecordCount;
    char unk0x0B0[0xAF0];
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
// 0x0065C5A0
const D2PropertiesTxt* __fastcall sub_0065C5A0_GetPropertiesTxtRecord(int nProperty) {
 if (nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount) {
  return &sgptDataTables->pPropertiesTxt[nProperty];
 }
 return 0;
}

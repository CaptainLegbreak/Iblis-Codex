#include "D2DataTbls.h"
#define TABLE_PREFIX 0xA4
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
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
// 0x0065C5A0
const D2PropertiesTxt* __fastcall sub_0065C5A0_GetPropertiesTxtRecord(int nProperty) {
 if (nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount) {
  return &sgptDataTables->pPropertiesTxt[nProperty];
 }
 return 0;
}

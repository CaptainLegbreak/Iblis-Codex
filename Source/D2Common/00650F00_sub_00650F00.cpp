struct D2UnitStrc;
struct D2InventoryStrc;
struct D2AnimDataRecordStrc
{
    char name[8];
    unsigned int frames;
    unsigned int animSpeed;
};
struct D2MonStatsTxt
{
    short id;
    short baseId;
    char pad04[0x2E];
    short velocity;
    short run;
    short walkAnimSpeed;
    short runAnimSpeed;
    char pad3A[0x16E];
};
extern D2MonStatsTxt* gpMonStatsTxt; // 0x0096C6A8
const D2AnimDataRecordStrc* __fastcall DATATBLS_GetAnimDataRecord(D2UnitStrc*, int, int, int, D2InventoryStrc*); // 0x0066A9B0

// 0x00650F00
void __stdcall sub_00650F00(int nRecordCount)
{
    int i = 0;
    if (nRecordCount <= 0) return;
    do
    {
        int base = gpMonStatsTxt[i].baseId;
        if (base < 0 || base >= nRecordCount)
        {
            gpMonStatsTxt[i].baseId = i;
            base = i;
        }

        const D2AnimDataRecordStrc* pAnimDataRecord = DATATBLS_GetAnimDataRecord(0, base, 2, 1, 0);
        unsigned int speed = pAnimDataRecord->animSpeed;
        if (base != i && gpMonStatsTxt[base].velocity > 0)
            speed = gpMonStatsTxt[i].velocity * speed / gpMonStatsTxt[base].velocity;
        speed = speed > 0 ? speed : 0;
        gpMonStatsTxt[i].walkAnimSpeed = speed < 0x7FFF ? speed : 0x7FFF;

        if (i >= 410)
            speed = DATATBLS_GetAnimDataRecord(0, base, 15, 1, 0)->animSpeed;
        else
            speed = gpMonStatsTxt[base].walkAnimSpeed / 2;
        if (base != i && gpMonStatsTxt[base].run > 0)
            speed = gpMonStatsTxt[i].run * speed / gpMonStatsTxt[base].run;
        speed = speed > 0 ? speed : 0;
        gpMonStatsTxt[i].runAnimSpeed = speed < 0x7FFF ? speed : 0x7FFF;
        ++i;
    } while (i < nRecordCount);
}

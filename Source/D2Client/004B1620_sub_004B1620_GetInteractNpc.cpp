struct D2UnitStrc;
struct D2BitBufferStrc;

struct D2ClientObjectStrc
{
    virtual void Destroy(int bFree) = 0;
};

extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern D2BitBufferStrc* gpQuestFlags_007C0D43;                                                              // 0x007C0D43
extern D2BitBufferStrc* gpQuestFlags_007C0D47;                                                              // 0x007C0D47
extern void* gpRes_007C0D5F;                                                                                // 0x007C0D5F
extern void* gpRes_007C0D63;                                                                                // 0x007C0D63
extern void* gpRes_007C0D67;                                                                                // 0x007C0D67
extern void* gpRes_007C0D6B;                                                                                // 0x007C0D6B
extern void* gpRes_007C0D6F;                                                                                // 0x007C0D6F
extern void* gpRes_007C0D73;                                                                                // 0x007C0D73
extern void* gpRes_007C0D77;                                                                                // 0x007C0D77
extern void* gpRes_007C0D7B;                                                                                // 0x007C0D7B
extern D2ClientObjectStrc* gpObject_007C0D83;                                                               // 0x007C0D83
void* gpCelFile_007C0DC8;                                                                                   // 0x007C0DC8
void* gpCelFile_007C0DCC;                                                                                   // 0x007C0DCC

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                            // 0x00463990
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord);                      // 0x0065C490

// 0x004B1620
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc()
{
    if (gnGlobal_007C0D29)
    {
        return sub_00463990(gnGlobal_007C0D25, 1);
    }
    return 0;
}

// 0x004B24A0
void __cdecl sub_004B24A0()
{
    QUESTRECORD_FreeRecord(0, gpQuestFlags_007C0D43);
    QUESTRECORD_FreeRecord(0, gpQuestFlags_007C0D47);
    gpQuestFlags_007C0D43 = 0;
    gpQuestFlags_007C0D47 = 0;

    if (gpCelFile_007C0DC8)
    {
        sub_00478A00(gpCelFile_007C0DC8);
        gpCelFile_007C0DC8 = 0;
    }
    if (gpCelFile_007C0DCC)
    {
        sub_00478A00(gpCelFile_007C0DCC);
        gpCelFile_007C0DCC = 0;
    }
    if (gpObject_007C0D83)
    {
        gpObject_007C0D83->Destroy(1);
        gpObject_007C0D83 = 0;
    }
    if (gpRes_007C0D5F) { sub_004B8020(gpRes_007C0D5F); gpRes_007C0D5F = 0; }
    if (gpRes_007C0D63) { sub_004B8020(gpRes_007C0D63); gpRes_007C0D63 = 0; }
    if (gpRes_007C0D67) { sub_004B8020(gpRes_007C0D67); gpRes_007C0D67 = 0; }
    if (gpRes_007C0D6B) { sub_004B8020(gpRes_007C0D6B); gpRes_007C0D6B = 0; }
    if (gpRes_007C0D77) { sub_004B8020(gpRes_007C0D77); gpRes_007C0D77 = 0; }
    if (gpRes_007C0D7B) { sub_004B8020(gpRes_007C0D7B); gpRes_007C0D7B = 0; }
    if (gpRes_007C0D6F) { sub_004B8020(gpRes_007C0D6F); gpRes_007C0D6F = 0; }
    if (gpRes_007C0D73) { sub_004B8020(gpRes_007C0D73); gpRes_007C0D73 = 0; }
}

struct D2AnimSeqTxt;
struct D2AnimDataRecordStrc
{
    char unk_00[0x10];
    unsigned char nFrameFlags[144];
};
struct D2UnitStrc
{
    int nUnitType;
    char dwClassId[0x0C];
    int nAnimMode;
    char unk_14[0x3C];
    D2AnimDataRecordStrc* pAnimData;
};
extern const char gszEmptyAssertText; // 0x006CC837
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc*); // 0x006633B0
void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt*, int, int, int*, int*, int*, int*); // 0x00663410

// 0x00621920
int __stdcall sub_00621920_GetEventFrameInfo(D2UnitStrc* pUnit, int nFrame)
{
    if (!pUnit)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDCC);
        exit(-1);
    }
    if (nFrame >= 144)
        return 0;

    int bSequence = 0;
    switch (pUnit->nUnitType)
    {
    case 0:
        if (pUnit->nAnimMode == 18)
            bSequence = 1;
    case 1:
        if (pUnit->nAnimMode == 14)
            break;
        if (bSequence)
            break;
    default:
        return pUnit->pAnimData->nFrameFlags[nFrame];
    }
    int nMode;
    int nSequenceFrame;
    int nDirection;
    int nEvent;
    D2AnimSeqTxt* pSequence = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    DATATBLS_ComputeSequenceAnimation(pSequence, nFrame << 8, nFrame << 8, &nMode, &nSequenceFrame, &nDirection, &nEvent);
    return nEvent;
}

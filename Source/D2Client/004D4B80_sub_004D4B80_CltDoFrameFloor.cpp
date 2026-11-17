struct D2UnitStrc;

int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0

// 0x004D4B80
void __fastcall sub_004D4B80_CltDoFrameFloor(D2UnitStrc* pMissile)
{
    if (sub_0064A380_GetRemainingFrames(pMissile) < 100)
    {
        MISSILE_SetCurrentFrame(pMissile, 500);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

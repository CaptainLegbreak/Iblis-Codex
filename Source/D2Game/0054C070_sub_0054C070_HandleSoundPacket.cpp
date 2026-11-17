struct D2GameStrc;
struct D2UnitStrc { char unk_00[0xC4]; unsigned int dwFlags; };
void __fastcall SUNIT_AttachSound(D2UnitStrc*, int, int); // 0x00553380
static __forceinline int HasSoundFlag(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwFlags >> 10) & 1 : 0;
}

// 0x0054C070
int __fastcall sub_0054C070_HandleSoundPacket(D2GameStrc* pGame, D2UnitStrc* pUnit, const unsigned char* pPacket, int nSize)
{
    if (nSize != 3)
        return 3;
    unsigned int nSound = *(const unsigned short*)(pPacket + 1);
    if (nSound >= 25 && nSound <= 32)
    {
        if (!HasSoundFlag(pUnit))
            SUNIT_AttachSound(pUnit, nSound, 0);
        else
            return 1;
    }
    return 0;
}

#include "D2Game.h"

struct T00534330
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
};

struct D2SaveHeaderStrc
{
    T00534330 tFileHeader;
    unsigned int dwSize;
};

int __fastcall sub_00534020_ReadSaveOld(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00534020
int __fastcall sub_0056B180_ReadSaveNew(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0056B180

// 0x00534330
int __fastcall sub_00534330(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    if (nSize < 8)
    {
        return 9;
    }

    const T00534330 tHeader = pSave->tFileHeader;
    if (tHeader.dwHeaderMagic != 0xAA55AA55)
    {
        return 9;
    }

    if (tHeader.dwVersion <= 0x5B)
    {
        return sub_00534020_ReadSaveOld(pGame, pClient, pSave, nSize, ppPlayer, pRoom, nX, nY);
    }

    return sub_0056B180_ReadSaveNew(pGame, pClient, pSave, nSize, ppPlayer, pRoom, nX, nY);
}

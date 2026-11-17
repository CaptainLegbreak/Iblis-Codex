extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2ActiveRoomStrc;

D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
extern int gnUiRecordIndex_00722354;                                                                        // 0x00722354
int gnLevelTimer_007BEFEC;                                                                                  // 0x007BEFEC
int gnLevelId_007BEFF0;                                                                                     // 0x007BEFF0

// 0x00498310
void __cdecl sub_00498310_UpdateLevelTimer()
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (gnLevelId_007BEFF0 != nLevelId)
        {
            gnLevelId_007BEFF0 = nLevelId;
            gnLevelTimer_007BEFEC = 0x3C;
        }
    }
}

// 0x00498D90
void __fastcall sub_00498D90_SetUiRecordIndex(int nIndex)
{
    if (nIndex >= 0)
    {
        gnUiRecordIndex_00722354 = nIndex;
        return;
    }
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xB07);
    exit(-1);
}

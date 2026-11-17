struct D2ClientStrc;
struct D2UnitStrc { char prefix[0xC8]; unsigned int dwFlagEx; };
struct D2PlayerTradeStrc { char prefix[0x14]; unsigned int nNextUpdateTick; };
struct D2PlayerDataStrc {
    char prefix[0x50]; int dwTradeState; int unknown54;
    unsigned int dwAcceptTradeTick; D2PlayerTradeStrc* pTrade;
};
struct D2GameStrc { char prefix[0xA8]; unsigned int dwGameFrame; };
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();  // 0x006CC260
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*);  // 0x006221A0
void __fastcall EVENT_SetEvent(D2GameStrc*,D2UnitStrc*,int,int,int,int);  // 0x005417D0
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc*,int*,int*);  // 0x00554100
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int);  // 0x00552F60
int __fastcall sub_00597A20_IsBusy(D2GameStrc*,D2UnitStrc*);
void __fastcall sub_6FC91050(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,D2PlayerDataStrc*,D2PlayerDataStrc*,int);  // 0x005679E0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int);  // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc*,unsigned char);  // 0x0053CAB0

// 0x005689D0
void __fastcall sub_005689D0(D2GameStrc* game,D2UnitStrc* player,int unused1,int unused2)
{
    D2PlayerDataStrc* data=UNITS_GetPlayerData(player);
    if (data->dwTradeState<=4) return;
    if (data->dwTradeState==7) {
        data->dwTradeState=8;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    }
    if (data->dwTradeState==14) {
        data->dwTradeState=15;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    }
    D2PlayerTradeStrc* trade=data->pTrade;
    if (data->dwTradeState==8) {
        if (player) player->dwFlagEx &= ~0x00400000u;
        if (trade->nNextUpdateTick) {
            data->dwTradeState=11;
            EVENT_SetEvent(game,player,0xD,game->dwGameFrame+125,0,0);
        } else {
            data->dwTradeState=3;
        }
        return;
    }
    if (data->dwTradeState==15) {
        if (player) player->dwFlagEx &= ~0x00400000u;
        data->dwTradeState=16;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+5,0,0);
        return;
    }
    if (data->dwTradeState==16) {
        int type,id;
        if (SUNIT_GetInteractInfo(player,&type,&id) && type==0) {
            D2UnitStrc* other=SUNIT_GetServerUnit(game,0,id);
            if (other) {
                D2PlayerDataStrc* first=UNITS_GetPlayerData(player);
                D2PlayerDataStrc* second=UNITS_GetPlayerData(other);
                if ((first->dwTradeState==2 || first->dwTradeState==1)
                    && (second->dwTradeState==2 || second->dwTradeState==1)) {
                    sub_6FC91050(game,player,other,first,second,12);
                    const unsigned int tick=GetTickCount();
                    second->dwAcceptTradeTick=tick;
                    first->dwAcceptTradeTick=tick;
                    return;
                } else if (!sub_00597A20_IsBusy(game,player) && !sub_00597A20_IsBusy(game,other)) {
                    sub_6FC91050(game,player,other,first,second,12);
                    const unsigned int tick=GetTickCount();
                    second->dwAcceptTradeTick=tick;
                    first->dwAcceptTradeTick=tick;
                    return;
                }
            }
        }
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+5,0,0);
        return;
    }
    switch (data->dwTradeState) {
    case 11:
        if (trade->nNextUpdateTick < GetTickCount()) {
            data->dwTradeState=3;
            if (player) player->dwFlagEx &= ~0x00C00000u;
            trade->nNextUpdateTick=0;
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(player,".\\PLAYER\\PlrTrade.cpp",0xE95),15);
            return;
        }
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+25,0,0);
        return;
    case 9:
        data->dwTradeState=10;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    case 5:
        data->dwTradeState=6;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    case 6:
        data->dwTradeState=3;
        if (player) player->dwFlagEx &= ~0x00C00000u;
        return;
    case 12:
        data->dwTradeState=13;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+4,0,0);
        return;
    case 10:
    case 13:
        data->dwTradeState=0;
        if (player) player->dwFlagEx &= ~0x00C00000u;
        return;
    }
}

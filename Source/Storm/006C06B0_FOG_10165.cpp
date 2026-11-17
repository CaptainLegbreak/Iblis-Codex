struct QServer;
int __fastcall sub_006C0420_ProcessClient(QServer* pServer, int nClientId, const char* szFile, int nLine); // 0x006C0420
// 0x006C06B0
int __stdcall FOG_10165(QServer* pServer, int nClientId, const char* szFile, int nLine)
{
    return sub_006C0420_ProcessClient(pServer, nClientId, szFile, nLine);
}

struct D2Connection006C3410Strc
{
    unsigned char unk_00[0x10];
    int nSocket10;
};
int __stdcall sub_006B017A_Send(int nSocket, const void* pBuffer, int nLength, int nFlags); // 0x006B017A
int __stdcall sub_006B0168_GetLastError(); // 0x006B0168

// 0x006C3410
int __fastcall sub_006C3410_Send(int nUnused, D2Connection006C3410Strc* pConnection, const void* pBuffer, int nLength)
{
    if (sub_006B017A_Send(pConnection->nSocket10, pBuffer, nLength, 0) == -1)
    {
        sub_006B0168_GetLastError();
        return 0;
    }
    return 1;
}

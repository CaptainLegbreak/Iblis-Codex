extern unsigned char gnSelectModeA_0070CD62; // 0x0070CD62
extern char gnSelectModeB_0070CD63; // 0x0070CD63
extern int gnSelectIdA_0070CD7C; // 0x0070CD7C
extern int gnGlobal_0077B0A0; // 0x0077B0A0

// 0x0043ECE0
int __stdcall sub_0043ECE0_Todo(int a)
{
    gnSelectIdA_0070CD7C -= gnGlobal_0077B0A0;
    unsigned char m = gnSelectModeB_0070CD63;
    gnSelectIdA_0070CD7C &= (gnSelectIdA_0070CD7C <= 0) - 1;
    gnSelectModeA_0070CD62 = m;
    return 1;
}

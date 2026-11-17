struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2MonStats2Txt;

struct D2DataTablesStrc
{
    char unk0x000[0x02C];
    D2TxtLinkStrc* pMonModeLinker;
    char unk0x030[0xA90 - 0x030];
    D2MonStats2Txt* pMonStats2Txt;
    D2TxtLinkStrc* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
    char unk0xA9C[0xB9C - 0xA9C];
    D2TxtLinkStrc* pSkillsLinker;
};

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_ASCIITOCODE = 9,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_NAMETOINDEX = 17,
    TXTFIELD_NAMETOWORD = 20,
    TXTFIELD_CUSTOMLINK = 23,
    TXTFIELD_BIT = 26,
};

extern "C" const char gszTxtField_Id[];                                                             // 0x006E6850
extern "C" const char gszTxtField_Height[];                                                         // 0x006EAA88
extern "C" const char gszTxtField_overlayHeight[];                                                  // 0x006ED120
extern "C" const char gszTxtField_pixHeight[];                                                      // 0x006ED114
extern "C" const char gszTxtField_SizeX[];                                                          // 0x006E8654
extern "C" const char gszTxtField_SizeY[];                                                          // 0x006E864C
extern "C" const char gszTxtField_spawnCol[];                                                       // 0x006ED108
extern "C" const char gszTxtField_MeleeRng[];                                                       // 0x006ED0FC
extern "C" const char gszTxtField_BaseW[];                                                          // 0x006ED0F4
extern "C" const char gszTxtField_HitClass[];                                                       // 0x006E6D10
extern "C" const char gszTxtField_HDv[];                                                            // 0x006ED0F0
extern "C" const char gszTxtField_TRv[];                                                            // 0x006ED0EC
extern "C" const char gszTxtField_LGv[];                                                            // 0x006ED0E8
extern "C" const char gszTxtField_Rav[];                                                            // 0x006ED0E4
extern "C" const char gszTxtField_Lav[];                                                            // 0x006ED0E0
extern "C" const char gszTxtField_RHv[];                                                            // 0x006ED0DC
extern "C" const char gszTxtField_LHv[];                                                            // 0x006ED0D8
extern "C" const char gszTxtField_SHv[];                                                            // 0x006ED0D4
extern "C" const char gszTxtField_S1v[];                                                            // 0x006ED0D0
extern "C" const char gszTxtField_S2v[];                                                            // 0x006ED0CC
extern "C" const char gszTxtField_S3v[];                                                            // 0x006ED0C8
extern "C" const char gszTxtField_S4v[];                                                            // 0x006ED0C4
extern "C" const char gszTxtField_S5v[];                                                            // 0x006ED0C0
extern "C" const char gszTxtField_S6v[];                                                            // 0x006ED0BC
extern "C" const char gszTxtField_S7v[];                                                            // 0x006ED0B8
extern "C" const char gszTxtField_S8v[];                                                            // 0x006ED0B4
extern "C" const char gszTxtField_HD[];                                                             // 0x006EABFC
extern "C" const char gszTxtField_TR[];                                                             // 0x006EABF8
extern "C" const char gszTxtField_LG[];                                                             // 0x006EABF4
extern "C" const char gszTxtField_RA[];                                                             // 0x006EABF0
extern "C" const char gszTxtField_LA[];                                                             // 0x006EABEC
extern "C" const char gszTxtField_RH[];                                                             // 0x006EABE8
extern "C" const char gszTxtField_LH[];                                                             // 0x006EABE4
extern "C" const char gszTxtField_SH[];                                                             // 0x006EABE0
extern "C" const char gszTxtField_S1[];                                                             // 0x006EABDC
extern "C" const char gszTxtField_S2[];                                                             // 0x006EABD8
extern "C" const char gszTxtField_S3[];                                                             // 0x006EABD4
extern "C" const char gszTxtField_S4[];                                                             // 0x006EABD0
extern "C" const char gszTxtField_S5[];                                                             // 0x006EABCC
extern "C" const char gszTxtField_S6[];                                                             // 0x006EABC8
extern "C" const char gszTxtField_S7[];                                                             // 0x006EABC4
extern "C" const char gszTxtField_S8[];                                                             // 0x006EABC0
extern "C" const char gszTxtField_TotalPieces[];                                                    // 0x006EABB4
extern "C" const char gszTxtField_mDT[];                                                            // 0x006ED0B0
extern "C" const char gszTxtField_mNU[];                                                            // 0x006ED0AC
extern "C" const char gszTxtField_mWL[];                                                            // 0x006ED0A8
extern "C" const char gszTxtField_mGH[];                                                            // 0x006ED0A4
extern "C" const char gszTxtField_mA1[];                                                            // 0x006ED0A0
extern "C" const char gszTxtField_mA2[];                                                            // 0x006ED09C
extern "C" const char gszTxtField_mBL[];                                                            // 0x006ED098
extern "C" const char gszTxtField_mSC[];                                                            // 0x006ED094
extern "C" const char gszTxtField_mS1[];                                                            // 0x006ED090
extern "C" const char gszTxtField_mS2[];                                                            // 0x006ED08C
extern "C" const char gszTxtField_mS3[];                                                            // 0x006ED088
extern "C" const char gszTxtField_mS4[];                                                            // 0x006ED084
extern "C" const char gszTxtField_mDD[];                                                            // 0x006ED080
extern "C" const char gszTxtField_mKB[];                                                            // 0x006ED07C
extern "C" const char gszTxtField_mSQ[];                                                            // 0x006ED078
extern "C" const char gszTxtField_mRN[];                                                            // 0x006ED074
extern "C" const char gszTxtField_dDT[];                                                            // 0x006ED070
extern "C" const char gszTxtField_dNU[];                                                            // 0x006ED06C
extern "C" const char gszTxtField_dWL[];                                                            // 0x006ED068
extern "C" const char gszTxtField_dGH[];                                                            // 0x006ED064
extern "C" const char gszTxtField_dA1[];                                                            // 0x006ED060
extern "C" const char gszTxtField_dA2[];                                                            // 0x006ED05C
extern "C" const char gszTxtField_dBL[];                                                            // 0x006ED058
extern "C" const char gszTxtField_dSC[];                                                            // 0x006ED054
extern "C" const char gszTxtField_dS1[];                                                            // 0x006ED050
extern "C" const char gszTxtField_dS2[];                                                            // 0x006ED04C
extern "C" const char gszTxtField_dS3[];                                                            // 0x006ED048
extern "C" const char gszTxtField_dS4[];                                                            // 0x006ED044
extern "C" const char gszTxtField_dDD[];                                                            // 0x006ED040
extern "C" const char gszTxtField_dKB[];                                                            // 0x006ED03C
extern "C" const char gszTxtField_dSQ[];                                                            // 0x006ED038
extern "C" const char gszTxtField_dRN[];                                                            // 0x006ED034
extern "C" const char gszTxtField_A1mv[];                                                           // 0x006ED02C
extern "C" const char gszTxtField_A2mv[];                                                           // 0x006ED024
extern "C" const char gszTxtField_SCmv[];                                                           // 0x006ED01C
extern "C" const char gszTxtField_S1mv[];                                                           // 0x006ED014
extern "C" const char gszTxtField_S2mv[];                                                           // 0x006ED00C
extern "C" const char gszTxtField_S3mv[];                                                           // 0x006ED004
extern "C" const char gszTxtField_S4mv[];                                                           // 0x006ECFFC
extern "C" const char gszTxtField_noGfxHitTest[];                                                   // 0x006ECFEC
extern "C" const char gszTxtField_htTop[];                                                          // 0x006ECFE4
extern "C" const char gszTxtField_htLeft[];                                                         // 0x006ECFDC
extern "C" const char gszTxtField_htWidth[];                                                        // 0x006ECFD4
extern "C" const char gszTxtField_htHeight[];                                                       // 0x006ECFC8
extern "C" const char gszTxtField_restore[];                                                        // 0x006ECFC0
extern "C" const char gszTxtField_automapCel[];                                                     // 0x006ECFB4
extern "C" const char gszTxtField_noMap[];                                                          // 0x006ECFAC
extern "C" const char gszTxtField_noOvly[];                                                         // 0x006ECFA4
extern "C" const char gszTxtField_isSel[];                                                          // 0x006ECF9C
extern "C" const char gszTxtField_alSel[];                                                          // 0x006ECF94
extern "C" const char gszTxtField_noSel[];                                                          // 0x006ECF8C
extern "C" const char gszTxtField_shiftSel[];                                                       // 0x006ECF80
extern "C" const char gszTxtField_corpseSel[];                                                      // 0x006ECF74
extern "C" const char gszTxtField_revive[];                                                         // 0x006ECF6C
extern "C" const char gszTxtField_isAtt[];                                                          // 0x006ECF64
extern "C" const char gszTxtField_large[];                                                          // 0x006ECF5C
extern "C" const char gszTxtField_small[];                                                          // 0x006ECF54
extern "C" const char gszTxtField_soft[];                                                           // 0x006ECF4C
extern "C" const char gszTxtField_critter[];                                                        // 0x006ECF44
extern "C" const char gszTxtField_inert[];                                                          // 0x006ECF3C
extern "C" const char gszTxtField_objCol[];                                                         // 0x006ECF34
extern "C" const char gszTxtField_deadCol[];                                                        // 0x006ECF2C
extern "C" const char gszTxtField_unflatDead[];                                                     // 0x006ECF20
extern "C" const char gszTxtField_shadow[];                                                         // 0x006ECF18
extern "C" const char gszTxtField_noUniqueShift[];                                                  // 0x006ECF08
extern "C" const char gszTxtField_compositeDeath[];                                                 // 0x006ECEF8
extern "C" const char gszTxtField_localBlood[];                                                     // 0x006ECEEC
extern "C" const char gszTxtField_bleed[];                                                          // 0x006ECEE4
extern "C" const char gszTxtField_light[];                                                          // 0x006ECEDC
extern "C" const char gszTxtField_light_r[];                                                        // 0x006E7A7C
extern "C" const char gszTxtField_light_g[];                                                        // 0x006E7A74
extern "C" const char gszTxtField_light_b[];                                                        // 0x006E7A6C
extern "C" const char gszTxtField_Utrans[];                                                         // 0x006EC9A8
extern "C" const char gszTxtField_Utrans_N_[];                                                      // 0x006EC99C
extern "C" const char gszTxtField_Utrans_H_[];                                                      // 0x006EC990
extern "C" const char gszTxtField_Heart[];                                                          // 0x006ECED4
extern "C" const char gszTxtField_BodyPart[];                                                       // 0x006ECEC8
extern "C" const char gszTxtField_InfernoLen[];                                                     // 0x006ECEBC
extern "C" const char gszTxtField_InfernoAnim[];                                                    // 0x006ECEB0
extern "C" const char gszTxtField_InfernoRollback[];                                                // 0x006ECEA0
extern "C" const char gszTxtField_ResurrectMode[];                                                  // 0x006ECE90
extern "C" const char gszTxtField_ResurrectSkill[];                                                 // 0x006ECE80
extern "C" const char gszTxtField_end[];                                                            // 0x006D9060
extern "C" const char gszMonStats2TxtName[];                                                        // 0x006ECE74
extern "C" const char gszMonsterTblsSourceFile[];                                                   // 0x006EBE70
extern D2DataTablesStrc gD2DataTables;                                                             // 0x0096BC30
void __fastcall sub_00657010();                                        // 0x00657010
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                            // 0x006BD040
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0

// 0x006571A0
D2MonStats2Txt* __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_Id, TXTFIELD_NAMETOINDEX, 0, 0, &gD2DataTables.pMonStats2Linker },
        { gszTxtField_Height, TXTFIELD_BYTE, 0, 11, 0 },
        { gszTxtField_overlayHeight, TXTFIELD_BYTE, 0, 12, 0 },
        { gszTxtField_pixHeight, TXTFIELD_BYTE, 0, 13, 0 },
        { gszTxtField_SizeX, TXTFIELD_BYTE, 0, 8, 0 },
        { gszTxtField_SizeY, TXTFIELD_BYTE, 0, 9, 0 },
        { gszTxtField_spawnCol, TXTFIELD_BYTE, 0, 10, 0 },
        { gszTxtField_MeleeRng, TXTFIELD_BYTE, 0, 14, 0 },
        { gszTxtField_BaseW, TXTFIELD_ASCIITOCODE, 0, 16, 0 },
        { gszTxtField_HitClass, TXTFIELD_BYTE, 0, 20, 0 },
        { gszTxtField_HDv, TXTFIELD_CUSTOMLINK, 0, 0, (void*)sub_00657010 },
        { gszTxtField_TRv, TXTFIELD_CUSTOMLINK, 0, 1, (void*)sub_00657010 },
        { gszTxtField_LGv, TXTFIELD_CUSTOMLINK, 0, 2, (void*)sub_00657010 },
        { gszTxtField_Rav, TXTFIELD_CUSTOMLINK, 0, 3, (void*)sub_00657010 },
        { gszTxtField_Lav, TXTFIELD_CUSTOMLINK, 0, 4, (void*)sub_00657010 },
        { gszTxtField_RHv, TXTFIELD_CUSTOMLINK, 0, 5, (void*)sub_00657010 },
        { gszTxtField_LHv, TXTFIELD_CUSTOMLINK, 0, 6, (void*)sub_00657010 },
        { gszTxtField_SHv, TXTFIELD_CUSTOMLINK, 0, 7, (void*)sub_00657010 },
        { gszTxtField_S1v, TXTFIELD_CUSTOMLINK, 0, 8, (void*)sub_00657010 },
        { gszTxtField_S2v, TXTFIELD_CUSTOMLINK, 0, 9, (void*)sub_00657010 },
        { gszTxtField_S3v, TXTFIELD_CUSTOMLINK, 0, 10, (void*)sub_00657010 },
        { gszTxtField_S4v, TXTFIELD_CUSTOMLINK, 0, 11, (void*)sub_00657010 },
        { gszTxtField_S5v, TXTFIELD_CUSTOMLINK, 0, 12, (void*)sub_00657010 },
        { gszTxtField_S6v, TXTFIELD_CUSTOMLINK, 0, 13, (void*)sub_00657010 },
        { gszTxtField_S7v, TXTFIELD_CUSTOMLINK, 0, 14, (void*)sub_00657010 },
        { gszTxtField_S8v, TXTFIELD_CUSTOMLINK, 0, 15, (void*)sub_00657010 },
        { gszTxtField_HD, TXTFIELD_BIT, 0, 232, 0 },
        { gszTxtField_TR, TXTFIELD_BIT, 1, 232, 0 },
        { gszTxtField_LG, TXTFIELD_BIT, 2, 232, 0 },
        { gszTxtField_RA, TXTFIELD_BIT, 3, 232, 0 },
        { gszTxtField_LA, TXTFIELD_BIT, 4, 232, 0 },
        { gszTxtField_RH, TXTFIELD_BIT, 5, 232, 0 },
        { gszTxtField_LH, TXTFIELD_BIT, 6, 232, 0 },
        { gszTxtField_SH, TXTFIELD_BIT, 7, 232, 0 },
        { gszTxtField_S1, TXTFIELD_BIT, 8, 232, 0 },
        { gszTxtField_S2, TXTFIELD_BIT, 9, 232, 0 },
        { gszTxtField_S3, TXTFIELD_BIT, 10, 232, 0 },
        { gszTxtField_S4, TXTFIELD_BIT, 11, 232, 0 },
        { gszTxtField_S5, TXTFIELD_BIT, 12, 232, 0 },
        { gszTxtField_S6, TXTFIELD_BIT, 13, 232, 0 },
        { gszTxtField_S7, TXTFIELD_BIT, 14, 232, 0 },
        { gszTxtField_S8, TXTFIELD_BIT, 15, 232, 0 },
        { gszTxtField_TotalPieces, TXTFIELD_BYTE, 0, 236, 0 },
        { gszTxtField_mDT, TXTFIELD_BIT, 0, 240, 0 },
        { gszTxtField_mNU, TXTFIELD_BIT, 1, 240, 0 },
        { gszTxtField_mWL, TXTFIELD_BIT, 2, 240, 0 },
        { gszTxtField_mGH, TXTFIELD_BIT, 3, 240, 0 },
        { gszTxtField_mA1, TXTFIELD_BIT, 4, 240, 0 },
        { gszTxtField_mA2, TXTFIELD_BIT, 5, 240, 0 },
        { gszTxtField_mBL, TXTFIELD_BIT, 6, 240, 0 },
        { gszTxtField_mSC, TXTFIELD_BIT, 7, 240, 0 },
        { gszTxtField_mS1, TXTFIELD_BIT, 8, 240, 0 },
        { gszTxtField_mS2, TXTFIELD_BIT, 9, 240, 0 },
        { gszTxtField_mS3, TXTFIELD_BIT, 10, 240, 0 },
        { gszTxtField_mS4, TXTFIELD_BIT, 11, 240, 0 },
        { gszTxtField_mDD, TXTFIELD_BIT, 12, 240, 0 },
        { gszTxtField_mKB, TXTFIELD_BIT, 13, 240, 0 },
        { gszTxtField_mSQ, TXTFIELD_BIT, 14, 240, 0 },
        { gszTxtField_mRN, TXTFIELD_BIT, 15, 240, 0 },
        { gszTxtField_dDT, TXTFIELD_BYTE, 0, 244, 0 },
        { gszTxtField_dNU, TXTFIELD_BYTE, 0, 245, 0 },
        { gszTxtField_dWL, TXTFIELD_BYTE, 0, 246, 0 },
        { gszTxtField_dGH, TXTFIELD_BYTE, 0, 247, 0 },
        { gszTxtField_dA1, TXTFIELD_BYTE, 0, 248, 0 },
        { gszTxtField_dA2, TXTFIELD_BYTE, 0, 249, 0 },
        { gszTxtField_dBL, TXTFIELD_BYTE, 0, 250, 0 },
        { gszTxtField_dSC, TXTFIELD_BYTE, 0, 251, 0 },
        { gszTxtField_dS1, TXTFIELD_BYTE, 0, 252, 0 },
        { gszTxtField_dS2, TXTFIELD_BYTE, 0, 253, 0 },
        { gszTxtField_dS3, TXTFIELD_BYTE, 0, 254, 0 },
        { gszTxtField_dS4, TXTFIELD_BYTE, 0, 255, 0 },
        { gszTxtField_dDD, TXTFIELD_BYTE, 0, 256, 0 },
        { gszTxtField_dKB, TXTFIELD_BYTE, 0, 257, 0 },
        { gszTxtField_dSQ, TXTFIELD_BYTE, 0, 258, 0 },
        { gszTxtField_dRN, TXTFIELD_BYTE, 0, 259, 0 },
        { gszTxtField_A1mv, TXTFIELD_BIT, 4, 260, 0 },
        { gszTxtField_A2mv, TXTFIELD_BIT, 5, 260, 0 },
        { gszTxtField_SCmv, TXTFIELD_BIT, 7, 260, 0 },
        { gszTxtField_S1mv, TXTFIELD_BIT, 8, 260, 0 },
        { gszTxtField_S2mv, TXTFIELD_BIT, 9, 260, 0 },
        { gszTxtField_S3mv, TXTFIELD_BIT, 10, 260, 0 },
        { gszTxtField_S4mv, TXTFIELD_BIT, 11, 260, 0 },
        { gszTxtField_noGfxHitTest, TXTFIELD_BIT, 0, 4, 0 },
        { gszTxtField_htTop, TXTFIELD_WORD, 0, 270, 0 },
        { gszTxtField_htLeft, TXTFIELD_WORD, 0, 272, 0 },
        { gszTxtField_htWidth, TXTFIELD_WORD, 0, 274, 0 },
        { gszTxtField_htHeight, TXTFIELD_WORD, 0, 276, 0 },
        { gszTxtField_restore, TXTFIELD_BYTE, 0, 304, 0 },
        { gszTxtField_automapCel, TXTFIELD_DWORD, 0, 280, 0 },
        { gszTxtField_noMap, TXTFIELD_BIT, 1, 4, 0 },
        { gszTxtField_noOvly, TXTFIELD_BIT, 2, 4, 0 },
        { gszTxtField_isSel, TXTFIELD_BIT, 3, 4, 0 },
        { gszTxtField_alSel, TXTFIELD_BIT, 4, 4, 0 },
        { gszTxtField_noSel, TXTFIELD_BIT, 5, 4, 0 },
        { gszTxtField_shiftSel, TXTFIELD_BIT, 6, 4, 0 },
        { gszTxtField_corpseSel, TXTFIELD_BIT, 7, 4, 0 },
        { gszTxtField_revive, TXTFIELD_BIT, 8, 4, 0 },
        { gszTxtField_isAtt, TXTFIELD_BIT, 9, 4, 0 },
        { gszTxtField_large, TXTFIELD_BIT, 11, 4, 0 },
        { gszTxtField_small, TXTFIELD_BIT, 10, 4, 0 },
        { gszTxtField_soft, TXTFIELD_BIT, 12, 4, 0 },
        { gszTxtField_critter, TXTFIELD_BIT, 13, 4, 0 },
        { gszTxtField_inert, TXTFIELD_BIT, 17, 4, 0 },
        { gszTxtField_objCol, TXTFIELD_BIT, 18, 4, 0 },
        { gszTxtField_deadCol, TXTFIELD_BIT, 19, 4, 0 },
        { gszTxtField_unflatDead, TXTFIELD_BIT, 20, 4, 0 },
        { gszTxtField_shadow, TXTFIELD_BIT, 14, 4, 0 },
        { gszTxtField_noUniqueShift, TXTFIELD_BIT, 15, 4, 0 },
        { gszTxtField_compositeDeath, TXTFIELD_BIT, 16, 4, 0 },
        { gszTxtField_localBlood, TXTFIELD_BYTE, 0, 284, 0 },
        { gszTxtField_bleed, TXTFIELD_BYTE, 0, 285, 0 },
        { gszTxtField_light, TXTFIELD_BYTE, 0, 286, 0 },
        { gszTxtField_light_r, TXTFIELD_BYTE, 0, 287, 0 },
        { gszTxtField_light_g, TXTFIELD_BYTE, 0, 288, 0 },
        { gszTxtField_light_b, TXTFIELD_BYTE, 0, 289, 0 },
        { gszTxtField_Utrans, TXTFIELD_BYTE, 0, 290, 0 },
        { gszTxtField_Utrans_N_, TXTFIELD_BYTE, 0, 291, 0 },
        { gszTxtField_Utrans_H_, TXTFIELD_BYTE, 0, 292, 0 },
        { gszTxtField_Heart, TXTFIELD_ASCIITOCODE, 0, 296, 0 },
        { gszTxtField_BodyPart, TXTFIELD_ASCIITOCODE, 0, 300, 0 },
        { gszTxtField_InfernoLen, TXTFIELD_BYTE, 0, 264, 0 },
        { gszTxtField_InfernoAnim, TXTFIELD_BYTE, 0, 265, 0 },
        { gszTxtField_InfernoRollback, TXTFIELD_BYTE, 0, 266, 0 },
        { gszTxtField_ResurrectMode, TXTFIELD_CODETOBYTE, 0, 267, &gD2DataTables.pMonModeLinker },
        { gszTxtField_ResurrectSkill, TXTFIELD_NAMETOWORD, 0, 268, &gD2DataTables.pSkillsLinker },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    gD2DataTables.pMonStats2Linker = FOG_AllocLinker(gszMonsterTblsSourceFile, 2705);
    return gD2DataTables.pMonStats2Txt = (D2MonStats2Txt*)DATATBLS_CompileTxt(hArchive, gszMonStats2TxtName, pTbl, &gD2DataTables.nMonStats2TxtRecordCount, 308);
}

#include "gen/data/Source/D2Common/006571A0_DATATBLS_LoadMonStats2Txt.inc"

#include "D2Launch.h"

struct D2CelFileStrc;
struct Value;
class BNGatewayAccess;

struct Value { unsigned short value; };

struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode toUpper() const;
};

class BNGatewayAccess
{
public:
    int __stdcall NumGateways();
    int __stdcall CurGateway();

private:
    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
};

extern int gnGatewayValue_007795BC; // 0x007795BC
extern int gbGatewayFlag_00779954; // 0x00779954
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0
extern D2CelFileStrc* gpCellFile_007796F8; // 0x007796F8
extern D2CelFileStrc* gpCellFile_007796FC; // 0x007796FC
extern D2CelFileStrc* gpCellFile_00779704; // 0x00779704
extern D2CelFileStrc* gpCellFile_00779708; // 0x00779708
extern D2CelFileStrc* gpCellFile_0077970C; // 0x0077970C
extern D2CelFileStrc* gpCellFile_00779710; // 0x00779710
extern D2CelFileStrc* gpCellFile_00779714; // 0x00779714
extern D2CelFileStrc* gpCellFile_00779718; // 0x00779718
extern D2CelFileStrc* gpCellFile_0077971C; // 0x0077971C
extern D2CelFileStrc* gpCellFile_00779720; // 0x00779720
extern D2CelFileStrc* gpCellFile_0077972C; // 0x0077972C
extern D2CelFileStrc* gpCellFile_00779730; // 0x00779730
extern D2CelFileStrc* gpCellFile_00779734; // 0x00779734
extern D2CelFileStrc* gpCellFile_00779738; // 0x00779738
extern D2CelFileStrc* gpCellFile_0077973C; // 0x0077973C
extern D2CelFileStrc* gpCellFile_00779740; // 0x00779740
extern D2CelFileStrc* gpCellFile_00779748; // 0x00779748
extern D2CelFileStrc* gpCellFile_0077974C; // 0x0077974C
extern D2CelFileStrc* gpCellFile_00779750; // 0x00779750
extern D2CelFileStrc* gpCellFile_00779754; // 0x00779754
extern D2CelFileStrc* gpCellFile_00779758; // 0x00779758
extern D2CelFileStrc* gpCellFile_0077975C; // 0x0077975C
extern D2CelFileStrc* gpCellFile_00779764; // 0x00779764
extern D2CelFileStrc* gpCellFile_00779768; // 0x00779768
extern D2CelFileStrc* gpCellFile_0077976C; // 0x0077976C
extern D2CelFileStrc* gpCellFile_00779770; // 0x00779770
extern D2CelFileStrc* gpCellFile_00779774; // 0x00779774
extern D2CelFileStrc* gpCellFile_00779778; // 0x00779778
extern D2CelFileStrc* gpCellFile_0077977C; // 0x0077977C
extern D2CelFileStrc* gpCellFile_00779780; // 0x00779780
extern D2CelFileStrc* gpCellFile_00779784; // 0x00779784
extern D2CelFileStrc* gpCellFile_00779788; // 0x00779788
extern D2CelFileStrc* gpCellFile_0077978C; // 0x0077978C
extern D2CelFileStrc* gpCellFile_00779790; // 0x00779790
extern D2CelFileStrc* gpCellFile_00779794; // 0x00779794
extern D2CelFileStrc* gpCellFile_00779798; // 0x00779798
extern D2CelFileStrc* gpCellFile_0077979C; // 0x0077979C
extern D2CelFileStrc* gpCellFile_007797A0; // 0x007797A0
extern D2CelFileStrc* gpCellFile_007797A4; // 0x007797A4
extern D2CelFileStrc* gpCellFile_007797A8; // 0x007797A8
extern D2CelFileStrc* gpCellFile_007797AC; // 0x007797AC
extern D2CelFileStrc* gpCellFile_007797B0; // 0x007797B0
extern D2CelFileStrc* gpCellFile_007797B4; // 0x007797B4
extern D2CelFileStrc* gpCellFile_007797B8; // 0x007797B8
extern D2CelFileStrc* gpCellFile_007797C8; // 0x007797C8
extern D2CelFileStrc* gpCellFile_007797CC; // 0x007797CC
extern D2CelFileStrc* gpCellFile_007797D0; // 0x007797D0
extern D2CelFileStrc* gpCellFile_007797D4; // 0x007797D4
extern D2CelFileStrc* gpCellFile_007797D8; // 0x007797D8
extern D2CelFileStrc* gpCellFile_007797DC; // 0x007797DC
extern D2CelFileStrc* gapCellFiles_007797E0[5]; // 0x007797E0
extern D2CelFileStrc* gapCellFiles_007797F4[5]; // 0x007797F4
extern D2CelFileStrc* gapCellFiles_00779808[5]; // 0x00779808
extern D2CelFileStrc* gapCellFiles_0077981C[5]; // 0x0077981C
extern D2CelFileStrc* gapCellFiles_00779830[5]; // 0x00779830
extern D2CelFileStrc* gapCellFiles_00779844[5]; // 0x00779844
extern D2CelFileStrc* gapCellFiles_00779858[5]; // 0x00779858
extern D2CelFileStrc* gapCellFiles_00779888[3]; // 0x00779888
extern D2CelFileStrc* gapCellFiles_0077989C[3]; // 0x0077989C

// 0x0042E5D0
extern "C" __declspec(dllexport) void __fastcall sub_0042E5D0(unsigned short* pValues, unsigned int nCount) {
    for (unsigned int i = 0; i < nCount; i++) {
        pValues[i] = (unsigned short)((pValues[i] << 8) | (pValues[i] >> 8));
    }
}

// 0x0042E610
extern "C" unsigned short __fastcall sub_0042E610(const Value* object) { return object->value; }

// 0x0042E650
Unicode Unicode::toUpper() const
{
    return Unicode(wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar);
}

// 0x0042E680
int __stdcall BNGatewayAccess::NumGateways()
{
    return m_nNumGateways;
}

// 0x0042E690
int __stdcall BNGatewayAccess::CurGateway()
{
    return m_nCurGateway;
}

// 0x0042E6C0
int __cdecl sub_0042E6C0_GetGatewayFlag()
{
    return gbGatewayFlag_00779954;
}

D2CelFileStrc* gpCellFile_00779700; // 0x00779700

D2CelFileStrc* gpCellFile_00779724; // 0x00779724

D2CelFileStrc* gpCellFile_00779728; // 0x00779728

D2CelFileStrc* gpCellFile_00779744; // 0x00779744

D2CelFileStrc* gpCellFile_007797BC; // 0x007797BC

D2CelFileStrc* gpCellFile_007797C0; // 0x007797C0

D2CelFileStrc* gpCellFile_007797C4; // 0x007797C4

D2CelFileStrc* gpCellFile_007798B0; // 0x007798B0

D2CelFileStrc* gpCellFile_007798C4; // 0x007798C4


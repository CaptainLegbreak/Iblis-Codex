struct Unicode
{
    unsigned short wChar;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00

#pragma pack(push, 2)

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01();

    int unk0x04;
};

class ButtonImplementation : public UIWidget
{
public:
    virtual ~ButtonImplementation();
};

class ButtonWrapper : public UIWidget
{
public:
    virtual ~ButtonWrapper();

    ButtonImplementation* pImpl;
};

class EditBoxImplementation : public UIWidget
{
public:
    virtual ~EditBoxImplementation();

    int nX;
    int nY;
    int nTextX;
    int nTextY;
    int nTextWidth;
    int nHeight;
    int unk0x20;
    int unk0x24;
    Unicode* pText;
    Unicode* pTextCopy;
    int unk0x30;
    unsigned short nMaxLength;
    int unk0x36;
    int unk0x3A;
    int unk0x3E;
    int unk0x42;
    int unk0x46;
    int unk0x4A;
    int nFont;
    void* pCellFile;
    int unk0x56;
};

class EditBoxWrapper : public UIWidget
{
public:
    virtual ~EditBoxWrapper();

    EditBoxImplementation* pImpl;
};

class SpinnerImplementation : public UIWidget
{
public:
    virtual ~SpinnerImplementation();

    int nX;
    int nY;
    int nUpX;
    int nUpY;
    int nDownX;
    int nDownY;
    int unk0x20;
    int nArrowHeight;
    int nArrowWidth;
    int f_2C;
    int unk0x30;
    int unk0x34;
    int unk0x38;
    int unk0x3C;
    int unk0x40;
    int unk0x44[2];
    int unk0x4C;
    void* pCellFile;
};

class SpinnerWrapper : public UIWidget
{
public:
    virtual ~SpinnerWrapper();

    SpinnerImplementation* pImpl;
};

#pragma pack(pop)

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ButtonWrapper@@6B@ 0x006DA72C
// build: symbol ??_7EditBoxImplementation@@6B@ 0x006DA77C
// build: symbol ??_7EditBoxWrapper@@6B@ 0x006DA7CC
// build: symbol ??_7SpinnerImplementation@@6B@ 0x006DA83C
// build: symbol ??_7SpinnerWrapper@@6B@ 0x006DA874
// 0x004BADD0
ButtonWrapper::~ButtonWrapper()
{
    delete pImpl;
}

// 0x004BB170
EditBoxImplementation::~EditBoxImplementation()
{
    if (pText)
    {
        FOG_Free(pText, ".\\UI\\editbox.cpp", 0x8E, 0);
        pText = 0;
    }
    if (pTextCopy)
    {
        FOG_Free(pTextCopy, ".\\UI\\editbox.cpp", 0x93, 0);
        pTextCopy = 0;
    }
    sub_00478A00(pCellFile);
}

// 0x004BB9F0
EditBoxWrapper::~EditBoxWrapper()
{
    delete pImpl;
}

// 0x004BBE10
SpinnerImplementation::~SpinnerImplementation()
{
    sub_00478A00(pCellFile);
}

// 0x004BC1F0
SpinnerWrapper::~SpinnerWrapper()
{
    delete pImpl;
}

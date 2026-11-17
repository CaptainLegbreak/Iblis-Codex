struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct sub_0040F7D0
{
    D2StormLinkStrc f_0;
    ~sub_0040F7D0();
};

// 0x0040F7D0
sub_0040F7D0::~sub_0040F7D0()
{
    f_0.Unlink();
}

struct sub_00417810
{
    D2StormLinkStrc f_0;
    ~sub_00417810();
};

// 0x00417810
sub_00417810::~sub_00417810()
{
    f_0.Unlink();
}

struct sub_00417860
{
    D2StormLinkStrc f_0;
    ~sub_00417860();
};

// 0x00417860
sub_00417860::~sub_00417860()
{
    f_0.Unlink();
}

struct sub_004178C0
{
    D2StormLinkStrc f_0;
    ~sub_004178C0();
};

// 0x004178C0
sub_004178C0::~sub_004178C0()
{
    f_0.Unlink();
}

struct sub_00417900
{
    D2StormLinkStrc f_0;
    ~sub_00417900();
};

// 0x00417900
sub_00417900::~sub_00417900()
{
    f_0.Unlink();
}

struct sub_00417950
{
    D2StormLinkStrc f_0;
    ~sub_00417950();
};

// 0x00417950
sub_00417950::~sub_00417950()
{
    f_0.Unlink();
}

struct sub_004179B0
{
    D2StormLinkStrc f_0;
    ~sub_004179B0();
};

// 0x004179B0
sub_004179B0::~sub_004179B0()
{
    f_0.Unlink();
}

struct sub_004183F0
{
    D2StormLinkStrc f_0;
    ~sub_004183F0();
};

// 0x004183F0
sub_004183F0::~sub_004183F0()
{
    f_0.Unlink();
}

struct sub_00418430
{
    D2StormLinkStrc f_0;
    ~sub_00418430();
};

// 0x00418430
sub_00418430::~sub_00418430()
{
    f_0.Unlink();
}

struct sub_00418780
{
    D2StormLinkStrc f_0;
    ~sub_00418780();
};

// 0x00418780
sub_00418780::~sub_00418780()
{
    f_0.Unlink();
}

struct sub_004187C0
{
    D2StormLinkStrc f_0;
    ~sub_004187C0();
};

// 0x004187C0
sub_004187C0::~sub_004187C0()
{
    f_0.Unlink();
}

struct sub_00418800
{
    D2StormLinkStrc f_0;
    ~sub_00418800();
};

// 0x00418800
sub_00418800::~sub_00418800()
{
    f_0.Unlink();
}

struct sub_00418840
{
    D2StormLinkStrc f_0;
    ~sub_00418840();
};

// 0x00418840
sub_00418840::~sub_00418840()
{
    f_0.Unlink();
}

struct sub_00418880
{
    D2StormLinkStrc f_0;
    ~sub_00418880();
};

// 0x00418880
sub_00418880::~sub_00418880()
{
    f_0.Unlink();
}

struct sub_004188C0
{
    D2StormLinkStrc f_0;
    ~sub_004188C0();
};

// 0x004188C0
sub_004188C0::~sub_004188C0()
{
    f_0.Unlink();
}

struct sub_00418BA0
{
    D2StormLinkStrc f_0;
    ~sub_00418BA0();
};

// 0x00418BA0
sub_00418BA0::~sub_00418BA0()
{
    f_0.Unlink();
}

struct sub_00418BE0
{
    D2StormLinkStrc f_0;
    ~sub_00418BE0();
};

// 0x00418BE0
sub_00418BE0::~sub_00418BE0()
{
    f_0.Unlink();
}

struct sub_00418C20
{
    D2StormLinkStrc f_0;
    ~sub_00418C20();
};

// 0x00418C20
sub_00418C20::~sub_00418C20()
{
    f_0.Unlink();
}

struct sub_00418E10
{
    D2StormLinkStrc f_0;
    ~sub_00418E10();
};

// 0x00418E10
sub_00418E10::~sub_00418E10()
{
    f_0.Unlink();
}

struct sub_0041C3D0
{
    D2StormLinkStrc f_0;
    ~sub_0041C3D0();
};

// 0x0041C3D0
sub_0041C3D0::~sub_0041C3D0()
{
    f_0.Unlink();
}

struct sub_0041C500
{
    D2StormLinkStrc f_0;
    ~sub_0041C500();
};

// 0x0041C500
sub_0041C500::~sub_0041C500()
{
    f_0.Unlink();
}

struct sub_0041C730
{
    D2StormLinkStrc f_0;
    ~sub_0041C730();
};

// 0x0041C730
sub_0041C730::~sub_0041C730()
{
    f_0.Unlink();
}

struct sub_0041C800
{
    D2StormLinkStrc f_0;
    ~sub_0041C800();
};

// 0x0041C800
sub_0041C800::~sub_0041C800()
{
    f_0.Unlink();
}

struct sub_00420430
{
    D2StormLinkStrc f_0;
    ~sub_00420430();
};

// 0x00420430
sub_00420430::~sub_00420430()
{
    f_0.Unlink();
}

struct sub_004204B0
{
    D2StormLinkStrc f_0;
    ~sub_004204B0();
};

// 0x004204B0
sub_004204B0::~sub_004204B0()
{
    f_0.Unlink();
}

struct sub_00420710
{
    D2StormLinkStrc f_0;
    ~sub_00420710();
};

// 0x00420710
sub_00420710::~sub_00420710()
{
    f_0.Unlink();
}

struct sub_004207E0
{
    D2StormLinkStrc f_0;
    ~sub_004207E0();
};

// 0x004207E0
sub_004207E0::~sub_004207E0()
{
    f_0.Unlink();
}

struct sub_00426960
{
    D2StormLinkStrc f_0;
    ~sub_00426960();
};

// 0x00426960
sub_00426960::~sub_00426960()
{
    f_0.Unlink();
}

struct sub_00426A80
{
    D2StormLinkStrc f_0;
    ~sub_00426A80();
};

// 0x00426A80
sub_00426A80::~sub_00426A80()
{
    f_0.Unlink();
}

struct sub_00426CB0
{
    D2StormLinkStrc f_0;
    ~sub_00426CB0();
};

// 0x00426CB0
sub_00426CB0::~sub_00426CB0()
{
    f_0.Unlink();
}

struct sub_00426D80
{
    D2StormLinkStrc f_0;
    ~sub_00426D80();
};

// 0x00426D80
sub_00426D80::~sub_00426D80()
{
    f_0.Unlink();
}

struct sub_0044DDD0
{
    D2StormLinkStrc f_0;
    ~sub_0044DDD0();
};

// 0x0044DDD0
sub_0044DDD0::~sub_0044DDD0()
{
    f_0.Unlink();
}

struct sub_0044DE90
{
    D2StormLinkStrc f_0;
    ~sub_0044DE90();
};

// 0x0044DE90
sub_0044DE90::~sub_0044DE90()
{
    f_0.Unlink();
}

struct sub_0044ECC0
{
    D2StormLinkStrc f_0;
    ~sub_0044ECC0();
};

// 0x0044ECC0
sub_0044ECC0::~sub_0044ECC0()
{
    f_0.Unlink();
}

struct sub_0044ED50
{
    D2StormLinkStrc f_0;
    ~sub_0044ED50();
};

// 0x0044ED50
sub_0044ED50::~sub_0044ED50()
{
    f_0.Unlink();
}

struct sub_00601BF0
{
    D2StormLinkStrc f_0;
    ~sub_00601BF0();
};

// 0x00601BF0
sub_00601BF0::~sub_00601BF0()
{
    f_0.Unlink();
}

struct sub_00601C70
{
    D2StormLinkStrc f_0;
    ~sub_00601C70();
};

// 0x00601C70
sub_00601C70::~sub_00601C70()
{
    f_0.Unlink();
}

struct sub_00601D60
{
    D2StormLinkStrc f_0;
    ~sub_00601D60();
};

// 0x00601D60
sub_00601D60::~sub_00601D60()
{
    f_0.Unlink();
}

struct sub_00601F20
{
    D2StormLinkStrc f_0;
    ~sub_00601F20();
};

// 0x00601F20
sub_00601F20::~sub_00601F20()
{
    f_0.Unlink();
}

struct sub_00601F60
{
    D2StormLinkStrc f_0;
    ~sub_00601F60();
};

// 0x00601F60
sub_00601F60::~sub_00601F60()
{
    f_0.Unlink();
}

struct sub_006020D0
{
    D2StormLinkStrc f_0;
    ~sub_006020D0();
};

// 0x006020D0
sub_006020D0::~sub_006020D0()
{
    f_0.Unlink();
}

struct sub_00602140
{
    D2StormLinkStrc f_0;
    ~sub_00602140();
};

// 0x00602140
sub_00602140::~sub_00602140()
{
    f_0.Unlink();
}

struct sub_006024A0
{
    D2StormLinkStrc f_0;
    ~sub_006024A0();
};

// 0x006024A0
sub_006024A0::~sub_006024A0()
{
    f_0.Unlink();
}

struct sub_00602760
{
    D2StormLinkStrc f_0;
    ~sub_00602760();
};

// 0x00602760
sub_00602760::~sub_00602760()
{
    f_0.Unlink();
}

struct sub_00417780
{
    D2StormLinkStrc f_0;
    sub_00417780();
};

// 0x00417780
sub_00417780::sub_00417780()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00417850
{
    D2StormLinkStrc f_0;
    sub_00417850();
};

// 0x00417850
sub_00417850::sub_00417850()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_004178B0
{
    D2StormLinkStrc f_0;
    sub_004178B0();
};

// 0x004178B0
sub_004178B0::sub_004178B0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00417940
{
    D2StormLinkStrc f_0;
    sub_00417940();
};

// 0x00417940
sub_00417940::sub_00417940()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00417990
{
    D2StormLinkStrc f_0;
    sub_00417990();
};

// 0x00417990
sub_00417990::sub_00417990()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418760
{
    D2StormLinkStrc f_0;
    sub_00418760();
};

// 0x00418760
sub_00418760::sub_00418760()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418770
{
    D2StormLinkStrc f_0;
    sub_00418770();
};

// 0x00418770
sub_00418770::sub_00418770()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418A40
{
    D2StormLinkStrc f_0;
    sub_00418A40();
};

// 0x00418A40
sub_00418A40::sub_00418A40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418DE0
{
    D2StormLinkStrc f_0;
    sub_00418DE0();
};

// 0x00418DE0
sub_00418DE0::sub_00418DE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418DF0
{
    D2StormLinkStrc f_0;
    sub_00418DF0();
};

// 0x00418DF0
sub_00418DF0::sub_00418DF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418E00
{
    D2StormLinkStrc f_0;
    sub_00418E00();
};

// 0x00418E00
sub_00418E00::sub_00418E00()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418E50
{
    D2StormLinkStrc f_0;
    sub_00418E50();
};

// 0x00418E50
sub_00418E50::sub_00418E50()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00418FF0
{
    D2StormLinkStrc f_0;
    sub_00418FF0();
};

// 0x00418FF0
sub_00418FF0::sub_00418FF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00419060
{
    D2StormLinkStrc f_0;
    sub_00419060();
};

// 0x00419060
sub_00419060::sub_00419060()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_0041C4F0
{
    D2StormLinkStrc f_0;
    sub_0041C4F0();
};

// 0x0041C4F0
sub_0041C4F0::sub_0041C4F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_0041C720
{
    D2StormLinkStrc f_0;
    sub_0041C720();
};

// 0x0041C720
sub_0041C720::sub_0041C720()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_0041C7F0
{
    D2StormLinkStrc f_0;
    sub_0041C7F0();
};

// 0x0041C7F0
sub_0041C7F0::sub_0041C7F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_004204A0
{
    D2StormLinkStrc f_0;
    sub_004204A0();
};

// 0x004204A0
sub_004204A0::sub_004204A0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00420700
{
    D2StormLinkStrc f_0;
    sub_00420700();
};

// 0x00420700
sub_00420700::sub_00420700()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_004207D0
{
    D2StormLinkStrc f_0;
    sub_004207D0();
};

// 0x004207D0
sub_004207D0::sub_004207D0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00426CA0
{
    D2StormLinkStrc f_0;
    sub_00426CA0();
};

// 0x00426CA0
sub_00426CA0::sub_00426CA0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00426D70
{
    D2StormLinkStrc f_0;
    sub_00426D70();
};

// 0x00426D70
sub_00426D70::sub_00426D70()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_0044BDE0
{
    D2StormLinkStrc f_0;
    sub_0044BDE0();
};

// 0x0044BDE0
sub_0044BDE0::sub_0044BDE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_0044ED40
{
    D2StormLinkStrc f_0;
    sub_0044ED40();
};

// 0x0044ED40
sub_0044ED40::sub_0044ED40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_0044ED90
{
    D2StormLinkStrc f_0;
    sub_0044ED90();
};

// 0x0044ED90
sub_0044ED90::sub_0044ED90()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00601F10
{
    D2StormLinkStrc f_0;
    sub_00601F10();
};

// 0x00601F10
sub_00601F10::sub_00601F10()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00602130
{
    D2StormLinkStrc f_0;
    sub_00602130();
};

// 0x00602130
sub_00602130::sub_00602130()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00602180
{
    D2StormLinkStrc f_0;
    sub_00602180();
};

// 0x00602180
sub_00602180::sub_00602180()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00602420
{
    D2StormLinkStrc f_0;
    sub_00602420();
};

// 0x00602420
sub_00602420::sub_00602420()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

struct sub_00602750
{
    D2StormLinkStrc f_0;
    sub_00602750();
};

// 0x00602750
sub_00602750::sub_00602750()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

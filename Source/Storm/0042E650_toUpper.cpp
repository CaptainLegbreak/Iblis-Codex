struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode toUpper() const;
};

extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578

// 0x0042E650
Unicode Unicode::toUpper() const
{
    return Unicode(wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar);
}

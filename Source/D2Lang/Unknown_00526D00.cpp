struct Unicode
{
    enum Direction
    {
        DIR_LEFT_TO_RIGHT = 0xF0,
        DIR_RIGHT_TO_LEFT = 0xF1,
        DIR_NEUTRAL = 0xF2,
    };

    unsigned short ch;

    int sub_00526D00_IsNotRightToLeft() const;
    Direction directionality();
};

// 0x00526D00
int Unicode::sub_00526D00_IsNotRightToLeft() const
{
    if ((ch >= 0x590 && ch <= 0x5FF) || (ch >= 0x600 && ch <= 0x6FF))
        return 0;
    return 1;
}

// 0x00526FB0
Unicode::Direction Unicode::directionality()
{
    if (this->ch >= 0x590 && this->ch <= 0x8FF)
        return DIR_RIGHT_TO_LEFT;
    if (this->ch >= L'a' && this->ch <= L'z')
        return DIR_LEFT_TO_RIGHT;
    if (this->ch >= L'@' && this->ch <= L'Z')
        return DIR_LEFT_TO_RIGHT;
    if (this->ch >= L'0' && this->ch <= L'9')
        return DIR_LEFT_TO_RIGHT;
    if (this->ch <= L'\?')
        return (this->ch == L'&') ? DIR_LEFT_TO_RIGHT : DIR_NEUTRAL;
    if (this->ch >= 0x3040 && this->ch <= 0x8BFF)
        return DIR_LEFT_TO_RIGHT;
    if (this->ch >= 0xC0 && this->ch <= 0x58F && this->ch != 0xD7 && this->ch != 0xF7)
        return DIR_LEFT_TO_RIGHT;
    if (this->ch >= 0x900 && this->ch <= 0x10FF)
        return DIR_LEFT_TO_RIGHT;
    if ((this->ch & 0xFE00) == 0x2000)
    {
        if (this->ch >= 0x2160 && this->ch <= 0x2182)
            return DIR_LEFT_TO_RIGHT;
        if (this->ch >= 0x20D0 && this->ch <= 0x20FF)
            return DIR_LEFT_TO_RIGHT;
        if (this->ch == 0x200E)
            return DIR_LEFT_TO_RIGHT;
        if (this->ch == 0x200F)
            return DIR_RIGHT_TO_LEFT;
    }
    return DIR_NEUTRAL;
}

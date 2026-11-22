#include "D2Unicode.h"
// 0x00526D00
int Unicode::isLeftToRight() const
{
    if ((wChar >= 0x590 && wChar <= 0x5FF) || (wChar >= 0x600 && wChar <= 0x6FF))
        return 0;
    return 1;
}

// 0x00526FB0
Unicode::Direction Unicode::directionality()
{
    if (this->wChar >= 0x590 && this->wChar <= 0x8FF)
        return DIR_RIGHT_TO_LEFT;
    if (this->wChar >= L'a' && this->wChar <= L'z')
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= L'@' && this->wChar <= L'Z')
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= L'0' && this->wChar <= L'9')
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar <= L'\?')
        return (this->wChar == L'&') ? DIR_LEFT_TO_RIGHT : DIR_NEUTRAL;
    if (this->wChar >= 0x3040 && this->wChar <= 0x8BFF)
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= 0xC0 && this->wChar <= 0x58F && this->wChar != 0xD7 && this->wChar != 0xF7)
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= 0x900 && this->wChar <= 0x10FF)
        return DIR_LEFT_TO_RIGHT;
    if ((this->wChar & 0xFE00) == 0x2000)
    {
        if (this->wChar >= 0x2160 && this->wChar <= 0x2182)
            return DIR_LEFT_TO_RIGHT;
        if (this->wChar >= 0x20D0 && this->wChar <= 0x20FF)
            return DIR_LEFT_TO_RIGHT;
        if (this->wChar == 0x200E)
            return DIR_LEFT_TO_RIGHT;
        if (this->wChar == 0x200F)
            return DIR_RIGHT_TO_LEFT;
    }
    return DIR_NEUTRAL;
}

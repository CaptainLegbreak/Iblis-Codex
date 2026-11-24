#pragma once
// Client: the list node of a dialog's widgets.

#include "D2Check.h"

struct D2DialogWidget;

struct D2DialogWidgetNodeStrc
{
    D2DialogWidget* f_0;
    D2DialogWidgetNodeStrc* pNext;
};

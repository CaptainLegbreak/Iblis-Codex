struct Point { int x, y; };
struct Control;
typedef int (__fastcall* ControlFn)(Control*);
struct Control {
    char prefix[0x0C];
    int x, y, width, height;
    char callbacks[0x1C];
    ControlFn shouldHandle;
};

// 0x004FA1B0
static __forceinline int sub_004FA1B0(Control* control, const Point* point)
{
    if (control->shouldHandle)
        return control->shouldHandle(control);
    const int left = control->x;
    const int bottom = control->y;
    if (point->x >= left && point->y >= bottom - control->height
        && point->x < left + control->width && point->y < bottom)
        return 1;
    return 0;
}

int __stdcall emit_hit_test_004FA1B0(Control* control, const Point* point) { return sub_004FA1B0(control, point); }

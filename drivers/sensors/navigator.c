#include "quantum.h"
#include "navigator.h"

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

bool set_scrolling = false;

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x / NAVIGATOR_SCROLL_DIVIDER;
        scroll_accumulated_v += (float)mouse_report.y / NAVIGATOR_SCROLL_DIVIDER;
        mouse_report.h = (int8_t)scroll_accumulated_h;
#ifdef NAVIGATOR_SCROLL_INVERT
        mouse_report.v = (int8_t)-scroll_accumulated_v;
#else
        mouse_report.v = (int8_t)scroll_accumulated_v;
#endif

        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

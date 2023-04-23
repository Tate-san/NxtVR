#ifndef USB_DESCRIPTORS_H_
#define USB_DESCRIPTORS_H_

#include "class/hid/hid.h" 
#include "tusb.h"
#include "tusb_types.h"

#define HID_PROTOCOL_NONE 0
#define TUD_HID_REPORT_DESC_HMD(...) \
    HID_USAGE_PAGE ( HID_USAGE_PAGE_VIRTUAL_REALITY)        ,\
    HID_USAGE      ( HID_USAGE_PAGE_GENERIC_DEVICE )        ,\
    HID_COLLECTION ( HID_COLLECTION_APPLICATION    )        ,\
   /* Report ID if any */\
    __VA_ARGS__ \
    HID_COLLECTION ( HID_COLLECTION_PHYSICAL       )        ,\
   /* Accel, Gyroscope and Magnetometer (min -2147483647, max 2147483647) */ \
    HID_USAGE_PAGE   ( HID_USAGE_PAGE_DESKTOP                 ) ,\
    HID_LOGICAL_MIN_N  ( 0x7FFFFFFF, 3                        ) ,\
    HID_LOGICAL_MAX_N  ( 0x80000000, 3                        ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_X                    ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_Y                    ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_Z                    ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_RX                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_RY                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_RZ                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_VX                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_VY                   ) ,\
    HID_USAGE        ( HID_USAGE_DESKTOP_VZ                   ) ,\
    HID_REPORT_COUNT ( 9                                      ) ,\
    HID_REPORT_SIZE  ( 32                                      ) ,\
    HID_INPUT        ( HID_DATA | HID_VARIABLE | HID_ABSOLUTE ) ,\
    HID_COLLECTION_END ,\
    HID_COLLECTION_END 

typedef struct TU_ATTR_PACKED
{
    int32_t ax;
    int32_t ay;
    int32_t az;
    int32_t gx;
    int32_t gy;
    int32_t gz;
    int32_t mx;
    int32_t my;
    int32_t mz;
}hid_hmd_report_t;

#endif /* USB_DESCRIPTORS_H_ */
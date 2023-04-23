#ifndef HIDHANDLER_H_
#define HIDHANDLER_H_

#include <cinttypes>
#include <hid/hid_handler.h>
#include <hid/usb_descriptors.h>
#include <pico/time.h>
#include <bsp/board.h>
#include <tusb.h>
#include <sensors/sensor.h>
#include <logging.h>

class HidHandler{
public:
    static HidHandler *globalHidHandler;

    static HidHandler *getInstance();

    void task(sensor_data_t);
private:
    HidHandler();
    virtual ~HidHandler();
};

#endif // HIDHANDLER_H_
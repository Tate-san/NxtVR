#include "hid_handler.h"

HidHandler* HidHandler::globalHidHandler = nullptr;

HidHandler *HidHandler::getInstance()
{
    if(globalHidHandler != nullptr){
        globalHidHandler = new HidHandler();
    }

    return globalHidHandler;
}
void HidHandler::task(sensor_data_t ctx)
{
    // Poll every 10ms
    const uint32_t interval_ms = 10;
    static uint32_t start_ms = 0;

    if (board_millis() - start_ms < interval_ms) return; // not enough time
        start_ms += interval_ms;

    // Remote wakeup
    if (tud_suspended()) {
        // Wake up host if we are in suspend mode
        // and REMOTE_WAKEUP feature is enabled by host
        tud_remote_wakeup();
    }
   //send the report if the device is ready for sending the data
    if (tud_hid_ready()) {

        hid_hmd_report_t report = 
        {
            .ax = ctx.accel[0], .ay = ctx.accel[1], .az = ctx.accel[2],
            .gx = ctx.gyro[0], .gy = ctx.gyro[2], .gz = ctx.gyro[2],
            .mx = 0, .my = 0, .mz = 0
        };

        tud_hid_report(0x01, &report, 32);
    }
}

HidHandler::HidHandler()
{
    globalHidHandler = this;
}

HidHandler::~HidHandler()
{
}
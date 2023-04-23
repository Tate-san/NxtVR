#include "sensor.h"

void Sensor::readData()
{
    readAccel();
    readGyro();
}

int16_t *Sensor::getAccel()
{
    return this->accel;
}

int16_t *Sensor::getGyro()
{
    return this->gyro;
}

sensor_data_t Sensor::getData()
{
    return sensor_data_t{accel, gyro};
}

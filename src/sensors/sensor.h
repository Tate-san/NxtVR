#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <inttypes.h>

typedef struct{
    int16_t *accel;
    int16_t *gyro;
}sensor_data_t;

class Sensor{
public:
    virtual void begin();
    virtual void readAccel();
    virtual void readGyro();

    void readData();

    int16_t* getAccel();
    int16_t* getGyro();
    sensor_data_t getData();

protected:
    int16_t accel[3] = {0, 0, 0};
    int16_t gyro[3] = {0, 0, 0};

};

#endif // __SENSOR_H__
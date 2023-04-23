#include <bsp/board.h>
#include <tusb.h>

#include <hardware/gpio.h>
#include <pico/stdlib.h>
#include <pico/time.h>
#include <stdint.h>
#include <stdio.h>
#include <hid/hid_handler.h>
#include <hid/usb_descriptors.h>
#include <sensors/mpu6050/mpu6050.h>
#include <logging.h>

#define SDA_PIN 4
#define SCL_PIN 5

MPU6050 mpu6050;
int16_t bias[6] = {OFFSET_AX, OFFSET_AY, OFFSET_AZ, OFFSET_GX, OFFSET_GY, OFFSET_GZ};

int main()
{
   board_init();
   stdio_init_all();
   tusb_init();
   printf("Board started\n");
   i2c_init(I2C_PORT, 400 * 1000);
   gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
   gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
   gpio_pull_up(SDA_PIN);
   gpio_pull_up(SCL_PIN); 
   mpu6050.begin();
   mpu6050.configure(bias);

   auto hid_handler = HidHandler::getInstance();
   while(1)
   { 
      tud_task();
      mpu6050.readData();
      sensor_data_t data = mpu6050.getData();
      printf("Accel: X: %d, Y: %d, Z: %d | Gyro: X: %d, Y: %d, Z: %d\n", data.accel[0], data.accel[1], data.accel[2], data.gyro[0], data.gyro[1], data.gyro[2]);
   
      hid_handler->task(data);
   }

   return 0;
}
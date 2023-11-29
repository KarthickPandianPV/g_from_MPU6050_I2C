#include <Arduino.h>
#include <Wire.h>
#include "mpu6050_register.hpp"

bool mpu_status;
byte accelz_8bit_array[2];
double az;


void setup() 
{
  Wire.begin();
  Serial.begin(9600); 

  // checking MPU connection
  Wire.beginTransmission(MPU6050_ADDRESS);
  mpu_status=Wire.endTransmission(true);
  if(mpu_status==0)
   Serial.println("MPU6050 Connection Successful.");
  else
   Serial.println("MPU6050 Connection Failed..!");

 // Disable sleep mode
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(PWR_MGMT_1_REG);
  Wire.write(0<<6);
  Wire.endTransmission(true); 
  
  // Setting sample rate
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(SMPLRT_DIV_REG);
  Wire.write(0);
  Wire.endTransmission(true);

  /*// Setting gyroscope and accelerometer range
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(GYRO_CONFIG_REG);
  Wire.write(GYROSCOPE_RANGE_1000);
  Wire.endTransmission(true);
*/
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(ACCEL_CONFIG_REG);
  Wire.write(ACCELERO_METER_RANGE_8);
  Wire.endTransmission(true);
}

void loop() 
{
  // Reading msb of az
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(ACCEL_ZOUT_H_REG);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS,1,true);
  while(Wire.available())
     accelz_8bit_array[1]=Wire.read();
  
  // Reading lsb of az
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(ACCEL_ZOUT_L_REG);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS,1,true);
  while(Wire.available())
   accelz_8bit_array[0]=Wire.read();
 
 // Combining into 16bit az
 az=(accelz_8bit_array[1]<<8 )+(accelz_8bit_array[0]);
 az= ACCELERATION_DUE_TO_GRAVITY * az * ACCELERO_METER_SENSITIVITY_8;

// Printing az
  Serial.print("az: ");
  Serial.println(az);
  delay(100);
}



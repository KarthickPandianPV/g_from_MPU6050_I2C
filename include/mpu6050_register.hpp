#define MPU6050_ADDRESS 0x68
#define SMPLRT_DIV_REG 0x19
#define PWR_MGMT_1_REG 0x6B
#define CONFIG_REG 0x1A
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCELERATION_DUE_TO_GRAVITY 9.80665
#define ACCELERO_METER_SENSITIVITY_8 0.0001220703125*2

#define ACCEL_XOUT_H_REG 0x3B
#define ACCEL_XOUT_L_REG 0x3C
#define ACCEL_YOUT_H_REG 0x3D
#define ACCEL_YOUT_L_REG 0x3E
#define ACCEL_ZOUT_H_REG 0x3F
#define ACCEL_ZOUT_L_REG 0x40

#define GYRO_XOUT_H_REG 0x43
#define GYRO_XOUT_L_REG 0x44
#define GYRO_YOUT_H_REG 0x45
#define GYRO_YOUT_L_REG 0x46
#define GYRO_ZOUT_H_REG 0x47
#define GYRO_ZOUT_L_REG 0x48

#define ACCELERO_METER_RANGE_2 0<<3
#define ACCELERO_METER_RANGE_4 1<<3
#define ACCELERO_METER_RANGE_8 2<<3
#define ACCELERO_METER_RANGE_16 3<<3

#define GYROSCOPE_RANGE_250 0<<3
#define GYROSCOPE_RANGE_500 1<<3
#define GYROSCOPE_RANGE_1000 2<<3
#define GYROSCOPE_RANGE_2000 3<<3
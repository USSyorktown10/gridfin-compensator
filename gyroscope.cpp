#include <i2c_t3.h>

#define ACCEL_NEW_PIN    16

#define CTRL_REG1        0x20
#define CTRL_REG2        0x21
#define CTRL_REG3        0x22
#define CTRL_REG4        0x23
#define OUT_X_L          0x28
#define OUT_X_H          0x29
#define OUT_Y_L          0x2A
#define OUT_Y_H          0x2B
#define OUT_Z_L          0x2C
#define OUT_Z_H          0x2D

#define accelAddress     0x19

volatile bool accelNew = true;
int16_t x, y, z;

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("Accel Ready");
  accelSetup();
}

void loop(){
  if(accelNew){
    getAccel(x, y, z);
    Serial.println(x);
    Serial.println(y);
    Serial.println(z);
    accelNew = false;
  }
}

void accelSetup(){
  Wire.begin(I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_EXT, 1800000, I2C_OP_MODE_IMM);
  writeAccel(CTRL_REG1, B00111111); 
  writeAccel(CTRL_REG2, B00110000); 
  writeAccel(CTRL_REG3, B00000010);
  writeAccel(CTRL_REG4, B10000000); 
  pinMode(ACCEL_NEW_PIN,INPUT);
  attachInterrupt(digitalPinToInterrupt(ACCEL_NEW_PIN), accelISR, RISING);
}

void accelISR(){
  accelNew = true;
}

void getAccel(int16_t& xAccel, int16_t& yAccel, int16_t& zAccel){
  uint8_t data[6];
  readAccel(OUT_X_L, data, 6);
  xAccel = (data[0] | data[1] << 8) >> 4;
  yAccel = (data[2] | data[3] << 8) >> 4;
  zAccel = (data[4] | data[5] << 8) >> 4;
}

void readAccel(byte address, byte* data, uint8_t bytes)
{
  Wire.beginTransmission(accelAddress);
  Wire.write(address | 0x80);//
  Wire.sendTransmission();
  Wire.sendRequest(accelAddress, bytes);
  while(Wire.available()) *(data++) = Wire.readByte();
}

void writeAccel(byte address, byte data)
{
  Wire.beginTransmission(accelAddress);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

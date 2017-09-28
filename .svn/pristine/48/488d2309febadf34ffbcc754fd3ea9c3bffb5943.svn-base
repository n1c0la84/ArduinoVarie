#include <Arduino.h>
#include <Wire.h>
#include "nunchuk.h"

#define NUNCHUK_DEVICE_ID 0x52

void Nunchuk::initialize() {
  Wire.begin();
  Wire.beginTransmission(NUNCHUK_DEVICE_ID);
  Wire.write((byte)0xF0); 
  Wire.write((byte)0x55); 
  Wire.endTransmission();
  Wire.beginTransmission(NUNCHUK_DEVICE_ID);
  Wire.write((byte)0xFB); 
  Wire.write((byte)0x00); 
  Wire.endTransmission();
  update();
}

bool Nunchuk::update() {
  delay(1); int byte_counter = 0;
  Wire.requestFrom(NUNCHUK_DEVICE_ID, NUNCHUK_BUFFER_SIZE);
  while (Wire.available() && byte_counter < NUNCHUK_BUFFER_SIZE) {
    _buffer[byte_counter++] = decode_byte(Wire.read());
  }
  request_data();
  return byte_counter == NUNCHUK_BUFFER_SIZE;
}

void Nunchuk::request_data() {
  Wire.beginTransmission(NUNCHUK_DEVICE_ID);
  Wire.write((byte)0x00);
  Wire.endTransmission();
}

char Nunchuk::decode_byte(const char b) {
  return b; 
}


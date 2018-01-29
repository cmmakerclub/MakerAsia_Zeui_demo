#ifndef _ZEUI_H_
#define _ZEUI_H_

float Read_mA_RMS (void) {
  uint32_t Start_time = millis();
  uint32_t log_time = Start_time;
  uint32_t Current_time = Start_time;
  uint8_t index = 0;
  uint16_t _max = 0;
  uint16_t _min = 0xfff;
  uint16_t _buffer[50] = {0};
  while (Current_time - Start_time < 1000UL) {
    Current_time = millis();
    if (Current_time - log_time >= 20) {
      log_time = Current_time;
      _buffer[index] = _max - _min;
      index++;
      _max = 0;
      _min = 0xfff;
    }
    uint16_t adc = analogRead(A0);
    if (adc > _max )_max = adc;
    if (adc < _min )_min = adc;
  }
  uint32_t _avg = 0;

  for (int x = 0; x < index; x++) {
    _avg += _buffer[x];
  }
  _avg = _avg / index;
  float I_RMS =  _avg * 9.331540081f ; //  185mV/A // R-devider 4k-1k //Vrms = Vpp /(2root2)

  I_RMS = I_RMS - 20; //offset ~20 mA
  if (I_RMS < 0) I_RMS = 0;
  return I_RMS;
}

float Turn_on (void) {
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);
}

float Turn_off (void) {
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW);
}

#endif

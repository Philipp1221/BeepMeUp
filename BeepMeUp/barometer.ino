
// Calculates the height gain resp. loss
void getVerticalSpeed() {
  f_tmp = getAltitude();
  vertical_speed = lowPassFilter(vertical_speed, (f_tmp - altitude)*1000/loop_time, 0.1);
  altitude = f_tmp;
}

// Calculates the altitude
float getAltitude() {
  pressure = (float)baro.getPressure()/100;
  temperature = (float)baro.getTemperature()/100;
  f_tmp = ((pow((sea_pressure / pressure), 1/5.257) - 1.0) * (temperature + 273.15)) / 0.0065;
  return lowPassFilter(altitude, f_tmp,0.05);
}

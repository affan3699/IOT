int Sine_LUT[7] = {128,152,176,198,218,234,2}
int i = 0;

void setup()
{
  Serial.begin(115200);
}

void loop() {
  Serial.println(Sine_LUT[i++]);

  if(i == 7)
  {
    i = 0;
  }

  delay(10);

}

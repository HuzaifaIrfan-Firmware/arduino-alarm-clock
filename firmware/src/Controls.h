#ifndef Controls_h
#define Controls_h

unsigned int adc_key_val[5] = {50, 200, 400, 600, 800};
int NUM_KEYS = 5;
int adc_key_in;
int key = -1;
int oldkey = -1;

int get_key(unsigned int input)
{
  int k;
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < adc_key_val[k])
    {
      return k;
    }
  }
  if (k >= NUM_KEYS)
    k = -1; // No valid key pressed
  return k;
}



void controlsSetup()
{
}

void controlsLoop()
{

  adc_key_in = analogRead(0); // read the value from the sensor
  key = get_key(adc_key_in);  // convert into key press
  if (key != oldkey)          // if keypress is detected
  {
    delay(50);                  // wait for debounce time
    adc_key_in = analogRead(0); // read the value from the sensor
    key = get_key(adc_key_in);  // convert into key press
    if (key != oldkey)
    {
      oldkey = key;
      if (key >= 0)
      {
        // Serial.println(key);
        switch (key)
        {
        case 0:
          // right
          moveCursor();
          break;
        case 1:
          // up
          increaseValue();
          break;
        case 2:
          // down
          decreaseValue();
          break;
        case 3:
          // left
          setAlarm();
          break;
        case 4:
          // reset alarm
          resetAlarm();
          break;
        }
      }
    }
  }
}



short value;
void serialLoop()
{
    if(Serial.available() > 0){
        value = Serial.parseInt();
        setCursorValue(value);
        
    }
}

#endif

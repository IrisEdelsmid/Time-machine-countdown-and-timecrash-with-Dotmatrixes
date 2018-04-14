//button one = +1000 til after 9000 =- 9000
// button two = +100 etc
//

int touchsensorReader()
{
  // delay(1);
  HomeButton();
}


int HomeButton()
{
  buttonTime = millis();
  while(digitalRead (homeButtonPin) == HIGH)
  {
    digitalRead (homeButtonPin);
    Serial.println("home");
    displayHomeYear();
  }
      _time1 = millis();
    if ((_time1 - buttonTime ) > 500 )
    {
      _sleep = ! _sleep;
      Sleepmode();
    }
}

int StartButton
{
  
}
  if (buttonInputClear == HIGH)
  {
    strip.setPixelColor(_sleepmodeLed[1], strip.Color(255, 255, 255));
    buttonTime = millis();
    Serial.println("buttonTime " + (_buttonTime));

    while ( buttonInputClear == HIGH )
    {
      buttonInputClear =  digitalRead (buttonReadClear);
      Serial.println("Clearbutton = HIGH");
    }
    _time1 = millis();
    if ((_time1 - buttonTime ) > minimumPressMiliSeconds )
    {
      _sleep = ! _sleep;
      Sleepmode();
    }
  }

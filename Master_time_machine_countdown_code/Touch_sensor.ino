//button one = +1000 til after 9000 =- 9000
// button two = +100 etc
//

void touchsensorReader()
{
  // delay(1);
  // HomeButton();

  if (digitalRead (startButtonPin) == HIGH) {
    Travel();
    Serial.print("start knop");
  }
  if (digitalRead (homeButtonPin) == HIGH) {
    displayHomeYear();
    Serial.println("Home");
  }
}


int HomeButton()
{
  //  unsigned long buttonTime = millis();
  //  while (digitalRead (homeButtonPin) == HIGH)
  //  {
  //    digitalRead (homeButtonPin);
  //    Serial.println("home");
  //    displayHomeYear();
  //  }
  //  unsigned long  _time1 = millis();
  //  if ((_time1 - buttonTime ) > 1000 )
  //  {
  //    startHomeYear();
  //  }
}

void StartButton()
{
  if (digitalRead (startButtonPin) == HIGH) {
    Travel();
    Serial.print("start knop");
    // timeTravelling = true;
  }
}


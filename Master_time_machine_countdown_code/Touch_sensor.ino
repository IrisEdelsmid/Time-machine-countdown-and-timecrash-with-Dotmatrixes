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
  if (digitalRead (homeButton) == HIGH)
  {
    Serial.println("home");
    displayHomeYear();
    delay(500);
  }
}

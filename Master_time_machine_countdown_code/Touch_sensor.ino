//button one = +1000 til after 9000 =- 9000
// button two = +100 etc
//

int touchsensorrReader();
{
  homeButton();
}


int homeButton()
{
  if (digitalRead (homeButton) == HIGH)
  {
    displayHomeYear(homeYear);
  }
}

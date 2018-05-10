void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int y[8];
  long year;
  int valLength;
  if (Serial.available()) {
    String binnen = Serial.readStringUntil('\n');
    year = binnen.toInt();

    for (int i = 0; i < 8 ; i++) {
      if (abs(year) >= pow(10, i))(valLength = i + 1);
    }

    for (int j = 0; j < 8 ; j++) {
      long tijdelijk = (abs(year) / pow(10, j));
      y[j] = tijdelijk % 10;
    }

    if (year < 0) {
      y[valLength] = 11;
      valLength ++;
    }

    Serial.println("test");
    Serial.println(year);
    Serial.println(valLength);
    for (int i = valLength - 1 , j = 0 ; i >= 0 && j < valLength ; i -- , j++){
      
      Serial.print(j);
      Serial.print("  --  ");
      Serial.println(y[i]);
    }
  }
}

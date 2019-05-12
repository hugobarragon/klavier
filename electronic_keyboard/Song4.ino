//***************** SONG 4 NOTES HERE **************************
void Song4()  {
  lcd.clear();

  // notes in the melody:

  lcd.setCursor(1, 0);
   lcd.print("    A tocar");
  lcd.setCursor(0, 1);
  lcd.print(" Game of Thrones");


  for (byte i = 0; i < 4; i++) {
    tone(8, NOTE_G4);
    delay(500);
    noTone(8);

    tone(8, NOTE_C4);
    delay(500);
    noTone(8);

    tone(8, NOTE_DS4);
    delay(250);
    noTone(8);

    tone(8, NOTE_F4);
    delay(250);
    noTone(8);
  }

  for (byte i = 0; i < 4; i++) {
    tone(8, NOTE_G4);
    delay(500);
    noTone(8);

    tone(8, NOTE_C4);
    delay(500);
    noTone(8);

    tone(8, NOTE_E4);
    delay(250);
    noTone(8);

    tone(8, NOTE_F4);
    delay(250);
    noTone(8);
  }

  tone(8, NOTE_G4);
  delay(500);
  noTone(8);

  tone(8, NOTE_C4);
  delay(500);

  tone(8, NOTE_DS4);
  delay(250);
  noTone(8);

  tone(8, NOTE_F4);
  delay(250);
  noTone(8);

  tone(8, NOTE_D4);
  delay(500);
  noTone(8);

  for (byte i = 0; i < 3; i++) {
    tone(8, NOTE_G3);
    delay(500);
    noTone(8);

    tone(8, NOTE_AS3);
    delay(250);
    noTone(8);

    tone(8, NOTE_C4);
    delay(250);
    noTone(8);

    tone(8, NOTE_D4);
    delay(500);
    noTone(8);
  }//

  tone(8, NOTE_G3);
  delay(500);
  noTone(8);

  tone(8, NOTE_AS3);
  delay(250);
  noTone(8);

  tone(8, NOTE_C4);
  delay(250);
  noTone(8);

  tone(8, NOTE_D4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_F4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_AS3);
  delay(1000);
  noTone(8);

  tone(8, NOTE_DS4);
  delay(250);
  noTone(8);

  tone(8, NOTE_D4);
  delay(250);
  noTone(8);

  tone(8, NOTE_F4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_AS3);
  delay(1000);
  noTone(8);

  tone(8, NOTE_DS4);
  delay(250);
  noTone(8);

  tone(8, NOTE_D4);
  delay(250);
  noTone(8);

  tone(8, NOTE_C4);
  delay(500);
  noTone(8);

  for (byte i = 0; i < 3; i++) {
    tone(8, NOTE_GS3);
    delay(250);
    noTone(8);

    tone(8, NOTE_AS3);
    delay(250);
    noTone(8);

    tone(8, NOTE_C4);
    delay(500);
    noTone(8);

    tone(8, NOTE_F3);
    delay(500);
    noTone(8);
  }

  tone(8, NOTE_G4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_C4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_DS4);
  delay(250);
  noTone(8);

  tone(8, NOTE_F4);
  delay(250);
  noTone(8);

  tone(8, NOTE_G4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_C4);
  delay(1000);
  noTone(8);

  tone(8, NOTE_DS4);
  delay(250);
  noTone(8);

  tone(8, NOTE_F4);
  delay(250);
  noTone(8);

  tone(8, NOTE_D4);
  delay(500);
  noTone(8);

  for (byte i = 0; i < 4; i++) {
    tone(8, NOTE_G3);
    delay(500);
    noTone(8);

    tone(8, NOTE_AS3);
    delay(250);
    noTone(8);

    tone(8, NOTE_C4);
    delay(250);
    noTone(8);

    tone(8, NOTE_D4);
    delay(500);
    noTone(8);
  }


  Song4title();


} // end Song4 loop

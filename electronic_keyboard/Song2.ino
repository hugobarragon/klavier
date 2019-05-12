//***************** SONG 2 NOTES HERE **************************

void Song2()  {
  
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("    A tocar");
  lcd.setCursor(0, 1);
  lcd.print(" Imperial March");
  const short c = 261;
  const short d = 294;
  const short e = 329;
  const short f = 349;
  const short g = 391;
  const short gS = 415;
  const short a = 440;
  const short aS = 455;
  const short b = 466;
  const short cH = 523;
  const short cSH = 554;
  const short dH = 587;
  const short dSH = 622;
  const short eH = 659;
  const short fH = 698;
  const short fSH = 740;
  const short gH = 784;
  const short gSH = 830;
  const short aH = 880;

  const byte buzzerPin = 8;


  //Play first section
  {
    beep(a, 500);
    beep(a, 500);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);

    delay(500);

    beep(eH, 500);
    beep(eH, 500);
    beep(eH, 500);
    beep(fH, 350);
    beep(cH, 150);
    beep(gS, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);

    delay(500);
  }

  //Play second section
  {
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 500);
    beep(gSH, 325);
    beep(gH, 175);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);

    delay(325);

    beep(aS, 250);
    beep(dSH, 500);
    beep(dH, 325);
    beep(cSH, 175);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);

    delay(350);
  }

  //Variant 1
  beep(f, 250);
  beep(gS, 500);
  beep(f, 350);
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);
  beep(cH, 125);
  beep(eH, 650);

  delay(500);

  //Repeat second section
  {
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 500);
    beep(gSH, 325);
    beep(gH, 175);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);

    delay(325);

    beep(aS, 250);
    beep(dSH, 500);
    beep(dH, 325);
    beep(cSH, 175);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);

    delay(350);
  }

  //Variant 2

  beep(f, 250);
  beep(gS, 500);
  beep(f, 375);
  beep(cH, 125);
  beep(a, 500);
  beep(f, 375);
  beep(cH, 125);
  beep(a, 650);

  delay(650);

Song2title();

  
 } // end Song2 loop

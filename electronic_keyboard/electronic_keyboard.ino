#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
#include "pitches.h"

const byte LCDswitchPin = 7;//variavel para o pin do butao lcd
byte LCDswitchState = 0; // variavel para ligar desligar lcd
byte prevLCDswitchState = 0;
byte LED = 6;
byte counter = 0; //contador para vezes de carregar no buttao
byte LCDswitchCounter = 0;   //variavel para contar a posição menu aumenta quando carregado

// butoes de musica define os valores de frequencias
short notes[] = {262, 294, 330, 349, 392, 440, 494}; // notas C, D, E, F, G, A, B

//////////////////////////////////////////////
void setup() {
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  pinMode(LCDswitchPin, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); // o lcd fica desligado enquando esta em modo piano
  lcd.noBacklight();
} //fim setup

//////////////////////////////////////////////
void loop() {
  
  LCDswitchState = digitalRead(LCDswitchPin);
  short keyVal = analogRead(A0);
  Serial.println(keyVal);
  lcd.noDisplay();
  digitalWrite(LED, LOW); // o led do menu desligase sempre que chega ao fim
 
// ************** começa "LCDstart" quando carrega no butao menu ***********

    if (LCDswitchState == HIGH)  {
      digitalWrite(LED, HIGH); //led liga-se quando se entra no menu para se saber que esta no modo menu e o piano off
      lcd.display();
      lcd.clear();
      LCDstart();
      }
   
// ***********************************************************************

////// teclado piano e frequencias //////
// 220 ohm = C5 // 560 ohm = D5 // 1K ohm = E5 // etc...
  if(keyVal == 1023)  {
    tone(8, notes[0]); // do
    } // end if
    
        else if(keyVal >= 990 & keyVal <=1010)  {
          tone(8, notes[1]); // re
          } // end else if
    
        else if(keyVal >= 960 && keyVal <= 980)  {
          tone(8, notes[2]); // mi
          } // end else if
        
        else if(keyVal >= 900 && keyVal <= 945)  {
          tone(8, notes[3]); // fa
          } // end else if
        
        else if(keyVal >= 650 && keyVal <= 710)  {
          tone(8, notes[4]); // so
          } // end else if
        
        else if(keyVal >= 500 && keyVal <= 550)  {
          tone(8, notes[5]); //la
          } // end else if
        
        else if(keyVal >= 5 && keyVal <= 10)  {
          tone(8, notes[6]); // si
          } // end else if
        
        else if(keyVal <= 1)  { //se nao se carregar em nenhum butao nao faz som
          noTone(8);
          } // end else if

} //fim do loop do tom da frequência 

/////////////////////////////////////////////////////
void LCDstart()  {
  short keyVal = analogRead(A0);  
  LCDswitchState = digitalRead(LCDswitchPin); // ve se o buttao para menu foi carregado
  lcd.backlight();
    while (LCDswitchState == LOW)  { //continua o loop enquanto o butao do menu nao é carregado
      LCDswitchState = digitalRead(LCDswitchPin); // ve sempre o estado do butao do menu no inicio de cada loop
      
      //************* inicio do titulo musica 1  ********************
      if (LCDswitchState == HIGH)  { // se o butao do menu por primido
        LCDswitchCounter++; // aumenta a contagem do butao neste caso +1
        Serial.print("butao carregado:  ");
        Serial.println(LCDswitchCounter);
        delay(300); 

        Song1title();//chama a muscia 1
        lcd.clear();
        break;
        }

      //************* ELSE SHOW MENU ****************
      else   {  // se o butao do menu nao for primido
        LCDswitchCounter=0; // mete o contador do butao a 0
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Selecione uma");
        lcd.setCursor(0, 1);
        lcd.print("musica p/ tocar");
        delay(50); // return to main 
        }
     
      } // fim while
  } // fim loop LCDstart
  
  
  

// ************* SONG 1 LOOP STARTS HERE **************  
void Song1title()  {
  short keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 2 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 2
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song2title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed   
        short keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(LED, LOW);
           Song1();
           break;
           } // end if
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SUPER MARIO BROS");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
    } // end while song 1 -> 2
        
} // end Song1title loop




// ************* musica 2 começa aqui **************  
void Song2title()  {
  short keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // ve outraves o estado do butao do menu
  
  while (LCDswitchState == LOW)  { // se o butao menu nao for primido continua  
    LCDswitchState = digitalRead(LCDswitchPin); //  ve outraves o estado do butao do menu 

      //************* chama o titulo da musica 3********************
      if (LCDswitchState == HIGH)  { // se o butao do menu nao for primido
        LCDswitchCounter++; // aumenta o contador neste caso para 3
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300);

        Song3title();
        lcd.clear();
        break;
        }
        
      else  { // se o butao do menu nao for primido
        short keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(LED, LOW);
           Song2();
           break;
           } // fim if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("    StarWars");
          lcd.setCursor(0, 1);
          lcd.print(" Imperial March");
          delay(50);
          }
        
        } // fim while muscia 2 -> 3
        
} // fim loop Song2title




// ************* SONG 3 LOOP STARTS HERE **************  
void Song3title()  {
  short keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 4
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song4title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        short keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(LED, LOW);
           Song3();
           break;
           } // end if
           
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Harry Potter");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
        
        } // end while song 3 -> 4
        
} // end Song3title loop





// ************* SONG 4 LOOP STARTS HERE **************  
void Song4title()  {
  short keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 5 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 5
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song5title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        short keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(LED, LOW);
           Song4();
           break;
           } // end if
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Game of Thrones");
          lcd.setCursor(0, 1);
          lcd.print("     Opening");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song4title loop




// ************* SONG 5 LOOP STARTS HERE **************  
void Song5title()  {
  short keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 5 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter=0; // set button count to 0
        lcd.noBacklight();
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more
        lcd.clear();
        }
        
      else  { // if menu button is not pressed
        short keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(LED, LOW);
           Song5();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     Darude");
          lcd.setCursor(0, 1);
          lcd.print("   Sandstrom");
          delay(50);
          }
        
        } // end while song 5 -> 6
        
} // end Song5title loop


void beep(short note, short duration)//starwars
{
  //Play tone on 8
  tone(8, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(6, HIGH);
    delay(duration);
    digitalWrite(6, LOW);
  }else
  {
    digitalWrite(6, HIGH);
    delay(duration);
    digitalWrite(6, LOW);
  }
 
  //Stop tone on 8
  noTone(8);
 
  delay(50);
 
  //Increment counter
  counter++;
}

/*##########Script Information###############################
  # Purpose: Cable Fault Detection Using Ohm's Law
  # Features: Buzzer & LED indication    
  # Created: 17-07-2022                                  
  # Author : Rumesh                                  
  ###########################################################*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// define phase control pins
int phase[3] = {7, 8, 9};

// define LED pins
#define ledr 6 
#define ledy 10  
#define ledg 13  


#define buzzer 0 
//*********************************************************
//update values in "" part in below function

int distance(int inputVoltage) {
  if (inputVoltage >= "" && inputVoltage < "") {
    return 20;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 18;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 16;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 14;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 12;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 10;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 8;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 6;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 4;
  }
  else if (inputVoltage >= "" && inputVoltage < "") {
    return 2;
  }
  else return 0 ;
}
//*********************************************************

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  lcd.print("Cable Fault");
  lcd.setCursor(3,1);
  lcd.print("Detector");
  delay(500);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print( "Simulated");
  lcd.setCursor(3,1);
  lcd.print( "By Rumesh");
  delay(1000);
  lcd.clear();

  // set pin mode for phase relays
  for (int j = 0; j < 3; j++) {
    pinMode(phase[j], OUTPUT);
  }

}

void loop() {
  digitalWrite(phase[0], HIGH);
  delay(500);
  int dist1 = distance(analogRead(A0));
  if (dist1 == 0) {
    lcd.setCursor(0, 0);
    lcd.write("R: ");
    lcd.setCursor(3, 0);
    lcd.write("NF   ");
    digitalWrite(ledr, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.write("R: ");
    lcd.setCursor(3, 0);
    lcd.write(' ');
    lcd.print(dist1);
    lcd.setCursor(6, 0);
    lcd.write("Km");
    digitalWrite(ledr, HIGH);
    digitalWrite(buzzer,HIGH);
  }
  digitalWrite(phase[0], LOW);
  //================================================
  digitalWrite(phase[1], HIGH);
  delay(500);
  int dist2 = distance(analogRead(A0));
  if (dist2 == 0) {
    lcd.setCursor(9, 0);
    lcd.write("Y: ");
    lcd.setCursor(11, 0);
    lcd.write("NF   ");
    digitalWrite(ledy, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
    lcd.setCursor(9, 0);
    lcd.write("Y: ");
    lcd.setCursor(11, 0);
    lcd.write(' ');
    lcd.print(dist2);
    lcd.setCursor(14, 0);
    lcd.write("Km");
    digitalWrite(ledy, HIGH);
    digitalWrite(buzzer,HIGH);
    
  }
  digitalWrite(phase[1], LOW);
  //=================================================
  digitalWrite(phase[2], HIGH);
  delay(500);
  int dist3 = distance(analogRead(A0));
  if (dist3 == 0) {
     lcd.setCursor(0, 1);
    lcd.write("G: ");
    lcd.setCursor(3, 1);
    lcd.write("NF   ");
    digitalWrite(ledg, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.write("G: ");
    lcd.setCursor(3, 1);
    lcd.write(' ');
    lcd.print(dist3);
    lcd.setCursor(6, 1);
    lcd.write("Km");
    digitalWrite(ledg, HIGH);
    digitalWrite(buzzer,HIGH);
  }
  digitalWrite(phase[2], LOW);
}

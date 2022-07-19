/*##########Script Information###############################
  # Purpose: Cable Fault Detection Using Ohm's Law    
  # Created: 13-07-2022                                  
  # Author : Rumesh                                  
  ###########################################################*/
  
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// define phase control pins
int phase[3] = {7, 8, 9};

//*********************************************************
int distance(int inputVoltage) { //update values in "" part
  if (inputVoltage >= "" && inputVoltage < "") {
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
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  lcd.print("Cable Fault");
  lcd.setCursor(4,1);
  lcd.print("Detector");
  delay(1000);
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
  }
  else {
    lcd.setCursor(0, 0);
    lcd.write("R: ");
    lcd.setCursor(3, 0);
    lcd.print(dist1);
    lcd.setCursor(4, 0);
    lcd.write(" KM");
  }
  digitalWrite(phase[0], LOW);
  //================================================
  digitalWrite(phase[1], HIGH);
  delay(500);
  int dist2 = distance(analogRead(A0));
  if (dist2 == 0) {
    lcd.setCursor(8, 0);
    lcd.write("Y: ");
    lcd.setCursor(11, 0);
    lcd.write("NF   ");
  }
  else {
    lcd.setCursor(8, 0);
    lcd.write("Y: ");
    lcd.setCursor(11, 0);
    lcd.print(dist2);
    lcd.setCursor(12, 0);
    lcd.write(" KM");
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
  }
  else {
    lcd.setCursor(0, 1);
    lcd.write("G: ");
    lcd.setCursor(3, 1);
    lcd.print(dist3);
    lcd.setCursor(4, 1);
    lcd.write(" KM");
  }
  digitalWrite(phase[2], LOW);
}

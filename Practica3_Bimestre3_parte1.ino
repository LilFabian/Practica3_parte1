#include <LedControl.h>
#define din_matrix  3
#define cs_matrix   2
#define clk_matrix  4

LedControl PacmanMatrix = LedControl(din_matrix,clk_matrix,cs_matrix,1);

int pot;
int velocidad;

byte pacman_boca_abierta[8]={
  B00111100,
  B01000010,
  B10001001,
  B10000001,
  B10000111,
  B10000001,
  B01000010,
  B00111100,
  
  };

  byte pacman_boca_cerrada[8]={
  B00111100,
  B01000010,
  B10001010,
  B10000100,
  B10001000,
  B10000100,
  B01000010,
  B00111100,
  };

   

void setup() {
 Serial.begin(9600);
 PacmanMatrix.shutdown(0, false);
 PacmanMatrix.setIntensity(0,15);
 PacmanMatrix.clearDisplay(0);
   
  
}

void loop() {
  
  pot = analogRead(A7);
  velocidad = map(pot,0,1023,300,3000);
  Serial.println(velocidad);
  Serial.println(pot);
  Pacman_Abierto();
  delay(velocidad);
  Pacman_Cerrado();  
  delay(velocidad);

  

}

void Pacman_Abierto(){
  for(int i=0; i<8; i++){
    PacmanMatrix.setRow(0,i, pacman_boca_abierta[i]);
     }
   }
   
    void Pacman_Cerrado(){
      for(int i=0; i<8; i++){
      PacmanMatrix.setRow(0,i, pacman_boca_cerrada[i]);
      }
  }

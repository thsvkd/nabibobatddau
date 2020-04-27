#include <Stepper.h>
#include <ArduinoSTL.h>
#include <StepperMulti.h>

using namespace std;

const int stepsPerRevolution = 200;
const float tempo = 122;


Stepper myStepper(stepsPerRevolution, 6, 8, 7, 9); //6879
Stepper myStepper2(stepsPerRevolution, 2, 4, 3, 5);
//StepperMulti  multimyStepper(stepsPerRevolution, 6, 8, 7, 9); //6879
//StepperMulti  multimyStepper2(stepsPerRevolution, 2, 4, 3, 5);


const float note_16 = ((float)1000 * (float)15) / tempo; 
const float note_1 = note_16 * 16; 
const float note_2 = note_16 * 8;
const float note_4 = note_16 * 4;
const float note_8 = note_16 * 2;
const float note_32 = note_16 / 2;
const float note_64 = note_16 / 4;

const float c1 = 32.7;
const float c1f = 34.65;
const float d1 = 36.71;
const float e1b = 38.89;
const float e1 = 41.2;
const float f1 = 43.65;
const float f1f = 46.25;
const float g1 = 49;
const float g1f = 51.91;
const float a1 = 55;
const float b1b = 58.27;
const float b1 = 61.74;

const float c2 = 65.41;
const float c2f = 69.3;
const float d2 = 73.42;
const float e2b = 77.78;
const float e2 = 82.41;
const float f2 = 87.31;
const float f2f = 92.5;
const float g2 = 98;
const float g2f = 103.8;
const float a2 = 110;
const float b2b = 116.5;
const float b2 = 123.5;

const float c3 = 130.8;
const float c3f = 138.6;
const float d3 = 146.8;
const float e3b = 155.6;
const float e3 = 164.8;
const float f3 = 174.6;
const float f3f = 185;
const float g3 = 196;
const float g3f = 207.7;
const float a3 = 220;
const float b3b = 233.1;
const float b3 = 246.9;

const float c4 = 261.6;
const float c4f = 277.2;
const float d4 = 293.7;
const float e4b = 311.1;
const float e4 = 329.6;
const float f4 = 349.2;
const float f4f = 370;
const float g4 = 392;
const float g4f = 415.3;
const float a4 = 440;
const float b4b = 466.2;
const float b4 = 493.9;

const float c5 = 523.3;
const float c5f = 554.4;
const float d5 = 587.3;
const float e5b = 622.3;
const float e5 = 659.3;
const float f5 = 698.5;
const float f5f = 740;
const float g5 = 784;
const float g5f = 830.6;
const float a5 = 880;
const float b5b = 932.3;
const float b5 = 987.8;

enum NOTE{
  n_1,
  n_2,
  n_4,
  n_8,
  n_16,
  n_32,
  n_64
};


enum PITCH{
  p_C1 ,
  p_C1f,
  p_D1 ,
  p_E1b,
  p_E1 ,
  p_F1 ,
  p_F1f,
  p_G1 ,
  p_G1f,
  p_A1 ,
  p_B1b,
  p_B1 ,
  p_C2 ,
  p_C2f,
  p_D2 ,
  p_E2b,
  p_E2 ,
  p_F2 ,
  p_F2f,
  p_G2 ,
  p_G2f,
  p_A2 ,
  p_B2b,
  p_B2 ,
  p_C3 ,
  p_C3f,
  p_D3 ,
  p_E3b,
  p_E3 ,
  p_F3 ,
  p_F3f,
  p_G3 ,
  p_G3f,
  p_A3 ,
  p_B3b,
  p_B3 ,
  p_C4 ,
  p_C4f,
  p_D4 ,
  p_E4b,
  p_E4 ,
  p_F4 ,
  p_F4f,
  p_G4 ,
  p_G4f,
  p_A4 ,
  p_B4b,
  p_B4 ,
  p_C5 ,
  p_C5f,
  p_D5 ,
  p_E5b,
  p_E5 ,
  p_F5 ,
  p_F5f,
  p_G5 ,
  p_G5f,
  p_A5 ,
  p_B5b,
  p_B5 
};

void multiturn(Stepper moter1, Stepper moter2, float Step)
{
  int i = 0;
  for(i = 0;i < Step; i++)
  {
    moter1.step(1);
    moter2.step(1);
  }
}

void note(float duration_ms, float pitch)
{
  //duration_ms -= note_64;
  float duration = (3.4)* (duration_ms * pitch) / 1000;
  Serial.println(duration);
  myStepper2.setSpeed(pitch);
  myStepper2.step(duration);
  //delay(note_64);
}

void rest(float duration_ms)
{
  delay(duration_ms);
}

void high_part1()
{
  ////////////////////////////1

/*
  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  */

  ////////////////////////////2

  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,g5);
  note(note_4+note_16,e5);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,g5);
  note(note_4+note_16,e5);

  rest(note_8);
  note(note_8,e5);
  note(note_16,g5);
  note(note_8,a5);
  note(note_2+note_16,e5);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_8,g3);

  ////////////////////////////4

  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8-note_64,a4);
  rest(note_64);
  note(note_16,a4);
  note(note_8,g5);
  note(note_2+note_16,e5);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  ////////////////////////////5

  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,g5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,e5);
  note(note_16,g5);
  note(note_8,a5);
  note(note_2+note_16,e5);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_16,g3);
  note(note_8,g5);
  note(note_8,f5);

  ////////////////////////////6

  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_8,e5b);
  note(note_8,d5);
  note(note_8,c5);
  note(note_8,a4);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  note(note_8,a3);
  rest(note_8);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_4,a3);
  rest(note_4);

  ////////////////////////////7
  
  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////9

  note(note_16-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);

  note(note_16-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);

  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);

  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);

  ////////////////////////////10
  
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);
  note(note_16-note_64,a3);
  rest(note_64);
  note(note_8-note_64,a3);
  rest(note_64);

  note(note_16-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);
  note(note_16-note_64,b3);
  rest(note_64);
  note(note_8-note_64,b3);
  rest(note_64);

  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);

  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_16-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  note(note_8-note_64,g3f);
  rest(note_64);
  rest(note_8);
  note(note_8,b4);
  note(note_8,c5);

  ////////////////////////////11
  
  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  note(note_8,f4f);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,g5);
  note(note_4+note_16,g5);
  rest(note_4);

  rest(note_8);
  note(note_8,e5);
  note(note_16,g5);
  note(note_8,a5);
  note(note_2+note_16,e5);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_8,g3);

  ////////////////////////////12
  
  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,g5);
  note(note_4+note_16,e5);

  rest(note_8);
  note(note_8-note_64,a4);
  rest(note_64);
  note(note_16,a4);
  note(note_8,g5);
  note(note_2+note_16,e5);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  ////////////////////////////13
  
  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_4,e5);
  rest(note_4);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,g5);
  note(note_4+note_16,e5);

  rest(note_8);
  note(note_8,e5);
  note(note_16,g5);
  note(note_8,a5);
  note(note_2+note_16,e5);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_8,g3);
  rest(note_16);
  note(note_8,g3);

  ////////////////////////////14
  
  note(note_8,e5);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_16+note_2,e5);

  rest(note_4+note_8);
  note(note_4,c5);
  note(note_8,b4);
  note(note_8,g4);
  note(note_8,a4);

  note(note_8,a4);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  ////////////////////////////15
  
  rest(note_2+note_8);
  note(note_8,a4);
  note(note_8,c5);
  note(note_16,d5);
  note(note_16,e5);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_8,e5b);
  note(note_8,d5);
  note(note_8,c5);
  note(note_8,a4);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_16,g3);
  rest(note_16);
  note(note_16,g3);
  rest(note_16);
  note(note_16,g3);

  ////////////////////////////16
  
  rest(note_2+note_8);
  note(note_8,a4);
  note(note_8,c5);
  note(note_16,d5);
  note(note_16,e5);

  rest(note_8);
  note(note_8,a4);
  note(note_16,c5);
  note(note_8,d5);
  note(note_8,e5b);
  note(note_8,d5);
  note(note_8,c5);
  note(note_8,a4);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  rest(note_8);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);
  rest(note_16);
  note(note_8,g3f);

  ////////////////////////////17
  
  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

}

void high_part2()
{
  ////////////////////////////1

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////2

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);

  ////////////////////////////4

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  ////////////////////////////5

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_16,d4);
  rest(note_4);

  ////////////////////////////6

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_4);

  rest(note_1);

  ////////////////////////////7

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////9

  note(note_16-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);

  note(note_16-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);

  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);

  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);

  ////////////////////////////10

  note(note_16-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);
  note(note_16-note_64,c4);
  rest(note_64);
  note(note_8-note_64,c4);
  rest(note_64);

  note(note_16-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);
  note(note_16-note_64,d4);
  rest(note_64);
  note(note_8-note_64,d4);
  rest(note_64);

  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);

  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_16-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  note(note_8-note_64,c4f);
  rest(note_64);
  rest(note_8);
  note(note_8,d5);
  note(note_8,e5b);
  
  ////////////////////////////11

  note(note_8-note_64,a4);
  rest(note_64);
  rest(note_1-note_8);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  
  ////////////////////////////12

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  
  ////////////////////////////13

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  
  ////////////////////////////14

  rest(note_1);

  rest(note_1);

  note(note_8,a4);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  
  ////////////////////////////15

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  
  ////////////////////////////16

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_8);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  
  ////////////////////////////17

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
}

void high_part3()
{
  ////////////////////////////1

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////2

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  ////////////////////////////4

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  ////////////////////////////5

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_16,c4f);
  rest(note_4);

  ////////////////////////////6

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_4);

  rest(note_1);

  ////////////////////////////7

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////9

  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);

  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);

  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);

  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);

  ////////////////////////////10

  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);

  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);
  note(note_16-note_64,f4f);
  rest(note_64);
  note(note_8-note_64,f4f);
  rest(note_64);

  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);

  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_16-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  note(note_8-note_64,e4);
  rest(note_64);
  rest(note_8+note_4);
  
  ////////////////////////////11

  note(note_8,e5);
  rest(note_1-note_8);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  
  ////////////////////////////12

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  
  ////////////////////////////13

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  
  ////////////////////////////14

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  
  ////////////////////////////15

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  
  ////////////////////////////16

  rest(note_1);

  rest(note_1);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  
  ////////////////////////////17

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
}

void high_part4()
{
  ////////////////////////////1

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////2

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////4

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////5

  rest(note_1);
 
  rest(note_1);

  rest(note_1);

  rest(note_2);
  note(note_8,f4);
  rest(note_2-note_8);

  ////////////////////////////6

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////7

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////9

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////10

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////11

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_2);
  note(note_8,f4);
  rest(note_16);
  note(note_8,f4);
  rest(note_16);
  note(note_8,f4);
  
  ////////////////////////////12

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////13

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_2);
  note(note_8,f4);
  rest(note_16);
  note(note_8,f4);
  rest(note_16);
  note(note_8,f4);
  
  ////////////////////////////14

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////15

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_2);
  note(note_8,f4);
  rest(note_16);
  note(note_8,f4);
  rest(note_16);
  note(note_8,f4);
  
  ////////////////////////////16

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////17

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
}

void low_part1()
{
  ////////////////////////////1
  note(note_8+note_16,d3);
  note(note_8+note_16,a3);
  note(note_4,d4);
  note(note_8,d3);
  note(note_8,a3);
  note(note_16,d3);
  note(note_16,e3b);
  
  note(note_8+note_16,e3);
  note(note_8+note_16,b3);
  note(note_4,e4);
  note(note_8,e3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_16,g3f);
  
  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_4,a3);
  note(note_8,a2);
  note(note_8,e3);
  note(note_16,g2);
  note(note_16,g2f);
  
  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_16,b3b);
  note(note_4-note_16,b3);
  note(note_8,a3);
  note(note_8,e3);
  note(note_8,e3b);

////////////////////////////////// 2

  note(note_4,d3);
  note(note_8+note_16,a3);
  note(note_8+note_16,d4);
  note(note_8,d3);
  note(note_8,a3);
  note(note_16,d3);
  note(note_16,e3b);

  note(note_4,e3);
  note(note_8+note_16,b3);
  note(note_8+note_16,e4);
  note(note_8,e3);
  note(note_8,b3);
  note(note_16,g2);
  note(note_16,g2f);

  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_4,a3);
  note(note_8,a2);
  note(note_8,e3);
  note(note_16,g2);
  note(note_16,g2f);

  note(note_8,a2);
  rest(note_4+note_8);
  note(note_16,a2);
  rest(note_4-note_16);
  note(note_16,a2);
  rest(note_4-note_16);

//////////////////////////////////// 3
  
  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);

  note(note_4,a2);
  note(note_4,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);

////////////////////////////////// 4

  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_4,a2);
  note(note_4,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);

////////////////////////////////// 5

  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);

  note(note_4,a2);
  note(note_4,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_8,e3b);
  note(note_8,c3);
  note(note_8,c3f);

////////////////////////////////// 6

  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

  rest(note_1);

////////////////////////////////// 7

  note(note_8+note_16,d3);
  note(note_8+note_16,a3);
  note(note_4,d4);
  note(note_8,d3);
  note(note_8,a3);
  note(note_16,d3);
  note(note_16,e3b);
  
  note(note_8+note_16,e3);
  note(note_8+note_16,b3);
  note(note_4,e4);
  note(note_8,e3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_16,g3f);
  
  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_4,a3);
  note(note_8,a2);
  note(note_8,e3);
  note(note_16,g2);
  note(note_16,g2f);
  
  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_16,b3b);
  note(note_4-note_16,b3);
  note(note_8,a3);
  note(note_8,e3);
  note(note_8,e3b);

////////////////////////////////// 8

  note(note_8+note_16,d3);
  note(note_8+note_16,a3);
  note(note_4,d4);
  note(note_8,d3);
  note(note_8,a3);
  note(note_16,d3);
  note(note_16,e3b);
  
  note(note_8+note_16,e3);
  note(note_8+note_16,b3);
  note(note_4,e4);
  note(note_8,e3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_16,g3f);
  
  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_4,a3);
  note(note_8,a2);
  note(note_8,e3);
  note(note_16,g2);
  note(note_16,g2f);
  
  note(note_8,a2);
  note(note_8,a3);
  note(note_8,b2);
  note(note_8,b3);
  note(note_8,c3);
  note(note_8,c4);
  note(note_8,b3);
  note(note_8,c4);

////////////////////////////////// 9

  note(note_4,d2);
  note(note_4+note_8-note_64,c3);
  rest(note_64);
  note(note_8+note_16,a2);
  note(note_8+note_16,d2);
  
  note(note_4,e2);
  note(note_4+note_8-note_64,d3);
  rest(note_64);
  note(note_8+note_16,b2);
  note(note_8+note_16,e2);

  note(note_4,a1);
  note(note_4+note_8-note_64,c3f);
  rest(note_64);
  note(note_8+note_16,c3f);
  note(note_8+note_16,d2);

  note(note_4,a1);
  note(note_4+note_8-note_64,c3f);
  rest(note_64);
  note(note_8+note_16,c3f);
  note(note_8+note_16,a2);

////////////////////////////////// 10

  note(note_4,d2);
  note(note_4+note_8-note_64,c3);
  rest(note_64);
  note(note_8+note_16,a2);
  note(note_8+note_16,d2);
  
  note(note_4,e2);
  note(note_4+note_8-note_64,d3);
  rest(note_64);
  note(note_8+note_16,b2);
  note(note_8+note_16,e2);

  note(note_4,a1);
  note(note_4+note_8-note_64,c3f);
  rest(note_64);
  note(note_8+note_16,c3f);
  note(note_8+note_16,d2);


  note(note_4,a1);
  note(note_4-note_64,c3f);
  rest(note_64);
  note(note_8,a2);
  rest(note_8);
  note(note_8,c3);
  note(note_8,c3f);

////////////////////////////////// 11

  note(note_8,d3);
  rest(note_2);
  note(note_16,f3);
  note(note_8,a4);
  note(note_16,f4);
  note(note_8,a4);

  note(note_8,e3);
  rest(note_2);
  note(note_16,g3);
  note(note_8,b3);
  note(note_8,g3);
  note(note_8,b3);

  note(note_4,a2);
  note(note_4,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);

////////////////////////////////// 12

  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_4,a2);
  note(note_4,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

////////////////////////////////// 13

  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);

  note(note_4,a2);
  note(note_4,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);

////////////////////////////////// 14

  note(note_4,d3);
  note(note_4-note_64,a3);
  rest(note_64);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

////////////////////////////////// 15

  note(note_8,d3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_8,b3);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

  note(note_8,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,a2);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);
  note(note_16,e3b);
  rest(note_8);


////////////////////////////////// 16

  note(note_8,d3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);
  note(note_16,f3);
  note(note_8,a3);

  note(note_4,e3);
  note(note_4-note_64,b3);
  rest(note_64);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);
  note(note_16,e3);
  note(note_8,g3f);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

  note(note_8,a2);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);
  note(note_16,e3);
  rest(note_8);

////////////////////////////////// 17

  note(note_8+note_16,d3);
  note(note_8+note_16,a3);
  note(note_4,d4);
  note(note_8,d3);
  note(note_8,a3);
  note(note_16,d3);
  note(note_16,e3b);
  
  note(note_8+note_16,e3);
  note(note_8+note_16,b3);
  note(note_4,e4);
  note(note_8,e3);
  note(note_8,b3);
  note(note_16,g3);
  note(note_16,g3f);
  
  note(note_8+note_16,a2);
  note(note_8+note_16,e3);
  note(note_4,a3);
  note(note_8,a2);
  note(note_8,e3);
  note(note_16,g2);
  note(note_16,g2f);

  note(note_8,a2);
  rest(note_8+note_4+note_2);
}

void low_part2()
{
  ////////////////////////////1

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////2

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4-note_64,d4);
  rest(note_64);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);

  rest(note_4);
  note(note_4-note_64,g3f);
  rest(note_64);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_1);

  ////////////////////////////4

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4,d4);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);

  rest(note_4);
  note(note_4-note_64,g3f);
  rest(note_64);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_1);

  ////////////////////////////5

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4-note_64,d4);
  rest(note_64);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);

  rest(note_4);
  note(note_4-note_64,g3f);
  rest(note_64);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_1);

  ////////////////////////////6

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4,d4);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);

  rest(note_1);

  rest(note_1);

  ////////////////////////////7

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1-note_4);
  note(note_8,d4);
  note(note_8,e4b);

  ////////////////////////////9

  rest(note_4);
  note(note_4+note_8,e3);
  note(note_8+note_16,c3);
  rest(note_8+note_16);

  rest(note_4);
  note(note_4+note_8,f3f);
  note(note_8+note_16,d3);
  rest(note_8+note_16);

  rest(note_4);
  note(note_4+note_8-note_64,e3);
  rest(note_64);
  note(note_8+note_16,e3);
  rest(note_8+note_16);

  rest(note_4);
  note(note_4+note_8-note_64,e3);
  rest(note_64);
  note(note_8+note_16,e3);
  rest(note_8+note_16);

  ////////////////////////////10

  rest(note_4);
  note(note_4+note_8,e3);
  note(note_8+note_16,c3);
  rest(note_8+note_16);

  rest(note_4);
  note(note_4+note_8,f3f);
  note(note_8+note_16,d3);
  rest(note_8+note_16);

  rest(note_4);
  note(note_4+note_8-note_64,e3);
  rest(note_64);
  note(note_8+note_16,e3);
  rest(note_8+note_16);

  rest(note_4);
  note(note_4-note_64,e3);
  rest(note_64);
  note(note_8,c3f);
  rest(note_4+note_8);

  ////////////////////////////11

  note(note_8,f3);
  rest(note_2+note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  note(note_8,b3);
  rest(note_2+note_16);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);

  rest(note_4);
  note(note_4-note_64,g3f);
  rest(note_64);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_1);

  ////////////////////////////12

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4,d4);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);

  rest(note_4);
  note(note_4-note_64,g3f);
  rest(note_64);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_1);

  ////////////////////////////13

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4-note_64,d4);
  rest(note_64);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);

  rest(note_4);
  note(note_4-note_64,g3f);
  rest(note_64);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);
  rest(note_16);
  note(note_8,c4f);

  rest(note_1);

  ////////////////////////////14

  rest(note_4);
  note(note_4-note_64,c4);
  rest(note_64);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4,d4);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);

  rest(note_1);

  rest(note_1);

  ////////////////////////////15

  rest(note_8);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4-note_64,d4);
  rest(note_64);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);
  rest(note_16);
  note(note_8,d4);

  rest(note_1);

  rest(note_1);

  ////////////////////////////16

  rest(note_8);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);
  rest(note_16);
  note(note_8,c4);

  rest(note_4);
  note(note_4,d4);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);
  rest(note_16);
  note(note_8,b3b);

  rest(note_1);

  rest(note_1);

  ////////////////////////////17

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

}

void low_part3()
{
  ////////////////////////////1

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////2

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4-note_64,f4f);
  rest(note_64);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);

  rest(note_4);
  note(note_4-note_64,c4f);
  rest(note_64);
  rest(note_2);

  rest(note_1);

  ////////////////////////////4

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4,f4f);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4-note_64,c4f);
  rest(note_64);
  rest(note_2);

  rest(note_1);

  ////////////////////////////5

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4-note_64,f4f);
  rest(note_64);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);

  rest(note_4);
  note(note_4-note_64,c4f);
  rest(note_64);
  rest(note_2);

  rest(note_1);

  ////////////////////////////6

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4,f4f);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_1);

  rest(note_1);

  ////////////////////////////7

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////9

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);


  ////////////////////////////10

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_2);
  note(note_8,e3);
  rest(note_4+note_8);

  ////////////////////////////11

  note(note_8,a3);
  rest(note_2+note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  note(note_8,d4);
  rest(note_2+note_16);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);

  rest(note_4);
  note(note_4,c4f);
  rest(note_2);

  rest(note_1);

  ////////////////////////////12

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4,f4f);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4-note_64,c4f);
  rest(note_64);
  rest(note_2);

  rest(note_1);

  ////////////////////////////13

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4-note_64,f4f);
  rest(note_64);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);

  rest(note_4);
  note(note_4-note_64,c4f);
  rest(note_64);
  rest(note_2);

  rest(note_1);

  ////////////////////////////14

  rest(note_4);
  note(note_4-note_64,e4);
  rest(note_64);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4,f4f);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_1);

  rest(note_1);

  ////////////////////////////15

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4-note_64,f4f);
  rest(note_64);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);
  rest(note_16);
  note(note_8,f4f);

  rest(note_1);

  rest(note_1);

  ////////////////////////////16

  rest(note_8);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_4);
  note(note_4,f4f);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);
  rest(note_16);
  note(note_8,e4);

  rest(note_1);

  rest(note_1);

  ////////////////////////////17

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

}

void low_part4()
{
  ////////////////////////////1

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////2

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////3

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////4

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////5

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////6

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////7

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////8

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////9

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);

  ////////////////////////////10

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////11

  note(note_8,c4);
  rest(note_1-note_8);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////12

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////13

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////14

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////15

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////16

  rest(note_1);

  rest(note_1);

  rest(note_1);

  rest(note_1);
  
  ////////////////////////////17
}

void low_low_part1()
{
  note(note_8,c2);
  note(note_8,c2f);
}

void setup() {
  
  myStepper.setSpeed(220);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(note_1);
  Serial.println(note_2);
  Serial.println(note_4);
  Serial.println(note_8);
  Serial.println(note_16);


  high_part1();
}


/*
 
 */

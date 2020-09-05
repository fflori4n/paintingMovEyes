
#define _step_A 7
#define _step_B 6
#define _step_C 5
#define _step_D 4

#define _step2_A 8
#define _step2_B 9
#define _step2_C 10
#define _step2_D 11

#define DOPSENS0 3
#define PIRSENS0 12

// motor 0 - +up -down  // max 480 in full step
//motor 1 - +left -right //max 1300 in full step
void moveStepper(int motor = 0, int stepnum = 1) {
  int timep = 5;
  bool dir = 1;
  static int i = 0;
  if(stepnum < 0){
    stepnum = -stepnum;
    dir = 0;
    }

  Serial.println(F("stepping"));
  for (int stepsCompleted = 0; stepsCompleted < stepnum; stepsCompleted++) {
    if (i > 3) {
      i = 0;
    }
    else if (i < 0) {
      i = 3;
    }

    if (motor == 0) {
      switch (i) {
        case 0:
          digitalWrite(_step_A, HIGH);
          break;
        case 1:
          digitalWrite(_step_B, HIGH);
          break;
        case 2:
          digitalWrite(_step_C, HIGH);
          break;
        case 3:
          digitalWrite(_step_D, HIGH);
          break;
      }
    }
    else if (motor == 1) {
      switch (i) {
        case 0:
          digitalWrite(_step2_A, HIGH);
          break;
        case 1:
          digitalWrite(_step2_B, HIGH);
          break;
        case 2:
          digitalWrite(_step2_C, HIGH);
          break;
        case 3:
          digitalWrite(_step2_D, HIGH);
          break;
      }
    }
    else {
      return;
    }
    delay(timep);
    delayMicroseconds(random(10,200));

    digitalWrite(_step_A, LOW);
    digitalWrite(_step_B, LOW);
    digitalWrite(_step_C, LOW);
    digitalWrite(_step_D, LOW);

    digitalWrite(_step2_A, LOW);
    digitalWrite(_step2_B, LOW);
    digitalWrite(_step2_C, LOW);
    digitalWrite(_step2_D, LOW);

    if (dir == 0) {
      i++;
    }
    else {
      i--;
    }
  }
}

// motor 0 - +up -down  // max 480 in full step
//motor 1 - +left -right //max 1300 in full step
void moveStepperHalf(int motor = 0, int stepnum = 1) {
  int timep = 4;  // 4 for silent
  bool dir = 1;
  static int i = 0;
  if(stepnum < 0){
    stepnum = -stepnum;
    dir = 0;
    }

  Serial.println(F("stepping"));
  for (int stepsCompleted = 0; stepsCompleted < stepnum; stepsCompleted++) {
    if (i > 7) {
      i = 0;
    }
    else if (i < 0) {
      i = 7;
    }

    if (motor == 0) {
      switch (i) {
        case 0:
          digitalWrite(_step_A, HIGH);
          break;
        case 1:
          digitalWrite(_step_A, HIGH);
          digitalWrite(_step_B, HIGH);
          break;
        case 2:
          digitalWrite(_step_B, HIGH);
          break;
        case 3:
          digitalWrite(_step_B, HIGH);
          digitalWrite(_step_C, HIGH);
          break;
        case 4:
          digitalWrite(_step_C, HIGH);
          break;
        case 5:
          digitalWrite(_step_C, HIGH);
          digitalWrite(_step_D, HIGH);
          break;
        case 6:
          digitalWrite(_step_D, HIGH);
          break;
        case 7:
          digitalWrite(_step_D, HIGH);
          digitalWrite(_step_A, HIGH);
          break;
      }
    }
    else if (motor == 1) {
      switch (i) {
        case 0:
          digitalWrite(_step2_A, HIGH);
          break;
        case 1:
          digitalWrite(_step2_A, HIGH);
          digitalWrite(_step2_B, HIGH);
          break;
        case 2:
          digitalWrite(_step2_B, HIGH);
          break;
        case 3:
          digitalWrite(_step2_B, HIGH);
          digitalWrite(_step2_C, HIGH);
          break;
        case 4:
          digitalWrite(_step2_C, HIGH);
          break;
        case 5:
          digitalWrite(_step2_C, HIGH);
          digitalWrite(_step2_D, HIGH);
          break;
        case 6:
          digitalWrite(_step2_D, HIGH);
          break;
        case 7:
          digitalWrite(_step2_D, HIGH);
          digitalWrite(_step2_A, HIGH);
          break;
      }
    }
    else {
      return;
    }
    delay(timep);
    delayMicroseconds(random(10,200));

    digitalWrite(_step_A, LOW);
    digitalWrite(_step_B, LOW);
    digitalWrite(_step_C, LOW);
    digitalWrite(_step_D, LOW);

    digitalWrite(_step2_A, LOW);
    digitalWrite(_step2_B, LOW);
    digitalWrite(_step2_C, LOW);
    digitalWrite(_step2_D, LOW);

    if (dir == 0) {
      i++;
    }
    else {
      i--;
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println(F("Serial RDY"));

  pinMode(DOPSENS0, INPUT);    // sets the digital pin 7 as input
  pinMode(PIRSENS0, INPUT);

  pinMode(_step_A, OUTPUT);
  pinMode(_step_B, OUTPUT);
  pinMode(_step_C, OUTPUT);
  pinMode(_step_D, OUTPUT);

  pinMode(_step2_A, OUTPUT);
  pinMode(_step2_B, OUTPUT);
  pinMode(_step2_C, OUTPUT);
  pinMode(_step2_D, OUTPUT);

  /*moveStepper(1,-1500);
  moveStepper(0,600);
  moveStepper(1,650);
  moveStepper(0,-240);*/
  
  moveStepperHalf(1,-1500*2);
  moveStepperHalf(0,600*2);
  moveStepperHalf(1,650*2);
  moveStepperHalf(0,-240*2);
}
void lookLeftRight(){
  moveStepperHalf(1,400);
  delay(500);
  moveStepperHalf(1,-800);
  delay(500);
  moveStepperHalf(1,400);
  }
void loop() {

   // moveStepper(0,600);
   // moveStepper(0,-480);
   // delay(5000);
    //moveStepper(1,1500);
    //moveStepper(1,-1300);
    int val = digitalRead(DOPSENS0); 
    int val2 = digitalRead(PIRSENS0);
    delay(50);
    Serial.print(val);
    Serial.print(",");
    Serial.println(val2);
    //lookLeftRight();
}

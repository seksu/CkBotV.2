// created by sek su

#define carWidth        155
#define carHight        260
#define tireDiameter    66
#define angleUltrasonic 30
#define wheelStep       10
#define pi              3.14259

const int frontMotor[4] = {1,2,3,4};
const int rearMotor[4]  = {5,6,7,8};
const int trigPin[6]    = {2,4,6,8,10,12};
const int echoPin[6]    = {3,5,7,9,11,13};
const int wheelCountPin[4] = {14,15,16,17};

const int perimeter = pi*tireDiameter;
const int astep = perimeter/wheelCount;

int step[4] = {0,0,0,0};
bool state[4] = {false,false,false,false};

void setup() {
  Serial.begin(115200);
  for(int i=0 ; i<4 ; i++){
    pinMode(frontMotor[i],OUTPUT);
    pinMode(rearMotor[i],OUTPUT);
  }
  for(int i=0 ; i<6 ; i++){
    pinMode(trigPin[i],OUTPUT);
    pinMode(echoPin[i],INPUT);
  }
  Serial.println("ckBot is Ready");
}

void loop() {
  
}


int ultrasonicRead(int num){
  
  digitalWrite(trigPin[num],LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[num],HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin[num],LOW);

  int duration = pulseIn(echoPin[num],HIGH);

  return duration*0.034/2;
  
}

void toStraight(int distance,int speed){
  int pwm = map(speed,0,100,0,255);
  for(int i=0 ; i<4 ; i++){
    step[i] = 0;
  }
  
  analogWrite(frontMotor[0],pwm);
  analogWrite(frontMotor[2],pwm);
  analogWrite(rearMotor[0],pwm);
  analogWrite(rearMotor[2],pwn);  
  
  while(1){
    for(int i=0 ; i<4 ; i++){
      if(digitalRead(wheelCountPin[i]) != state[i]){
        state[i] = !state[i];
        step[i]++;
      }
    }
    for(int i=0 ; i<4 ; i++){
      if(step[i] >= distance/astep){
        if(i==0){
          analogWrite(frontMotor[0],0);
        }
        else if(i==1){
          analogWrite(frontMotor[2],0);
        }
        else if(i==2){
          analogWrite(rearMotor[0],0);
        }
        else if(i==3){
          analogWrite(rearMotor[2],0);
        }
      }
    }
  }
}

void uturn(){
  
}


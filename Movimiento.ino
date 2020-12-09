//prueba de motores/

const int motor1Pin1 = 12;
const int motor1Pin2 = 11;
const int motor2Pin1 = 3;
const int motor2Pin2 = 4;
const int p=0;

//Forward sensor/
int cenTrig = 13;
int cenEcho = 10;
float timeCen;
float distanceCen;

//Right sensor/
int cenTrigR = 6;
int cenEchoR = 7;
float timeCenR;
float distanceCenR;

//Left sensor/
int cenTrigL = 8;
int cenEchoL = 9;
float timeCenL;
float distanceCenL;



void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(9600);
  
  //Forward sensor/
  pinMode(cenTrig, OUTPUT);
  pinMode(cenEcho, INPUT);

  //Right sensor/
  pinMode(cenTrigR, OUTPUT);
  pinMode(cenEchoR, INPUT);

    //Left sensor/
  pinMode(cenTrigL, OUTPUT);
  pinMode(cenEchoL, INPUT);
 
}

void stops(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  }
void forward(){
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);

  

  }

void backward(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  }

void left(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

  }

void right(){
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  }

void cp(){
  right();
  }
void loop() {
  //Forward sensor/
  
  digitalWrite(cenTrig, LOW);
  delayMicroseconds(5);
  digitalWrite(cenTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(cenTrig, LOW);
  timeCen = pulseIn(cenEcho, HIGH);
  distanceCen = (0.5 * 0.03432) * timeCen;
  Serial.print(distanceCen);
  Serial.println( "cm");

  //Right sensor/

  digitalWrite(cenTrigR, LOW);
  delayMicroseconds(5);
  digitalWrite(cenTrigR, HIGH);
  delayMicroseconds(5);
  digitalWrite(cenTrigR, LOW);
  timeCenR = pulseIn(cenEchoR, HIGH);
  distanceCenR = (0.5 * 0.03432) * timeCenR;
  Serial.print(distanceCenR);
  Serial.println( "cm");

  //Left sensor/
  
  digitalWrite(cenTrigL, LOW);
  delayMicroseconds(5);
  digitalWrite(cenTrigL, HIGH);
  delayMicroseconds(5);
  digitalWrite(cenTrigL, LOW);
  timeCenL = pulseIn(cenEchoL, HIGH);
  distanceCenL = (0.5 * 0.03432) * timeCenL;
  Serial.print(distanceCenL);
  Serial.println( "cm");

  
    if (distanceCen>25){
      forward();
      
  }
    else if (distanceCen > 26){
      stops();
      delay(950); 
      right();
      delay(695);
     
      

  }
  
     
    else if (distanceCen < 26 && distanceCenR > 26){
      stops();
      delay(950); 
      right();
      delay(695);

  }

    else if (distanceCen < 26 && distanceCenL > 26){
      stops();
      delay(950); 
      left();
      delay(695);

  }

    else if (distanceCen < 26 && distanceCenL < 26 && distanceCenR < 26){
      stops();
      delay(950); 
      left();
      delay(695*2);

  }
    

}

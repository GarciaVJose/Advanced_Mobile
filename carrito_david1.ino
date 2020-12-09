// Sensores HC-SR04
int trigIzq = 8;
int echoIzq = 9;
int trigDer = 6;
int echoDer = 7;
int trigCen = 13;
int echoCen = 10;

float timeIzq, timeDer, timeCen;
float distanceIzq, distanceDer, distanceCen;

// Motores

const int motorIzq1 = 12;
const int motorIzq2 = 11;
const int motorDer1 = 4;
const int motorDer2 = 3;

//int PWM = 10;
int tiempoDeFuncion;
int velocidadDeGiroMotor;


void setup()
{
  // Sensores HC-SR04
  pinMode(trigIzq, OUTPUT);
  pinMode(echoIzq, INPUT);
  pinMode(trigDer, OUTPUT);
  pinMode(echoDer, INPUT);
  pinMode(trigCen, OUTPUT);
  pinMode(echoCen, INPUT);
  
  // Motores
  pinMode(motorIzq1, OUTPUT);
  pinMode(motorIzq2, OUTPUT);
  pinMode(motorDer1, OUTPUT);
  pinMode(motorDer2, OUTPUT);
 
  
  // Monitor Serial
  Serial.begin(9600);
}

void loop()
{
  // Sensor Izquierdo
  digitalWrite(trigIzq, LOW);
  delayMicroseconds(5);
  digitalWrite(trigIzq, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigIzq, LOW);
  timeIzq = pulseIn(echoIzq, HIGH);
  distanceIzq = (0.5 * 0.03432) * timeIzq;//conversion de metro por segundo a centimetro por microsegundo
  
  // Sensor Derecho
  digitalWrite(trigDer, LOW);
  delayMicroseconds(5);
  digitalWrite(trigDer, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigDer, LOW);
  timeDer = pulseIn(echoDer, HIGH);
  distanceDer = (0.5 * 0.03432) * timeDer;
  
  // Sensor Centro
  digitalWrite(trigCen, LOW);
  delayMicroseconds(5);
  digitalWrite(trigCen, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigCen, LOW);
  timeCen = pulseIn(echoCen, HIGH);
  distanceCen = (0.5 * 0.03432) * timeCen;
  
  
  // Motores
  
  
  // Monitoreo de Sensores HC-SR04
  Serial.print(distanceIzq);
  Serial.print(" cm ");
  Serial.print(distanceDer);
  Serial.println(" cm ");
  Serial.print(distanceCen);
  Serial.println(" cm");
  delay(1000);
}


// Set de funciones de movimiento
void Paro(int tiempoDeFuncion)
{
  digitalWrite(motorIzq1, LOW);
  digitalWrite(motorIzq2, LOW);
  digitalWrite(motorDer1, LOW);
  digitalWrite(motorDer2, LOW);
  //Serial.println("   Parado");
  delay(tiempoDeFuncion);
  
}

void Avance(int tiempoDeFuncion, int velocidadDeGiroMotor)
{
  //analogWrite(PWM, velocidadDeGiroMotor);
  digitalWrite(motorIzq1, LOW);
  digitalWrite(motorIzq2, HIGH);
  digitalWrite(motorDer1, HIGH);
  digitalWrite(motorDer2, LOW);
  //Serial.println("   Avanzando");
  delay(tiempoDeFuncion);
  
}

void GiraIzq(int tiempoDeFuncion, int velocidadDeGiroMotor)
{
  //analogWrite(PWM, velocidadDeGiroMotor);  
  digitalWrite(motorIzq1, HIGH);
  digitalWrite(motorIzq2, LOW);
  digitalWrite(motorDer1, HIGH);
  digitalWrite(motorDer2, LOW);
  //Serial.println("   Girando a la Izquierda");
  delay(tiempoDeFuncion);
  
}

void GiraDer(int tiempoDeFuncion, int velocidadDeGiroMotor)
{
  //analogWrite(PWM, velocidadDeGiroMotor);
  digitalWrite(motorIzq1, LOW);
  digitalWrite(motorIzq2, HIGH);
  digitalWrite(motorDer1, LOW);
  digitalWrite(motorDer2, HIGH);
  //Serial.println("   Girando a la Derecha");
  delay(tiempoDeFuncion);
  
}

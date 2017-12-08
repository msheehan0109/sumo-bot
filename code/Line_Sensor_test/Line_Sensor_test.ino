#define Sensor 3
#define Sensor2 12

int x;
//x = sensor 1

int y;
//y = sensor 2

int MotorLF = 9;
int MotorLB = 10;
int MotorRF = 5;
int MotorRB = 6;
void setup() {
  pinMode(1, INPUT);
  pinMode(3, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
  pinMode(MotorLF, OUTPUT);
  pinMode(MotorLB, OUTPUT);
  pinMode(MotorRF, OUTPUT);
  pinMode(MotorRB, OUTPUT);



}

void loop() {

  digitalWrite (MotorLF, HIGH);
  digitalWrite (MotorLB, LOW);
  digitalWrite (MotorRF, LOW);
  digitalWrite (MotorRB, HIGH);
  delay(1000);
  digitalWrite (MotorLF, LOW);
  digitalWrite (MotorLB, HIGH);
  digitalWrite (MotorRF, HIGH);
  digitalWrite (MotorRB, LOW);
  delay(1000);
}

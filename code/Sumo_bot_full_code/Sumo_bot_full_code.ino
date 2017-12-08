#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
#define Sensor 3
#define Sensor2 12
int x;
//x = sensor 1
int y;
//y = sensor 2
#define MotorLF 9
#define MotorLB 10
#define MotorRF 5
#define MotorRB 6
void setup() {
  pinMode(1, INPUT);
  pinMode(3, INPUT);
  pinMode(12, INPUT);
  pinMode(MotorLF, OUTPUT);
  pinMode(MotorLB, OUTPUT);
  pinMode(MotorRF, OUTPUT);
  pinMode(MotorRB, OUTPUT);
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  delay(3000);
  x = digitalRead(11);
  y = digitalRead(12);
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);

  } else {
    Serial.println(" out of range ");
  }

  delay(100);

  if ((measure.RangeMilliMeter < 350) && (measure.RangeMilliMeter > 20))
  {
    Serial.print("FORWARD");
    Serial.println();
    digitalWrite (MotorLF, LOW);
    digitalWrite (MotorLB, HIGH);
    digitalWrite (MotorRF, LOW);
    digitalWrite (MotorRB, HIGH);
    delay(200);
  }
  //RIGHT

  if ((y == HIGH) and (y == LOW))
  {
    Serial.print("RIGHT");
    Serial.println();
    digitalWrite (MotorLF, LOW);
    digitalWrite (MotorLB, LOW);
    digitalWrite (MotorRF, HIGH);
    digitalWrite (MotorRB, LOW);
    delay(1000);
  }
  //LEFT

  if ((x == LOW) and (y == HIGH))
  {
    Serial.print("LEFT");
    Serial.println();
    digitalWrite (MotorLF, HIGH);
    digitalWrite (MotorLB, LOW);
    digitalWrite (MotorRF, LOW);
    digitalWrite (MotorRB, LOW);
    delay(1000);
  }
  if ((measure.RangeMilliMeter > 350) or (measure.RangeMilliMeter < 20))
  {
    Serial.print ("TURN");
    digitalWrite (MotorLF, HIGH);
    digitalWrite (MotorLB, LOW);
    digitalWrite (MotorRF, LOW);
    digitalWrite (MotorRB, HIGH );
    analogWrite (9, 134);
    //analogWrite (10, 134);
   // analogWrite (5, 134);
    analogWrite (6, 134);
   delay(100);
  }
}

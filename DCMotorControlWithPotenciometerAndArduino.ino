//Code is to control the speed of a DC motor by a potentiometer using l298n driver
//We read the value from the analog input, calibrate it then inject to the module
//References: Surtrtech youtube channel and https://www.instructables.com/

//Declaring where our module is wired : IN1 <-> pin 8 / IN2 <-> pin 9
int in1 = 8; 
int in2 = 9;
// ENA <-> pin 10
int ConA = 10;
//speed1 variable
int speed1;

void setup() {
  //pin setup
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  
  pinMode(10, OUTPUT);
}

void TurnMotorA(){ //Function - control the direction and speed
  //HIGH and LOW values: set direction
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  //set speed based on analog value from potenciometer
  speed1 = analogRead(A0);
  speed1 = speed1*0.25; //0.25 - empirically estipulated value
  analogWrite(ConA,speed1);// Then inject it to DC motor
}

void loop() {
  TurnMotorA(); //function keeps looping
}

#define sol_ileri 7
#define sol_geri 8
#define sol_pwm 9
#define sag_ileri 12
#define sag_geri 10
#define sag_pwm 11

int pwm = 250;
char gelenVeri;

int f,b,l,r;

void setup() {
  Serial.begin(9600);
   
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sol_pwm, OUTPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sag_pwm, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) { /* RX/TX */
  gelenVeri = Serial.read();
  Serial.println(gelenVeri);

  analogWrite(sol_pwm, pwm);
  analogWrite(sag_pwm, pwm);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, LOW);
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, LOW);
  
  if(gelenVeri=='F')f=1;
  while(f==1)
  {        
    digitalWrite(sol_pwm, HIGH);
    digitalWrite(sag_pwm, HIGH);
    digitalWrite(sol_ileri, HIGH);
    digitalWrite(sol_geri, LOW);
    digitalWrite(sag_ileri, HIGH);
    digitalWrite(sag_geri, LOW);
    gelenVeri = Serial.read();
    if(gelenVeri=='S')f=0;
  }

  if(gelenVeri=='B')b=1;
  while(b==1)
  {        
    analogWrite(sol_pwm, pwm);
    analogWrite(sag_pwm, pwm);
    digitalWrite(sol_ileri, LOW);
    digitalWrite(sol_geri, HIGH);
    digitalWrite(sag_ileri, LOW);
    digitalWrite(sag_geri, HIGH);
    gelenVeri = Serial.read();
    if(gelenVeri=='S')b=0;
  }
  
  if(gelenVeri=='R')r=1;
  while(r==1)
  {        
    analogWrite(sol_pwm, pwm);
    analogWrite(sag_pwm, pwm);
    digitalWrite(sol_ileri, LOW);
    digitalWrite(sol_geri, HIGH);
    digitalWrite(sag_ileri, HIGH);
    digitalWrite(sag_geri, LOW);
    gelenVeri = Serial.read();
    if(gelenVeri=='S')r=0;
  }

  if(gelenVeri=='L')l=1;
  while(l==1)
  {        
    analogWrite(sol_pwm, pwm);
    analogWrite(sag_pwm, pwm);
    digitalWrite(sol_ileri, HIGH);
    digitalWrite(sol_geri, LOW);
    digitalWrite(sag_ileri, LOW);
    digitalWrite(sag_geri, HIGH);
    gelenVeri = Serial.read();
    if(gelenVeri=='S')l=0;
  }
        
      
}
}

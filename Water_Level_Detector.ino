const int trigPin = 13;
const int echoPin = 11;

float duration;
float Level;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Level = (duration*.0343)/2;

  if (Level > 20)
    {
     Level = 0;
    }

  else
    { 
      Level = (20 - Level)*100;
    }  
    
  Serial.print("The Water's Level is: ");
  Serial.print(Level);
  Serial.println(" ml");
  delay(100);
}

int sensor = 4;
int c =0;
double cal = 1;
void setup() 
{
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int sval ;
  sval = digitalRead(sensor);
  double t = 0;
  int check = 0;
  if (sval == HIGH)
  { 
    while(1)
    {
      sval = digitalRead(sensor);
      if (sval == LOW)
        check = 1;
      if (sval == HIGH && check == 1)
        break;
      t = t+1;
    }
  }
  if(t>0)
  {
    //Serial.println(t);
    double k = 60000/t*cal;
    Serial.println(k); 
  } 
}

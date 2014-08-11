int A = 1;
int B = 1;

void setup ()
{
  Serial.begin(9600);
  
}

void loop ()
{
  A += 1;
  B += 1;
  Serial.println(A);
  Serial.println(B);
  delay(1000);
}

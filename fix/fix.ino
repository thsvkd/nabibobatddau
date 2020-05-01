int RXLED = 17;
void setup()
{
 pinMode(RXLED, OUTPUT);
 Serial.begin(9600);    
 Serial1.begin(9600);
}

void loop()
{
 digitalWrite(RXLED, LOW); //led_on
 TXLED0; //
}

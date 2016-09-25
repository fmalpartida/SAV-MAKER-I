
const int numPins = 25;

void setup()
{

 for ( int i = 0; i < numPins; i++ )
 {
    pinMode ( i, OUTPUT );
 }
 
}

void loop()
{
  static int pinOut = 0;
  
  for ( int i = 0; i < numPins; i++ )
  {
     digitalWrite ( i, pinOut );
  }
  pinOut ^= 1; // toggle the output for next round
  delay ( 1 );
}
  

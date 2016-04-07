/*
 * from Arduino -> OpenWrt
 * send string to MT7688
 * 
 * OpenWrt:
 * readStringFromArduino.py 
 * 
 */
 

void sendStringTo7688() {
  char sdata[64];
  Serial.print("Sending: ");
  sprintf(sdata,"hi MT7688-%i\n",random(1000));
  Serial.print(sdata);
  Serial1.write(sdata);
  delay(1000);

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(57600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sendStringTo7688();

}

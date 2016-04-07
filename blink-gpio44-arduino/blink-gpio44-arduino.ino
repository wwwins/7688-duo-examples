/*
 * 從 Arduino -> OpenWrt
 * 控制 7688 Duo 上 wifi led(GPIO44)
 * 
 * OpenWrt:
 * blink-gpio44-arduino.py
 * 
 */

void blinkWifiLED() {
  Serial.println("led on");
  Serial1.write("led on\n");
  delay(3000);
  Serial.println("led off");
  Serial1.write("led off\n");
  delay(3000);

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:

  blinkWifiLED();
}

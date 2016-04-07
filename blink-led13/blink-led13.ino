/*
 * 從 OpenWrt -> Arduino
 * 控制 LED13
 * 
 * OpenWrt:
 * blink-led13.py
 * 
 */
const int pin = 13;
int ledStatus = 0;

void led(boolean s) {
  if (s) {
    digitalWrite(pin, 1);
  }
  else {
    digitalWrite(pin, 0);
  }
}

void readStringFrom7688() {
  String rdata = "";
  if (Serial1.available() > 0) {
    rdata = Serial1.readStringUntil('\n');
  }
  if (rdata != "") {
    Serial.print("Received: ");
    Serial.println(rdata);
    if (rdata=="on") {
      Serial.println("led on");
      led(true);
    }
    else {
      Serial.println("led off");
      led(false);
    }

  }
  delay(100);

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(57600);

  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read data from MT7688
  // blink-led13.py
  readStringFrom7688();

}

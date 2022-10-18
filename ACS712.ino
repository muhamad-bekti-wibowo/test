/* --- www.nyebarilmu.com --- */
const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;
double averagenilaiarus = 00;

const int numReadings1 = 10;
int readings1[numReadings1];      // the readings from the analog input
int readIndex1 = 0;              // the index of the current reading
int total1 = 0;
double averagenilaiarus1 = 00;

const int pinADC = A0;
int sensitivitas = 185; //tegantung sensor arus yang digunakan, yang ini 5A
int nilaiadc = 00;
int teganganoffset = 2480; //nilai pembacaan offset saat tidak ada arus yang lewat
double tegangan = 00;
double nilaiarus = 00;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 1;

void setup() {
  Serial.begin(9600); //baud komunikasi serial monitor 9600bps

  delay(2000);
}

void loop() {
   currentMillis = millis();
   if (currentMillis - previousMillis >= interval)
   { previousMillis = currentMillis;
    nilaiadc = analogRead(pinADC);
    tegangan = (nilaiadc / 1023.0) * 5000;
    nilaiarus = ((tegangan - teganganoffset) / sensitivitas);
   nilaiarus = nilaiarus * 1000;
  if ( nilaiarus < 0 ) {
      nilaiarus = nilaiarus * -1;
    }
     // subtract the last reading:
    total = total - readings[readIndex];
    // read from the sensor:
    readings[readIndex] = nilaiarus;
    // add the reading to the total:
    total = total + readings[readIndex];
    // advance to the next position in the array:
    readIndex = readIndex + 1;

    // if we're at the end of the array...
    if (readIndex >= numReadings) {
      // ...wrap around to the beginning:
      readIndex = 0;

    }
    averagenilaiarus = total / numReadings; delay(1);
    }
    
  
  Serial.println(averagenilaiarus);
}

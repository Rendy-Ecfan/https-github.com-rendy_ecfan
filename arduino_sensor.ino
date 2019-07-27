#define trigPin 7 
#define echoPin 6
#define led 13
#define led2 10
#define led3 8
#define buzzer 3

int sound = 10;

void setup() {  //untuk menyeting
Serial.begin (9600); // Default Baudrate
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() { // Perogram akan menyalah terus hingga alat tercabut atau terhenti 
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance <= 15) { // Jika jarak kurang dari 15 cm maka led akan menyala
digitalWrite(led, HIGH); //jika jara kurang dari 15 cm maka lampu led hjau akan menyala
sound = 100; //jika jara kurang dari 15 cm maka suara yang di keuarkan akan lebih kecil sebesr 100
}
else {
digitalWrite(led,LOW);
}
if (distance <= 10) { // jika jarak kurang dari 10 cm maka led 2 akan menyala
digitalWrite(led2, HIGH); //jika jarak kurang dari 10 cm maka lampu led2 akan menyala berwarna kuning
sound = 200; //jika jara kurang dari 10 cm maka suara yang di keuarkan sebesr 200
}  
else { 
digitalWrite(led2, LOW);
}
if (distance < 5) { // Jika jarak kurang dari 5 cm maka led 3 akan menyala
digitalWrite(led3, HIGH); // jika jara kurang dari 5 cm maka lampu led3 otomatis akan menyala dengan mengeluarkan warna merah
sound = 300; //jika jara kurang dari 5 cm maka suara yang di keuarkan sebesr 300
}
else { 
digitalWrite(led3, LOW);
}
if (distance > 20 || distance <= 0){ // jika jaraka lebih dari 20 cm dan kurang dari 0 maka akan keluar jarak di luar jangkauan 
Serial.println("Jarak diluar jangkauan!");
sound = 400;
//noTone(buzzer);
}
else {
Serial.print(distance);
Serial.println(" cm");
tone(buzzer, sound);
}
delay(800); //delay kecepatan alat dalam membaca sensor
}

#include <SoftwareSerial.h>

// Pin configuration for HC-05
#define RX_PIN 10
#define TX_PIN 11

// Pin configuration for LED
#define LED_PIN 2
#define LED_PIN2 12
#define LED_PIN3 13

int inputPin = 4;    // signal receiver pin ECHO to D4
int outputPin = 5;   // signal transmitter pin TRIG to D5

int inputPin2 = 6;    // signal receiver pin ECHO to D6
int outputPin2 = 7;   // signal transmitter pin TRIG to D7

int inputPin3 = 8;    // signal receiver pin ECHO to D8
int outputPin3 = 9;   // signal transmitter pin TRIG to D9

int currentState = 0; // 0: Default

// Lists to store the buzzer tones and step numbers for game mode
int twinkle[] = {261, 261, 392, 392, 440, 440, 392};
int twinklel[] = {1, 1, 2, 2, 3, 3, 2};

int mary[] = {659, 587, 523, 587, 659, 659, 659, 587, 587, 587, 659, 659, 659};
int maryl[] = {1, 2, 3, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1};

int sheep[] = {523, 523, 392, 392, 440, 440, 440, 440, 392, 349, 349, 329, 329, 293, 293, 523};
int sheepl[] = {1, 1, 2, 2, 3, 3, 3, 3, 2, 1, 1, 2, 2, 3, 3, 2};

int johnny[] = {523, 523, 392, 392, 440, 440, 392, 349, 349, 329, 329, 293, 293, 523};
int johnnyl[] = {1, 1, 2, 2, 3, 3, 2, 1, 1, 2, 2, 3, 3, 2};

int london[] = {392, 440, 392, 349, 329, 349, 392, 293, 329, 349, 329, 349, 392};
int londonl[] = {1, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3};

int humpty[] = {523, 523, 659, 659, 587, 659, 587, 523, 659, 659, 784, 784, 698, 784, 698, 659};
int humptyl[] = {1, 1, 2, 2, 1, 2, 1, 2, 3, 3, 2, 2, 1, 2, 1, 2};

int i = 0;
// Create a software serial object for the HC-05 Bluetooth module
SoftwareSerial hc05(RX_PIN, TX_PIN);

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  hc05.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin2, INPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(inputPin3, INPUT);
  pinMode(outputPin3, OUTPUT);
}

void loop() {
  // Check the distances from the Ultrasonic sensors
  int dis1 = checkUltrasonic(inputPin, outputPin);
  delay(10);
  int dis2 = checkUltrasonic(inputPin2, outputPin2);
  delay(10);
  int dis3 = checkUltrasonic(inputPin3, outputPin3);
  
  // Check if there is any data available from the HC-05 module
  if (hc05.available()) {
    // Read the next character from the HC-05 module
    char data = hc05.read();
    Serial.println(data);

    if (data == '1') {
      currentState = 1; // Switch to Ultrasonic Loop state 1
    }
    else if (data == '2') {
      currentState = 2; // Switch to Ultrasonic Loop state 2
    }
    else if (data == '3') {
      currentState = 3; // Switch to Ultrasonic Loop state 3
    }
    else if (data == '4') {
      currentState = 4; // Switch to Ultrasonic Loop state 4
    }
    else if (data == '5') {
      currentState = 5; // Switch to Ultrasonic Loop state 5
    }
    else if (data == '6') {
      currentState = 6; // Switch to Ultrasonic Loop state 6
    }
    else if (data == 'a') {
      currentState = 7; // Switch to Ultrasonic Loop state 7
    }
    else if (data == 'b') {
      currentState = 8; // Switch to Ultrasonic Loop state 8
    }
    else if (data == 'c') {
      currentState = 9; // Switch to Ultrasonic Loop state 9
    }
    else if (data == 'd') {
      currentState = 10; // Switch to Ultrasonic Loop state 10
    }
    else if (data == 'e') {
      currentState = 11; // Switch to Ultrasonic Loop state 11
    }
    else if (data == 'f') {
      currentState = 12; // Switch to Ultrasonic Loop state 12
    }
  }

  // Implement state-based logic
  switch (currentState) {
  case 0: 
    if (hc05.available()) {
      // Read the next character from the HC-05 module
      char data = hc05.read();
      Serial.println(data);
  
      if (data == '1') {
        currentState = 1; // Switch to Ultrasonic Loop state 1
      }
      else if (data == '2') {
        currentState = 2; // Switch to Ultrasonic Loop state 2
      }
      else if (data == '3') {
        currentState = 3; // Switch to Ultrasonic Loop state 3
      }
      else if (data == '4') {
        currentState = 4; // Switch to Ultrasonic Loop state 4
      }
      else if (data == '5') {
        currentState = 5; // Switch to Ultrasonic Loop state 5
      }
      else if (data == '6') {
        currentState = 6; // Switch to Ultrasonic Loop state 6
      }
      else if (data == 'a') {
        currentState = 7; // Switch to Ultrasonic Loop state 7
      }
      else if (data == 'b') {
        currentState = 8; // Switch to Ultrasonic Loop state 8
      }
      else if (data == 'c') {
        currentState = 9; // Switch to Ultrasonic Loop state 9
      }
      else if (data == 'd') {
        currentState = 10; // Switch to Ultrasonic Loop state 10
      }
      else if (data == 'e') {
        currentState = 11; // Switch to Ultrasonic Loop state 11
      }
      else if (data == 'f') {
        currentState = 12; // Switch to Ultrasonic Loop state 12
      }
      else {
        Serial.println("Cant exit");
      }
    }
    
    break;

  case 1: // Play Guitar notes
    Serial.println(dis2);
    if (dis1 > 30 && dis1 <= 50) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 440);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("1a1");
      delay(500);
    } else if (dis1 <= 30 && dis1 > 0) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 200);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("1a2");
      delay(500);
    } else if (dis2 > 30 && dis2 <= 50) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 466.16);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("1a3");
      Serial.println(dis2);
      delay(500);
    } else if (dis2 <= 30 && dis2 > 0) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 554.37);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("1a4");
      delay(500);
    } else if (dis3 > 30 && dis3 <= 50) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 523.25);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("1a5");
      delay(500);
    } else if (dis3 <= 30 && dis3 > 0) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 587.33);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("1a6");
      delay(500);
    }
    
    break;

  case 2: // Play Drum notes
    if (dis1 > 30 && dis1 <= 50) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 80);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("2a1");
      delay(500);
    } else if (dis1 <= 30 && dis1 > 0) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 200);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("2a2");
      delay(500);
    } else if (dis2 > 30 && dis2 <= 50) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 100);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("2a3");
      delay(500);
    } else if (dis2 <= 30 && dis2 > 0) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 50);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("2a4");
      delay(500);
    } else if (dis3 > 30 && dis3 <= 50) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 150);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("2a5");
      delay(500);
    } else if (dis3 <= 30 && dis3 > 0) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 180);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("2a6");
      delay(500);
    }
    
    break;
       
  case 3: // Play Piano notes
    if (dis1 > 30 && dis1 <= 50) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 370);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("3a1");
      delay(500);
    } else if (dis1 <= 30 && dis1 > 0) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 415);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("3a2");
      delay(500);
    } else if (dis2 > 30 && dis2 <= 50) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 466);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("3a3");
      delay(500);
    } else if (dis2 <= 30 && dis2 > 0) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 554);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("3a4");
      delay(500);
    } else if (dis3 > 30 && dis3 <= 50) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 622);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("3a5");
      delay(500);
    } else if (dis3 <= 30 && dis3 > 0) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 740);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("3a6");
      delay(500);
    }
    
    break;

  case 4: // Play Flute notes
    if (dis1 > 30 && dis1 <= 50) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 261);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("4a1");
      delay(500);
    } else if (dis1 <= 30 && dis1 > 0) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 311);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("4a2");
      delay(500);
    } else if (dis2 > 30 && dis2 <= 50) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 277);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("4a3");
      delay(500);
    } else if (dis2 <= 30 && dis2 > 0) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 466);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("4a4");
      delay(500);
    } else if (dis3 > 30 && dis3 <= 50) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 293);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("4a5");
      delay(500);
    } else if (dis3 <= 30 && dis3 > 0) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 493);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("4a6");
      delay(500);
    }
    
    break;

  case 5: // Play Violin notes
    if (dis1 > 30 && dis1 <= 50) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 311);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("5a1");
      delay(500);
    } else if (dis1 <= 30 && dis1 > 0) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 370);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("5a2");
      delay(500);
    } else if (dis2 > 30 && dis2 <= 50) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 330);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("5a3");
      delay(500);
    } else if (dis2 <= 30 && dis2 > 0) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 392);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("5a4");
      delay(500);
    } else if (dis3 > 30 && dis3 <= 50) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 349);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("5a5");
      delay(500);
    } else if (dis3 <= 30 && dis3 > 0) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 415);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("5a6");
      delay(500);
    }
    
    break;
    
  case 6: // Play Organ notes
    if (dis1 > 30 && dis1 <= 50) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 261);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("6a1");
      delay(500);
    } else if (dis1 <= 30 && dis1 > 0) {
      digitalWrite(LED_PIN, HIGH);
      tone(15, 349);
      delay(1500);
      digitalWrite(LED_PIN, LOW);
      noTone(15);
      Serial.println("6a2");
      delay(500);
    } else if (dis2 > 30 && dis2 <= 50) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 294);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("6a3");
      delay(500);
    } else if (dis2 <= 30 && dis2 > 0) {
      digitalWrite(LED_PIN2, HIGH);
      tone(15, 329);
      delay(1500);
      digitalWrite(LED_PIN2, LOW);
      noTone(15);
      Serial.println("6a4");
      delay(500);
    } else if (dis3 > 30 && dis3 <= 50) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 523);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("6a5");
      delay(500);
    } else if (dis3 <= 30 && dis3 > 0) {
      digitalWrite(LED_PIN3, HIGH);
      tone(15, 392);
      delay(1500);
      digitalWrite(LED_PIN3, LOW);
      noTone(15);
      Serial.println("6a6");
      delay(500);
    }
    
    break;

  case 7: // Twinkle Twinkle memory game
    digitalWrite(LED_PIN, HIGH);
    tone(15, twinkle[0]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, twinkle[1]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, twinkle[2]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, twinkle[3]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, twinkle[4]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, twinkle[5]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, twinkle[6]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    //Start sound
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(500);
    
    i = 0;

    while (i < 7) { //Check Steps
      bool j = true;
      while (j) {
        int dist1 = checkUltrasonic(inputPin, outputPin);
        delay(10);
        int dist2 = checkUltrasonic(inputPin2, outputPin2);
        delay(10);
        int dist3 = checkUltrasonic(inputPin3, outputPin3);
        if (dist1 <= 50 && twinklel[i] == 1) {
          digitalWrite(LED_PIN, HIGH);
          tone(15, twinkle[i]);
          delay(500);
          digitalWrite(LED_PIN, LOW);
          noTone(15);
          j = false;
        } else if (dist2 <= 50 && twinklel[i] == 2) {
          digitalWrite(LED_PIN2, HIGH);
          tone(15, twinkle[i]);
          delay(500);
          digitalWrite(LED_PIN2, LOW);
          noTone(15);
          j = false;
        } else if (dist3 <= 50 && twinklel[i] == 3) {
          digitalWrite(LED_PIN3, HIGH);
          tone(15, twinkle[i]);
          delay(500);
          digitalWrite(LED_PIN3, LOW);
          noTone(15);
          j = false;
        } else if ((dist1 <= 50 && twinklel[i] != 1) || (dist2 <= 50 && twinklel[i] != 2) || (dist3 <= 50 && twinklel[i] != 3)) { //Wrong Step
          delay(500);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          delay(100);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          i = -1; //Start all over again
          j = false;
        }
      }
      Serial.println("Exited");
      i = i + 1; //Check next step
    }

    delay(500);
    hc05.write('1');
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    currentState = 0; // Switch back to Default state

    break;
    
  case 8: // Mary Had A Little Lamb memory game
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[0]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, mary[1]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, mary[2]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, mary[3]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[4]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[5]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[6]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, mary[7]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, mary[8]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, mary[9]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[10]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[11]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, mary[12]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    //Start sound
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(500);
    
    i = 0;

    while (i < 13) { //Check Steps
      bool j = true;
      while (j) {
        int dism1 = checkUltrasonic(inputPin, outputPin);
        delay(10);
        int dism2 = checkUltrasonic(inputPin2, outputPin2);
        delay(10);
        int dism3 = checkUltrasonic(inputPin3, outputPin3);
        if (dism1 <= 50 && maryl[i] == 1) {
          digitalWrite(LED_PIN, HIGH);
          tone(15, mary[i]);
          delay(500);
          digitalWrite(LED_PIN, LOW);
          noTone(15);
          j = false;
        } else if (dism2 <= 50 && maryl[i] == 2) {
          digitalWrite(LED_PIN2, HIGH);
          tone(15, mary[i]);
          delay(500);
          digitalWrite(LED_PIN2, LOW);
          noTone(15);
          j = false;
        } else if (dism3 <= 50 && maryl[i] == 3) {
          digitalWrite(LED_PIN3, HIGH);
          tone(15, mary[i]);
          delay(500);
          digitalWrite(LED_PIN3, LOW);
          noTone(15);
          j = false;
        } else if ((dism1 <= 50 && maryl[i] != 1) || (dism2 <= 50 && maryl[i] != 2) || (dism3 <= 50 && maryl[i] != 3)) { //Wrong Step
          delay(500);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          delay(100);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          i = -1; //Start all over again
          j = false;
        }
      }
      Serial.println("Exited");
      i = i + 1; //Check next step
    }

    delay(500);
    hc05.write('1');
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    currentState = 0; // Switch back to Default state

    break;

  case 9: // Ba Ba Black Sheep memory game
    digitalWrite(LED_PIN, HIGH);
    tone(15, sheep[0]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, sheep[1]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, sheep[2]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, sheep[3]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, sheep[4]);
    delay(200);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, sheep[5]);
    delay(200);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, sheep[6]);
    delay(200);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, sheep[7]);
    delay(200);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, sheep[8]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, sheep[9]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, sheep[10]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, sheep[11]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, sheep[12]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, sheep[13]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, sheep[14]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, sheep[15]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    //Start sound
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(500);
    
    i = 0;

    while (i < 16) { //Check Steps
      bool j = true;
      while (j) {
        int diss1 = checkUltrasonic(inputPin, outputPin);
        delay(10);
        int diss2 = checkUltrasonic(inputPin2, outputPin2);
        delay(10);
        int diss3 = checkUltrasonic(inputPin3, outputPin3);
        if (diss1 <= 50 && sheepl[i] == 1) {
          digitalWrite(LED_PIN, HIGH);
          tone(15, sheep[i]);
          delay(500);
          digitalWrite(LED_PIN, LOW);
          noTone(15);
          j = false;
        } else if (diss2 <= 50 && sheepl[i] == 2) {
          digitalWrite(LED_PIN2, HIGH);
          tone(15, sheep[i]);
          delay(500);
          digitalWrite(LED_PIN2, LOW);
          noTone(15);
          j = false;
        } else if (diss3 <= 50 && sheepl[i] == 3) {
          digitalWrite(LED_PIN3, HIGH);
          tone(15, sheep[i]);
          delay(500);
          digitalWrite(LED_PIN3, LOW);
          noTone(15);
          j = false;
        } else if ((diss1 <= 50 && sheepl[i] != 1) || (diss2 <= 50 && sheepl[i] != 2) || (diss3 <= 50 && sheepl[i] != 3)) { //Wrong Step
          delay(500);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          delay(100);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          i = -1; //Start all over again
          j = false;
        }
      }
      Serial.println("Exited");
      i = i + 1; //Check next step
    }

    delay(500);
    hc05.write('1');
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    currentState = 0; // Switch back to Default state

    break;

  case 10: // Johnny Johnny memory game
    digitalWrite(LED_PIN, HIGH);
    tone(15, johnny[0]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, johnny[1]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, johnny[2]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, johnny[3]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, johnny[4]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, johnny[5]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, johnny[6]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, johnny[7]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, johnny[8]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, johnny[9]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, johnny[10]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, johnny[11]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, johnny[12]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, johnny[13]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    //Start sound
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(500);
    
    i = 0;

    while (i < 14) { //Check Steps
      bool j = true;
      while (j) {
        int disj1 = checkUltrasonic(inputPin, outputPin);
        delay(10);
        int disj2 = checkUltrasonic(inputPin2, outputPin2);
        delay(10);
        int disj3 = checkUltrasonic(inputPin3, outputPin3);
        if (disj1 <= 50 && johnnyl[i] == 1) {
          digitalWrite(LED_PIN, HIGH);
          tone(15, johnny[i]);
          delay(500);
          digitalWrite(LED_PIN, LOW);
          noTone(15);
          j = false;
        } else if (disj2 <= 50 && johnnyl[i] == 2) {
          digitalWrite(LED_PIN2, HIGH);
          tone(15, johnny[i]);
          delay(500);
          digitalWrite(LED_PIN2, LOW);
          noTone(15);
          j = false;
        } else if (disj3 <= 50 && johnnyl[i] == 3) {
          digitalWrite(LED_PIN3, HIGH);
          tone(15, johnny[i]);
          delay(500);
          digitalWrite(LED_PIN3, LOW);
          noTone(15);
          j = false;
        } else if ((disj1 <= 50 && johnnyl[i] != 1) || (disj2 <= 50 && johnnyl[i] != 2) || (disj3 <= 50 && johnnyl[i] != 3)) { //Wrong Step
          delay(500);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          delay(100);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          i = -1; //Start all over again
          j = false;
        }
      }
      Serial.println("Exited");
      i = i + 1; //Check next step
    }

    delay(500);
    hc05.write('1');
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    currentState = 0; // Switch back to Default state

    break;

  case 11: // London Bridge memory game
    digitalWrite(LED_PIN, HIGH);
    tone(15, london[0]);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, london[1]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, london[2]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, london[3]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, london[4]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, london[5]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, london[6]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, london[7]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, london[8]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, london[9]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, london[10]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, london[11]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, london[12]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    //Start sound
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(500);
    
    i = 0;

    while (i < 13) { //Check Steps
      bool j = true;
      while (j) {
        int disl1 = checkUltrasonic(inputPin, outputPin);
        delay(10);
        int disl2 = checkUltrasonic(inputPin2, outputPin2);
        delay(10);
        int disl3 = checkUltrasonic(inputPin3, outputPin3);
        if (disl1 <= 50 && londonl[i] == 1) {
          digitalWrite(LED_PIN, HIGH);
          tone(15, london[i]);
          delay(500);
          digitalWrite(LED_PIN, LOW);
          noTone(15);
          j = false;
        } else if (disl2 <= 50 && londonl[i] == 2) {
          digitalWrite(LED_PIN2, HIGH);
          tone(15, london[i]);
          delay(500);
          digitalWrite(LED_PIN2, LOW);
          noTone(15);
          j = false;
        } else if (disl3 <= 50 && londonl[i] == 3) {
          digitalWrite(LED_PIN3, HIGH);
          tone(15, london[i]);
          delay(500);
          digitalWrite(LED_PIN3, LOW);
          noTone(15);
          j = false;
        } else if ((disl1 <= 50 && londonl[i] != 1) || (disl2 <= 50 && londonl[i] != 2) || (disl3 <= 50 && londonl[i] != 3)) { //Wrong Step
          delay(500);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          delay(100);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          i = -1; //Start all over again
          j = false;
        }
      }
      Serial.println("Exited");
      i = i + 1; //Check next step
    }

    delay(500);
    hc05.write('1');
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    currentState = 0; // Switch back to Default state

    break;

  case 12: // Humpty Dumpty memory game
    digitalWrite(LED_PIN, HIGH);
    tone(15, humpty[0]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, humpty[1]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[2]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[3]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, humpty[4]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[5]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, humpty[6]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[7]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, humpty[8]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, humpty[9]);
    delay(500);
    digitalWrite(LED_PIN3, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[10]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[11]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, humpty[12]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[13]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    digitalWrite(LED_PIN, HIGH);
    tone(15, humpty[14]);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    noTone(15);
    digitalWrite(LED_PIN2, HIGH);
    tone(15, humpty[15]);
    delay(500);
    digitalWrite(LED_PIN2, LOW);
    noTone(15);
    //Start sound
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    delay(500);
    
    i = 0;

    while (i < 16) { //Check Steps
      bool j = true;
      while (j) {
        int dish1 = checkUltrasonic(inputPin, outputPin);
        delay(10);
        int dish2 = checkUltrasonic(inputPin2, outputPin2);
        delay(10);
        int dish3 = checkUltrasonic(inputPin3, outputPin3);
        if (dish1 <= 50 && humptyl[i] == 1) {
          digitalWrite(LED_PIN, HIGH);
          tone(15, humpty[i]);
          delay(500);
          digitalWrite(LED_PIN, LOW);
          noTone(15);
          j = false;
        } else if (dish2 <= 50 && humptyl[i] == 2) {
          digitalWrite(LED_PIN2, HIGH);
          tone(15, humpty[i]);
          delay(500);
          digitalWrite(LED_PIN2, LOW);
          noTone(15);
          j = false;
        } else if (dish3 <= 50 && humptyl[i] == 3) {
          digitalWrite(LED_PIN3, HIGH);
          tone(15, humpty[i]);
          delay(500);
          digitalWrite(LED_PIN3, LOW);
          noTone(15);
          j = false;
        } else if ((dish1 <= 50 && humptyl[i] != 1) || (dish2 <= 50 && humptyl[i] != 2) || (dish3 <= 50 && humptyl[i] != 3)) { //Wrong Step
          delay(500);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          delay(100);
          digitalWrite(LED_PIN, HIGH);
          digitalWrite(LED_PIN2, HIGH);
          digitalWrite(LED_PIN3, HIGH);
          tone(15, 150);
          delay(1000);
          noTone(15);
          digitalWrite(LED_PIN, LOW);
          digitalWrite(LED_PIN2, LOW);
          digitalWrite(LED_PIN3, LOW);
          i = -1; //Start all over again
          j = false;
        }
      }
      Serial.println("Exited");
      i = i + 1; //Check next step
    }

    delay(500);
    hc05.write('1');
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    tone(15, 1000);
    delay(1000);
    noTone(15);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    currentState = 0; // Switch back to Default state

    break;
    
  }
}

// Function to check distance from the ultrasonic sensors
int checkUltrasonic(int inputPin, int outputPin) {
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); // Pulse for 10μs to trigger ultrasonic detection
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH); // Read receiver pulse time
  distance = distance / 58;               // Transform pulse time to distance
  return distance;
  delay(50);
}

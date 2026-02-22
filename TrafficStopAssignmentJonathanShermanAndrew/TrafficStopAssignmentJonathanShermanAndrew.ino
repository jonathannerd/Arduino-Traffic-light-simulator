///////////////////////////////////////
// Jonathan Sherman
// Andrew Halpern
//////////////////////////////////////

//This Arduino program controls traffic lights and pedestrian crossing signals using LEDs and buttons.
//It defines arrays for different colored LEDs and sets pins for four buttons.
//In the setup() function, it initializes LED pins as outputs and the button pins as inputs with pull-up resistors.
//The loop() function runs continuously to control the traffic light patterns and checks for button presses.
//If a button is pressed, it triggers pedestrian crossing functions that flash blue LEDs and then turn on red LEDs to simulate a real-world traffic light system with pedestrian signals.


// 4 buttons
// 4 blue leds
// cardboard box
// 4 pcb boards
// 12 red, green and yellow leds
// duct tape
// A lot of wires
// Aurduino Mega

int redLEDs[] = { 4, 47 };
int redLEDs1[] = { 52, 46 };
int yellowLEDs[] = { 3, 45 };
int yellowLEDs1[] = { 50, 44 };
int greenLEDs[] = { 2, 43 };
int greenLEDs1[] = { 48, 42 };
int blueLEDs1[] = { 35, 39 };
int blueLEDs[] = { 37, 41 };
int button1 = 24;
int button2 = 26;
int button3 = 28;
int button4 = 30;


void setup() {
  Serial.begin(9600);
  //pinMode for all leds and buttons
  for (int i = 0; i < 2; i++) {
    pinMode(redLEDs[i], OUTPUT);
    pinMode(redLEDs1[i], OUTPUT);
    pinMode(yellowLEDs1[i], OUTPUT);
    pinMode(greenLEDs1[i], OUTPUT);
    pinMode(blueLEDs1[i], OUTPUT);
    pinMode(yellowLEDs[i], OUTPUT);
    pinMode(greenLEDs[i], OUTPUT);
    pinMode(blueLEDs[i], OUTPUT);
  }
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}

void loop() {
  //Detects if button is on or off
  Serial.println(digitalRead(button1));
  Serial.println(digitalRead(button2));
  Serial.println(digitalRead(button3));
  Serial.println(digitalRead(button4));

  //Traffic lights pattern
  traficLight(yellowLEDs1, LOW);
  traficLight(greenLEDs1, LOW);
  traficLight(redLEDs1, HIGH);
  traficLight(redLEDs, LOW);
  traficLight(yellowLEDs, LOW);
  traficLight(greenLEDs, HIGH);
  //if the button is pressed initiate crossing
  if (digitalRead(button1) == 0 || digitalRead(button2) == 0) {
    crossing();
  } else if (digitalRead(button3) == 0 || digitalRead(button4) == 0) {
    crossingTwo();
  }
  delay(5000);
  //Traffic lights pattern
  traficLight(greenLEDs, LOW);
  traficLight(redLEDs, LOW);
  traficLight(yellowLEDs, HIGH);
  traficLight(yellowLEDs1, LOW);
  traficLight(greenLEDs1, LOW);
  traficLight(redLEDs1, HIGH);
  //if the button is pressed initiate crossing
  if (digitalRead(button1) == 0 || digitalRead(button2) == 0) {
    crossing();
  } else if (digitalRead(button3) == 0 || digitalRead(button4) == 0) {
    crossingTwo();
  }
  delay(2500);
  //Traffic lights pattern
  traficLight(redLEDs1, LOW);
  traficLight(yellowLEDs1, LOW);
  traficLight(yellowLEDs, LOW);
  traficLight(greenLEDs, LOW);
  traficLight(redLEDs, HIGH);
  traficLight(greenLEDs1, HIGH);
  //if the button is pressed initiate crossing
  if (digitalRead(button1) == 0 || digitalRead(button2) == 0) {
    crossing();
  } else if (digitalRead(button3) == 0 || digitalRead(button4) == 0) {
    crossingTwo();
  }
  delay(5000);
  //Traffic lights pattern
  traficLight(greenLEDs1, LOW);
  traficLight(redLEDs1, LOW);
  traficLight(yellowLEDs1, HIGH);
  traficLight(yellowLEDs, LOW);
  traficLight(greenLEDs, LOW);
  traficLight(redLEDs, HIGH);
  //if the button is pressed initiate crossing
  if (digitalRead(button1) == 0 || digitalRead(button2) == 0) {
    crossing();
  } else if (digitalRead(button3) == 0 || digitalRead(button4) == 0) {
    crossingTwo();
  }
  delay(2500);
}


void traficLight(int ledArray[], int state) {
  //this is to run the lights
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledArray[i], state);
  }
}

void crossing() {
  //flashes the blue leds1 and turns leds1 to red
  traficLight(redLEDs1, LOW);
  traficLight(yellowLEDs1, HIGH);
  traficLight(greenLEDs1, LOW);
  traficLight(redLEDs, LOW);
  traficLight(yellowLEDs, LOW);
  traficLight(greenLEDs, HIGH);
  delay(1500);
  traficLight(redLEDs1, HIGH);
  traficLight(yellowLEDs1, LOW);
  traficLight(greenLEDs1, LOW);

  for (int i = 0; i < 10; i++) {
    traficLight(blueLEDs1, HIGH);
    delay(500);
    traficLight(blueLEDs1, LOW);
    delay(500);
  }
}
void crossingTwo() {
  //flashes the blue leds and turns leds to red
  traficLight(redLEDs, LOW);
  traficLight(yellowLEDs, HIGH);
  traficLight(greenLEDs, LOW);
  traficLight(redLEDs1, LOW);
  traficLight(yellowLEDs1, LOW);
  traficLight(greenLEDs1, HIGH);
  delay(1500);
  traficLight(redLEDs, HIGH);
  traficLight(yellowLEDs, LOW);
  traficLight(greenLEDs, LOW);

  for (int i = 0; i < 10; i++) {
    traficLight(blueLEDs, HIGH);
    delay(500);
    traficLight(blueLEDs, LOW);
    delay(500);
  }
}

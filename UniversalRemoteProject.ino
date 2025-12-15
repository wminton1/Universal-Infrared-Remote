#include <IRremote.h>

// Define GPIO pins for each button
#define PIN_POWER 5
#define PIN_UP 6
#define PIN_DOWN 7
#define PIN_LEFT 8
#define PIN_RIGHT 9
#define PIN_SELECT 10
#define PIN_BACK 11
#define PIN_HOME 12
#define PIN_PLAY_PAUSE 13
#define PIN_VOL_PLUS 14
#define PIN_VOL_MINUS 15
#define PIN_MUTE 16
#define PIN_OPTIONS 17

// Transmission codes for each button
const uint32_t CODE_POWER = 0x20DF10EF;
const uint32_t CODE_UP = 0x20DF40BF;
const uint32_t CODE_DOWN = 0x20DFC03F;
const uint32_t CODE_LEFT = 0x20DFE01F;
const uint32_t CODE_RIGHT = 0x20DF609F;
const uint32_t CODE_SELECT = 0x20DF22DD;
const uint32_t CODE_BACK = 0x20DF12ED;
const uint32_t CODE_HOME = 0x20DF708F;
const uint32_t CODE_PLAY_PAUSE = 0x20DF807F;
const uint32_t CODE_VOL_PLUS = 0x20DF00FF;
const uint32_t CODE_VOL_MINUS = 0x20DF807F;
const uint32_t CODE_MUTE = 0x20DF906F;
const uint32_t CODE_OPTIONS = 0x20DFB04F;

// IR transmitter pin
#define IR_SEND_PIN 4
IRsend irsend(IR_SEND_PIN);

void setup() {
  Serial.begin(115200);
  
  // Initialize the IR sender
  irsend.begin(IR_SEND_PIN);

  // Configure all button pins as inputs
  pinMode(PIN_POWER, INPUT_PULLUP);
  pinMode(PIN_UP, INPUT_PULLUP);
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);
  pinMode(PIN_SELECT, INPUT_PULLUP);
  pinMode(PIN_BACK, INPUT_PULLUP);
  pinMode(PIN_HOME, INPUT_PULLUP);
  pinMode(PIN_PLAY_PAUSE, INPUT_PULLUP);
  pinMode(PIN_VOL_PLUS, INPUT_PULLUP);
  pinMode(PIN_VOL_MINUS, INPUT_PULLUP);
  pinMode(PIN_MUTE, INPUT_PULLUP);
  pinMode(PIN_OPTIONS, INPUT_PULLUP);

  Serial.println("IR Remote Ready!"); // this to monitors and ensure its working right in the serial monitor
}

void loop() {
  // Check each button and send the corresponding IR code if pressed
  if (digitalRead(PIN_POWER) == LOW) sendIR(CODE_POWER, "Power");
  if (digitalRead(PIN_UP) == LOW) sendIR(CODE_UP, "Up");
  if (digitalRead(PIN_DOWN) == LOW) sendIR(CODE_DOWN, "Down");
  if (digitalRead(PIN_LEFT) == LOW) sendIR(CODE_LEFT, "Left");
  if (digitalRead(PIN_RIGHT) == LOW) sendIR(CODE_RIGHT, "Right");
  if (digitalRead(PIN_SELECT) == LOW) sendIR(CODE_SELECT, "Select");
  if (digitalRead(PIN_BACK) == LOW) sendIR(CODE_BACK, "Back");
  if (digitalRead(PIN_HOME) == LOW) sendIR(CODE_HOME, "Home");
  if (digitalRead(PIN_PLAY_PAUSE) == LOW) sendIR(CODE_PLAY_PAUSE, "Play/Pause");
  if (digitalRead(PIN_VOL_PLUS) == LOW) sendIR(CODE_VOL_PLUS, "Volume +");
  if (digitalRead(PIN_VOL_MINUS) == LOW) sendIR(CODE_VOL_MINUS, "Volume -");
  if (digitalRead(PIN_MUTE) == LOW) sendIR(CODE_MUTE, "Mute");
  if (digitalRead(PIN_OPTIONS) == LOW) sendIR(CODE_OPTIONS, "Options");

  delay(100); // Debounce delay
}

void sendIR(uint32_t code, const char *buttonName) {
  Serial.print("Sending IR code for ");
  Serial.println(buttonName);
  irsend.sendNEC(code, 32); // Send the code with a 32-bit length
}

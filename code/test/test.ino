
/* AVRxxDD14 (AVR64DD14 AVR32DD14 AVR16DD14) example for Arduino
 * Simple test file based on what is found in
 * /Users/xxxx/Library/Arduino15/packages/DxCore/hardware/megaavr/1.6.2/variants/14pin-ddseries/pins_arduino.h
 */

// Ports to Arduino Pinout 
#define PA0  0 // TX
#define PA1  1 // RX
#define PC1  9 // A29/LED
#define PC2 10 // SDA/A30      (PIN_WIRE_SDA_PINSWAP_2)
#define PC3 11 // SCL/A31      (PIN_WIRE_SCL_PINSWAP_2)
#define PD4 16 // MOSI/A4      (SPI_MUX_PINSWAP_4)
#define PD5 17 // MISO/A5      (SPI_MUX_PINSWAP_4)
#define PD6 18 // SCK/A6/DAC   (SPI_MUX_PINSWAP_4)
#define PD7 19 // SS/A7/BUTTON (SPI_MUX_PINSWAP_4)
#define PF6 20 // RESET
#define PF7 21 // UPDI

#define LED_BUILTIN PIN_PC1
#define BUTTON_PIN  PIN_PD7

int count = 0;
bool wasButtonPressed = false;

void setup() {
  Serial.begin(9600);
  delay(4000);
  Serial.println("test");
  pinMode(LED_BUILTIN, OUTPUT);       // LED
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Button
}

void loop() {
  // If button is pressed, keep LED turned on
  bool isButtonPressed = !digitalRead(BUTTON_PIN);
  if( isButtonPressed != wasButtonPressed ){
    Serial.println( isButtonPressed );
    digitalWrite( LED_BUILTIN, isButtonPressed );
    delay(100);// simple debounce
  }
  wasButtonPressed = isButtonPressed;

  // Toggle LED every 10000 loops
  if( !isButtonPressed && count % 10000 == 0 ){
    digitalWrite( LED_BUILTIN, !digitalRead(LED_BUILTIN) );
  } else if( isButtonPressed ){
    analogWrite( LED_BUILTIN, (count % LED_BUILTIN) );
    delay(3);
  }
  count++;
}

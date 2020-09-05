#include <FancyButton.h>
#define BUTTON 14

FancyButton button(BUTTON);
    
void setup() {
    Serial.begin(9600);
    while (!Serial);
}

void loop() {
    button.check();
    if (button.press()){
      Serial.print("Button pressed ... ");
    }
    if (button.short_press()){
      Serial.print("short press.\n");
    }
    if (button.long_press()){
      Serial.print("long press ... ");
    }
    if (button.long_released()){
      Serial.print("released.\n");
    }
}

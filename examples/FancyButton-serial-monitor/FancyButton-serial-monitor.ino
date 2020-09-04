#include <FancyButton.h>
#define BUTTON 14

FancyButton button(BUTTON);
    
void setup() {
    Serial.begin(9600);
    while (!Serial);
}

void loop() {
    button.check();
    if (button.press_flag){
      Serial.print("Button pressed ... ");
      button.press_flag = false;
    }
    if (button.short_press_flag){
      Serial.print("short press.\n");
      button.short_press_flag = false;
    }
    if (button.long_press_flag){
      Serial.print("long press ... ");
      button.long_press_flag = false;
    }
    if (button.release_long_flag){
      Serial.print("released.\n");
      button.release_long_flag = false;
    }
}

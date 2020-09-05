# FancyButton
An Arduino library for debouncing and generating long press events

## Installing
Simply copy the files to your local Arduino folder, as explained [here](https://www.arduino.cc/en/guide/libraries)

## Usage
The library provides a FancyButton class that handles the GPIO and sets event flags.

To use it in your code, import the library and declare a FancyButton instance in global scope (outside the loop and setup functions), initializing it with the pin to which the button is connected.
```cpp
import <FancyButton.h>
FancyButton button(10);
```
You must then invoke the ```check ``` method regularly, for example at the start of the main loop:
```cpp
void loop() {
  button.check()
  
  // you code goes here

}
```

To check for events, simply call one of the event methods, like this:
```cpp
if (button.press()){

  // event handling code goes here

}

```

If an event is was detected, the methods clear the internal flag upon calling.

See the provided example.

For each pin you want to debounce, create a new FancyButton instance.

The event methods are: 
| method | returns true if |
| :---:  |  :--- |
| ```FancyButton::press```           | any button press is detected |
| ```FancyButton::short_press()```   | short press (default: <2s) is released |
| ```FancyButton::long_press()```    | long press is detected |
| ```FancyButton::long_released()``` | long press is released |

## Implementation notes
The main component of the class is a finite-state machine. The flags are set just before the state transitions.

## Future work / missing feature list
- Double click events
- Not needing one instance for every pin (having a single instance for all buttons)
- Porting to a FreeRTOS task

Help is welcome. Feel free to fork the project if you want to implement these or any other features.

##

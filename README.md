# FancyButton
An Arduino library for debouncing and generating long press events
## Usage
For each pin you want to debounce, create a new FancyButton instance. See provided example.
Several event flags are implemented. They must be manually unset in your code. They are: 
| Flag | meaning |
| :--- |  ---:   |
| press_flag | set at the moment any button press is detected |
| short_press_flag | set when a short press (default: <2s) is released |
| long_press_flag | set when a long press is detected |
| release_long_flag | set when a long press is released |

## Installing
Simply copy the files to your local Arduino folder, as explained [here](https://www.arduino.cc/en/guide/libraries)

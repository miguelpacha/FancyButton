/*
 * FancyButton.cpp - Library for debouncing and generating long press events
 * Created by Miguel Pachá, Sep 4, 2020.
 * 
 * License: LGPL
 */

#include "Arduino.h"
#include "FancyButton.h"

FancyButton::FancyButton(int pin){
    pinMode(pin, INPUT_PULLUP);
    _pin = pin;
}

void FancyButton::check(){
  _reading = digitalRead(_pin);
  switch(_state){
    case standby:
      if (_reading==LOW) {
        if (_reading==_last_reading) {
          if (!_counting) {
            _counting = true;
            _last_event = millis();
          } else {
            if ((millis()-_last_event)>debounceDelay){
              press_flag = true;
              _state = pressed;
            }
          }
        }
      } else {
        _counting = false;
      }
    break;
    case pressed:
      if (_reading==LOW){
        if ((millis()-_last_event)>LONG_PRESS_TIME){
          long_press_flag = true;
          _state = long_pressed;
        }
      } else {
        short_press_flag = true;
        _state = standby; 
      }
    break;
    case long_pressed:
      if (_reading==HIGH) {
        release_long_flag = true;
        _state = standby;
      }
    break;
    default: break;
  }
  _last_reading = _reading;
}

bool FancyButton::press(){
    if (press_flag){
      press_flag = false;
      return true;
    }
    return false;
}

bool FancyButton::short_press(){
    if (short_press_flag){
      short_press_flag = false;
      return true;
    }
    return false;
}

bool FancyButton::long_press(){
    if (long_press_flag){
      long_press_flag = false;
      return true;
    }
    return false;
}

bool FancyButton::long_released(){
    if (release_long_flag){
      release_long_flag = false;
      return true;
    }
    return false;
}

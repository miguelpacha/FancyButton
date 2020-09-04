/*
 * FancyButton.cpp - Library for debouncing and generating long press events
 * Created by Miguel Pachá, Sep 4, 2020.
 * 
 * License: LGPL
 */


#ifndef FancyButton_h
#define FancyButton_h

#include "Arduino.h"

class FancyButton
{
  public:
    FancyButton(int pin);
    void check();
    volatile bool press_flag;
    volatile bool short_press_flag;
    volatile bool long_press_flag;
    volatile bool release_long_flag;
    const unsigned long LONG_PRESS_TIME  = 2000;
    const unsigned long debounceDelay = 50; // debounce time; increase if output flickers
   private:
    int _pin;
    volatile bool _counting = false;
    volatile bool _reading;
    volatile bool _last_reading = HIGH;
    volatile unsigned long _last_event;
    enum button_state {
      standby,
      pressed,
      long_pressed  
      };
     button_state _state = standby;
};

#endif

# iot_fastled [![Build Status](https://travis-ci.org/dgorbunov/iot_fastled.svg?branch=master)](https://travis-ci.org/dgorbunov/iot_fastled)

Google Assistant (or other services like Alexa) enabled addressable light strips using FastLED. 

Two Arduinos are required (one NodeMCU and another generic Arduino) because:
- A realtime response from Adafruit IO cannot be achieved without continusouly interrupting the lightstrip code
- The NodeMCU is often incompatibile with lightstrips without logic level converters and other hardware adjustments

# Voice Commands:
Syntax:
- Turn Lightstrip off/on (sets lightstrip brightness to 0/default brightness)
- Set Lightstrip brightness to 100 % (ramps brightness)
- Set Lightstrip to 12 (sets the mode)

These can be declared as needed in IFTTT but make sure that IFTTT only sends the textfield to the mode feed and the numberfield to the brightness feed.
# Framework
![concept map](https://github.com/dgorbunov/iot_fastled/blob/master/ConceptMap.PNG)

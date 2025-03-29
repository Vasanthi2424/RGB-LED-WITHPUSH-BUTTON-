
 int buttonPin = 12;    
int redPin = 11;       
int greenPin = 9;    
int bluePin = 10;     

int buttonState = 0;        
int lastButtonState = 0;   
 long lastDebounceTime = 0;  
 long debounceDelay = 50;    
int clickCount = 0;         
 long firstClickTime = 0;   
 long secondClickTime = 0;   

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        clickCount++;
        if (clickCount == 1) {
          firstClickTime = millis();
          setColor(255, 0, 0);  // Red
        } else if (clickCount == 2) {
          secondClickTime = millis();
          setColor(0, 255, 0);  // Green
        } else {
          setColor(0, 0, 255);  // Blue
        }
      }
    }
  }

 /* if (clickCount == 1 && (millis() - firstClickTime) > 1000) {
    setColor(0, 0, 255);  // Blue if held longer than 1 second
  }

  if (clickCount == 2 && (millis() - secondClickTime) > 1000) {
    setColor(0, 0, 255);  // Blue if held longer than 1 second
  }
*/
  lastButtonState = reading;
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}



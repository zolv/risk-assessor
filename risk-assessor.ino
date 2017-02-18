int input1 = A0;
int input2 = A5;
int input3 = A2;
int input4 = A3;
int input5 = A1;
int input6 = A4;

int displayA = 2;
int displayB = 3;
int displayC = 4;
int displayD = 5;
int displayE = 6;
int displayF = 7;
int displayG = 8;

int RPin = 9;
int GPin = 10;
int BPin = 11;

int digit1 = 12;
int digit2 = 13;

const int RiskExtremeValue = 56;
const int RiskRedValue = 40;
const int RiskYellowValue = 20;

const int DigitDisplayDelay = 5;

int colorValueG = 60;
int colorValueR = 96;//160;

const int blinkCount = 24;
int blinkingTime = blinkCount / 2;

void setup() {
  Serial.begin(9600);

  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  pinMode(input5, INPUT);
  pinMode(input6, INPUT);

  pinMode(displayA, OUTPUT);
  pinMode(displayB, OUTPUT);
  pinMode(displayC, OUTPUT);
  pinMode(displayD, OUTPUT);
  pinMode(displayE, OUTPUT);
  pinMode(displayF, OUTPUT);
  pinMode(displayG, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
}

void loop() {

  int value = calculateRisk2();
  if (value < RiskExtremeValue) {
    blinkingTime = blinkCount / 2;
    displayColour(value);
  } else {
    continueBlinking();
  }

  displayValue(value);

}

int calculateRisk2() {
  const int input1Value = analogRead(input1);
  const int input1Scaled = map(constrain(input1Value, 0, 111), 0, 111, 1, 6);
  int input1Risk = 8;
  if (input1Value < 18) {
    input1Risk = 1;
  } else {
    if (input1Value < 47) {
      input1Risk = 3;
    } else {
      if (input1Value < 75) {
        input1Risk = 6;
      } else {
        if (input1Value < 102) {
          input1Risk = 10;
        } else {
          input1Risk = 15;
        }
      }
    }
  }

  const int input2Value = analogRead(input2);
  int input2Scaled = map(constrain(input2Value, 0, 111), 0, 111, 1, 4);
  int input2Risk = 5;
  if (input2Value < 36) {
    input2Risk = 1;
  } else {
    if (input2Value < 76) {
      input2Risk = 5;
    } else {
      input2Risk = 10;
    }
  }

  const int input3Value = analogRead(input3);
  int input3Risk = 0;

  if (input3Value < 46) {
    input3Risk = 1;
  } else {
    if (input3Value < 96) {
      input3Risk = 1;
    } else {
      if (input3Value < 149) {
        input3Risk = 2;
      } else {
        if (input3Value < 198) {
          input3Risk = 3;
        } else {
          if (input3Value < 245) {
            input3Risk = 4;
          } else {
            if (input3Value < 287) {
              input3Risk = 5;
            } else {
              if (input3Value < 340) {
                input3Risk = 6;
              } else {
                if (input3Value < 392) {
                  input3Risk = 7;
                } else {
                  if (input3Value < 445) {
                    input3Risk = 8;
                  } else {
                    if (input3Value < 500) {
                      input3Risk = 9;
                    } else {
                      input3Risk = 10;

                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }



  const int input4Value = analogRead(input4);
  int input4Scaled = map(constrain(input4Value, 0, 111), 0, 111, 1, 5);
  int input4Risk = 6;
  if (input4Value < 23) {
    input4Risk = 1;
  } else {
    if (input4Value < 54) {
      input4Risk = 4;
    } else {
      if (input4Value < 87) {
        input4Risk = 7;
      } else {
        input4Risk = 10;
      }
    }
  }


  int input5Value = analogRead(input5);
  int input5Risk = input5Value < 100 ? 5 : 1;

  const int input6Value = analogRead(input6);
  int input6Scaled = map(constrain(input6Value, 0, 111), 0, 111, 1, 5);
  int input6Risk = 6;
  switch (input6Scaled) {
    case 1:
      input6Risk = 1;
      break;
    case 2:
      input6Risk = 4;
      break;
    case 3:
      input6Risk = 7;
      break;
    case 4:
    case 5:
      input6Risk = 10;
      break;
  }
  if (input6Value < 25) {
    input6Risk = 1;
  } else {
    if (input6Value < 55) {
      input6Risk = 4;
    } else {
      if (input6Value < 84) {
        input6Risk = 7;
      } else {
        input6Risk = 10;
      }
    }
  }

  const int result = input1Risk + input2Risk + input3Risk + input4Risk + input5Risk + input6Risk;

  //  Serial.print(" 1: ");Serial.print(min1);Serial.print( "-");Serial.print(input1Value);Serial.print( "-");Serial.print(max1);Serial.println();
  //  Serial.print(" 2: ");Serial.print(min2);Serial.print( "-");Serial.print(input2Value);Serial.print( "-");Serial.print(max2);Serial.println();
  //  Serial.print(" 3: ");Serial.print(min3);Serial.print( "-");Serial.print(input3Value);Serial.print( "-");Serial.print(max3);Serial.println();
  //  Serial.print(" 4: ");Serial.print(min4);Serial.print( "-");Serial.print(input4Value);Serial.print( "-");Serial.print(max4);Serial.println();
  //  Serial.print(" 5: ");Serial.print(min5);Serial.print( "-");Serial.print(input5Value);Serial.print( "-");Serial.print(max5);Serial.println();
  //  Serial.print(" 6: ");Serial.print(min6);Serial.print( "-");Serial.print(input6Value);Serial.print( "-");Serial.print(max6);Serial.println();
  //  Serial.println();

  // Serial.print(input1Risk);Serial.print(input1Value);Serial.print( "+");
  //  Serial.print(input2Risk);Serial.print(input2Value);Serial.print( "+");
  // Serial.print(input3Value);Serial.print(splittedValue);Serial.print(" ");Serial.print( "+");
  // Serial.print(input4Risk);Serial.print(input4Value);Serial.print( "+");
  //  Serial.print(input5Risk);Serial.print(input5Value);Serial.print( "+");
  // Serial.print(input6Risk);Serial.print(input6Value);
  //Serial.print( "=");Serial.println(result);

  //  delay(1000);
  return result;
}

void displayValue(int value) {
  const int decimal = value / 10;
  displayDigit(decimal);
  turnOnSquare(2);
  delay(DigitDisplayDelay);

  const int unit = value % 10;
  displayDigit(unit);
  turnOnSquare(1);
  delay(DigitDisplayDelay);

  turnOnSquare(-1);
}

void turnOnSquare(int num) {
  switch (num) {
    case 1:
      digitalWrite(digit2, HIGH);
      digitalWrite(digit1, LOW);
      break;
    case 2:
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, LOW);
      break;

    case -1:
      digitalWrite(digit1, HIGH);
      digitalWrite(digit2, HIGH);
      break;
  }

  // Serial.print(digit1); Serial.print(" "); Serial.print(digit2); Serial.print(" ");
}

void displayDigit(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(displayA, a);
  digitalWrite(displayB, b);
  digitalWrite(displayC, c);
  digitalWrite(displayD, d);
  digitalWrite(displayE, e);
  digitalWrite(displayF, f);
  digitalWrite(displayG, g);
}
void displayDigit(byte num) {
  switch (num % 9) {
    case 0:
      displayDigit(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
      break;
    case 1:
      displayDigit(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
      break;
    case 2:
      displayDigit(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH);
      break;
    case 3:
      displayDigit(HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH);
      break;
    case 4:
      displayDigit(HIGH, HIGH, LOW, LOW, HIGH, LOW, HIGH);
      break;
    case 5:
      displayDigit(LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH);
      break;
    case 6:
      displayDigit(LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);
      break;
    case 7:
      displayDigit(HIGH, HIGH, LOW, LOW, LOW, HIGH, LOW);
      break;
    case 8:
      displayDigit(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);
      break;
    case 9:
      displayDigit(HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH);
      break;
  }
}
void displayColour(const int value) {

  int r, g, b = 0;
  if (value >= RiskRedValue) {
    r = colorValueR;
    g = 0;
  } else {
    if (value >= RiskYellowValue) {
      r = 3 * colorValueR / 4;
      g =  colorValueR / 4;
    } else {
      r = 0;
      g =  colorValueG;
    }
  }
  setRGBLed(r, g, b);

}

void continueBlinking() {
  int r, b;
  blinkingTime += 1;
  if (blinkingTime < blinkCount) {
    r = sin(blinkingTime);// map(blinkingTime, 0, blinkCount - 1, 0, colorValue);
    b =  -sin(blinkingTime);//, 0, blinkCount - 1, colorValue, 0);
  } else {
    r = map(blinkingTime, blinkCount, blinkCount * 2, colorValueR, 0);
    b = map(blinkingTime, blinkCount, blinkCount * 2, 0, colorValueR);
  }

  float x = blinkingTime * 6.28 / (blinkCount * 2);

  r = ((sin(x) + 1 ) / 2) * colorValueR; // map(blinkingTime, 0, blinkCount - 1, 0, colorValue);
  b = ((sin(x + 3.14159) + 1 ) / 2) * colorValueR;

  // Serial.print("\nx "); Serial.print(x);Serial.print(" r"); Serial.print(r);Serial.print(" b"); Serial.print(b);
  if (blinkingTime > 2 * blinkCount) {
    blinkingTime = 0;
  }
  setRGBLed(r, 0, b);
}

void setRGBLed(int r, int g, int b) {
  analogWrite(RPin, r);
  analogWrite(GPin, g);
  analogWrite(BPin, b);
}




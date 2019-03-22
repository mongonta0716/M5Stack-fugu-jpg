#include <M5Stack.h>
#include <M5StackUpdater.h>

void setup() {
  M5.begin();
  Wire.begin();
  if(digitalRead(BUTTON_A_PIN) == 0) {
    Serial.println("Will Load menu binary");
    updateFromFS(SD);
    ESP.restart();
  }

  // put your setup code here, to run once:
  M5.Lcd.setBrightness(200);  // BRIGHTNESS = MAX 255
  M5.Lcd.fillScreen(BLACK);   // CLEAR SCREEN
  M5.Lcd.setRotation(1);      // ROTATION
  M5.Lcd.drawJpgFile(SD, "/jpg/fugu_normal.jpg");  // Load Initial Image
  
}

void loop() {
  M5.update();
  // put your main code here, to run repeatedly:
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.drawJpgFile(SD, "/jpg/fugu_eyeclose.jpg");
  } else if (M5.BtnB.wasReleased()) {
    M5.Lcd.drawJpgFile(SD, "/jpg/fugu_normal.jpg");
  } else if (M5.BtnC.wasPressed()) {
    while (true) {
      M5.update();
      M5.Lcd.drawJpgFile(SD, "/jpg/fugu_water1.jpg");
      delay(10);
      M5.Lcd.drawJpgFile(SD, "/jpg/fugu_water2.jpg");
      delay(10);
      M5.Lcd.drawJpgFile(SD, "/jpg/fugu_water3.jpg");
      delay(10);
      if (M5.BtnC.wasReleased()) {
        M5.Lcd.drawJpgFile(SD, "/jpg/fugu_normal.jpg");
        break;    
      }
    }
  }
  
}

#include <Arduino.h>
#include "sound.h"
#include <LiquidCrystal.h>

const int pinY = 1; 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pinPiezo = 13;

int y = 0;
char default_obstacles[3][2] = { {6, 0}, {11, 1}, {16, 0}};
char obstacles[3][2] = { {6, 0}, {11, 1}, {16, 0}};
int score = 0;
int jump = 0;
int game_state = 0;

void win() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You won!");
  playWin(pinPiezo);
  game_state = 3;
}

void setup() {
  lcd.begin(16, 2);
}

void game_over() {
  lcd.clear();
  playLoss(pinPiezo);
  game_state = 2;
}

void tick() {
  delay(500);
  lcd.clear();
  if (jump > 0) {
    jump--;
    if (jump == 0) {
      tone(13, NOTE_C2, 100);
    }
  };
  y = analogRead(pinY);
  if (y < 400 && jump == 0) {
    tone(13, NOTE_C5, 100);
    jump = 4;
  }
  if (jump > 0) {
    lcd.setCursor(0, 0);
  } else {
    lcd.setCursor(0, 1);
  }
  lcd.print("@");

  for(int i = 0; i < 3; i++) {
    if (obstacles[i][0] == 0) {
      if ((jump > 0 && obstacles[i][1] == 0) || (jump == 0 && obstacles[i][1] == 1)) {
        game_over();
        return;
      } else if ((jump > 0 && obstacles[i][1] == 1) || (jump == 0 && obstacles[i][1] == 0)) {
        score++;
        tone(13, NOTE_CS4, 30);
      }
    }
    
    if (obstacles[i][0] == 0 ) {
      obstacles[i][0] = 15;
      obstacles[i][1] = random(2);
    }
    obstacles[i][0]--;
    if (!(obstacles[i][1] == 0 && obstacles[i][0] >= 14)) {
      lcd.setCursor(obstacles[i][0], obstacles[i][1]);
      lcd.print("!"); 
    }
  }

  if (score > 99) {
    win();
    return;
  }

  lcd.setCursor(14, 0);
  lcd.print(score);
}

void new_game() {
  lcd.clear();
  tone(13, NOTE_C5, 100);
  score = 0;
  jump = 0;
  for(int i = 0; i < 3; i++) {
    obstacles[i][0] = default_obstacles[i][0];
    obstacles[i][1] = default_obstacles[i][1];
  }
  game_state = 1;
}

void loop() {
  if (game_state == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Pull up");
    lcd.setCursor(0, 1);
    lcd.print("to start");
  } else if (game_state == 1) {
    tick();
  } else if (game_state == 2) {
    lcd.setCursor(0, 0);
    lcd.print("You lost!");
    lcd.setCursor(0, 1);
    char buf[12];
    snprintf(buf, 12, "Score: %d", score);
    lcd.print(buf);
  } else if (game_state == 3) {
    lcd.setCursor(0, 0);
    lcd.print("You won!");
  }
  if (game_state != 1) {
    y = analogRead(pinY);
    if (y < 400) {
      new_game();
    }
  }
}
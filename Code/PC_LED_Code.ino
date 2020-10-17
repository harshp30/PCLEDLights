#define red 11
#define blue 10               //DigitalPin values for RGB and on-off and mode switch
#define green 9
#define on_off_swt 2
#define mode_switch 4

int pot_pin = A1;
//int red_pin = A3;
//int blue_pin = A4;
//int green_pin = A5;
int diff = 3;
float time_break = 0;
float red_pot = 0;
float blue_pot = 0;
float green_pot = 0;
int flag = 0;

void setup() {
  
}

void loop() {
  int on_off_status = digitalRead(on_off_swt);
  
  if (on_off_status == 0) {
    analogWrite(red, 0);
    analogWrite(green, 0);               //Power on-off
    analogWrite(blue, 0);
  } else {
    int mode_status = digitalRead(mode_switch);      //if power on

    if (mode_status == 0) {
      int color_status = analogRead(pot_pin);
      int color = map(color_status, 0, 1023, 0, 765);          //mode set to static

      if(color < 256) {
        int color_val = color;
        analogWrite(red, 255 - color_val);
        analogWrite(blue, color_val);
      } else if(color >= 265 and color < 511) {
        int color_val = color - 255;
        analogWrite(blue, 255 - color_val);            // potentiometer controls color differenc math, which allows for all colors to be displayed in a pattern. As red decreases green increases, as green decreases blue increases, as blue decreases red increases and so on
        analogWrite(green, color_val);
      } else if(color >= 511 and color <= 765) {
        int color_val = color - 510;
        analogWrite(green, 255 - color_val);
        analogWrite(red, color_val);
      }
    } else {
      flag = 0;
      int red_val = 255;
      int blue_val = 0;
      int green_val = 0;                                 //mode set to dynamic
      analogWrite(red, red_val);                         
      analogWrite(blue, blue_val);
      analogWrite(green, green_val);
  
      while(blue_val != 255 and flag == 0) {
        analogWrite(red, red_val - diff);
        analogWrite(blue, blue_val + diff);
        blue_val += diff;
        red_val -= diff;
        int speed_status = analogRead(pot_pin);
        time_break = map(speed_status, 0, 1023, 3, 1000);
        delay(time_break);
        on_off_status = digitalRead(on_off_swt);
        mode_status = digitalRead(mode_switch);
        if(on_off_status == 0 or mode_status == 0) {
          flag = 1;
        } 
      }
      while(green_val != 255 and flag == 0) {
        analogWrite(blue, blue_val - diff);
        analogWrite(green, green_val + diff);
        green_val += diff;                                                           //color differenc math, potentionmeter controls the speed at which the lights change
        blue_val -= diff;
        int speed_status = analogRead(pot_pin);
        time_break = map(speed_status, 0, 1023, 3, 1000);
        delay(time_break);
        on_off_status = digitalRead(on_off_swt);
        mode_status = digitalRead(mode_switch);
        if(on_off_status == 0 or mode_status == 0) {
          flag = 1;
        } 
      }
      while(red_val != 255 and flag == 0) {
        analogWrite(green, green_val - diff);
        analogWrite(red, red_val + diff);
        red_val += diff;
        green_val -= diff;
        int speed_status = analogRead(pot_pin);
        time_break = map(speed_status, 0, 1023, 3, 1000);
        delay(time_break);
        on_off_status = digitalRead(on_off_swt);
        mode_status = digitalRead(mode_switch);
        if(on_off_status == 0 or mode_status == 0) {
          flag = 1;
        } 
      }
    }
  }
}

#define red 11
#define blue 10               //DigitalPin values for RGB and on-off and mode switch
#define green 9
#define on_off_swt 2
#define mode_switch 4

int red_pin = A3;
int blue_pin = A4;
int green_pin = A5;

void setup() {
}

void loop() {
  analogWrite(red, 255);
  analogWrite(blue, 255);
  analogWrite(green, 255);

}

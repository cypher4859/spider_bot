/***********************************************************
File name: 02_servo.ino
Description:   The servo motor circulates to 180 degrees, 90 degrees
               Degrees, 0 degrees,
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2020/06/09 
***********************************************************/
#include <Servo.h>
Servo d2servo;//create servo object to control a servo
Servo d4servo;
Servo d6servo;
Servo d8servo;
Servo d10servo;
Servo d12servo;

Servo servos_list[6] = { d2servo, d4servo, d6servo, d8servo, d10servo, d12servo };

void initialize_servo_pin(Servo servo_object, int servo_pin, int default_pin_position = 0)
{
  servo_object.attach(servo_pin);
  servo_object.write(default_pin_position);
}

void set_to_standby()
{
  Serial.print("Setting all servos to standby...");
  for (int servo_count = 0; servo_count < (sizeof(servos_list)/sizeof(servos_list[0])); servo_count++) {
    Serial.print("Servo setting to base position: d");
    Serial.println((servo_count + 1)*2);
    servos_list[servo_count].write(0);
  }
}

void legs_diagnostic()
{
  int positions[4] = { 0, 30, 90, 180 };
  
  for (int position_index = 0; position_index < (sizeof(positions)/sizeof(positions[0])); position_index++){
    for (int servo_count = 0; servo_count < 6; servo_count++) {
      servos_list[servo_count].write(positions[position_index]);
    }
    delay(2000);
  }
}

void setup()
{
  Serial.begin(9600);
  for (int servo_count = 0; servo_count < 6; servo_count++) {
    Serial.print("Initializing...");
    initialize_servo_pin(servos_list[servo_count], (servo_count + 1)*2);
  }
  
  delay(1000);//wait for a second
}

void loop()
{  
  set_to_standby();
  delay(4000);
}

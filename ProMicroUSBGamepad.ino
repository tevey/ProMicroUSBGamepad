//Based on https://github.com/MHeironimus/ArduinoJoystickLibrary
/*
	Code by Viktor René (@_tEvEy)
*/
#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
	10, 0,                  // Button Count, Hat Switch Count
	true, true, false,     // X and Y, but no Z Axis
	false, false, false,   // No Rx, Ry, or Rz
	false, false,          // No rudder or throttle
	false, false, false);  // No accelerator, brake, or steering

// Constant that maps the phyical pin to the joystick button.
const int START_PIN = 8;
const int SELECT_PIN = 9;

const int CROSS_PIN = 10;
const int CIRCLE_PIN = 14;
const int TRIANGLE_PIN = 20;
const int SQUARE_PIN = 16;

const int R1_PIN = 19;
const int R2_PIN = 18;

const int L1_PIN = 3;
const int L2_PIN = 2;

const int UP_PIN = 4;
const int RIGHT_PIN = 5;
const int LEFT_PIN = 6;
const int DOWN_PIN = 7;

// Last state of the button
int joyStickStates[14][2] = {
	{1, START_PIN},
	{1, SELECT_PIN},
	{1, CROSS_PIN},
	{1, CIRCLE_PIN},
	{1, TRIANGLE_PIN},
	{1, SQUARE_PIN},
	{1, R1_PIN},
	{1, R2_PIN},
	{1, L1_PIN},
	{1, L2_PIN},
	{1, UP_PIN},
	{1, RIGHT_PIN},
	{1, LEFT_PIN},
	{1, DOWN_PIN}
};

const int SQUARE_BUTTON = 0;
const int CROSS_BUTTON = 1;
const int CIRCLE_BUTTON = 2;
const int TRIANGLE_BUTTON = 3;
const int L1_BUTTON = 4;
const int L2_BUTTON = 6;
const int R1_BUTTON = 5;
const int R2_BUTTON = 7;
const int START_BUTTON = 8;
const int SELECT_BUTTON = 9;

const int JOYSTICK_CENTER = 128;
const int JOYSTICK_MAX = 256;
const int JOYSTICK_MIN = 0;

void setup() {
	// Initialize Button Pins
	for (int i = 0; i < 14; ++i)
	{
		pinMode(joyStickStates[i][1], INPUT_PULLUP);
	}

	// Initialize Joystick Library
	Joystick.begin();
	Joystick.setXAxisRange(0, 256);
	Joystick.setYAxisRange(0, 256);
}

void loop() {

	// Read pin values
	for (int i = 0; i < 14; i++) {
		int currentButtonState = !digitalRead(joyStickStates[i][1]);
		if (currentButtonState != joyStickStates[i][0]) {
			switch(joyStickStates[i][1]) {
				case UP_PIN:
					if (currentButtonState == 1) {
						Joystick.setYAxis(JOYSTICK_MIN);
					} else {
						Joystick.setYAxis(JOYSTICK_CENTER);
					}
				break;
				case RIGHT_PIN:
					if (currentButtonState == 1) {
						Joystick.setXAxis(JOYSTICK_MAX);
					} else {
						Joystick.setXAxis(JOYSTICK_CENTER);
					}
				break;
				case LEFT_PIN:
					if (currentButtonState == 1) {
						Joystick.setXAxis(JOYSTICK_MIN);
					} else {
						Joystick.setXAxis(JOYSTICK_CENTER);
					}
				break;
				case DOWN_PIN:
					if (currentButtonState == 1) {
						Joystick.setYAxis(JOYSTICK_MAX);
					} else {
						Joystick.setYAxis(JOYSTICK_CENTER);
					}
				break;
				case START_PIN:
					Joystick.setButton(START_BUTTON, currentButtonState);
				break;
				case SELECT_PIN:
					Joystick.setButton(SELECT_BUTTON, currentButtonState);
				break;
				case CROSS_PIN:
					Joystick.setButton(CROSS_BUTTON, currentButtonState);
				break;
				case CIRCLE_PIN:
					Joystick.setButton(CIRCLE_BUTTON, currentButtonState);
				break;
				case TRIANGLE_PIN:
					Joystick.setButton(TRIANGLE_BUTTON, currentButtonState);
				break;
				case SQUARE_PIN:
					Joystick.setButton(SQUARE_BUTTON, currentButtonState);
				break;
				case R1_PIN:
					Joystick.setButton(R1_BUTTON, currentButtonState);
				break;
				case R2_PIN:
					Joystick.setButton(R2_BUTTON, currentButtonState);
				break;
				case L1_PIN:
					Joystick.setButton(L1_BUTTON, currentButtonState);
				break;
				case L2_PIN:
					Joystick.setButton(L2_BUTTON, currentButtonState);
				break;
			}
			joyStickStates[i][0] = currentButtonState;
		}
	}
	delay(10);
}
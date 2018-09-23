/*
 * Crecomard.h
 *
 *  Created on: 28 abr. 2017
 *      Author: marvin
 */

#include "ExtraFunction.h"
#ifndef CRECOMARD_H
#define CRECOMARD_H
#define IS_READY_TEST "IS_READY"

#define DW "DW"
#define AW "AW"
#define PM_CHANGE "PM_CHANGE"
#define DR "DR"
#define AR "AR"
#define PM_OUT "PM_OUT"
#define PM_IN "PM_IN"
#define PIN_STATES "PINS_STATES"
#define DR_ALL "DR_ALL"
#define DW_ALL "DW_ALL"

#define TASK_DONE "TASK_DONE"


class Crecomard {
public:
	Crecomard(HardwareSerial *btSerial);
	void printDebug(String data);
	void printDebug(char c);
	void printlnDebug(String data);
	void notifyEvent(String event, String message);
	void setAsOutput(int *pins, int pSize);
	void setAsOutput(int from, int to);
	void sendPinStates(int *pins, int size);
	void sendExternChange(int pin, bool digital);
	void sendExternChange(int pin, int state);
	void toHigh(int pin);
	void toLow(int pin);
	void togglePin(int pin);
	void listen(ExtraFunction *extra);
	void listen();
	void begin();
	void sendMessage(String _id, String message, int pin);

private:
	const String FUN = "{\"f\":\"";
	const String VALUE  = "\",\"v\":\"";
	const String EXTRA   = "\",\"e\":\"";
	const String END = "\"}";
	bool _debug = true;
	HardwareSerial *_btSerial;
	int numLen = 0;
	int valueLen = 0;
	int extraLen = 0;
	int endPos = 0;
	int valuePos = 0;
	int extraPos = 0;
	int pin = 0;
	int act = 0;
	String act2 = "";
	String p = "";
	String fun = "";
	String val = "";
	String ext = "";

	void resetValues();
	void process(ExtraFunction *extra);

	void splitOnOffAll();
	void splitDrAll();
};

#endif /* BLUINODROID_H_ */

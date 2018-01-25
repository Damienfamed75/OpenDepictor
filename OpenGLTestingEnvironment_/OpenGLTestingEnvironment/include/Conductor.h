#include <iostream>
#ifndef _CONDUCTOR_TIME_H
	#include <chrono>
	#include <ctime>
#define _CONDUCTOR_TIME_H
#endif

using std::cin;
using std::cout;

double calcTimeDiffInMs();
double calcBeatsInMs();

class Conductor {
	int _bpm;
	int _offsetInMs;
	double _lengthInS;
	

public:
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point currTime;
	std::chrono::milliseconds timeDiff;
	double totalBeats;
	double offsetBeats;
	double currBeat;
	
	float calcTotalBeats(double lengthInS, int bpm) {
		return (lengthInS / 60) * bpm;
	}

	Conductor(int bpm, double lengthInS, int offsetInMs) {
		_bpm = bpm;
		_lengthInS = lengthInS;
		_offsetInMs = offsetInMs;
		startTime = std::chrono::high_resolution_clock::now(); 
		totalBeats = calcTotalBeats(_lengthInS, _bpm) - offsetBeats; 
		offsetBeats = calcTotalBeats((double) _offsetInMs / 1000, _bpm);
	}

	float calcCurrentBeat();
	float calcBeatsInMs();
	void startTimer();
	void refreshMembers();	
	void conduct();
};

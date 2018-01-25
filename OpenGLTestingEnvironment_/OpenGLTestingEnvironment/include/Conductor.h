#include <iostream>
#ifndef CONDUCTOR_TIME
	#include <chrono>
	#include <ctime>
	#include "ChronoTypes.h"
#endif

#ifndef _GLIBCXX_MATH_H
	#include <math.h>
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
	ChronoTimePoint startTime;
	ChronoTimePoint currTime;
	ChronoMs timeDiff;
	double totalBeats;
	double offsetBeats;
	double currBeat;
	double beatSinceRefresh;
	float numBeatsSinceRefresh;	

	float calcTotalBeats(double lengthInS, int bpm) {
		return (lengthInS / 60) * bpm;
	}

	Conductor(int bpm, double lengthInS, int offsetInMs) {
		_bpm = bpm;
		_lengthInS = lengthInS;
		_offsetInMs = offsetInMs;
	}

	float calcCurrentBeat();
	float calcBeatsInMs();
	void startTimer();
	void refreshMembers();	
	void conduct();
};
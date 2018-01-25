#include "Conductor.h"
float calcTimeDiffInS(time_t startTime, double offsetInMs) {
	auto currTimeT = std::chrono::system_clock::to_time_t(std::chrono::high_resolution_clock::now()) - offsetInMs / 1000;  
	return currTimeT - startTime;
}

float calcBeatsInMs(int bpm) {
	return bpm / 60 / 1000;
}

float Conductor::calcCurrentBeat() {
	auto timeDiffInMin = calcTimeDiffInS(std::chrono::system_clock::to_time_t(startTime), _offsetInMs) / 60;
	return timeDiffInMin * _bpm;
}

void Conductor::startTimer() {
}

void Conductor::refreshMembers() {
	currTime = std::chrono::high_resolution_clock::now();  
	timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currTime - startTime);
	currBeat = calcCurrentBeat() - offsetBeats;
}

void Conductor::conduct() {
	auto startTimeT = std::chrono::system_clock::to_time_t(startTime);
	time_t currTimeT;
	while(timeDiff.count() / 1000 < _lengthInS) {
		refreshMembers();
		currTimeT = std::chrono::system_clock::to_time_t(currTime);
		cout << "Start time (s): " << startTimeT;
		cout << "\nCurrent time (s): " << currTimeT;
		cout << "\nOffset (ms): " << _offsetInMs;
		cout << "\nTime (s): " << (double) timeDiff.count() / 1000 << " / " << _lengthInS;
		cout << "\nOffset beats: " << offsetBeats;
		cout << "\nCurrent beat: " << currBeat << " / " << totalBeats << std::endl;
		std::system("clear");
	}
}
/*
int main(int argc, char **argv) {
	if (argc < 4) {
		cout << "Error: not all arguments supplied";
		return 1;
	}
	
	int bpm = std::stoi(argv[1]);
	double lengthInS = std::stod(argv[2], NULL);
	int offsetInMs = std::stoi(argv[3]);

	Conductor conductor(bpm, lengthInS, offsetInMs);
	conductor.conduct();
	return 0;
*/

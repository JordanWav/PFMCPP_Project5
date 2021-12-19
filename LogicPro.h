#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct LogicPro
{
    float sampleRate;
    std::string nameOfInputDevice;
    std::string nameOfProject;
    int numTracks;
    double tempo;

    LogicPro();
    ~LogicPro();

    std::string createInstrumentTrack(const LogicPro& trackA);
    std::string insertPlugin(const LogicPro& trackA);
    int recordPerformance(const LogicPro& trackB);
    int addTracks(int numTracksNeeded);
    void printSampleRate();

    JUCE_LEAK_DETECTOR(LogicPro)
};

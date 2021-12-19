#include "LogicPro.h"

LogicPro::LogicPro() : sampleRate(44100.f), nameOfInputDevice("Scarlett 2i4"), nameOfProject("My Song"), numTracks(25), tempo(135)
{
    std::cout << "Logic Pro Opened" << std::endl;
    std::cout << std::endl;

    std::cout << "Number of tracks in session: " << numTracks << 
    std::endl;

    std::cout << "Session tempo: " << tempo << " BPM" <<
    std::endl;

}

LogicPro::~LogicPro()
{
    std::cout << "Logic Pro Closed" << std::endl;
}

std::string LogicPro::createInstrumentTrack(const LogicPro& trackA)
{
    if ( trackA.numTracks < 1000 )
    {
        std::cout << "New track created!" << std::endl;
        return "new track";
    }
    std::cout << "Could not make a new track" << std::endl;
    return "!";
}

std::string LogicPro::insertPlugin(const LogicPro& trackA)
{
    if ( trackA.nameOfProject == "my project" )
    {
        std::cout << "Plugin inserted!" << std::endl;
        return "FabFilter Pro-Q 3";
    }
    std::cout << "Plugin could not be inserted!" << std::endl;
    return "no plugin";
}

int LogicPro::recordPerformance(const LogicPro& trackB)
{
    if ( trackB.nameOfInputDevice == "SSL 2+")
    {
        std::cout << "Input device: " << trackB.nameOfInputDevice << std::endl;
        return 0;
    }
    if ( trackB.nameOfInputDevice == "Focusrite Scarlett 2i2")
    {
        std::cout << "Wrong Input Device Selected" << std::endl;
        return 1; 
    }
    if ( trackB.numTracks == 0 )
    {
        std::cout << "Please Create a New Track" << std::endl;
        return 2;
    }
    std::cout << "Something Went Wrong... Please Try Again" << std::endl;
    return 3;
}

int LogicPro::addTracks(int numTracksNeeded)
{
    for( int i = 1; i <= numTracksNeeded; ++i )
    {
        ++numTracks;
        std::cout << "Track " << numTracks << " created" << std::endl;
    }
    std::cout << "New total number of tracks: " << numTracks << std::endl;
    return numTracks;
}

void LogicPro::printSampleRate()
{
    std::cout << "THIS Sample rate: " << this->sampleRate << std::endl;
}

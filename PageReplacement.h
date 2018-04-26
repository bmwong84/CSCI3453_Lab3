#ifndef PAGING_
#define PAGING_
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

struct page
{
	int pageRequest=-1;
	int frameIndex=0;
	int usedCounter = 0;
	int distanceSinceUsed=0;
	int distanceUntilUsed = 0;
};

class PageReplacement
{
private:
	std::vector <int> pages;
	page* frames = nullptr;
	int frameSize = 0;
	int faults2000 = 0;
	int faults4000 = 0;
	int faults6000 = 0;
	int faults8000 = 0;
	int faults10000 = 0;
	int totalFaults = 0;
	int framesFilled = 0;
	int lastReplacedIndex = 0;
	std::vector <int> FIFOResults;
	std::vector <int> LRUResults;
	std::vector <int> MFUResults;
	std::vector <int> LFUResults;
	std::vector <int>OptimalResults;

public:
	PageReplacement();
	~PageReplacement();
	int getFrameSize()
	{
		return frameSize;
	}
	void setframeSize(int _frameSize)
	{
		frameSize = _frameSize;
	}

	void runFramesMenu();
	//void runAlgorithmMenu();
	void readData();
	void runFIFO();
	void runLRU();
	void runMFU();
	void runLFU();
	void runOptimal();
	bool scanHit(int page);
	void printOutput();
	void incrementFaults(int pageReference);
	int findMostUsed();
	int findLeastUsed();
	int findLeastRecentlyUsed();
	int findLongestFutureDistance();
};

#endif // !PAGING_


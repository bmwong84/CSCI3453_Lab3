#include "PageReplacement.h"
#include<fstream>
#include <algorithm>


PageReplacement::PageReplacement()
{
	frames = new page[frameSize];
}

PageReplacement::~PageReplacement()
{
	delete[] frames;
}

void PageReplacement::runFramesMenu()
{
	char menuchoice = '0';
	while (menuchoice != '5')
	{
		std::cout << "Page replacement algorithm simulator" << std::endl;
		std::cout << "Please enter the number of page frames you wish to simulate" << std::endl;
		if (frameSize != 0)
		{
			delete[] frames;
			frameSize = 0;
		}
		pages.clear();
		std::cout << "1. 128 Frames" << std::endl;
		std::cout << "2. 256 Frames" << std::endl;
		std::cout << "3. 512 Frames" << std::endl;
		std::cout << "4. 1024 Frames" << std::endl;
		std::cout << "5. Exit simulation" << std::endl;
		std::cin >> menuchoice;
		switch (menuchoice)
		{
		case'1': 
		{
			frames = new page[128];
			setframeSize(128);
			//runAlgorithmMenu();
			readData();
			runFIFO();
			delete[]frames;
			frameSize = 0;
			frames = new page[128];
			setframeSize(128);
			runLRU();
			//delete[]frames;
			//frameSize = 0;
			//frames = new page[128];
			//setframeSize(128);
			//runMFU();
			delete[]frames;
			frameSize = 0;
			frames = new page[128];
			setframeSize(128);
			runLFU();
			delete[]frames;
			frameSize = 0;
			frames = new page[128];
			setframeSize(128);
			runOptimal();
			printOutput();
			break;
		}
		case'2':
		{
			frames = new page[256];
			setframeSize(256);
			readData();
			runFIFO();
			delete[]frames;
			frameSize = 0;
			frames = new page[256];
			setframeSize(256);
			runLRU();
			//delete[]frames;
			//frameSize = 0;
			//frames = new page[256];
			//setframeSize(256);
			//runMFU();
			delete[]frames;
			frameSize = 0;
			frames = new page[256];
			setframeSize(256);
			runLFU();
			delete[]frames;
			frameSize = 0;
			frames = new page[256];
			setframeSize(256);
			runOptimal();
			printOutput();
			break;
		}
		case'3':
		{
			frames = new page[512];
			setframeSize(512);
			readData();
			runFIFO();
			delete[]frames;
			frameSize = 0;
			frames = new page[512];
			setframeSize(512);
			runLRU();
			delete[]frames;
			//frameSize = 0;
			//frames = new page[512];
			//setframeSize(512);
			//runMFU();
			//delete[]frames;
			frameSize = 0;
			frames = new page[512];
			setframeSize(512);
			runLFU();
			delete[]frames;
			frameSize = 0;
			frames = new page[512];
			setframeSize(512);
			runOptimal();
			printOutput();
			break;
		}
		case'4':
		{
			frames = new page[1024];
			setframeSize(1024);
			readData();
			runFIFO();
			delete[]frames;
			frameSize = 0;
			frames = new page[1024];
			setframeSize(1024);
			runLRU();
			delete[]frames;
			//frameSize = 0;
			//frames = new page[1024];
			//setframeSize(1024);
			//runMFU();
			//delete[]frames;
			frameSize = 0;
			frames = new page[1024];
			setframeSize(1024);
			runLFU();
			delete[]frames;
			frameSize = 0;
			frames = new page[1024];
			setframeSize(1024);
			runOptimal();
			printOutput();
			break;
		}
		case'5':
		{
			frames = new page[0];
			break;
		}
		default:
			std::cout << "Invalid choice, enter a valid choice" << std::endl;
		}
	}
}


void PageReplacement::readData()
{
	std::cout << "Enter name of file to read" << std::endl;
	std::string filename;
	std::cin >> filename;
	std::ifstream infile;
	infile.open(filename.c_str());
	std::string temp;
	while (std::getline(infile, temp))
	{
		int tempInt = std::stoi(temp);
		pages.push_back(tempInt);
	}
	infile.close();
}

bool PageReplacement::scanHit(int page)
{
	for (int count = 0; count < frameSize; count++)
	{
		if (page == frames[count].pageRequest)
		{
			return true;
		}
	}
	return false;
}



void PageReplacement::printOutput()
{
	std::cout << "Page Replacement Algorithm Simulation (frame size = " << getFrameSize() << ")" << std::endl;
	std::cout << std::setw(57) << "Page fault rates" << std::endl;
	std::cout << "Algorithm" << std::setw(14) << "Total faults" << std::setw(8) << "2000"
		<< std::setw(9) << "4000" << std::setw(10) << "6000" << std::setw(10) << "8000" << std::setw(10) << "10000"
		<< std::endl;
	std::cout << std::setw(6) << "FIFO" << std::setw(12) << FIFOResults[5] 
		<< std::setw(13)<< std::fixed<< std::setprecision(4) << (float)FIFOResults[0] / (float)2000
		<< std::setw(10) << (float)FIFOResults[1] / (float)2000 << std::setw(10) << (float)FIFOResults[2] / (float)2000
		<< std::setw(10) << (float)FIFOResults[3] / (float)2000 << std::setw(10) << (float)FIFOResults[4] / (float)2000 << std::endl;
	std::cout << std::setw(6) << "LRU" << std::setw(12) << LRUResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)LRUResults[0] / (float)2000
		<< std::setw(10) << (float)LRUResults[1] / (float)2000 << std::setw(10) << (float)LRUResults[2] / (float)2000
		<< std::setw(10) << (float)LRUResults[3] / (float)2000 << std::setw(10) << (float)LRUResults[4] / (float)2000 << std::endl;
	//std::cout << std::setw(6) << "MFU" << std::setw(12) << MFUResults[5]
	//	<< std::setw(13) << std::fixed << std::setprecision(4) << (float)MFUResults[0] / (float)2000
	//	<< std::setw(10) << (float)MFUResults[1] / (float)2000 << std::setw(10) << (float)MFUResults[2] / (float)2000
	//	<< std::setw(10) << (float)MFUResults[3] / (float)2000 << std::setw(10) << (float)MFUResults[4] / (float)2000 << std::endl;
	std::cout << std::setw(6) << "LFU" << std::setw(12) << LFUResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)LFUResults[0] / (float)2000
		<< std::setw(10) << (float)LFUResults[1] / (float)2000 << std::setw(10) << (float)LFUResults[2] / (float)2000
		<< std::setw(10) << (float)LFUResults[3] / (float)2000 << std::setw(10) << (float)LFUResults[4] / (float)2000 << std::endl;
	std::cout << std::setw(6) << "Optimal" << std::setw(12) << OptimalResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)OptimalResults[0] / (float)2000
		<< std::setw(10) << (float)OptimalResults[1] / (float)2000 << std::setw(10) << (float)OptimalResults[2] / (float)2000
		<< std::setw(10) << (float)OptimalResults[3] / (float)2000 << std::setw(10) << (float)OptimalResults[4] / (float)2000 << std::endl;

	std::ofstream outfile;
	std::string filename;
	std::cin.ignore(1);
	std::cout << "Enter an output file name" << std::endl;
	std::getline(std::cin, filename);
	outfile.open(filename.c_str());
	outfile << "Page Replacement Algorithm Simulation (frame size = " << getFrameSize() << ")" << std::endl;
	outfile << std::setw(57) << "Page fault rates" << std::endl;
	outfile << "Algorithm" << std::setw(14) << "Total faults" << std::setw(8) << "2000"
		<< std::setw(9) << "4000" << std::setw(10) << "6000" << std::setw(10) << "8000" << std::setw(10) << "10000"
		<< std::endl;
	outfile << std::setw(6) << "FIFO" << std::setw(12) << FIFOResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)FIFOResults[0] / (float)2000
		<< std::setw(10) << (float)FIFOResults[1] / (float)2000 << std::setw(10) << (float)FIFOResults[2] / (float)2000
		<< std::setw(10) << (float)FIFOResults[3] / (float)2000 << std::setw(10) << (float)FIFOResults[4] / (float)2000 << std::endl;
	outfile << std::setw(6) << "LRU" << std::setw(12) << LRUResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)LRUResults[0] / (float)2000
		<< std::setw(10) << (float)LRUResults[1] / (float)2000 << std::setw(10) << (float)LRUResults[2] / (float)2000
		<< std::setw(10) << (float)LRUResults[3] / (float)2000 << std::setw(10) << (float)LRUResults[4] / (float)2000 << std::endl;
	//outfile << std::setw(6) << "MFU" << std::setw(12) << MFUResults[5]
	//	<< std::setw(13) << std::fixed << std::setprecision(4) << (float)MFUResults[0] / (float)2000
	//	<< std::setw(10) << (float)MFUResults[1] / (float)2000 << std::setw(10) << (float)MFUResults[2] / (float)2000
	//	<< std::setw(10) << (float)MFUResults[3] / (float)2000 << std::setw(10) << (float)MFUResults[4] / (float)2000 << std::endl;
	outfile << std::setw(6) << "LFU" << std::setw(12) << LFUResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)LFUResults[0] / (float)2000
		<< std::setw(10) << (float)LFUResults[1] / (float)2000 << std::setw(10) << (float)LFUResults[2] / (float)2000
		<< std::setw(10) << (float)LFUResults[3] / (float)2000 << std::setw(10) << (float)LFUResults[4] / (float)2000 << std::endl;
	outfile << std::setw(6) << "Optimal" << std::setw(12) << OptimalResults[5]
		<< std::setw(13) << std::fixed << std::setprecision(4) << (float)OptimalResults[0] / (float)2000
		<< std::setw(10) << (float)OptimalResults[1] / (float)2000 << std::setw(10) << (float)OptimalResults[2] / (float)2000
		<< std::setw(10) << (float)OptimalResults[3] / (float)2000 << std::setw(10) << (float)OptimalResults[4] / (float)2000 << std::endl;
}

void PageReplacement::runFIFO()
{

	faults2000 = 0;
	faults4000 = 0;
	faults6000 = 0;
	faults8000 = 0;
	faults10000 = 0;
	totalFaults = 0;
	framesFilled = 0;
	lastReplacedIndex = 0;
	FIFOResults.clear();
	for (int count = 0; count < pages.size(); count++)
	{
		if (scanHit(pages[count]) == false && framesFilled<frameSize)
		{
			framesFilled++;
			frames[framesFilled - 1].pageRequest = pages[count];
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == false && framesFilled >= frameSize)
		{
			//find index of last replaced, replace it with this page
			frames[lastReplacedIndex%frameSize].pageRequest = pages[count];
			lastReplacedIndex++;
			incrementFaults(count);
		}
		//test code for checking
		//for (int i = 0; i < framesFilled; i++)
		//{
		//	std::cout << frames[i].pageRequest << " ";
		//}
		//std::cout << std::endl;
	}
	FIFOResults.push_back(faults2000);
	FIFOResults.push_back(faults4000);
	FIFOResults.push_back(faults6000);
	FIFOResults.push_back(faults8000);
	FIFOResults.push_back(faults10000);
	FIFOResults.push_back(totalFaults);
}




int PageReplacement::findLeastUsed()
{
	int tempIndex = frameSize - 1;

	for (int count = frameSize - 1; count >= 0; count--)			//scans frames backwards
	{
		if (frames[count].usedCounter <= frames[tempIndex].usedCounter)
		{
			tempIndex = frames[count].frameIndex;
		}
	}
	return tempIndex;
}

void PageReplacement::runLFU()
{
	faults2000 = 0;
	faults4000 = 0;
	faults6000 = 0;
	faults8000 = 0;
	faults10000 = 0;
	totalFaults = 0;
	framesFilled = 0;
	LFUResults.clear();

	for (int count = 0; count < pages.size(); count++)
	{
		if (scanHit(pages[count]) == false && framesFilled<frameSize)
		{
			framesFilled++;
			frames[framesFilled - 1].pageRequest = pages[count];
			frames[framesFilled - 1].usedCounter++;
			frames[framesFilled - 1].frameIndex = framesFilled - 1;
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == false && framesFilled >= frameSize)
		{
			//find index of least frequently IN THE FRAMES used and replace that one with this incoming one

			int tempIndex = findLeastUsed();
			frames[tempIndex].pageRequest = pages[count];
			int tempUsed = 0;
			for (int i = 0; i < count + 1; i++)						//scan up to count
			{
				if (pages[i] == pages[count])
					tempUsed++;
			}
			frames[tempIndex].usedCounter = tempUsed;
			frames[tempIndex].frameIndex = tempIndex;
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == true)
		{
			for (int count2 = 0; count2 < frameSize; count2++)
			{
				if (frames[count2].pageRequest == pages[count])
				{
					frames[count2].usedCounter++;					//if most used is found, increase its used counter
					break;
				}
			}
		}
		//for debugging
		//for (int i = 0; i < framesFilled; i++)
		//{
		//	std::cout << frames[i].pageRequest << " ";
		//}
		//std::cout << std::endl;

	}
	LFUResults.push_back(faults2000);
	LFUResults.push_back(faults4000);
	LFUResults.push_back(faults6000);
	LFUResults.push_back(faults8000);
	LFUResults.push_back(faults10000);
	LFUResults.push_back(totalFaults);
}

//for LRU
int PageReplacement::findLeastRecentlyUsed()
{
	int tempIndex = 0;

	for (int count = frameSize - 1; count >= 0; count--)		//scan the frames backwards
	{
		if (frames[count].distanceSinceUsed >= frames[tempIndex].distanceSinceUsed)		//finds greatest distance amongst the frames
		{
			tempIndex = frames[count].frameIndex;
		}
	}
	return tempIndex;
}

void PageReplacement::runLRU()
{
	faults2000 = 0;
	faults4000 = 0;
	faults6000 = 0;
	faults8000 = 0;
	faults10000 = 0;
	totalFaults = 0;
	framesFilled = 0;
	LRUResults.clear();
	for (int count = 0; count < pages.size(); count++)
	{
		if (scanHit(pages[count]) == false && framesFilled<frameSize)		
		{
			framesFilled++;
			frames[framesFilled - 1].pageRequest = pages[count];
			frames[framesFilled - 1].frameIndex = framesFilled - 1;
			for (int i = 0; i < framesFilled; i++)			//increment the distance of all of those that were used
			{
				frames[i].distanceSinceUsed++;
			}
			frames[framesFilled - 1].distanceSinceUsed = 0;
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == false && framesFilled >= frameSize)
		{
			//scan the frames for the one with the highest distance, replace that one with the page[count]
			int tempIndex = findLeastRecentlyUsed();
			for (int i = 0; i < framesFilled; i++)			//increment the distance of all of those that were used
			{
				frames[i].distanceSinceUsed++;
			}
			frames[tempIndex].distanceSinceUsed = 0;
			frames[tempIndex].frameIndex = tempIndex;
			frames[tempIndex].pageRequest = pages[count];
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == true)
		{
			//scan the frames, reset the one that was hit's distance to 0
			for (int i = 0; i < framesFilled; i++)		//increments the distance of all the frames since they were last used
			{
				frames[i].distanceSinceUsed++;
				if (frames[i].pageRequest == pages[count])
				{
					frames[i].distanceSinceUsed = 0;		//sets the hit one's distance to 0
				}
			}
		}
		//for debugging
		//for (int i = 0; i < framesFilled; i++)
		//{
		//	std::cout << frames[i].pageRequest << " ";
		//}
		//std::cout << std::endl;
	}
	LRUResults.push_back(faults2000);
	LRUResults.push_back(faults4000);
	LRUResults.push_back(faults6000);
	LRUResults.push_back(faults8000);
	LRUResults.push_back(faults10000);
	LRUResults.push_back(totalFaults);
}

//for Optimal
int PageReplacement::findLongestFutureDistance()
{
	//scan frames for longest future distance, return first index
	int tempIndex=0;
	for (int count = 0; count < framesFilled; count++)
	{
		if (frames[count].distanceUntilUsed > frames[tempIndex].distanceUntilUsed)
		{
			tempIndex = frames[count].frameIndex;
		}
	}
	return tempIndex;
}


//works with 20 reference string given in the book, but the 10,000 entry one does not seem correct; too few replacements.
void PageReplacement::runOptimal()
{
	//same as LRU except, for each page, scan forwards in the REFERENCE STRING until the next time it sees itself in the future for the FIRST time 
	//and sets its distance.  If it is not found, then it is simply size of reference string - count
	//decrement every page's distance by 1 every time a new page from reference string is added
	faults2000 = 0;
	faults4000 = 0;
	faults6000 = 0;
	faults8000 = 0;
	faults10000 = 0;
	totalFaults = 0;
	framesFilled = 0;
	OptimalResults.clear();
	for (int count = 0; count < pages.size(); count++)
	{
		if (scanHit(pages[count]) == false && framesFilled<frameSize)
		{
			framesFilled++;
			frames[framesFilled - 1].pageRequest = pages[count];				//set the page number
			frames[framesFilled - 1].frameIndex = framesFilled - 1;			//set the frame index
			for (int i = 0; i < framesFilled; i++)			//decrement the distance
			{
				frames[i].distanceUntilUsed--;
			}
			for (int i = count+1; i < pages.size(); i++)			//probably should've used iterators for pages
			{
				if (pages[i] == pages[count])
				{
					frames[framesFilled - 1].distanceUntilUsed = i-count;
					break;					//breaks when first found so it doesn't hit the next
				}
				else if (i == pages.size()-1)  //if it is not ever used again/reaches end of the reference string, set distance until used = referencestring size - current position
				{
					frames[framesFilled - 1].distanceUntilUsed = pages.size();// -count;
				}
			}
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == false && framesFilled >= frameSize)
		{
			//find the one with the greatest distance within in page frames, replace that with incoming page request
			for (int i = 0; i < framesFilled; i++)			//decrement all the distances
			{
				frames[i].distanceUntilUsed--;
			}
			int tempIndex = findLongestFutureDistance();
			frames[tempIndex].frameIndex = tempIndex;
			frames[tempIndex].pageRequest = pages[count];
			for (int i = count + 1; i < pages.size(); i++)			//probably should've used iterators for pages
			{
				if (pages[i] == pages[count])
				{
					frames[tempIndex].distanceUntilUsed = i-count;
					break;					//breaks when first found so it doesn't hit the next
				}
				else if (i == pages.size() - 1)  //if it is not ever used again/reaches end of the reference string, set distance until used = referencestring size - current position
				{
					frames[tempIndex].distanceUntilUsed = pages.size();// - count;
				}
			}
			incrementFaults(count);
		}
		else if (scanHit(pages[count]) == true)
		{
			//scan pages to find the one hit, if it is the one hit, find the next time it is used, if not used, set distance = distance to end of reference string

			for (int i = 0; i < framesFilled; i++)
			{
				frames[i].distanceUntilUsed--;							//decrement all the distances
				if (pages[count] == frames[i].pageRequest)				//if it's the hit
				{
					for (int j = count + 1; j < pages.size(); j++)		 //find distance until it is next used, if not used again, set to distance to end of reference string
					{
						if (pages[j] == pages[count])
						{
							frames[i].distanceUntilUsed = j-count;
							break;					//breaks when first found so it doesn't hit the next
						}
						else if (j == pages.size() - 1)  //if it is not ever used again/reaches end of the reference string, set distance until used = referencestring size - current position
						{
							frames[i].distanceUntilUsed = pages.size();// -count;
						}
					}
				}
			}
		}//end elseif
		//for debugging
		//for (int i = 0; i < framesFilled; i++)
		//{
		//	std::cout << frames[i].pageRequest << " ";
		//}
		//std::cout << std::endl;
	}
	OptimalResults.push_back(faults2000);
	OptimalResults.push_back(faults4000);
	OptimalResults.push_back(faults6000);
	OptimalResults.push_back(faults8000);
	OptimalResults.push_back(faults10000);
	OptimalResults.push_back(totalFaults);
}

//counts the faults, splits them into blocks of 2000 up to 10000
void PageReplacement::incrementFaults(int pageReference)
{
	if (pageReference < 2000)
	{
		faults2000++;
	}
	else if (pageReference < 4000 && pageReference >= 2000)
	{
		faults4000++;
	}
	else if (pageReference < 6000 && pageReference >= 4000)
	{
		faults6000++;
	}
	else if (pageReference < 8000 && pageReference >= 6000)
	{
		faults8000++;
	}
	else if (pageReference < 10000 && pageReference >= 8000)
	{
		faults10000++;
	}
	totalFaults++;
}


////for MFU
//int PageReplacement::findMostUsed()
//{
//	int tempIndex = frameSize - 1;
//
//	for (int count = frameSize - 1; count >= 0; count--)			//scans frames backwards
//	{
//		if (frames[count].usedCounter >= frames[tempIndex].usedCounter)
//		{
//			tempIndex = frames[count].frameIndex;
//		}
//	}
//	return tempIndex;
//}


//void PageReplacement::runMFU()
//{
//	faults2000 = 0;
//	faults4000 = 0;
//	faults6000 = 0;
//	faults8000 = 0;
//	faults10000 = 0;
//	totalFaults = 0;
//	framesFilled = 0;
//	MFUResults.clear();
//	
//	for (int count = 0; count < pages.size(); count++)
//	{
//		if (scanHit(pages[count]) == false && framesFilled<frameSize)
//		{
//			framesFilled++;
//			frames[framesFilled - 1].pageRequest = pages[count];
//			frames[framesFilled - 1].usedCounter++;
//			frames[framesFilled - 1].frameIndex = framesFilled - 1;
//			incrementFaults(count);
//		}
//		else if (scanHit(pages[count]) == false && framesFilled >= frameSize)
//		{
//			//find index of most frequently used and replace with this
//			//FIND INDEX AT MAX
//			//tempIndex = std::max_element(frames[0], frames[frameSize - 1],predicate).frameIndex;	//index at max's frameIndex
//			int tempIndex = findMostUsed();
//			frames[tempIndex].pageRequest = pages[count];
//			int tempUsed = 0;
//			for (int i = 0; i < count+1; i++)						//scan up to count
//			{
//				if (pages[i] == pages[count])
//					tempUsed++;
//			}
//			frames[tempIndex].usedCounter = tempUsed;
//			frames[tempIndex].frameIndex = tempIndex;
//			incrementFaults(count);
//		}
//		else if (scanHit(pages[count]) == true)
//		{
//			for (int count2 = 0; count2 < frameSize; count2++)
//			{
//				if (frames[count2].pageRequest == pages[count])
//				{
//					frames[count2].usedCounter++;					//if most used is found, increase its used counter
//					break;
//				}
//			}
//		}
//		//for debugging
//		//for (int i = 0; i < framesFilled; i++)
//		//{
//		//	std::cout << frames[i].pageRequest << " ";
//		//}
//		//std::cout << std::endl;
//
//	}
//	MFUResults.push_back(faults2000);
//	MFUResults.push_back(faults4000);
//	MFUResults.push_back(faults6000);
//	MFUResults.push_back(faults8000);
//	MFUResults.push_back(faults10000);
//	MFUResults.push_back(totalFaults);
//}


//void PageReplacement::runAlgorithmMenu()
//{
//	char secondMenu = '0';
//	while (secondMenu != '1' && secondMenu !='2' && secondMenu !='3' && secondMenu !='4')
//	{
//		std::cout << "Choose algorithm to simulate" << std::endl;
//		std::cout << "1. First-in-First-Out (FIFO)" << std::endl;
//		std::cout << "2. Least Recently Used (LRU)" << std::endl;
//		std::cout << "3. Least Frequently Used (LFU)" << std::endl;
//		std::cout << "4. Optimal algorithm" << std::endl;
//		switch (secondMenu)
//		{
//		case'1':
//		{
//			runFIFO();
//			break;
//		}
//		case '2':
//		{
//			runLRU();
//			break;
//		}
//		case'3':
//		{
//			runLFU();
//			break;
//		}
//		case'4':
//		{
//			runOptimal();
//			break;
//		}
//		default:
//			std::cout << "Invalid choice, enter a valid choice" << std::endl;
//		}
//	}
//}

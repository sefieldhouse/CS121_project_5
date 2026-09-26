#include <iostream>
#include <time.h>
#include <array>
#include <cstdlib>

class Horse {
  private:
    int position;
    int horseIndex;
    int trackLength;
  public:
    Horse();
    void init(int index, int trackLength); // don't need to add parameters to other methods if we pass it
    void advance();                             // after the horse is born
    void printLane();
    bool isWinner();
}; // end class Horse

class Race {
  private:
    int TRACK_LENGTH; // uppercase implies int constants
    const static int NUM_HORSES = 5;
    std::array<Horse, NUM_HORSES> horses;
  public:
    Race(); // a constructor
    void start();
};

int main() {
  Race race;
  race.start();
  return 0;
} // end main
	  

Race::Race() {
  TRACK_LENGTH = 15;
  for (int index = 0; (index < NUM_HORSES); index++) {
    horses[index].init(index, TRACK_LENGTH);
  } // end for
} // end Race::Race()

void Race::start() {
  srand(time(NULL));
  bool keepGoing = true;
  while (keepGoing == true) {
    for (int index = 0; (index < NUM_HORSES) && (keepGoing == true); index++) {
      horses[index].advance();
      horses[index].printLane();
      bool winning = horses[index].isWinner();
      if (winning == true) {
        keepGoing = false;
      } // end if
    } // end for
    if (keepGoing == true) {
      std::cout << "Press ENTER for another turn.";
      std::cin.get();
    } // end if
    std::cout << std::endl;
  } // end while
} // end Race::start()

Horse::Horse() {
  position = 0;
  horseIndex = 0;
  trackLength = 15; // now a variable, not a constant
} // end Horse::Horse()

void Horse::init(int index, int trackLength) {  // init passes in the things we need
  Horse::horseIndex = index;
  Horse::trackLength = trackLength;
  Horse::position = 0;
} // end Horse::init

void Horse::advance() {
  int coin = (rand() % 2);
  position = (position + coin);
} // end Horse::advance()
  
void Horse::printLane() {
  for (int position = 0; position < trackLength; position++) { 
    if (Horse::position == position) {
      std::cout << Horse::horseIndex;
    } // end if
    else {
      std::cout << ".";
    } // end else
  } // end for
  std::cout << std::endl;
} // end Horse::printLane()

bool Horse::isWinner() {
  bool winning = false;
  if (position >= trackLength) {
    winning = true;
    std::cout << "Horse number " << horseIndex << " won!"; // index refers to the horse's ID
    std::cout << std::endl;
  } // end if
  return winning;
  } // end Horse::isWinner()


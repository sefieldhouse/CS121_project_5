OOP Horse Race Formula
classDiagram

class Horse {
  int position
  int horseIndex
  int trackLength
  Horse()
  init(int index, int trackLength)// don't need to add parameters to other methods if we pass it
  advance()                       // after the horse is born
  printLane()
  isWinner() bool 
}

class Race {
  int TRACK_LENGTH // uppercase implies int constants
  int NUM_HORSES
  Horse horses[]
  Race()// a constructor
  start()
}

Race → Horse
```

## Race::Race()
```
const int TRACK_LENGTH
const static int NUM_HORSES
Create an array of horses length NUM_HORSES
Initialize all the horses
For each horse
  initialize that horse with its index and the track length
```

## Race::start()
```
seed random (0 or 1)
bool keepGoing
while keepGoing
  go through each horse
    advance that horse
    print that horse’s lane
    if that horse won
      set keepGoing to false
```

## Horse::Horse()
```
position = 0
index = 0
trackLength = 15 // now a variable, not a constant
```

 ## void Horse::init(int index, int trackLength) // init passes in the things we need
```
Horse::index = index
Horse::trackLength = trackLength
Horse::position = 0
```

## Horse::advance()
```
roll a random 0-1 int, put in coin
add coin to position -> position
```

## Horse::printLane()
```
loop from 0 to track length
  if Horse::position == position
    print Horse::index
  else
    print a .
print a new line at the end
```

## bool Horse::isWinner()
```
bool winning = false
if position of horse >= trackLength
  set int winning = true
  print “Horse number “ >> horseID >> “ won!”
return winning
```

create a makefile and turn into code


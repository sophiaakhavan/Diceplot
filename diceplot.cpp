#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function prototypes
int roll();
void printHistogram(int counts[]);

int main(){
  /*int testCounts[21];
  for(int i=0; i<21; i++){
    testCounts[i] = i/2;
  }
  printHistogram(testCounts);*/
  srand(time(0)); //seeding the rng - putting in main instead of roll so it's only called once
  int n;
  int arr[21]={0}; //need to assign default values first (0)
  cout << "Enter a number: " << endl;
  cin >> n;
  

  for(int i=0; i<n; i++){
    int sum=-4; //declare inside outer for loop so it keeps resetting to -4
    //^-4 to adjust to range of 0-20 for array
    for(int j=0; j<4; j++){ //inner loop to roll 4 dice for each i iteration
      sum+=roll();
    }
    arr[sum]++; //add 1 to each element equaling sum
  }
  printHistogram(arr);
}

int roll(){ //random number between 1 and 6
  int r = 1 + (rand()%6); //if we want 3-sided dice, change 6 to 3
  return r;
}
void printHistogram(int counts[]){ //prints "x" counts[i] times
  for(int i=0; i<21; i++){
    cout << i+4 << ":";
    for(int j=0; j<counts[i]; j++){
      cout << "x";
    }
    cout << endl;
  }
}

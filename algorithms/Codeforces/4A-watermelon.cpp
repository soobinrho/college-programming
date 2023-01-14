#include <string>
#include <iostream>

using namespace std;

string checkEvenWatermelon(int inputInt) {
  /*
   *   Check if a watermelon can be divided into two parts.
   *   The condition is that both parts have to be an even number.
   *
   */
  const string answer = inputInt%2==0 ? "YES" : "NO";

  if (inputInt==2) return "NO";
  else return answer;
}

int main() {
  int buffer;
  cin>>buffer;
  cout<<checkEvenWatermelon(buffer);

  // Return 0 to signal success
  return 0;
}

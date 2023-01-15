#include <string>
#include <iostream>

using namespace std;

int main() {
  /*
   *   Check if a watermelon can be divided into two parts.
   *   The condition is that both parts have to be an even number.
   */

  int inputInt;
  cin>>inputInt;
  const string answer = inputInt%2==0 ? "YES" : "NO";

  if (inputInt==2) cout<<"NO";
  else cout<<answer;
}

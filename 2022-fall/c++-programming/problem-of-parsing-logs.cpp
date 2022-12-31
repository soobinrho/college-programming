#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> getPowerUsers(vector<string> logs, int threshhold);

int main() {

  vector<string> logs;
  logs.push_back("1 35 LOGIN");  // id, time, LOGIN/LOGOUT
  logs.push_back("2 38 LOGIN");
  logs.push_back("2 48 LOGOUT");
  logs.push_back("3 55 LOGIN");
  logs.push_back("3 394 LOGOUT");
  logs.push_back("1 1234153 LOGOUT");

  int threshholdTime = 10;  // in seconds

  cout<<"POWER USERS LIST\n";
  vector<string> listPowerUsers = getPowerUsers(logs,threshholdTime);
  for (const string& id : listPowerUsers) {
    cout<<"ID: "<<id<<'\n';
  }

  // Return 0 to signal success
  return 0;
}

vector<string> getPowerUsers(vector<string> logs, int threshhold) {

  const string LOGIN = "LOGIN";
  const string LOGOUT = "LOGOUT";

  map<int, int> timeLogin;
  map<int, int> timeLogout;
  for (int i=0; i<logs.size(); ++i) {
    // Parse the string into id, time, and type
    stringstream buffer {logs[i]};
    int id, time;
    string type;
    buffer>>id>>time>>type;

    // Assign logs into either timeLogin or timeLogout
    if (type==LOGIN) timeLogin[id] = time;
    else timeLogout[id] = time;
  }

  // This map decomposition declaration is a C++ 17 feature,
  // so here's a C++14 version:
  // Example:
  //   for (const auto member : timeLogin) {
  //     const int id = member.first;
  //     const int time = member.second;
  //     
  //     cout<<id<<"nice";
  //   }
  vector<string> listPowerUsers;
  for (const auto& [id, time] : timeLogin) {
    if (timeLogout[id]-time>=threshhold)
      listPowerUsers.push_back(to_string(id));
  }

  sort(listPowerUsers.begin(),listPowerUsers.end());
  return listPowerUsers;
}

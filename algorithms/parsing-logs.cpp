#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

namespace {
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
}

TEST_CASE("Parsing Log Files","[core]") {
  SECTION("Testing correct cases") {
    vector<string> logs = {"1 35 LOGIN", "2 38 LOGIN", "2 48 LOGOUT",
                           "3 55 LOGIN", "3 394 LOGOUT", "1 1234 LOGOUT"};
    vector<string> answer = {"1", "3"};
    CHECK(getPowerUsers(logs,60)==answer);
  }
}

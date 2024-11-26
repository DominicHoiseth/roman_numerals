#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_romanvals(string roman){
  vector<char> numerals = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  vector<int> numvals = {1, 5, 10, 50, 100, 500, 1000};
  vector<int> romanvals;
  
  for(auto i : roman){
    for(int j = 0; j < 7; j++){
      if(i == numerals[j])
        romanvals.push_back(numvals[j]);
    }
  }
  return romanvals;
}


int solution(string roman) {
  
  vector<int> romanvals = get_romanvals(roman);
  
  int total = 0;
  int small = 0;
  int numi = 0;
  for(int i = 0; i < romanvals.size(); i++){
    if(romanvals[i] == 1){
      for(int j = i; j < romanvals.size(); j++)
        if(romanvals[j] > 1){
          small = romanvals[j] - numi;
        } else {numi++;}
    }
    else {
      total += romanvals[i];
    }
    
  }
        
  return total + small;
}

#include <iostream>
#include <string>
#include <vector>

/*



*/

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
  for(int i = 0; i < romanvals.size(); i++){
    if((i + 1) < romanvals.size()){
        if(romanvals[i] >= romanvals[i + 1]){
            total += romanvals[i];
        } else {
            total -= romanvals[i];
        }
    } else {
        total += romanvals[i];
    }

  }

  return total;
}


int main(){
    cout << "Enter Roman Numerals: ";
    string num;
    cin >> num;
    for(int i = 0; i < num.length(); i++){
        if(i == ' ' || i == '\n')
            cout << "please re-enter";
        num.replace(i, 1, 1, toupper(num[i]));
    }

    
    cout << "Value: " << solution(num) << endl;

}
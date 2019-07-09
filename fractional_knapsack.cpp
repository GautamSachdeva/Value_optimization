#include <iostream>
#include <fstream>
#include "stdio.h"
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int storage = capacity;
  vector< pair<double,int> > pair_vector;
  for(int i = 0 ; i < weights.size() ; i++){
  	pair_vector.push_back(make_pair(double(values[i])/(double)(weights[i]),weights[i]));
  }
  stable_sort(pair_vector.begin(),pair_vector.end());
  int index = weights.size() - 1;
  while(storage != 0){
  	if(pair_vector[index].second > storage ){
  		value = value + storage * pair_vector[index].first;
  		storage = 0;
	  }
	  else{
	  	value = value + pair_vector[index].second * pair_vector[index].first;
	  	storage = storage - pair_vector[index].second;
	  }
	  index --;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

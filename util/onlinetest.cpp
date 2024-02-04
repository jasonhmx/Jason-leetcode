#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <limits>
#include <queue>
#include <cmath>
//
// Implement the OrderBook class
//
using namespace std;
class OrderBook {
public:
  void insert(double price, int id){
    id2price[id] = price;
    price2id[price].insert(id);
  }

  void erase(int id){
    double price = id2price[id];
    id2price.erase(id);
    price2id[price].erase(id);
    if(price2id[price].empty()){
        price2id.erase(price);
    }
  }

  double getHighestPrice(){
    if(id2price.empty()){
        return numeric_limits<double>::quiet_NaN();
    }
    return price2id.rbegin()->first;
  }

private:
    unordered_map<int, double> id2price; // id to price
    map<double, unordered_set<int>> price2id;
};


// Complete this function to parse the file and use the OrderBook class to
// compute the time weighted average high price.
//
double time_weighted_average_from_file(const char * filename)
{
  ifstream file(filename);
  OrderBook orderBook;
  int prevTimeStamp = 0;
  int totalTime = 0;
  double totalPrice = 0.0;
  string line;
  while (getline(file, line)){
    istringstream iss(line);
    int timestamp;
    int id;
    char operation;
    double price;
    iss >> timestamp >> operation >> id;

    double prevHighestPrice = orderBook.getHighestPrice();

    if (operation == 'I'){
      iss >> price;
      orderBook.insert(price, id);
    } else if (operation == 'E'){
      orderBook.erase(id);
    }

    int timediff = timestamp - prevTimeStamp;
    prevTimeStamp = timestamp;
    if (!isnan(prevHighestPrice)){
      totalPrice += prevHighestPrice * timediff;
      totalTime += timediff;
    }
  }
  file.close();
  return totalTime > 0 ? totalPrice / totalTime : 0.0;
}


int main()
{
  // The contents of the file is visible via the top right-hand 'files' menu
  std::cout << time_weighted_average_from_file("test.dat") << std::endl;
  return 0;
}

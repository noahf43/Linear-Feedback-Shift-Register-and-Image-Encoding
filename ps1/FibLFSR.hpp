#include <iostream>
#include <vector> 
#include <string>
#include <cmath>

class FibLFSR {
public:
// Constructor to create LFSR with the given initial seed
FibLFSR(std::string seed);

// Simulate one step and return the new bit as 0 or 1
int step();

friend std::ostream& operator<< (std::ostream& out, const FibLFSR& lfsr);
// Simulate k steps and return a k-bit integer
int generate(int k);
private:
char start;
std::vector<int> v;
// Any fields that you need
};
std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);

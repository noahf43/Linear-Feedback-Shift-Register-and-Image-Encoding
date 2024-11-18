#include "FibLFSR.hpp"
FibLFSR::FibLFSR(std::string seed)
{
    int size = seed.size();
    int i = 0;
    while(i<size)
    {
    start = seed[i];
    v.push_back(start-'0');
    i++;
    }
}
int FibLFSR::step()
{
   int size = v.size();
   int i = 0;
   int tap1 = 2,tap2 = 3,tap3 = 5;
   int sum1 = v.at(0) ^ v.at(tap1);
   int sum2 = sum1 ^ v.at(tap2);
   int sum3 = sum2 ^ v.at(tap3);
   //std::cout << "XOR: " << sum3 << std::endl;
   while(i<size-1)
   {
    v.at(i) = v.at(i+1);
    i++;
   }
   v.at(15) = sum3;
   return sum3;
}
int FibLFSR::generate(int k)
{
    int i = 0;
    while(i<k)
    {
    this->step();
    i++;
    }
    int size = v.size();
    int p = size-k;
    int product = 0;
    int power = k-1;
    while(p<size)
    {
        product += v.at(p) * pow(2,power);
        power--;
        p++;
    }
    return product;
}
std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr)
{
int size = lfsr.v.size();
for(int i = 0;i<size;i++)
{
    out << lfsr.v.at(i);
}
return out;
}
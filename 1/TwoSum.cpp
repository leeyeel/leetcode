#include <iostream>
#include <vector>
#include<time.h>
using namespace std;

class Solution {
public:

    vector <int> b;
    vector<int> twoSum(vector<int>& nums, int target) {
    int size=nums.size();
    for(int i=0;i<size;i++){
     for(int j=i+1;j<size;j++){
     if(nums[i]+nums[j]==target){
     b.push_back(nums[i]);
     b.push_back(nums[j]);
     std::cout<<b[0]<<"!!"<<b[1]<<std::endl;
     return b;
      }
     }
    }
   }

};

int main(){
   clock_t start_time=clock();
   vector<int> v;
   for(int i=0;i<100;i++){
   v.push_back(i);
   }
   Solution so;
   so.twoSum(v,167);
   clock_t end_time=clock();
   cout<< "Running time is: "<<static_cast<double>(end_time-start_time)<<"\n";	
   return 0;

   }
   

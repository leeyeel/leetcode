#include <iostream>
#include <vector>
#include<time.h>
#include<map>
#include<string>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> vv;
    map<int,int> m;
   for(int i = 0; i < nums.size(); i++){
    if(m.count(target-nums[i]) ==1){
      vv.push_back(m[target - nums[i]]);
      vv.push_back(i);
      break;
      }
      m[nums[i]] = i;
    }
     cout<<vv[0]<<" "<<vv[1]<<endl;
     return vv;
  }
};

int main(){
   clock_t start_time=clock();
   vector<int> v;
   for(int i=0;i<100;i++){
   v.push_back(i*i);
   }
   Solution so;
   so.twoSum(v,73);
   clock_t end_time=clock();
   cout<< "Running time is: "<<static_cast<double>(end_time-start_time)<<"\n";	
   return 0;

   }
   

#include <iostream>
#include <vector>
#include<time.h>
#include<map>
#include<string>
using namespace std;

class Solution {

public:

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<int> v1;
        vector<vector<int> > v2;
        map<int,int> m;
        const int size=nums.size();
        for(int i=0;i<size;i++){
         m[nums[i]]=i; 
        }
        for(int i=0;i<size;i++){
         for(int j=i+1;j<size;j++){
             int another=0-nums[i]-nums[j];
             if(m.count(another)==1 && i!=j){
                 v1.push_back(nums[i]);
                 v1.push_back(nums[j]);
                 v1.push_back(another);
                 v2.push_back(v1);
             }
          }
        }
        int size2=v2.size();
        cout<<"size1 is :"<<size<<endl;
        cout<<"size2 is :"<<size2<<endl;
        for(int i=0;i<size2;i++){
    //     cout<<"["<<v2[i][0]<<","<<v2[i][1]<<","<<v2[i][2]<<"]\n";
          }

        return v2;
    }

};
int main(){
   clock_t start_time=clock();
   vector<int> v;
   int ay[130]={-4,-8,7,13,10,1,-14,-13,0,8,6,-13,-5,-4,-12,2,-11,7,-5,0,-9,-14,-8,-9,2,-7,-13,-3,13,9,-14,-6,8,1,14,-5,-13,8,-10,-5,1,11,-11,3,14,-8,-10,-12,6,-8,-5,13,-15,2,11,-5,10,6,-1,1,0,0,2,-7,8,-6,3,3,-13,8,5,-5,-3,9,5,-4,-14,11,-8,7,10,-6,-3,11,12,-14,-9,-1,7,5,-15,14,12,-5,-8,-2,4,2,-14,-2,-12,6,8,0,0,-2,3,-7,-14,2,7,12,12,12,0,9,13,-2,-15,-3,10,-14,-4,7,-12,3,-10};
   for(int i=0;i<130;i++){
   v.push_back(ay[i]);
   }
   Solution so;
   so.threeSum(v);
   clock_t end_time=clock();
   cout<< "Running time is: "<<static_cast<double>(end_time-start_time)<<"\n";	
   return 0;

   }
   

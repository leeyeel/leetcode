//实现输入一组大于等于0的整数，根据从小达到的顺序排序后输出，排序后有连续数时，质输出连续数中最小和最大的两个数
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
void mySort(std::vector<int>&);

int main(){
    int tmp;
    std::vector<int> input;
    do{
        std::cin>>tmp;
    input.push_back(tmp);
    }
    while(std::cin.get()==',');
    mySort(input);

    return 0;
}

void mySort(std::vector<int>& inPut0){
    sort(inPut0.begin(),inPut0.end());
    int num=0;
    vector<int> res;
    res.push_back(inPut0[0]);
    for(int i=1;i<inPut0.size()-1;++i){
        if(inPut0[i]+1==inPut0[i+1] && inPut0[i-1]+1==inPut0[i])
            continue;
        res.push_back(inPut0[i]);
    }
    res.push_back(inPut0.back());
    for(int i=0;i<res.size();++i){
        std::cout<<res[i]<<" ";
    }
    std::cout<<"\n";

}

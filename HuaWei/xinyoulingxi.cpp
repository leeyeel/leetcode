//http://blog.csdn.net/howeverpf/article/details/38470989
//心有灵犀一点通的题目
//存在bug,当第一行输入2a时不报错误
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;
int xinyoulingxi(std::vector<int> );

int main(){
    int tmp;
    string line1,line2;
    std::vector<int> n1;
    std::vector<int> N;
    getline(cin,line1);
    istringstream stream1(line1);
    while(stream1>>tmp){
        n1.push_back(tmp);
    }
    
    if(n1.size()!=1 ||n1[0]<1 || n1[0]>500) {
        cout<<"-1\n";
        return -1;
    }
    getline(cin,line2);
    istringstream stream2(line2);
    while(stream2>>tmp){
    if(tmp>500 || tmp<1){
        cout<<"-1\n";
        return -1;
    }
    N.push_back(tmp);
    }
    if(2* n1[0] != N.size()){
        cout<<"-1"<<endl;
        return -1;
    }
    cout<<xinyoulingxi(N)<<endl;
}

int xinyoulingxi(std::vector<int>v){
    int num=0;
    int man=0,woman=0;
    for(int i=0;i<v.size();++i){
        man = man+v[i];
        for(int j=v.size()-1;j>-1;--j){
            woman = woman+v[j];
            if(man == woman)
                ++num;
        }
        woman = 0;
    }
    return num;
}

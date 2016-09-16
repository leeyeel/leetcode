#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

int huiwen(string &);

int main(){
    string test="adb    abcba  abcdefgfedcba        adfa adfgljlqew asdfajlj";
    huiwen(test);
    return 0;
}

int huiwen(string& str){
    vector<string> tmp;
    vector<string> result;
   if(str.length()>128) return 0;
    int size = str.size();
    int x;
    while(true){
    string sub1(str,0,str.find_first_of(" "));
    str.substr(str.find_first_of(" ")+1,size-1);
    string sub2(str,str.find(" ")+1,size-1);
    str=sub2;
    //std::cout<<sub1<<std::endl;
    tmp.push_back(sub1);
    if(sub2.find(" ") == string::npos) break;
    }
    for(int i=0;i<tmp.size();++i){
        int flag=0;
        int len=tmp[i].size();
        for(int j=0;j<len/2;++j){
            if(tmp[i][j]!=tmp[i][len-1-j])
                flag=1;
        }
        if(flag==0) result.push_back(tmp[i]);
    } 

    int a=0;
    for(int i=0;i<result.size();++i){
       // std::cout<<result[i]<<std::endl;
        a = result[i].size()>a ? result[i].size() : a;
    }
    for(int i=0;i<result.size();++i){
        if(a==0) std::cout<<""<<std::endl;
        if(result[i].size()==a){
        std::cout<<result[i]<<" ";
        }
    }
    std::cout<<std::endl; 
    return 0;
}

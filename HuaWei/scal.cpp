//十进制转12进制
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

void scal(int);

int main(){
   int input;
   std::cin>>input;
   scal(input);
   return 0;
}

void scal(int n){
    char tmp[2];
    int c=0;
    int p=16;
    std::vector<char> result;
    while(n){
        c = n%p;
        n = n/p;
        if(c>9){
            sprintf(tmp,"%c",(char)(c+55));
        }else{
            sprintf(tmp,"%d",c);
        }
        result.push_back(tmp[0]);
    }
    reverse(result.begin(),result.end());
    for(int i=0;i<result.size();++i){
        std::cout<<result[i];
    }
    std::cout<<"\n";
}

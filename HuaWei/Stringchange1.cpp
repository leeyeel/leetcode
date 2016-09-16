#include <iostream>
#include <cstring>
#include<cctype>
void Stringchange(const char* input,char* output){
    int len = strlen(input);
    for(short i=0;i<len;++i){
	if(input[i]=='z'||input[i]=='Z')
	    output[i] = input[i]-25;
	else
	    output[i] = input[i]+1;
    }
}
int main(){
    char a[9]="abDfzrTZ";
    char b[9];
    Stringchange(a,b);
    std::cout<<b<<std::endl;
    return 0;
}
   

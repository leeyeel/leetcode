//洞穴逃生题。
//思路是，如果够用魔法值就直接用魔法值，如果等一秒划算就等一秒，如果等两秒划算就等两秒
#include <iostream>
using namespace std;
int escape(int m,int s,int t){

    int distance=0;
    int flashdistance=0;
    int i=0;

    if(s==0){
        cout<<"YES 0\n" ;
        return 0;
    }else if(t==0){
        cout<<"NO 0\n";
        return 0;
    }else{
        for(i=1;i<=t;++i){

            if(m>=10){
                distance+=60;
                m=m-10;
            }else if(m>=6){
                if(s-distance>17){
                m=m+4;
                }else{
                distance+=17;
                cout<<"YES "<<i<<endl;
                return 0;
                }
            }else if(m>=2 ){
                if(s-distance>34){
                m=m+4;
                }else{
                distance+=17;
                }
            }else if(m>=0){
                if(s-distance>119){
                    m=m+4;
                }else{
                    distance+=17;
                }
            }
            if(distance>=s)
                break;
        }
        if(i<=t)
            cout << "Yes " << i << endl;
        else
            cout<< "NO "<<distance<<endl;
    }

    return 0;
}

int main(){
    int M,S,T;
    cin>>M;
    cin>>S;
    cin>>T;
    escape(M,S,T);
    return 0;
}

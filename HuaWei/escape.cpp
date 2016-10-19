//洞穴逃生题。
//思路是，如果够用魔法值就直接用魔法值，如果等一秒划算就等一秒，如果等两秒划算就等两秒
#include <iostream>
using namespace std;

int escape(int m,int s,int t){
    int distance=0;
    int i=0;

    if(s==0){
        cout<<"YES 0\n" ;
        return 0;
    }else if(t==0){
        cout<<"NO 0\n";
        return 0;
    }else{
        for(i=1;i<=t;++i){

            if(m>=10){ //魔法够了就闪
                distance+=60;
                m=m-10;
            }else if(m>=6){ //等一秒再闪，但是要考虑距离是否可以直接跑过去
                if(s-distance>17){ //距离长就等
                m=m+4;
                }else{
                distance+=17;
                cout<<"YES "<<i<<endl;
                return 0;
                }
            }else if(m>=2 ){ //等两秒在闪，但是还是要考虑距离
                if(s-distance>34){
                m=m+4;
                }else{
                distance+=17;
                }
            }else if(m>=0){ //等三秒再闪，只有距离大于119才是值得的，否则还不如直接跑
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

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char tmp[5];
    int y,mon,d,h,m,s;
    scanf("%d/%02d/%02d %02d:%02d:%02d",&y,&mon,&d,&h,&m,&s);
    int flagM=0;
    if(s==59){
        s=0;
        m=m+1;
        if(m==60){
            m=0;
            h=h+1;
            if(h==60){
                h=0;
                d=d+1;
                if((mon==4||mon==6||mon==9||mon==11)&&d==31){
                    flagM=1;
                }else if((mon==1||mon==3||mon==5||mon==7||mon==8||mon==10||mon==12)&& d==32){
                    flagM=1;
                }else if(y%4==0&&y%100==0 &&mon==2&&d==30){
                    flagM=1;
                }else if(y%4!=0&&mon==2&&d==29){
                    flagM=1;
                }
                if(flagM==1){
                    d=1;
                    mon=mon+1;
                    if(mon==13){
                        mon=1;
                        y=y+1;
                        printf("%d/%02d/%02d %02d:%02d:%02d\n",y,mon,d,h,m,s);
                    }else printf("%d/%02d/%02d %02d:%02d:%02d\n",y,mon,d,h,m,s);
                }else printf("%d/%02d/%02d %02d:%02d:%02d\n",y,mon,d,h,m,s);
            }else printf("%d/%02d/%02d %02d:%02d:%02d\n",y,mon,d,h,m,s);
        }else printf("%d/%02d/%02d %02d:%02d:%02d\n",y,mon,d,h,m,s);
    }else printf("%d/%02d/%02d %02d:%02d:%02d\n",y,mon,d,h,m,s+1);
    //    <<std::setfill('0')<<std::setw(2)<<h<<":"<<std::setfill('0')<<std::setw(2)<<m<<":"<<std::setfill('0')
}

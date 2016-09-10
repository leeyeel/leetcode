#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> >v(n,vector<int>(n,-1));
            int num=0;
            int left=0,right=n-1,top=0.,bottom=n-1;
            while(1){
                for(int i=left;i<right;++i){
                    v[top][i]=++num;
                }
                left++;
                if(num==n*n) break;

                for(int j=top;j<bottom;++j){
                    v[j][right]=++num;
                }
                top++;
                if(num==n*n) break;

                for(int k=right;k>=left;--k){
                    v[bottom][k]=++num;
                }
                right--;
                if(num==n*n) break;
                
                for(int m=bottom;m>=top;--m){
                    v[m][left-1]=++num;
                }
                bottom--;
                if(num==n*n) break;
                
                std::cout<<"num is "<<num<<std::endl; 
                if(n%2==1 && num+1==n*n){
                num++;
                v[n/2][n/2]=n*n;
                }
            }
        
                return v;
        }
};

int main(){
    Solution sol;
    std::cout<<"please type a number....\n";
    int test;
    std::cin>>test;
    vector<vector<int> > res = sol.generateMatrix(test);
    for(int i=0;i<test;++i){
        for(int j=0;j<test;++j){
            std::cout<<std::setw(3)<<res[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

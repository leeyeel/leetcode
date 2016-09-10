#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> >& matrix) {
            int m = matrix.size();
            int n = matrix.at(0).size();
            vector<int>v;
            //v.resize(m*n);  
            v.reserve(m*n);
            if(m==0) return v;
            int left=0,right=n-1,top=0,bottom=m-1;
            int countor=0;
            while(countor<n*m){
                for(int i=left;i<right;++i){
                    v.push_back(matrix[top][i]);
                    ++countor;
                }
                left++;
                for(int j=top;j<bottom;++j){
                    v.push_back(matrix[j][right]);
                    ++countor;
                }
                top++;
                for(int k=right;k>=left;--k){
                    v.push_back(matrix[bottom][k]);
                    ++countor;
                }
                right--;
                
                for(int l=bottom;l>=top;--l){
                    v.push_back(matrix[l][left-1]);
                    ++countor;
                }
                bottom--;

                std::cout<<"counter is "<<countor<<std::endl;

                if(countor+1==n*m){
                    v.push_back(n*m);
                    break;
                }
            }
            return v;
        }
};

int main(){
    int n1=3;
    int n2=4;
    int num=0;
    vector<vector<int> > test(n1,vector<int>(n2));
    for(int i=0;i<n1;++i){
        for(int j=0;j<n2;++j){
            test[i][j]=++num;
        }
    }

    Solution sol;
    vector<int> res = sol.spiralOrder(test);
    for(int i=0;i<n1*n2;++i){
        std::cout<<res[i]<<"  ";
    }
    std::cout<<std::endl;
}

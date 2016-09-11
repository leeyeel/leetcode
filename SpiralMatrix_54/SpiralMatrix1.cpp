#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> >& matrix) {
            vector<int>v;
            if(matrix.empty()) return v;
            int m = matrix.size();
            int n = matrix.at(0).size();
            int biginX=0,endX=n-1,beginY=0,EndY=m-1;
            while(true){
                for(int i=biginX;i<=endX;++i){
                    v.push_back(matrix[beginY][i]);
                }
                if(++beginY>EndY) break;

                for(int j=beginY;j<=EndY;++j){
                    v.push_back(matrix[j][endX]);
                }
                if(--endX<biginX) break;

                for(int k=endX;k>=biginX;--k){
                    v.push_back(matrix[EndY][k]);
                }
                if(--EndY<beginY) break;

                for(int l=EndY;l>=beginY;--l){
                    v.push_back(matrix[l][biginX]);
                }
                if(++biginX>endX) break;
            }
            return v;
        }
};

int main(){
    int n1;
    int n2;
    std::cout<<" type row and column..\n";
    std::cin>>n1>>n2;
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

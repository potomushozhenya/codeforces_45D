#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

bool comp(std::vector<int> &a,std::vector<int> &b){
    return a[1]<b[1];
}
int main(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> curr(n, std::vector<int>(3));
    for (int i = 0; i < n; ++i) {
        std::cin>>curr[i][0]>>curr[i][1];
        curr[i][2]=i;
    }
    std::sort(curr.begin(),curr.end(), comp);
    std::vector<int> res(n);
    std::unordered_set<int> ind;
    for (int i = 0; i < n; ++i) {
        int left = curr[i][0];
        while(ind.count(left)){
            ++left;
        }
        res[curr[i][2]]=left;
        ind.insert(left);
    }
    for (int i = 0; i < n; ++i) {
        std::cout<<res[i]<<' ';
    }

    return 0;
}
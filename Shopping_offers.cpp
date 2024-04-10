Leetcode:https://leetcode.com/problems/shopping-offers/
//ABHAY SHARMA
class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int idx,int n)
    {
        //base condition
        if(idx==special.size())
        {
            int cost=0;
            for(int i=0;i<n;i++)
            {
                cost+=needs[i]*price[i];
            }
            return cost;
        }

        bool check=true;
        //Checking if the current offer is in range of needs.
        for(int i=0;i<n;i++)
        {
            if(special[idx][i]>needs[i])
            {
                check=false;
                break;
            }
        }

        if(check)
        {
            //if check is TRUE then subtrcating from needs.
            for(int i=0;i<n;i++)
            {
                needs[i]-=special[idx][i];
            }
            //now i will call solve(),but index will be idx only as repetition is allowed,may be we can choose this current offer again in future.
            int val1=special[idx][n]+solve(price,special,needs,idx,n);

            //backtracking:if we will not take this current offer..
            for(int i=0;i<n;i++)
            {
                needs[i]+=special[idx][i];
            }
            int val2=solve(price,special,needs,idx+1,n);
            return min(val1,val2);
        }
        //if check is false then we are having only one choice to move further i.e idx+1
        return solve(price,special,needs,idx+1,n);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=needs.size();

        return solve(price,special,needs,0,n);
    }
};

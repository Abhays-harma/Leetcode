Leetcode:https://leetcode.com/problems/reveal-cards-in-increasing-order/
//ABHAY SHARMA
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        //we have to reverse the order from sortes to required
            /*steps:
            1.take the last element from dequeue and put it in front.
            2.take the last element from the sorted array and put in the front of dequeue.
        */

        sort(deck.begin(),deck.end());

        deque<int> q;

        while(deck.size()>0)
        {
            if(!q.empty())
            {
                int last=q.back();
                q.pop_back();
                q.push_front(last);
            }
            int len=deck.size();
            int end=deck[len-1];
            deck.pop_back();
            q.push_front(end);
        }
        vector<int> ans;

        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;


    }
};

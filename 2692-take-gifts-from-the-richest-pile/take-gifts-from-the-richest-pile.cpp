class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;

        for(int &x:gifts){
            pq.push(x);
        }

        for(int i=0;i<k;i++){
            int num=pq.top();
            pq.pop();
            num=sqrt(num);
            pq.push(num);
        }
        long long cnt=0;
        while(!pq.empty()){
            cnt+=pq.top();
            pq.pop();
        }

        return cnt;
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> gfr; 
        priority_queue<int, vector<int>, greater<int>> fr;
        unordered_map<int, int> meetCount;

        int room = 0;
        while(room<n){
            fr.push(room++);
        }
        
        sort(meetings.begin(), meetings.end());
        long long int size = meetings.size();
        long long int diff = 0;

        for(int i=0; i<size; i++)
        {
            long long int start = meetings[i][0];
            long long int end = meetings[i][1];

            while(!gfr.empty() && start>=(long long)gfr.top().first){
                int fRoom = gfr.top().second;
                gfr.pop();
                fr.push(fRoom);
            }

            if(fr.empty()){
                i--;
                diff = (long long)(gfr.top().first-start);
                fr.push(gfr.top().second);
                gfr.pop();
            }
            else{
                int freeRoom = fr.top();
                fr.pop();
                gfr.push({end+diff, freeRoom});
                diff = 0;
                meetCount[freeRoom]++;
            }
        }

        int ans = INT_MAX, meets = -1;
        for(auto it : meetCount){
            if(it.second==meets) {
                ans = min(ans, it.first);
            }
            else if(it.second>meets) {
                ans = it.first;
                meets = it.second;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        typedef pair<int,int> P;
        int n = arr.size();
        unordered_map<int,int> mp;
        // Comparator: larger freq first, smaller num if tie
        auto cmp = [&](P p1,P p2){
            if(p1.first == p2.first) return p1.second < p2.second;// smaller number if freq same
            return p1.first > p2.first;// larger frequency first
        };
        set<P, decltype(cmp)>s(cmp);
        // Build initial frequency map
        for(int i=0; i<k; i++){
            mp[arr[i]]++;
        }
        // Insert all frequencies into set
        for(auto &it: mp)s.insert({it.second, it.first});

        int sum = (*s.begin()).second; // max freq element in first window
        int i = 0, j = k;
        while(j < n){
            int out = arr[i]; // element leaving the window
            int in = arr[j];  // element entering the window
            // Remove old freq of outgoing element
            s.erase({mp[out], out}); // remove old frequency from set
            mp[out]--;                // decrease frequency in map
            if(mp[out]>0)s.insert({mp[out], out}); // re-insert with new freq if > 0

            // Remove old freq of incoming element
            if(mp[in] > 0)s.erase({mp[in], in}); // remove old frequency if it exists
            mp[in]++;                  // increment frequency in map
            s.insert({mp[in], in});    // insert new frequency
            // Add max freq element to sum
            sum += (*s.begin()).second;
            i++;
            j++;
        }
        return sum;
    }
};
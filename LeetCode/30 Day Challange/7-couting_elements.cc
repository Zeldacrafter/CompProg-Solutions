class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> set;
        for(int i : arr)
            set.insert(i);
        int res = 0;
        for(int i : arr)
            if(set.count(i + 1))
                res++;
        return res;
    }
};

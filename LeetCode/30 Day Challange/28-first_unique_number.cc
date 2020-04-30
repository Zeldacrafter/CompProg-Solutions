class FirstUnique {
    map<int, int> freq;
    queue<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        for(int n : nums)
            add(n);
    }
    
    int showFirstUnique() {
        if(q.empty())
            return -1;
        return q.front();        
    }
    
    void add(int value) {
        freq[value]++;
        q.push(value);
        while(!q.empty() && freq[q.front()] > 1)
            q.pop();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

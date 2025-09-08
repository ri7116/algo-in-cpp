class KthLargest {
public:
    int k;
    priority_queue <int, vector<int>, greater<int>> pq;// 1 2 3 4 5 6 7 8 9 10
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(auto aa : nums) pq.push(aa);
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k) { //if 4면 7 8 9 10만 남음
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

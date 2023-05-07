class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    // First traversal
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(!s.empty() && curr >= s.top()){
            s.pop();
        }

        if(!s.empty()){
            ans[i] = s.top();
        } else {
            ans[i] = -1;
        }
        s.push(curr);
    }

    // Second traversal (circular)
    for(int i=n-1;i>=0;i--){
        int curr=arr[i % n]; // Circular index
        while(!s.empty() && curr >= s.top()){
            s.pop();
        }

        if(!s.empty()){
            if(ans[i % n] == -1){ // If ans[i] is not set, set it to the next greater element
                ans[i % n] = s.top();
            }
        } else {
            if(ans[i % n] == -1){ // If ans[i] is not set, set it to -1
                ans[i % n] = -1;
            }
        }
        s.push(curr);
    }

    return ans;


    }
};
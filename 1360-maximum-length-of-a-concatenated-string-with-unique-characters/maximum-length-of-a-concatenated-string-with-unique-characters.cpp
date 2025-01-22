class Solution {
public:
    int n;
    bool hasDuplicate(int i,string &temp,string&arr){
        int m=arr.size();
        vector<int>freq(26,0);
        for(char ch:arr){
            if(freq[ch-'a']>0) return true;
            freq[ch-'a']++;
        }

        for(char ch:temp){
            if(freq[ch-'a']>0) return true;
        }

        return false;
    }

    int solve(int i,string temp,vector<string>& arr){
        if(i>=n){
            return temp.length();
        }

        int include=0,exclude=0;

        if(hasDuplicate(i,temp,arr[i])){ //exclude only option
            exclude=solve(i+1,temp,arr);
        }else{
            include = solve(i+1,temp+arr[i],arr);
            exclude = solve(i+1,temp,arr);  
        }

        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        n=arr.size();
        string temp="";
        return solve(0,temp,arr);
    }
};
class Solution {
public:
    bool queryString(string s, int n) {
        for(int num=1;num<=n;num++){
            string bin = bitset<32>(num).to_string();
            bin = bin.substr(bin.find('1'));
            if(bin.size()>s.size()) return false;
            bool found = false;
            for(int i=0;i<=s.size()-bin.size();i++){
                string cmp = s.substr(i,bin.size());
                if(cmp==bin){
                    found=true;
                    break;
                }
            }

            if(!found) return false;
        }

        return true;
    }
};
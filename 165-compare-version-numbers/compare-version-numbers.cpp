class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() && j<version2.size()){
            string v1="",v2="";
            while(i<version1.size() && version1[i]!='.'){
                v1+=version1[i];
                i++;
            }
            i++;
            while(j<version2.size() && version2[j]!='.'){
                v2+=version2[j];
                j++;
            }
            j++;
            int v1_= v1==""?0:stoi(v1), v2_=v2==""?0:stoi(v2);
            if(v1_>v2_) return 1;
            if(v2_>v1_) return -1;
        }

        while(i<version1.size()){
            string v1="";
            while(i<version1.size() && version1[i]!='.'){
                v1+=version1[i];
                i++;
            }
            i++;
            int v1_= v1==""?0:stoi(v1);
            int v2=0;
            if(v1_>v2) return 1;
        }

        while(j<version2.size()){
            string v2="";
            while(j<version2.size() && version2[j]!='.'){
                v2+=version2[j];
                j++;
            }
            j++;
            int v2_=v2==""?0:stoi(v2);
            int v1=0;
            if(v2_>v1) return -1;
        }

        return 0;
    }
};
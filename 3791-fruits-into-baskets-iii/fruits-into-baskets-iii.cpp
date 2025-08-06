class Solution {
public: 
    void build(int i,int l,int r, vector<int>& baskets,vector<int>&tree){
        if(l==r){
            tree[i]=baskets[l];
            return;
        }
        int m = l+(r-l)/2;
        build(2*i+1,l,m,baskets,tree);
        build(2*i+2,m+1,r,baskets,tree);
        tree[i] = max(tree[2*i+1],tree[2*i+2]);
    }

    bool query(int i,int l,int r,vector<int>&tree,int fruit){
        if(tree[i]<fruit) return false;
        if(l==r){
            tree[i]=-1;
            return true;
        }

        int mid = l+(r-l)/2;
        bool placed = false;

        if(tree[2*i+1]>=fruit){
            placed = query(2*i+1,l,mid,tree,fruit);
        }else{
            placed = query(2*i+2,mid+1,r,tree,fruit);
        }

        tree[i] = max(tree[2*i+1],tree[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>tree(4*n,-1);
        build(0,0,n-1,baskets,tree);
        int unplaced = 0;
        for(int& fruit:fruits){
            if(!query(0,0,n-1,tree,fruit)){
                unplaced++;
            }
        }

        return unplaced;
    }
};
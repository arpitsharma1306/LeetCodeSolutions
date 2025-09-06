class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>result;
        vector<string>words;
        for(int i=0;i<products.size();i++){
            if(products[i][0]==searchWord[0]){
                words.push_back(products[i]);
            }
        }
        vector<string>output;
        for(int j=0;j<3 && j<words.size();j++){  
            output.push_back(words[j]);
        }
        result.push_back(output);
        output.clear();
        for(int i=1;i<searchWord.size();i++){
            for(int j=0;j<words.size();j++){
                if(i<words[j].size() && searchWord[i]==words[j][i]){
                    output.push_back(words[j]);
                }
            }
            vector<string>insert;
            for(int j=0;j<3 && j<output.size();j++){  
                insert.push_back(output[j]);
            }
            result.push_back(insert);
            words = output;
            output.clear();
        }

        return result;
    }
};
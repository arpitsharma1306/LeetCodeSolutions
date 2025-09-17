class FoodRatings {
public:
    // cuisine -> set of (-rating, food)
    unordered_map<string, set<pair<int,string>>> cuisineMap;

    // food -> (cuisine, rating)
    unordered_map<string, pair<string,int>> foodMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodMap[food] = {cuisine, rating};
            cuisineMap[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodMap[food];

        // remove old entry
        cuisineMap[cuisine].erase({-oldRating, food});

        // insert new entry
        cuisineMap[cuisine].insert({-newRating, food});

        // update in foodMap
        foodMap[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
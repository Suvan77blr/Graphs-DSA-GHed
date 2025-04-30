
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <sstream>
using namespace std;

class Solution {
    public:
        // vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
        void findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies);
  
};

// vector<string> Solution :: findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
void Solution :: findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
{
    int nR = recipes.size(), nS = supplies.size();

    unordered_map<string, bool> mapping;
    for(const string& sup : supplies) {
        mapping[sup] = 1;
    }

    set<string> readyList;

    int n = recipes.size();
    bool allIngrdThere = false;
    bool changedInCurr = true;

    while(changedInCurr)
    {
        changedInCurr = false;
        for(int i=0; i<n; i++)
        {
            // cout << ingredients[i][0] << " : " << mapping[ingredients[i][0]] << endl;
            auto ingrList = ingredients[i];
            allIngrdThere = true;
            for(string& ingrd : ingrList) 
            {
                // cout << ingrd << " : " << mapping[ingrd] << endl;
                if(!mapping[ingrd]) {
                    allIngrdThere = false;
                    break;
                }
            }
            
            if(allIngrdThere){
                mapping[recipes[i]] = 1;
                // ingredients.push_back(recipes[i]);
                changedInCurr = true;
                readyList.insert(recipes[i]);
            }
        }
    }
    // return readyList;
    cout << "\nReady-List : [ ";
    for(const string& str : readyList) {
        cout << str << " ";
    }cout << "]\n";

}

int main(void) {
    vector<string> recipes;
    vector<vector<string>> ingredients;
    vector<string> supplies;

    int nRecipes, nSupplies;    // nRecipes == nIngredients.
    // cout << "\nEnter the Recipes-Ingredients count : ";
    cin >> nRecipes;
    // cout << "\nEnter the Supplies count : ";
    cin >> nSupplies;

    recipes = vector<string>(nRecipes, "");
    ingredients = vector<vector<string>>(nRecipes, vector<string>());
    supplies = vector<string>(nSupplies, "");
    
    // cout << "\nEnter the " << nRecipes << " recipes : ";
    for(int i=0; i<nRecipes; i++) {
        cin >> recipes[i];
    }
    // cout << "\nEnter ingredients for each of the " << nRecipes << " recipes : " ;
    string ingrdList, temp;
    cin.ignore();
    for(int i=0; i<nRecipes; i++) {
        // cin >> ingrdList;
        getline(cin, ingrdList);
        // cout << ingrdList << endl;

        /* VERY IMPT! */
        stringstream ss(ingrdList);

        while(getline(ss, temp, ' ')){
            ingredients[i].push_back(temp);
        }
    }

    // cout << "Enter the " << nSupplies << " supplies : ";
    for(int i=0; i<nSupplies; i++) {
        cin >> supplies[i];
    }
/*
    cout << "Recipe - Ingredients list : ";
    for(int i=0; i<nRecipes; i++) {
        cout << "\n\t\'" << recipes[i] << "\' : [ ";
        for(const string& ingrd : ingredients[i]) {
            cout << ingrd << " ";
        }
        cout << "]";
    }
    cout << "\nSupplies : [ ";
    for(const string& str : supplies) {
        cout << str << " ";
    }cout << "]\n";
// */

    Solution().findAllRecipes(recipes, ingredients, supplies);
    // vector<string> readyRecipes = Solution().findAllRecipes(recipes, ingredients, supplies);
    // cout << "\nReady-Recipes : [ ";
    // for(const string& str : readyRecipes) {
    //     cout << str << " ";
    // }cout << "]\n";
}
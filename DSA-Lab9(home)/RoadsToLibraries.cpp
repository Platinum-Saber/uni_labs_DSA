#include <bits/stdc++.h>
#include <functional> 
#include <iostream>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
 
 int visit(vector<vector<int>> &cityNodes, int &cityIndex, vector<bool> &isVisited){
    int count = 1;
    isVisited[cityIndex] = true;
    for(int i=0; i < (int)cityNodes[cityIndex].size(); i++){
        if(!isVisited[cityNodes[cityIndex][i]]){
            count += visit(cityNodes, cityNodes[cityIndex][i], isVisited);
        }
    }
    return count;
}
 
vector<long> dfs(vector<vector<int>> cityNodes){
    vector<bool> isVisited;
    vector<long> roads;
    for(int i=0; i < (int)cityNodes.size(); i++){
        isVisited.push_back(false);
    }
    for(int i=0; i < (int)cityNodes.size(); i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            roads.push_back(visit(cityNodes, i, isVisited));
        }
    }
    return roads;
}



long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    //build a graph with the connected cities
    vector<vector<int>> cityNodes(n);
    for(int i=0; i< (int)cities.size(); i++){
        cityNodes[cities[i][0]-1].push_back(cities[i][1]-1);
        cityNodes[cities[i][1]-1].push_back(cities[i][0]-1);
    }
    //collect the depths of the cities
    vector<long> roads = dfs(cityNodes);
    //find the cost
    long cost = 0;
    for(int i=0; i < (int)roads.size(); i++){
        cost += min((roads[i]-1)*c_road + c_lib, roads[i]*c_lib);
    }
    return cost;
}


int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not_fn<int(int)>(isspace))
    );

    return s;
}

// Include the <functional> header for not_fn

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not_fn<int(int)>(isspace)).base(), 
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

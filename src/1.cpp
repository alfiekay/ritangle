#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> cord;

map<int, int> axisX = {
    {0, 17},
    {1, 19},
    {2, 23},
    {3, 29},
    {4, 31},
    {5, 37}
};
map<int, int> axisY = {
    {0, 2},
    {1, 3},
    {2, 5},
    {3, 7},
    {4, 11},
    {5, 13}
};

vector<cord> startingPoints = {
    {0, 3},
    {2, 1},
    {4, 0}
};

float findDistance(cord p1, cord p2) {
    float distance = hypot(
        static_cast<float>(p1.first - p2.first),
        static_cast<float>(p1.second - p2.second)
    );
    return distance;
}

float findValue(cord p) {
    return axisX[p.first] * axisY[p.second];
}

void findNewPoint(vector<vector<cord>>& oldCombinations, vector<vector<cord>>& combinations) {
    combinations.clear();
    for (const auto& oldCombi : oldCombinations) {
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= 5; j++) {
                cord newCord = {i, j};
                if (find(oldCombi.begin(), oldCombi.end(), newCord) != oldCombi.end()) continue;
                // do this for every point not in starting points

                vector<cord> newCombi(oldCombi.begin(), oldCombi.end());
                newCombi.push_back(newCord);
                set<float> distances;
                bool valid = true;
                for (int k = 0; k < newCombi.size(); k++) {
                    for (int l = k + 1; l < newCombi.size(); l++) {
                        float distance = findDistance(newCombi[k], newCombi[l]);
                        if (distances.find(distance) == distances.end()) {
                            distances.insert(distance);
                        } else {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }
                if (valid) {
                    combinations.push_back(newCombi);
                }
            }
        }
    }
}

int main() {
    vector<vector<cord>> combinations1;
    combinations1.push_back(startingPoints);
    vector<vector<cord>> combinations2;

    findNewPoint(combinations1, combinations2);
    findNewPoint(combinations2, combinations1);
    findNewPoint(combinations1, combinations2);

    cout << "first solution: ";
    for (auto point : combinations2[0]) {
        cout << "(" << axisX[point.first] << ", " << axisY[point.second] << ") ";
    }
    cout << '\n';
    cout << "Number of combinations: " << combinations2.size() << '\n';

    set<int> sums;
    for (const auto& combi : combinations2) {
        int sum = findValue(combi[3]) + findValue(combi[4]) + findValue(combi[5]);
        sums.insert(sum);
    }
    for (auto sum : sums) {
        cout << "sum of values: " << sum << '\n';
    }

    return 0;
}
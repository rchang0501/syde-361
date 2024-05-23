#include "./bits/stdc++.h"

struct Solution {
    int e;
    int c;
    vector<int> items;

    Solution(int n) {
        e = 0;
        c = 0;
        items = vector<int>(n, -1);
    }
};

const auto cmp = [](const Solution& a, const Solution& b) {
    return a.e < b.e;
};

void combinations(int i, Solution curr, priority_queue<Solution, vector<Solution>, decltype(cmp)>& pq, vector<vector<pair<int, int>>>& input) {
    // out of bounds
    if(i >= input.size()) {
        pq.push(curr);
        return;
    }

    for(int j = 0 ; j < input[i].size() ; j++) {
        pair<int,int> option = input[i][j];
        Solution next = curr;
        next.e += option.first;
        next.c += option.second;
        next.items[i] = j;

        combinations(i + 1, next, pq, input);
    }
}

int main() {
    vector<pair<int, int>> pump_water = {{10, 0}};
    vector<pair<int, int>> change_dir_of_water = {{8, 5}, {6, 10}, {7, 15}, {6, 10}};
    vector<pair<int, int>> change_flow_rate = {{9, 10}, {7, 5}, {8, 12}, {8, 20}};
    vector<pair<int, int>> spin_turbine = {{7, 20}, {9, 25}, {6, 15}, {8, 10}};
    vector<pair<int, int>> discharge_water = {{8, 5}, {7, 15}, {6, 10}, {9, 5}};
    vector<pair<int, int>> motor = {{10, 0}};
    vector<pair<int, int>> ac_to_dc = {{9, 5}, {7, 2}, {8, 10}, {10, 20}};
    vector<pair<int, int>> store_electricity = {{7, 15}, {9, 25}, {10, 25}, {8, 20}};
    vector<pair<int, int>> usb = {{10, 0}};

    vector<vector<pair<int, int>>> input;
    input.push_back(pump_water);
    input.push_back(change_dir_of_water);
    input.push_back(change_flow_rate);
    input.push_back(spin_turbine);
    input.push_back(discharge_water);
    input.push_back(motor);
    input.push_back(ac_to_dc);
    input.push_back(store_electricity);
    input.push_back(usb);

    priority_queue<Solution, vector<Solution>, decltype(cmp)> pq(cmp);

    Solution curr = Solution(input.size());
    combinations(0, curr, pq, input);

    for(int i = 0 ; i < 5 ; i++) {
        Solution curr = pq.top(); pq.pop();
        cout << curr.e << ", " << curr.c << ", [";
        for(int j: curr.items) cout << j << ",";
        cout << "]\n";
    }


    return 0;
}

/*
- water pump
- pvc elbow
- ball valve
- hydro turbine generator
- gravity fed
- motor
- dc adapter
- lithium ion
- usb
*/
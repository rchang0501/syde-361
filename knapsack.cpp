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
    vector<pair<int, int>> spin_turbine = {{10, 15}};
    vector<pair<int, int>> discharge_water = {{8, 5}, {7, 15}, {6, 10}, {9, 5}};
    vector<pair<int, int>> motor = {{10, 0}};
    vector<pair<int, int>> ac_to_dc = {{10, 0}};
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

    string dict[9][4] = {
        {"water pump", "", "", ""},
        {"PVC elbow joint", "Adjustable hose nozzle", "Flexible hose", "Rubber tubing with clamps"},
        {"Ball valve", "Adjustable clamp", "Flow restrictor", "Inline water flow regulator"},
        {"3D printed turbine", "", "", ""},
        {"PVC pipe outlet", "Flexible discharge hose", "Drainage spout", "Gravity-fed return system"},
        {"motor", "", "", ""},
        {"full wave rectifier", "", "", ""},
        {"Rechargeable AA batteries", "Supercapacitor", "Lithium-ion battery", "18650 battery"},
        {"USB", "", "", ""}
    };

    priority_queue<Solution, vector<Solution>, decltype(cmp)> pq(cmp);

    Solution curr = Solution(input.size());
    combinations(0, curr, pq, input);

    for(int i = 0 ; i < 10 ; i++) {
        Solution curr = pq.top(); pq.pop();
        cout << curr.e << ", " << curr.c << ", [";
        for(int r = 0 ; r < curr.items.size() ; r++) {
            int c = curr.items[r];
            cout << dict[r][c] << ", "; 
        }
        cout << "]\n\n";
    }

    return 0;
}

/*
86, 60, [water pump, PVC elbow joint, Ball valve, 3D printed turbine, Gravity-fed return system, motor, full wave rectifier, Lithium-ion battery, USB, ]
*/
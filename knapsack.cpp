#include "./bits/stdc++.h"

int main() {
    vector<pair<int,int>> pump_water = {{10, 0}};
    vector<pair<int,int>> change_dir_of_water = {{8, 5}, {6, 10}, {7, 15}, {6, 10}};
    vector<pair<int,int>> change_flow_rate = {{9, 10}, {7, 5}, {8, 12}, {8, 20}};
    vector<pair<int,int>> spin_turbine = {{7, 20}, {9, 25}, {6, 15}, {8, 10}};
    vector<pair<int,int>> discharge_water = {{8, 5}, {7, 15}, {6, 10}, {9, 5}};
    vector<pair<int,int>> motor = {{10, 0}};
    vector<pair<int,int>> ac_to_dc = {{9, 5}, {7, 2}, {8, 10}, {10, 20}};
    vector<pair<int,int>> store_electricity = {{7, 15}, {9, 25}, {10, 25}, {8, 20}};
    vector<pair<int,int>> usb = {{10, 0}};

    vector<vector<pair<int,int>>> input;
    input.push_back(pump_water);
    input.push_back(change_dir_of_water);
    input.push_back(change_flow_rate);
    input.push_back(spin_turbine);
    input.push_back(discharge_water);
    input.push_back(motor);
    input.push_back(ac_to_dc);
    input.push_back(store_electricity);
    input.push_back(usb);

    cout << "hi" << endl;
    return 0;
}
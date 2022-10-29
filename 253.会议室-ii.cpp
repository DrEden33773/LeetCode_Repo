/**
 * @file 253.会议室-ii.cpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-24
 *
 * @copyright Copyright (c) 2022
 *
 */

// in_out vehicle problem

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // [ [in, out], [in, out], [in, out] ]
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // <time_point, NumOf_In_or_Out>
        map<int, int> in_out_map;

        for (auto&& sub_vec : intervals) {
            // in
            ++in_out_map[sub_vec[0]];
            // out
            --in_out_map[sub_vec[1]];
        }

        int curr_num_of_vehicle    = 0;
        int history_num_of_vehicle = 0;

        // map must be non-descending ordered by `time_point`

        for (auto&& info : in_out_map) {
            curr_num_of_vehicle += info.second;
            history_num_of_vehicle
                = max(history_num_of_vehicle, curr_num_of_vehicle);
        }

        return history_num_of_vehicle;
    }
};
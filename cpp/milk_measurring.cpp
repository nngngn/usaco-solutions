

// http://www.usaco.org/index.php?page=viewproblem2&cpid=918

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Milking {
    int start_time;
    int end_time;
    int milk_produced;
};

bool compare_milkings(const Milking& a, const Milking& b) {
    return a.start_time < b.start_time;
}

struct Measurement {
    int time;
    int index;
};

bool compare_measurements(const Measurement& a, const Measurement& b) {
    return a.time < b.time;
}

int main() {
    int n, m;
    cin >> n >> m;

    // read in the milkings
    vector<Milking> milkings(n);
    for (int i = 0; i < n; i++) {
        cin >> milkings[i].start_time >> milkings[i].end_time >> milkings[i].milk_produced;
    }
    sort(milkings.begin(), milkings.end(), compare_milkings);

    // read in the measurement times
    vector<Measurement> measurements(m);
    for (int i = 0; i < m; i++) {
        cin >> measurements[i].time;
        measurements[i].index = i;
    }
    sort(measurements.begin(), measurements.end(), compare_measurements);

    // determine the milk output for each interval
    priority_queue<int> q;
    vector<int> output(m);
    int milk = 0;
    int j = 0;
    for (int i = 0; i < m; i++) {
        int start_time = measurements[i].time;
        int end_time = i == m-1 ? 1000000000 : measurements[i+1].time;
        while (j < n && milkings[j].start_time < end_time) {
            if (milkings[j].end_time > start_time) {
                q.push(milkings[j].milk_produced);
                milk += milkings[j].milk_produced;
            }
            j++;
        }
        while (!q.empty() && milkings[j-1].end_time <= start_time) {
            milk -= q.top();
            q.pop();
        }
        output[measurements[i].index] = milk;
    }

    // output the minimum output for each interval
    int min_output = 1000000000;
    for (


// You are using GCC
#include <bits/stdc++.h>
using namespace std;
struct Activity {
    int start, end, fun;
};
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}
int maxFunScore(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);
    int n = activities.size();
    int totalFun = 0;
    int lastEndTime = -1;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEndTime) {
            totalFun += activities[i].fun;
            lastEndTime = activities[i].end;
        }
    }
    return totalFun;
}
int main() {
    int n;
    cin >> n;
    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end >> activities[i].fun;
    }
    int result = maxFunScore(activities);
    cout << result << endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    cout << fixed << setprecision(4);
    double proportion = 0;

    const double INTERVAL = 0.0000001;

    for (double t = -1.000; t <= 1.000; t += INTERVAL) {
        double A = (t*t) - 1.0;
        double B = (t*t*t);
        double C = t*(t-1);
        double D = t*(t+1);

        vector<double> nums = {A, B, C, D};
        for (auto& num : nums) {
            num = abs(num);
        }

        sort(nums.begin(), nums.end());

        if (nums[1] == abs(C)) {
            cout << t << '\n';
            proportion += INTERVAL;
        }
    }

    proportion /= 2;
    cout << setprecision(5);
    cout << "proportion: " << proportion << '\n';
    return 0;
}
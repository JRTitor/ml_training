#include <iostream>
#include <iomanip>
#include <algorithm>


using namespace std;

int main() {
    int N;
    cin >> N;
    pair<double, double> y[N];
    for (size_t i = 0; i < N; ++i) {
        cin >> y[i].first >> y[i].second;
    }

    sort(y, y + N);
    double roc_auc = 0.0, pairs = 0;

    for (int i = N-1;  i > 0; --i) {
        for (int j = i-1; j >= 0; --j) {
            if (y[i].first > y[j].first) {
                pairs++;
                roc_auc += double(y[i].second == y[j].second) / 2 + double(y[i].second > y[j].second);
            }
        }
    }
    cout << fixed << setprecision(6) << roc_auc / pairs;
}

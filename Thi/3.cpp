#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxHistogram(vector<int>& height) {
    stack<int> st;
    int max_area = 0;
    int width = 0, height_max = 0;

    height.push_back(0);
    int n = height.size();

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && height[i] < height[st.top()]) {
            int h = height[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            int area = h * w;

            if (area > max_area || (area == max_area && abs(h - w) < abs(height_max - width))) {
                max_area = area;
                width = min(h, w);
                height_max = max(h, w);
            }
        }
        st.push(i);
    }
    height.pop_back();
    return {width, height_max};
}

void solveTest() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matrix[i][j];

    vector<int> height(M, 0);
    int max_area = 0;
    pair<int, int> best = {0, 0};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            height[j] = (matrix[i][j] == 0) ? 0 : height[j] + 1;

        pair<int, int> rect = maxHistogram(height);
        int w = rect.first;
        int h = rect.second;
        int area = w * h;

        if (area > max_area || (area == max_area && abs(h - w) < abs(best.second - best.first))) {
            max_area = area;
            best = make_pair(w, h);
        }
    }
    cout << best.first << " " << best.second << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) {
        solveTest();
    }

    return 0;
}

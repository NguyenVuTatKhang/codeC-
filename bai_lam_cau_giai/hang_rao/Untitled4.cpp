#include<bits/stdc++.h>

using namespace std;

int n, m;
int XX, YY;
struct fen{
	int x1, x2, y1, y2;
};
struct cow{
	int x,y;
};
fen M[10000];
cow N[10000];
char C[2000][2000];
bool check[2000][2000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(){
	memset(check, false, sizeof(check));
	set<int> S;
	map<int, int> X;
	for (int i = 0; i < n; i++){
		S.insert(M[i].x1), S.insert(M[i].x2);
	}
	for (int i = 0; i < m; i++){
		S.insert(N[i].x);
	}
	int i = 2;
	for (auto s : S){
		X[s] = i, i += 2;
	}
	XX = i + 10;
	for (int i = 0; i < n; i++){
		M[i].x1 = X[M[i].x1], M[i].x2 = X[M[i].x2];
	}
	for (int i = 0; i < m; i++){
		N[i].x = X[N[i].x];
	}
	S.clear();
	X.clear();
	for (int i = 0; i < n; i++){
		S.insert(M[i].y1), S.insert(M[i].y2);
	}
	for (int i = 0; i < m; i++){
		S.insert(N[i].y);
	}
	i = 2;
	for (auto s : S){
		X[s] = i, i += 2;
	}
	YY = i + 10;
	for (int i = 0; i < n; i++){
		M[i].y1 = X[M[i].y1], M[i].y2 = X[M[i].y2];
	}
	for (int i = 0; i < m; i++){
		N[i].y = X[N[i].y];
	}
	for (int i = 0; i < XX; i++){
		for (int j = 0; j < YY; j++){
			C[i][j] = '.';
		}
	}
	for (int i = 0; i < m; i++){
		C[N[i].x][N[i].y] = '0';
	}
	for (int i = 0; i < n; i++){
		fen x = M[i];
		for (int l = x.x1; l < x.x2 + 1; l++){
			for (int k = x.y1; k < x.y2 + 1; k++){
				C[l][k] = 'X';
			}
		}
	}
}
void DFS(cow u){
	check[u.x][u.y] = true;
	for (int i = 0; i < 4; i++){
		int x = u.x + dx[i];
		int y = u.y + dy[i];
		if (0 < x && x < XX - 1 && 0 < y && y < YY - 1 && C[x][y] != 'X' && !check[x][y]){
			DFS({ x,y });
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> M[i].x1 >> M[i].y1 >> M[i].x2 >> M[i].y2;
			if (M[i].x1 > M[i].x2){
				swap(M[i].x1, M[i].x2);
			}
			if (M[i].y1 > M[i].y2){
				swap(M[i].y1, M[i].y2);
			}
		}
		for (int i = 0; i < m; i++){
			cin >> N[i].x >> N[i].y;
		}
		init();
		int res = 0;
		int tmp = 0;
		for (int i = 0; i < m; i++){
			if (!check[N[i].x][N[i].y]){
				DFS(N[i]);
				int count = 0;
				for (int j = 0; j < m; j++){
					if (check[N[j].x][N[j].y]){
						count++;
					}
				}
				res = max(res, count - tmp);
				tmp = count;
			}
		}
		cout << res << "\n";
	}
}

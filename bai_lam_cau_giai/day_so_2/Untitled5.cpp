#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int m = 0, l;
		for (int i = n; i > 0; i--){
			m = m + i;
		}
		l = m;
		vector <int> a(n), b(n), c(m);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		c[m] = a[0];
		m--;
		for (int i = 0; i < n; i++){
			c[m] = a[0];
			m--;
			for (int j = 1; j < n - i; j++){
				c[m] = a[j];
				m--;
				b[j - 1] = a[j - 1] + a[j];
			}
			for (int j = 0; j < n - i; j++){
				a[j] = b[j];
			}

		}
		int total = c.size();
	    int index = 0;
	    int take = 1;
	
	    while (index + take <= total) {
	        cout << "[";
	        for (int i = take - 1; i >= 0; --i) {
	            cout << c[index + i];
	            if (i > 0) cout << " ";
	        }
	        cout << "]" << " ";
	
	        index += take;
	        take++;
	    }
	}
} 

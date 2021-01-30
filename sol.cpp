#include <bits/stdc++.h> 	

using namespace std;
    
int main() {                          	
	ios::sync_with_stdio(false);
	cin.tie(0);          
	int tt;
	cin >> tt;
	while (tt--) {                                                
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int solved_problems = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// count the number of problems solved
			if (a[i] != -1) {                                                           
				solved_problems++;
			}
		}            
		// check if the numbers of problem solved is greater than or equal to ceil(n / 2)
		if (solved_problems < ceil((double) n / 2)) {
			cout << "Rejected\n";
			continue;
		}
		// check if the all the time is STRICTLY less than 'k'
		bool too_slow = false;
		for (int i = 0; i < n; i++) {
			if (a[i] > k) {
				too_slow = true;
				break;
			}
		}
		if (too_slow) {
			cout << "Too Slow\n";
			continue;
		}
		// check the possibility that the bot answered the problems 
		bool bot = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > 1 || a[i] == -1) {
				bot = false;
				break;
			}
		}
		if (bot) {
			cout << "Bot\n";
			continue;
		}
		// print "Accepted" if it passes all the conditions
		cout << "Accepted\n";
	}
	return 0;
}
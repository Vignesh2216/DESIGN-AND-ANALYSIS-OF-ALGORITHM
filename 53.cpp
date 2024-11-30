// You are using GCC
#include <bits/stdc++.h>
using namespace std;
void minSpacePreferLarge(int wall, int m, int n)
{
	int num_m = 0, num_n = 0, min_empty = wall;
	int p = wall/m, q = 0, rem=wall%m;
	num_m=p;
	num_n=q;
	min_empty=rem;
	while (wall >= n) {
		q += 1;
		wall = wall - n;
		p = wall / m;
		rem = wall % m;
		if (rem <= min_empty) {
			num_m = p;
			num_n = q;
			min_empty = rem;
		}
	}
	cout<<num_m<<" "<<num_n<<" "<<min_empty ;
}
int main()
{
	int w, m, n ;
	cin >> w >> m >> n ;
	minSpacePreferLarge(w, m, n) ;
	return 0;
}

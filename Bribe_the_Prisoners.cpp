#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int Qnum[100 + 10];
int dp[100 + 10][100 + 10];


int main(){

	int t;
	int p,q;
	scanf("%d",&t);
	for(int ics = 1; ics <=t ; ics ++){
		scanf("%d%d",&p,&q);
		for(int i = 0;i < q; i ++){
			scanf("%d",&Qnum[i + 1]);
		}
		Qnum[0] = 0;
		Qnum[q + 1] = p + 1;
		
		for(int i = 0;i < q + 2; i ++){
			dp[i][i] = 0;
			if(i + 1 < q + 2)
				dp[i][i + 1] = 0;
		}

		sort(Qnum,Qnum + q + 2);


		for(int l = 2;l <= q + 1; l ++){
			for(int i = 0;i  + l < q + 2; i ++){
				int t = INT_MAX;
				for(int k = i + 1; k < i + l; k ++){
					t = min(t,dp[i][k] + dp[k][i + l]);				
				}

				dp[i][i + l] = Qnum[i + l] - Qnum[i] - 2 + t;
			}
		}
		printf("Case #%d: %d\n",ics,dp[0][q + 1]);
	}
}

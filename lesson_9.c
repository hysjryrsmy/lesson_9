#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//判断素数
//int is_prime(int n){
//	for (int i = 2, I = sqrt(n); i <= I; i++) {
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main() {
//	int n;
//	while (~scanf("%d", &n)) {
//		printf("%s\n", is_prime(n) ? "Yes" : "No");
//	}
//	return 0;
//}


//用素数筛的方法判断素数
/*
#define MAX_N 100

int prime[MAX_N + 5] = { 0 };

void init() {
	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i])  continue;
		prime[++prime[0]] = i;   // 等价于int cnt = 0; cnt += 1;
		//for (int j = 2 * i; j <= MAX_N; j += i) {
			//prime[j] = 1;
		//}
		for (int j = i; j <= MAX_N / i; j++) {
			prime[j * i] = 1;        
		}

	}
	return ;
}

int main() {
	init();
	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i]) continue;
		printf("%d\n", i);
	}
	return 0;
}
*/


//最小素因子
#define MAX_N 100
int prime[MAX_N + 5];


void init() {
	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i])  continue;
		for (int j = i; j <= MAX_N; j += i) {
			if (prime[j])  continue;
			prime[j] = i;
		}
	}
	return;
}

int main() {
	init();
	for (int i = 2; i <= MAX_N; i++) {
		printf("min_fac[%d] = %d\n", i, prime[i]);
	}
	return 0;
}
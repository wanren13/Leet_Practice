#pragma once
namespace fibonacci {
	long long fib(int n) {
		long long num1 = 0;
		long long num2 = 1;
		if (n == 0) {
			return num1;
		}
		if (n == 1) {
			return num2;
		}

		long long num3;

		for (int i = 2; i <= n; i++) {
			num3 = num1 + num2;
			num1 = num2;
			num2 = num3;
		}
		return num3;
	}

	int fibRec(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
			return fibRec(n - 1) + fibRec(n - 2);
	}
}
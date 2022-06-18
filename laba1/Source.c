#define E 0.0000001
#define pi 3.14159265

double Pow(double x, int power)
{
	double result;
	int i;
	result = 1.0;
	for (i = 1; i <= power; i++)
	{
		result = result * x;
	}
	return(result);
}
long fact (long x) {
	if (x <= 1) return 1;
	else return x * fact(x - 1);
}
double bink(long n, long k) {
	return 1. * fact(n) / fact(k) / fact(n - k);
}
double bernoulli(long n) {
	if (n <= 0) return 1;
	else {
		double s = 0, l = - 1;
		for (long k = 1; k <= n; k++) {
			s += bink(n + 1, k + 1) * bernoulli(n - k);
		}
			return l / (n + 1) * s;
	}
}
double tg(double a) {
	double itog = 0; 
	for (int n = 1; n < 7; n++) {
		itog = itog + (((bernoulli(2 * n) * Pow(-4, n) * (1 - Pow(4, n))) / fact(2 * n)) * Pow(a, 2 * n - 1));
	}
	return itog;
}
int test_sqrt() {
	int a, b, c, d;

	a = fact(tg(pi/3) - 1.73205) <= E;
	b = fact(tg(pi/4) - 1.0) <= E;
	c = fact(tg(pi/8) - 0.414214) <= E;
	d = fact(tg(pi/7) - 0.198912) <= E;
	if (a & b & c & d) {
		return 0;
	}
}

int main() {
	return(test_sqrt());
}
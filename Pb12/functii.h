float power1(float x, unsigned n)
{
	float prod = 1;
	for (unsigned i = 1; i <= n; ++i)
		prod *= x;
	return prod;
}

float power2(float x, unsigned n)
{
	if (!n)
		return 1;
	if (n == 1)
		return x;
	return power2(x, n - 1) * x; // return x * power2(x, n - 1);
}

float divideEtImpera(float x, unsigned left, unsigned right)
{
	if (left == right) // stop condition
		return x; // solution of trivial problem (x ^ 1 == x)

	// Divide (Impera)
	unsigned mid = left + ((right - left) >> 1); // unsigned mid = (left + right) / 2;
												 // unsigned mid = (left + right) >> 1;

	// Conquer
	float power_left, power_right;
	power_left = divideEtImpera(x, left, mid);
	power_right = divideEtImpera(x, mid + 1, right);

	// Combine
	return power_left * power_right;
}

float power3(float x, unsigned n)
{
	/*
	if (!n)
		return 1;
	return divideEtImpera(x, 1, n);
	*/

	return !n ? 1 : divideEtImpera(x, 1, n);
}

float power4(float x, unsigned n)
{
	if (n <= 1) // stop condition
		return !n ? 1 : x; // trivial problem
	unsigned mid = n / 2; // divide
	float p = power4(x, n / 2); // conquer (impera)
	if (!(n % 2))
		return p * p; // combine
	return x * p * p; // combine
}

float generic_power(float x, unsigned n, float (*f)(float, unsigned))
{
	return f(x, n);
}
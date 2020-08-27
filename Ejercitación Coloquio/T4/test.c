long fun(const int * v,
	unsigned long l, // Lo primero que se me viene a la cabeza
	unsigned long r, // con estos valores son left y right
	int t) {
	long p = (l+r)/2;

	int m = v[p]; // Seguramente sea m de middle
	if (m == t)
		return p; //L8 - Además vemos que devuelve p y no m por la firma de la función.
	if (t < m)
		r = p;
	else
		l = p;
	if (l == r) 
		return -1; // L5
	return fun(v, l, r, t); // L3 - Recursividad! => Será algún tipo de búsqueda u ordenamiento probablemente.
}

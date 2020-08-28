int fun1(int a, int b){
	if (a < b)
		return a;
	else
		return b;
}
int fun2(int a, int b){
	if (b < a)
		return b;
	else
		return a;
}
int fun3(int a, int b){
	unsigned ua = (unsigned) a;
	if (ua < b)
		return b;
	else
		return ua;
}

// La respuesta correcta probablemente es fun2. Esto se ve haciendo el seguimiento para a = -1 y b = -2

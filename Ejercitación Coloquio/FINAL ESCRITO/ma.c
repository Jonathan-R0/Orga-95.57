extern unsigned long casos_diarios[512];

// La llamada inicial para el ejercicio de caché es: ma(casos_diarios,512,8);

/*
 Sabiendo que cada bloque de la caché puede guardar 4 longs, ocurrirá que se producirá un miss de lectura en cada primera lectura 
 del ciclo interno y para cuando estemos en la parte de la escritura, el último long cacheado será el que tenemos que escribir. 
 Miss rate de lectura = 25% (2 de cada 8).
 Miss rate de escrituras = 0%.
*/

unsigned long ma(unsigned long *v, unsigned long i, unsigned long n){
    unsigned long i,j;
    for(i=n-1;i<j;i++){
        unsigned long s = 0;
        for(j=0;j<n;j++)
            s += v[i-j]; // Acumulo la cantidad de infectados semanales.
        s /= n; // Calculo el promedio de infectados semanal.
        v[i-j] = s; // Así está en la consigna original, pero como genera segmentation faults se debería reemplazar por v[i-j+1] 
    }
    return l - n;
}
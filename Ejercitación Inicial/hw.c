#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// Precondición: n es un número positivo mayor o igual a 0 y menor a 4.
uint32_t reemplazar_byte (uint32_t t, int n, uint8_t b)
{
    uint32_t mask = (uint32_t)b << (n << 3); 
    uint32_t nullmask = ~((uint32_t)0xff << (n << 3)); 
    
    t = t & nullmask; //Anulamos los bits correspondientes al byte que queremos cambiar
    t = t | mask; //Este or bit a bit nos permite dejar todos los bits 1 como estaban, y el espacio vacío con el byte b.
  
    return t;
}

uint32_t leftmost_one (uint32_t dword)
{
    dword |= (dword >>  1);
    dword |= (dword >>  2); // Completo todos los bits a la derecha
    dword |= (dword >>  4); // del primer bit uno (desde la izquierda)
    dword |= (dword >>  8); // con unos.
    dword |= (dword >> 16);

    return (dword + 1) >> 1; 
}


int main()
{
    return 0;
}
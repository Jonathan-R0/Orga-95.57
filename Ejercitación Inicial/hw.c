#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// Precondición: n es un número positivo mayor o igual a 0 y menor a 4.
uint32_t reemplazar_byte (uint32_t t, int n, uint8_t b)
{
    uint32_t mask1 = (uint32_t)b << (n << 3);       // Acomodamos el byte b desplazandolo n*8 bits a la izquierda.
    uint32_t mask2 = ~((uint32_t)0xff << (n << 3)); // Todos los bits, menos el byte correspondiente a b, con unos.
    
    t = t & mask2; // Anulamos los bits correspondientes al byte que queremos cambiar.
    t = t | mask1; // Este or bit a bit nos permite dejar todos los bits 1 como estaban, y el espacio vacío con el byte b.
  
    return t;
}

uint32_t leftmost_one (uint32_t dword)
{
    dword |= (dword >>  1);
    dword |= (dword >>  2);  // Completo todos los bits a la derecha
    dword |= (dword >>  4);  // del primer bit uno (desde la izquierda)
    dword |= (dword >>  8);  // con unos.
    dword |= (dword >> 16);

    if (dword > 0x7fffffff)
    {                        // Si en el método implementado, el último bit de la izquierda es 1, este mismo se perderá en la
        return 0x80000000;   // próxima linea donde lo desplazamos, así que directamente devolvemos el valor correspondiente.
    }

    return (dword >> 1) + !!dword; // Con la suma dejamos el 1 deseado a la izquierda, y lo desplazamos.
}                                  // La doble exclamación está para evitar el caso borde de 0x00

void tests()
{
    if (reemplazar_byte(0x00303456, 2, 0xcd) == 0x00cd3456) printf("OK TEST 1\n");
    if (reemplazar_byte(0xb00710ad, 0, 0x07) == 0xb0071007) printf("OK TEST 2\n");
    if (reemplazar_byte(0xcafecafe, 3, 0xca) == 0xcafecafe) printf("OK TEST 3\n");

    if (leftmost_one(0xefffffff) == 0x80000000) printf("OK TEST 4\n"); // Los tests funcionan ya que operan bit a bit.
    if (leftmost_one(0x8fffffff) == 0x80000000) printf("OK TEST 5\n"); 
    if (leftmost_one(0xff00) == 0x8000) printf("OK TEST 6\n");
    if (leftmost_one(0x6600) == 0x4000) printf("OK TEST 7\n");
    if (leftmost_one(0x0) == 0x0) printf("OK TEST 8\n");
    if (leftmost_one(1) == 0x1) printf("OK TEST 9\n");
}

int main()
{
    tests();
    return 0;
}
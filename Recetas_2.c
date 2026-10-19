#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64

int main () 
{
    char buffer[BUFFER_SIZE];
    float Masa;
    float MM;
    float Litros;

    write(STDOUT_FILENO, "Ingrese Masa: ", 14);
    int n = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
    buffer[n] = '\0';
    Masa = strtof(buffer, NULL);

    write(STDOUT_FILENO, "Ingrese MM: ", 12);
    n = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
    buffer[n] = '\0';
    MM = strtof(buffer, NULL);

    write(STDOUT_FILENO, "Ingrese Litros: ", 16);
    n = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
    buffer[n] = '\0';
    Litros = strtof(buffer, NULL);

    double F = (Masa / MM) / Litros;

    char resultado[BUFFER_SIZE];
    snprintf(resultado, BUFFER_SIZE, "Molaridad:\t%.2fM\n", F);
    
    write(STDOUT_FILENO, resultado, strlen(resultado));

    return 0;
}

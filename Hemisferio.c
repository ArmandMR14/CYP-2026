#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

int main() {
    char buffer[BUFFER_SIZE];
    char msg_inicio[] = "\nIntroduce la latitud o 'q' para salir: ";
    char msg_norte[] = "-> El punto se encuentra en el Hemisferio Norte.\n";
    char msg_sur[] = "-> El punto se encuentra en el Hemisferio Sur.\n";
    char msg_ecuador[] = "-> El punto se encuentra exactamente en el Ecuador.\n";
    char msg_error[] = "[Error]: Entrada inválida. Introduce solo números entre -90 y 90.\n";
    
    while (1) {
        write(STDOUT_FILENO, msg_inicio, strlen(msg_inicio));

        ssize_t bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        if (bytes_read <= 0) {
            continue; 
        }

        if (buffer[bytes_read - 1] == '\n') {
            buffer[bytes_read - 1] = '\0';
            bytes_read--;
        } else {
            buffer[bytes_read] = '\0';
        }

        if (strcmp(buffer, "q") == 0 || strcmp(buffer, "Q") == 0) {
            char msg_salir[] = "Saliendo del programa...\n";
            write(STDOUT_FILENO, msg_salir, strlen(msg_salir));
            break;
        }

        int i = 0;
        int puntos = 0;
        int es_valido = 1;

        if (buffer[i] == '-' || buffer[i] == '+') {
            i++;
        }

        if (buffer[i] == '\0') {
            es_valido = 0;
        }

        while (buffer[i] != '\0') {
            if (buffer[i] == '.') {
                puntos++;
                if (puntos > 1) { 
                    es_valido = 0;
                    break;
                }
            } else if (buffer[i] < '0' || buffer[i] > '9') {
                es_valido = 0;
                break;
            }
            i++;
        }

        if (!es_valido) {
            write(STDERR_FILENO, msg_error, strlen(msg_error));
            continue;
        }

        double latitud = strtod(buffer, NULL);

        if (latitud < -90.0 || latitud > 90.0) {
            write(STDERR_FILENO, msg_error, strlen(msg_error));
            continue;
        }

        if (latitud > 0.0) {
            write(STDOUT_FILENO, msg_norte, strlen(msg_norte));
        } else if (latitud < 0.0) {
            write(STDOUT_FILENO, msg_sur, strlen(msg_sur));
        } else {
            write(STDOUT_FILENO, msg_ecuador, strlen(msg_ecuador));
        }
    }

    return 0;
}


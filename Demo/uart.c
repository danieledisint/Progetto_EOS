#include "uart.h"
#include <stdarg.h> // Necessario per gestire gli argomenti variadici (...)

void UART_init( void )
{
    UART0_BAUDDIV = 16;
    UART0_CTRL = 1;
}

// Funzione helper per inviare un singolo carattere (rende il codice più pulito)
void UART_putc(char c) {
    UART0_DATA = (unsigned int)c;
}

// Funzione helper per convertire un intero in stringa e stamparlo
void UART_print_int(int num) {
    char buffer[12]; // Buffer per contenere le cifre (sufficiente per int a 32 bit)
    int i = 0;

    // Caso speciale per lo 0
    if (num == 0) {
        UART_putc('0');
        return;
    }

    // Gestione numeri negativi
    if (num < 0) {
        UART_putc('-');
        num = -num;
    }

    // Estrazione delle cifre (in ordine inverso)
    while (num > 0) {
        buffer[i++] = (num % 10) + '0'; // Converte la cifra in carattere ASCII
        num /= 10;
    }

    // Stampa delle cifre nell'ordine corretto
    while (i > 0) {
        UART_putc(buffer[--i]);
    }
}

// La firma cambia: ora accetta "..." dopo format
void UART_printf(const char *format, ...) {
    va_list args;
    va_start(args, format); // Inizializza la lista degli argomenti

    while(*format != '\0') {
        if (*format == '%') {
            format++; // Salta il carattere '%' e guarda il successivo
            
            if (*format == 'd') {
                // Se è %d, recupera un intero dalla lista e stampalo
                int val = va_arg(args, int);
                UART_print_int(val);
            } 
            else if (*format == '%') {
                // Se è %%, stampa il simbolo percentuale
                UART_putc('%');
            }
            // Qui potresti aggiungere altri casi come 'c', 's', 'x' in futuro
        } 
        else {
            // Carattere normale, stampalo direttamente
            UART_putc(*format);
        }
        format++;
    }

    va_end(args); // Pulisce la memoria della lista argomenti
}

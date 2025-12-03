/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

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

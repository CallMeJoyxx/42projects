/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:35:56 by jtriscar          #+#    #+#             */
/*   Updated: 2023/10/22 09:05:18 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

static void	action(int sig)
{
    static int	received = 0; // Contatore per i segnali ricevuti

    if (sig == SIGUSR1)
        ++received; // Incrementa il contatore se il segnale è SIGUSR1
    else
    {
        ft_putnbr_fd(received, 1); // Stampa il numero di segnali ricevuti
        ft_putchar_fd('\n', 1); // Stampa una nuova linea
        exit(0); // Termina il programma
    }
}

static void	mt_kill(int pid, char *str)
{
    int		i;
    char	c;

    while (*str)
    {
        i = 8; // Numero di bit per carattere
        c = *str++; // Prende il carattere corrente e passa al successivo
        while (i--)
        {
            if (c >> i & 1)
                kill(pid, SIGUSR2); // Invia SIGUSR2 se il bit è 1
            else
                kill(pid, SIGUSR1); // Invia SIGUSR1 se il bit è 0
            usleep(100); // Attende 100 microsecondi
        }
    }
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1); // Invia 8 segnali SIGUSR1 per indicare la fine del messaggio
        usleep(100); // Attende 100 microsecondi
    }
}

int	main(int argc, char **argv)
{
    if (argc != 3 || !ft_strlen(argv[2]))
        return (1); // Controlla che ci siano esattamente 3 argomenti e che il secondo non sia vuoto
    ft_putstr_fd("Sent    : ", 1); // Stampa "Sent    : "
    ft_putnbr_fd(ft_strlen(argv[2]), 1); // Stampa la lunghezza della stringa inviata
    ft_putchar_fd('\n', 1); // Stampa una nuova linea
    ft_putstr_fd("Received: ", 1); // Stampa "Received: "
    signal(SIGUSR1, action); // Imposta il gestore per SIGUSR1
    signal(SIGUSR2, action); // Imposta il gestore per SIGUSR2
    mt_kill(ft_atoi(argv[1]), argv[2]); // Invia la stringa al PID specificato
    while (1)
        pause(); // Attende segnali
    return (0);
}
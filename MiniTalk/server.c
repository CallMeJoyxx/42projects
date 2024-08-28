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
#include <unistd.h>
#include "libft/libft.h"

static void	action(int sig, siginfo_t *info, void *context)
{
    static int				i = 0; // Counter for bits received
    static pid_t			client_pid = 0; // PID of the client
    static unsigned char	c = 0; // Character being constructed

    (void)context; // Unused parameter
    if (!client_pid)
        client_pid = info->si_pid; // Set client PID if not already set
    c |= (sig == SIGUSR2); // Set the least significant bit if signal is SIGUSR2
    if (++i == 8) // If 8 bits have been received
    {
        i = 0; // Reset bit counter
        if (!c) // If character is null
        {
            kill(client_pid, SIGUSR2); // Notify client with SIGUSR2
            client_pid = 0; // Reset client PID
            return ;
        }
        ft_putchar_fd(c, 1); // Print the character
        c = 0; // Reset character
        kill(client_pid, SIGUSR1); // Notify client with SIGUSR1
    }
    else
        c <<= 1; // Shift bits to the left
}

int	main(void)
{
    struct sigaction	s_sigaction;

    ft_putstr_fd("Server PID: ", 1); // Print server PID message
    ft_putnbr_fd(getpid(), 1); // Print server PID
    ft_putchar_fd('\n', 1); // Print newline
    s_sigaction.sa_sigaction = action; // Set action function for signals
    s_sigaction.sa_flags = SA_SIGINFO; // Use sa_sigaction instead of sa_handler
    sigaction(SIGUSR1, &s_sigaction, 0); // Register SIGUSR1 handler
    sigaction(SIGUSR2, &s_sigaction, 0); // Register SIGUSR2 handler
    while (1)
        pause(); // Wait for signals
    return (0);
}

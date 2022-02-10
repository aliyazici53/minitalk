# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:19:35 by fkaratay          #+#    #+#              #
#    Updated: 2022/02/10 11:27:59 by fkaratay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./

CLIENT = $(CC) $(CFLAGS) client.c minitalk_utils.c -o client

SERVER = $(CC) $(CFLAGS) server.c minitalk_utils.c -o server

all:
	$(CLIENT)
	$(SERVER)

re: all

clean:
	rm -rf client server

fclean:
	rm -rf client server

.PHONY: re fclean clean all
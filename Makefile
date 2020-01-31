##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

all:
	make -C ./src/server/
	make -C ./src/client/
	make -C ./src/bonus/

client:
	make -C ./src/client/

server:
	make -C ./src/server/
bonus:
	make -C ./src/bonus/
clean:
	make clean -C ./src/server/
	make clean -C ./src/client/
	make clean -C ./src/bonus/
fclean:
	make fclean -C ./src/server/
	make fclean -C ./src/client/
	make fclean -C ./src/bonus/

re: fclean all

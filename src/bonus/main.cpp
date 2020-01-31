/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <iostream>
//#include "QWidget/Myirc.hpp"
#include "MyircTimer.hpp"

int is_tap_help (int nbr, char **av)
{
        for (int i = 1; i < nbr; ++i) {
                if (strcmp(av[i], "-help") == 0)
                        return (1);
        }
	return (0);
}

int invalid ()
{
 	fprintf(stderr, "Client : invalid command \n");
	fprintf(stderr, "Run : \"Sever -help \" for more information\n");
	return (84);
}

int help ()
{
 	printf("USAGE : ./client machine port\n");
	return (0);
}

int main(int argc, char *argv[])
{

	if (is_tap_help(argc, argv) == 1)
		return (help());
	if (argc != 1)
		return (invalid());


	QApplication app(argc, argv);
	//test.start();
	Myirc fenetre;
	fenetre.show();
	/*
	client();
	return (0);
	*/
	MyircTimer *timer = new MyircTimer(&fenetre);
        timer->start(50);	
	return app.exec();
}

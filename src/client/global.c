/*
** EPITECH PROJECT, 2018
** global
** File description:
** global
*/

#include "client.h"

t_trad g_tradco[20] = {
	{"/server","SERVER"},
	{"/nick","NICK"},
	{"/list","LIST"},
	{"/join","JOIN"},
	{"/part","PART"},
	{"/users","USERS"},
	{"/user","USER"},
	{"/names","NAMES"},
	{"/msg","PRIVMSG"},
	{"/accept_file","ACCEPT_FILE"},
	{"/invite","INVITE"},
	{"/quit","QUIT"},
	{NULL, NULL}
};

t_trad g_error_msgs[40] = {
	{"001 RPL_WELCOME", "[green]Hello[end]"},
	{"321 RPL_LISTSTART", "[green]List :[end]"},
	{"322 RPL_LIST", "[green]=>[end]"},
	{"353 RPL_NAMREPLY", "Name reply"},
	{"404 ERR_NEEDMOREPARAME","[red]More parameter are required[end]"},
	{"421 ERR_UNKNOWNCOMMAND","[red]Unknow command[end]"},
	{"431 ERR_NOCHANNELGIVE","[red]Channel[end]"},
	{"431 ERR_NONICKNAMEGIVE","[red]You don't have a nickname[end]"},
	{"432 ERR_ERRONEUSCHANNEL","[red]Error channel[end]"},
	{"432 ERR_ERRONEUSNICKNAME","[red]Error registering nick name[end]"},
	{"433 ERR_NICKNAMEINUSE","[red]This nickname exists already[end]"},
	{"442 ERR_NOTONCHANNEL","[red]Coucou[end]"},
	{"461 ERR_TOOMUCHPARAMS","[red]Too many parameters[end]"},
	{"462 ERR_ALREADYREGISTRED","[red]You are already registered on this channel[end]"},
	{":No topic is set", "[green]No topice set[end]"},
	{"Name reply :", "from"},
	{"JOIN", "join"},
	{NULL, NULL}
};

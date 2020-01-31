//
// EPITECH PROJECT, 2018
// ircTimer
// File description:
// ircTimer
//

#include "MyircTimer.hpp"



MyircTimer::MyircTimer(Myirc *myirc)
{
	_myirc = myirc;

	init_struct_client(&client);
	fds.nbr = 20;
}

void MyircTimer::timerEvent(QTimerEvent *e)
{
	std::string messages;

	(void)e;
	set_fds(&fds, client.sock);
        if (select_client(&fds) == 0) {
                client_reads_info(&fds, &client);
		messages = _myirc->getMessages().toStdString();
		if (messages != ""){
			//std::cout << messages << std::endl;
			client.msg_client = strdup(messages.c_str());
		} else {
			client.msg_client = NULL;
		}
		if (client.msg_server){
			translate(g_error_msgs, &client.msg_server);
			_myirc->analyseAnswer(client.msg_server);
                        client.msg_server = NULL;
                }
		if (client.msg_client){
                        if (strcmp(client.msg_client, "/quit") == 0)
	                        return ;
                        handle_commands(&client);
			client.msg_client = NULL;
			if (client.msg_server)
				_myirc->analyseAnswer(client.msg_server);
                }
		client.msg_client = NULL;
		client.msg_server = NULL;
        }
}

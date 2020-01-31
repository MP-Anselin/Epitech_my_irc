//
// EPITECH PROJECT, 2018
// Buttonsend
// File description:
// Buttonsend
//

#include "Config.hpp"

Config::Config()
{
	_layout = new QGridLayout;

	_host = new QLineEdit("127.0.0.1");
	_port = new QLineEdit("4242");
	_add_server = new Buttonirc("Connect to the server");

	_nickname = new QLineEdit("Merlin");
	_set_nickname = new Buttonirc("Set nickname");

	_chanel_to_create = new QLineEdit("CocoChanel");
	_create_chanel = new Buttonirc("Add a new chanel");

	_layout->addWidget(_host, 0, 0);
	_layout->addWidget(_nickname, 0, 1);
	_layout->addWidget(_chanel_to_create, 0, 2);
	
	_layout->addWidget(_port, 1, 0);
	_layout->addWidget(_set_nickname, 1, 1);
	_layout->addWidget(_create_chanel, 1, 2);
	
	_layout->addWidget(_add_server, 2, 0);

	
	//_message_to_send = nullptr;
	_to_send = false;
	this->setLayout(_layout);
}
/*
bool Config::event(QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress){
		_to_send = true;
	}
	return (QPushButton::event(e));
	(void)e;
	return (false);
}
*/
void Config::reinit()
{
	_to_send = false;
}

bool Config::is_to_send() const
{
	return (_to_send);
}

QString Config::getMessages() const
{
	if (_create_chanel->is_to_send()){
		_create_chanel->reinit();
		return (QString("/join ") + _chanel_to_create->text());
	}
	if (_set_nickname->is_to_send()){
		_set_nickname->reinit();
		return (QString("/nick ") + _nickname->text());
	}
	if (_add_server->is_to_send()){
		_add_server->reinit();
		return (QString("/server ") + _host->text() + ":" + _port->text());
	} else
		return (QString(""));
}

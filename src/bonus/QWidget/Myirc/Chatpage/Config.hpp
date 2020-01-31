//
// EPITECH PROJECT, 2018
// Buttonsend
// File description:
// Buttonsend
//

#include <QtGui/QtGui>
#include <iostream>
#include "Buttonirc.hpp"

#ifndef CONFIG_HPP_
# define CONFIG_HPP_

class Config : public QWidget
{
	QGridLayout *_layout;

	QLineEdit *_host;
	QLineEdit *_port;
	Buttonirc *_add_server;

	QLineEdit *_nickname;
	Buttonirc *_set_nickname;

	QLineEdit *_chanel_to_create;
	Buttonirc *_create_chanel;

	bool _to_send;
public:
	Config();
	//virtual bool event(QEvent * e);
	//void connectQTextEdit(QTextEdit *message_to_send);
	void reinit();
	bool is_to_send() const;
	QString getMessages() const;
	//std::string get_message_to_send() const;
};

#endif

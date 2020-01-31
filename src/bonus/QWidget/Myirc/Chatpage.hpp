//
// EPITECH PROJECT, 2018
// Chatpage
// File description:
// Chatpage
//

#include <QtGui/QtGui>
#include "Chatpage/Buttonirc.hpp"
#include "Chatpage/Config.hpp"
#include "../../Tools.hpp"

#ifndef CHATPAGE_HPP_
# define CHATPAGE_HPP_

class Chatpage : public QWidget
{
public:
	Chatpage(const std::string &name = "");
//public slots:
	void sendMessage(bool checked = false);
	QTextEdit *getAll_Message();
	Buttonirc *get_send_message();
	QTextEdit *getMessage_to_send();
	QString getMessages() const;
	void reInitMessage_to_send();
	void addTextChat(const std::string str);
	virtual bool event(QEvent * e);
private:
	QGridLayout *_layout;
	std::string _channel_name;

	QTextEdit *_all_messages;
	Config *_config;
	
        QTextEdit *_message_to_send;
        QTextEdit *_command_to_send;

        Buttonirc *_send_message;
        Buttonirc *_send_command;
};

#endif

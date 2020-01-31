//
// EPITECH PROJECT, 2018
// Buttonsend
// File description:
// Buttonsend
//

#include <QtGui/QtGui>
#include <iostream>
//#include "../Chatpage.hpp"

#ifndef BUTTONIRC_HPP_
# define BUTTONIRC_HPP_

class Buttonirc : public QPushButton
{
	//QTextEdit *_message_to_send;
	bool _to_send;
public:
	Buttonirc();
	Buttonirc(const QString &contents);
	virtual void clicked(bool checked = false);
	virtual bool event(QEvent * e);
	//void connectQTextEdit(QTextEdit *message_to_send);
	void reinit();
	bool is_to_send() const;
	//std::string get_message_to_send() const;
};

#endif

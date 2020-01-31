//
// EPITECH PROJECT, 2018
// Buttonsend
// File description:
// Buttonsend
//

#include "Buttonirc.hpp"

Buttonirc::Buttonirc()
{
	setText("Send message");
	//_message_to_send = nullptr;
	_to_send = false;
}

Buttonirc::Buttonirc(const QString &contents):QPushButton(contents)
{
	_to_send = false;
}

void Buttonirc::clicked(bool checked)
{
	(void)checked;
	qApp->quit();
}

bool Buttonirc::event(QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress){
		_to_send = true;
		/*
		std::cout << "Send message" << _message_to_send->toPlainText().toStdString() << std::endl;
		Buttonsend::reinit();
		*/
	}
	return (QPushButton::event(e));
	(void)e;
	//qApp->quit();

	return (false);
}
/*
void Buttonsend::connectQTextEdit(QTextEdit *message_to_send)
{
	_message_to_send = message_to_send;
}
*/
void Buttonirc::reinit()
{
	//_message_to_send->setText("");
	_to_send = false;
}

bool Buttonirc::is_to_send() const
{
	return (_to_send);
}
/*
std::string Buttonsend::get_message_to_send() const
{
	return (_message_to_send->toPlainText().toStdString());
}
*/

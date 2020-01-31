//
// EPITECH PROJECT, 2018
// Chatpage
// File description:
// Chatpage
//

#include "Chatpage.hpp"

Chatpage::Chatpage(const std::string &channel_name)
{
	_channel_name = channel_name;
	_all_messages = new QTextEdit();
	_message_to_send = new QTextEdit("/server 127.0.0.1:4242<br/>/nick Merlin<br/>/join #CocoChanel<br/>Hi, I'm Arthur<br/>/list");
	_command_to_send = new QTextEdit("/server");
	QFont font;
	font.setPointSize(16);
	_message_to_send->setFont(font);
	_all_messages->setFont(font);
	
	_send_message = new Buttonirc();
	_send_command = new Buttonirc();
	_config = new Config();

	_layout = new QGridLayout;
	_layout->addWidget(_all_messages, 0, 0);
	_layout->addWidget(_config, 0, 1, 2, 1);

	_layout->addWidget(_message_to_send, 1, 0);
	//_layout->addWidget(_command_to_send, 1, 1);

	_layout->addWidget(_send_message, 2, 0);
	//_layout->addWidget(_send_command, 2, 1);

        this->setLayout(_layout);
}

void Chatpage::sendMessage(bool checked)
{
	(void)checked;
	qApp->quit();
}

QTextEdit *Chatpage::getAll_Message()
{
	return (_all_messages);
}

Buttonirc *Chatpage::get_send_message()
{
	return (_send_message);
}

QTextEdit *Chatpage::getMessage_to_send()
{
	return (_message_to_send);
}

void Chatpage::reInitMessage_to_send()
{
	_message_to_send->setText("");
	_send_message->reinit();
}

QString Chatpage::getMessages() const
{
	QString message;

	if (_send_message->is_to_send()){
		_send_message->reinit();
		message = _message_to_send->toPlainText();
		if (message != ""){
			QString name = _channel_name.c_str();
			if (name != "")
				message = "/join " + name + "\n" + message;
		}
		_message_to_send->setText("");
		return (message);
	}else
		return (_config->getMessages());
}

void Chatpage::addTextChat(const std::string str)
{
	QString all_message = _all_messages->toHtml();
	QString new_text = str.c_str();


	new_text.replace("[red]", QString("<span style='color:#990000'>"));
	new_text.replace("[green]", QString("<span style='color:#009900'>"));
	new_text.replace("[blue]", QString("<span style='color:#000099'>"));
	new_text.replace("[end]",QString( "</span>"));
	new_text.replace("\n",QString("<br/>"));
	//_all_messages->setText(QString(all_message) + new_text);
	_all_messages->append(new_text);
}

bool Chatpage::event(QEvent * e)
{
	(void)e;
	return (QWidget::event(e));
}

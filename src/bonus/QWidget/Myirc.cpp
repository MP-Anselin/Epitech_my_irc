//
// EPITECH PROJECT, 2018
// Myirc
// File description:
// Myirc
//

#include "Myirc.hpp"

Myirc::Myirc()
{
	_onglets = new QTabWidget(this);
	_onglets->setGeometry(30, 20, 1200, 600);
	setWindowTitle("MyIrc");

	_page1 = new Chatpage;
	//_page2 = new Chatpage;
	//_page2 = new QWidget;
	//_page3 = new QLabel;

	_onglets->addTab(_page1, "General");
	//_onglets->addTab(_page2, "CocoChanel");
	//_onglets->addTab(_page2, "Progression");
	//_onglets->addTab(_page3, "Image");

	/*
	MyircTimer *timer = new MyircTimer();                                               
	timer->start(50);
	*/
	/*
        QProgressBar *progress = new QProgressBar;
        progress->setValue(50);
        QSlider *slider = new QSlider(Qt::Horizontal);
        QPushButton *bouton3 = new QPushButton("Valider");
	
        QVBoxLayout *vbox2 = new QVBoxLayout;
        vbox2->addWidget(progress);
        vbox2->addWidget(slider);
        vbox2->addWidget(bouton3);
	
	page2->setLayout(vbox2);
	*/
	/*
        page3->setPixmap(QPixmap("icone.png"));
        page3->setAlignment(Qt::AlignCenter);
	*/
}

Chatpage *Myirc::getChatpage()
{
	return (_page1);
}

QString Myirc::getMessages() const
{
	QString messages;
	QString message;

	for (std::map<std::string,Chatpage*>::const_iterator it=_channels_pages.begin();
	     it!=_channels_pages.end(); ++it){
		message = it->second->getMessages();
		if (message != "")
			messages += message;
	}
	message = _page1->getMessages();
	messages += message;
	return (messages);
}

void Myirc::addTextChat(const std::string str)
{
	std::string to_print = str;
	std::vector <std::string> args;
	std::string start;

	args = Tools::explode(str, " ");
	if (args.size() >= 4 && 0){
		if (args[1] == "PRIVMSG"){
			if (_channels_pages[args[2]]){
				start = args[0] + " " + args[1] + " "
					+ args[2] + " "+ args[3] + " ";
				to_print = Tools::str_replace(to_print, start, "");
				to_print = "[blue]" + Tools::str_replace(args[0], ":", "")
					+ "[end] " + to_print;
				_channels_pages[args[2]]->addTextChat(to_print);
			}
		}
	}
	_page1->addTextChat(to_print);
}

void Myirc::addChanel(const std::string name_channel)
{
	Chatpage *new_page = new Chatpage(name_channel);

	_onglets->addTab(new_page, name_channel.c_str());
	_channels_pages[name_channel] = new_page;
}

void Myirc::analyseAnswer(const std::string message_server)
{
	std::string name_chanel;
	std::vector <std::string> commands;

	commands = Tools::explode(message_server, "\n");
	for (size_t i = 0;i < commands.size();i++){
		if (commands[i].find("[info]enter_channel:")
		    != std::string::npos){
			name_chanel = Tools::str_replace(commands[i],
						  "[info]enter_channel:", "");
			if (_channels_pages[name_chanel] == nullptr)
				addChanel(name_chanel);
		} else if (commands[i].find("[info][connect_server]")
			   != std::string::npos){
			for (std::map<std::string,Chatpage*>::iterator
				     it=_channels_pages.begin();
			     it!=_channels_pages.end(); ++it){
				_onglets->removeTab(_onglets->indexOf(it->second));
				delete(it->second);
			}
			_channels_pages.clear();
			/*
			for (std::vector<int>::iterator
				     it=_all_onglets_index.begin();
			     it!=_all_onglets_index.end(); ++it){
				_onglets->removeTab(*it);
			}
			*/
			/*
			while(_onglets->page(1))
				_onglets->removeTab(1);
			_channels_pages.clear();
			_all_onglets_index.clear();
			*/
			/*
			_channels_pages.clear();
			*/
		}
		else
			addTextChat(commands[i]);
	}
}

//
// EPITECH PROJECT, 2018
// Myirc
// File description:
// Myirc
//

#include <QtGui/QtGui>
#include <map>
#include <string>
#include "Myirc/Chatpage.hpp"
//#include "../MyircTimer.hpp"

#ifndef MYIRC_HPP_
# define MYIRC_HPP_

class Myirc : public QWidget
{
public:
	Myirc();
	Chatpage *getChatpage();
	QString getMessages() const;
	void addTextChat(const std::string str);
	void analyseAnswer(const std::string str);
	void addChanel(const std::string str);
private:
	QTabWidget *_onglets;
	//std::vector<int> _all_onglets_index;
	Chatpage *_page1;
	std::map <std::string, Chatpage *> _channels_pages;
};

#endif

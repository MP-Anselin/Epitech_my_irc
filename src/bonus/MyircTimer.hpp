//
// EPITECH PROJECT, 2018
// IrcTimer
// File description:
// IrcTimer
//

#include <QtGui/QtGui>
#include <iostream>
#include "QWidget/Myirc.hpp"
//#include "client.h"

extern "C" {
#include "client.h"
}

#ifndef MYIRCTIMER_HPP_
# define MYIRCTIMER_HPP_

class MyircTimer : public QTimer
{
public:
        MyircTimer(Myirc *myirc);
protected:
        void timerEvent(QTimerEvent *e);
	Myirc *_myirc;
private:
	t_client client;
        t_fds fds;
};

#endif

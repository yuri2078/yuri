#include "teacher.h"
#include <QDebug>
#include <fstream>
#include "log.hpp"


Teacher::Teacher(QObject *parent) : QObject(parent)
{
    this->age = 66;
    this->name = "yuri";
}

void Teacher::eat()
{
    // button->setText(this->name);
    m_log << "nihao";
}

void Teacher::eat(string food)
{
    // button->setText(this->name);
    m_log << food;
}

int Teacher::clean()
{
    return m_log.clean();
}
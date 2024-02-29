//
// Created by jlibyvali on 24-2-28.
//
/*
 *  This is one 'Node' class, we usually  use object-oriented way by creating class in CPP.
 *
 * */

#include "Contact.h"

Contact::Contact(std::string _name):name(_name), next(NULL) {}  // Initialise Contact constructor

std::ostream& operator<<(std::ostream& os ,const Contact& man){
    return os<< "Name: "<<man.name;
}


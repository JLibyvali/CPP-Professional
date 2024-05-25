//
// Created by jlibyvali on 24-2-28.
//

#ifndef DATASTRUCTURE_CONTACT_H
#define DATASTRUCTURE_CONTACT_H


#include <iostream>
#include <string>

class Contact{
friend  std::ostream& operator<< (std::ostream& os,const Contact& c);

public:
    Contact(std::string name ="none");
private:
    std::string name;
    Contact* next;

};






#endif //DATASTRUCTURE_CONTACT_H

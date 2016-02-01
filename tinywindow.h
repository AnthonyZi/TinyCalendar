#ifndef TINYWINDOW_H
#define TINYWINDOW_H

#include <gtkmm.h>
#include <string>
#include <vector>
#include "person.h"
#include "sortpersons.h"

class TinyWindow : public Gtk::Window
{
private:
        Gtk::Box topBox;
        Gtk::Frame labelFrame;
        Gtk::Label label;

        std::string getNext(std::vector<Person*>* pvector);
public:
        TinyWindow(std::vector<Person*>* pvector);
};

#endif

#include "tinywindow.h"

TinyWindow::TinyWindow(std::vector<Person*>* pvector) :
        topBox(Gtk::ORIENTATION_VERTICAL, 5),
        labelFrame("BIRTHDAYS OF THE NEXT 30 DAYS"),
        label("")
{
        set_title("TinyCalendar - Birthday Reminder");
        set_border_width(5);
        set_default_size(200, 50);

        label.set_text(getNext(pvector));

        add(topBox);

        labelFrame.add(label);
        topBox.pack_start(labelFrame, Gtk::PACK_SHRINK);

        show_all_children();
}

std::string TinyWindow::getNext(std::vector<Person*>* pvector)
{
        std::string result;
        sortPersons(pvector, 1);

        int lastperson = 0;
        int firstperson = 0;
        time_t now; struct tm compare;
        time(&now);
                
        while(1)
        {
                if(pvector->size()-1 == (unsigned int)lastperson)
                        break;
                compare = *(localtime(&now));
                compare.tm_mday = (*pvector)[lastperson]->getDate()->tm_mday;
                compare.tm_mon = (*pvector)[lastperson]->getDate()->tm_mon;

                if(difftime(mktime(&compare), now) < 0)
                        firstperson++;

                if(difftime(mktime(&compare), now) < 2592000)
                        lastperson++;
                else
                        break;
        }
        for(int i = firstperson; i < lastperson; i++)
        {
                result += (*pvector)[i]->getString();
        }
        return result; 
}



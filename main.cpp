#include "userio.h"
#include <vector>
#include "person.h"
#include <iostream>
#include "tinywindow.h"
#include <gtkmm.h>

int main(int argc, char *argv[])
{
        std::vector<Person*> persons;
        readFile("/home/zmann/.windowreminder", &persons);

        if(argc == 1)
        {
                Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "tiny.cal.gtk");

                TinyWindow window(&persons);
                return app->run(window);
        }
        else
        {
                std::string param(argv[1]);
                if(param.compare("console") == 0)
                {
                        std::cout << "--TinyCal--" << std::endl;
                        system("clear");
                        consoleUI(&persons);
                }
        }

        return 0;
}

A tiny console-calendar with a Terminal-Interface
The attempt was do develope it within 30min

        Standard-File is /home/zmann/.windowreminder
-> autoread with startup
-> autosave with parameter "-"

compile the Code with:

g++ main.cpp person.cpp consoleio.cpp fileio.cpp tinywindow.cpp sortpersons.cpp -o tinycal -Wall -g -O3 -std=c++14 `pkg-config gtkmm-3.0 --cflags --libs`

compilation with make does not work!

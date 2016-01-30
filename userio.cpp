void consoleUI()
{
        while(1)
        {
                std::string command;
                command = getCommand();

                if(command.compare("new")
                {
                        addUser();
                }

                if(command.compare("delete")
                {
                        delUser();
                }
        }
}

std::string getCommand()
{
        std::string input;
        std::cin >> input;
        return input;
}

void addUser()
{
        Person newPerson = new Person();
        
        std::string input;
        std::cout << "Name:" << std::endl;
        std::cin >> input;

        

}

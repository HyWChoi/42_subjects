#ifndef ITERN_HPP
# define ITERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(Intern const & src);
        Intern &operator=(Intern const & src);
        ~Intern();

        class FormNotFoundException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Form not found";
                }
        };

        AForm* makeForm(std::string name, std::string target);
};

#endif
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        int getLevelIndex(std::string level);

    public:
        Harl();
        ~Harl();
        void filterComplains(std::string level);
};

#endif

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		typedef void (Harl::*HarlMethodPointer)(void);

		typedef struct MethodHandleMap {
			std::string level;
			HarlMethodPointer HarlMethodPtr;
		} MethodHandleMap;

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif

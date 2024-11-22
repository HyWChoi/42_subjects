#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed {
	private:
		std::string fileName;
		std::string originString;
		std::string replaceString;
	public:
		Sed(const std::string &fileName, const std::string &s1, const std::string &s2);
		~Sed();
		std::string getFileName() const;
		std::string getOriginString() const;
		std::string getReplaceString() const;
		void setFileName(std::string str);
		void setOriginString(std::string str);
		void setReplceString(std::string str);
		void sed();
};

#endif

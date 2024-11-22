#include <iostream>
#include <string>

int	main(){
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address in memory of the string: " << &str << std::endl;
	std::cout << "Address in memory of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;
	std::cout << "String" << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;

	// 일반 스트링은 레퍼런스 는 차이점이 파라미터로 넘긴다면, 일반 스트링은 메모리 낭비가 심함, 레퍼런스를 넘기면 주소값만 넘겨서 낭비가 없다
	// 포인터는 레퍼런스 둘 다 주소값인데, 포인터는 선언과 동시에 초기화 x,
	// 레퍼런스는 선언과 동시에 초기화해서 안정성이 높고 선언과 초기화를 동시에 해야한다면, 보통 레퍼런스를 쓴다
	// 널밧으로 남겨야할 땐 포인터를 쓴다
	return (0);
}

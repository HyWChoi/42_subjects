#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	{
		std::cout << "--- test 1 ---" << std::endl;
		Base *a = new A();
		Base *b = new B();
		Base *c = new C();

		identify(a);
		identify(b);
		identify(c);

		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}
	{
		std::cout << "--- test 2" << std::endl;
		Base *a = generate();

		identify(a);

		identify(*a);

		delete a;
	}
	return 0;
}

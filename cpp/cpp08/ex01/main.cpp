#include "Span.hpp"

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}


// int main()
// {
// 	try {
// 		Span sp = Span(5);

// 		sp.addNumber(6);
// 		sp.addNumber(3);
// 		sp.addNumber(17);
// 		sp.addNumber(9);
// 		sp.addNumber(11);

// 		// 이 줄은 예외를 발생시킬 것입니다 (이미 꽉 찼으므로)
// 		sp.addNumber(1);

// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	}
// 	catch (const Span::SpanFullException& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	catch (const Span::SpanNotEnoughNumbersException& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	catch (const std::exception& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}

// 	return 0;
// }


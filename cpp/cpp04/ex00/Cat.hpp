#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
   		Cat();
    
    	// 복사 생성자
    	Cat(const Cat& other);
    
    	// 소멸자 (가상 소멸자로 선언)
    	virtual ~Cat();
    
    	// 대입 연산자 오버로딩
    	Cat& operator=(const Cat& other);
    
    	// makeSound 가상 함수 오버라이드
    	virtual void makeSound() const;
};

#endif
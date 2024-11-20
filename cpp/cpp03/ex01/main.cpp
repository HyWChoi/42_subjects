#include <iostream>
#include "ClapTrap.hpp"

int main() {
   // 기본 ClapTrap 생성 및 초기 상태
   ClapTrap clap1("Clap1");
   ClapTrap clap2("Clap2");

   std::cout << "\n=== Basic Attack Test ===" << std::endl;
   clap1.attack("Clap2");
   clap2.takeDamage(0);  // 회피 테스트
   clap2.takeDamage(5);  // 일반 데미지 테스트

   std::cout << "\n=== Repair Test ===" << std::endl;
   clap2.beRepaired(3);  // 수리 테스트
   clap2.beRepaired(0);  // 0 수리량 테스트

   std::cout << "\n=== Energy Depletion Test ===" << std::endl;
   // 에너지 소진 테스트 (기본 10에서 모두 소진할때까지)
   for (int i = 0; i < 12; i++) {
       std::cout << "\nAttack " << i+1 << ":" << std::endl;
       clap1.attack("Target");
   }

   std::cout << "\n=== Death State Test ===" << std::endl;
   // 죽음 상태 테스트
   ClapTrap clap3("Clap3");
   clap3.takeDamage(20);  // 치명적 데미지
   clap3.attack("Target");  // 죽은 후 공격 시도
   clap3.beRepaired(5);   // 죽은 후 수리 시도
   clap3.takeDamage(5);   // 죽은 후 추가 데미지

   std::cout << "\n=== Copy Constructor Test ===" << std::endl;
   ClapTrap clap4(clap1);  // 복사 생성자 테스트
   clap4.attack("Target");

   return 0;
}

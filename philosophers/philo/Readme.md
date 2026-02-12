# 📌 Philosophers – Dining Philosophers 동시성 문제 해결 #
## 📂 Project Overview ##

Dining Philosophers 문제를 기반으로
멀티스레드 환경에서의 자원 공유, 동기화, 데드락 방지를 직접 설계·구현한 프로젝트입니다.

pthread 기반 병렬 처리 구조를 구현하고,
mutex를 활용하여 race condition을 방지하며 안정적인 실행 환경을 구성했습니다.

## 🎯 Technical Highlights ##

동시성 문제 분석 및 해결 경험

자원 경쟁 상황에서의 안전한 설계

병렬 처리 구조 이해

시스템 레벨에서의 타이밍 제어 구현

## 📈 What I Learned ##

멀티스레드 환경에서 공유 자원의 위험성 이해

데드락과 race condition의 차이 및 해결 전략 체득

스레드 생명주기 관리 및 리소스 정리의 중요성 경험

## 🛠 Tech Stack ## 

C

POSIX Threads (pthread)

Mutex

Linux

## ⚙ 주요 구현 내용 ##
### 1️⃣ 멀티스레딩 구조 설계 ###

각 철학자를 독립적인 스레드로 생성

공용 자원(포크)을 공유 구조체로 관리

### 2️⃣ Mutex 기반 동기화 처리 ###

포크를 mutex로 보호하여 임계 영역 제어

공유 데이터 접근 시 동기화 보장

race condition 방지 로직 설계

### 3️⃣ 데드락 방지 전략 구현 ###

포크 획득 순서 비대칭 설계

홀수/짝수 철학자 분리 전략 적용

### 4️⃣ 모니터링 스레드 구현 ###

철학자의 생존 시간 지속 체크

time_to_die 초과 시 즉시 종료 처리

프로그램 전체 종료 조건 관리

### 5️⃣ 리소스 정리 및 예외 처리 ###

모든 mutex 및 스레드 안전 종료

메모리 누수 방지

입력 값 검증 및 edge case 처리

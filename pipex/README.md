# pipex

## 조건

- `pipex`프로그램은 다음과 같이 실행

  - 명령줄 인수로 파일과 명령어를 받기
  - 첫 번째 파일(`file1`)에서 입력을 받아 첫 번째 명령어(`cmd1`)를 실행
  - 그 결과를 두 번째 명령어(`cmd2`)로 전달
  - 최종 결과를 두 번째 파일(`file2`)에 저장

  - 과정은 유닉스의 파이프라인 (`< file1 cmd1 | cmd2 > file2`)과 동일한 작업을 수행

## 목표

```shell
$> ./pipex file1 cmd1 cmd2 file2
```

- **파일 접근:** 프로그램은 `file1`의 내용을 읽고, `file2`에 결과를 쓸 수 있는 권한이 필요
- **에러 처리:** 에러 발생 시, 적절한 에러 메시지를 출력

## operations

- perror(const char \*s): 에러 메시지를 출력한다.
- strerror(int errnum): 에러 번호에 해당하는 에러 메시지를 반환한다.
- access(const char \*pathname, int mode): 파일에 대한 접근 권한을 확인한다.
  - R_OK : 파일 존재 여부, 읽기 권한 여부
  - W_OK : 파일 존재 여부, 쓰기 권한 여부
  - X_OK : 파일 존재 여부, 실행 권한 여부
  - F_OK : 파일 존재 여부
- dup(int oldfd): 파일 디스크립터를 복제한다.
- dup2(int oldfd, int newfd): 파일 디스크립터를 다른 파일 디스크립터로 복제한다.
- execve(const char *pathname, char *const argv[], char \*const envp[]): 새로운 프로세스를 실행한다.
- exit(int status): 프로그램을 종료한다.
- fork(void): 현재 프로세스를 복제하여 새로운 프로세스를 생성한다.
- pipe(int pipefd[2]): 파이프를 생성한다.
- unlink(const char \*pathname): 파일을 삭제한다.
- wait(int \*status): 자식 프로세스가 종료될 때까지 대기하고 종료 상태를 받는다.
- waitpid(pid_t pid, int \*status, int options): 특정 자식 프로세스가 종료될 때까지 대기하고 종료 상태를 받는다.

## 구현

- 파이프의 연결은 `file discriptor`를 통해 구현,

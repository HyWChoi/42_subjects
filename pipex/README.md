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
  우선 파이프 엑스의 main함수를 작성했다.
  파이프를 연결해서 출력하는 결과를 저장하려면 우선 읽는 파일 설정과 출력 파일 설정이 필요하다.

## pipex 읽기 전용 - 출력 전용 파일 만들기

### main

```
pipex.infile = open(argv[1], O_RDONLY);
pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
```

- open(fd, open_option, mod);
  - 특정 파일의 옵션과 권한을 설정한다.

```
if (!sanity_check(argc, argv, &pipex))
    return (0);
if (!check_fork(&pid1))
    return (0);
```

- 무결성 검사를 통해 인자의 개수, 파일접근 권한 등 초기 조건을 검사
- fork함수의 호출이 제대로 이루어졌는지 검사

```
if (pid1 == 0)
    change_fd_children(&pipex, argv, envp);
else
    change_fd_parent(&pipex, argv, envp);
```

- 자식 프로세스인 경우 chilredn을 호출, 부모 프로세스인 경우 parent를 호출하여 실행
  - fork의 반환값을 통해 부모와 자식을 판별
  - fork()호출을 사용하면, 자식 프로세스에겐 0을 반환하고 부모 프로세스에게는 자식 프로세스의 PID를 반환한다.
  - 에러 상황에는 -1을 반환한다.

```
close(pipex.infile);
close(pipex.outfile);
```

- 사용이 완료된 입력 파일과 출력 파일의 파일 디스크립터 닫는다.

```
waitpid(pid1, NULL, 0);
```

- waitpid 시스템 호출을 사용하여 자식 프로세스의 종료를 기다린다.
  - `waitpid()` 사용 여부에 따른 차이점
  - `waitpid()`를 사용할 경우
    - **부모 프로세스 동작:** `pid1` 자식 프로세스의 종료를 기다립니다.
    - **실행 흐름:** 자식 프로세스가 종료되면, 부모 프로세스는 그 다음 코드를 실행합니다.
    - **장점:** 이 방식은 프로세스의 실행 순서를 제어하고, 자식 프로세스가 종료될 때까지 부모 프로세스가 끝나지 않도록 보장합니다.
  - `waitpid()`를 사용하지 않을 경우
    - **부모 프로세스 동작:** 자식 프로세스의 종료를 기다리지 않고 바로 다음 코드를 실행합니다.
    - **결과:** 이로 인해 자식 프로세스가 아직 실행 중일 때 부모 프로세스가 종료될 수 있습니다.
    - **고아 프로세스:** 자식 프로세스가 종료되기 전에 부모 프로세스가 끝나면, 자식 프로세스는 고아 프로세스가 되거나 `init` 프로세스의 자식이 됩니다.
- waitpid를 통해 프로세스의 동작을 제어하고 자원 관리를 최적화할 수 있다.

### Utils & SanityCheck

```
t_boolean    check_argc(int argc)
{
    if (argc != 5)
    {
        perror("Usage: ./pipex file1 cmd1 cmd2 file2");
        return (FALSE);
    }
    return (TRUE);
}

t_boolean    check_open(int *fd)
{
    if (*fd == ERROR)
    {
        perror("open error");
        return (FALSE);
    }
    return (TRUE);
}

t_boolean    check_access(char *str[])
{
    char    *file1;
    char    *file2;
    int        read;
    int        write;

    read = R_OK;
    write = W_OK;
    file1 = str[1];
    file2 = str[4];
    if (access(file1, read) == ERROR)
    {
        perror("infile is not exist or permission denied.");
        return (FALSE);
    }
    if (access(file2, write) == ERROR)
    {
        perror("outfile is not exist or permission denied.");
        return (FALSE);
    }
    return (TRUE);
}

t_boolean    check_pipe(int *pipefd)
{
    pipe(pipefd);
    if (*pipefd == ERROR || *(pipefd + 1) == ERROR)
    {
        perror("pipe error");
        return (FALSE);
    }
    return (TRUE);
}

t_boolean    sanity_check(int argc, char *argv[], t_pipex *pipex)
{
    if (!check_argc(argc))
        return (FALSE);
    if (!check_access(argv))
        return (FALSE);
    if (!check_open(&pipex->infile) || !check_open(&pipex->outfile))
        return (FALSE);
    if (!check_pipe(pipex->pipefd))
        return (FALSE);
    return (TRUE);
}
```

- check_argc
  - 함수 인자의 개수를 검사
- check_open
  - 파일 디스크립터가 유효한지 검사
- check_access
  - 입-출력 파일의 접근 권한을 검사
- check_pipe

  - 파이프를 생성하고, 오류 발생 검사

    ```
    t_boolean    sanity_check(int argc, char *argv[], t_pipex *pipex)
    {
    if (!check_argc(argc))
        return (FALSE);
    if (!check_access(argv))
        return (FALSE);
    if (!check_open(&pipex->infile) || !check_open(&pipex->outfile))
        return (FALSE);
    if (!check_pipe(pipex->pipefd))
        return (FALSE);
    return (TRUE);
    }
    ```

    실행 전 여러 조건들에 대한 유효성 검사를 진행한 뒤에 모든 검사가 통과하면 true를 반환한다.

```
char    *find_command_path(char *command, char *envp[])
{
    char    *path;
    char    *full_path;
    char    **paths;
    char    **tmp;

    path = find_path(envp);
    paths = ft_split(path, ':');
    tmp = paths;
    while (*paths)
    {
        full_path = ft_strjoin(*paths, "/");
        full_path = ft_strjoin(full_path, command);
        if (access(full_path, X_OK) == 0)
        {
            free_split(tmp);
            return (full_path);
        }
        free(full_path);
        paths++;
    }
    free_split(tmp);
    return (NULL);
}

char    *find_path(char *envp[])
{
    while (*envp)
    {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
            return (*envp + 5);
        envp++;
    }
    return (NULL);
}
```

- find_path
  - envp 배열을 순회하면서 각 환경 변수의 이름이 "PATH="으로 시작하는지 검사
  - 목표를 찾으면 그 뒤에 이어지는 문자열을 반환, 찾지 못하면 NULL을 반환한다.
- find_command_path
  - 주어진 명령어에 대한 실행 파일 경로를 탐색
  - 환경 변수로부터 받은 "PATH" 환경 변수 값을 이용하려 탐색
  - PATH 환경 변수에서 ":"를 기준으로 분리하여 디렉토리 목록을 생성
  - 각 디렉토리에 /과 주어진 명령어를 붙여 전체 경로를 생성한 뒤에 access함수로 실행 권환을 검사
  - 실행 권한이 있는 파일 경로를 찾으면 메모리를 정리하고 해당 경로를 반환
  - 찾지 못한다면 NULL을 반환한다.

```
void    execute_cmd(t_pipex *pipex, char **envp)
{
    char    *path;

    path = find_command_path(pipex->cmd[0], envp);
    if (!path)
    {
        perror("command not found");
        exit(1);
    }
    if (execve(path, pipex->cmd, envp) == ERROR)
    {
        perror("execve error");
        exit(1);
    }
}
```

- 위의 find_command_path를 통해 찾은 경로를 찾는다.
- 만약 경로가 존재하지 않는다면 에러 메시지를 보여주고 종료시킨다.
- 만약 경로가 존재한다면 execve 호출을 통해 명령어를 실행한다.
  - execve는 pipex->cmd의 인자 배열과 envp의 환경 변수 배열을 사용하여 실행

## execve

- `execve` 함수는 Unix 및 Unix 계열 시스템에서 현재 프로세스를 새로운 프로그램으로 대체하는 시스템 호출
- 현재 실행 중인 프로그램의 코드, 데이터, 힙, 스택을 새로운 프로그램의 것으로 완전히 대체
- 프로그램 실행에 필요한 모든 정보를 새로운 프로그램으로 전달하고, 새 프로그램을 시작시키는 역할을 수행

  ```
  int execve(const char *pathname, char *const argv[], char *const envp[]);
  ```

- pathname
  - 실행할 프로그램의 경로
- argv\[\]
  - 프로그램에 전달될 인자(argument)의 배열
  - argv\[0\]은 일반적으로 프로그램의 이름, 배열의 마지막 요소는 NULL이어야함
- envp\[\]
  - 프로그램에 전달될 환경 변수(environment variables)의 배열
  - 이 배열 역시 NULL로 끝나야함

### 부모-자식 프로세스에서 실행할 함수

우선은 부모 프로세스에서 실행할 함수이다.

```
void    change_fd_parent(t_pipex *pipex, char *argv[], char **envp)
{
    pipex->cmd = ft_split(argv[3], ' ');
    close(pipex->pipefd[1]);
    dup2(pipex->pipefd[0], STDIN_FILENO);
    dup2(pipex->outfile, STDOUT_FILENO);
    close(pipex->outfile);
    close(pipex->pipefd[0]);
    execute_cmd(pipex, envp);
    free(pipex->cmd);
    pipex->cmd = 0;
}
```

- 인자로 받은 명령어를 split으로 공백 구분 후 결과를 cmd에 저장
- `close`를 통해 파이프의 쓰기를 닫음
- `dup2`를 사용해 `pipex->pipfd[0]`을 표준 입력으로 바꿈
- `dup2`를 사용해 `pipex->outfile`을 표준 출력으로 바꿈
- `pipex->outfile`과 `pipex->pipfd[0]`은 더이상 사용하지 않기 때문에 닫음
- 커맨드 실행
- 자원 해제 후 포인터 초기화

```
void    change_fd_children(t_pipex *pipex, char *argv[], char **envp)
{
    pipex->cmd = ft_split(argv[2], ' ');
    close(pipex->pipefd[0]);
    dup2(pipex->infile, STDIN_FILENO);
    dup2(pipex->pipefd[1], STDOUT_FILENO);
    close(pipex->infile);
    close(pipex->pipefd[1]);
    execute_cmd(pipex, envp);
    free(pipex->cmd);
    pipex->cmd = 0;
}
```

- 인자로 받은 명령어를 split으로 공백 구분 후 결과를 cmd에 저장
- `close`를 통해 파이프의 읽기를 닫음
- `dup2`를 사용해 `pipex->pipfd[1]`을 표준 출력으로 바꿈
- `dup2`를 사용해 `pipex->infile`을 표준 입력으로 바꿈
- `pipex->infile`과 `pipex->pipfd[1]`은 더이상 사용하지 않기 때문에 닫음
- 커맨드 실행
- 자원 해제 후 포인터 초기화

위 두 함수를 통해 부모와 자식 프로세스에 연결된 파이프에 대해 관리를 한다.
자식 프로세스의 경우 파일에서 읽은 값에 대한 결과를 부모에 보내주어야하는데 이 때, infile을 입력에 복사하고, 출력은 표준 출력에 복사시킨다.
부모의 경우 반대로 진행해 진행한다.

이 두함수와 첫 글의 mian함수를 통해 프로세스를 복사, 내용을 교체하여 여러 프로세스들의 실행순서등을 효과적으로 제어 및 실행할 수 있게한다.

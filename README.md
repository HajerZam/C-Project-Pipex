# C-Project-Pipex
my sixth project in 42 common core, I am . . . f i n e( ._. )
### **1. Understanding Unix**

Unix is an operating system that provides a way for programs to interact with the computer's hardware and other programs. It is powerful because of:

- **Processes**: Every running program is a "process."
- **Files**: Everything (even devices) is treated as a file.
- **Pipes**: A way to send the output of one program as input to another.

### **Basic Unix Commands**

These commands are commonly needed when testing a project:

- `ls` → List files
- `cat file.txt` → Show contents of a file
- `echo "hello"` → Print text
- `> file.txt` → Redirect output to a file
- `< file.txt` → Take input from a file
- `|` → Pipe output of one command into another

Example:

```
echo "Hello" | wc -c

```

This prints **6**, because "Hello" has 5 letters + 1 newline.

---

### **2. Understanding Imperative Programming**

Imperative programming refers to a style where step-by-step instructions are given to the computer. It differs from functional or declarative programming.

### **Key Concepts**

- **Variables**: Store values
- **Loops**: Repeat actions
- **Conditions**: Make decisions (`if`, `else`)
- **Functions**: Group reusable code
- **Pointers & Memory**: Work with raw memory (important in C)

Example in C:

```c
#include <stdio.h>

int main()
{
    int x;
    
    x = 5;
    if (x > 0)
    {
        printf("Positive number\n");
    }
    return (0);
}

```

---

### **3. How Pipes Work in Unix (The Heart of Pipex)**

A **pipe (`|`)** allows two programs to communicate.

Example in shell:

```
ls | grep "file"

```

- `ls` lists files.
- `grep "file"` filters the output to show only lines containing "file."

### **How Pipes Work in C**

A **pipe** is a communication channel between processes. It is created using `pipe()`.

```c
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd[2]; // File descriptors (fd[0] = read, fd[1] = write)
    pipe(fd);  // Create the pipe
    if (fork() == 0) { // Child process
        close(fd[0]); // Close unused read end
        write(fd[1], "Hello", 5);
        close(fd[1]);
    }
    else
    { // Parent process
        char buffer[10];
        close(fd[1]); // Close unused write end
        read(fd[0], buffer, 5);
        buffer[5] = '\0';
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return (0);
}

```

### **What Happens Here?**

1. A pipe (`fd[2]`) is created.
2. The parent forks (creates a child process).
3. The child writes "Hello" into the pipe.
4. The parent reads "Hello" from the pipe.

---

### **4. What Are Processes in Unix?**

A **process** is a running program. Every time a program is opened, a process is created in the system.

Examples:

- When `ls` is typed in the terminal, it starts a **process** that lists files.
- When Chrome is opened, it starts a **process** for web browsing.

Each process has:

- **A PID (Process ID)** → A unique number for each process.
- **A Parent Process** → The process that created it.
- **A Child Process** → A new process made by another process.

### **What Is a Parent and Child Process?**

When a process creates another process:

- The **original** process → **Parent**
- The **new** process → **Child**

### **Example: Using `fork()`**

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    
    pid = fork(); // Create a new process
    if (pid == 0)
    {
        printf("I am the child process!\n");
    }
    else
    {
        printf("I am the parent process!\n");
    }
    return (0);
}

```

---

### **5. What Is Pipex?**

Pipex simulates how shell pipes work, using:

- `pipe()` → Creates a pipe
- `fork()` → Creates child processes
- `dup2()` → Redirects input/output
- `execve()` → Replaces a process with a new program

### **Pipex Goal**

The objective is to create a program that mimics:

```
./pipex file1 cmd1 cmd2 file2

```

Which should behave like:

```
< file1 cmd1 | cmd2 > file2

```

---

### **6. Key C Functions Needed**

### **`pipe()`**

Creates a communication channel between two processes.

```c
int fd[2];
pipe(fd);

```

- `fd[0]` → Read end
- `fd[1]` → Write end

### **`fork()`**

Creates a child process.

```c
pid_t pid = fork();

```

- `pid == 0` → Child process
- `pid > 0` → Parent process

### **`dup2()`**

Redirects file descriptors.

```c
dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end

```

- `STDIN_FILENO` → Standard input (`0`)
- `STDOUT_FILENO` → Standard output (`1`)

### **`execve()`**

Runs a new program inside a process.

```c
char *cmd[] = {"/bin/ls", NULL};
execve(cmd[0], cmd, envp);

```

This replaces the current process with `/bin/ls`.
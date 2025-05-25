<h1 align="center">🔗 C-Project: Pipex</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/badge/42-Common%20Core-critical" />
  <img src="https://img.shields.io/github/last-commit/HajerZam/C-Project-Pipex" />
</p>

<p align="center">
  💥 Sixth project in the 42 Common Core<br>
  I am . . . f i n e ( ._. )
</p>

---

## 🧠 Project Overview

**Pipex** is a reproduction of how Unix handles pipes (`|`) in the shell.

You will build a program that mimics the shell behavior for piping commands like:

```bash
< infile cmd1 | cmd2 > outfile
````

Implemented in C using:

* `pipe()`
* `fork()`
* `dup2()`
* `execve()`

---

## 🔧 Usage

### Build

```bash
make
```

### Run

```bash
./pipex infile cmd1 cmd2 outfile
```

This is equivalent to:

```bash
< infile cmd1 | cmd2 > outfile
```

Example:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

---

## 📁 File Structure

| File       | Purpose                              |
| ---------- | ------------------------------------ |
| `pipex.c`  | Main logic for parsing and executing |
| `utils.c`  | String splitting, path resolving     |
| `pipex.h`  | Header with macros and prototypes    |
| `Makefile` | Builds your program                  |

---

## 📚 Unix Concepts Recap

### 📄 Everything is a File

In Unix:

* Files = text, devices, sockets, etc.
* You use file descriptors (FDs) to access them

### 🔁 Pipes (`|`)

A pipe sends the **stdout of one command** to the **stdin of another**.

Example:

```bash
echo "Hello" | wc -c  # Outputs: 6
```

---

## 🔍 How Pipes Work in C

### 🔨 Code Example

```c
int fd[2];
pipe(fd);
if (fork() == 0)
{
    close(fd[0]);           // Close read end
    dup2(fd[1], STDOUT_FILENO); // Redirect stdout
    execve(cmd1_path, cmd1_args, envp);
}
else
{
    close(fd[1]);           // Close write end
    dup2(fd[0], STDIN_FILENO);  // Redirect stdin
    execve(cmd2_path, cmd2_args, envp);
}
```

---

## 🧵 Processes in Unix

Every program is a **process** with:

* A **PID**
* A **Parent**
* Possibly **Children**

Creating a new process:

```c
pid_t pid = fork();
```

* `pid == 0` → child
* `pid > 0` → parent

---

## ⚙️ Core System Calls Used

### `pipe(int fd[2])`

Creates a pipe: `fd[0]` for reading, `fd[1]` for writing.

### `fork()`

Creates a new process.

### `dup2(oldfd, newfd)`

Redirects file descriptors.

```c
dup2(fd[1], STDOUT_FILENO); // Redirect stdout to write end
```

### `execve()`

Runs a command.

```c
char *cmd[] = {"/bin/ls", NULL};
execve(cmd[0], cmd, envp);
```

---

## 🧪 Testing

### Basic Test

```bash
./pipex infile "cat" "wc -l" outfile
```

### Compare to Shell Output

```bash
diff <(./pipex in "grep hello" "wc -l" out) <( < in grep hello | wc -l > out )
```

---

## 🛠 Bonus Ideas

* Support more than 2 commands (multi-pipe)
* Handle quotes and escaped characters
* Implement your own `split()` and `get_path()`

---

## 🧠 Educational Notes

### Imperative Programming

Pipex teaches core Unix concepts like:

* File descriptors
* Process control
* Inter-process communication
* Executing binaries

Plus, you'll get better at debugging with:

* `strace ./pipex ...`
* `valgrind ./pipex ...`

---

## 🧵 Debugging Tip

Use these to see what’s happening behind the scenes:

```bash
valgrind ./pipex input "ls -l" "wc -l" output
strace ./pipex input "ls" "wc" output
```

---

## 🧼 Clean

```bash
make fclean
```

---

## 🧊 Sample Output

```bash
$ cat infile
hello
hi there

$ ./pipex infile "grep h" "wc -l" outfile

$ cat outfile
2
```

---

## 🌐 Resources

* [man execve](https://man7.org/linux/man-pages/man2/execve.2.html)
* [man pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
* [fork() visualizer](https://stackoverflow.com/questions/7346931/visual-explanation-of-fork-join)

---

## 💬 Final Words

This project is where you:

* Really understand how a shell works
* Learn the cost of forking badly
* Fall into `execve` segfault despair

But then... you emerge **stronger** 💪

---

<p align="center">
Made with 🍝, 🧠, and a little bit of crying by your local wizard.
</p>
```

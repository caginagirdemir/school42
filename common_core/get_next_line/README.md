# Get Next Line

This function return a line read from a file descriptor. 

Compile with 

```
gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

<img src="screenshot.png" />

Project Instructions 
  
| Specs  | Explanation |
| ------------- | ------------- |
| Prototype  | char *get_next_line(int fd); |
| Turn in files  | get_next_line.c, get_next_line_utils.c, get_next_line.h  |
| Parameters  |  fd: The file descriptor to read form  |
| Return value  |  **Read line** : correct behavior <br /> **NULL** : there is nothing else to read, or an error occured |
| External functs.  |  read, malloc, free |
| Description  |  Write a function that returns a line read from a file descriptor |

**Project Instructions**

- Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, **one line at a time**.
- Your function should return the line that was read. <br/> If there is nothing else to read or if an error occurred, it should return NULL.
- Make sure that your function works as expected both when reading a file and when reading from the standard input.
- **Please note** that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- Your header file get_next_line.h must at least contain the prototype of the get_next_line() function
- Add all the helper functions you need in the get_next_line_utils.c file.
- Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n <br/> It will define the buffer size for read(). <br/> The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
- You will compile your code as follows <br/> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c 
- We consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn't reach the end of file.
- We also consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn't reach the end of file.
- We also consider that get_next_line() has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.
  
**Forbidden**
  
- You are not allowed to use your libft in this project.
- lseek() is forbidden.
- Global variables are forbidden.
  
  
# Bonus Part
  
- Develop get_next_line() using only one static variable.
- Your get_next_line() can manage multiple file descriptors at the same time.
  

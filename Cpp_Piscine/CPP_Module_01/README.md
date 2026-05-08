# CPP Module 01

## Summary
- Exercise 00 : To understand that it's better to allocate the class on the stack or heap.
- Exercise 01 : To understand that N pieces class initilaze in a single allocation. 
- Exercise 02 : To understand that the differences between a pointer and a reference.

**Project Instructions**

<details>
  <summary>Exercise 00</summary>
  
  - ### Exercise 00
  
    First, implement a **Zombie** class. It has a string private attribute name.

    Add a member function ```void announce (void);``` to the Zombie class. Zombies announce themselves as follows:

    name: BraiiiiiinnnzzzZ...

    Then, implement the two following functions:

    ```Zombie* newZombie (std::string name);```

    It creates a zombie, name it, and return it so you can use it outside of the function scope.

    ```void randomChump (std::string name);```

    It creates a zombie, name it, and the zombie announces itself.

    Now, what is the actual point of the exercise? You have to determine in what case it's batter to allocate the zombies on the stack or heap.

    Zombies must be destroyed when you don't need them anymore. The destructor must print a message with the name of the zombie for debuggin purposes.
</details>

<details>
  <summary>Exercise 01</summary>
  
  - ### Exercise 01

    Time to create a horde of Zombies!

    Implement the following function in the appropriate file:

    ```Zombie* zombieHorde (int N, std::string name);```

    It must allocate N Zombie objects in a single  allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.

    Implement your own tests to ensure your ```zombieHorde()``` function works as expected. Try to call ```announce()``` for each one of the zombies.

    Don't forget to delete all the zombies and check for **memory leaks**.

 </details>

<details>
  <summary>Exercise 02</summary>
  
  - ### Exercise 02

    Write a program that contains:

    - A string variable initialized to "HI THIS IS BRAIN".
    - stringPTR: A pointer to the string.
    - stringREF: A reference to the string.

    Your program has to print:
    - The memory address of the string variable.
    - The memory address held by stringPTR.
    - The memory address address held by stringREF.
  
</details>

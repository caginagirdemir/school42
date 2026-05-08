# minitalk project

**Project Objectives** : to communicate between two program through signals. to understand bit-shifting, logical operations, kill funcs, signal redirects, and signals in linux. to learn signal func and sigaction func. Also I wrote a [article](https://medium.com/@cagina/cde-sinyaller-d63297fdc216) about signals in Turkish on Medium.

**Project Instructions**

  You must create a communication program in the form of a **client** and a **server**.

  - The server must be started first. After its launch, it has to print its PID.
  - The client takes two parameters:
    - The server PID.
    - The string to send.
  - The client must send the string passed as a parameter to the server. <br/> Once the string has been received, the server must print it.
  - The server has to display the string pretty quickly. Quickly means that if you think it takes too long, the it is probably too long.
  - Your server should be able to receive strings from several clients in a row without needing to restart.
  - The communication between your client and your server has to be done only using UNIX signals.
  - You can only use these two signals: **SIGUSR1** and **SIGUSR2**.


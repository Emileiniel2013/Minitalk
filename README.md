The project is composed out of two executables. "Server" and "Client". The server prints its own process Id and enters a waiting state, while the client takes two arguments, the process Id(PID) of the server and a string to pass to the server. The client deconstructs the message into binary, sending the signals SIGURS1 and SIGURS2, meaning 1 and 0, and the server takes the information and reconstructs the message. The bonus version send also an acknowledgment message back to the client, and after the receiving of the message the client prints a message signaling that the message has been succesfully received. Please run the make command wich will compile both the normal executables, but also the bonus ones. Enjoy! :)



Subject: https://cdn.intra.42.fr/pdf/pdf/118139/en.subject.pdf

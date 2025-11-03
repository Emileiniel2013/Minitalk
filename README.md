# Minitalk

Minitalk is a small yet powerful experiment in **inter-process communication (IPC)** using UNIX signals.  
It consists of two programs — a **server** and a **client** — that communicate by encoding text messages into binary data and transmitting them bit-by-bit via `SIGUSR1` and `SIGUSR2`.

This project demonstrates low-level communication techniques and precise signal handling without relying on any external libraries or sockets.
---
## ⚙️ Features
- Two independent executables: `server` and `client`
- Communication via `SIGUSR1` and `SIGUSR2` signals
- Message encoding and decoding at the **bit** level
- Acknowledgment system (bonus) confirming message delivery
- Robust error handling and graceful exits
---
## 🧩 How to Run

### 1. Build both programs
```bash
make
```
2. Start the server
```bash
./server
```
It will print its Process ID (PID) and wait for incoming messages.

3. Send a message from the client (in a different terminal window)
```bash
./client <server_pid> "Hello, world!"
```
The client converts the string into binary, sends it one bit at a time using SIGUSR1 (for 1) and SIGUSR2 (for 0), and the server reconstructs the message.
The bonus executables (server_bonus and client_bonus) add acknowledgment signals — the client prints a confirmation once the message is successfully received by the server.

---
🧠 Technical Details

-Written in C (C99)

-Uses UNIX signal API: kill(), signal(), pause(), and usleep()

-Bitwise operations for encoding and decoding messages

-No shared memory or sockets used — pure signal-based communication

-Fully asynchronous message passing

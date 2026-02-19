# Contact-List-in-C
## 📒 Contact List Manager in C

A **console-based Contact List Manager written in C** designed to strengthen core programming skills such as:

* File handling
* Structs and memory management
* String parsing
* Modular project structure
* Function pointers

This project was built as part of my preparation for **Computer Engineering**, focusing on building a strong foundation in **C for embedded systems and robotics**.

---

## 🚀 Features

✔ Add new contacts

✔ List all contacts

✔ Search contact by name

✔ Remove contact

✔ Change contact phone number

✔ Data persistence using file storage

✔ Modular code organization

✔ Function pointer menu system


---

## 🧠 What I Learned

This project helped me practice important C concepts used in low-level and embedded development:

* Using `struct` to organize data
* Dynamic memory allocation with `malloc` and `free`
* File I/O using `fopen`, `fprintf`, `fgets`
* String parsing with `strtok`
* Error handling with file operations
* Using function pointers instead of large `switch` statements
* Modular architecture with `.h` and `.c` files

---

## 📂 Project Structure

- main.c        -> Menu and program flow
- contact.h     -> Struct and function prototypes
- contact.c     -> Contact management implementation
- contactList.txt -> Stored contacts (created automatically)


---

## ⚙️ How to Compile and Run

Using GCC:

```
gcc main.c contact.c -o contacts
./contacts
```
---

## 🖥️ Example Usage

```
---OPTIONS---
[1] Add Contact
[2] Print Contacts
[3] Print Specific Contact
[4] Remove Contact
[5] Change a Contact Number
[6] Exit
```

Stored format in file:

```
Name-Number-Email
```

---

## 📈 Future Improvements

Planned upgrades to make the project more advanced:

* [ ] Support names with spaces
* [ ] Sort contacts alphabetically
* [ ] Better input validation
* [ ] Search by phone/email
* [ ] SDL graphical interface version
* [ ] Unit tests

---

## 🎯 Why This Project Matters

This project is part of my portfolio to demonstrate:

* Strong C fundamentals
* Clean modular code
* Understanding of memory and files
* Preparation for embedded systems and robotics

It shows the ability to design small systems from scratch

---

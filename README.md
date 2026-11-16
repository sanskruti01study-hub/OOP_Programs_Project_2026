# Object-Oriented Programming (OOP) Practical Lab & Mini-Project

[![Deploy with Vercel](https://vercel.com/button)](https://vercel.com/new/clone?repository-url=https://github.com/sanskruti01study-hub/OOP-Programs-Project)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Platform](https://img.shields.io/badge/Deploy-Vercel-black?logo=vercel)
![Status](https://img.shields.io/badge/Status-Completed-success)

A curated collection of C++ Object-Oriented Programming practicals, complete with syntax extensions, a comprehensive hospital management mini-project (**CAREPASS**), and a web-based interactive showcase ready for deployment on **Vercel**.

---

## 🚀 Live Web Showcase & Vercel Deployment

This repository is pre-configured for instant zero-configuration deployment on **Vercel**:
- **Interactive Web Portal**: Explore source code, terminal outputs, and interactive simulators for each experiment directly in your browser.
- **`vercel.json`**: Pre-configured static deployment file for seamless hosting on Vercel's global edge network.

To deploy your own instance to Vercel:
1. Click the **Deploy with Vercel** button above or import this repository on [Vercel](https://vercel.com).
2. Keep the default settings (Framework Preset: **Other**, Root Directory: `./`).
3. Click **Deploy**.

---

## 📂 Repository Contents & Experiments

All program files now carry standard `.cpp` extensions and clean, standard-compliant C++ code:

| File | Title | Core OOP Concept | Description |
| :--- | :--- | :--- | :--- |
| [`Experiment-1.cpp`](./Experiment-1.cpp) | **Basic Syntax & Data Types** | Foundations | Demonstration of primitive types (`int`, `float`, `char`, `bool`), standard stream operations (`cout`, `endl`), and arithmetic operations. |
| [`Experiment-2.cpp`](./Experiment-2.cpp) | **Classes & Objects** | Encapsulation | Definition of a `vehicle` class, data encapsulation with `private` members, and `public` getter/setter methods. |
| [`Experiment-3.cpp`](./Experiment-3.cpp) | **Constructors in C++** | Object Initialization | Implementation of Default Constructor, Parameterized Constructor, and Copy Constructor in a `Student` class. |
| [`Experiment-5.cpp`](./Experiment-5.cpp) | **Inheritance Hierarchy** | Single & Multilevel | Demonstrates `Person` (Base) $\rightarrow$ `Student` (Single Derived) $\rightarrow$ `GraduateStudent` (Multilevel Derived). |
| [`Experiment-6.cpp`](./Experiment-6.cpp) | **Virtual Polymorphism** | Abstract Classes | Pure virtual function `virtual void area() = 0` in an abstract `Shape` base class overridden by `Circle`, `Rectangle`, and `Triangle`. |
| [`Experiment-7.cpp`](./Experiment-7.cpp) | **Operator Overloading** | Polymorphism | Overloading binary operators `+` and `*` for arithmetic manipulation of `Complex` numbers. |
| [`Experiment-9.cpp`](./Experiment-9.cpp) | **Class Templates** | Generic Programming | Template-based generic LIFO Stack (`Stack<T>`) supporting arbitrary data types with push, pop, and boundary checks. |
| [`Mini-Project.cpp`](./Mini-Project.cpp) | **CAREPASS: Hospital Management** | Comprehensive System | Full hospital management CLI featuring patient registration, status updates, search, and persistent file storage (`ofstream`). |

---

## 🛠️ How to Compile & Run Locally

Ensure you have a C++ compiler (`g++` or `clang++`) installed:

### On Linux / macOS / MinGW:
```bash
# Compile any experiment (e.g., Experiment-1.cpp)
g++ -std=c++17 -o app Experiment-1.cpp

# Execute
./app
```

### On Windows (PowerShell / Command Prompt):
```powershell
# Compile
g++ -std=c++17 -o app.exe Experiment-1.cpp

# Execute
.\app.exe
```

### Running the Mini-Project:
```bash
g++ -std=c++17 -o carepass Mini-Project.cpp
./carepass
```

---

## 🌐 Local Web Preview

To preview the interactive web showcase locally before or alongside Vercel deployment:
- Simply open [`index.html`](./index.html) in any modern web browser, or
- Run a lightweight static server:
  ```bash
  npx serve .
  # or
  python -m http.server 3000
  ```

---

## 👤 Author
- **Sanskruti Renuse** ([@sanskruti01study-hub](https://github.com/sanskruti01study-hub))

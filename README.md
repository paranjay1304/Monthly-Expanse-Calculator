# Monthly-Expanse-Calculator
# Personal Finance & Expense Predictor

A lightweight, terminal-based financial assistant written in C. Unlike basic logging applications, this tool tracks daily expenditures and applies mathematical logic to project end-of-month spending habits, warning users if they are on track to exceed their budget.

## 🚀 Key Features
* **Dynamic Budget Tracking:** Set a monthly allowance and log expenses across custom categories (Food, Transport, Entertainment, etc.).
* **Smart Financial Forecasting:** Computes your daily burn rate ($ \text{Daily Average} = \frac{\text{Total Spent}}{\text{Current Day}} $) to project total monthly expenditure.
* **Proactive Alerts:** Automatically warns the user if their current spending trajectory will breach their budget, calculating the exact day they risk running out of funds.
* **Interactive CLI Menu:** A clean, loop-driven command-line interface for easy navigation.
* *[Optional: Add this if you implemented saving files]* **Persistent Storage:** Saves and loads transactional data via File I/O using `.txt`/`.csv` files.

## 🛠️ Concepts & Skills Practiced
* **Data Structuring:** Utilized C structures (`struct`) to group complex expense datasets.
* **Memory & String Manipulation:** Handled dynamic string matching using `<string.h>` for category-wise segregation.
* **Algorithmic Logic:** Developed forecasting logic using floating-point arithmetic.
* **Code Modularity:** Structured the project across multiple functions to ensure clean, maintainable, and readable code.

## 💻 How to Run This Project

### Prerequisites
You need a C compiler (like `gcc`) installed on your system.

### Steps
1. Clone this repository to your local machine:
   ```bash
   git clone [https://github.com/paranjay1304/Monthly-Expanse-Calculator.git](https://github.com/paranjay1304/Monthly-Expanse-Calculator.git)

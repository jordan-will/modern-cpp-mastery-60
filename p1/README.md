
# Exercise 01 — Sensor Data Analyzer

Level 2 — Integration

Block 1 · Exercise 1/3

Tempo estimado: 20–25 minutos

### 1. Assuntos de C++ abordados

- Variables, data types and operators.
- Conditional statements.
- Loops.
- Functions and parameters.
- `std::array`.
- `std::string`.
- Enums.

### 2. Context

An embedded system collects temperature readings from a sensor. You must develop a small C++ program capable of analyzing these readings and generating a diagnostic report.

### 3. Requirements

1. Work with a fixed collection of 10 temperature readings.
2. Store the readings using an appropriate data structure.
3. Calculate:
   - Minimum temperature.
   - Maximum temperature.
   - Average temperature.
4. Count how many readings are:
   - Within the operating range.
   - Above the operating range.
   - Below the operating range.
5. Classify the sensor's overall condition using an `enum`.
6. Display an organized diagnostic report.

### 4. Constraints

- Use `std::array` to store the readings.
- Use functions to separate the main operations.
- Use an `enum` to represent the sensor condition.
- Define configurable minimum and maximum operating temperatures.
- Avoid unnecessary code duplication.
- Do not use external libraries.

### 5. Acceptance Criteria

Your implementation must:

- Correctly calculate all statistical values.
- Correctly classify readings, including boundary values.
- Correctly determine the sensor's overall condition.
- Present readable and organized output.
- Use appropriate data types and function responsibilities.

### 6. Modification — After initial validation

Once the original implementation is complete, we will introduce a new operational classification without unnecessarily rewriting the analysis logic.


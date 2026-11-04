# Exercise 03 — Telemetry Data Collector

Level 2 — Integration

Block 01 · Exercise 03

## 1. C++ topics

Os principais assuntos envolvidos serão:

| Área                        | Conteúdos                                                 |
| --------------------------- | --------------------------------------------------------- |
| Data modeling               | `struct`, `class`, enums                                  |
| Object-oriented programming | Encapsulation, constructors, member functions             |
| STL containers              | `std::vector`                                             |
| STL algorithms              | `std::minmax_element`, `std::count_if`, `std::accumulate` |
| Modern C++                  | Lambdas, `auto`, `const` correctness                      |
| Error handling              | Exceptions                                                |
| Software organization       | Headers, source files, separation of responsibilities     |

## 2. Context

An IoT monitoring station receives telemetry readings from multiple sensors.

Each reading contains information about its origin, measurement type and measured value.

Your task is to develop a small telemetry collection system capable of storing readings, validating incoming data and providing aggregated information about the collected measurements.

Unlike the previous exercise, the system must support a dynamically sized collection of readings.

## 3. Requirements

### A. Data modeling

Create an appropriate representation for a telemetry reading.

Each reading must contain:

- Sensor ID.
- Sensor type.
- Measured value.

The system must support at least three sensor types:

- Temperature.
- Humidity.
- Pressure.

Use an enumeration to represent sensor types.

### B. Telemetry collection

Implement a component responsible for managing the collected readings.

It must support:

1. Adding a new telemetry reading.
2. Retrieving the total number of stored readings.
3. Counting readings belonging to a specific sensor type.
4. Calculating statistics for a specific sensor type.

### C. Statistics

For a requested sensor type, the system must calculate:

- Number of readings.
- Minimum value.
- Maximum value.
- Average value.

The calculations must consider only readings belonging to the requested sensor type.

### D. Validation

The system must reject:

- Readings with an empty sensor ID.
- Readings with invalid numerical values, such as NaN or infinity.
- Statistics requests for sensor types that have no recorded readings.

Use appropriate exception types to communicate invalid arguments and invalid operations.

### E. Presentation

Create a separate presentation component responsible for displaying:

- Total number of collected readings.
- Number of readings for each sensor type.
- Statistics for each sensor type that has available readings.

The collection component must not be responsible for printing information to the terminal.

## 4. Acceptance criteria

Your implementation should demonstrate:

| Criterion              | Expected behavior                                  |
| ---------------------- | -------------------------------------------------- |
| Dynamic storage        | Accept a variable number of readings               |
| Data modeling          | Represent readings and statistics appropriately    |
| Encapsulation          | Keep collection management details private         |
| Validation             | Reject invalid readings                            |
| Filtering              | Distinguish sensor types correctly                 |
| Aggregation            | Calculate accurate statistics                      |
| Separation of concerns | Keep presentation outside the collection component |
| Error handling         | Handle invalid operations appropriately            |

## 5. Constraints

- Use C++20.
- Use `std::vector` for dynamic storage.
- Prefer STL algorithms where appropriate.
- Avoid unnecessary inheritance and design patterns.
- Organize the project into headers and source files.
- Do not use external libraries.

Important: These are requirements, not implementation instructions. You should decide how many classes and structures are necessary, which methods they expose, how statistics are represented and how the components interact.

## 6. Expected workflow

1. Model the data structures and classes.
2. Define the public interfaces in the headers.
3. Implement the collection and its validation rules.
4. Implement the presentation component.
5. Create `main.cpp` with representative test scenarios.
6. Compile with `-Wall -Wextra -Wpedantic`.
7. Validate the results.


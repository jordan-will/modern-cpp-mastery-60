# Exercise 02 — Device Configuration Manager

Level 2 — Integration

Block 1 · Exercise 2/3

Tempo estimado: 25–30 minutos

## 1. Assuntos de C++ abordados

- Structs and classes.
- Encapsulation.
- Constructors.
- Member functions.
- `std::string`.
- Enums (`enum class`).
- Conditional statements.
- Functions.
- `const` correctness.

## 2. Context

An IoT device requires a configuration system to manage its operational parameters.

The device has an identifier, a transmission interval, an operating mode, and an operational status.

Your task is to develop a small C++ application that manages these configurations and ensures their validity.

## 3. Requirements

Device configuration

The device must contain:

| Attribute             | Description                           |
| --------------------- | ------------------------------------- |
| Device ID             | Unique textual identifier             |
| Transmission Interval | Data transmission interval in seconds |
| Operating Mode        | Current operational mode              |
| Device Status         | Active or inactive                    |

Configuration management

Implement functionality to:

1. Initialize a device with its configuration.
2. Retrieve its current configuration.
3. Change its transmission interval.
4. Change its operating mode.
5. Activate the device.
6. Deactivate the device.
7. Display its current configuration.

Validation

- Device ID cannot be empty.
- Transmission interval must be between 1 and 3600 seconds.
- Invalid configuration changes must be rejected.
- The device must start in an inactive state.

## 4. Acceptance Criteria

- Encapsulate the device's internal attributes.
- Use appropriate constructors.
- Use enums to represent operating modes and device status.
- Separate configuration management from presentation.
- Ensure invalid values cannot corrupt the device configuration.
- Provide clear feedback when an operation succeeds or fails.

## 5. Modification — After initial validation

Introduce the following additional requirement:

An active device must not allow configuration changes.

The device must first be deactivated before its transmission interval or operating mode can be modified.

## 6. Your task

Begin with problem analysis and solution modeling.

Consider:

- Which class or classes are necessary?
- Which attributes should be private?
- Which operations should be public?
- Which information should be represented by enums?
- How should invalid operations be handled?

You may consult your notes and official documentation.


University Management System
A clean and modern desktop application built in C++ using the Qt6 framework. This project implements a fully decoupled, layered architecture to manage student academic records.

Architecture & Clean Code
The project is structured according to the Layered Architecture pattern, ensuring a strict separation of concerns:

Domain: Simple entities representing the core models (Student).

Repository: Handles data persistence and acts as an in-memory collection.

Service (Business Logic): Validates user inputs and coordinates operations between the UI and Repository.

GUI (Presentation): A modern, native desktop interface powered by Qt6.

Features Implemented
Data Persistence: Automatic serialization and deserialization of student data to/from CSV files.

Automated Testing: A dedicated suite of unit tests running automatically via assert statements at application startup to validate core repository and business logic.

Interactive GUI:

View all registered students dynamically.

Add new students with validation.

Add grades (1-10) and calculate real-time averages.

Remove students dynamically from the database.

Active Development & Roadmap
!!!!!!
This project is currently under active development. I am working on extending its capabilities with the following advanced features:

Live Filtering: Add a real-time search bar to filter the student list dynamically as you type.

Advanced Sorting: Implement dynamic multi-criteria sorting (by average grade or alphabetical order) directly from the GUI.

Undo/Redo Actions: Implement the Command Design Pattern to allow reverting and redoing database changes.

Custom Exceptions: Refactor error handling with specialized custom exceptions (ValidationException, RepositoryException).

Tech Stack
Language: C++17

GUI Framework: Qt6

Build System: CMake

Environment: CLion on macOS (Apple Silicon native)

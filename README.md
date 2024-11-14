# Nitro C++ Proficiency test

## Overview
This Repository contains the source code for an executable that receives a json file with rectangle coordinates
and calculates all intersections between these rectangles. The repo also contains a test for the classes used,
several json files used for testing, a PDF file detailing the task and this readme, whose main purpose is
detailing the compilation and execution process of the project.

## Author
This project was developed by **Johannes Portz Dias**.  

## Dependencies
- **JSON for Modern C++**: [Github link](https://github.com/nlohmann/json).
- **acutest: Simple header-only C/C++ unit testing facility**: [Github link](https://github.com/mity/acutest).

## Building the Project
1. Navigate to the project directory:
    ```bash
    cd NitroCppTest-JohannesPortzDias
    ```
2. Build the project:
    ```bash
    make
    ```

### Running the Project
```bash
./build/exec "input.json"
```

## Building the Test
1. Navigate to the project directory:
    ```bash
    cd NitroCppTest-JohannesPortzDias
    ```
2. Build the test:
    ```bash
    make test
    ```

### Running the Test
```bash
./build/test
```


OpenVM Bytecode Runtime
=======================

The OpenVM Bytecode Runtime is a C++ library designed for executing OpenVM bytecode. This document provides instructions on how to include and use the library in your own projects.

Table of Contents
-----------------

*   [Features](#features)
*   [Requirements](#requirements)
*   [Installation](#installation)
    *   [Option 1: Manual Installation](#option-1-manual-installation)
    *   [Option 2: FetchContent](#option-2-fetchcontent)
*   [Usage](#usage)
*   [CMake Integration](#cmake-integration)
*   [License](#license)

Features
--------

*   Execute OpenVM bytecode efficiently.
*   Easy integration with existing CMake projects.

Requirements
------------

*   CMake version 3.14 or higher
*   C++20 compliant compiler

Installation
------------

### Option 1: Manual Installation

1.  **Download the Library:** You can download the precompiled ZIP package from the releases section of this repository or build it from source.
2.  **Extract the ZIP file:** After downloading, extract the contents of the ZIP file. You should see the following structure:
    
                OpenVM-Bytecode-Runtime/
                ├── include/
                │   └── OpenVMBytecodeRuntime/
                │       └── \[Header files\]
                └── lib/
                    └── libOpenVMBytecodeRuntime.a
                
    
3.  **Include the Library in Your Project:** Copy the `include` and `lib` directories into your project's directory.

### Option 2: FetchContent

If you prefer to use FetchContent to include the library directly from the repository, follow these steps:

1.  **Add FetchContent to Your CMakeLists.txt:**
    
    cmake\_minimum\_required(VERSION 3.14)
    project(MyProject)
    
    # Specify the C++ standard
    set(CMAKE\_CXX\_STANDARD 20)
    
    # Include FetchContent
    include(FetchContent)
    
    # Fetch the OpenVM Bytecode Runtime
    FetchContent\_Declare(
        OpenVMBytecodeRuntime
        GIT\_REPOSITORY https://github.com/your\_username/OpenVM-Bytecode-Runtime.git
        GIT\_TAG main # or a specific tag/commit
    )
    
    # Make the content available
    FetchContent\_MakeAvailable(OpenVMBytecodeRuntime)
    
    # Add your executable
    add\_executable(my\_program my\_program.cpp)
    
    # Link the OpenVM Bytecode Runtime library
    target\_link\_libraries(my\_program PRIVATE The\_OpenVM\_Project::OpenVMBytecodeRuntime)
                
    

Usage
-----

### 1\. Include the Header Files

In your source files, include the library header:

#include <OpenVMBytecodeRuntime/openvm\_runtime.h>
    

### 2\. Link Against the Library

When compiling your project, ensure you link against the `libOpenVMBytecodeRuntime.a` library (for manual installation). For example, if you are using g++, you can compile your code as follows:

g++ -o my\_program my\_program.cpp -L./lib -lOpenVMBytecodeRuntime
    

CMake Integration
-----------------

To include the OpenVM Bytecode Runtime library in your CMake project, follow these steps:

1.  **Using Manual Installation:** Follow the manual installation instructions above to include the library and link it.
2.  **Using FetchContent:** Follow the FetchContent instructions above to include the library automatically.

License
-------

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

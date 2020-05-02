# Account Management and Ledger Generator



## 1. Install the Prerequisites

Before you build and run, you'll need to [install the prerequisites](https://docs.ultralig.ht/docs/installing-prerequisites) for your platform.

## 2. Clone and build the app

To clone the repo and build, run the following:

```shell
git clone https://github.com/vinayvinu9876/AccountManager-Co-Sequential-Processing-.git
cd AccountManager-Co-Sequential-Processing-
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

> **Note**: _To force CMake to generate 64-bit projects on Windows, use `cmake .. -DCMAKE_GENERATOR_PLATFORM=x64` instead of `cmake ..`_

## 3. Run the app

### On macOS and Linux

Navigate to `AccountManager-Co-Sequential-Processing-/build` and run `MyApp` to launch the program.

### On Windows

Navigate to `AccountManager-Co-Sequential-Processing-/build/Release` and run `MyApp` to launch the program.



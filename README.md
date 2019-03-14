# CL-server
The java server of the map app

The server has to call the core to give the front the necessary ressources

# Installation Guide

You'll need `java`, `cmake` and `maven` to compile this program.

It uses JNI which means you'll to compile the C++ code to a library.

## Linux instructions

The project uses `CMake`. You just need to create a `build/` directory then go into it and execute `cmake ..` 
followed by `make`.

```shell
mkdir build
cd build/
cmake ..
make
```

After that you'll find the libraries generated in `build/lib`. The `libserver.so` is the lib to be used with 
the Java server.

## Windows instructions

`CMake` is cross platform so it should work on Windows too.

# Native code

The native C++ code in this repository is a proof of concept to show how to 
implement the native method in our `JniDirectionService`. In the end the real C++
implementation of the native mehod calls will be located in the [CL-core]() 
repository.

# Running the server

To be able to run the server you **NEED** to have compiled the shared library implementing the 
method declared in `JniDirectionService`.

Then you can create the executable jar using `mvn clean pacakge`. The output will be an executable
JAR named like this : `server-X.X.X-SNAPSHOT`.

You can then execute it with 
`java -Djava.library.path=/path/to/the/library/ -jar server-X.X.X-SNAPSHOT.jar`.

The `-Djava.library.path` is used to specify the directory which contains the library.

# Calling java methods from C++

You need to get the descriptor string of the method. You can get it easily with `javap -s -p target/my/compiled/class`.
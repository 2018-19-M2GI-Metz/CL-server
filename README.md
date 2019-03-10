# CL-server
The java server of the map app

The server has to call the core to give the front the necessary ressources

# Installation Guide

You'll need `java` and `maven` to compile this program.

It uses JNI which means you'll to compile the C++ code to a library.

## Linux instructions

A `create-native-lib.sh` script is available to create the native library on a GNU/Linux system (Debian, Fedora, ...).

It creates the JNI header in `src/native` and compiles the `testjni.cpp` file in
`src/native` too. The output of this script is a shared library called `libmap.so`
located in  `lib/`.

Note that some paths in this script are hard coded, like the path to the necessary
Spring Framework JAR file. You may have to tweak it a little bit to make it work
on your system.

## Windows instructions

According to [this website](https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html) the command to compile the library on Windows systems
is `x86_64-w64-mingw32-gcc -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -shared -o hello.dll HelloJNI.c`

It needs MinGW, for more information on that look on to the website linked earlier.

# Native code

The native C++ code in this repository is a proof of concept to show how to 
implement the native method in our `JniDirectionService`. In the end the real C++
implementation of the native mehod calls will be located in the [CL-core]() 
repository.

When that happens the script to build the library will have to be modified to 
compile the code in the CL-core repository, or you could also manually compile it
and place the resulting library in the `lib/` folder.

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
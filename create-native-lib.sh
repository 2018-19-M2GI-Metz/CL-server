#/bin/bash

echo 'Generating the C++ header file.';

javac -h src/native/ -classpath ~/.m2/repository/org/springframework/spring-context/5.1.2.RELEASE/spring-context-5.1.2.RELEASE.jar src/main/java/fr/mim/cl/server/services/JniDirectionService.java src/main/java/fr/mim/cl/server/model/*.java src/main/java/fr/mim/cl/server/services/DirectionService.java -d target/

echo 'Compiling the library.';

g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o lib/libmap.so src/native/*.cpp src/native/core/*.cpp core/src/core/API/interface.cpp core/src/core/API/interface.hpp

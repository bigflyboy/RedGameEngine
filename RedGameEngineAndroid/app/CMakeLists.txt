# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library(
             redgameengine

             SHARED

             src/main/cpp/interface.cpp

             src/main/cpp/RedEngine/Shader/ShaderProgram.cpp
             src/main/cpp/RedEngine/Shader/Shader.cpp

             src/main/cpp/RedEngine/File/AssetFile.cpp

             src/main/cpp/SOIL/SOIL.c
             src/main/cpp/SOIL/image_DXT.c
             src/main/cpp/SOIL/image_helper.c
             src/main/cpp/SOIL/stb_image_aug.c
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       redgameengine

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
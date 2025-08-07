# Setup

1 - Run 

    cmake -B build -G "Ninja Multi-Config"

this will produce build files for your current platform.


2 - Run

    cmake --build build --config Debug

Runs the build system created previously, and creates the executable. 
`build` is the folder where these will be placed.
`--config Debug` tells cmake create a Debug build. This needs to be specified because we set the Ninja generator to be
Multi-Config, which gives us the option to create "Debug", "Release" and "RelWithDebInfo" builds.


3 - Run 

    ./build/Debug/raylib-template

to run the executable we just created.

# Useful Links

[Raylib's Github](https://github.com/raysan5/raylib)

[Raylib's Examples](https://www.raylib.com/examples.html)



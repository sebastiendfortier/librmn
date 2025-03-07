# Empty preset file to satisfy the include() in ec_compiler_presets.cmake
# This bypasses the error about missing compiler presets

message(STATUS "(EC) Using mock compiler preset for gnu-14.2.0")

# Set minimal compiler flags
set(CMAKE_C_FLAGS "-O2" CACHE STRING "C compiler flags" FORCE)
set(CMAKE_Fortran_FLAGS "-O2" CACHE STRING "Fortran compiler flags" FORCE) 

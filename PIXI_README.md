# librmn with Pixi and Rattler-build

This README explains how to use the added pixi.toml and rattler-build recipe for librmn.

## Project Structure

This project builds two libraries:

1. **libApp** - A support library that provides core functionality
2. **librmn** - The main RPN library that depends on libApp

The build process automatically compiles libApp first before building librmn.

## Build Configuration

The build system uses the following settings:

1. **OpenMP Support**: OpenMP is disabled with both `-DWITH_OPENMP=no` and `-DWITH_OMPI=OFF`
2. **Compiler Settings**: Uses GNU compilers with Release build type
3. **Installation**: Libraries are installed into the `install` directory
4. **Custom Modules**: Uses custom FindOpenMP.cmake and compiler preset files to work around missing dependencies

## Prerequisites

- [Pixi](https://github.com/prefix-dev/pixi) for environment management
- [Rattler-build](https://github.com/prefix-dev/rattler-build) for package building (optional, only for packaging)

## Using Pixi for Development

### Setup Environment

```bash
# Initialize the pixi environment
pixi install

# IMPORTANT: Unset EC_ARCH if it's set in your environment
unset EC_ARCH
```

### Build Commands

```bash
# Configure, build, and install in one command
pixi run all

# Or run each step individually
pixi run configure  # Create build directory
pixi run cmake      # Run CMake configuration
pixi run build      # Compile the code
pixi run install    # Install the binaries

# Generate documentation (requires doxygen)
pixi run doc
```

## Build System Compatibility

This build configuration has been tested in:
- Ubuntu 16.04 container with packages: software-properties-common, build-essential, gfortran, libopenmpi-dev, libssl-dev

## Troubleshooting

If you encounter build errors:

1. **EC_ARCH environment variable**: Make sure to unset this variable with `unset EC_ARCH` before building
2. **Missing ECCC compiler presets**: The build includes mock compiler preset files to bypass this issue
3. **OpenMP detection failures**: We've included a custom FindOpenMP.cmake that returns "success" without actually enabling OpenMP
4. **Submodule initialization**: Make sure git submodules are initialized with `git submodule update --init --recursive`

## Using Rattler-build for Packaging

Rattler-build uses the modern recipe.yaml and variants.yaml files instead of the traditional conda-build format. This recipe is configured to build **only for Linux (linux-64)**.

### Build the Package

```bash
# Make sure EC_ARCH is unset
unset EC_ARCH

# Build the package using rattler-build
rattler-build build --recipe ./recipe.yaml

# Or with specific options
rattler-build build --recipe ./recipe.yaml --output-dir ./dist
```

### Package Installation

The built package can be installed with conda, mamba, or pixi:

```bash
# Using conda
conda install -c ./dist eccc_librmn

# Using mamba
mamba install -c ./dist eccc_librmn

# Using pixi
pixi add eccc_librmn --channel ./dist
```

## Output Libraries

After the build process completes, you should have:

1. `libApp.so` and `libApp.a` - The App support library
2. `librmn.so` and `librmn.a` - The main RPN library

## Dependencies

The following dependencies are managed by pixi:

- gcc/gfortran - C and Fortran compilers
- cmake (>=3.20.0) - Build system
- make - Build tool
- OpenMPI - For parallel processing
- git - For submodule handling

## Custom Build Options

You can modify the build options by editing:
- The pixi.toml file's `[tasks]` section for development
- The recipe.yaml and variants.yaml files for package building

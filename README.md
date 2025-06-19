# Raster Graphics

A C++ raster graphics processor supporting common image formats and operations, designed with modularity and extensibility in mind.

---

## Overview

This project provides a suite of classes and commands to load, manipulate, and save raster images in the following formats:

- **PPM** (Portable Pixmap)
- **PGM** (Portable Graymap)
- **PBM** (Portable Bitmap)

It features core image processing operations such as:

- Grayscale conversion
- Monochrome (black & white) conversion
- Negative (color inversion)
- Rotation (clockwise and counterclockwise)
- Flipping (horizontal and vertical)

The design is object-oriented, employing:

- Abstract base classes for images and commands
- Command pattern for applying and undoing operations
- Session management for handling multiple image editing sessions

---

## Features

- Load and save PPM, PGM, and PBM images
- Perform common image transformations and filters
- Undo/redo support for image commands
- Command factory for extensible command creation
- Session management to isolate multiple image workflows
- Doxygen-generated documentation including class diagrams and inheritance graphs

---

## Build and Documentation

- Use CMake to configure and build the library
- Generate HTML documentation using Doxygen
- Documentation includes detailed API reference and diagrams

---

## Getting Started

1. Clone the repository
2. Run `cmake -S . -B build`
3. Build the project: `cmake --build build`
4. Open the documentation at `build/html/index.html`

## Tested Environment

---

- **Operating System:** Ubuntu (x86_64-linux-gnu)
- **Compiler:** GCC 13.3.0

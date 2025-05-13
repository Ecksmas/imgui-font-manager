# ImGui Font Manager

A modular font manager for Dear ImGui, which was created for the need to be able to load different font across several files and organise and centralise font creation.

## Overview

Dear ImGui offers basic font support, but lacks a built-in font management system. Fonts must be loaded abd referenced by pointers or index, which can quickly become a messy affair in larger projects.

This project introduces a **singleton-based Font Manager** to centralise font loading and ease of access by referencing the font directly like "notoSansNormal" or "notoSansBold".

The project includes:
- A "FontSingleton" that loads and store ImGui fonts.
- An interactive demo that lets the user switch between two fonts.
- A clean setup using modern C++17 and CMake.

## Purpose

The purpose of creating this code was to create something that can be used when creating ImGui projects that heavly use different styling on their text. Additionally, it was created to demostrate and improve my knowledge of singleton patterns and testing.

### `FontSingleton`
A singleton class that:
- Loads font from `.ttf` files during startup
- Stores them in a `std::unordered_map<std::string, ImFont*>`
- Provides a simple API:

```cpp
ImGui::PushFont(FontSingleton::getInstance().getFont(currentFont));
ImGui::Text("Your text!");
ImGui::PopFont();

## Testing

Doctest is used in the testing of the project, some simple test to check that everything is running correctly.

To run tests:
- cd build
- ./runTests
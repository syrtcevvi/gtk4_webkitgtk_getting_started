# Gtk4 WebKitGtk Getting started

![Gtk4 WebKitGtk Getting started main window image](docs/images/application_main_window.png)

> TODO have a look at the **tutorial.md**

## 0. Checked platforms

This tiny example have been checked on the: 
- **Ubuntu 22.04** 
- **Ubuntu 24.04**

The newer versions allow us to slightly expand the functionality of this application.

> Probably, this project will compile without troubles on other **unix-like** platforms too, but there can be pitfalls.

## 1. Install prerequisites
```bash
sudo apt install libgtk-4-dev libadwaita-1-dev libwebkitgtk-6.0-dev -y
```

### 2. Verify that pkg-config can found required packages

> \> symbol shows the output of the previously executed command, don't type it.

**Ubuntu 22.04**:
```
pkg-config gtk4 --modversion
> 4.6.9
pkg-config libadwaita-1 --modversion
> 1.1.7
pkg-config webkitgtk-6.0 --modversion
> 2.48.3
```

**Ubuntu 24.04**:
```
pkg-config gtk4 --modversion
> 4.14.2
pkg-config libadwaita-1 --modversion
> 1.5.0
pkg-config webkitgtk-6.0 --modversion
> 2.48.3
```

Also you can check your **glib-2.0** version. If **glib-2.0** version <= 2.74, there will be slightly changes in the **main.c**:
```
pkg-config glib-2.0 --modversion
> 2.72.4 # Here is what I get on the Ubuntu 22.04
> 2.80.2 # Ubuntu 24.04
```

> Btw, we could use the latest versions of the **gtk4** and **libadwaita-1** by compiling everything from the source, but it's a
bit hard (there're plenty of things to compile). Currently we will use the available development packages.

### 3. Build the project

We use the **CMake** to build this project, however the usual tool for the **gtk4** environment is **meson**. Maybe later I will add the **meson.build** file.

I use **VSCode** to make this project and some **CMake** extension (pick up the most popular one).

You need to change the **current working directory** to the project root and execute one of the following sequences:

#### 3.1 For Debug build
```
cmake -B build/debug -S .
cmake --build build/debug --config Debug
```

#### 3.2 For Release build
```
cmake -B build/release -S .
cmake --build build/release --config Release
```
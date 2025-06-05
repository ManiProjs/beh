# _beh_

_beh_ (**B**etter `feh`) is a lightweight, cross-platform image viewer and an alternative to `feh`

It's supposes to be lightweight, cross-platform, free, open-source and easy to use, just takes a image path

It doesn't need 

_Psst, you can open a image with the most hated image format (WebP) with it_

[![alt text](//beh_preview.mp4)](beh_preview.mp4)

## Installation

### Windows

Prebuilt releases are avaliable at [Releases](https://github.com/ManiProjs/beh/releases) page

It will be published to Winget and Scoop and maybe, Chocolatey soon.

### Mac

You can use Homebrew (not ready yet):

```shell
brew install
```

### Linux

[Build it from source](#build-from-source)

## Build from source

### Requirements

#### For all system

- [CMake](https://cmake.org/download)
- [SFML](https://sfml-dev.org)
- [libwebp](https://developers.google.com/speed/webp/download) for reading WebP files (optional, `beh` can be compiled without it, but without support for WebP)
- A build system such as [Make](http://www.gnu.org/software/make/) or [Ninja](https://ninja-build.org/)
- [Git](https://git-scm.com)

#### Windows

- [Visual Studio Build Tools](https://aka.ms/vs/17/release/vs_BuildTools.exe) in order to build (You can use Visual Studio, too but it's not required if you don't use the IDE itself)

#### Mac

- [Xcode Command-line Tools](https://developer.apple.com/download/all/?q=Command%20Line%20Tools%20for%20Xcode) (You must log in to your Apple Account (formerly Apple ID) in order to download the software)
- [Homebrew](https://brew.sh)

#### Linux

##### Ubuntu/Debian

- `build-essential` package

You can install it with `apt` (`sudo apt install build-essential`)

#### Fedora/RHEL/CentOS

- `gcc`
- `make`
- `gcc-c++`

You can install them with `dnf` or `yum` (`sudo dnf install [packages here]`)

#### Arch (btw)/Manjaro/

- `gcc`
- `make`
- `gcc-c++`

You can install them with `pacman` or `yay` (`sudo pacman -S [packages here]`)

### Building instructions

First clone this repository with Git:

```shell
git clone https://github.com/ManiProjs/beh.git
```

Use CMake to create build files:

```shell
cmake -S . -B build
```

Finally, `cd` to the `build` directory and build it and install it (not required, but recommended) and run it.

If you have `Makefile` in the folder:

```shell
cd build &&
```

If you have `build.ninja`:

```shell
ninja
```

To install it, simply copy `beh` (Mac or Linux) or `beh.exe` (on Windows) to `/usr/bin` on Mac or Linux or "C:\Program Files\beh" in Windows (You can put it anywhere) (Don't forget to add "C:\Program Files\beh" to your PATH on Windows)

##### _beh_ is an acronym of "beh is not Better feh"

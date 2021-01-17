[![donate button](https://img.shields.io/badge/$-donate-ff69b4.svg?maxAge=2592000&amp;style=flat)](https://github.com/haxpor/donate)

# makefile_cpp_sample
Just a sample C++ built with Makefile to remind myself about target usage in Makefile

# Project

Sample project used in this repository for Makefile demonstration has the following setup.

* library project built as shared library (.so) - `util.cpp`, and `util.h`
* main program which consumes such library - `main.cpp`

The project utilizes Makefile to build.

# Makefile

It provides the following targets (not include internal targets although can be used, but not as part of concern for users)

* `all` - build both library, and main program (didn't execute a binary executable)
* `lib` - build library as shared library (.so)
* `main` - build main program as an executable binary
* `clean` - remove all artifact files
* `test` - to execute the executable binary (you might have to set `LD_LIBRARY_PATH` to current directory first externally via `export LD_LIBRARY_PATH=$PWD`)

# Notice on Makefile

Key an eye on the Makefile's target, and `.PHONY`. They are related to each other.

## Example hit-in-the-knee case - `.PHONY`

I've been hit with this case.
If your Makefile produces an executable named `main.out`, and you also include this as part of `.PHONY`,
then it's bad.

Makefile use `.PHONY` to differentiate between a target, and actual filename. Because Makefile itself
is based on filename as target thus whenever you include a target name inside `.PHONY` it will regard
that thing as such and it will always try to build that target. So its dependent target of that one
will also be affected, and thus be built unnecessily.

### Symptom

The symptom will show that Makefile will **always** build a target even without any changes has been made.

### Solution

Remove such target from `.PHONY`.

### So in short ...
In short, look at `Makefile` in this repository, and **don't** include
`main.out` as part of `.PHONY` otherwise Makefile will always build `main.out` (regarded as target)
even no changes made.

# License
MIT, Wasin Thonkaew


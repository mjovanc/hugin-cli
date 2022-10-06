<img height="80" src="hugin-cli-logo.png">

<p>
<a href="https://github.com/mjovanc/hugin-cli/actions">
    <img src="https://github.com/mjovanc/hugin-cli/actions/workflows/main-ci.yml/badge.svg">
</a>
<a href="https://github.com/mjovanc/hugin-cli/issues">
    <img src="https://img.shields.io/github/issues/mjovanc/hugin-cli">
</a>
<a href="https://github.com/mjovanc/hugin-cli/pulls">
    <img src="https://img.shields.io/github/issues-pr/mjovanc/hugin-cli">
</a>
<a href="https://github.com/mjovanc/hugin-cli/commits/main">
    <img src="https://img.shields.io/github/commit-activity/m/mjovanc/hugin-cli">
</a>
<a href="https://github.com/mjovanc/hugin-cli/graphs/contributors">
    <img src="https://img.shields.io/github/contributors/mjovanc/hugin-cli">
</a>
</p>

Hugin CLI - A Hugin client built with C++17. 

## Setup and run

1. Clone the repository
2. Run `cmake .` to initialize CMake project
3. Run `cmake -B ./build -S .`
4. Go to build directory and run `make`
5. Run executable `./Hugin`

### Unit tests

To run the test cases in **daemon_test.cpp** that comes along we need (after we have built) to run:

`./build/daemon_test`

We need in the future to link all test files so we can run all unit tests at once.

### Clean 

If we want to do a cleanup of generated files during build we can run:

`git clean -xfd`

## Contribute

### Pull request

I appreciate all contributions whether it be small changes such as documentation of source code to major improvement of code. The easiest way is to make a fork and then make a pull request into our master branch. 

## License

The license is GPL-3.0 License.

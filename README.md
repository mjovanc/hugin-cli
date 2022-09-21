# Heimdall
Heimdall - A simple password manager built with C++17. 

## Features

Features listed here are not done yet, it's just in idea stage:

- Login/Create account
- List password entries in ASC/DESC based on settings (gmail, protonvpn, kryptokrona_wallet)
- Update settings (select cryptographic method to store passwords, burn stored passwords after given time)
- Add/Edit password entries
- Export passwords entries to csv/xml/txt
- Send password entries with a transaction in the Kryptokrona blockchain to a specific Hugin Tx Hash

## Setup and run

1. Clone the repository
2. Run `cmake .` to initialize CMake project
3. Run `cmake -B ./build -S .`
4. Go to build directory and run `make`
5. Run executable `./Heimdall`

### Unit tests

To run the test cases in **routing_table_test.cpp** that comes along we need (after we have built) to run:

`./build/routing_table_test`

We need in the future to link all test files so we can run all unit tests at once.

### Clean 

If we want to do a cleanup of generated files during build we can run:

`git clean -xfd`

## Contribute

### Pull request

I appreciate all contributions whether it be small changes such as documentation of source code to major improvement of code. The easiest way is to make a fork and then make a pull request into our develop branch. 

## License

The license is GPL-3.0 License.

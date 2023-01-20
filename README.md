![Hugin CLI](resources/hugin-cli-logo-github.png)

[![Hugin CLI Main Pipeline](https://github.com/mjovanc/hugin-cli/actions/workflows/main-ci.yml/badge.svg)](https://github.com/mjovanc/hugin-cli/actions/workflows/main-ci.yml)

A private messaging CLI based Hugin Messenger. Powered by the Kryptokrona Blockchain.

- [Development Resources](#development-resources)
- [Releases](#releases)
- [Setup and run](#setup-and-run)
  - [Dependencies](#dependencies)
    - [Program arguments](#program-arguments)
  - [Commands](#commands)
    - [Auth](#auth)
    - [Chat](#chat)
    - [Other](#other)
  - [Clean](#clean)
- [Testing](#testing)
  - [Unit testing](#unit-testing)
- [CI/CD](#cicd)
- [Checklist before release](#checklist-before-release)
- [Contribute](#contribute)
  - [Pull request](#pull-request)
- [Contributors](#contributors)
- [License](#license)

# Development Resources

- Web: https://kryptokrona.org
- Docs: https://docs.kryptokrona.org
- GitHub: https://github.com/kryptokrona/hugin-cli
- Hugin: Hugin Development group on Hugin Messenger (currently only GUI version): `4820de8e26d21981afe6de2ff7b62fa6aa01126482ca0faeff151886c73619e5` \
  It is HIGHLY recommended to join our board on Hugin Messenger if you want to contribute to stay up to date on what is happening on the project.
- Twitter: @mjovanc

# Releases

| NAME | VERSION | RELEASED | DESCRIPTION    |
| ---- | ------- | -------- | -------------- |
| Tor  | 0.1.0   | No       | Alpha release. |

# Setup and run

1. Clone the repository and all its submodules `git clone --recurse-submodules git@github.com:kryptokrona/hugin-cli.git`
2. Run `cmake .` to initialize CMake project
3. Run `cmake -B ./build -S .`
4. Go to build directory and run `make`
5. Run executable `./Hugin`

Note to be able to run these commands above, install the dependencies in the next section first.

## Dependencies

The following table summarizes the tools and libraries required to build.

| Dep       | Min. version | Optional | Purpose                                               |
| --------- | ------------ | -------- | ----------------------------------------------------- |
| GCC       | 11           | NO       | Compiler.                                             |
| CMake     | 3.18         | NO       | Build generation tool for this project.               |
| OpenSSL   | 3            | NO       |                                                       |
| SQLCipher | 3.39.2       | NO       | Database (forked from Sqlite3) with encryption tools. |
| CUnit     | 3.2.7        | NO       | Unit testing framework written in C.                  |

To be able to build using Debian/Ubuntu

```sh
sudo apt-get -y install build-essential libssl-dev cmake git pkg-config
```

### Program arguments

Here is a list of available/future implementations of program arguments to use before starting the application.

- `-v`, `--version` - Get the current version.
- `-u`, `--username` (not implemented) - Pass the username to use to login.
- `-p`, `--password` (not implemented) - Pass the password to use to login.
- `-b`, `--batch-file` (not implemented) - Pass a batch file to import. File formats could be XML or JSON with a defined structure of what board, group or DM to send to.

Example of usage:

Login directly without going through menu options:

```shell
./Hugin --username=mjovanc --password=mysecretpwd
```

Login and pass a batch file:

```shell
./Hugin --username=mjovanc --password=mysecretpwd --batch-file=messages.json
```

More program arguments will come.

## Commands

### Auth
- `/r` - Register an account.
- `/l` - Login
- `/q` - Quit and logout.

### Chat

- `/b` or `/b <board-name>` - Join a board or list currently joined boards.
- `/pm` or `/pm <hugin-address>` (not implemented) - Join a private message or list currently joined private messages.
- `/pgm` or `/pgm <group-key>` (not implemented) - Join a private group or list currently joined private groups.

### Other
- `/i` (not implemented) - Get regular information such as wallet address, Hugin address, key, current node, node status, funds ratio, balance and so forth.
- `/t` or `/tip <wallet-address|saved-username>` (not implemented) - Tip an amount to a user by wallet address or saved username.
- `/c` or `/c <wallet-address|hugin-address|key|mnemonic-seed|private-keys>` (not implemented) - Copy wallet address, Hugin address, key, mnemonic seed or private keys. Need to authenticate again to access it. If only `/c` it copies everything to clipboard.
- `/s` (not implemented) - Settings to change which node to connect to, username, new password, check for updates and so forth.
- `/lt` (not implemented) - List all transactions made.
- `/lc` (not implemented) - List all contacts with their Hugin addresses and username.
- `/sf <path> <hugin-address|saved-username>` (not implemented) - Send file.

## Clean

If we want to do a cleanup of generated files during build we can run:

`git clean -xfd`

# Testing

## Unit testing

We use CUnit for the unit testing of this project. The unit tests are located in dir `test` with the same structure as the file being tested
includes in. To run all the tests:

TODO...

# CI/CD

This project is automatically built, tested and deployed using GitHub Actions. We have two pipelines:

- **Main Pipeline** - This is the pipeline that runs the code merged into our master branch.
- **Pull Request Pipeline** - This is the pipeline that runs each time a pull request come in so the reviewer has some
  help evaluating if the code is good enough to be merged.

The Main Pipeline do everything the Pull Request Pipeline does in addition to building and publishing a Docker Image to
the project tagged by the project name, owner, repository and short form of commit SHA value. We also setup continuous
deployment so if all the steps succeed and if tagged with a release it will publish to various package managers such as APT, Snapcraft etc.

# Checklist before release

1. Edit the file in `config/version.h` and bump up the version.
2. Update the release in this README in the [Releases](#releases) section and set YES on "Released", add the release if it doesn't
exists in the table.
3. Create PR and wait for review + merge.
4. Create a tag on master `git tag v*.*.*`
5. Push the changes `git push origin <tag_name>` to trigger a new build and to publish to various package managers.

# Contribute

## Pull request

We appreciate all contributions whether it be small changes such as documentation of source code to major improvement of
code. The easiest way is to make a fork and then make a pull request into our master branch.

# Contributors

The following contributors have either helped to start this project, have contributed
code, are actively maintaining it (including documentation), or in other ways
being awesome contributors to this project. **We'd like to take a moment to recognize them.**

[<img src="https://github.com/mjovanc.png?size=72" alt="mjovanc" width="72">](https://github.com/mjovanc)

# License

The license is BSD-3 License.
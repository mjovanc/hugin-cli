# Hugin CLI

[![Hugin CLI Main Pipeline](https://github.com/mjovanc/hugin-cli/actions/workflows/main-ci.yml/badge.svg)](https://github.com/mjovanc/hugin-cli/actions/workflows/main-ci.yml)

A private messaging CLI based Hugin Messenger. Powered by the Kryptokrona Blockchain.

## Table of Contents

- [Development Resources](#development-resources)
- [Testing](#testing)
  - [Unit testing](#unit-testing)
- [CI/CD](#cicd)
- [Checklist before release](#checklist-before-release)
- [Contribute](#contribute)
  - [Pull request](#pull-request)
- [Contributors](#contributors)
- [License](#license)

## Development Resources

- Web: https://kryptokrona.org
- GitHub: https://github.com/mjovanc/hugin-cli
- Hugin: Hugin Development group on Hugin Messenger (currently only GUI version): `4820de8e26d21981afe6de2ff7b62fa6aa01126482ca0faeff151886c73619e5` \
  It is HIGHLY recommended to join our board on Hugin Messenger if you want to contribute to stay up to date on what is happening on the project.
- Twitter: https://twitter.com/mjovanc

## Testing

### Unit testing

We use CUnit for the unit testing of this project. The unit tests are located in dir `test` with the same structure as the file being tested
includes in. To run all the tests:

TODO...

## CI/CD

This project is automatically built, tested and deployed using GitHub Actions. We have two pipelines:

- **Main Pipeline** - This is the pipeline that runs the code merged into our master branch.
- **Pull Request Pipeline** - This is the pipeline that runs each time a pull request come in so the reviewer has some
  help evaluating if the code is good enough to be merged.

The Main Pipeline do everything the Pull Request Pipeline does in addition to building and publishing a Docker Image to
the project tagged by the project name, owner, repository and short form of commit SHA value. We also setup continuous
deployment so if all the steps succeed and if tagged with a release it will publish to various package managers such as APT, Snapcraft etc.

## Checklist before release

1. Edit the file in `config/version.h` and bump up the version.
2. Update the release in this README in the [Releases](#releases) section and set YES on "Released", add the release if it doesn't
exists in the table.
3. Create PR and wait for review + merge.
4. Create a tag on master `git tag v*.*.*`
5. Push the changes `git push origin <tag_name>` to trigger a new build and to publish to various package managers.

## Contribute

### Pull request

We appreciate all contributions whether it be small changes such as documentation of source code to major improvement of
code. The easiest way is to make a fork and then make a pull request into our master branch.

## Contributors

The following contributors have either helped to start this project, have contributed
code, are actively maintaining it (including documentation), or in other ways
being awesome contributors to this project. **We'd like to take a moment to recognize them.**

[<img src="https://github.com/mjovanc.png?size=72" alt="mjovanc" width="72">](https://github.com/mjovanc)

## License

The license is BSD-3 License.
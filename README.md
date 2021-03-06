# Libra ZK reference implementation

[Libra](https://eprint.iacr.org/2019/317) is a doubly-efficient (meaning,
for both the prover and the verifier) zkSNARK.

This repo will help you to run all tests that performed in the paper.

Please read the README files in each of the following repositories:

- [Implementation](https://github.com/sunblaze-ucb/Libra/tree/master/implementation): the main Libra codebase

- [Paper](https://github.com/sunblaze-ucb/Libra/tree/master/paper): the paper with all versions

# Acknowledgement

Our benchmarks use the SHA256 circuit generator and LANCZOS circuit generator from Hyrax (https://github.com/hyraxZK). The files are in [/test/](https://github.com/sunblaze-ucb/Libra/tree/Libra/implementation/tests). We thank the Hyrax authors Riad S. Wahby, Ioanna Tzialla,abhi shelat, Justin Thaler and Michael Walfish for making the code open-source.



## Prerequisites ##

On Debian based systems, you can run the following command:

    ./setup.sh
    
This script will change your default clang compiler to clang-7.

Or:

    apt update
    apt -y install make git clang++-7 libgmp-dev g++ parallel

In other words, you'll need a C++11-compatible compiler (we use clang-7) (g++ 5, 6, or 7 will work).

## Building ##

The top-level Makefile in this directory will build everything below. Just run

    make -j4        # for example

## Testing ##
### Lanczos
    cd implemetation/tests/lanczos
    python build.py
    python run.py

### Matmul
    cd implemetation/tests/matmul
    python build.py
    python run.py

### SHA256
    cd implemetation/tests/SHA256
    python build.py
    python run.py

use `sudo` if necessary.

What is FantasyGold?
-------------

FantasyGold serves the $7billion fantasy sports and $1.5billion esports industries as a decentralized blockchain project built on Bitcoin's UTXO model, with support for Ethereum Virtual Machine based smart contracts, and secured by a proof of stake consensus model. It achieves this through the revolutionary Account Abstraction Layer which allows the EVM to communicate with FantasyGold's Bitcoin-like UTXO blockchain. 

For more general information about FantasyGold as well as links to join our community, go to https://fantasygold.io

Current Use Cases:

1. Play Daily Fantasy Sports using FGC20 Tokens https://DraftDaily.com
2. Play in eSports Tournaments using FGC20 Tokens https://FGCArena.com

This is the main network where the tokens hold value and should be guarded very carefully. If you are testing the network, or developing unstable software on FantasyGold, we highly recommend using either testnet or regtest mode. 

The major features of the FantasyGold network include:

1. Compatibility with the Ethereum Virtual Machine, which allows for compatibility with most existing Solidity based smart contracts. No special solidity compiler is required to deploy your smart contract to FantasyGold. This includes ERC20 and ERC7210 smart contracts and Dapps
2. A Proof of Stake consensus system which is optimized for FantasyGold's contract model. Any user can stake and help to secure the network. There is no voting, master nodes, or minimum amount required.
3. Uses the UTXO transaction model and is compatible with Bitcoin, allowing for existing tooling and workflows to be used with FantasyGold. This allows for the infamous SPV protocol to be used which is ideal for light wallets on mobile phones and IoT devices.

Note: FantasyGold Core is considered beta software. We make no warranties or guarantees of its security or stability.

FantasyGold Documentation and Usage Resources
---------------

These are some resources that might be helpful in understanding FantasyGold. Note that the unofficial documents are not created by the FantasyGold team. Rscourses will be added to the list as development continues.

Basic usage resources:

1. Official FantasyGold Usage Guide https://github.com/FantasyGold/FantasyGold-Core/wiki/FantasyGold-Wallet-Tutorial
2. Block explorer https://fantasygold.network)



Development resources:

1. Deploying a token to FantasyGold (https://github.com/fantasygold/FGC20Token)
2. FantasyGold PlayBook - A Developer's Guide To FGC (Comming Soon)



Developer's Tools
-----------------

1. Smart contract deployment tool https://github.com/fantasygold/solar (Comming Soon)
2. DApp JavaScript Library https://github.com/FantasyGold/FantasyGoldjs (Coming Soon)
3. A toolkit for building fantasygold light wallets https://github.com/FantasyGold/FantasyGoldjs-wallet (Coming Soon)
4. CORS fantasygoldd RPC proxy for DApp https://github.com/FantasyGold/FantasyGold-Core/portal (Coming Soon)
5. Docker images for running fantasygold services https://github.com/FantasyGold/FantasyGold-docker (Coming Soon)
6. HTTP API that powers the block explorer and the FGC web wallet https://github.com/fantasygold/insight-api-fgc


What is FantasyGold Core?
------------------

FantasyGold Core is our primary mainnet wallet. It implements a full node and is capable of storing, validating, and distributing all history of the FantasyGold network. FantasyGold Core is considered the reference implementation for the FantasyGold network. 

FantasyGold Core currently implements the following:

1. Sending/Receiving FantasyGold
2. Sending/Receiving FGC20 tokens on the FantasyGold network
3. Staking and creating blocks for the FantasyGold network
4. Creating and interacting with smart contracts
5. Running a full node for distributing the blockchain to other users
6. Prune+ACI- mode, which minimizes disk usage
7. Regtest mode, which enables developers to very quickly build their own private FantasyGold network for Dapp testing
8. Compatibility with the Bitcoin Core set of RPC commands and APIs

Alternative Wallets
-------------------

FantasyGold Core uses a full node model, and thus requires downloading the entire blockchain. If you do not need the entire blockchain, and do not intend on developing smart contracts, it may be more ideal to use an alternative wallet such as one of our light wallets that can be synchronized in a matter of seconds. 

FantasyGold Electrum (Coming Soon)

A light wallet that supports the Ledger hardware wallet and is based on the well known Electrum wallet software. 

Download: https://github.com/FantasyGold/

iOS and Android Wallets (Coming Soon)

Android Download: https://github.com/FantasyGold/

iOS Download: https://github.com/FantasyGold/




Building FantasyGold Core
----------

#Build on Ubuntu

    This is a quick start script for compiling FantasyGold on  Ubuntu


    sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils git cmake libboost-all-dev
    sudo apt-get install software-properties-common
    sudo add-apt-repository ppa:bitcoin/bitcoin
    sudo apt-get update
    sudo apt-get install libdb4.8-dev libdb4.8++-dev

    #If you want to build the Qt GUI:
    sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler qrencode

    git clone https://github.com/FantasyGold/FantasyGold-Core --recursive
    cd fantasygold

    #Note autogen will prompt to install some more dependencies if needed
    ./autogen.sh
    ./configure 
    make -j2
    
#Build on CentOS

Here is a brief description for compiling FantasyGold on CentOS, for more details please refer to https://github.com/FantasyGold/FantasyGold-Core/blob/master/doc/build-unix.md

    #Compiling boost manually
    sudo yum install python-devel bzip2-devel
    git clone https://github.com/boostorg/boost.git
    cd boost
    git checkout boost-1.66.0
    git submodule update --init --recursive
    ./bootstrap.sh --prefix=/usr --libdir=/usr/lib64
    ./b2 headers
    sudo ./b2 -j4 install
    
    #Installing Dependencies for FantasyGold
    sudo yum install epel-release
    sudo yum install libtool libdb4-cxx-devel openssl-devel libevent-devel
    
    #If you want to build the Qt GUI:
    sudo yum install qt5-qttools-devel protobuf-devel qrencode-devel
    
    Building FantasyGold
    git clone --recursive https://github.com/FantasyGold/FantasyGold-Core.git
    cd fantasygold
    ./autogen.sh
    ./configure
    make -j4

#Build on OSX

The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

#Preparation

Install the OS X command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

#Dependencies

    brew install cmake automake berkeley-db4 libtool boost --c++11 --without-single --without-static miniupnpc openssl pkg-config protobuf qt5 libevent imagemagick --with-librsvg qrencode

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

#Build FantasyGold Core

1. Clone the fantasygold source code and cd into `fantasygold`

        git clone --recursive https://github.com/FantasyGold/FantasyGold-Core.git
        cd fantasygold

2.  Build fantasygold-core:

    Configure and build the headless fantasygold binaries as well as the GUI (if Qt is found).

    You can disable the GUI build by passing `--without-gui` to configure.

        ./autogen.sh
        ./configure
        make

3.  It is recommended to build and run the unit tests:

        make check

#Run

Then you can either run the command-line daemon using `src/fantasygoldd` and `src/fantasygold-cli`, or you can run the Qt GUI using `src/qt/fantasygold-qt`

License
-------

FantasyGold is GPLv3 licensed.


Development Process
-------------------

The master branch is regularly built and tested, but is not guaranteed to be
completely stable. Tags (https://github.com/FantasyGold/FantasyGold-Core/tags) are created
regularly to indicate new official, stable release versions of FantasyGold.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Developer Chat can be found on Discord 

Testing
-------

Testing and code review is the bottleneck for development+ADs- we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

#Automated Testing

Developers are strongly encouraged to write 'unit tests' (src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: 'make check'. Further details on running
and extending unit tests can be found in '/src/test/README.md' (/src/test/README.md).

There are also +'regression and integration tests' (/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the 'test dependencies' (/test) are installed) with: 'test/functional/test-runner.py'

#Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

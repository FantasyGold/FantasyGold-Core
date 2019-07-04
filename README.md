What is FantasyGold?
-------------

FantasyGold is a decentralized blockchain project built on Bitcoin's UTXO model, with support for Ethereum Virtual Machine based smart contracts, and secured by a proof of stake consensus model. It achieves this through the revolutionary Account Abstraction Layer which allows the EVM to communicate with FantasyGold's Bitcoin-like UTXO blockchain. For more general information about FantasyGold as well as links to join our community, go to https://fantasygold.io

Welcome to the FantasyGold Ignition Main Network. This is the main network where the tokens hold value and should be guarded very carefully. If you are testing the network, or developing unstable software on FantasyGold, we highly recommend using either testnet or regtest mode. 

The major features of the FantasyGold network include:

1. Compatibility with the Ethereum Virtual Machine, which allows for compatibility with most existing Solidity based smart contracts. No special solidity compiler is required to deploy your smart contract to FantasyGold. 
2. A Proof of Stake consensus system which is optimized for FantasyGold's contract model. Any user can stake and help to secure the network. There is no voting, master nodes, or minimum amount required. There have been transactions as small as 2 FantasyGold that have created blocks in the past. 
3. The Decentralized Governance Protocol is completely implemented and functional, which allows certain network parameters to be modified without a fork or other network disruption. This currently controls parameters like block size, gas prices, etc. 
4. Uses the UTXO transaction model and is compatible with Bitcoin, allowing for existing tooling and workflows to be used with FantasyGold. This allows for the infamous SPV protocol to be used which is ideal for light wallets on mobile phones and IoT devices.

Note: FantasyGold Core is considered beta software. We make no warranties or guarantees of its security or stability.

FantasyGold Documentation and Usage Resources
---------------

These are some resources that might be helpful in understanding FantasyGold. Note that the unofficial documents are not created by the FantasyGold team.

Basic usage resources:

+ACo- +AFs-Official FantasyGold Usage Guide+AF0-(https://github.com/FantasyGold/FantasyGold-Core/wiki/FantasyGold-Wallet-Tutorial)
+ACo- +AFs-Unofficial FantasyGold staking tutorial+AF0-(https://steemit.com/fantasygold/+AEA-cryptominder/fantasygold-staking-tutorial-using-fantasygold-qt)
+ACo- +AFs-Unofficial FantasyGold staking tutorial on Raspberry Pi+AF0-(https://steemit.com/fantasygold/+AEA-cryptominder/fantasygold-staking-tutorial-using-fantasygoldd-on-a-raspberry-pi-3)
+ACo- +AFs-Unofficial FantasyGold staking tutorial on AWS EC2+AF0-(https://github.com/aaronmboyd/fantasygold-staking-on-aws-ec2)
+ACo- +AFs-Unofficial guide for keeping your wallet safe+AF0-(https://steemit.com/fantasygold/+AEA-cryptominder/encrypting-backing-up-and-restoring-your-fantasygold-wallet)
+ACo- +AFs-Block explorer+AF0-(https://explorer.fantasygold.org)
+ACo- +AFs-Unofficial block explorer+AF0-(https://fantasygoldexplorer.io/)

Development resources:

+ACo- +AFs-Deploying a custom token to FantasyGold+AF0-(https://blog.fantasygold.org/fantasygold-custom-token-walkthrough-467d725fa27d)
+ACo- +AFs-Early example faucet contract+AF0-(http://earlz.net/view/2017/06/30/2144/the-fantasygold-sparknet-faucet)
+ACo- +AFs-Unofficial FantasyGold Hello World tutorial+AF0-(https://steemit.com/fantasygold/+AEA-cryptominder/quantum-fantasygold-blockchain-developer-tutorial-hello-world)
+ACo- +AFs-FantasyGold Book - A Developer's Guide To FGC+AF0-(https://github.com/FantasyGold/FantasyGold-Corebook)

General Info about FantasyGold:

+ACo- +AFs-Mainnet event AMA+AF0-(https://www.reddit.com/r/FantasyGold/comments/6zs8t0/official+AF8-fantasygold+AF8-ama+AF8-thread+AF8-starts+AF8-at+AF8-10pm+AF8-beijing/)
+ACo- +AFs-FantasyGold's PoS vs CASPER+AF0-(https://www.reddit.com/r/FantasyGold/comments/788oa5/fantasygolds+AF8-pos+AF8-vs+AF8-casper+AF8-and+AF8-the+AF8-nothingatstake+AF8-problem/)
+ACo- +AFs-Technical article explaining FantasyGold's PoS model in depth+AF0-(http://earlz.net/view/2017/07/27/1904/the-missing-explanation-of-proof-of-stake-version)
+ACo- +AFs-Unofficial What is FantasyGold article+AF0-(https://storeofvalue.github.io/posts/what-is-fantasygold-without-the-bullshit/)

Developer's Tools
-----------------

+ACo- Smart contract deployment tool
  +ACo- https://github.com/fantasygold/solar
+ACo- DApp JavaScript Library
  +ACo- https://github.com/FantasyGold/FantasyGold-Corejs
+ACo- A toolkit for building fantasygold light wallets
  +ACo- https://github.com/FantasyGold/FantasyGold-Corejs-wallet
+ACo- CORS fantasygoldd RPC proxy for DApp
  +ACo- https://github.com/FantasyGold/FantasyGold-Coreportal
+ACo- Docker images for running fantasygold services
  +ACo- https://github.com/FantasyGold/FantasyGold-Core-docker
+ACo- HTTP API that powers the block explorer and the FGC web wallet
  +ACo- https://github.com/fantasygold/insight-api-fgc


What is FantasyGold Core?
------------------

FantasyGold Core is our primary mainnet wallet. It implements a full node and is capable of storing, validating, and distributing all history of the FantasyGold network. FantasyGold Core is considered the reference implementation for the FantasyGold network. 

FantasyGold Core currently implements the following:

+ACo- Sending/Receiving FantasyGold
+ACo- Sending/Receiving FGC20 tokens on the FantasyGold network
+ACo- Staking and creating blocks for the FantasyGold network
+ACo- Creating and interacting with smart contracts
+ACo- Running a full node for distributing the blockchain to other users
+ACo- +ACI-Prune+ACI- mode, which minimizes disk usage
+ACo- Regtest mode, which enables developers to very quickly build their own private FantasyGold network for Dapp testing
+ACo- Compatibility with the Bitcoin Core set of RPC commands and APIs

Alternative Wallets
-------------------

FantasyGold Core uses a full node model, and thus requires downloading the entire blockchain. If you do not need the entire blockchain, and do not intend on developing smart contracts, it may be more ideal to use an alternative wallet such as one of our light wallets that can be synchronized in a matter of seconds. 

+ACMAIwAj- FantasyGold Electrum

A light wallet that supports the Ledger hardware wallet and is based on the well known Electrum wallet software. 

Download: https://github.com/FantasyGold/FantasyGold-Core-electrum/releases

+ACMAIwAj- iOS and Android Wallets

These wallets run on mobile devices and synchronize quickly. 

Android Download: https://play.google.com/store/apps/details?id+AD0-org.fantasygold.wallet

iOS Download: https://github.com/FantasyGold/FantasyGold-Core-ios (open source, we are still working with Apple to get approval for their app store)

+ACMAIwAj- Ledger Chrome Wallet

This light wallet runs in your Chrome browser as a browser extension. This wallet requires a Ledger device to use.

How to install: https://ledger.zendesk.com/hc/en-us/articles/115003776913-How-to-install-and-use-FantasyGold-with-Ledger


Building FantasyGold Core
----------

+ACMAIwAj- Build on Ubuntu

    This is a quick start script for compiling FantasyGold on  Ubuntu


    sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils git cmake libboost-all-dev
    sudo apt-get install software-properties-common
    sudo add-apt-repository ppa:bitcoin/bitcoin
    sudo apt-get update
    sudo apt-get install libdb4.8-dev libdb4.8++-dev

    +ACM- If you want to build the Qt GUI:
    sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler qrencode

    git clone https://github.com/FantasyGold/FantasyGold-Core --recursive
    cd fantasygold

    +ACM- Note autogen will prompt to install some more dependencies if needed
    ./autogen.sh
    ./configure 
    make -j2
    
+ACMAIwAj- Build on CentOS

Here is a brief description for compiling FantasyGold on CentOS, for more details please refer to +AFs-the specific document+AF0-(https://github.com/FantasyGold/FantasyGold-Core/blob/master/doc/build-unix.md)

    +ACM- Compiling boost manually
    sudo yum install python-devel bzip2-devel
    git clone https://github.com/boostorg/boost.git
    cd boost
    git checkout boost-1.66.0
    git submodule update --init --recursive
    ./bootstrap.sh --prefix=/usr --libdir=/usr/lib64
    ./b2 headers
    sudo ./b2 -j4 install
    
    +ACM- Installing Dependencies for FantasyGold
    sudo yum install epel-release
    sudo yum install libtool libdb4-cxx-devel openssl-devel libevent-devel
    
    +ACM- If you want to build the Qt GUI:
    sudo yum install qt5-qttools-devel protobuf-devel qrencode-devel
    
    +ACM- Building FantasyGold
    git clone --recursive https://github.com/FantasyGold/FantasyGold-Core.git
    cd fantasygold
    ./autogen.sh
    ./configure
    make -j4

+ACMAIwAj- Build on OSX

The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

+ACMAIwAjACM- Preparation

Install the OS X command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

+ACMAIwAjACM- Dependencies

    brew install cmake automake berkeley-db4 libtool boost --c++11 --without-single --without-static miniupnpc openssl pkg-config protobuf qt5 libevent imagemagick --with-librsvg qrencode

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

+ACMAIwAjACM- Build FantasyGold Core

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

+ACMAIwAj- Run

Then you can either run the command-line daemon using `src/fantasygoldd` and `src/fantasygold-cli`, or you can run the Qt GUI using `src/qt/fantasygold-qt`

For in-depth description of Sparknet and how to use FantasyGold for interacting with contracts, please see [sparknet-guide](doc/sparknet-guide.md).

License
-------

FantasyGold is GPLv3 licensed.


Development Process
-------------------

The +AGA-master+AGA- branch is regularly built and tested, but is not guaranteed to be
completely stable. +AFs-Tags+AF0-(https://github.com/FantasyGold/FantasyGold-Core/tags) are created
regularly to indicate new official, stable release versions of FantasyGold.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Developer IRC can be found on Freenode at #fantasygold-dev.

Testing
-------

Testing and code review is the bottleneck for development+ADs- we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

+ACMAIwAj- Automated Testing

Developers are strongly encouraged to write +AFs-unit tests+AF0-(src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: +AGA-make check+AGA-. Further details on running
and extending unit tests can be found in +AFs-/src/test/README.md+AF0-(/src/test/README.md).

There are also +AFs-regression and integration tests+AF0-(/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the +AFs-test dependencies+AF0-(/test) are installed) with: +AGA-test/functional/test+AF8-runner.py+AGA-

+ACMAIwAj- Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

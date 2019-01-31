FantasyGold Core Documentation
=====================

### Tables of Contents

- [Setup](#setup)
- [Running](#running)
	- [Unix](#unix)
	- [Windows](#windows)
	- [OSX](#osx)
	- [Need Help?](#need-help)
	- [Ran into a Bug?](#ran-into-a-bug)
- [Building](#building)
- [Development](#development)
	- [Wallet Information](#wallet-information)
	- [Masternode Information](#masternode-information)
	- [Proof-of-Stake Information](#proof-of-stake-information)
	- [Governance Information](#governance-information)
	- [Transactions](#transactions)
	- [Miscellaneous](#miscellaneous)
- [License](#license)

Setup
---------------------
[FantasyGold Core](http://fantasygold.io.org/#downloads) is the original FantasyGold client and it builds the backbone of the network. However, it downloads and stores the entire history of FGC transactions; depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once.

Running
---------------------
The following are some helpful notes on how to run fgc on your native platform.

### Unix

Unpack the files into a directory and run:

- ./fantasygold-qt (GUI) or ./fantasygoldd (headless)

### Windows

Unpack the files into a directory, and then run fantasygold-qt.exe.

### OSX

Drag FantasyGold-Qt to your applications folder, and then run FantasyGold-Qt.

### Need Help?

* Ask for help on [Discord](https://discord.me/fantasygoldcrypto) or on the [FantasyGold Telegram](https://t.me/fantasygoldcrypto).
* Join our [Reddit Community](https://www.reddit.com/r/FantasyGoldCoin/)
* Tweet at [FantasyGold-Crypto](https://twitter.com/FantasyGoldCoin)

### Ran into a Bug?

* Submit an Issue on our [GitHub](https://github.com/FantasyGold/FantasyGold-Core.git/issues)

Building
---------------------
The following are developer notes on how to build fgc on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Unix Build Notes](building/Linux-Build-Guide.md)
- [MacOS Build Notes](building/MacOS-Build-Guide.md)
- [Windows Build Notes](building/Windows-Build-Guide.md)
- [NetBSD Build Notes](building/NetBSD-build-guide.md)
- [OpenBSD Build Notes](building/OpenBSD-build-guide.md)

Development
---------------------
The FantasyGold repo's [root README](https://github.com/FantasyGold/FantasyGold-Core.git/blob/master/README.md) contains relevant information our parameters.

- [Developer Notes](miscellaneous/Developer-Notes.md)
- [Multiwallet Qt Development](fantasygold-core/multiwallet-qt.md)
- [Release Notes](release-notes/)
- [Unit Tests](miscellaneous/unit-tests.md)
- [Unauthenticated REST Interface](fantasygold-core/REST-interface.md)
- [Dnsseed Policy](miscellaneous/dnsseed-policy.md)

### Wallet Information

- [Core Files](fantasygold-core/FantasyGold-Core-Files.md)
- [Default Data Locations](fantasygold-core/Default-Data-Locations.md)
- [Running FantasyGold](fantasygold-core/Running-FantasyGold.md)
- [Init Commands](fantasygold-core/fantasygoldd-init.md)
- [API Calls](fantasygold-core/FantasyGold-API-Calls.md)
- [Bootstrap](fantasygold-core/Bootstrap.md)
- [Traffic Reduction](fantasygold-core/Reduce-Traffic-in-FantasyGold-Core.md)
- [Accounts](fantasygold-core/Accounts-Explained.md)
- [Multisend](fantasygold-core/Multisend-Setup-Guide.md)
- [Data Locations](fantasygold-core/Default-Data-Locations.md)
- [TOR Support](fantasygold-core/TOR-Support-In-FantasyGold.md)

### Masternode Information

- [Masternode Commands](masternode/Masternode-Commands.md)
- [Installation](masternode/Masternode-Installation.md)
- [RPC Changes](masternode/Masternode-RPC-Changes.md)
- [Refresh Guide](masternode/Refresh-Guide.md)

### Proof-of-Stake Information

- [Staking Guide](proof-of-stake/Staking-Guide.md)
- [Staking Troubleshooting CLI](proof-of-stake/Staking-Troubleshooting-CLI.md)
- [Staking Troubleshooting GUI](proof-of-stake/Staking-Troubleshooting-GUI.md)

### Governance Information

- [Governance](miscellaneous/Governance.md)

### Transactions

- [ZeroMQ](transactions/Broadcasting-with-ZeroMQ.md)
- [SwiftTX](transactions/SwiftTX-Technical-Information.md)

### Miscellaneous

- [Assets Attribution](miscellaneous/assets-attribution.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.

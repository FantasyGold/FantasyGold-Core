(note: this is a temporary file, to be added-to by anybody, and moved to release-notes at release time)

FantasyGold Core version *version* is now available from:

  <https://github.com/fantasygold-project/fantasygold/releases>

This is a new major version release.

Please report bugs using the issue tracker at github:

  <https://github.com/fantasygold-project/fantasygold/issues>


Compatibility
==============

FantasyGold Core is tested on multiple operating systems using the Linux kernel, macOS 10.8+, and Windows 10 and later.

FantasyGold Core should also work on most other Unix-like systems but is not
frequently tested on them.

Notable Changes
===============

Zerocoin (zFGC) Protocol
---------------------

The zerocoin protocol has been fully implemented! This allows users to send transactions with 100% fungible coins and absolutely zero history or link-ability to their previous owners.

Full and comprehensive details about the process and the use will be posted here during the days between Oct 6 and Oct 13.

Tor Service Integration Improvements
---------------------

Integrating with Tor is now easier than ever! Starting with Tor version 0.2.7.1 it is possible, through Tor's control socket API, to create and destroy 'ephemeral' hidden services programmatically. FantasyGold Core has been updated to make use of this.

This means that if Tor is running (and proper authorization is available), FantasyGold Core automatically creates a hidden service to listen on, without manual configuration. FantasyGold Core will also use Tor automatically to connect to other .onion nodes if the control socket can be successfully opened. This will positively affect the number of available .onion nodes and their usage.

This new feature is enabled by default if FantasyGold Core is listening, and a connection to Tor can be made. It can be configured with the `-listenonion`, `-torcontrol` and `-torpassword` settings. To show verbose debugging information, pass `-debug=tor`.




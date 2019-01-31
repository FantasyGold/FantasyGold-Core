
Debian
====================
This directory contains files used to package fantasygoldd/fantasygold-qt
for Debian-based Linux systems. If you compile fantasygoldd/fantasygold-qt yourself, there are some useful files here.

## fantasygold: URI support ##


fantasygold-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install fantasygold-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your fantasygoldqt binary to `/usr/bin`
and the `../../share/pixmaps/fantasygold128.png` to `/usr/share/pixmaps`

fantasygold-qt.protocol (KDE)



Debian
====================
This directory contains files used to package tunezd/tunez-qt
for Debian-based Linux systems. If you compile tunezd/tunez-qt yourself, there are some useful files here.

## tunez: URI support ##


tunez-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tunez-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tunezqt binary to `/usr/bin`
and the `../../share/pixmaps/tunez128.png` to `/usr/share/pixmaps`

tunez-qt.protocol (KDE)


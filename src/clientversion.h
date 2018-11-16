// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CLIENTVERSION_H
#define BITCOIN_CLIENTVERSION_H

#if defined(HAVE_CONFIG_H)
#include "config/tunez-config.h"
#else

/**
* client versioning and copyright year
*/

//! These need to be macros, as clientversion.cpp's and tunez*-res.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR 1
#define CLIENT_VERSION_MINOR 1
#define CLIENT_VERSION_REVISION 1
#define CLIENT_VERSION_BUILD 0

//! Set to true for release, false for prerelease or test build
#define CLIENT_VERSION_IS_RELEASE false

/**
* Copyright year (2009-this)
* Todo: update this when changing our copyright comments in the source
*/
#define COPYRIGHT_YEAR 2017

#endif //HAVE_CONFIG_H

/**
* Point to URL that redirects to the latest update available
*/
#define GITHUB_RELEASE_URL "https://github.com/TunezCoinNG/TunezCoinNG/releases/latest"

// Check that required client information is defined
#if !defined(CLIENT_VERSION_MAJOR) || !defined(CLIENT_VERSION_MINOR) || !defined(CLIENT_VERSION_REVISION) || !defined(CLIENT_VERSION_BUILD) || !defined(CLIENT_VERSION_IS_RELEASE) || !defined(COPYRIGHT_YEAR)
#error Client version information missing: version is not defined by tunez-config.h or in any other way
#endif

/**
 * Converts the parameter X to a string after macro replacement on X has been performed.
 * Don't merge these into one macro!
 */
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

//! Copyright string used in Windows .rc files
#define COPYRIGHT_STR "2009-" STRINGIZE(COPYRIGHT_YEAR) " The Bitcoin Core Developers, 2014-" STRINGIZE(COPYRIGHT_YEAR) " The Dash Core Developers, 2015-" STRINGIZE(COPYRIGHT_YEAR) " The TunezNG Core Developers"

/**
 * tunezd-res.rc includes this file, but it cannot cope with real c++ code.
 * WINDRES_PREPROC is defined to indicate that its pre-processor is running.
 * Anything other than a define should be guarded below.
 */

#if !defined(WINDRES_PREPROC)

#include <string>
#include <vector>

static const int CLIENT_VERSION =
    1000000 * CLIENT_VERSION_MAJOR  ///
    + 10000 * CLIENT_VERSION_MINOR  ///
    + 100 * CLIENT_VERSION_REVISION ///
    + 1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

std::string FormatVersion(int nVersion);
std::string FormatFullVersion();
std::string FormatSubVersion(const std::string& name, int nClientVersion, const std::vector<std::string>& comments);

#endif // WINDRES_PREPROC

#endif // BITCOIN_CLIENTVERSION_H
Skip to content
This repository
Search
Pull requests
Issues
Gist
 @yeqing
 Watch 6
  Star 0
  Fork 1 mobile/usc_hybrid
 Code  Issues 1  Pull requests 0  Wiki  Pulse  Graphs
Branch: master Find file Copy pathusc_hybrid/README.md
026c4a3  29 days ago
@sanjanam sanjanam Update README.md
2 contributors @sanjanam @renachen
RawBlameHistory     103 lines (84 sloc)  1.77 KB
USC Mobile App
Built using Cordova and Angular2.

Supported Platforms

iOS

Android

Requirements

Download and install Node.js, at least version 4.x.x. Make sure NPM is at least version 3.x.x.
Install Cordova module.
For Windows:
C:/>npm install -g cordova
For Mac:
$sudo npm install -g cordova
Installation

Download or clone repository
Go into project folder
cd usc_hybrid
Install dependencies:
npm install
Add Cordova platforms
For iOS:
cordova platform add ios --save
For Android:
cordova platform add android --save
To check if you satisfy requirements for building the platform:

cordova requirements
Install required plugins:

  cordova plugin add cordova-plugin-inappbrowser

  cordova plugin add cordova-plugin-statusbar

  cordova plugin add com.lampa.startapp

  cordova plugin add cordova-plugin-device
Building App

Run the following command to build project for all platforms:  cordova build 
Deploying App

For emulator:
cordova emulate <platform name>
For device:
cordova run <platform name>
Example:

cordova run android
Running Unit Tests

Tests are written in Jasmine and run using Karma test-runner.

To run the unit tests directly without building the app:

Download or clone repository
Go into project folder
cd usc_hybrid
Install dependencies:
npm install
Run Karma Tests:

cd www
karma start


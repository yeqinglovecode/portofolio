# USC Mobile App

Built using Cordova and Angular2. 

Supported Platforms

* iOS

* Android

## Requirements

* Download and install <a href="https://nodejs.org/en/download/current/">Node.js</a>, at least version **4.x.x**. Make sure NPM is at least version **3.x.x**.
* Install <a href="https://cordova.apache.org">Cordova</a> module.
 * For Windows:
 ```
 C:/>npm install -g cordova
 ```
 * For Mac:
 ```
 $sudo npm install -g cordova
 ```

## Installation

* Download or clone repository
* Go into project folder
```
cd usc_hybrid
```
* Install dependencies:
```
npm install
```
* Add Cordova platforms
 * For iOS:
 ```
 cordova platform add ios --save
 ```
 * For Android:
 ```
 cordova platform add android --save
 ```
 To check if you satisfy requirements for building the platform:
 ```
 cordova requirements
 ```
* Install required plugins:
 ```
    cordova plugin add cordova-plugin-inappbrowser

    cordova plugin add cordova-plugin-statusbar

    cordova plugin add com.lampa.startapp
    
    cordova plugin add cordova-plugin-device
 ```

## Building App
* Run the following command to build project for all platforms:
 ```
 cordova build
 ```

## Deploying App
* For emulator:
```
cordova emulate <platform name>
```
* For device:
```
cordova run <platform name>
```
Example:
```
cordova run android
```

## Running Unit Tests
Tests are written in <a href="http://jasmine.github.io/1.3/introduction.html">Jasmine</a> and run using <a href="https://karma-runner.github.io/1.0/index.html">Karma</a> test-runner.

 * To run the unit tests directly without building the app:

  * Download or clone repository
  * Go into project folder
   ```
   cd usc_hybrid
   ```
  * Install dependencies:
   ```
   npm install
   ```

Run Karma Tests:
```
cd www
```
```
karma start
```



# [WeThinkCode_](http://www.wethinkcode.co.za/) Social Tech Project - ER QR

![screenshot](https://user-images.githubusercontent.com/18417244/38734064-c5213ac0-3f13-11e8-838e-59440eacd1a8.png)

## Project Description

The Social Tech project was our final WeThinkCode_ project. It began in August 2017 and the final grading happened in January 2018. We were tasked to innovate and create a tech solution specifically designed to solve one of South Africa's most pressing social or environmental issues. 

All the teams had the chance to pitch our ideas to a jury of industry professionals and WeThinkCode_ corporate sponsors, in a Shark Tank-like setting. We had to prove the feasibility of our idea and were either given the thumbs up to proceed with development or advised on how to improve the current idea in order to make it a success.

My team and I decided to address the issue of the difficulties medics face when trying to attain a patient's medical information in trauma situations.  We created two apps to streamline the process of retrieving patient data. One application takes a patient's brief medical history, allergies and current medications and generates a QR Code and the other is a QR Code scanning app for authenticated medical personnel to access the data during the first stage of treatment.

The 18th of January was the Final Pitch evening where the 5 teams with the highest scores so far in the process went head to head to win the jury's vote to become the first winners of the WeThinkCode_ Social Tech lab.
I am pleased to announce that we [won](https://youtu.be/BRSDM_y6pa8?t=2m26s) and received the opportunity to travel to France and represent Africa in the [**Viva Technology**](https://vivatechnology.com/) Hackathon in Paris this May.

![screenshot](https://user-images.githubusercontent.com/18417244/38740998-5c0cc2e2-3f28-11e8-8aa9-b6ee4bb00383.png)

## The Team

* **Owen Exall** - was incharge of building the QR Scanner & the QR Code Generating apps 
* **Robert Jones** - was our business liaison and in charge of the business model
* **Miriam Lamarre** - was in charge of design, mock-ups, front end and the presentation
* **Phillip Jacobs** - aided Owen with development and user testing
* **Dillon Mather** - was in charge of testing and editing our user feedback video

![screenshot](https://user-images.githubusercontent.com/18417244/38734065-c5585ee2-3f13-11e8-942a-f6395cdd31d8.png)

## Screenshots

### Medic QR Code Scanning Application

![screenshot](https://user-images.githubusercontent.com/18417244/38741263-15ac56ea-3f29-11e8-915e-ba35774fafc2.gif)

### Patient QR Code Generating Application

![screenshot](https://user-images.githubusercontent.com/18417244/38741275-1cbde962-3f29-11e8-991e-b5b8e8b28c1c.gif)

## Prerequisites

* Install Brew
* Install MongoDB
    * URL: *https://treehouse.github.io/installation-guides/mac/mongo-mac.html*
    * SECTION: **'Install and Run MongoDB by Downloading it Manually'**
    * Stop before creating the data directory
* `mkdir ~/mongoData`
* `export PATH=$PATH:$HOME/mongodb/bin`
    * Add the above command to your **~/.zshrc** file
* `mongod --dbpath ~/mongoData`
    * You should see a lot of text & "**waiting for connections on port 27017**" at the end
* Install React-Native
    * URL: *https://facebook.github.io/react-native/docs/getting-started.html*
    * SECTION: **'Building Projects with Native Code'**
    * Change the Target OS to **'Android'**

**Note: everything should already be installed to run iOS, if not, just change the target and read through it.**

## Projects

### API
* Navigate to API Directory
* `npm install` to install all the dependencies
* `npm run dev` **(Note: it will fail if mongodb hasn't been started.)**

### React-Native Apps

**This should be the same for both the QR_Generator & QR_Scanner**

* `npm install`
* `react-native run-ios`

**Note: to run on android, you need to have a running emulator. Then call** `react-native run-android`

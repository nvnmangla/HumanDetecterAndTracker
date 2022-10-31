# Human Detector and Tracker 
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Build Status](https://github.com/mahimaarora2208/HumanDetecterAndTracker/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/mahimaarora2208/HumanDetecterAndTracker//actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/mahimaarora2208/HumanDetecterAndTracker/badge.png?branch=main)](https://coveralls.io/github/mahimaarora2208/HumanDetecterAndTracker?branch=main)
## Overview
In this project, a Human Detector and Tracker has been developed. To achieve this, we
used the pre-trained model of Yolo-V5. The last layer of the Yolo neural network was frozen so that it only detects humans in the image. After detecting the humans in the image there distance was calculated from the camera. Assumption we have taken is that the human in average is of 5ft.

Four classes were implemented to achieve this objective, in which the master class is **Human-Detector**.

## Team:Group 4

 - Mahima Arora - Driver (https://github.com/mahimaarora2208)
 - Naveen Mangla - Navigator (https://github.com/nvnmangla)
 - Abhinav Garg - Designer (https://github.com/15abhinavgarg)


## AIP Development

This project will be completed using AIP process with the involvement of 3 programmers using Pair-programming in turns. One of the programmer would be driver while other 2 would be navigator and design keeper. The detailed Product Backlog, Iteration Backlogs and Work Log are mentioned in the link given below :

[Agile Iterative Process](https://docs.google.com/spreadsheets/d/1lvFBjKfvxlf-LXtopkBy3UAMlyQPi31W/edit?usp=sharing&ouid=106728747057946217321&rtpof=true&sd=true)

## Important Links

[Phase 0 Proposal](https://drive.google.com/file/d/10hK7GmJcISf981nXX9E4CqcFHO8nGW70/view?usp=sharing)


[Phase 0 Video](https://drive.google.com/file/d/1qjiJ8MVaANbqeYgCbcMmP3CATyp1pWou/view?usp=sharing)

[Phase 1 Video](https://drive.google.com/file/d/1FNlZqDXzz6H9pJ2Tok4gB1hnIMF776Sp/view?usp=sharing)

[UML Class Diagram Phase 0](https://drive.google.com/file/d/16ZB5cMJbd44Ys_4KVa8fdSBXSPN-JB1F/view?usp=sharing)

[UML Class Diagram Phase 1](https://drive.google.com/file/d/1Ky4Y5SGkwsw3tudvV3qMJoQ9zC0JVxFh/view?usp=sharing)

[UML Class Diagram Phase 2](https://drive.google.com/file/d/1glShZYrTTs4PfVRKWUgJwSy6m5da1fdX/view?usp=sharing)

[Activity Diagram Phase 0](https://drive.google.com/file/d/1PFQ3R563C5RVZqSqUmu6HlybmQZDz23V/view?usp=sharing)

[Quad Chart](https://drive.google.com/file/d/1kqztJTiyrLfmTfumVQuHahukdQgT3-xU/view?usp=sharing)

## Sprint Planning Notes
The below link contains combined notes of sprint 1 and sprint 2.
[Link](https://docs.google.com/document/d/1r_AImnCmMG55agtjQzNZ3n2YdrxkfY6n6iax4RRetbs/edit?usp=sharing)


## Downloading Dependencies
The main dependency that needs to be downloaded is openCV 4.2 or above.

```
# Installing Dependencies
sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config

# Cloning Git repository
git clone https://github.com/opencv/opencv.git;mkdir -p build && cd build

# CMAKE
cmake ../opencv;make -j4

# Installing OpenCV 
sudo make install
```



## How to build and run demo code
```
git clone https://github.com/nvnmangla/HumanDetecterAndTracker.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```


## To Generate and Check code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## To Generate Doxygen Documentation
open your terminal in your repository
```
doxywizard
```
Follow steps in GUI after selecting path of your repository.


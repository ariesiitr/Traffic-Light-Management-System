# Traffic-light-management-System
Recruitment Project for 1st year

This project tries to overcome the problem of mismanaged traffic effeciently, by using the state of the art object detection algorithm called YOLO.
At each signal, a snapshot is taken that is sent to the program for processing. Using YOLO (which we have integrated with our main python program) we first extract the number of cars, buses etc in that photo.
We feed these values to a function , that is designed to calculate the appropriate green signal time for the given nu. of vehicles of each class.

The main function is designed to run a loop, in which the status of each signal (RYG time left) is updated each second. As move from one signal to another, we update the green signal time (using the function), and then the function runs in the next iteration with updated parameters. The green time for the first signal is initialised to 20 seconds.
Yellow time for all signals is 4 seconds.

Training info and specifications are described in the word doc.


LIBRARIES USED:

for training:

argeparse,numpy,pytorch,shutil

for the final detection program:

numpy,tensorflow,pytorch,openCv, time 


WORKING MODEL:

We used an arduino simulation to demonstrate the signal switching process. We also used an LCD and serial communication, to display the green time left at the current signal.
https://www.tinkercad.com/things/i1Ndch9GYBg

RUNNING THE PROJECT/ INSTALLATION INFO

The python file that demonstrates the signal switching process and the YOLO implementation is signalcountdown.py (under the folder yolov5_implementation). Currently, it runs for 6 test images , that are located under yolov5_implementation/data/arsimages. More test images can be added to this folder, and we will need to change the variable maxruns in the python file accordingly.

The detection information can be found in yolov5_implementation/runs/detect, with the bounding box and confidence score displayed for the objects.




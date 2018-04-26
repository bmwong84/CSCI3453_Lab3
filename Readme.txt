*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 3453         
*  HW#       :  Lab 3              
*  Due Date  :  Nov. 29, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program simulates page replacement algorithms First-in-First-Out (FIFO),
Least Recently Used (LRU), Least Frequently Used(LFU), and Optimal.  
Input file is the string of replacement pages and the program runs with
memory size of 128, 256, 512, and 1024 available frames.  
The input file should be named input.txt (or whatever file you have)

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This has member function calls that contains all of the actual code.

Name:  PageReplacement.cpp
   Holds all of the code for the algorithms as well as two menu functions and associated search
algorithms as well as read file and output file.

Name:  PageReplacement.h
   Holds the class for PageReplacement as well as the struct "page" that contains all of the values
necessary for calculating which frame should be replaced with which algorithm.

   
   
*******************************************************
*  Circumstances of programs
*******************************************************

Compiles and runs on csegrid.  

Developed on Visual Studio Community 2017 version 15.3.2.  


*******************************************************
*  How to build and run the program
*******************************************************


    You should see a directory named won1009 with the files:
        main.cpp
	output128.txt		(sample outputs)
	output256.txt
	output512.txt
	output1024.txt
        makefile
	input.txt
        Readme.txt
	Report.doc	(contains analysis and graphs)

    Compile the program by:
    % make

Run the program by:
   % ./lab3

Delete the obj files, executables, and core dump by
   %./make clean

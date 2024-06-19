# Arkanoid-Brick-Breaker-Game-

**To run this project you have to run these commands on Ubuntu terminal**:

        sudo apt-get install freeglut3-dev glew-utils libglew-dev libfreeimage-dev	
  
# how to install libraries first update by:
      
        sudo apt update 
      
**Run the commands:**
       
        1) chmod sudo apt-get install libglew-dev
        2) bash install-libraries.sh (**it will install the libraries**) 
        3) make
        4) ./game


**To run on Windows:**

  1) Download GLUT:
  
      Visit the OpenGLUT project page on SourceForge: OpenGLUT
      Download the precompiled binary version of GLUT for Windows.
 
  2) Extract the Files:
  
      Once the download is complete, extract the contents of the downloaded ZIP file to a location on your computer.
  
  3) Copy Files:
   
      Navigate to the extracted folder and copy the necessary files (e.g., glut.dll, glut.lib, glut.h) to your project directory or to a location where your compiler can find them.
  
  4) Set up Your IDE:
   
      If you're using an IDE like Visual Studio, you may need to configure the project settings to include the GLUT files. This typically involves adding the glut.lib file to the linker settings       and adding the folder containing glut.h to the include directories.
 
  5) Link the Library: 
   
      When compiling your project, make sure to link against the GLUT library (glut.lib).

**On Mac:**
    
    Install Homebrew (if not already installed):

  **Open Terminal:**
      Run the following command to install Homebrew:
      /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
      In Terminal, run the following command to install GLUT:
      brew install freeglut

##Resources

##Kinect

ofxKinect ships with OF 0.8

https://github.com/gameoverhack/ofxOpenNI

https://github.com/sadmb/ofxKinectNui

https://github.com/joshuajnoble/ofxKinectCommonBridge

####Adding ofxKinectCommonBridge to a Project:
-------------

1. In vs, right click on your project in the solution explorer, and go to properties
2. Expand the Configuration Properties Tab, and click "C/C++"
3. Add 
````
$(KINECTSDK10_DIR)inc
````
to Additional Include Directories
4. Expand the Linker tab and click on General
5. Add 
```````
$(KINECTSDK10_DIR)lib\x86
and 
..\..\..\addons\ofxKinectCommonBridge\libs\KinectCommonBridge\lib\windows
```````
to Additional Library Directories
6. Open the Input Tab under Linker
7. Add
``````
Kinect10.lib
and
KinectCommonBridge.lib
``````
to Additional Dependencies
8. Finally, copy KinectCommonBridge.dll to the bin folder of your application.
9. Done.


##Camera

https://github.com/kylemcdonald/ofxFaceTracker

https://github.com/kylemcdonald/ofxEdsdk

##Tracking

https://github.com/karldd/ofxARToolkitPlus

https://github.com/patriciogonzalezvivo/ofxPTAMM

Video Manipulation

https://github.com/kylemcdonald/ofxCv

##RGB+D

https://github.com/obviousjim/ofxRGBDepth

projection mapping

https://github.com/morethanlogic/ofxMtlMapping2D

https://github.com/maxillacult/ofxMpplr

https://github.com/camilosw/ofxVideoMapping

http://chparsons.com.ar/#camara_lucida
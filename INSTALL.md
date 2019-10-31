
Requirements
====================================================

* OMNeT++ is required: See https://omnetpp.org/
* * This release is only tested with **OMNeT++ 4.6**
* * Help with installing OMNeT++ can be found in the **OMNeT++ Install Guide**

Step 1: Import the project into OMNeT++:
====================================================

* Right-click on the project explorer (on the left side of a default OMNeT++ installation)
* Select **General -> Existing Projects into Workspace**
* Select the folder containing the **OMNeT_Utils** project as the root directory
* Click **Finish**

Step 2: Build project in OMNeT++:
====================================================

* Select the build configuration (release or debug) by right-clicking on the project  and selecting **Configurations -> Set Active**
* Right click on project and select **Build Project**
* The project should be built without errors, and the build result will be a shard library which can be used within other OMNeT++ projects.
* To use the OMNeT_Utils libary in other OMNeT++ projects, add it as a project reference of the other project.

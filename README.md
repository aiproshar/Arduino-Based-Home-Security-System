# Arduino-Based-Home-Security-System

## Project description
An Arduino based home monitoring, which continuously monitors for air or gas leakage, Temperature and IR emission from fire incident, excessive current flow from short circuit detection. Upon detecting anomalies, the system shuts down electrical and gas connections automatically triggers an alarm, and notifies authority via SMS.
This system also constantly monitors for motions in an empty house, detecting any breach or theft activity in the house. And notifies users in those events.

## Project Structure
The project was divided initially into two parts, the GSM Module and Monitoring System. The Monitoring System continuously monitors for anomaly through sensors. Upon detecting an anomaly, it calls the GSM function to send an appropriate response to authority.

The GSM Exclude File has separate code files to test out each modules, While the GSM module tests and debugs the GSM module's functionality. In the release folder, there is the final code (with versions) that was uploaded and tested to Arduino UNO. 

## Why no version Control?
This project was developed as part of academics back in 2017, in that time I was not familiar with GitHub and version control. But in the "release folder" the version control is maintained internally. I decided to make this public so I am just uploading the folder as it was.

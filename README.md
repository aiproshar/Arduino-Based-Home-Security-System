# Arduino-Based-Home-Security-System

## Project description
A Arduino based home monitoring, which continuously monitors for air for gas leakage, Temperature and IR emission for fire incident, current flow for short circuit detection. Upon detecting anomalies through, the system shuts down electrical and gas connections automatically, triggers alarm and notifies authority via SMS.
This system also constantly monitors for motions in empty house, detecting any breach or theft activity in the house. And notifies users in those event.

## Project Structure
The project was divided initially into two parts, the GSM module and Monitoring System. The Monitoring System Continiously monitors for anomaly through sensors. Upon detectiong an anomaly, it walls the GSM function to send appropriate response to authority.

The GSM Exclue File has separate code files to test out each modules, While the GSM module tests and debugs the GSM module functionality. In the release folder, there is the final code (with versions) that was uploaded and tested to Arduino UNO. 

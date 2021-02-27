# Arduino Playground

This repository is a collection of Arduino codes that I frequently use. If there will be codes that have the same context, I would separate them into different repository.

* OttoAllLimbs ---> Codes that used to move all Otto's [https://www.ottodiy.com/](https://www.ottodiy.com/) limbs and do all movement available. These codes are useful to test whether or not your servos will stall.
* OttoBasicAlignment ---> Codes that used to do sweep movement of all Otto's [https://www.ottodiy.com/](https://www.ottodiy.com/) limbs, ended with all servos stayed on 90°. These codes are useful if you want to assembly your Otto, to set all servos initial position.
* OttoBasicSweep ---> Codes that used to do sweep movement of all Otto's [https://www.ottodiy.com/](https://www.ottodiy.com/) limbs, continously.
* OttoBestModifiedCalibrationWithSave ---> Modified codes from Otto_Calibration_V9 example (you can also see the codes here ---> [https://wikifactory.cn/+OttoDIY/otto-diy/v/acb8f76/file/Code/Otto_Calibration_V9/Otto_Calibration_V9.ino](https://wikifactory.cn/+OttoDIY/otto-diy/v/acb8f76/file/Code/Otto_Calibration_V9/Otto_Calibration_V9.ino) ). With my modifications, I put a dedicated button press to save the trim position to microcontroller's EEPROM. In the original codes, everytime we adjust trim position it automatically saves. There are rumors that saving too much to EEPROM will damage the microcontroller.
* OttoMain ---> Basic Otto [https://www.ottodiy.com/](https://www.ottodiy.com/) codes that makes your Otto follows based on the distance sensor.

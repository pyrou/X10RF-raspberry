X10RF-raspberry
===============

X10RF-raspberry is for controlling 433(.92)Mhz X10 receiver with the Raspberry pi. This code is based on a fork of [p2baron/x10rf](http://github.com/pyrou/x10rf) initially created for Energia, then ported to Arduino plateform.


### Dependencies
wiringPi : https://projects.drogon.net/raspberry-pi/wiringpi/

### Building WiringPi
```bash
sudo apt-get install git-core
git clone git://git.drogon.net/wiringPi
cd wiringPi/wiringPi
./build
```

## Usage

X10RF-raspberry is shipped with an example program *send* that you have to compile by executing *make*. 
You may want to change the used GPIO pin before compilation in the send.cpp source file.

```bash
git clone git@github.com:pyrou/X10RF-raspberry.git
cd X10RF-raspberry
make
sudo ./send B 10 ON
```

#  Raspberry Pi Master for Arduino Slave
#  i2c_master_pi.py
#  Connects to Arduino via I2C

########################################
#  Changed by py777hub for two devices #
########################################
  
#  DroneBot Workshop 2019
#  https://dronebotworkshop.com

#  

from smbus import SMBus

addr1 = 0x8 # bus address
addr2 = 0x9 # bus address
bus = SMBus(1) # indicates /dev/ic2-1

numb = 1

print ("Enter 1 for ON or 0 for OFF")
while numb == 1:

	ledstate = input(">>>>   ")

	if ledstate == "1":
		bus.write_byte(addr1, 0x1) # switch it on
	elif ledstate == "2":
		bus.write_byte(addr2, 0x1) # switch it on	
	elif ledstate == "0":
		bus.write_byte(addr1, 0x0) # switch it off
		bus.write_byte(addr2, 0x0) # switch it off
	else:
		numb = 0

# This should be a test or example startup script

require heaterctrl

iocshLoad("$(daq6510_DIR)daq6510.iocsh", "IP=192.168.10.44,P=CstatV-AC:,IOCNAME=ioc27-htrctrl,TOP=/tmp/autosave")

dbLoadRecords("heaterctrl.db", "P=CstatV-AC:, DEV=DAQ6510, PORT=PORT1")

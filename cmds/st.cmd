# This should be a test or example startup script

require heaterctrl

addScan(60)
addScan(30)

epicsEnvSet("IOCNAME", "ioc27-htrctrl")
epicsEnvSet("IP", "192.168.10.44")
epicsEnvSet("P", "CstatV-AC:")
epicsEnvSet("TOP", "/tmp/autosave")

#drvAsynIPPortConfigure("$(ASYN_PORT=PORT1)","$(IP):$(IP_PORT=5025)",0,0,0)
iocshLoad("$(daq6510_DIR)daq6510_init.iocsh", "ASYN_PORT=DAQ_PORT,IP=192.168.10.44,P=CstatV-AC:")

#dbLoadRecords("daq6510.db", "PORT=$(ASYN_PORT=PORT1),P=$(P),DEV=$(DEV=DAQ6510)")

dbLoadRecords("asynRecord.db","P=${IOCNAME},R=:asynRec,PORT=$(ASYN_PORT=DAQ_PORT),ADDR='0',IMAX='1024',OMAX='256'")
dbLoadRecords("heaterctrl.db", "P=CstatV-AC:, DEV=DAQ6510, PORT=DAQ_PORT")

iocshLoad("$(autosave_DIR)/autosave.iocsh", "AS_TOP=$(TOP),IOCNAME=$(IOCNAME),IOCDIR=$(IOCDIR=daq6510)")

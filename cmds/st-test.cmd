# This should be a test or example startup script

require heaterctrl

epicsEnvSet("P", "CstatV-AC:")

dbLoadRecords("calculus.db", "P=CstatV-AC:, DEV=DAQ6510")

var fillArrDebug 7

afterInit("dbpf CstatV-AC:DAQ6510:ChanInactive1-val.VAL 100")


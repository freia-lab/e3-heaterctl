# This should be a test or example startup script

require heaterctrl

epicsEnvSet("P", "CstatV-AC:")

dbLoadRecords("calculus.db", "P=CstatV-AC:, DEV=DAQ6510")

var fillArrDebug 0

afterInit("dbpf CstatV-AC:DAQ6510:ChanInactive1-val.VAL 100")
afterInit("dbpf CstatV-AC:DAQ6510:ChanInactive2-val.VAL 100")


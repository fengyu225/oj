import sys

n = int(sys.stdin.readline().strip())

for i in range(n):
    url = sys.stdin.readline().strip()
    protocol = url.split("://")[0]
    temp = url[len(protocol)+3:].split("/")[0]
    host = temp.split(":")[0]
    port = temp.split(":")[1] if len(temp.split(":"))>1 else "<default>"
    path = "/".join(url[len(protocol)+3:].split("/")[1:]) if len(url[len(protocol)+3:].split("/"))>1 else "<default>"
    print "URL #%d" % (i+1)
    print "Protocol = "+protocol
    print "Host     = "+host
    print "Port     = "+port
    print "Path     = "+path
    print ""
